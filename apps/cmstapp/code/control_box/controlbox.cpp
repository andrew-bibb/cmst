/**************************** controlbox.cpp ***************************

Code to manage the primary user interface to include the QDialog the
user interfaces with and the system tray icon.

Copyright (C) 2013-2016
by: Andrew J. Bibb
License: MIT

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"),to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
***********************************************************************/

/**********************************************************************
 * NOTE TO PEOPLE HACKING ON THE CODE
 * 
 * Prior to 2015.11.12 text returned by connman was translated and then
 * stored in the various maps.  After that date the code was revised so
 * that text is stored in the maps exactly as connman returns it and
 * is then translated when it needs to be displayed.
 * 
***********************************************************************/																								 

# include <QtCore/QDebug>
# include <QDBusArgument>

# include <QTableWidget>
# include <QTableWidgetItem>
# include <QFileInfo>
# include <QFile>
# include <QWhatsThis>
# include <QMenu>
# include <QPixmap>
# include <QMessageBox>
# include <QCloseEvent>
# include <QKeyEvent>
# include <QToolTip>
# include <QTableWidgetSelectionRange>
# include <QProcess>
# include <QProcessEnvironment>
# include <QCryptographicHash>
# include <QLocale>
# include <QColorDialog>
# include <QPainter>
# include <QImage>
# include <QDesktopWidget>
# include <QInputDialog>

# include "../resource.h"
# include "./controlbox.h"
# include "./code/scrollbox/scrollbox.h"
# include "./code/peditor/peditor.h"
# include "./code/provisioning/prov_ed.h"
# include "./code/vpn_prov_ed/vpn_ed.h"
# include "./code/trstring/tr_strings.h"

//  headers for system logging
# include <stdio.h>
# include <unistd.h>
# include <syslog.h>

# define DBUS_PATH "/"
# define DBUS_CON_SERVICE "net.connman"
# define DBUS_VPN_SERVICE "net.connman.vpn"
# define DBUS_CON_MANAGER "net.connman.Manager"
# define DBUS_VPN_MANAGER	"net.connman.vpn.Manager"

// Custom push button, used in the technology box for powered on/off
// This is really a single use button, after it is clicked all idButtons
// are deleted and recreated.  Once is is clicked disable the button.
idButton::idButton(QWidget* parent, const QDBusObjectPath& id) :
          QFrame(parent)
{
  // margins
  const int m_left = 5;
  const int m_top = 0;
  const int m_right = 5;
  const int m_bottom = 0;

  // create the button
  button = new QToolButton(this);
  button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  obj_id = id;
  button->setCheckable(true);
  connect (button, SIGNAL(clicked(bool)), this, SLOT(buttonClicked(bool)));

  // create the box
  QHBoxLayout* layout = new QHBoxLayout(this);
  layout->setContentsMargins(m_left, m_top, m_right, m_bottom);
  layout->addWidget(button, 0, 0);

  return;
}


void idButton::buttonClicked(bool checked)
{
  this->setDisabled(true);

  emit clickedID (obj_id.path(), checked);

  return;
}

// main GUI element
ControlBox::ControlBox(const QCommandLineParser& parser, QWidget *parent)
    : QDialog(parent)
{
  // set the Locale (probably not necessary since the default is the system one anyway)
  QLocale::setDefault(QLocale::system() );

  // setup the user interface
  ui.setupUi(this);

  // install global event filter (used to disable showing tooltips)
  qApp->installEventFilter(this);

	// We need this if someone is running the program from the tray popup menu.
	// The main UI is fine without it, but if you call up the agent dialog and then
	// close that seems to be treated as the last window.
	qApp->setQuitOnLastWindowClosed(false);
  
  // set the window title
  setWindowTitle(TranslateStrings::cmtr("connman system tray"));
  
  // data members
  q8_errors = CMST::No_Errors;
  properties_map.clear();
  services_list.clear();
  technologies_list.clear();
  wifi_list.clear();
  peer_list.clear();
  vpn_list.clear();
  agent = new ConnmanAgent(this);
  vpnagent = new ConnmanVPNAgent(this);
  counter = new ConnmanCounter(this);
  trayiconmenu = new QMenu(this);
  tech_submenu = new QMenu(tr("Technologies"), this);
  info_submenu = new QMenu(tr("Service Details"), this);
  wifi_submenu = new QMenu(tr("WiFi Connections"), this);
  vpn_submenu	 = new QMenu(tr("VPN Connections"), this);
  mvsrv_menu = new QMenu(this);
  settings = new QSettings(ORG, APP, this);
  notifyclient = 0;
  onlineobjectpath.clear();
  socketserver = new QLocalServer(this);
  socketserver->removeServer(SOCKET_NAME);  // remove any files that may have been left after a crash
  socketserver->listen(SOCKET_NAME);
  trayiconbackground = QColor();
  iconman = new IconManager(this);

  // Read saved settings which will set the ui controls in the preferences tab.
  this->readSettings();
  
  // Set the iconmanager color
  iconman->setIconColor(QColor(ui.lineEdit_colorize->text()) );
  
  // Constructor scope bool, set to true if we are using start options
  bool b_so = (! parser.isSet("bypass-start-options") && ui.checkBox_usestartoptions->isChecked() );
  
  // Enable or disable preferences group box (changed via ui signal/slot after the constructor)
  ui.groupBox_startoptions->setEnabled(ui.checkBox_usestartoptions->isChecked());
  
  // Restore window if retain_state is checked and we have not bypassed it on the command line
	if (! parser.isSet("bypass-restore-state") && settings->value("CheckBoxes/retain_state").toBool() ) {
		settings->beginGroup("MainWindow");
		resize(settings->value("size", QSize(700, 550)).toSize() );
		move(settings->value("pos", QPoint(200, 200)).toPoint() );
		ui.tabWidget->setCurrentIndex(settings->value("current_page").toInt() );
		settings->endGroup();
	}
	
	// Make sure the controlbox will fit onto small acreens
	QSize sz_target = (qApp->desktop()->availableGeometry(this)).size();
	QSize sz_source = this->sizeHint();
	sz_target.scale(sz_target.width() - 100, sz_target.height() - 100, Qt::KeepAspectRatio); // give me a little buffer
	if (sz_source.width() > sz_target.width() || sz_source.height() > sz_target.height() ) {
		sz_source.scale(sz_target.width(), sz_target.height(), Qt::KeepAspectRatio);
		resize(sz_source);
		move(25, 25);
	}
		
  // set a flag if we sent a commandline option to log the connman inputrequest
  agent->setLogInputRequest(parser.isSet("log-input-request"));
  vpnagent->setLogInputRequest(parser.isSet("log-input-request"));
  QDir d(IPT_REQ_LOG_PATH);
	d.mkpath(IPT_REQ_LOG_PATH);
	if (d.exists(IPT_REQ_LOG_FILE)) d.remove(IPT_REQ_LOG_FILE);

  // Set icon theme if provided on the command line or in the settings
  if (parser.isSet("icon-theme") )
		QIcon::setThemeName(parser.value("icon-theme"));
	else
		if (b_so && ui.checkBox_systemicontheme->isChecked() )
			QIcon::setThemeName(ui.lineEdit_icontheme->text() );
		else QIcon::setThemeName(INTERNAL_THEME);
		
	// Set the window icon.  If an icon was installed to /usr/share/icons/hicolor/48x48/apps
	// use that, otherwise use a freedesktop.org named one
	if (QFile::exists("/usr/share/icons/hicolor/48x48/apps/cmst.png") )
		this->setWindowIcon(QIcon("/usr/share/icons/hicolor/48x48/apps/cmst.png") );
	else
		this->setWindowIcon(QIcon::fromTheme("preferences-system-network") );
	
	// Set the whatsthis icons
	ui.toolButton_whatsthis->setIcon(iconman->getIcon("whats_this"));
	agent->setWhatsThisIcon(iconman->getIcon("whats_this"));
	vpnagent->setWhatsThisIcon(iconman->getIcon("whats_this"));

  // set a flag is we want to use XFCE or MATE custom code.
  // Currently (as of 2014.11.24) this is only used to get around a bug between QT5.3 and the XFCE system tray
  // Even then the fix may not work, but for now keep it in.
  b_usexfce = (parser.isSet("use-xfce") || (b_so && ui.radioButton_desktopxfce->isChecked()) );
  b_usemate = (parser.isSet("use-mate") || (b_so && ui.radioButton_desktopmate->isChecked()) );

  // Fake transparency
  if (parser.isSet("fake-transparency") ) {
    bool ok;
    trayiconbackground = QColor(parser.value("fake-transparency").toUInt(&ok, 16) );
    if (! ok) trayiconbackground = QColor();
  } // if parser set
  else
		if (b_so && ui.checkBox_faketranparency->isChecked() ) {
			trayiconbackground = QColor(ui.spinBox_faketransparency->value() );
		}	// if
		else trayiconbackground = QColor();
	
  // set counter update params from command line options if available otherwise
  // default params specified in main.cpp are used.  Set a minimum value for
  // each to maintain program response.
  uint minval = 256;
  uint setval = 0;
  if (parser.isSet("counter-update-kb") ) {
		bool ok;
    setval = parser.value("counter-update-kb").toUInt(&ok, 10);
    if (! ok) setval = minval;
	}	// if parser set
  else if (b_so && ui.checkBox_counterkb->isChecked() ) {
    setval = ui.spinBox_counterkb->value();
	}	// else if
	counter_accuracy = setval > minval ? setval : minval; // number of kb for counter updates

  minval = 5;
  setval = 0;
  if (parser.isSet("counter-update-rate") ) {
		bool ok;
    setval = parser.value("counter-update-rate").toUInt(&ok, 10);
    if (! ok) setval = minval;
	}	// if parser set
  else if (b_so && ui.checkBox_counterseconds->isChecked() ) {
    setval = ui.spinBox_counterrate->value();
  }
  counter_period = setval > minval ? setval : minval; // number of seconds for counter updates


  // operate on settings not dealt with elsewhere
  ui.pushButton_provisioning_editor->setVisible(ui.checkBox_advanced->isChecked() );
  ui.pushButton_vpn_editor->setVisible(ui.checkBox_advanced->isChecked() );
  ui.groupBox_process->setVisible(ui.checkBox_advanced->isChecked() );
  enableRunOnStartup(ui.checkBox_runonstartup->isChecked() );

  // Create the notifyclient, make four tries; first immediately in constructor, then
  // at 1/2 second, 2 seconds and finally at 8 seconds
  notifyclient = new NotifyClient(this);
  this->connectNotifyClient();
  QTimer::singleShot(500, this, SLOT(connectNotifyClient()));
  QTimer::singleShot(2 * 1000, this, SLOT(connectNotifyClient()));
  QTimer::singleShot(8 * 1000, this, SLOT(connectNotifyClient()));

  // setup the dbus interface to connman.manager
  if (! QDBusConnection::systemBus().isConnected() ) logErrors(CMST::Err_No_DBus);
  else {
    con_manager = new QDBusInterface(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, QDBusConnection::systemBus(), this);
    if (! con_manager->isValid() ) logErrors(CMST::Err_Invalid_Con_Iface);
    else {
      // Access connman.manager to retrieve the data
      this->managerRescan(CMST::Manager_All);

      // register the agent
      con_manager->call(QDBus::AutoDetect, "RegisterAgent", QVariant::fromValue(QDBusObjectPath(AGENT_OBJECT)) );      
      
      // if counters are enabled connect signal to slot and register the counter 
      if (! parser.isSet("disable-counters") && (b_so ? (! ui.checkBox_disablecounters->isChecked()) : true ) ) {
        QList<QVariant> vlist_counter;
        vlist_counter.clear();
        vlist_counter << QVariant::fromValue(QDBusObjectPath(CNTR_OBJECT)) << counter_accuracy << counter_period;
        QDBusMessage reply = con_manager->callWithArgumentList(QDBus::AutoDetect, "RegisterCounter", vlist_counter);
        if (reply.type() == QDBusMessage::ReplyMessage)
					connect(counter, SIGNAL(usageUpdated(QDBusObjectPath, QString, QString)), this, SLOT(counterUpdated(QDBusObjectPath, QString, QString)));
      }

    // connect some dbus signals to our slots
    QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "PropertyChanged", this, SLOT(dbsPropertyChanged(QString, QDBusVariant)));
    QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "ServicesChanged", this, SLOT(dbsServicesChanged(QList<QVariant>, QList<QDBusObjectPath>, QDBusMessage)));
    QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "PeersChanged", this, SLOT(dbsPeersChanged(QList<QVariant>, QList<QDBusObjectPath>, QDBusMessage)));
    QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "TechnologyAdded", this, SLOT(dbsTechnologyAdded(QDBusObjectPath, QVariantMap)));
    QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "TechnologyRemoved", this, SLOT(dbsTechnologyRemoved(QDBusObjectPath)));

    // clear the counters if selected
    this->clearCounters();
    
    // VPN manager
   vpn_manager = new QDBusInterface(DBUS_VPN_SERVICE, DBUS_PATH, DBUS_VPN_MANAGER, QDBusConnection::systemBus(), this);
    if (! vpn_manager->isValid() ) logErrors(CMST::Err_Invalid_VPN_Iface);
    else  vpn_manager->call(QDBus::AutoDetect, "RegisterAgent", QVariant::fromValue(QDBusObjectPath(VPN_AGENT_OBJECT)) );
    } // else have valid connection
  } // else have connected systemBus

  //  add actions to groups
  minMaxGroup = new QActionGroup(this);
  minimizeAction = new QAction(tr("Mi&nimize"), this);
  maximizeAction = new QAction(tr("Ma&ximize"), this);
  minMaxGroup->addAction(minimizeAction);
  minMaxGroup->addAction(maximizeAction);
  exitAction = new QAction(tr("&Exit"), this);

  moveGroup = new QActionGroup(this);
  moveGroup->addAction(ui.actionMove_Before);
  moveGroup->addAction(ui.actionMove_After);
    
  //  connect signals and slots - actions and action groups
  connect(minMaxGroup, SIGNAL(triggered(QAction*)), this, SLOT(minMaxWindow(QAction*)));
  connect(tech_submenu, SIGNAL(triggered(QAction*)), this, SLOT(techSubmenuTriggered(QAction*)));
  connect(info_submenu, SIGNAL(triggered(QAction*)), this, SLOT(infoSubmenuTriggered(QAction*)));
  connect(wifi_submenu, SIGNAL(triggered(QAction*)), this, SLOT(wifiSubmenuTriggered(QAction*)));
  connect(vpn_submenu, SIGNAL(triggered(QAction*)), this, SLOT(vpnSubmenuTriggered(QAction*)));
  connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
  connect(moveGroup, SIGNAL(triggered(QAction*)), this, SLOT(moveButtonPressed(QAction*)));
  connect(mvsrv_menu, SIGNAL(triggered(QAction*)), this, SLOT(moveService(QAction*)));
  connect(ui.actionRescan, SIGNAL (triggered()), this, SLOT(scanWiFi()));
  connect(ui.actionIDPass, SIGNAL (triggered()), this, SLOT(wifiIDPass()));
  connect(ui.actionOffline_Mode, SIGNAL(triggered(bool)), this, SLOT(toggleOfflineMode(bool)));

  //  connect signals and slots - ui elements
  connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));
  connect(ui.comboBox_service, SIGNAL(currentIndexChanged(int)), this, SLOT(getServiceDetails(int)));
  connect(ui.pushButton_exit, SIGNAL(clicked()), exitAction, SLOT(trigger()));
  connect(ui.pushButton_minimize, SIGNAL(clicked()), minimizeAction, SLOT(trigger()));
  connect(ui.checkBox_hideIcon, SIGNAL(clicked(bool)), this, SLOT(toggleTrayIcon(bool)));
  connect(ui.pushButton_connect, SIGNAL(clicked()), this, SLOT(connectPressed()));
  connect(ui.pushButton_vpn_connect, SIGNAL(clicked()), this, SLOT(connectPressed()));
  connect(ui.pushButton_disconnect, SIGNAL(clicked()), this, SLOT(disconnectPressed()));
  connect(ui.pushButton_vpn_disconnect, SIGNAL(clicked()), this, SLOT(disconnectPressed()));
  connect(ui.pushButton_remove, SIGNAL(clicked()), this, SLOT(removePressed()));
  connect(ui.pushButton_aboutCMST, SIGNAL(clicked()), this, SLOT(aboutCMST()));
  connect(ui.pushButton_aboutIconSet, SIGNAL(clicked()), this, SLOT(aboutIconSet()));
  connect(ui.pushButton_aboutQT, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
  connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(cleanUp()));
  connect(ui.pushButton_license, SIGNAL(clicked()), this, SLOT(showLicense()));
  connect(ui.pushButton_change_log, SIGNAL(clicked()), this, SLOT(showChangeLog()));
  connect(ui.tableWidget_services, SIGNAL (cellClicked(int, int)), this, SLOT(enableMoveButtons(int, int)));
  connect(ui.checkBox_hidecnxn, SIGNAL (toggled(bool)), this, SLOT(updateDisplayWidgets()));
  connect(ui.checkBox_hidetethering, SIGNAL (toggled(bool)), this, SLOT(updateDisplayWidgets()));
  connect(ui.checkBox_systemtraynotifications, SIGNAL (clicked(bool)), this, SLOT(trayNotifications(bool)));
  connect(ui.checkBox_notifydaemon, SIGNAL (clicked(bool)), this, SLOT(daemonNotifications(bool)));
  connect(ui.pushButton_configuration, SIGNAL (clicked()), this, SLOT(configureService()));
  connect(ui.pushButton_provisioning_editor, SIGNAL (clicked()), this, SLOT(provisionService()));
  connect(ui.pushButton_vpn_editor, SIGNAL (clicked()), this, SLOT(provisionService()));
  connect(socketserver, SIGNAL(newConnection()), this, SLOT(socketConnectionDetected()));
  connect(ui.checkBox_runonstartup, SIGNAL(toggled(bool)), this, SLOT(enableRunOnStartup(bool)));
  connect(ui.toolButton_colorize, SIGNAL(clicked()), this, SLOT(callColorDialog()));
  connect(ui.lineEdit_colorize, SIGNAL(textChanged(const QString&)), this, SLOT(iconColorChanged(const QString&)));

  // tray icon - disable it if we specifiy that option on the commandline or in
  // the settings, otherwise set a singleshot timer to create the tray icon.
  trayicon = 0;
  if (parser.isSet("disable-tray-icon") || (b_so && ui.checkBox_disabletrayicon->isChecked()) ) {
    ui.checkBox_hideIcon->setDisabled(true);
    this->updateDisplayWidgets();
    this->showNormal(); // no place to minimize to, so showMaximized
  } // if
  else {
    const short mintrigger = 100; // Minimum time (milliseconds) to wait before starting the tray icon.  We advertise zero, but not really.
    int timeout = 0;
    if (parser.isSet("wait-time") ) {
			bool ok;
      timeout = parser.value("wait-time").toInt(&ok, 10);
      if (! ok) timeout = 0;
		}	// if parser set
    else if (b_so && ui.checkBox_waittime->isChecked() ) {
      timeout = ui.spinBox_waittime->value();
    }

    timeout *= 1000;
    if (timeout < mintrigger) timeout = mintrigger;
    if (parser.isSet("minimized") || (b_so && ui.checkBox_startminimized->isChecked()) ) {
      QTimer::singleShot(timeout, this, SLOT(createSystemTrayIcon()) );
    } // if showMinimized
    else {
      this->showNormal();
      QTimer::singleShot(timeout, this, SLOT(createSystemTrayIcon()) );
    } // else showNormal
   } // else
}

////////////////////////////////////////////////// Public Functions //////////////////////////////////

////////////////////////////////////////////////// Public Slots //////////////////////////////////////
//
// slot to display an about box for this program
void ControlBox::aboutCMST()
{
 QMessageBox::about(this, tr("About %1").arg(TranslateStrings::cmtr("cmst")),
      tr("<center>%1 is a program to interface with the Connman daemon and to provide a system tray control."
      "<br><center>Version <b>%2</b>"
                  "<center>Release date: %3"
                  "<center>Copyright c %4<center>by"
                  "<center>Andrew J. Bibb"
                  "<center>Vermont, USA"
                  "<br><center><b>Contributors:</b>"
                  "<center>Brett Dutro"
                  "<center>Adam Fontenot"
                  "<center>Lester Bico"
                  "<center>Yaohan Chen"
                  "<br><center><b>Translations:</b>"
                  "<center>Jianfeng Zhang (Chinese)"
                  "<center>sqozz (German)"
                  "<center>Ilya Shestopalov (Russian)"
                  "<br><center><b>Build Information:</b>"
                  "<center>Compiled using QT version %5"
                  "<center>Built %6 - %7")	.arg(TranslateStrings::cmtr("cmst"))
																						.arg(VERSION)
																						.arg(RELEASE_DATE)
																						.arg(COPYRIGHT_DATE)
																						.arg(QT_VERSION_STR)
																						.arg(__DATE__)
																						.arg(__TIME__) );
}

//
// slot to display an about box for the icons we used
void ControlBox::aboutIconSet()
{
 QMessageBox::about(this, tr("About AwOken"),
       tr("<center>This program uses the <b>AwOken</b> icon set version 2.5"
          "<br><br>Released under the"
          "<br>Creative Commons"
          "<br>Attribution-Share Alike 3.0"
          "<br>Unported License"
          "<br><a href=\"url\">http://creativecommons.org/licenses/by-sa/3.0/legalcode</a>"
          "<br><center>The CMST icon is a derivative work from the AwOken icon set."
                  ) );
}

//
//  slot to display the program license
void ControlBox::showLicense()
{
  QString s = readResourceText(":/text/text/license.txt");
  if ( s.isEmpty() ) s.append(tr("%1 license is the MIT (Expat) license.").arg(TranslateStrings::cmtr("cmst")));

  QMessageBox::about(this, tr("License"), s);
}

//
//  slot to display the change log of the program
void ControlBox::showChangeLog()
{
  QString s = readResourceText(":/text/text/changelog.txt");
  if ( s.isEmpty() ) s.append(tr("%1 change log is not available.").arg(TranslateStrings::cmtr("cmst")));

  ScrollBox::execScrollBox(tr("ChangeLog"), s, this);
}


////////////////////////////////////////////Private Slots ////////////////////////////////////////////
//
//  Slot to update all of our display widgets
void ControlBox::updateDisplayWidgets()
{
  // each assemble function will check q8_errors to make sure it can
  // get the information it needs.  Only check for major errors since we
  // can't run the assemble functions if there are.

  if ( ((q8_errors & CMST::Err_No_DBus) | (q8_errors & CMST::Err_Invalid_Con_Iface)) == 0x00 ) {
    //  rebuild our pages
    this->assembleTabStatus();
    this->assembleTabDetails();
    this->assembleTabWireless();
    this->assembleTabVPN();
    this->assembleTabCounters();
    if (trayicon != 0 ) this->assembleTrayIcon();
  } // if there were no major errors

  return;
}
//
// Slot to move the selected service before or after another service.
// Called when an item in mvsrv_menu is selected.  QAction act is the
// action selected.
void ControlBox::moveService(QAction* act)
{
  // See if act belongs to a service
  QString ss;
  QDBusObjectPath targetobj;
  for (int i = 0; i < services_list.size(); ++i) {
    ss = getNickName(services_list.at(i).objpath);
    // the items in mvsrv_menu are in the same order as services_list
    if (ss == act->text() ) {
      targetobj = QDBusObjectPath(services_list.at(i).objpath.path());
      break;
    } // if
  } // for

  // make sure we got a targetobject, if not most likely cancel pressed
  if (targetobj.path().isEmpty()) return;

  // get enough information from tableWidget_services to identify the source object
  QList<QTableWidgetItem*> list;
  list.clear();
  list = ui.tableWidget_services->selectedItems();
  if (list.isEmpty() ) return;

  // apply the movebefore or moveafter message to the source object
  QDBusInterface* iface_serv = new QDBusInterface(DBUS_CON_SERVICE, services_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
  if (iface_serv->isValid() ) {
    if (mvsrv_menu->title() == ui.actionMove_Before->text()) {
      QDBusMessage reply = iface_serv->call(QDBus::AutoDetect, "MoveBefore", QVariant::fromValue(targetobj) );
      //qDebug() << reply;
    }
    else {
      QDBusMessage reply = iface_serv->call(QDBus::AutoDetect, "MoveAfter", QVariant::fromValue(targetobj) );
      //qDebug() << reply;
    } // else
  } // iface_srv is valid

  // clean up
  iface_serv->deleteLater();
  return;
}

//
//  Slot called if the movebefore or moveafter button was pressed
void ControlBox::moveButtonPressed(QAction* act)
{
  mvsrv_menu->setTitle(act->text());
  mvsrv_menu->popup(QCursor::pos());

  return;
}

//
//  Slot to enable the movebefore and moveafter buttons, and to prepare the poupup menu
void ControlBox::enableMoveButtons(int row, int col)
{
	(void)col;
  // enable the buttons
  ui.pushButton_movebefore->setEnabled(true);
  ui.pushButton_moveafter->setEnabled(true);

  // create the menu to show if a user selects one of the buttons
  mvsrv_menu->clear();
  QString ss;
  for (int i = 0; i < services_list.size(); ++i) {
    ss = getNickName(services_list.at(i).objpath);
    QAction* act = mvsrv_menu->addAction(ss);
    if (i == row) act->setDisabled(true);
    }

  // add a cancel option
  mvsrv_menu->addSeparator();
  mvsrv_menu->addAction(tr("Cancel"));

  return;
}

//
//  Slot to update the service label when this->counter is updated.  Other labels in page 4 receive signals directly
void ControlBox::counterUpdated(const QDBusObjectPath& qdb_objpath, const QString& home_label, const QString& roam_label)
{
  // Don't update the counter if qdb_objpath is not the online service
  if (! qdb_objpath.path().contains(onlineobjectpath) ) return;

  // Set the labels in page 4
  if (! qdb_objpath.path().isEmpty() ) {
    QMap<QString,QVariant> map;
    for (int i =0; i < services_list.size(); ++i) {
      if (services_list.at(i).objpath == qdb_objpath) {
        map = services_list.at(i).objmap;
        break;
      } // if
    } // for
    ui.label_counter_service_name->setText(tr("<b>Service:</b> %1").arg(getNickName(qdb_objpath)) );
    ui.label_home_counter->setText(home_label);
    ui.label_roam_counter->setText(roam_label);
  }
  else
    ui.label_counter_service_name->setText(tr("<b>Service:</b> %1").arg(tr("Unable to determine service")) );

  return;
}


//
// Slot to connect a wifi or vpn service. Called when ui.pushButton_connect
// or ui.pushButton_vpn_connect is pressed.
// For VPN's this connects the service, not the vpnconnection.  It appears that connman_vpn takes
// the vpnconnections and creates one service for each.  The vpnconnection part could be connected by
// using vpn connection interface, but not really worth it since connman automatically creates a
// a service for us.
void ControlBox::connectPressed()
{
	// Process wifi or vpn depending on who sent the signal
	QTableWidget* qtw = NULL;
	if (sender() == ui.pushButton_connect) qtw = ui.tableWidget_wifi;
		else if (sender() == ui.pushButton_vpn_connect) qtw = ui.tableWidget_vpn;
			else 	return;
	
  // If there is only one row select it
  if (qtw->rowCount() == 1 ) {
    QTableWidgetSelectionRange qtwsr = QTableWidgetSelectionRange(0, 0, 0, qtw->columnCount() - 1);
    qtw->setRangeSelected(qtwsr, true);
  }

  // If no row is selected then return(
  QList<QTableWidgetItem*> list;
  list.clear();
  list = qtw->selectedItems();
  if (list.isEmpty() ) {
    QMessageBox::information(this, tr("No Services Selected"),
      tr("You need to select a service before pressing the connect button.") );
    return;
  }
  
  //	send the connect message to the service.  TableWidget only allows single selection so list can only have 0 or 1 elments
  QDBusInterface* iface_serv = NULL;

  if (qtw == ui.tableWidget_wifi) { 
		iface_serv = new QDBusInterface(DBUS_CON_SERVICE, wifi_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
	}
	else if (qtw == ui.tableWidget_vpn) { 
		iface_serv = new QDBusInterface(DBUS_CON_SERVICE, vpn_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);	 
	}
	else return;	// really not needed 
	
	// don't know why, but can't get the Agent until the timeout, set a short one 
	iface_serv->setTimeout(5);
	QDBusMessage reply = iface_serv->call(QDBus::AutoDetect, "Connect");
	//qDebug() << "reply: " << reply;
	iface_serv->deleteLater();
	return;  
}

//
// Slot to disconnect a wifi or VPN service. Called when ui.pushButton_disconnect
// or ui.pushBotton_vpn_disconnect is pressed
void ControlBox::disconnectPressed()
{
	// Process wifi or vpn depending on who sent the signal
	QTableWidget* qtw = NULL;
	if (sender() == ui.pushButton_disconnect) qtw = ui.tableWidget_wifi;
		else if (sender() == ui.pushButton_vpn_disconnect) qtw = ui.tableWidget_vpn;
			else 	return;
	
	// If there is no item is selected run through the list looking for
  // services in "online" or "ready" state. If more than one is found 
  // break as we will have to use the one currently selected.
  int cntr_connected = 0;
	int row_connected = -1;
  if (qtw->selectedItems().isEmpty() ) {
	  int itemcount = 0;
	  QMap<QString,QVariant> map;
	  if (qtw == ui.tableWidget_wifi)	itemcount = wifi_list.size();
			else if (qtw == ui.tableWidget_vpn)  itemcount = vpn_list.size();
				else return;	// line is not really needed
		 
	  for (int row = 0; row < itemcount; ++row) {
			if (qtw == ui.tableWidget_wifi) map = wifi_list.at(row).objmap;
				else if (qtw == ui.tableWidget_vpn)  map = vpn_list.at(row).objmap;
					else return; // line is not really needed
	
	    if (map.value("State").toString() == "online" || map.value("State").toString() == "ready" ) {
	       ++cntr_connected;
	       row_connected = row;
	     }
	     if (cntr_connected > 1 ) break;
	  } // for
	  
		// Nothing selected, online or ready so return now
		if (cntr_connected == 0) return;	
  
		// If only one entry is connected or online, select it
		if (cntr_connected == 1 ) {
			QTableWidgetSelectionRange qtwsr = QTableWidgetSelectionRange(row_connected, 0, row_connected, qtw->columnCount() - 1);
			qtw->setRangeSelected(qtwsr, true);
		}	// cntr_connected == 1		
	}	// if there are no currently selected items
  
  // If no row selected return
  QList<QTableWidgetItem*> list;
  list.clear();
  list = qtw->selectedItems();
  if (list.isEmpty() ) {
    QMessageBox::information(this, tr("No Services Selected"),
      tr("You need to select a service before pressing the disconnect button.") );
    return;
  }

  // Send the disconnect message to the service.  TableWidget only allows single selection so list can only have 0 or 1 elments
  QDBusInterface* iface_serv = NULL;
  if (qtw == ui.tableWidget_wifi) 
		iface_serv = new QDBusInterface(DBUS_CON_SERVICE, wifi_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
	else if (qtw == ui.tableWidget_vpn) 
		iface_serv = new QDBusInterface(DBUS_CON_SERVICE, vpn_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
	else return;	// this line really not needed 
	
	iface_serv->call(QDBus::AutoDetect, "Disconnect");
	iface_serv->deleteLater();
	return;
}

//
// Slot to remove (unset the Favorite property, clear passphrase if one exists) of a Wifi service
// Called when ui.pushButton_remove is pressed
void ControlBox::removePressed()
{			
  // if no row selected return
  QList<QTableWidgetItem*> list;
  list.clear();
  list = ui.tableWidget_wifi->selectedItems();
  if (list.isEmpty() ) {
    QMessageBox::information(this, tr("No Services Selected"),
      tr("You need to select a Wifi service before pressing the remove button.") );
    return;
  }

  //  send the Remove message to the service
  QDBusInterface* iface_serv = new QDBusInterface(DBUS_CON_SERVICE, wifi_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
  iface_serv->call(QDBus::AutoDetect, "Remove");
  iface_serv->deleteLater();

  return; 	
}

//  dbs slots are slots to receive DBus Signals
//
//  Slot called whenever DBUS issues a PropertyChanged signal
void ControlBox::dbsPropertyChanged(QString prop, QDBusVariant dbvalue)
{
  // save current state and update propertiesMap
  QString oldstate = properties_map.value(prop).toString();
  properties_map.insert(prop, dbvalue.variant() );

  // refresh display widgets
  updateDisplayWidgets();

  // offlinemode property
  if (prop == "OfflineMode") {
    notifyclient->init();
    if (dbvalue.variant().toBool()) {
      notifyclient->setSummary(tr("Offline Mode Engaged"));
      notifyclient->setIcon(iconman->getIconName("offline_mode_engaged") );
    }
    else {
      notifyclient->setSummary(tr("Offline Mode Disabled"));
      notifyclient->setIcon(iconman->getIconName("offline_mode_disengaged") );
    }
    this->sendNotifications();  
  } // if contains offlinemode

  if (prop =="State") {
    // local variables
    QString type;
    QString name;
    QString state = dbvalue.variant().toString();
    QString iconpath;

    // if there is at least 1 service
    if (services_list.count() > 0 ) {
        QMap<QString,QVariant> map = services_list.at(0).objmap;
        type = services_list.at(0).objmap.value("Type").toString();
        name = getNickName(services_list.at(0).objpath);

      // notification text and icons
      if (type == "wifi")
				iconpath = iconman->getIconName("connection_wireless");
      else 
				iconpath = iconman->getIconName("connection_wired");

      notifyclient->init();
      notifyclient->setSummary(tr("%1 (%2) Network").arg(type).arg(name) );
      notifyclient->setBody(tr("Connection: %1").arg(state) );
      notifyclient->setIcon(iconpath);
      
      this->sendNotifications();
      
      // execute external program if specified
      if (! ui.lineEdit_afterconnect->text().isEmpty()  ) {
				if( (state == "ready" || state == "online") &&
					(oldstate != "ready" && oldstate != "online") ) {
					QString text = ui.lineEdit_afterconnect->text();	
					text = text.simplified();
					QStringList args = text.split(' ');
					QString cmd = args.first();
					args.removeFirst();
					QProcess* proc = new QProcess(this);
					proc->startDetached(cmd, args);	
				}	// if online or ready and not online before		  
			}	// if lineedit not empty
    } // if services count > 0

    // no services listed
    else {
      notifyclient->init();
      notifyclient->setSummary(tr("Network Services:") );
      notifyclient->setBody(tr("No network services available") );
      notifyclient->setIcon(iconman->getIconName("connection_not_ready") );
      this->sendNotifications();
    } // else no services listed
  } // if state change

  return;
}

//
// Slot called whenever DBUS issues a ServicesChanged signal.  When a
// Scan method is called on a technology the results of that scan are
// signaled through this slot.  This is also called when the sort order
// of the services list changes.  It will not be called when a property
// of a service object changes.  
void ControlBox::dbsServicesChanged(QList<QVariant> vlist, QList<QDBusObjectPath> removed, QDBusMessage msg)
{		
	// Demarshall the raw QDBusMessage instead of vlist as it is easier..
  if (! vlist.isEmpty() ) {
    QList<arrayElement> revised_list;
    if (! getArray(revised_list, msg)) return; 
   
    // merge the existing services_list into the revised_list
    // first find the original element that matches the revised
    for (int i = 0; i < revised_list.size(); ++i) {	
      arrayElement revised_element = revised_list.at(i);
      arrayElement original_element = {QDBusObjectPath(), QMap<QString,QVariant>()};
      for (int j = 0; j < services_list.size(); ++j) {
        if (revised_element.objpath == services_list.at(j).objpath) {
          original_element = services_list.at(j);
          break;
        } // if
      } // j for

      // merge the new elementArray into the existing
      if (! original_element.objpath.path().isEmpty()) {
        QMapIterator<QString, QVariant> itr(revised_element.objmap);
        while (itr.hasNext()) {
          itr.next();
          original_element.objmap.insert(itr.key(), itr.value() );
        } // while

        // now insert the element into the revised list
        QDBusConnection::systemBus().disconnect(DBUS_CON_SERVICE, original_element.objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
				revised_list.replace(i, original_element);
				QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, revised_element.objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));       
        
      } // if original element is not empty
    } // i for

    // now copy the revised list to services_list
    services_list.clear();
    services_list = revised_list;
  } // revised_list not empty

  // process removed services
  if (! removed.isEmpty() ) {
    for (int i = 0; i < services_list.count(); ++i) {
      if (removed.contains(services_list.at(i).objpath) ) {
				QDBusConnection::systemBus().disconnect(DBUS_CON_SERVICE, services_list.at(i).objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
        services_list.removeAt(i);
			}	// if
     } // for
   } // if we needed to remove something
    
  // clear the counters (if selected) and update the widgets
  clearCounters(); 
  // Next line a bit of a hack, but I can find no evidence that service provider properties are changed via signals once a connection is
  // made. This includes both the manager.servicesChanged() and services.propertyChanged() signals. Connecting a VPN seems to be a 
  // black hole of signals (well except for vpn connection interface - but we're not using that).   
  // This will force a service rescan which picks up some of these properties.
  if (services_list.at(0).objmap.value("Type") == "vpn") managerRescan(CMST::Manager_Services);
	updateDisplayWidgets();
	
  return;  
}

//
// Slot called whenever DBUS issues a Peerschanged signal.  See note above about
// scan results being signaled here.
void ControlBox::dbsPeersChanged(QList<QVariant> vlist, QList<QDBusObjectPath> removed, QDBusMessage msg)
{
  // Set the update flag
  bool b_needupdate = false;

  // Process changed peers. Demarshall the raw QDBusMessage instead of vlist as it is easier.
  if (! vlist.isEmpty() ) {
    QList<arrayElement> revised_list;
    if (! getArray(revised_list, msg)) return;

    // if revised_list is not the same size as the existing peer_list
    // then we definetely need an update
    if (revised_list.count() != peer_list.count() ) b_needupdate = true;

    // merge the existing peers_list into the revised_list
    // first find the original element that matches the revised
    for (int i = 0; i < revised_list.size(); ++i) {
      arrayElement revised_element = revised_list.at(i);
      arrayElement original_element = {QDBusObjectPath(), QMap<QString,QVariant>()};
      for (int j = 0; j < peer_list.size(); ++j) {
        if (revised_element.objpath == peer_list.at(j).objpath) {
          original_element = peer_list.at(j);
          break;
        } // if
      } // j for

      // merge the new elementArray into the existing
      if (! original_element.objpath.path().isEmpty()) {
        QMapIterator<QString, QVariant> itr(revised_element.objmap);
        while (itr.hasNext()) {
          itr.next();
          b_needupdate = true;
          original_element.objmap.insert(itr.key(), itr.value() );
        } // while

        // now insert the element into the revised list
        revised_list.replace(i, original_element);
      } // if original element exists
    } // i for

    // now copy the revised list to peer_list
    peer_list.clear();
    peer_list = revised_list;
  } // vlist not empty

  // process removed peers
  if (! removed.isEmpty() ) {
    for (int i = 0; i < peer_list.count(); ++i) {
      if (removed.contains(peer_list.at(i).objpath) )
        peer_list.removeAt(i);
      } // for
    } // if we needed to remove something

  // update the widgets
  if (b_needupdate) updateDisplayWidgets();

  return;
}

//
// Slot called whenever DBUS issues a TechonlogyAdded signal
// There must be an internal counter for technologies, first time a
// technology is changed we get a signal even if we've already run
// getTechnologies.  After that first time we never get this signal.
// Use this this to catch real additions, which we defined as something
// we don't already have from getTechnologies.
void ControlBox::dbsTechnologyAdded(QDBusObjectPath path, QVariantMap properties)
{
  // iterate over the properties map and replace connman text with translated text
  QMapIterator<QString, QVariant> itr(properties);
  while (itr.hasNext()) {
    itr.next();
    properties.insert(itr.key(), itr.value() );
  } // map iterator

  // construct an arrayElement
  arrayElement ae = {path, properties};
  bool newelem = true;

  // first see if the element exists, if so replace it
  for (int i = 0; i < technologies_list.count(); ++i) {
    if (path == technologies_list.at(i).objpath) {
      technologies_list.replace(i, ae);
      newelem = false;
      break;
    } // if
  } // for

  // if it is a new element add it
  if (newelem) {
    technologies_list.append(ae);
  }

  updateDisplayWidgets();

  return;
}

//
//  Slot called whenever DBUS issues a TechonlogyAdded signal
void ControlBox::dbsTechnologyRemoved(QDBusObjectPath removed)
{
  for (int i = 0; i < technologies_list.count(); ++i) {
    if ( removed == technologies_list.at(i).objpath ) {
      technologies_list.removeAt(i);
      break;
    } // if
  } // for

  updateDisplayWidgets();

  return;
}

//
//  Slots called from objects.  The previous slots were called from Manager
//
//  Slot called whenever a service object issues a PropertyChanged signal on DBUS
void ControlBox::dbsServicePropertyChanged(QString property, QDBusVariant dbvalue, QDBusMessage msg)
{
  QString s_path = msg.path();
  QVariant value = dbvalue.variant();
  QString s_state;

  // replace the old values with the changed ones.
  for (int i = 0; i < services_list.count(); ++i) {
    if (s_path == services_list.at(i).objpath.path() ) {
      QMap<QString,QVariant> map = services_list.at(i).objmap;
      map.remove(property);
      map.insert(property, value );
      arrayElement ae = {services_list.at(i).objpath, map};
      services_list.replace(i, ae);
      s_state = map.value("State").toString();
      break;
    } // if
  } // for

  // process errrors  - errors only valid when service is in the failure state
  if (property =="Error" && s_state == "failure") {
    notifyclient->init();
    notifyclient->setSummary(QString(tr("Service Error: %1")).arg(value.toString()) );
    notifyclient->setBody(QString(tr("Object Path: %1")).arg(s_path) );
    notifyclient->setIcon(iconman->getIconName("state_error") );
    notifyclient->setUrgency(Nc::UrgencyCritical);
    this->sendNotifications();
  }

  // if state property changed sync the online data members
  if (property == "State") {
    if (value.toString() == "online") {
      onlineobjectpath = s_path;
    } //
    else if (s_path == onlineobjectpath) {
      onlineobjectpath.clear();
		} // else if object went offline
		// Send notification if vpn changed
		for (int i = 0; i < vpn_list.count(); ++i) {
			if (s_path == vpn_list.at(i).objpath.path() ) {
				notifyclient->init();
				if (value.toString() == "ready") {
					notifyclient->setSummary(QString(tr("VPN Engaged")) );
					notifyclient->setIcon(iconman->getIconName("connection_vpn") );
				}
				else {
					notifyclient->setSummary(QString(tr("VPN Disengaged")) );
					notifyclient->setIcon(iconman->getIconName("onnection_not_ready") );
				}
				notifyclient->setBody(QString(tr("Object Path: %1")).arg(s_path) );
				notifyclient->setUrgency(Nc::UrgencyNormal);
				this->sendNotifications();
				break;
			} // if
		}	// for
	} // if property contains State 

	// update the widgets
  updateDisplayWidgets();
  
  return;
}

//
//  Slot called whenever a technology object issues a PropertyChanged signal on DBUS
void ControlBox::dbsTechnologyPropertyChanged(QString name, QDBusVariant dbvalue, QDBusMessage msg)
{
  QString s_path = msg.path();

  // replace the old values with the changed ones.
  for (int i = 0; i < technologies_list.count(); ++i) {
    if (s_path == technologies_list.at(i).objpath.path() ) {
      QMap<QString,QVariant> map = technologies_list.at(i).objmap;
      map.remove(name);
      map.insert(name, dbvalue.variant() );
      arrayElement ae = {technologies_list.at(i).objpath, map};
      technologies_list.replace(i, ae);
      break;
    } // if
  } // for

  updateDisplayWidgets();

  return;
}

//  Slot to rescan all WiFi technologies.  Called from the
//  ui.pushButton_rescan control.
//  Results signaled by manager.ServicesChanged(), except for peer
//  services which will be signaled by manager.PeersChanged()
void ControlBox::scanWiFi()
{
  // Make sure we got the technologies_list before we try to work with it.
  if ( (q8_errors & CMST::Err_Technologies) != 0x00 ) return;

  // Run through each technology and do a scan for any wifi
  for (int row = 0; row < technologies_list.size(); ++row) {
    if (technologies_list.at(row).objmap.value("Type").toString() == "wifi") {
      if (technologies_list.at(row).objmap.value("Powered").toBool() ) {
        ui.pushButton_rescan->setDisabled(true);
        ui.tableWidget_services->setCurrentIndex(QModelIndex()); // first cell becomes selected once pushbutton is disabled
        qApp->processEvents();  // needed to promply disable the button
        QDBusInterface* iface_tech = new QDBusInterface(DBUS_CON_SERVICE, technologies_list.at(row).objpath.path(), "net.connman.Technology", QDBusConnection::systemBus(), this);
        iface_tech->setTimeout( 8 * 1000);  // full 25 second timeout is a bit much when there is a problem
        QDBusMessage reply = iface_tech->call(QDBus::AutoDetect, "Scan");
        if (reply.type() != QDBusMessage::InvalidMessage) ui.pushButton_rescan->setEnabled(true);
        if (reply.type() != QDBusMessage::ReplyMessage) {
          QMessageBox::warning(this,
            QString(TranslateStrings::cmtr("cmst")) + tr(" Warning"),
            tr("<center><b>We received a DBUS reply message indicating an error while trying to scan technologies.</b></center>"
            "<br><br>Error Name: %1<br><br>Error Message: %2").arg(reply.errorName()).arg(TranslateStrings::cmtr(reply.errorMessage())) );
        } // if reply is something other than a normal reply message

        iface_tech->deleteLater();
      } // if the wifi was powered
    } // if the list item is wifi
  } // for

  return;
}

//  Slot to loop through all WiFi technologies and set or reset the
//  id and password.  Called from the ui.pushButton_IDPass and from this
//  toggleTethered().
void ControlBox::wifiIDPass(const QString& obj_path)
{
  // Make sure we got the technologies_list before we try to work with it.
  if ( (q8_errors & CMST::Err_Technologies) != 0x00 ) return;

	// Run through each technology looking for Wifi
	for (int row = 0; row < technologies_list.size(); ++row) {
		if (technologies_list.at(row).objmap.value("Type").toString() == "wifi") {
				if (technologies_list.at(row).objpath.path() == obj_path || obj_path.isEmpty() ) {
					QString sid;
					QString spw;
					bool ok;
					QDBusInterface* iface_tech = new QDBusInterface(DBUS_CON_SERVICE, technologies_list.at(row).objpath.path(), "net.connman.Technology", QDBusConnection::systemBus(), this);
	
					sid = QInputDialog::getText(this, 
						tr("%1 - Text Input").arg(TranslateStrings::cmtr("cmst")),
						tr("<b>Technology: %1</b><p>Please enter the WiFi AP SSID that clients will<br>have to join in order to gain internet connectivity.").arg(technologies_list.at(row).objpath.path() ),
						QLineEdit::Normal,
						technologies_list.at(row).objmap.value("TetheringIdentifier").toString(),
						&ok);
					if (ok) QDBusMessage reply01 = iface_tech->call(QDBus::AutoDetect, "SetProperty", "TetheringIdentifier", QVariant::fromValue(QDBusVariant(sid)) );		
	
					spw = QInputDialog::getText(this, 
						tr("%1 - Text Input").arg(TranslateStrings::cmtr("cmst")),
						tr("<b>Technology: %1</b><p>Please enter the WPA pre-shared key clients will<br>have to use in order to establish a connection.").arg(technologies_list.at(row).objpath.path() ),
						QLineEdit::Normal,
						technologies_list.at(row).objmap.value("TetheringPassphrase").toString(),
						&ok);
					if (ok) QDBusMessage reply02 = iface_tech->call(QDBus::AutoDetect, "SetProperty", "TetheringPassphrase", QVariant::fromValue(QDBusVariant(spw)) );		
	 
					// cleanup
					iface_tech->deleteLater();
				}	// if wifi match
			}	// if tech is wifi
		}	// for
  
  return;
}

//
//  Slot to globally turn power off to all network adapters
//  Called when ui.checkBox_devicesoff is clicked
void ControlBox::toggleOfflineMode(bool checked)
{
  if ( ((q8_errors & CMST::Err_No_DBus) | (q8_errors & CMST::Err_Invalid_Con_Iface)) != 0x00 ) return;

  QList<QVariant> vlist;
  vlist.clear();
  vlist << QVariant("OfflineMode") << QVariant::fromValue(QDBusVariant(checked ? true : false));
  con_manager->callWithArgumentList(QDBus::AutoDetect, "SetProperty", vlist);

  return;
}

//
//  Slot to toggle the visibility of the tray icon
//  Called when ui.checkBox_hideIcon is clicked
void ControlBox::toggleTrayIcon(bool b_checked)
{
  if (trayicon != 0 ) {
    if (b_checked) {
      trayicon->setVisible(false);
      ui.pushButton_minimize->setDisabled(true);
    } // if
    else {
      trayicon->setVisible(true);
      ui.pushButton_minimize->setDisabled(false);
    } // else
  } //if

  return;
}

//
//  Slot to toggle the powered state of a technology
//  Called when our custom idButton in the powered cell in the page 1 technology tableWidget is clicked
void ControlBox::togglePowered(QString object_id, bool checkstate)
{
  QDBusInterface* iface_tech = new QDBusInterface(DBUS_CON_SERVICE, object_id, "net.connman.Technology", QDBusConnection::systemBus(), this);
  QDBusMessage reply = iface_tech->call(QDBus::AutoDetect, "SetProperty", "Powered", QVariant::fromValue(QDBusVariant(checkstate)) );

  // cleanup
  iface_tech->deleteLater();
  return;
}

//
// Slot to toggle the tethering state of a technology
//  Called when our custom idButton in the powered cell in the page 1 technology tableWidget is clicked
void ControlBox::toggleTethered(QString object_id, bool checkstate)
{
	QDBusInterface* iface_tech = new QDBusInterface(DBUS_CON_SERVICE, object_id, "net.connman.Technology", QDBusConnection::systemBus(), this);
	
	// See if this is a wifi technology, get the ID and Pass if necessary
	bool ok = true;
  for (int row = 0; row < technologies_list.size(); ++row) {
		if (technologies_list.at(row).objpath.path() == object_id) {
			if(technologies_list.at(row).objmap.value("Type").toString() == "wifi") {
				QString sid = technologies_list.at(row).objmap.value("TetheringIdentifier").toString();
				QString spw = technologies_list.at(row).objmap.value("TetheringPassphrase").toString();
				if (sid.isEmpty() || spw.isEmpty() ) wifiIDPass(object_id);
			}	// if technology is wifi
		}	// if object_id
	}	// for

	// Send message if everything is ok
	if (ok) QDBusMessage reply = iface_tech->call(QDBus::AutoDetect, "SetProperty", "Tethering", QVariant::fromValue(QDBusVariant(checkstate)) );

  // cleanup
  iface_tech->deleteLater();
  return;
}

//
//  Slot to minimize the input window.  QWidget.hide() if the tray icon
//  is visible, QWidget.showMinmized() if the tray icon is not visible.
//  Do it this way as otherwise there is no way to get the dialog back if
//  the tray icon is not shown.
//  called when actionMinimize is activated
void ControlBox::minMaxWindow(QAction* act)
{
  if (act == minimizeAction ) {
    this->writeSettings();
    if (trayicon != 0 ) trayicon->isVisible() ? this->hide() : this->showMinimized();
    else this->showMinimized();
  } // if minimizeAction

  else if (act == maximizeAction) {
    this->showNormal();
  }

  // Called from the systemtrayicon context menu.  Actions are
  // created dynamically and we don't know them up front.  Actions here
  // we want to open the details page and set the combo box to display
  // information on the service.
  else {
    ui.tabWidget->setCurrentIndex(1);
    ui.comboBox_service->setCurrentIndex(ui.comboBox_service->findText(act->text()) );
    this->showNormal();
  }

  return;
}

//
// Called from the systemtrayicon context menu.  Actions are
// created dynamically and we don't know them up front.  Actions here
// are to power and unpower technologies
void ControlBox::techSubmenuTriggered(QAction* act)
{
	// find the techology associated with the action and toggle its powered state 
	for (int i = 0; i < technologies_list.count(); ++i) {
		if (technologies_list.at(i).objmap.value("Name").toString() == act->text() ) {
			togglePowered(technologies_list.at(i).objpath.path(), act->isChecked() );
			break;
		}	// if
	}	// for
	
  return;
}

//
// Called from the systemtrayicon context menu.  Actions are
// created dynamically and we don't know them up front.  Actions here
// we want to open the details page and set the combo box to display
// information on the service.
void ControlBox::infoSubmenuTriggered(QAction* act)
{
	ui.tabWidget->setCurrentIndex(1);
  ui.comboBox_service->setCurrentIndex(ui.comboBox_service->findText(act->text()) );
  this->showNormal();
  
  return;
}

//
// Called from the systemtrayicon context menu.  Actions are
// created dynamically and we don't know them up front.  Actions here
// connect to a wifi service.
void ControlBox::wifiSubmenuTriggered(QAction* act)
{
	// find the wifi service associated with the action.
	for (int i = 0; i < wifi_list.count(); ++i) {
		if (getNickName(wifi_list.at(i).objpath) == act->text() ) {
			QDBusInterface* iface_serv = new QDBusInterface(DBUS_CON_SERVICE, wifi_list.at(i).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
			iface_serv->setTimeout(1);
			QString state = wifi_list.at(i).objmap.value("State").toString();
			if (state == "online" || state == "ready")
				iface_serv->call(QDBus::AutoDetect, "Disconnect");
			else 
				iface_serv->call(QDBus::AutoDetect, "Connect");
			iface_serv->deleteLater();
			break;
		}	// if
	} 	// for
	
  return;
}

//
// Called from the systemtrayicon context menu.  Actions are created
// dynamically and we don't know them up front. Actions here connect
// to a VPN service.
void ControlBox::vpnSubmenuTriggered(QAction* act)
{
	// find the VPN service associated with the action
	for (int i = 0; i < vpn_list.count(); ++i) {
		if (getNickName(vpn_list.at(i).objpath) == act->text() ) {
			QDBusInterface* iface_serv = new QDBusInterface(DBUS_CON_SERVICE, vpn_list.at(i).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
			iface_serv->setTimeout(1);
			QString state = vpn_list.at(i).objmap.value("State").toString();
			if (state == "ready")
				iface_serv->call(QDBus::AutoDetect, "Disconnect");
			else 
				iface_serv->call(QDBus::AutoDetect, "Connect");
			iface_serv->deleteLater();
			break;
		}	// if
	} 	// for

	return;
}

//
//  Slot to get details of the selected service and write it into ui.label_details
//  Called when the ui.comboBox_services currentIndexChanged() signal is emitted.
void ControlBox::getServiceDetails(int index)
{
  //  Make sure we were sent a valid index, can happen if the comboBox is
  //  cleared and for whatever reason could not be reseeded with entries.
  if (index < 0 ) return;

  // variables
  bool b_editable = services_list.size() > 0 ? true : false;

  //  Get the QMap associated with the index stored in an arrayElement
  QMap<QString,QVariant> map = services_list.at(index).objmap;

  //  Some of the QVariants in the map are QMaps themselves, create a data structure for them
  QMap<QString,QVariant> submap;

  // Get a QFileInfo associated with the index and display the connection
  QFileInfo fi = services_list.at(index).objpath.path();
  ui.label_details_connection->setText(tr("<b>Connection:</b> %1").arg(fi.baseName()) );

  //  Start building the string for the left label
  QString rs = tr("<br><b>Service Details:</b><br>");
  if (getNickName(services_list.at(index).objpath).isEmpty() ) b_editable = false;
  rs.append(tr("Service Type: %1<br>").arg(TranslateStrings::cmtr(map.value("Type").toString())) );
  rs.append(tr("Service State: %1<br>").arg(TranslateStrings::cmtr(map.value("State").toString())) );
  rs.append(tr("Favorite: %1<br>").arg(map.value("Favorite").toBool() ? tr("Yes", "favorite") : tr("No", "favorite"))  );
  rs.append(tr("External Configuration File: %1<br>").arg(map.value("Immutable").toBool() ? tr("Yes", "immutable") : tr("No", "immutable")) );
  if (map.value("Immutable").toBool() ) b_editable = false;
  rs.append(tr("Auto Connect: %1<br>").arg(map.value("AutoConnect").toBool() ? tr("On", "autoconnect") : tr("No", "autoconnect")) );

  rs.append(tr("<br><b>IPv4</b><br>"));
  extractMapData(submap, services_list.at(index).objmap.value("IPv4") );
  rs.append(tr("IP Address Acquisition: %1<br>").arg(TranslateStrings::cmtr(submap.value("Method").toString(), "connman ipv4 method string")) );
  rs.append(tr("IP Address: %1<br>").arg(submap.value("Address").toString()));
  rs.append(tr("IP Netmask: %1<br>").arg(submap.value("Netmask").toString()));
  rs.append(tr("IP Gateway: %1<br>").arg(submap.value("Gateway").toString()));

  rs.append(tr("<br><b>IPv6</b><br>"));
  extractMapData(submap, services_list.at(index).objmap.value("IPv6") );
  rs.append(tr("Address Acquisition: %1<br>").arg(TranslateStrings::cmtr(submap.value("Method").toString(), "connman ipv6 method string")) );
  rs.append(tr("IP Address: %1<br>").arg(submap.value("Address").toString()));
  QString s_ipv6prefix = submap.value("PrefixLength").toString();
  if (s_ipv6prefix.isEmpty() )
    rs.append(tr("Prefix Length: <br>"));
  else
    rs.append(tr("Prefix Length: %1<br>").arg(submap.value("PrefixLength").toUInt()));
  rs.append(tr("IP Gateway: %1<br>").arg(submap.value("Gateway").toString()));
  rs.append(tr("Privacy: %1<br>").arg(TranslateStrings::cmtr(submap.value("Privacy").toString())) );

  rs.append(tr("<br><b>Proxy</b><br>"));
  extractMapData(submap, services_list.at(index).objmap.value("Proxy") );
  QString s_proxymethod = TranslateStrings::cmtr(submap.value("Method").toString(), "connman proxy string" );
  rs.append(tr("Address Acquisition: %1<br>").arg(s_proxymethod) );
  if (s_proxymethod == "auto" ) {
    rs.append(tr("URL: %1<br>").arg(submap.value("URL").toString()) );
  }
  else if (s_proxymethod == "manual" ) {
    rs.append(tr("Servers:<br>&nbsp;&nbsp;%1<br>").arg(submap.value("Servers").toStringList().join("<br>&nbsp;&nbsp;")) );
    rs.append(tr("Excludes:<br>&nbsp;&nbsp;%1<br>").arg(submap.value("Excludes").toStringList().join("<br>&nbsp;&nbsp;")) );
  }

  //  write the text to the left display label
  ui.label_details_left->setText(rs);

  // Start building the string for the right label
  rs = tr("<br><b>Name Servers</b><br>");
  rs.append(map.value("Nameservers").toStringList().join("<br>") );

  rs.append(tr("<br><br><b>Time Servers</b><br>  "));
  rs.append(map.value("Timeservers").toStringList().join("<br>") );

  rs.append(tr("<br><br><b>Search Domains</b><br>  "));
  rs.append(map.value("Domains").toStringList().join("<br>") );

  rs.append(tr("<br><br><b>Ethernet</b><br>"));
  extractMapData(submap, services_list.at(index).objmap.value("Ethernet") );
  rs.append(tr("Connection Method: %1<br>").arg(TranslateStrings::cmtr(submap.value("Method").toString(), "connman ethernet connection method")) );
  rs.append(tr("Interface: %1<br>").arg(submap.value("Interface").toString()) );
  rs.append(tr("Device Address: %1<br>").arg(submap.value("Address").toString()) );
  rs.append(tr("MTU: %1<br>").arg(submap.value("MTU").value<quint16>()) );

  rs.append(tr("<br><b>Wireless</b><br>"));
  QStringList sl_tr;
  for (int i = 0; i < map.value("Security").toStringList().size(); ++i) {
		sl_tr << TranslateStrings::cmtr(map.value("Security").toStringList().at(i) );
	}	// for
  rs.append(tr("Security: %1<br>").arg(sl_tr.join(',')) );
  if (! map.value("Strength").toString().isEmpty() ) rs.append(tr("Strength: %1<br>").arg(map.value("Strength").value<quint8>()) );
  rs.append(tr("Roaming: %1<br>").arg(map.value("Roaming").toBool() ? tr("Yes", "roaming") : tr("No", "roaming")) );
  
  rs.append(tr("<br><b>VPN Provider</b><br>"));
  extractMapData(submap, services_list.at(index).objmap.value("Provider") );
  rs.append(tr("Host: %1<br>").arg(submap.value("Host").toString()) );
  rs.append(tr("Domain: %1<br>").arg(submap.value("Domain").toString()) );
  rs.append(tr("Name: %1<br>").arg(submap.value("Name").toString()) );
  rs.append(tr("Type: %1<br>").arg(submap.value("Type").toString()) );

  //  write the text to the right display label
  ui.label_details_right->setText(rs);

  // enable or disable the editor button
  if (map.value("Type").toString() == "vpn") b_editable = false; // can't edit vpn connections
  ui.pushButton_configuration->setEnabled(b_editable);

  return;
}

//
//  Slot to enter whats this mode
//  Called when the ui.toolButton_whatsthis clicked() signal is emitted
void ControlBox::showWhatsThis()
{
  QWhatsThis::enterWhatsThisMode();
}

//////////////////////////////////////////// Protected Functions //////////////////////////////////
//
// Close events for this dialog.  If there is a systemtray and it is visible
// then a close event will only minimize (for instance clicking the X in a
// window bar.  If there is no system tray or there is one but it is not
// visible then close the program.
void ControlBox::closeEvent(QCloseEvent* e)
{
	if (trayicon != 0 ) {
		if (trayicon->isVisible() ){
			this->hide();
			e->ignore();
		}	// if visible
	}	// if there is a tray icon
	else
		e->accept();
  return;
}

//
// Key event for this dialog. If escape is pressed, minimize instead of close if
// applicable.
void ControlBox::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Escape &&
	    trayicon != 0 &&
	    trayicon->isVisible()) {
		this->hide();
		return;
	}
        QDialog::keyPressEvent(e);
}

//
// Event filter used to filter out tooltip events if we don't want to see them
// in eventFilters return true eats the event, false passes on it.
bool ControlBox::eventFilter(QObject* obj, QEvent* evn)
{
  if (evn->type() == QEvent::ToolTip) {
    // first check if the object is the system tray icon
    QString objname = obj->metaObject()->className();
    if (objname.contains("QSystemTrayIconSys") ) {
      if (ui.checkBox_enablesystemtraytooltips->isChecked())
        return false;
      else
        return true;
    } // if obj is QSystemTrayIconSys

    // now check all the other interface widgets
    if (ui.checkBox_enableinterfacetooltips->isChecked())
      return false;
    else
      return true;
  } // event is a tooltip

  return false;
}

//////////////////////////////////////////// Private Functions ////////////////////////////////////
//
// Function to rescan connman properties, technologies and services
// Int return value is the errors encountered  
// This function is now really misnamed.  Originally we called it a lot, but now
// everything is dealt with using DBus signals so it is only called at startup
// as an initial scan.
int ControlBox::managerRescan(const int& srv)
{
  if ( ((q8_errors & CMST::Err_No_DBus) | (q8_errors & CMST::Err_Invalid_Con_Iface)) == 0x00 ) {

    // Reset the getXX errors, always a chance we could read them after
    // a previous error. Don't actually believe it, but just in case.
    q8_errors &= ~CMST::Err_Properties;
    q8_errors &= ~CMST::Err_Technologies;
    q8_errors &= ~CMST::Err_Services;

    // Access connman.manager to retrieve the data
    if (srv & CMST::Manager_Technologies) {
      if (! getTechnologies() ) {
        logErrors(CMST::Err_Technologies);
      } // if
      else {
        // connect technology signals to slots
        for (int i = 0; i < technologies_list.size(); ++i) {
          QDBusConnection::systemBus().disconnect(DBUS_CON_SERVICE, technologies_list.at(i).objpath.path(), "net.connman.Technology", "PropertyChanged", this, SLOT(dbsTechnologyPropertyChanged(QString, QDBusVariant, QDBusMessage)));
          QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, technologies_list.at(i).objpath.path(), "net.connman.Technology", "PropertyChanged", this, SLOT(dbsTechnologyPropertyChanged(QString, QDBusVariant, QDBusMessage)));
        } // for
      } //else
    } // if technolgies

    if (srv & CMST::Manager_Services) {
      if (! getServices() ) {
        logErrors(CMST::Err_Services);
      } // if
      // connect service signals to slots
      else {
        for (int i = 0; i < services_list.size(); ++i) {
          QDBusConnection::systemBus().disconnect(DBUS_CON_SERVICE, services_list.at(i).objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
          QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, services_list.at(i).objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));       
        } // for
      } // else
    } // if services

    if (srv & CMST::Manager_Properties) {
      if (! getProperties() ) logErrors(CMST::Err_Properties);
    }

  } // if

  return (q8_errors & CMST::Err_Properties) | (q8_errors & CMST::Err_Technologies) | (q8_errors & CMST::Err_Services);
}

//
//  Function to assemble status tab of the dialog
void ControlBox::assembleTabStatus()
{
  // Global Properties
  if ( (q8_errors & CMST::Err_Properties) == 0x00 ) {
    QString s1 = properties_map.value("State").toString();
    if (s1 == "online") {	
			ui.label_state_pix->setPixmap(iconman->getIcon("state_online").pixmap(QSize(16,16)) );
    } // if online
    else {
      if (s1 == "ready") {
				ui.label_state_pix->setPixmap(iconman->getIcon("state_ready").pixmap(QSize(16,16)) );
				      } // if ready
      else {
				ui.label_state_pix->setPixmap(iconman->getIcon("state_not_ready").pixmap(QSize(16,16)) );
      } // else any other state
    } //  else ready or any other state
    s1 = TranslateStrings::cmtr(s1);
    s1.prepend(tr("State: ") );
    ui.label_state->setText(s1);
   
    bool b1 = properties_map.value("OfflineMode").toBool();
    QString s2 = QString();
    if (b1) {
      s2 = tr("Engaged");
      ui.label_offlinemode_pix->setPixmap(QPixmap (iconman->getIconName("offline_mode_engaged")) );
    } // if offline mode is engaged

    else {
      s2 = tr("Disabled");
      ui.label_offlinemode_pix->setPixmap(QPixmap (iconman->getIconName("offline_mode_disengaged")) );
    } //  else offlinemode disabled
    s2.prepend(tr("Offline Mode "));
    ui.label_offlinemode->setText(s2);
  } // properties if no error

  // Technologies
  if ( (q8_errors & CMST::Err_Technologies) == 0x00 ) {
    QString st = QString();
    bool bt;
    ui.tableWidget_technologies->clearContents();
    ui.tableWidget_technologies->setRowCount(technologies_list.size() );
    ui.tableWidget_technologies->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui.tableWidget_technologies->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
      
		if (ui.checkBox_hidetethering->isChecked() ) {
			ui.tableWidget_technologies->hideColumn(4);
			ui.tableWidget_technologies->hideColumn(5);
			ui.pushButton_IDPass->setHidden(true);
		}
		else { 
			ui.tableWidget_technologies->showColumn(4);
			ui.tableWidget_technologies->showColumn(5);
			ui.pushButton_IDPass->setHidden(false);
		} 
		    
    for (int row = 0; row < technologies_list.size(); ++row) {
      QTableWidgetItem* qtwi00 = new QTableWidgetItem();
      st = technologies_list.at(row).objmap.value("Name").toString();
      qtwi00->setText(TranslateStrings::cmtr(st) );
      qtwi00->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_technologies->setItem(row, 0, qtwi00) ;

      QTableWidgetItem* qtwi01 = new QTableWidgetItem();
      st = technologies_list.at(row).objmap.value("Type").toString();
      qtwi01->setText(TranslateStrings::cmtr(st) );
      qtwi01->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_technologies->setItem(row, 1, qtwi01);

      idButton* qpb02 = new idButton(this, technologies_list.at(row).objpath);
      qpb02->setFixedSize(
        ui.tableWidget_technologies->horizontalHeader()->sectionSize(2),
        ui.tableWidget_technologies->verticalHeader()->sectionSize(0) );
      connect (qpb02, SIGNAL(clickedID(QString, bool)), this, SLOT(togglePowered(QString, bool)));
      QString padding = "     ";
      if (technologies_list.at(row).objmap.value("Powered").toBool()) {
        qpb02->setText(tr("%1On%1%1", "powered").arg(padding));
        qpb02->setIcon(QPixmap(":/icons/images/interface/golfball_green.png"));
        qpb02->setChecked(true);
      }
      else {
        qpb02->setText(tr("%1Off%1%1", "powered").arg(padding));
        qpb02->setIcon(QPixmap(":/icons/images/interface/golfball_red.png"));
        qpb02->setChecked(false);
      }
      ui.tableWidget_technologies->setCellWidget(row, 2, qpb02);

      QTableWidgetItem* qtwi03 = new QTableWidgetItem();
      bt = technologies_list.at(row).objmap.value("Connected").toBool();
      qtwi03->setText( bt ? tr("Yes", "connected") : tr("No", "connected") );
      qtwi03->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_technologies->setItem(row, 3, qtwi03);
 
      idButton* qpb04 = new idButton(this, technologies_list.at(row).objpath);
      qpb04->setFixedSize(
        ui.tableWidget_technologies->horizontalHeader()->sectionSize(4),
        ui.tableWidget_technologies->verticalHeader()->sectionSize(0) );
      connect (qpb04, SIGNAL(clickedID(QString, bool)), this, SLOT(toggleTethered(QString, bool)));
      if (technologies_list.at(row).objmap.value("Tethering").toBool()) {
        qpb04->setText(tr("%1On%1%1", "tethering").arg(padding));
        qpb04->setIcon(QPixmap(":/icons/images/interface/golfball_green.png"));
        qpb04->setChecked(true);
      }
      else {
        qpb04->setText(tr("%1Off%1%1", "tethering").arg(padding));
        qpb04->setIcon(QPixmap(":/icons/images/interface/golfball_red.png"));
        qpb04->setChecked(false);
        if (technologies_list.at(row).objmap.value("Type").toString() == "ethernet")
					qpb04->setDisabled(true);
				else 
					qpb04->setEnabled(technologies_list.at(row).objmap.value("Powered").toBool() );	
      }
			ui.tableWidget_technologies->setCellWidget(row, 4, qpb04); 
	
			QTableWidgetItem* qtwi05 = new QTableWidgetItem();
      QString sid = technologies_list.at(row).objmap.value("TetheringIdentifier").toString();
      QString spw = technologies_list.at(row).objmap.value("TetheringPassphrase").toString();
      if (sid.isEmpty() ) sid = "--";
      if (spw.isEmpty() ) spw = "--";
      qtwi05->setText(QString("%1 : %2").arg(sid).arg(spw) );
      qtwi05->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_technologies->setItem(row, 5, qtwi05);
       	   
    } // technologies for loop
    
		// resize the columns to contents
		ui.tableWidget_technologies->resizeColumnToContents(0);
		ui.tableWidget_technologies->resizeColumnToContents(1);
		ui.tableWidget_technologies->resizeColumnToContents(3); 
				 
  } // technologies if no error

  // Services
  if ( (q8_errors & CMST::Err_Services) == 0x00 ) {
    QString ss = QString();
    ui.tableWidget_services->clearContents();
    ui.tableWidget_services->setRowCount(services_list.size() );
 
     if (ui.checkBox_hidecnxn->isChecked() ) {
			ui.tableWidget_services->hideColumn(3);
		}
		else {
			ui.tableWidget_services->showColumn(3);
			ui.tableWidget_services->horizontalHeader()->resizeSection(1, ui.tableWidget_services->horizontalHeader()->defaultSectionSize());
		}
    for (int row = 0; row < services_list.size(); ++row) {
      QTableWidgetItem* qtwi00 = new QTableWidgetItem();
      ss = getNickName(services_list.at(row).objpath);
      qtwi00->setText(TranslateStrings::cmtr(ss) );
      qtwi00->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_services->setItem(row, 0, qtwi00);
      
      QTableWidgetItem* qtwi01 = new QTableWidgetItem();
      ss = services_list.at(row).objmap.value("Type").toString();
      qtwi01->setText(TranslateStrings::cmtr(ss) );
      qtwi01->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_services->setItem(row, 1, qtwi01);

      QTableWidgetItem* qtwi02 = new QTableWidgetItem();
      ss = services_list.at(row).objmap.value("State").toString();
      qtwi02->setText(TranslateStrings::cmtr(ss) );
      qtwi02->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_services->setItem(row, 2, qtwi02);

      QTableWidgetItem* qtwi03 = new QTableWidgetItem();
      QFileInfo fi = services_list.at(row).objpath.path();
      qtwi03->setText(fi.baseName() );
      qtwi03->setTextAlignment(Qt::AlignVCenter|Qt::AlignLeft);
      ui.tableWidget_services->setItem(row, 3, qtwi03);
      
    } // services for loop

    // resize the services columns to contents
    ui.tableWidget_services->resizeColumnToContents(0);
    ui.tableWidget_services->resizeColumnToContents(1);
    ui.tableWidget_services->resizeColumnToContents(2);

  } // services if no error

  return;
}

//
//  Function to assemble details tab of the dialog.  Only fill in the
//  ui.comboBox_service widget.  The detail portion will be filled in
//  by the getServiceDetails() slot whenever the comboBox index changes.
void ControlBox::assembleTabDetails()
{
  // initilize the page2 display widgets
  ui.comboBox_service->clear();
  ui.label_details_left->clear();
  ui.label_details_right->clear();

  //  services details
  if ( (q8_errors & CMST::Err_Services) == 0x00 ) {
	  // populate the combobox
	  for (int row = 0; row < services_list.size(); ++row) {
			QString ss = getNickName(services_list.at(row).objpath);
				ui.comboBox_service->addItem(TranslateStrings::cmtr(ss) );
	  } // services for loop
	   ui.comboBox_service->setCurrentIndex(0);
  } // services if no error

  return;
}

//
//  Function to assemble the wireless tab of the dialog.
void ControlBox::assembleTabWireless()
{
  //  initilize the table
  ui.tableWidget_wifi->clearContents();
  ui.tableWidget_wifi->setRowCount(0);
  int rowcount = 0;

  // Make sure we got the services_list before we try to work with it.
  if ( (q8_errors & CMST::Err_Services) != 0x00 ) return;

  // Run through the technologies again, this time only look for wifi
  if ( (q8_errors & CMST::Err_Technologies) == 0x00 ) {
    int i_wifidevices= 0;
    int i_wifipowered = 0;
    for (int row = 0; row < technologies_list.size(); ++row) {
      if (technologies_list.at(row).objmap.value("Type").toString() == "wifi" ) {
        ++i_wifidevices;
        if (technologies_list.at(row).objmap.value("Powered").toBool() ) ++i_wifipowered;
      } // if census
    } // for loop
    ui.label_wifi_state->setText(tr("  WiFi Technologies:<br>  %1 Found, %2 Powered").arg(i_wifidevices).arg(i_wifipowered) );
  } // technologis if no errors

  // Run through each service_list looking for wifi services
  wifi_list.clear();

	// set the stylesheet for signalbars
	QFile f0(":/stylesheets/stylesheets/signal_bar.qss");
	QString qss;
	if (f0.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qss = QString(f0.readAll());
		if (QColor(ui.lineEdit_colorize->text()).isValid() ) {
			qss = qss.left(qss.lastIndexOf('}') );
			qss.append(QString("background-color: %1;").arg(ui.lineEdit_colorize->text()) );
			qss.append('}'); 
		}
		f0.close();
	}
  
  for (int row = 0; row < services_list.size(); ++row) {
    QMap<QString,QVariant> map = services_list.at(row).objmap;
    if (map.value("Type").toString() == "wifi") {
      wifi_list.append(services_list.at(row));
      ui.tableWidget_wifi->setRowCount(rowcount + 1);

      QTableWidgetItem* qtwi00 = new QTableWidgetItem();
      qtwi00->setText(getNickName(services_list.at(row).objpath) );
      qtwi00->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_wifi->setItem(rowcount, 0, qtwi00);

      QLabel* ql01 = new QLabel(ui.tableWidget_wifi);
      if (map.value("Favorite").toBool() ) {
				ql01->setPixmap(iconman->getIcon("favorite").pixmap(QSize(16,16)) );
      }
      ql01->setAlignment(Qt::AlignCenter);
      ui.tableWidget_wifi->setCellWidget(rowcount, 1, ql01);
 
      QLabel* ql02 = new QLabel(ui.tableWidget_wifi);
      if (map.value("State").toString() == "online") {
				ql02->setPixmap(iconman->getIcon("state_online").pixmap(QSize(16,16)) );
      } // if online
      else {
        if (map.value("State").toString() == "ready") {
					ql02->setPixmap(iconman->getIcon("state_ready").pixmap(QSize(16,16)) );
        } // if ready
        else {
					ql02->setPixmap(iconman->getIcon("state_not_ready").pixmap(QSize(16,16)) );
        } // else any other state
      } // else ready or any other state
      ql02->setAlignment(Qt::AlignCenter);
      ql02->setToolTip(TranslateStrings::cmtr(map.value("State").toString()) );
      ui.tableWidget_wifi->setCellWidget(rowcount, 2, ql02);

      QTableWidgetItem* qtwi03 = new QTableWidgetItem();
      QStringList sl_tr;
      for (int i = 0; i < map.value("Security").toStringList().size(); ++i) {
				sl_tr << TranslateStrings::cmtr(map.value("Security").toStringList().at(i) );
			}	// for
			qtwi03->setText(sl_tr.join(',') );
      qtwi03->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_wifi->setItem(rowcount, 3, qtwi03);

      QProgressBar* pb04 = new QProgressBar(ui.tableWidget_wifi);
      pb04->setMinimum(0);
			pb04->setMaximum(100);
			pb04->setOrientation( Qt::Horizontal);
			pb04->setStyleSheet(qss);
      pb04->setValue(map.value("Strength").value<quint8>() );
      ui.tableWidget_wifi->setCellWidget(rowcount, 4, pb04);

      ++rowcount;
    } //  if wifi cnxn
  } // services for loop

  // resize the services column 0 to 4 to contents
  ui.tableWidget_wifi->resizeColumnToContents(0);
  ui.tableWidget_wifi->resizeColumnToContents(1);
  ui.tableWidget_wifi->resizeColumnToContents(2);
  ui.tableWidget_wifi->resizeColumnToContents(3);

  // enable the control buttons if there is at least on line in the table
  bool b_enable = false;
  if ( wifi_list.count() > 0 ) b_enable = true;
  ui.pushButton_connect->setEnabled(b_enable);
  ui.pushButton_disconnect->setEnabled(b_enable);
  ui.pushButton_remove->setEnabled(b_enable);

  return;
}

//
// FUnction to assemble the VPN tab of the dialog
void ControlBox::assembleTabVPN()
{
  //  initilize the table
  ui.tableWidget_vpn->clearContents();
  ui.tableWidget_vpn->setRowCount(0);
  int rowcount = 0;

  // Make sure we got the services_list before we try to work with it.
  if ( (q8_errors & CMST::Err_Services) != 0x00 ) return;	
  
// Run through each service_list looking for wifi services
  vpn_list.clear();
  for (int row = 0; row < services_list.size(); ++row) {
    QMap<QString,QVariant> map = services_list.at(row).objmap;
    if (map.value("Type").toString() == "vpn") {
      vpn_list.append(services_list.at(row));
      ui.tableWidget_vpn->setRowCount(rowcount + 1);    
      QMap<QString,QVariant> providermap;
      extractMapData(providermap, services_list.at(row).objmap.value("Provider") );
      
      QTableWidgetItem* qtwi00 = new QTableWidgetItem();
      qtwi00->setText(getNickName(services_list.at(row).objpath) );
      qtwi00->setTextAlignment(Qt::AlignCenter);
      ui.tableWidget_vpn->setItem(rowcount, 0, qtwi00);

      QLabel* ql01 = new QLabel(ui.tableWidget_vpn);
			ql01->setText(TranslateStrings::cmtr(providermap.value("Type").toString()) );
			ql01->setAlignment(Qt::AlignCenter);
			ui.tableWidget_vpn->setCellWidget(rowcount, 1, ql01);    
 
			if (map.value("State").toString() == "association") {
				QProgressBar* pb02 = new QProgressBar(ui.tableWidget_vpn);
				pb02->setMinimum(0);
				pb02->setMaximum(0);
				pb02->setOrientation( Qt::Horizontal);
				pb02->setFormat("Connecting");
				// set the stylesheet on pb02
				QFile f0(":/stylesheets/stylesheets/vpn_connecting.qss");
				if (f0.open(QIODevice::ReadOnly | QIODevice::Text)) {
					QString qss = QString(f0.readAll());
					if (QColor(ui.lineEdit_colorize->text()).isValid() ) {
						qss = qss.left(qss.lastIndexOf('}') );
						qss.append(QString("background-color: %1;").arg(ui.lineEdit_colorize->text()) );
						qss.append('}'); 
					}
					f0.close();
					pb02->setStyleSheet(qss);
				}

				ui.tableWidget_vpn->setCellWidget(rowcount, 2, pb02);
			} // if association
			else {
				QLabel* ql02 = new QLabel(ui.tableWidget_vpn);
				if (map.value("State").toString() == "ready") {
				ql02->setPixmap(iconman->getIcon("state_vpn_connected").pixmap(QSize(16,16)) );
				} // if ready
				else {
					ql02->setPixmap(iconman->getIcon("state_not_ready").pixmap(QSize(16,16)) );
				} // else any other state
			  ql02->setAlignment(Qt::AlignCenter);
				ql02->setToolTip(TranslateStrings::cmtr(map.value("State").toString()) );
				ui.tableWidget_vpn->setCellWidget(rowcount, 2, ql02);
			}	// else not association 
			
      QLabel* ql03 = new QLabel(ui.tableWidget_vpn);
      ql03->setText(providermap.value("Host").toString() );
			ql03->setAlignment(Qt::AlignCenter);
			ui.tableWidget_vpn->setCellWidget(rowcount, 3, ql03);
      
      QLabel* ql04 = new QLabel(ui.tableWidget_vpn);
			QFileInfo fi = services_list.at(row).objpath.path();
			ql04->setText(fi.baseName() );
			ql04->setAlignment(Qt:: AlignCenter);
			ui.tableWidget_vpn->setCellWidget(rowcount, 4, ql04);
						     
      ++rowcount;
    } //  if vpn cnxn
  } // services for loop 
  
  // resize the services column 0 to 3 to contents
  ui.tableWidget_vpn->resizeColumnToContents(0);
  ui.tableWidget_vpn->resizeColumnToContents(1);
  ui.tableWidget_vpn->resizeColumnToContents(2);
  ui.tableWidget_vpn->resizeColumnToContents(3);
  
  // enable the control buttons if there is at least on line in the table
  bool b_enable = false;
  if ( vpn_list.count() > 0 ) b_enable = true;
  ui.pushButton_vpn_connect->setEnabled(b_enable);
  ui.pushButton_vpn_disconnect->setEnabled(b_enable);
	
	return;
}

//
//  Function to assemble the counters tab of the dialog.
void ControlBox::assembleTabCounters()
{
  // Text for the counter settings label
  ui.label_counter_settings->setText(tr("Update resolution of the counters is based on a threshold of %L1 KB of data and %L2 seconds of time.")   \
      .arg(counter_accuracy)  \
      .arg(counter_period) );

  return;
}

//
//  Function to assemble the tray icon tooltip text and picture.  Called
//  mainly from updateDisplayWidgets(), also from createSystemTrayIcon()
void ControlBox::assembleTrayIcon()
{
  QString stt = QString();
  int readycount = 0;
  QIcon prelimicon;
  
  if ( (q8_errors & CMST::Err_Properties & CMST::Err_Services) == 0x00 ) {
    // count how many services are in the ready state
    for (int i = 0; i < services_list.count(); ++i) {
      if (services_list.at(i).objmap.value("State").toString() == "ready")  ++readycount;
    } // readycount for loop
    if ((properties_map.value("State").toString() == "online") ||
        (properties_map.value("State").toString() == "ready" && readycount == 1) ) {
      if ( (q8_errors & CMST::Err_Services) == 0x00 ) {
        QMap<QString,QVariant> submap;
        if (services_list.at(0).objmap.value("Type").toString() == "ethernet") {
          extractMapData(submap, services_list.at(0).objmap.value("Ethernet") );
          stt.prepend(tr("Ethernet Connection<br>","icon_tool_tip"));
          stt.append(tr("Service: %1<br>").arg(getNickName(services_list.at(0).objpath)) );
          stt.append(tr("Interface: %1").arg(TranslateStrings::cmtr(submap.value("Interface").toString())) );
          prelimicon = iconman->getIcon("connection_wired");
        } //  if wired connection

        else if (services_list.at(0).objmap.value("Type").toString() == "wifi") {
          stt.prepend(tr("WiFi Connection<br>","icon_tool_tip"));
          extractMapData(submap, services_list.at(0).objmap.value("Ethernet") );
          stt.append(tr("SSID: %1<br>").arg(getNickName(services_list.at(0).objpath)) );
          QStringList sl_tr;
					for (int i = 0; i < services_list.at(0).objmap.value("Security").toStringList().size(); ++i) {
						sl_tr << TranslateStrings::cmtr(services_list.at(0).objmap.value("Security").toStringList().at(i) );
					}	// for
          stt.append(tr("Security: %1<br>").arg(sl_tr.join(',')) );
          stt.append(tr("Strength: %1%<br>").arg(services_list.at(0).objmap.value("Strength").value<quint8>()) );
          stt.append(tr("Interface: %1").arg(TranslateStrings::cmtr(submap.value("Interface").toString())) );
          quint8 str = services_list.at(0).objmap.value("Strength").value<quint8>();
          if (str > 80 ) prelimicon = iconman->getIcon("connection_wifi_100");
          else if (str > 60 ) prelimicon = iconman->getIcon("connection_wifi_075");  
            else if (str > 40 )   prelimicon = iconman->getIcon("connection_wifi_050");
              else if (str > 20 )   prelimicon = iconman->getIcon("connection_wifi_025");
                else prelimicon = iconman->getIcon("connection_wifi_000");
        } // else if wifi connection
        
        else if (services_list.at(0).objmap.value("Type").toString() == "vpn") {
					extractMapData(submap, services_list.at(0).objmap.value("Provider") );
          stt.prepend(tr("VPN Connection<br>","icon_tool_tip"));
          stt.append(tr("Type: %1<br>").arg(TranslateStrings::cmtr(submap.value("Type").toString())) );
          stt.append(tr("Service: %1<br>").arg(services_list.at(0).objmap.value("Name").toString()) );
          stt.append(tr("Host: %1<br>").arg(TranslateStrings::cmtr(submap.value("Host").toString())) );
          prelimicon = iconman->getIcon("connection_vpn");
				}	// else if vpn connection     
      } //  services if no error
    } //  if the state is online

    // else if state is ready
    else if (properties_map.value("State").toString() == "ready") {
        prelimicon = iconman->getIcon("connection_ready");
      stt.append(tr("Connection is in the Ready State.", "icon_tool_tip"));
    } // else if if ready

    // else if state is failure
    else if (properties_map.value("State").toString() == "failure") {
      // try to reconnect if service is wifi and Favorite and if reconnect is specified
      if (ui.checkBox_retryfailed->isChecked() ) {
        if (services_list.at(0).objmap.value("Type").toString() =="wifi"  && services_list.at(0).objmap.value("Favorite").toBool() ) {
          QDBusInterface* iface_serv = new QDBusInterface(DBUS_CON_SERVICE, services_list.at(0).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
          QDBusMessage reply = iface_serv->call(QDBus::AutoDetect, "Connect");
          iface_serv->deleteLater();
          stt.append(tr("Connection is in the Failure State, attempting to reestablish the connection", "icon_tool_tip") );
        } // if wifi and favorite
      } // if retry checked
      prelimicon = iconman->getIcon("state_online");
      stt.append(tr("Connection is in the Failure State.", "icon_tool_tip"));
    } // else if failure state

    // else anything else, states in this case should be "idle", "association", "configuration", or "disconnect"
    else {
			prelimicon = iconman->getIcon("connection_not_ready");
      stt.append(tr("Not Connected", "icon_tool_tip"));
    } // else any other connection sate
  } // properties if no error

  // could not get any properties
  else {
		prelimicon = iconman->getIcon("connection_error");
    stt.append(tr("Error retrieving properties via Dbus"));
    stt.append(tr("Connection status is unknown"));
  }

  // Set the tray icon.  If the trayiconbackground color is valid and 
  // there is a valid alpha channel convert the alpha to the background
  // color to get our fake transparency.  Fake transparency can be set as a command
  // line option so trayiconbackground is set up in the constructor.
  // Otherwise just convert the image to ARGB32 which seems to be required
  // for the icons to display in Plasma5.
  // First convert from a QIcon through QPixmap to QImage
  QPixmap pxm = prelimicon.pixmap(prelimicon.actualSize(QSize(22,22)) );
  QImage src = pxm.toImage();  
 	QImage dest = QImage(src.width(), src.height(), QImage::Format_ARGB32);
	QPainter painter(&dest); 
  if (trayiconbackground.isValid() && src.hasAlphaChannel() ) {
		painter.setCompositionMode(QPainter::CompositionMode_Source);
		painter.fillRect(dest.rect(), trayiconbackground);
		painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
	}	// if img has alpha channel and background color valid
	else {
		painter.setCompositionMode(QPainter::CompositionMode_Source);
	}	// else just make an ARGB32 copy	
	painter.drawImage(0, 0, src);
	prelimicon = QIcon(QPixmap::fromImage(dest));
  trayicon->setIcon(prelimicon);

  //  Set the tool tip (shown when mouse hovers over the systemtrayicon)
  trayicon->setToolTip(stt);

	// Don't continue if we can't get properties
	if ( (q8_errors & CMST::Err_Properties & CMST::Err_Technologies & CMST::Err_Services) != 0x00 ) return;
	
  // Assemble the submenus for the context menu
  // tech_submenu.  
  tech_submenu->clear();
  for (int i = 0; i < technologies_list.count(); ++i) {
		QAction* act = tech_submenu->addAction(technologies_list.at(i).objmap.value("Name").toString() );
		act->setCheckable(true);
		act->setChecked(technologies_list.at(i).objmap.value("Powered").toBool() );
		QString ttstr = QString(tr("<p style='white-space:pre'><center><b>%1 Properties</b></center>").arg(TranslateStrings::cmtr(technologies_list.at(i).objmap.value("Name").toString())) );
		ttstr.append(tr("Type: %1").arg(technologies_list.at(i).objmap.value("Type").toString()) );
		ttstr.append(tr("<br>Powered "));
		technologies_list.at(i).objmap.value("Powered").toBool() ? ttstr.append(tr("On")) : ttstr.append(tr("Off"));
		ttstr.append("<br>");
		technologies_list.at(i).objmap.value("Connected").toBool() ? ttstr.append(tr("Connected")) : ttstr.append(tr("Not Connected"));	
		ttstr.append(tr("<br>Tethering "));
		technologies_list.at(i).objmap.value("Tethering").toBool() ? ttstr.append(tr("Enabled")) : ttstr.append(tr("Disabled"));	
		act->setToolTip(ttstr);
	}	// i for
  
  // info_submenu
  info_submenu->clear();
  for (int j = 0; j < services_list.count(); ++j) {
    QAction* act = info_submenu->addAction(getNickName(services_list.at(j).objpath) );
		if (services_list.at(j).objmap.value("Type").toString() == "ethernet" ) {
		  if (services_list.at(j).objmap.value("State").toString() == "online")
				act->setIcon(iconman->getIcon("connection_wired"));
			else
				if(services_list.at(j).objmap.value("State").toString() == "ready")
					act->setIcon(iconman->getIcon("connection_ready"));
				else
					act->setIcon(iconman->getIcon("connection_not_ready"));
		}	// if wired
		
		else if (services_list.at(j).objmap.value("Type").toString() == "wifi" ) {
			if (services_list.at(j).objmap.value("State").toString() == "online" ||
					(properties_map.value("State").toString() != "online" &&
					(services_list.at(j).objmap.value("State").toString() == "ready" && readycount == 1)) ) {
				quint8 str = services_list.at(j).objmap.value("Strength").value<quint8>();
				if (str > 80 ) act->setIcon(iconman->getIcon("connection_wifi_100") );
				else if (str > 60 ) act->setIcon(iconman->getIcon("connection_wifi_075") );  
					else if (str > 40 )   act->setIcon(iconman->getIcon("connection_wifi_050") );
						else if (str > 20 )   act->setIcon(iconman->getIcon("connection_wifi_025") );
							else act->setIcon(iconman->getIcon("connection_wifi_000") );
			}	// if we want to show a wifi signal symbol
			else
				if(services_list.at(j).objmap.value("State").toString() == "ready")
					act->setIcon(iconman->getIcon("connection_ready"));
				else
					act->setIcon(iconman->getIcon("connection_not_ready"));
		}	// else if wifi
		
		else if (services_list.at(j).objmap.value("Type").toString() == "vpn" ) {
			if (services_list.at(j).objmap.value("State").toString() == "ready")
				act->setIcon(iconman->getIcon("connection_vpn"));
			else if (services_list.at(j).objmap.value("State").toString() == "association")
				act->setIcon(iconman->getIcon("connection_vpn_acquiring"));				
			else	
				act->setIcon(iconman->getIcon("connection_not_ready"));
		}	// else if vpn
		
		else if (services_list.at(j).objmap.value("State").toString() == "ready") act->setIcon(iconman->getIcon("connection_ready"));
			else if (services_list.at(j).objmap.value("State").toString() == "failure" ) act->setIcon(iconman->getIcon("connection_failure"));
				else act->setIcon(iconman->getIcon("connection_not_ready"));
  } // j for
  
  // wifi_submenu.  
  wifi_submenu->clear();
  for (int k = 0; k < wifi_list.count(); ++k) {
    QAction* act = wifi_submenu->addAction(getNickName(wifi_list.at(k).objpath) );
    act->setCheckable(true);
    QString state = wifi_list.at(k).objmap.value("State").toString();
		if (state == "online" || state == "ready") act->setChecked(true);
    QString ttstr = QString(tr("<p style='white-space:pre'><center><b>%1</b></center>").arg(getNickName(wifi_list.at(k).objpath)) );
    ttstr.append(tr("Connection : %1").arg(TranslateStrings::cmtr(state)) );
    ttstr.append("<br>");
    ttstr.append(tr("Signal Strength: %1%").arg(wifi_list.at(k).objmap.value("Strength").toInt()) );
    ttstr.append("<br>");
    wifi_list.at(k).objmap.value("Favorite").toBool() ? ttstr.append(tr("Favorite Connection")) : ttstr.append(tr("Never Connected"));
    ttstr.append(tr("<br>Security : %1").arg(wifi_list.at(k).objmap.value("Security").toString()) );
    if (wifi_list.at(k).objmap.value("Roaming").toBool() ) ttstr.append(tr("<br>Roaming"));
    ttstr.append(tr("<br>Autoconnect is "));
    wifi_list.at(k).objmap.value("AutoConnect").toBool() ? ttstr.append(tr("Enabled")) : ttstr.append(tr("Disabled"));
    act->setToolTip(ttstr);
  } // k for
  
  // vpn_submenu
  vpn_submenu->clear();	
  for (int l = 0; l < vpn_list.count(); ++l) {
    QAction* act = vpn_submenu->addAction(getNickName(vpn_list.at(l).objpath) );
    act->setCheckable(true);
    QString state = vpn_list.at(l).objmap.value("State").toString();
		if (state == "ready") act->setChecked(true);
    QString ttstr = QString(tr("<p style='white-space:pre'><center><b>%1</b></center>").arg(getNickName(vpn_list.at(l).objpath)) );
    ttstr.append(tr("Connection : %1").arg(TranslateStrings::cmtr(state)) );
    act->setToolTip(ttstr);
  } // l for
  
  return;
}

// Handler for left click on tray icon
void ControlBox::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
  //Only handling left click case
  if(reason == QSystemTrayIcon::Trigger)
  {
    //Show the window if it is currently hidden/minimized
    if(this->isHidden() || this->isMinimized())
    {
      minMaxWindow(maximizeAction);
    }
    //Otherwise hide the window
    else
    {
      minMaxWindow(minimizeAction);
    }
  }
}

void ControlBox::enableRunOnStartup(bool enabled)
{
  QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
  QString HOME = env.value("HOME");
  QString XDG_CONFIG_HOME = env.value("XDG_CONFIG_HOME", QFileInfo(QDir(HOME), ".config").absoluteFilePath());
  QFileInfo autostart_dir_info(QDir(XDG_CONFIG_HOME), "autostart");
  QFileInfo autostart_file_info(QDir(autostart_dir_info.absoluteFilePath()), "cmst-autostart.desktop");
  QFile user_autostart_file(autostart_file_info.absoluteFilePath());

  if (enabled) {
    QCryptographicHash hasher(QCryptographicHash::Sha1);
    QFile fileToCopy("/usr/share/cmst/autostart/cmst-autostart.desktop");

    if (user_autostart_file.exists()) {
      hasher.reset();
      hasher.addData(&fileToCopy);
      QByteArray orig_file_hash = hasher.result();

      hasher.reset();
      hasher.addData(&user_autostart_file);
      QByteArray user_autostart_file_hash = hasher.result();

      if (orig_file_hash == user_autostart_file_hash) {
        return;
      }

      if (!user_autostart_file.remove()) {
        return;
      }
    }
    // Copy the autostart file (create the target directory first if needed)
    QDir dir = autostart_file_info.dir();
    if (! dir.exists() ) dir.mkdir(autostart_file_info.path() );
    fileToCopy.copy(autostart_file_info.absoluteFilePath());

  } // if enabled
  else {
    if (!autostart_file_info.exists()) {
        return;
    }
    user_autostart_file.remove();
  }
}

// Slot to save GUI settings to disk
void ControlBox::writeSettings()
{
  settings->beginGroup("MainWindow");
  settings->setValue("size", this->size() );
  settings->setValue("pos", this->pos() );
  settings->setValue("current_page", ui.tabWidget->currentIndex());
  settings->endGroup();

  settings->beginGroup("CheckBoxes");
  settings->setValue("hide_tray_icon", ui.checkBox_hideIcon->isChecked() );
  settings->setValue("devices_off", ui.checkBox_devicesoff->isChecked() );
  settings->setValue("retain_settings", ui.checkBox_usestartoptions->isChecked() );
  settings->setValue("retain_state", ui.checkBox_retainstate->isChecked() );
  settings->setValue("services_less", ui.checkBox_hidecnxn->isChecked() );
  settings->setValue("technologies_less", ui.checkBox_hidetethering->isChecked() );
  settings->setValue("enable_interface_tooltips", ui.checkBox_enableinterfacetooltips->isChecked() );
  settings->setValue("enable_systemtray_tooltips", ui.checkBox_enablesystemtraytooltips->isChecked() );
  settings->setValue("enable_systemtray_notications", ui.checkBox_systemtraynotifications->isChecked() );
  settings->setValue("enable_daemon_notifications", ui.checkBox_notifydaemon->isChecked() );
  settings->setValue("reset_counters", ui.checkBox_resetcounters->isChecked() );
  settings->setValue("advanced", ui.checkBox_advanced->isChecked() );
  settings->setValue("retry_failed", ui.checkBox_retryfailed->isChecked() );
  settings->setValue("run_on_startup", ui.checkBox_runonstartup->isChecked());
  settings->endGroup();
  
  settings->beginGroup("LineEdits");
  settings->setValue("colorize_icons", ui.lineEdit_colorize->text() );
  settings->endGroup();  

  settings->beginGroup("StartOptions");
  settings->setValue("disable_counters", ui.checkBox_disablecounters->isChecked() );
  settings->setValue("disable_tray_icon", ui.checkBox_disabletrayicon->isChecked() );
  settings->setValue("use_icon_theme", ui.checkBox_systemicontheme->isChecked() );
  settings->setValue("icon_theme", ui.lineEdit_icontheme->text() );
  settings->setValue("start_minimized", ui.checkBox_startminimized->isChecked() );
  settings->setValue("use_wait_time", ui.checkBox_waittime->isChecked() );
  settings->setValue("wait_time", ui.spinBox_waittime->value() );
  settings->setValue("use_counter_update_rate", ui.checkBox_counterseconds->isChecked() );
  settings->setValue("counter_update_rate", ui.spinBox_counterrate->value() );
  settings->setValue("use_fake_transparency", ui.checkBox_faketranparency->isChecked() );
  settings->setValue("fake_transparency_color", ui.spinBox_faketransparency->value() );
  settings->setValue("desktop_none", ui.radioButton_desktopnone->isChecked() );
  settings->setValue("desktop_xfce", ui.radioButton_desktopxfce->isChecked() );
  settings->setValue("desktop_mate", ui.radioButton_desktopmate->isChecked() );
  settings->endGroup();
  
  settings->beginGroup("ExternalPrograms");
  settings->setValue("run_after_connect", ui.lineEdit_afterconnect->text() );
  settings->endGroup();
  
  return;
}

//
// Slot to read GUI settings to disk
void ControlBox::readSettings()
{
  settings->beginGroup("CheckBoxes");
  ui.checkBox_hideIcon->setChecked(settings->value("hide_tray_icon").toBool() );
  ui.checkBox_devicesoff->setChecked(settings->value("devices_off").toBool() );
  ui.checkBox_usestartoptions->setChecked(settings->value("retain_settings").toBool() );
  ui.checkBox_retainstate->setChecked(settings->value("retain_state").toBool() );
  ui.checkBox_hidecnxn->setChecked(settings->value("services_less").toBool() );
  ui.checkBox_hidetethering->setChecked(settings->value("technologies_less").toBool() );
  ui.checkBox_enableinterfacetooltips->setChecked(settings->value("enable_interface_tooltips").toBool() );
  ui.checkBox_enablesystemtraytooltips->setChecked(settings->value("enable_systemtray_tooltips").toBool() );
  ui.checkBox_systemtraynotifications->setChecked(settings->value("enable_systemtray_notications").toBool() );
  ui.checkBox_notifydaemon->setChecked(settings->value("enable_daemon_notifications").toBool() );
  ui.checkBox_resetcounters->setChecked(settings->value("reset_counters").toBool() );
  ui.checkBox_advanced->setChecked(settings->value("advanced").toBool() );
  ui.checkBox_retryfailed->setChecked(settings->value("retry_failed").toBool() );
  ui.checkBox_runonstartup->setChecked(settings->value("run_on_startup").toBool());
  settings->endGroup();
 
  settings->beginGroup("LineEdits");
  ui.lineEdit_colorize->setText(settings->value("colorize_icons").toString() );
  settings->endGroup();
  

  settings->beginGroup("StartOptions");
  ui.checkBox_disablecounters->setChecked(settings->value("disable_counters").toBool() );
  ui.checkBox_disabletrayicon->setChecked(settings->value("disable_tray_icon").toBool() );
  ui.checkBox_systemicontheme->setChecked(settings->value("use_icon_theme").toBool() );
  ui.lineEdit_icontheme->setText(settings->value("icon_theme").toString() );
  ui.checkBox_startminimized->setChecked(settings->value("start_minimized").toBool() );
  ui.checkBox_waittime->setChecked(settings->value("use_wait_time").toBool() );
  ui.spinBox_waittime->setValue(settings->value("wait_time").toInt() );
  ui.checkBox_counterseconds->setChecked(settings->value("use_counter_update_rate").toBool() );
  ui.spinBox_counterrate->setValue(settings->value("counter_update_rate").toInt() );
  ui.checkBox_faketranparency->setChecked(settings->value("use_fake_transparency").toBool() );
  ui.spinBox_faketransparency->setValue(settings->value("fake_transparency_color").toInt() );
  ui.radioButton_desktopnone->setChecked(settings->value("desktop_none").toBool() );
  ui.radioButton_desktopxfce->setChecked(settings->value("desktop_xfce").toBool() );
  ui.radioButton_desktopmate->setChecked(settings->value("desktop_mate").toBool() );
  settings->endGroup();
  
  settings->beginGroup("ExternalPrograms");
  ui.lineEdit_afterconnect->setText(settings->value("run_after_connect").toString() );
  settings->endGroup();
  
  return;
}

//
// Slot to create the systemtray icon.  Really part of the constructor
// and called by a single shot QTimer.
void ControlBox::createSystemTrayIcon()
{
	// Search for a tray icon, don't read XDG_CURRENT_DESKTOP for the tray type
	bool b_dtaware = qApp->desktopSettingsAware();
	qApp->setDesktopSettingsAware(false);
	
  // We still need to make sure there is a tray available
  if (QSystemTrayIcon::isSystemTrayAvailable() ) {

    // Create the systemtrayicon
    trayicon = new QSystemTrayIcon(this);

    // Create the outline of the context menu.  Submenu contents are defined in the
    // assembletrayIcon() function.
    trayiconmenu->clear();
    trayiconmenu->setTearOffEnabled(true);
    trayiconmenu->setToolTipsVisible(true);
    tech_submenu->setToolTipsVisible(true);
    info_submenu->setToolTipsVisible(true);
    wifi_submenu->setToolTipsVisible(true);
    vpn_submenu->setToolTipsVisible(true);
    
    trayiconmenu->addMenu(tech_submenu);
    trayiconmenu->addMenu(info_submenu);
    trayiconmenu->addMenu(wifi_submenu);
    trayiconmenu->addMenu(vpn_submenu);
    trayiconmenu->addSeparator();
    
    trayiconmenu->addAction(ui.actionRescan);
		trayiconmenu->addAction(ui.actionOffline_Mode);
		trayiconmenu->addSeparator();
	
		trayiconmenu->addAction(maximizeAction);
		trayiconmenu->addAction(minimizeAction);
		trayiconmenu->addSeparator();
		trayiconmenu->addAction(tr("Cancel"), this, SLOT(closeSystemTrayTearOffMenu()) );
		trayiconmenu->addAction(exitAction);
   
		trayicon->setContextMenu(trayiconmenu);
    
    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    // Assemble the tray icon (set the icon to display)
    assembleTrayIcon();

    // QT5.3 and XFCE don't play nicely.  Hammer the XFCE tray up to
    // maxtries to get a valid icon geometry.
    // QT5.4 update, may be fixed but leave option in for now
    if (b_usexfce || b_usemate) {
      const int maxtries = 125;
      int i;
      for (i = 0; i < maxtries; ++i) {
        trayicon->setVisible(true);
        //qDebug() << "icon geometry: " << trayicon->geometry();
        if ((trayicon->geometry().left() > 0 || trayicon->geometry().top() > 0) && trayicon->geometry().width() > 1) break;
        trayicon->setVisible(false);
        qApp->processEvents();
      }   // hammer loop
      if (i == maxtries - 1) {
        qDebug() << QString("Failed to get a valid icon from the systemtray in %1 tries").arg(maxtries);
        ui.pushButton_minimize->setDisabled(true);
        trayicon = 0; // reinitialize the pointer
      } // if we hit the end of the loop
    } // if use xfce

    // Sync the visibility to the checkbox
    ui.checkBox_hideIcon->setEnabled(true);
    trayicon->setVisible(true);

  } // if there is a systemtray available

  // else no systemtray available
  else {
    ui.checkBox_hideIcon->setDisabled(true);
    trayicon = 0;

    QMessageBox::warning(this,
      QString(TranslateStrings::cmtr("cmst")) + tr(" Warning"),
      tr("<center><b>Unable to find a systemtray on this machine.</b>"
         "<center><br>The program may still be used to manage your connections, but the tray icon will be disabled."
         "<center><br><br>If you are seeing this message at system start up and you know a system tray exists once the "
         "system is up, try starting with the <b>-w</b> switch and set a delay as necessary.  The exact wait time will vary "
         "from system to system."
          ) );

    // Even if we want to be minimized we can't there is no place to minimize to.
    this->showNormal();
  } // else

	// Restore the desktopAware
	qApp->setDesktopSettingsAware(b_dtaware);

  // Lastly update the display widgets (since this is actually the last
  // line of the constructor.)
  this->updateDisplayWidgets();

  return;
}

//
// Function to show notifications (if desired by the user). Called from
// the functions we connect dbus signals to, for instance dbsPropertyChanged(),
// The notifyclient class is used to store data for display from both
// the systemtrayicon and the notification server.
void ControlBox::sendNotifications()
{
  // if we want system tray notifications
  if (ui.checkBox_systemtraynotifications->isChecked() && QSystemTrayIcon::isSystemTrayAvailable() ) {
    QSystemTrayIcon::MessageIcon sticon = QSystemTrayIcon::NoIcon;
    if (notifyclient->getUrgency() == Nc::UrgencyCritical) sticon = QSystemTrayIcon::Warning;
    else sticon = QSystemTrayIcon::Information;

    if (notifyclient->getBody().isEmpty() )  trayicon->showMessage(TranslateStrings::cmtr("cmst"), notifyclient->getSummary(), sticon);
    else trayicon->showMessage(TranslateStrings::cmtr("cmst"),  QString(notifyclient->getSummary() + "\n" + notifyclient->getBody()), sticon);
  }

  // if we want notify daemon notifications
    if (ui.checkBox_notifydaemon->isChecked() && notifyclient->isValid() ) {
      notifyclient->sendNotification();
    }
  return;
}

//
//  Function to query connman.manager.GetProperties
//  Return a bool, true on success, false otherwise
bool ControlBox::getProperties()
{
  // call connman and GetProperties
  QDBusMessage reply = con_manager->call("GetProperties");

  // call the function to get the map values
  properties_map.clear();
  return getMap(properties_map, reply);
}

//
//  Function to query connman.manager.GetTechnologies
//  Return a bool, true on success, false otherwise
bool ControlBox::getTechnologies()
{
  // call connman and GetTechnologies
  QDBusMessage reply = con_manager->call("GetTechnologies");

  // call the function to get the map values
  technologies_list.clear();
  return getArray(technologies_list, reply);
}

//
//  Function to query connman.manager.GetServices
//  Return a bool, true on success, false otherwise
bool ControlBox::getServices()
{
  // call connman and GetServices
  QDBusMessage reply = con_manager->call("GetServices");

  // call the function to get the map values
  services_list.clear();
  return getArray(services_list, reply);
}

//
//  Function to extract arrayElements from a DBus reply message (that contains an array).
//  This data type is returned by GetServices and GetTechnologies.
//
//  Return value a bool, true on success, false otherwise
//  A QList of arrayElements is sent by reference (called r_list here)
//  and is modified by this function.  r_msg is a constant reference
//  to the DBus reply message.
bool ControlBox::getArray(QList<arrayElement>& r_list, const QDBusMessage& r_msg )
{
  // make sure r_msg is a QDBusArgument
  if ( ! r_msg.arguments().at(0).canConvert<QDBusArgument>() ) return false;

  // make sure the QDBusArgument holds an array
  const QDBusArgument &qdb_arg = r_msg.arguments().at(0).value<QDBusArgument>();
  if (qdb_arg.currentType() != QDBusArgument::ArrayType ) return false;

  // iterate over the QDBusArgument pulling array elements out and inserting into
  // an arrayElement structure.
  qdb_arg.beginArray();
  r_list.clear();

  while ( ! qdb_arg.atEnd() ) {
    // make sure the argument is a structure type
    if (qdb_arg.currentType() != QDBusArgument::StructureType ) return false;

    arrayElement ael;
    qdb_arg.beginStructure();
    qdb_arg >> ael.objpath >> ael.objmap;
    qdb_arg.endStructure();
    r_list.append (ael);
  }	// while
  qdb_arg.endArray();

  return true;
}

//  Function to extract a QMap from a DBus reply message (that contains a map).
//  This data type is returned by GetProperties
//
//  Return value a bool, true on success, false otherwise.
//  The map is sent by reference (called r_map here) and is modified by this function.
//  r_msg is a constant reference to the DBus reply message.
bool ControlBox::getMap(QMap<QString,QVariant>& r_map, const QDBusMessage& r_msg )
{
  // make sure r_msg is a QDBusArgument
  if ( ! r_msg.arguments().at(0).canConvert<QDBusArgument>() ) return false;

  // make sure the QDBusArgument holds a map
  const QDBusArgument &qdb_arg = r_msg.arguments().at(0).value<QDBusArgument>();
  if (qdb_arg.currentType() != QDBusArgument::MapType ) return false;

  // iterate over the QDBusArgument pulling map keys and values out
  qdb_arg.beginMap();
  r_map.clear();

  while ( ! qdb_arg.atEnd() ) {
    QString key;
    QVariant value;
    qdb_arg.beginMapEntry();
    qdb_arg >> key >> value;
    qdb_arg.endMapEntry();
    r_map.insert(key, value);
  }
  qdb_arg.endMap();

  return true;
}

//
//  Function to extract the data from a QDBusArgument that contains a map.
//  Some of the arrayElements can contain a QDBusArgument as the object
//  instead of a primitive (string, bool, int, etc.). This function
//  will extract the data from the QDBusArgument and write it into a map.
//
//  Return value a bool, true on success, false otherwise.
//  The map is sent by reference (called r_map here) and is modified by this function.
//  r_var is a constant reference to the QDBusArgument.
//
//  This is a static function because we send it to the PropertiesEditor class
//  as a function argument.
bool ControlBox::extractMapData(QMap<QString,QVariant>& r_map, const QVariant& r_var)
{
  //  make sure we can convert the QVariant into a QDBusArgument
  if (! r_var.canConvert<QDBusArgument>() ) return false;
  const QDBusArgument qdba =  r_var.value<QDBusArgument>();
  
  // make sure the QDBusArgument holds a map
  if (qdba.currentType() != QDBusArgument::MapType ) return false;

  // iterate over the QDBusArgument pulling map keys and values out
    r_map.clear();
    qdba.beginMap();

    while ( ! qdba.atEnd() ) {
      QString key;
      QVariant value;
      qdba.beginMapEntry();
      qdba >> key >> value;
      qdba.endMapEntry();
      r_map.insert(key, value);
    } // while

    qdba.endMap();
    return true;
}

//
// Function to log errors to the system log.  Functionallity provided
// by syslog.h and friends.
void ControlBox::logErrors(const quint8& err)
{
  //  store the error in a data element
  q8_errors |= err;

  //  Log the error in the system log
  //  LOG_PID   Include PID with each message
  //  LOG_CONS  Write to console if there is a problem writing to system log
  //  LOG_USER  User Level Message
  //  LOG_ERR   Error condition
  //  LOG_WARNING   Warning contition
  //  Defined in resource.h
  //  LOG_NAME  Name to display in the log
  openlog(qPrintable(LOG_NAME), LOG_PID|LOG_CONS, LOG_USER);
  switch (err)
  {
    case  CMST::Err_No_DBus:
      syslog(LOG_ERR, "%s", tr("Could not find a connection to the system bus").toUtf8().constData() );
      QMessageBox::critical(this, tr("%1 - Critical Error").arg(TranslateStrings::cmtr("cmst")),
        tr("Unable to find a connection to the system bus.<br><br>%1 will not be able to communicate with connman.").arg(TranslateStrings::cmtr("cmst")) );
      break;
    case  CMST::Err_Invalid_Con_Iface:
      syslog(LOG_ERR, "%s",tr("Could not create an interface to connman on the system bus").toUtf8().constData());
      QMessageBox::critical(this, tr("%1 - Critical Error").arg(TranslateStrings::cmtr("cmst")),
        tr("Unable to create an interface to connman on the system bus.<br><br>%1 will not be able to communicate with connman.").arg(TranslateStrings::cmtr("cmst")) );
      break;
    case  CMST::Err_Properties:
      syslog(LOG_ERR, "%s", tr("Error reading or parsing connman.Manager.GetProperties").toUtf8().constData() );
      QMessageBox::warning(this, tr("%1 - Warning").arg(TranslateStrings::cmtr("cmst")),
        tr("There was an error reading or parsing the reply from method connman.Manager.GetProperties.<br><br>It is unlikely any portion of %1 will be functional.").arg(TranslateStrings::cmtr("cmst")) );
      break;
    case  CMST::Err_Technologies:
      syslog(LOG_ERR, "%s",tr("Error reading or parsing connman.Manager.GetTechnologies").toUtf8().constData() );
      QMessageBox::warning(this, tr("%1 - Warning").arg(TranslateStrings::cmtr("cmst")),
        tr("There was an error reading or parsing the reply from method connman.Manager.GetTechnologies.<br><br>Some portion of %1 may still be functional.").arg(TranslateStrings::cmtr("cmst")) );
      break;
    case  CMST::Err_Services:
      syslog(LOG_ERR, "%s", tr("Error reading or parsing connman.Manager.GetServices").toUtf8().constData() );
      QMessageBox::warning(this, tr("%1 - Warning").arg(TranslateStrings::cmtr("cmst")),
        tr("There was an error reading or parsing the reply from method connman.Manager.GetServices.<br><br>Some portion of %1 may still be functional.").arg(TranslateStrings::cmtr("cmst")) );
      break;
    default:
      break;
    }
 closelog();

 return;
}

//
//  Function to read text contained in a resource file.  Input is a const char* to the resource,
//  Return value is a QString of the text
QString ControlBox::readResourceText(const char* textfile)
{
  QString rtnstring = QString();

  QFile file(textfile);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    while (!in.atEnd()) {
      rtnstring.append(in.readLine() );
    } // while
  } // if

  return rtnstring;
}

//
// Function to clear the counters if selected in the ui.  Called from the constructor
// and from dbsServicesChanged
void ControlBox::clearCounters()
{
  if (ui.checkBox_resetcounters->isChecked() && ! onlineobjectpath.isEmpty() ) {
    QDBusInterface* iface_serv = new QDBusInterface(DBUS_CON_SERVICE, onlineobjectpath, "net.connman.Service", QDBusConnection::systemBus(), this);
    iface_serv->call(QDBus::AutoDetect, "ResetCounters");
    iface_serv->deleteLater();
  }

  return;
}

//
// Function to return a nick name for a service. Typically return the 
// Name property.  For wired ethernet Name comes back as Wired, and for
// hidden wifi networks this is blank.  In those cases create a 
// nickname and return it.
QString ControlBox::getNickName(const QDBusObjectPath& objpath)
{	
	for (int i = 0; i < services_list.size(); ++i) {
		if (services_list.at(i).objpath == objpath) {
			QMap<QString,QVariant> submap;
			if (services_list.at(i).objmap.value("Type").toString() == "ethernet") {
				extractMapData(submap, services_list.at(i).objmap.value("Ethernet") );
				if (submap.value("Interface").toString().isEmpty() )
					return services_list.at(i).objmap.value("Name").toString();
				else	
					return QString(TranslateStrings::cmtr(services_list.at(i).objmap.value("Name").toString()) + " [%1]").arg(submap.value("Interface").toString() );				
			}	// if type ethernet
			
			else if ( services_list.at(i).objmap.value("Type").toString() == "wifi" && services_list.at(i).objmap.value("Name").toString().isEmpty() ) 
				return tr("[Hidden Wifi]");
			else 
				return  services_list.at(i).objmap.value("Name").toString();
		}	// if objpath matches
	}	// for
	
	return QString();
}


// Slot to connect to the notification client. Called from QTimers to give time for the notification server
// to start up if this program is started automatically at boot.  We make four attempts at finding the
// notification server.  First is in the constructor of NotifyClient, following we call the connectToServer()
// function.
void ControlBox::connectNotifyClient()
{
   //initialize the counter
   static short count = 0;
   ++count;

  if (count > 1 ) {
    // if we have a valid notifyclient return now
    if (notifyclient->isValid() )
      return;
    // else try to connect again
    else
      notifyclient->connectToServer();
  } // if count > 1

  // setup the notify server label if we were successful in finding and connecting to a server
  if (notifyclient->isValid() ) {
    QString name = notifyclient->getServerName().toLower();
    name = name.replace(0, 1, name.left(1).toUpper() );
    QString vendor = notifyclient->getServerVendor();
    vendor = vendor.replace(0, 1, vendor.left(1).toUpper() );
    QString lab = tr("%1 version %2 by %3 has been detected on this system.<p>This server supports desktop Notification Specification version %4")
      .arg(name)
      .arg(notifyclient->getServerVersion() )
      .arg(vendor)
      .arg(notifyclient->getServerSpecVersion() );
    ui.label_serverstatus->clear();
    ui.label_serverstatus->setDisabled(true);
    ui.groupBox_notifications->setToolTip(lab);
  }
  // not successful, try again or abandon if counter is at limit
  else {
    if (count < 4) {
      ui.label_serverstatus->setText(tr("Attempt %1 of 4 looking for notification server.").arg(count));
    } // try again
    else {
      ui.label_serverstatus->setText(tr("Unable to find or connect to a Notification server."));
      ui.checkBox_notifydaemon->setChecked(false);
      ui.checkBox_notifydaemon->setEnabled(false);
    } // else last time
  ui.groupBox_notifications->setToolTip("");
  ui.groupBox_notifications->setWhatsThis("");
  } // else we don't have a valid client.

  return;
}

// The following two functions are somewhat similar.  ConfigureSerivce opens a dialog to tweak
// defaults set by Connman.  All settings are read and written by Connman into files that Connman
// creates.
//
// Provisioning creates a provision file that takes precedence over anything Connman creates.  It
// is required for certain types of networks, for instance Eduroam.  The provisioning file must be
// created manually before trying to connect via Connman.  Disk reads and writes are handled by
// a program (this one) and not by Connman.
//
// Slot to open a dialog to configure the selected service
void ControlBox::configureService()
{
  // Make sure the index is real
  if (ui.comboBox_service->currentIndex() < 0 ) return;

  // Create a new properties editor
  PropertiesEditor* peditor = new PropertiesEditor(this, services_list.at(ui.comboBox_service->currentIndex()), this->extractMapData );

  // Set the whatsthis button icon
	peditor->setWhatsThisIcon(iconman->getIcon("whats_this"));

  // call then clean up
  peditor->exec();
  peditor->deleteLater();

  return;
}

//
// Slot to open the provisioning editor to create a configuration (provisioning) file
// Called whenever ui.pushButton_provisioning_editor or ui.pushButton_vpn_editor
// is pressed.
void ControlBox::provisionService()
{
	if (qobject_cast<QPushButton*>(sender()) == ui.pushButton_provisioning_editor) {
		ProvisioningEditor* peditor = new ProvisioningEditor(this);
		
		// Set the whatsthis button icon
		peditor->setWhatsThisIcon(iconman->getIcon("whats_this") );
  
		// call then clean up
		peditor->exec();
		peditor->deleteLater();
	}
	
	else if (qobject_cast<QPushButton*>(sender()) == ui.pushButton_vpn_editor) {
		VPN_Editor* veditor = new VPN_Editor(this);
				
		// Set the whatsthis button icon
		veditor->setWhatsThisIcon(iconman->getIcon("whats_this") );
  
		// call then clean up
		veditor->exec();
		veditor->deleteLater();	
	}
	
	return;
}

//
// Slot called when a connection to the local socket was detected.  Means another instance of CMST was started
// while this instance was running.
void ControlBox::socketConnectionDetected()
{
  this->showNormal();
  return;
}

//
// Slot to tidy up the place at close.  Called when the QApplication::aboutToQuit() signal is emitted
void ControlBox::cleanUp()
{
  // close and delete the socket server
  socketserver->close();
  socketserver->deleteLater();

  // write settings
  this->writeSettings();
  
  // unregister objects
  if (con_manager->isValid() ) {
	  // agent
	  QDBusMessage reply_a = con_manager->call(QDBus::AutoDetect, "UnregisterAgent", QVariant::fromValue(QDBusObjectPath(AGENT_OBJECT)) );
		//qDebug() << reply_a;			
		// counter - only have a signal-slot connection if the counter was able to be registered
		if (counter->cnxns() > 0) {
			QDBusMessage reply_c = con_manager->call(QDBus::AutoDetect, "UnregisterCounter", QVariant::fromValue(QDBusObjectPath(CNTR_OBJECT)) ); 
			//qDebug() << reply_c;
		}	// if counters are connected to anything
	}	// if con_manager isValid
	
			
	if (vpn_manager->isValid() ) {
	  QDBusMessage reply_b = vpn_manager->call(QDBus::AutoDetect, "UnregisterAgent", QVariant::fromValue(QDBusObjectPath(VPN_AGENT_OBJECT)) );
		//qDebug() << reply_b;
	}	// ivpn_manager isValid

  return;
}
	
// 
// Slot to open the color selection dialog and request input.
void ControlBox::callColorDialog()
{
	QColor color = QColorDialog::getColor(QColor(ui.lineEdit_colorize->text()), this, tr("Colorize Icons"));
	if (color.isValid() ) ui.lineEdit_colorize->setText(color.name() );
	
	return;
}	

//
// Slot to process things when the user changes the icon color
void ControlBox::iconColorChanged(const QString& col)
{
	iconman->setIconColor(QColor(col) );
	this->updateDisplayWidgets();
	ui.toolButton_whatsthis->setIcon(iconman->getIcon("whats_this"));
	agent->setWhatsThisIcon(iconman->getIcon("whats_this"));
	vpnagent->setWhatsThisIcon(iconman->getIcon("whats_this"));
	
	return;
}
