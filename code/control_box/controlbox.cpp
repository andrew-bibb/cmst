/**************************** controlbox.cpp ***************************
/**************************** controlbox.cpp ***************************

Code to manage the primary user interface to include the QDialog the
user interfaces with and the system tray icon.  

Copyright (C) 2013-2014
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

# include <QtCore/QDebug>
# include <QDBusArgument>

# include <QTableWidget>
# include <QTableWidgetItem>
# include <QFileInfo>
# include <QFile>
#	include <QWhatsThis>
# include <QMenu>
# include <QPixmap>
# include <QProgressBar>
# include <QMessageBox>
# include <QLocale>
# include <QCloseEvent>
# include <QToolTip>

# include "./code/control_box/controlbox.h"
# include "./code/resource.h"	
# include "./code/scrollbox/scrollbox.h"
	
//	headers for system logging
# include <stdio.h>
# include <unistd.h>
# include <syslog.h>

// icon substitutions 
//	system theme										hard coded
//	emblem-favorite									bookmark.png
//	network-transmit-receive				connect_established
//	network-idle										connect_creating
//	network-offline									connect_no
//																	ledgreen
//																	ledred
//	network-error										cancel
//	system-help											help

#define DBUS_SERVICE "net.connman"
#define DBUS_PATH "/"
#define DBUS_MANAGER "net.connman.Manager"

// Custom push button, used in the technology box for powered on/off
// This is really a single use button, after it is clicked all idButtons
// are deleted and recreated.  Once is is clicked disable the button.
idButton::idButton(QWidget* parent, const QDBusObjectPath& id) :
		QPushButton(parent)
{
	obj_id = id;
	setCheckable(true);
	
	connect (this, SIGNAL(clicked(bool)), this, SLOT(buttonClicked(bool)));
	
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
	// set the Locale
	QLocale::setDefault(QLocale(QLocale::L_LANG, QLocale::L_COUNTRY));	
  
  // setup the user interface
  ui.setupUi(this);
  
  // install global event filter (used to disable showing tooltips)
  qApp->installEventFilter(this);
  
	// set the window title 
  setWindowTitle(tr(WINDOW_TITLE));    
 
  // data members
  q8_errors = CMST::No_Errors;
  properties_map.clear();
  services_list.clear();
  technologies_list.clear();
  wifi_list.clear();
  agent = new ConnmanAgent(this);
  counter = new ConnmanCounter(this);
  mvsrv_menu = new QMenu(this);
  QString s_app = PROGRAM_NAME; 
  settings = new QSettings(s_app.toLower(), s_app.toLower(), this);
	notifyclient = new NotifyClient(this);

  // set a flag if we sent a commandline option to log the connman inputrequest
	agent->setLogInputRequest(parser.isSet("log-input-request")); 
	
	// set a flag if we want to use the local system icon theme and set the whatsthis button
	b_useicontheme = parser.isSet("icon-theme"); 
	if (b_useicontheme) {
		ui.toolButton_whatsthis->setIcon(QIcon::fromTheme("system-help", QIcon(":/icons16x16/images/16x16/help.png")) );
		agent->setWhatsThisIcon(QIcon::fromTheme("system-help", QIcon(":/icons16x16/images/16x16/help.png")) );
	}
  
  // my plan is to eventually have these as options called from the command line.  
  wifi_interval = 60;				// number of seconds between wifi scans
  counter_accuracy = 1024;	// number of kb for counter updates
  counter_period = 10;			// number of seconds for counter updates

	// connect counter signal to  the counterUpdated slot before we register the counter, assuming counters are not disabled
	if (! parser.isSet("disable-counters"))
		connect(counter, SIGNAL(usageUpdated(QDBusObjectPath, QString, QString)), this, SLOT(counterUpdated(QDBusObjectPath, QString, QString)));
  
	// restore GUI settings
	this->readSettings(); 
	
	// setup the notify server label
	if (notifyclient->isValid() ) {
		QString lab = tr("Using the %1 notification server version %2 by %3.<br>Server supports Notification specification version %4")
			.arg(notifyclient->getServerName() )
			.arg(notifyclient->getServerVersion() )
			.arg(notifyclient->getServerVendor() )
			.arg(notifyclient->getServerSpecVersion() );
		ui.label_serverstatus->setText(lab);		
	}
	else {
		ui.label_serverstatus->setText(tr("Unable to find or connect to a Notification server."));
		ui.checkBox_notifydaemon->setChecked(false);
		ui.checkBox_notifydaemon->setEnabled(false);
	}
			 
  
  // setup the dbus interface to connman.manager
	if (! QDBusConnection::systemBus().isConnected() ) logErrors(CMST::Err_No_DBus);
  else {	
		iface_manager = new QDBusInterface(DBUS_SERVICE, DBUS_PATH, DBUS_MANAGER, QDBusConnection::systemBus(), this); 
		if (! iface_manager->isValid() ) logErrors(CMST::Err_Invalid_Iface);
		else {
		// Access connman.manager to retrieve the data
			this->managerRescan(CMST::Manager_All);
			
			// register the agent
			QList<QVariant> vlist_agent;
			vlist_agent.clear();
			vlist_agent << QVariant::fromValue(QDBusObjectPath("/org/monkeybusiness/Agent")); 
			iface_manager->callWithArgumentList(QDBus::NoBlock, "RegisterAgent", vlist_agent);
			
			// if counters are enabled register the counter
			if (! parser.isSet("disable-counters")) {
				QList<QVariant> vlist_counter;
				vlist_counter.clear();
				vlist_counter << QVariant::fromValue(QDBusObjectPath("/org/monkeybusiness/Counter")) << counter_accuracy << counter_period;;
				iface_manager->callWithArgumentList(QDBus::NoBlock, "RegisterCounter", vlist_counter);			
			}
		
		// connect some dbus signals to our slots
			QDBusConnection::systemBus().connect(DBUS_SERVICE, DBUS_PATH, DBUS_MANAGER, "PropertyChanged", this, SLOT(dbsPropertyChanged(QString, QDBusVariant)));
			QDBusConnection::systemBus().connect(DBUS_SERVICE, DBUS_PATH, DBUS_MANAGER, "ServicesChanged", this, SLOT(dbsServicesChanged(QMap<QString, QVariant>, QList<QDBusObjectPath>, QDBusMessage)));
			QDBusConnection::systemBus().connect(DBUS_SERVICE, DBUS_PATH, DBUS_MANAGER, "TechnologyAdded", this, SLOT(dbsTechnologyAdded(QDBusObjectPath, QVariantMap)));
			QDBusConnection::systemBus().connect(DBUS_SERVICE, DBUS_PATH, DBUS_MANAGER, "TechnologyRemoved", this, SLOT(dbsTechnologyRemoved(QDBusObjectPath)));
		
		// clear the counters if selected
		this->clearCounters();
		
		}	// else have valid connection
	}	// else have connected systemBus
	
	//	setup the dialog  
  //	timer to scan for wifi services now and again
  wifi_timer = new QTimer(this);
  wifi_timer->setInterval(wifi_interval * 1000); 
  connect(wifi_timer, SIGNAL(timeout()), this, SLOT(scanWifi()));
      
  //  add actions 
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
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
	connect(moveGroup, SIGNAL(triggered(QAction*)), this, SLOT(moveButtonPressed(QAction*)));
	connect(mvsrv_menu, SIGNAL(triggered(QAction*)), this, SLOT(moveService(QAction*)));
	
	//  connect signals and slots - ui elements
	connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));
	connect(ui.comboBox_service, SIGNAL(currentIndexChanged(int)), this, SLOT(getServiceDetails(int)));
	connect(ui.pushButton_exit, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.pushButton_minimize, SIGNAL(clicked()), minimizeAction, SLOT(trigger()));
	connect(ui.checkBox_hideIcon, SIGNAL(clicked(bool)), this, SLOT(toggleTrayIcon(bool))); 	
	connect(ui.checkBox_devicesoff, SIGNAL(clicked(bool)), this, SLOT(toggleOfflineMode(bool)));
	connect(ui.pushButton_connect,SIGNAL(clicked()),this, SLOT(connectPressed()));
	connect(ui.pushButton_disconnect,SIGNAL(clicked()),this, SLOT(disconnectPressed()));	
	connect(ui.pushButton_remove,SIGNAL(clicked()),this, SLOT(removePressed()));		
  connect(ui.pushButton_aboutCMST, SIGNAL(clicked()), this, SLOT(aboutCMST()));  
  connect(ui.pushButton_aboutIconSet, SIGNAL(clicked()), this, SLOT(aboutIconSet()));	
	connect(ui.pushButton_aboutQT, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
	connect(ui.pushButton_license, SIGNAL(clicked()), this, SLOT(showLicense()));
	connect(ui.pushButton_change_log, SIGNAL(clicked()), this, SLOT(showChangeLog()));	
	connect(ui.tableWidget_services, SIGNAL (cellClicked(int, int)), this, SLOT(enableMoveButtons(int, int)));
	connect(ui.checkBox_hidecnxn, SIGNAL (toggled(bool)), this, SLOT(updateDisplayWidgets()));
	connect(ui.pushButton_scanWifi, SIGNAL (clicked()), this, SLOT(scanWifi()));
	connect(ui.checkBox_systemtraynotifications, SIGNAL (clicked(bool)), this, SLOT(trayNotifications(bool)));
	connect(ui.checkBox_notifydaemon, SIGNAL (clicked(bool)), this, SLOT(daemonNotifications(bool)));

  // tray icon - disable it if we specifiy that option on the commandline
  // otherwise set a singleshot timer to create the tray icon and showMinimized
  // or showMaximized.
  trayicon = 0;
  if (parser.isSet("disable-tray-icon")) {
		ui.checkBox_hideIcon->setDisabled(true);
		this->showNormal(); // no place to minimize to, so showMaximized
	}	// if
	else {
		bool ok;
		const short mintrigger = 100;	// minimum time (milliseconds) to wait before starting the tray icon
		int timeout = parser.value("wait-time").toInt(&ok, 10);
		if (! ok) timeout = 0;
		timeout *= 1000;
		if (timeout < mintrigger) timeout = mintrigger;
		if (parser.isSet("minimized")) {
			QTimer::singleShot(timeout, this, SLOT(startSystemTrayMinimized()));
		}
		else {
			this->showNormal();
			QTimer::singleShot(timeout, this, SLOT(startSystemTrayNormal()));
		}
		}	// else
	
	//// turn network cards on or off globally based on checkbox
	toggleOfflineMode(ui.checkBox_devicesoff->isChecked() );
		
	// start the timer
	wifi_timer->start();
		
	// set up and fill in the display widgets
	this->updateDisplayWidgets();				
}  

////////////////////////////////////////////////// Public Functions //////////////////////////////////

////////////////////////////////////////////////// Public Slots //////////////////////////////////////
//
// slot to display an about box for this program
void ControlBox::aboutCMST()
{
 QMessageBox::about(this, tr("About %1").arg(PROGRAM_NAME),
      tr("<center>%1 is a program to interface with the Connman daemon and to provide a system tray control."
		  "<br><center>Version <b>%2</b>"
                  "<center>Release date: %3"                        
                  "<center>Copyright c %4\n<center>by\n"
                  "<center>Andrew J. Bibb\n"
                  "<center>Vermont, USA\n"
                  "<br><center><b>Contributors:</b>\n"
                  "<center>Brett Dutro").arg(PROGRAM_NAME).arg(VERSION).arg(RELEASE_DATE).arg(COPYRIGHT_DATE) );
}

//
// slot to display an about box for the icons we used
void ControlBox::aboutIconSet()
{
 QMessageBox::about(this, tr("About AwOken"),
       tr("<center>This program uses the <b>AwOken</b> icon set version 2.5"                       
                  "<br><br>Released under the"
		  "<br>Creative Commons Attribution-Share Alike 3.0 Unported License"
		  "<br><a href=\"url\">http://creativecommons.org/licenses/by-sa/3.0/legalcode</a>"
                  ) );
}

//
//	slot to display the program license
void ControlBox::showLicense()
{
	QString s = readResourceText(":/text/text/license.txt");
  if ( s.isEmpty() ) s.append(tr("%1 license is the MIT license.").arg(PROGRAM_NAME));
	
	QMessageBox::about(this, tr("License"), s);
}

//
//	slot to display the change log of the program
void ControlBox::showChangeLog()
{
	QString s = readResourceText(":/text/text/changelog.txt");
  if ( s.isEmpty() ) s.append(tr("%1 change log is not available.").arg(PROGRAM_NAME));
	
	ScrollBox::execScrollBox(tr("ChangeLog"), s, this);
}


////////////////////////////////////////////Private Slots ////////////////////////////////////////////
//	Slot to update all of our display widgets
void ControlBox::updateDisplayWidgets()
{
	// each assemble function will check q8_errors to make sure it can
	// get the information it needs.  Only check for major errors since we
	// can't run the assemble functions if there are. 

	if ( ((q8_errors & CMST::Err_No_DBus) | (q8_errors & CMST::Err_Invalid_Iface)) == 0x00 ) {		
			
		//	rebuild our pages	
		this->assemblePage1();
		this->assemblePage2();
		this->assemblePage3();
		this->assemblePage4();
		if (trayicon != 0 ) this->assembleTrayIcon();
		
	}	// if there were no major errors
	
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
		ss = services_list.at(i).objmap.value("Name").toString();
		ss = ss.replace(0, 1, ss.left(1).toUpper() );
		// the items in mvsrv_menu are in the same order as services_list
		if (ss == act->text() ) {
			targetobj = QDBusObjectPath(services_list.at(i).objpath.path());
			break;
		}	// if
	}	// for
	
	// make sure we got a targetobject, if not most likely cancel pressed
	if (targetobj.path().isEmpty()) return;
	
	// get enough information from tableWidget_services to identify the source object
	QList<QTableWidgetItem*> list;
	list.clear();
	list = ui.tableWidget_services->selectedItems();
	if (list.isEmpty() ) return;
	
	// apply the movebefore or moveafter message to the source object
	QDBusInterface* iface_serv = new QDBusInterface(DBUS_SERVICE, services_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);	
	if (mvsrv_menu->title() == ui.actionMove_Before->text())
		iface_serv->call(QDBus::NoBlock, "MoveBefore", QVariant::fromValue(targetobj) );
	else
		iface_serv->call(QDBus::NoBlock, "MoveAfter", QVariant::fromValue(targetobj) );
	
	iface_serv->deleteLater();
	
	return;
}

//
//	Slot called if the movebefore or moveafter button was pressed
void ControlBox::moveButtonPressed(QAction* act)
{
	mvsrv_menu->setTitle(act->text());
	mvsrv_menu->popup(QCursor::pos());
	
	return;
}

//
//	Slot to enable the movebefore and moveafter buttons, and to prepare the poupup menu
void ControlBox::enableMoveButtons(int row, int col)
{
	// enable the buttons
	ui.pushButton_movebefore->setEnabled(true);
	ui.pushButton_moveafter->setEnabled(true);

	// create the menu to show if a user selects one of the buttons
	mvsrv_menu->clear();
	QString ss;
	for (int i = 0; i < services_list.size(); ++i) {
		ss = services_list.at(i).objmap.value("Name").toString();
		ss = ss.replace(0, 1, ss.left(1).toUpper() );
		QAction* act = mvsrv_menu->addAction(ss);
		if (i == row) act->setDisabled(true);
		}
		
	// add a cancel option
	mvsrv_menu->addSeparator();
	QAction* act = mvsrv_menu->addAction(tr("Cancel"));
		
	return;
}

//
//	Slot to update the service label when this->counter is updated.  Other labels in page 4 receive signals directly
void ControlBox::counterUpdated(const QDBusObjectPath& qdb_objpath, const QString& home_label, const QString& roam_label)
{
	// Don't update the counter if qdb_objpath is not the online service
	if (qdb_objpath != serviceOnline() ) return;
	
	// Set the labels in page 4
	if (! qdb_objpath.path().isEmpty() ) {
		QMap<QString,QVariant> map;
		for (int i =0; i < services_list.size(); ++i) {
			if (services_list.at(i).objpath == qdb_objpath) {
				map = services_list.at(i).objmap;
				break;
			}	// if
		}	// for
		ui.label_counter_service_name->setText(tr("<b>Service:</b> %1").arg(map.value("Name").toString()) );
		ui.label_home_counter->setText(home_label);
		ui.label_roam_counter->setText(roam_label);
	}
	else 
		ui.label_counter_service_name->setText(tr("<b>Service:</b> %1").arg(tr("Unable to determine service")) );
		
	return;
}


//
//	Slot to connect a wifi service. Called when ui.pushButton_connect is pressed
void ControlBox::connectPressed()
{
	// if no row is selected then return(
	QList<QTableWidgetItem*> list;
	list.clear();
	list = ui.tableWidget_wifi->selectedItems();
	if (list.isEmpty() ) {
		QMessageBox::information(this, tr("No Services Selected"),
			tr("You need to select a Wifi service before pressing the connect button.") );
		return;
	}
	
	//	send the connect message to the service
	QDBusInterface* iface_serv = new QDBusInterface(DBUS_SERVICE, wifi_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);	
	iface_serv->call(QDBus::NoBlock, "Connect");
	iface_serv->deleteLater();
	
	return;		
}

//
//	Slot to disconnect a wifi service. Called when ui.pushButton_disconnect is pressed
void ControlBox::disconnectPressed()
{
	// if no row selected return
	QList<QTableWidgetItem*> list;
	list.clear();
	list = ui.tableWidget_wifi->selectedItems();
	if (list.isEmpty() ) {
		QMessageBox::information(this, tr("No Services Selected"),
			tr("You need to select a Wifi service before pressing the disconnect button.") );
		return;
	}
	
	//	send the disconnect message to the service
	QDBusInterface* iface_serv = new QDBusInterface(DBUS_SERVICE, wifi_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
	iface_serv->call(QDBus::NoBlock, "Disconnect");
	iface_serv->deleteLater();
	
	return;	
}

//
//	Slot to remove (unset the Favorite property, clear passphrase if one exists) of a Wifi service
//	Called when ui.pushButton_remove is pressed
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
	
	//	send the Remove message to the service
	QDBusInterface* iface_serv = new QDBusInterface(DBUS_SERVICE, wifi_list.at(list.at(0)->row()).objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
	iface_serv->call(QDBus::NoBlock, "Remove");
	iface_serv->deleteLater();

	return;
}	

//	dbs slots are slots to receive DBus Signals		
//
//	Slot called whenever DBUS issues a PropertyChanged signal
void ControlBox::dbsPropertyChanged(QString name, QDBusVariant dbvalue)
{
	QVariant value = dbvalue.variant();
	
	// update propertiesMap
	properties_map.insert(name, value);
	
	// refresh properties from connman and update display widgets
	updateDisplayWidgets();
		
	// offlinemode property
	if (name.contains("OfflineMode", Qt::CaseInsensitive)) {
		if (value.toBool()) sendNotifications(
			QString(tr("Offline Mode Engaged")),
			QIcon(":/icons/images/interface/golfball_green.png"),
			QSystemTrayIcon::Information );						
		else sendNotifications(
			QString(tr("Offline Mode Disabled")),
			QIcon(":/icons/images/interface/golfball_red.png"),
			QSystemTrayIcon::Information );	
	}	// if contains offlinemode
		
	// state property
	else if (name.contains("State", Qt::CaseInsensitive)) {
		if (value.toString().contains("online", Qt::CaseInsensitive)) {
			QString type = "";	
			QString name = "";
			
			// find the online service
			if (properties_map.value("State").toString().contains("online", Qt::CaseInsensitive) ) {
				for (int i =0; i < services_list.size(); ++i) {
					if (services_list.at(i).objmap.value("State").toString().contains("online", Qt::CaseInsensitive)) {
						type = services_list.at(i).objmap.value("Type").toString();
						type = type.replace(0, 1, type.left(1).toUpper() );
						name = services_list.at(i).objmap.value("Name").toString();
						name = name.replace (0, 1, name.left(1).toUpper() );
						break;
					}	// if
				}	// for
			}	// if state contains online	
			
			// notification text and icons if online
			if (type.contains("wifi", Qt::CaseInsensitive))   {
				sendNotifications(
				QString(tr("%1 (%2) Online")).arg(type).arg(name),
				b_useicontheme ? 
					QIcon::fromTheme("network-transmit-receive", QIcon(":/icons/images/systemtray/wl000.png")).pixmap(QSize(16,16)) :
					QIcon(":/icons/images/systemtray/wl000.png"),
				QSystemTrayIcon::Information );
			}	// if wifi
			else {
				sendNotifications(
					QString(tr("%1 (%2) Online")).arg(type).arg(name),
					b_useicontheme ? 
						QIcon::fromTheme("network-transmit-receive", QIcon(":/icons/images/systemtray/wired_established.png")).pixmap(QSize(16,16)) :
						QIcon(":/icons/images/systemtray/wired_established.png"),
					QSystemTrayIcon::Information );
			}	// else (probably ethernet)			
		}	//	if value online
		
		// ready state
		else if (value.toString().contains("ready", Qt::CaseInsensitive)) {
			sendNotifications(
				QString(tr("Connection Ready")),
				b_useicontheme ?
					QIcon::fromTheme("network-idle", QIcon(":/icons/images/interface/connect_creating.png")).pixmap(QSize(16,16))	:
					QIcon(":/icons/images/interface/connect_creating.png"),
				QSystemTrayIcon::Information );							
		}	// if ready
		
		// any other state, report as offline
		else {
			sendNotifications(
				QString(tr("Offline")),
				b_useicontheme ?
					QIcon::fromTheme("network-offline", QIcon(":/icons/images/interface/connect_no.png")).pixmap(QSize(16,16))	:
					QIcon (":/icons/images/interface/connect_no.png"),
				QSystemTrayIcon::Information );		
		} // else offline
	}	// else state
	
	return;
}

//
//	Slot called whenever DBUS issues a ServicesChanged signal
void ControlBox::dbsServicesChanged(QMap<QString, QVariant> vmap, QList<QDBusObjectPath> removed, QDBusMessage msg)
{
	// process changed services. Demarshall the raw QDBusMessage instead of vmap as it is easier.
	if (! vmap.isEmpty() ) {	
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
				}	// if
			}	// j for
			
			// merge the new elementArray into the existing
			if (! original_element.objpath.path().isEmpty()) {
				QMapIterator<QString, QVariant> itr(revised_element.objmap);
				while (itr.hasNext()) {
					itr.next();
					original_element.objmap.insert(itr.key(), itr.value());
				}	// while
				
				// now insert the element into the revised list
				revised_list.replace(i, original_element);
			}	// if original element exists
		}	// i for
		
		// now copy the revised list to services_list
		services_list.clear();
		services_list = revised_list;
	}	// vmap not empty

	// process removed services
	if (! removed.isEmpty() ) {
		for (int i = 0; i < services_list.count(); ++i) {
			if (removed.contains(services_list.at(i).objpath) )
				services_list.removeAt(i);
			}	// for
		}	// if we needed to remove something

	// clear the counters (if selected) and update the widgets'
	clearCounters();
	updateDisplayWidgets();
	
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
	arrayElement ae = {path, properties};
	bool newelem = true;

	// first see if the element exists, if so replace it
	for (int i = 0; i < technologies_list.count(); ++i) {
		if (path == technologies_list.at(i).objpath) {
			technologies_list.replace(i, ae);
			newelem = false;
			break;
		}	// if
	}	// for
	
	// if it is a new element add it
	if (newelem) {
		technologies_list.append(ae);
		updateDisplayWidgets();
	}
	
	return;
}

//
//	Slot called whenever DBUS issues a TechonlogyAdded signal
void ControlBox::dbsTechnologyRemoved(QDBusObjectPath removed)
{
	for (int i = 0; i < technologies_list.count(); ++i) {
		if ( removed == technologies_list.at(i).objpath ) {
			technologies_list.removeAt(i);
			break;
		}	// if
	}	// for
	
	updateDisplayWidgets();
	
	return;
}

//
//	Slots called from objects previous slots were called from Manager)	
//
//	Slot called whenever a service object issues a PropertyChanged signal on DBUS
void ControlBox::dbsServicePropertyChanged(QString name, QDBusVariant dbvalue, QDBusMessage msg)
{
	QString s_path = msg.path();
	QVariant value = dbvalue.variant();

	// replace the old values with the changed ones.
	for (int i = 0; i < services_list.count(); ++i) {
		if (s_path.contains(services_list.at(i).objpath.path(), Qt::CaseSensitive) ) {
			QMap<QString,QVariant> map = services_list.at(i).objmap;
			map.remove(name);
			map.insert(name, value );
			arrayElement ae = {services_list.at(i).objpath, map};
			services_list.replace(i, ae);
			break;
		}	// if
	}	// for
		
	// process errrors
	if (name.contains("Error", Qt::CaseInsensitive) ) {
		sendNotifications(
			QString(tr("Service Error: %1\nObject Path: %2")).arg(value.toString()).arg(s_path),
			QIcon(":/icons/images/interface/cancel.png"),
			QSystemTrayIcon::Critical);			
	}
	
	return;
}

//
//	Slot called whenever a technology object issues a PropertyChanged signal on DBUS
void ControlBox::dbsTechnologyPropertyChanged(QString name, QDBusVariant dbvalue, QDBusMessage msg)
{
	QString s_path = msg.path();
	
	// replace the old values with the changed ones.
	for (int i = 0; i < technologies_list.count(); ++i) {
		if (s_path.contains(technologies_list.at(i).objpath.path(), Qt::CaseSensitive) ) {
			QMap<QString,QVariant> map = technologies_list.at(i).objmap;
			map.remove(name);
			map.insert(name, dbvalue.variant() );
			arrayElement ae = {technologies_list.at(i).objpath, map};
			technologies_list.replace(i, ae);
			break;
		}	// if
	}	// for
	
	updateDisplayWidgets();
	
	return;
}

//	Slot to scan for wifi networks.  Called from a QTimer and it also
//	can be called by functions as well.
void ControlBox::scanWifi()
{
	// Make sure we got the technologies_list before we try to work with it.
	if ( (q8_errors & CMST::Err_Technologies) != 0x00 ) return; 
	
	// Run through each technology and do a scan for any wifi
	for (int row = 0; row < technologies_list.size(); ++row) {
		if (technologies_list.at(row).objmap.value("Type").toString().contains("wifi", Qt::CaseInsensitive) ) {
		QDBusInterface* iface_tech = new QDBusInterface(DBUS_SERVICE, technologies_list.at(row).objpath.path(), "net.connman.Technology", QDBusConnection::systemBus(), this);
		iface_tech->call(QDBus::AutoDetect, "Scan");
		iface_tech->deleteLater();
		}	// if
	}	// for
	
	return;
}

//
//	Slot to globally turn power off to all network adapters
//	Called when ui.checkBox_devicesoff is clicked
void ControlBox::toggleOfflineMode(bool checked)
{
	if ( ((q8_errors & CMST::Err_No_DBus) | (q8_errors & CMST::Err_Invalid_Iface)) != 0x00 ) return;	
	
	QList<QVariant> vlist;
	vlist.clear();
	vlist << QVariant("OfflineMode") << QVariant::fromValue(QDBusVariant(checked ? true : false)); 
	iface_manager->callWithArgumentList(QDBus::NoBlock, "SetProperty", vlist);
	
	if (! checked ) this->scanWifi();
		
	return;
}

//
//	Slot to toggle the visibility of the tray icon
//	Called when ui.checkBox_hideIcon is clicked
void ControlBox::toggleTrayIcon(bool b_checked)
{
	if (trayicon != 0 ) {
		if (b_checked) {
			trayicon->hide();
			ui.pushButton_minimize->setDisabled(true);
		}	// if
		else {
			trayicon->show();
			ui.pushButton_minimize->setDisabled(false);
		}	// else
	}	//if
	
	return;
}

//
//	Slot to toggle the powered state of a technology
//	Called when our custom idButton in the powered cell in the page 1 technology tableWidget is clicked
void ControlBox::togglePowered(QString object_id, bool checkstate)
{	
	QDBusInterface* iface_tech = new QDBusInterface(DBUS_SERVICE, object_id, "net.connman.Technology", QDBusConnection::systemBus(), this);

	QList<QVariant> vlist;
	vlist.clear();
	vlist << QVariant("Powered") << QVariant::fromValue(QDBusVariant(checkstate) );

	QDBusMessage reply = iface_tech->callWithArgumentList(QDBus::AutoDetect, "SetProperty", vlist);
	if (reply.type() != QDBusMessage::ReplyMessage)
		QMessageBox::warning(this, tr("CMST Warning"),
		tr("<center><b>We received a DBUS reply message indicating an error while trying to send the toggle power request to connman.</b></center>"                       
			 "<p>The powered state of the technology will not be changed."
			 "<br><br>Error Name: %1<br><br>Error Message: %2").arg(reply.errorName()).arg(reply.errorMessage())
		);
		
	// cleanup
	iface_tech->deleteLater();
	
	return;
} 

//
//	Slot to minimize the input window.  QWidget.hide() if the tray icon
//	is visible, QWidget.showMinmized() if the tray icon is not visible.
//	Do it this way as otherwise there is no way to get the dialog back if
//	the tray icon is not shown.
//	called when actionMinimize is activated
void ControlBox::minMaxWindow(QAction* act)
{
	if (act == minimizeAction ) {
		this->writeSettings();
		if (trayicon != 0 ) trayicon->isVisible() ? this->hide() : this->showMinimized();
		else this->showMinimized();
	}	// if minimizeAction
	
	else
		this->showNormal();
	
	return;
}

//
//	Slot to get details of the selected service and write it into ui.label_details
//	Called when the ui.comboBox_services currentIndexChanged() signal is emitted.
void ControlBox::getServiceDetails(int index)
{
	//	Make sure we were sent a valid index, can happen if the comboBox is 
	//	cleared and for whatever reason could not be reseeded with entries.
	if (index < 0 ) return; 
	
	//	Get the QMap associated with index stored in an arrayElement 
	QMap<QString,QVariant> map = services_list.at(index).objmap;
	
	//	Some of the QVariants in the map are QMaps themselves, create a data structure for them
	QMap<QString,QVariant> submap;
	
	//	Start building the string for the left label
	QString rs = tr("<br><b>Service Details:</b><br>");
	rs.append(tr("Service Name: %1<br>").arg(map.value("Name").toString()) );
	rs.append(tr("Service Type: %1<br>").arg(map.value("Type").toString()) );
	rs.append(tr("Service State: %1<br>").arg(map.value("State").toString()) );
	rs.append(tr("Favorite: %1<br>").arg(map.value("Favorite").toBool() ? tr("Yes", "favorite") : tr("No", "favorite"))  );
	rs.append(tr("External Configuration File: %1<br>").arg(map.value("Immutable").toBool() ? tr("Yes", "immutable") : tr("No", "immutable")) );
	rs.append(tr("Auto Connect: %1<br>").arg(map.value("AutoConnect").toBool() ? tr("On", "autoconnect") : tr("No", "autoconnect")) );
	
	rs.append(tr("<br><b>IPv4</b><br>"));
	extractMapData(submap, services_list.at(index).objmap.value("IPv4") );
	rs.append(tr("IP Address Acquisition: %1<br>").arg(submap.value("Method").toString()));
	rs.append(tr("IP Address: %1<br>").arg(submap.value("Address").toString()));
	rs.append(tr("IP Netmask: %1<br>").arg(submap.value("Netmask").toString()));
	rs.append(tr("IP Gateway: %1<br>").arg(submap.value("Gateway").toString()));
	
	rs.append(tr("<br><b>IPv6</b><br>"));
	extractMapData(submap, services_list.at(index).objmap.value("IPv6") );
	rs.append(tr("IP Address Acquisition: %1<br>").arg(submap.value("Method").toString()));
	rs.append(tr("IP Address: %1<br>").arg(submap.value("Address").toString()));
	rs.append(tr("IP Netmask: %1<br>").arg(submap.value("Netmask").toString()));
	rs.append(tr("IP Gateway: %1<br>").arg(submap.value("Gateway").toString()));
	
	//	write the text to the left display label
	ui.label_details_left->setText(rs);
	
	// Start building the stringfortherightlabel
	rs = tr("<br><b>Name Servers</b><br>");
	rs.append(map.value("Nameservers").toStringList().join("<br>") );
	
	rs.append(tr("<br><br><b>Time Servers</b><br>  "));
	rs.append(map.value("Timeservers").toStringList().join("<br>") );
	
	rs.append(tr("<br><br><b>Search Domains</b><br>  "));
	rs.append(map.value("Domains").toStringList().join("<br>") );	
	
	rs.append(tr("<br><br><b>Ethernet</b><br>"));
	extractMapData(submap, services_list.at(index).objmap.value("Ethernet") );
	rs.append(tr("Connection Method: %1<br>").arg(submap.value("Method").toString()) );
	rs.append(tr("Interface: %1<br>").arg(submap.value("Interface").toString()) );
	rs.append(tr("Device Address: %1<br>").arg(submap.value("Address").toString()) );	
	rs.append(tr("MTU: %1<br>").arg(submap.value("MTU").value<quint16>()) );
	
	rs.append(tr("<br><b>Wireless</b><br>"));
	rs.append(tr("Security: %1<br>").arg(map.value("Security").toStringList().join(',')) );
	if (! map.value("Strength").toString().isEmpty() ) rs.append(tr("Strength: %1<br>").arg(map.value("Strength").value<quint8>()) );
	rs.append(tr("Roaming: %1<br>").arg(map.value("Roaming").toBool() ? tr("Yes", "roaming") : tr("No", "roaming")) );
	
	//	write the text to the right display label
	ui.label_details_right->setText(rs);
	
	return;
}
//
//  Slot to enter whats this mode
//	Called when the ui.toolButton_whatsthis clicked() signal is emitted
void ControlBox::showWhatsThis()
{
  QWhatsThis::enterWhatsThisMode();
}

//////////////////////////////////////////// Protected Functions //////////////////////////////////
//
// Close event.  Save GUI settings on close events
void ControlBox::closeEvent(QCloseEvent* e)
{
	this->writeSettings();
	e->accept();
	
	return;
}

//
// Event filter used to filter out tooltip events if we don't want to see them
// in eventFilters return true eats the event, false passes on it.
bool ControlBox::eventFilter(QObject* obj, QEvent* evn)
{	
	if (evn->type() == QEvent::ToolTip) {
		// first check if the object is the system tray icon
		QString objname = obj->metaObject()->className();
		if (objname.contains("QSystemTrayIconSys")) {
			if (ui.checkBox_enablesystemtraytooltips->isChecked())
				return false;
			else
				return true;
		}	// if obj is QSystemTrayIconSys
		
		// now check all the other interface widgets
		if (ui.checkBox_enableinterfacetooltips->isChecked())
			return false;
		else
			return true;
	}	// event is a tooltip
	
	return false;
}

//////////////////////////////////////////// Private Functions ////////////////////////////////////
//
//	Function to rescan connman properties, technologies and services
//	Int return value is the errors encountered
int ControlBox::managerRescan(const int& srv)
{
	if ( ((q8_errors & CMST::Err_No_DBus) | (q8_errors & CMST::Err_Invalid_Iface)) == 0x00 ) {

		// Reset the getXX errors, always a chance we could read them after
		// a previous error. Don't actually believe it, but just in case.
		q8_errors &= ~CMST::Err_Properties;
		q8_errors &= ~CMST::Err_Technologies;
		q8_errors &= ~CMST::Err_Services;
	
		// Access connman.manager to retrieve the data
		if (srv & CMST::Manager_Technologies) {
			if (! getTechnologies() ) {
				logErrors(CMST::Err_Technologies);
			}	// if
			else {	
				// connect technology signals to slots
				for (int i = 0; i < technologies_list.size(); ++i) {	
					QDBusConnection::systemBus().disconnect(DBUS_SERVICE, technologies_list.at(i).objpath.path(), "net.connman.Technology", "PropertyChanged", this, SLOT(dbsTechnologyPropertyChanged(QString, QDBusVariant, QDBusMessage)));
					QDBusConnection::systemBus().connect(DBUS_SERVICE, technologies_list.at(i).objpath.path(), "net.connman.Technology", "PropertyChanged", this, SLOT(dbsTechnologyPropertyChanged(QString, QDBusVariant, QDBusMessage)));
				}	// for	
			}	//else			
		}	// if technolgies
		
		if (srv & CMST::Manager_Services) {
			if (! getServices() ) {
				logErrors(CMST::Err_Services);
			}	// if
			// connect service signals to slots
			else {	
				for (int i = 0; i < services_list.size(); ++i) {
					QDBusConnection::systemBus().disconnect(DBUS_SERVICE, services_list.at(i).objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
					QDBusConnection::systemBus().connect(DBUS_SERVICE, services_list.at(i).objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
				}	// for
			}	// else
		}	// if services
		
		if (srv & CMST::Manager_Properties) {
			if (! getProperties() ) logErrors(CMST::Err_Properties);
		}
				
	}	// if
	
	return (q8_errors & CMST::Err_Properties) | (q8_errors & CMST::Err_Technologies) | (q8_errors & CMST::Err_Services);
}		
		
//
//	Function to assemble page 1 of the dialog

void ControlBox::assemblePage1()
{
	// Global Properties
	if ( (q8_errors & CMST::Err_Properties) == 0x00 ) {	
		QString s1 = properties_map.value("State").toString();
		s1 = s1.replace(0, 1, s1.left(1).toUpper() );
		if (s1.contains("online", Qt::CaseInsensitive)) {
			b_useicontheme ?
				ui.label_state_pix->setPixmap(QIcon::fromTheme("network-transmit-receive", QIcon(":/icons/images/interface/connect_established.png")).pixmap(QSize(16,16)) ) :
				ui.label_state_pix->setPixmap(QPixmap (":/icons/images/interface/connect_established.png"));
		}	// if online
		else {
			if (s1.contains("ready", Qt::CaseInsensitive)) {
				b_useicontheme ?
					ui.label_state_pix->setPixmap(QIcon::fromTheme("network-idle", QIcon(":/icons/images/interface/connect_creating.png")).pixmap(QSize(16,16)) )	:
					ui.label_state_pix->setPixmap(QPixmap (":/icons/images/interface/connect_creating.png"));
			}	// if ready
			else {
				b_useicontheme ?
					ui.label_state_pix->setPixmap(QIcon::fromTheme("network-offline", QIcon(":/icons/images/interface/connect_no.png")).pixmap(QSize(16,16)) )	:
					ui.label_state_pix->setPixmap(QPixmap (":/icons/images/interface/connect_no.png"));
			}	// else any other state
		}	//	else ready or any other state	
		s1.prepend(tr("State: ") );
		ui.label_state->setText(s1);
		
		bool b1 = properties_map.value("OfflineMode").toBool();
		QString s2 = QString();
		if (b1 ) {
			s2 = tr("Engaged");
			ui.label_offlinemode_pix->setPixmap(QPixmap (":/icons/images/interface/golfball_green.png"));
		}	// if offline mode is engaged
			
		else {
			s2 = tr("Disabled");
			ui.label_offlinemode_pix->setPixmap(QPixmap (":/icons/images/interface/golfball_red.png"));
		} //	else offlinemode disabled 
		s2.prepend(tr("Offline Mode "));
		ui.label_offlinemode->setText(s2);	
	}	// properties if no error		
	
	// Technologies
	if ( (q8_errors & CMST::Err_Technologies) == 0x00 ) {
		QString st = QString();
		bool bt;
		ui.tableWidget_technologies->clearContents();
		ui.tableWidget_technologies->setRowCount(technologies_list.size() );
		for (int row = 0; row < technologies_list.size(); ++row) {
		
			QTableWidgetItem* qtwi00 = new QTableWidgetItem();
			st = technologies_list.at(row).objmap.value("Name").toString();
			st = st.replace(0, 1, st.left(1).toUpper() );
			qtwi00->setText(st);
			qtwi00->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_technologies->setItem(row, 0, qtwi00) ;
			
			QTableWidgetItem* qtwi01 = new QTableWidgetItem();
			st = technologies_list.at(row).objmap.value("Type").toString();
			st = st.replace(0, 1, st.left(1).toUpper() );
			qtwi01->setText(st);
			qtwi01->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_technologies->setItem(row, 1, qtwi01);
			
			QTableWidgetItem* qtwi02 = new QTableWidgetItem();
			bt = technologies_list.at(row).objmap.value("Powered").toBool();			
			idButton* qpb02 = new idButton(this, technologies_list.at(row).objpath);
			connect (qpb02, SIGNAL(clickedID(QString, bool)), this, SLOT(togglePowered(QString, bool)));
			QString padding = "     ";
			if (bt ) {
				qpb02->setText(tr("%1On", "powered").arg(padding));
				qpb02->setIcon(QPixmap(":/icons/images/interface/golfball_green.png"));
				qpb02->setChecked(true);
			}
			else {
				qpb02->setText(tr("%1Off", "powered").arg(padding));
				qpb02->setIcon(QPixmap(":/icons/images/interface/golfball_red.png"));
				qpb02->setChecked(false);
			}	
			ui.tableWidget_technologies->setCellWidget(row, 2, qpb02);
			
			QTableWidgetItem* qtwi03 = new QTableWidgetItem();
			bt = technologies_list.at(row).objmap.value("Connected").toBool();
			qtwi03->setText( bt ? tr("Yes", "connected") : tr("No", "connected") );
			qtwi03->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_technologies->setItem(row, 3, qtwi03);
			
			QTableWidgetItem* qtwi04 = new QTableWidgetItem();
			bt = technologies_list.at(row).objmap.value("Tethered").toBool();
			qtwi04->setText( bt ? tr("Yes", "tethered") : tr("No", "tethered") );
			qtwi04->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_technologies->setItem(row, 4, qtwi04);	
		}	// technologies for loop
	}	// technologies if no error
		
	// Services
	if ( (q8_errors & CMST::Err_Services) == 0x00 ) {
		QString ss = QString();
		ui.tableWidget_services->clearContents();
		ui.tableWidget_services->setRowCount(services_list.size() );
		for (int row = 0; row < services_list.size(); ++row) {
			
			QTableWidgetItem* qtwi00 = new QTableWidgetItem();
			ss = services_list.at(row).objmap.value("Name").toString();
			ss = ss.replace(0, 1, ss.left(1).toUpper() );
			qtwi00->setText(ss);
			qtwi00->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_services->setItem(row, 0, qtwi00);		
			
			QTableWidgetItem* qtwi01 = new QTableWidgetItem();
			ss = services_list.at(row).objmap.value("State").toString();
			ss = ss.replace(0, 1, ss.left(1).toUpper() );
			qtwi01->setText(ss);
			qtwi01->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_services->setItem(row, 1, qtwi01);
			
			QTableWidgetItem* qtwi02 = new QTableWidgetItem();
			QFileInfo fi = services_list.at(row).objpath.path();
			qtwi02->setText(fi.baseName() );
			qtwi02->setTextAlignment(Qt::AlignVCenter|Qt::AlignLeft);
			ui.tableWidget_services->setItem(row, 2, qtwi02);
			
			if (ui.checkBox_hidecnxn->isChecked() ) {
				ui.tableWidget_services->hideColumn(2);
			}
			else {
				ui.tableWidget_services->showColumn(2);
				ui.tableWidget_services->horizontalHeader()->resizeSection(1, ui.tableWidget_services->horizontalHeader()->defaultSectionSize());
			}			
		}	// services for loop
		
		// resize the services column 0 to contents
		ui.tableWidget_services->resizeColumnToContents(0);			
			
	}	// services if no error
	
	return;
}

//
//	Function to assemble page 2 of the dialog.  Only fill in the
//	ui.comboBox_service widget.  The detail portion will be filled in 
//	by the getServiceDetails() slot whenever the comboBox index changes.
void ControlBox::assemblePage2()
{
	// initilize the page2 display widgets
	ui.comboBox_service->clear();
	ui.label_details_left->clear();
	ui.label_details_right->clear();
	
	//	services details
	if ( (q8_errors & CMST::Err_Services) == 0x00 ) {
	
		// populate the combobox
		for (int row = 0; row < services_list.size(); ++row) {
			QFileInfo fi =services_list.at(row).objpath.path();
			ui.comboBox_service->addItem(fi.baseName() );
		}	// services for loop
			
		ui.comboBox_service->setCurrentIndex(0);
	}	// services if no error
	
	return;
}

//
//	Function to assemble page 3 of the dialog.
void ControlBox::assemblePage3()
{
	//	initilize the table
	ui.tableWidget_wifi->clearContents();
	int rowcount=0;
	
	// Make sure we got the services_list before we try to work with it.	
	if ( (q8_errors & CMST::Err_Services) != 0x00 ) return;
	
	// Run through the technologies again, this time only look for wifi
	if ( (q8_errors & CMST::Err_Technologies) == 0x00 ) {
		int i_wifidevices= 0;
		int i_wifipowered = 0;
		for (int row = 0; row < technologies_list.size(); ++row) {
			if (technologies_list.at(row).objmap.value("Type").toString() .contains("wifi", Qt::CaseInsensitive) ) {
				++i_wifidevices;
				if (technologies_list.at(row).objmap.value("Powered").toBool() ) ++i_wifipowered;
			}	// if census
		}	// for loop
		ui.label_wifi_state->setText(tr("  WiFi Technologies:  %1 Found, %2 Powered").arg(i_wifidevices).arg(i_wifipowered) );
	}	// technologis if no errors	
		
	// Run through each service_list looking for wifi services
	wifi_list.clear();
	for (int row = 0; row < services_list.size(); ++row) {
		QMap<QString,QVariant> map = services_list.at(row).objmap;
		if (map.value("Type").toString().contains("wifi", Qt::CaseInsensitive) ) {
			wifi_list.append(services_list.at(row));
			ui.tableWidget_wifi->setRowCount(rowcount + 1);	
			
			QTableWidgetItem* qtwi00 = new QTableWidgetItem();
			qtwi00->setText(map.value("Name").toString() );
			qtwi00->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_wifi->setItem(rowcount, 0, qtwi00);	
			
			QLabel* ql01 = new QLabel(ui.tableWidget_wifi);			
			if (map.value("Favorite").toBool() ) {
				b_useicontheme ?
					ql01->setPixmap(QIcon::fromTheme("emblem-favorite", QIcon(":/icons/images/interface/favorite.png")).pixmap(QSize(16,16)) ) :
					ql01->setPixmap(QPixmap(":/icons/images/interface/favorite.png"));
			}
			ql01->setAlignment(Qt::AlignCenter);
			ui.tableWidget_wifi->setCellWidget(rowcount, 1, ql01);
			
			QLabel* ql02 = new QLabel(ui.tableWidget_wifi);
			if (map.value("State").toString().contains("online", Qt::CaseInsensitive) ) {
				b_useicontheme ?
					ql02->setPixmap(QIcon::fromTheme("network-transmit-receive", QIcon(":/icons/images/interface/connect_established.png")).pixmap(QSize(16,16)) ) :
					ql02->setPixmap(QPixmap(":/icons/images/interface/connect_established.png"));
			}	// if online
			else { 
				if (map.value("State").toString().contains("ready", Qt::CaseInsensitive) ) {
					b_useicontheme ?
						ql02->setPixmap(QIcon::fromTheme("network-idle", QIcon(":/icons/images/interface/connect_creating.png")).pixmap(QSize(16,16)) )	:
						ql02->setPixmap(QPixmap(":/icons/images/interface/connect_creating.png") );
				}	// if ready
				else {
					b_useicontheme ?
						ql02->setPixmap(QIcon::fromTheme("network-offline", QIcon(":/icons/images/interface/connect_no.png")).pixmap(QSize(16,16)) )	:
						ql02->setPixmap(QPixmap(":/icons/images/interface/connect_no.png"));
				}	// else any other state
			}	// else ready or any other state
			ql02->setAlignment(Qt::AlignCenter);
			QString s2 = map.value("State").toString();
			ql02->setToolTip(s2.replace(0, 1, s2.left(1).toUpper()) );
			ui.tableWidget_wifi->setCellWidget(rowcount, 2, ql02);			
			
			QTableWidgetItem* qtwi03 = new QTableWidgetItem();
			qtwi03->setText(map.value("Security").toStringList().join(',') );
			qtwi03->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_wifi->setItem(rowcount, 3, qtwi03);			
				
			QProgressBar* qpb04 = new QProgressBar(ui.tableWidget_wifi);
			qpb04->setAlignment(Qt::AlignCenter);
			qpb04->setRange(0, 100);
			qpb04->setValue(map.value("Strength").value<quint8>() );
			ui.tableWidget_wifi->setCellWidget(rowcount, 4, qpb04);
						
			++rowcount;
		}	//	if wifi cnxn
	}	// services for loop

	// resize the services column 0 and 1 to contents
	ui.tableWidget_wifi->resizeColumnToContents(0);
	ui.tableWidget_wifi->resizeColumnToContents(1);
	
	return;
} 

//
//	Function to assemble page 4 of the dialog.
void ControlBox::assemblePage4()
{	
	// Text for the counter settings label
	ui.label_counter_settings->setText(tr("Update resolution of the counters is based on a threshold of %L1 KB of data and %L2 seconds of time.") 	\
			.arg(counter_accuracy)	\
			.arg(counter_period) );
				
	return;
}

//
//	Function to assemble the tray icon tooltip text and picture
void ControlBox::assembleTrayIcon()
{
	QString stt = QString();
  
  if ( (q8_errors & CMST::Err_Properties) == 0x00 ) {
		if (properties_map.value("State").toString().contains("online", Qt::CaseInsensitive) ) {
			if ( (q8_errors & CMST::Err_Services) == 0x00 ) {
				QMap<QString,QVariant> submap;
				for (int i =0; i < services_list.size(); ++i) {
					if (services_list.at(i).objpath == serviceOnline() ) {
						if (services_list.at(i).objmap.value("Type").toString().contains("ethernet", Qt::CaseInsensitive) ) {
							extractMapData(submap, services_list.at(i).objmap.value("Ethernet") );
							stt.prepend(tr("Ethernet Connection<br>","icon_tool_tip"));
							stt.append(tr("Service: %1<br>").arg(services_list.at(i).objmap.value("Name").toString()) );
							stt.append(tr("Interface: %1").arg(submap.value("Interface").toString()) );		
							b_useicontheme ?
								trayicon->setIcon(QIcon::fromTheme("network-transmit-receive", QIcon(":/icons/images/systemtray/wired_established.png")) )	:
								trayicon->setIcon(QIcon(":/icons/images/systemtray/wired_established.png") );					
						}	//	if wired connection
						
						if (services_list.at(i).objmap.value("Type").toString().contains("wifi", Qt::CaseInsensitive) ) {
							stt.prepend(tr("WiFi Connection<br>","icon_tool_tip"));
							extractMapData(submap, services_list.at(i).objmap.value("Ethernet") );							
							stt.append(tr("SSID: %1<br>").arg(services_list.at(i).objmap.value("Name").toString()) );							
							stt.append(tr("Security: %1<br>").arg(services_list.at(i).objmap.value("Security").toStringList().join(',')) );
							stt.append(tr("Strength: %1%<br>").arg(services_list.at(i).objmap.value("Strength").value<quint8>()) );
							stt.append(tr("Interface: %1").arg(submap.value("Interface").toString()) );
							quint8 str = services_list.at(i).objmap.value("Strength").value<quint8>();
							if (b_useicontheme) trayicon->setIcon(QIcon::fromTheme("network-transmit-receive", QIcon(":/icons/images/systemtray/wl00.png")) );
							else {
							if (str > 80 ) trayicon->setIcon(QIcon(":/icons/images/systemtray/wl00.png"));
							else if (str > 60 )  trayicon->setIcon(QIcon(":/icons/images/systemtray/wl075.png"));
								else if (str > 40 )  trayicon->setIcon(QIcon(":/icons/images/systemtray/wl050.png"));
									else if (str > 20 )  trayicon->setIcon(QIcon(":/icons/images/systemtray/wl025.png"));
										else trayicon->setIcon(QIcon(":/icons/images/systemtray/wl000.png"));
							}	// else use our built in icons			
						}	//	if wifi connection
						break;
					}	// if the service is online
				}	// for
			}	//	services if no error
		}	//	if the state is online	
		else {
			b_useicontheme ?
				trayicon->setIcon(QIcon::fromTheme("network-offline", QIcon(":/icons/images/systemtray/connect_no.png")) )	:
				trayicon->setIcon(QIcon(":/icons/images/systemtray/connect_no.png") );
			stt.append(tr("Not Connected", "icon_tool_tip"));
		}	// else not connected
	}	// properties if no error
	
	// could not get any properties 
	else {
		b_useicontheme ?
			trayicon->setIcon(QIcon::fromTheme("network-error", QIcon(":/icons/images/interface/cancel.png")) )	:
			trayicon->setIcon(QIcon(":/icons/images/interface/cancel.png") );
		stt.append(tr("Error retrieving properties via Dbus"));
		stt.append(tr("Connection status is unknown"));
	}
	
	//	set the tool tip
	trayicon->setToolTip(stt);
	
	// show or hide depending on checkbox
	toggleTrayIcon(ui.checkBox_hideIcon->isChecked() );
	
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

// Slot to save GUI settings to disk
void ControlBox::writeSettings()
{
	settings->beginGroup("MainWindow");
	settings->setValue("size", size() );
	settings->setValue("pos", pos() );
	settings->endGroup();	
	
	settings->beginGroup("CheckBoxes");
	settings->setValue("hide_tray_icon", ui.checkBox_hideIcon->isChecked() );
	settings->setValue("devices_off", ui.checkBox_devicesoff->isChecked() );
	settings->setValue("retain_settings", ui.checkBox_retainsettings->isChecked() );
	settings->setValue("services_less", ui.checkBox_hidecnxn->isChecked() );
	settings->setValue("enable_interface_tooltips", ui.checkBox_enableinterfacetooltips->isChecked() );
	settings->setValue("enable_systemtray_tooltips", ui.checkBox_enablesystemtraytooltips->isChecked() );
	settings->setValue("enable_systemtray_notications", ui.checkBox_systemtraynotifications->isChecked() );
	settings->setValue("enable_daemon_notifications", ui.checkBox_notifydaemon->isChecked() );
	settings->setValue("reset_counters", ui.checkBox_resetcounters->isChecked() );
	settings->endGroup(); 
	
	return;
}

//
// Slot to read GUI settings to disk
void ControlBox::readSettings()
{
	// only restore settings if retain_settings is checked
	if (! settings->value("CheckBoxes/retain_settings").toBool() ) return;
	
	settings->beginGroup("MainWindow");
	resize(settings->value("size", QSize(700, 550)).toSize() );
	move(settings->value("pos", QPoint(200, 200)).toPoint() );
	settings->endGroup();
	
	settings->beginGroup("CheckBoxes");
	ui.checkBox_hideIcon->setChecked(settings->value("hide_tray_icon").toBool() );
	ui.checkBox_devicesoff->setChecked(settings->value("devices_off").toBool() );
	ui.checkBox_retainsettings->setChecked(settings->value("retain_settings").toBool() );
	ui.checkBox_hidecnxn->setChecked(settings->value("services_less").toBool() );
	ui.checkBox_enableinterfacetooltips->setChecked(settings->value("enable_interface_tooltips").toBool() );
	ui.checkBox_enablesystemtraytooltips->setChecked(settings->value("enable_systemtray_tooltips").toBool() );
	ui.checkBox_systemtraynotifications->setChecked(settings->value("enable_systemtray_notications").toBool() );
	ui.checkBox_notifydaemon->setChecked(settings->value("enable_daemon_notifications").toBool() );
	ui.checkBox_resetcounters->setChecked(settings->value("reset_counters").toBool() );
	settings->endGroup();
	
	return;
}

//
// Function to create the systemtray icon.  Really part of the constructor
// and called by a single shot QTimer (actually via a slot between the timer
// and here).  Used in situations where CMST is created before the system tray.
// The default time is zero seconds
void ControlBox::createSystemTrayIcon(bool b_startminimized)
{	
	// We still need to make sure there is a tray available	
	if (QSystemTrayIcon::isSystemTrayAvailable() ) {
		QMenu* trayIconMenu = new QMenu(this);
		trayIconMenu->addAction(maximizeAction);
		trayIconMenu->addAction(minimizeAction);
		trayIconMenu->addSeparator();
		trayIconMenu->addAction(exitAction);
	
		trayicon = new QSystemTrayIcon(this);
		trayicon->setContextMenu(trayIconMenu);
		connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
		ui.checkBox_hideIcon->setEnabled(true);
		this->updateDisplayWidgets();
		trayicon->setVisible(true);
	
		// start minimized, no reason to do anything as we're minimized until
		// we tell it otherwise

	}	// if
	else {
		ui.checkBox_hideIcon->setDisabled(true);
		trayicon = 0;
		
		QMessageBox::warning(this, tr("CMST Warning"),
			tr("<center><b>Unable to find a systemtray on this machine.</b>"                       
				 "<center><br>The program may still be used to manage your connections, but the tray icon will be disabled."
				 "<center><br><br>If you are seeing this message at system start up and you know a system tray exists once the "
				 "system is up, try starting with the <b>-w</b> switch and set a delay as necessary.  The exact wait time will vary "
				 "from system to system." 
					) );
		
		// Even if we want to be minimized we can't there is no place to minimize to.
		this->showNormal();
							
	}	// else
		
	
	return;
}

//
// Function to show notifications (if desired by the user).  Called from
// Called from the functions we connect dbus signals to, for instance
// dbsPropertyChanged(), stateChanged();
void ControlBox::sendNotifications(const QString& text, QIcon icon, QSystemTrayIcon::MessageIcon sticon)
{
	// if we want system tray notifications
	if (ui.checkBox_systemtraynotifications->isChecked() && QSystemTrayIcon::isSystemTrayAvailable() ) { 
		trayicon->showMessage(PROGRAM_NAME, text, sticon);
	}
	
	// if we want notify daemon notifications
	if (ui.checkBox_notifydaemon->isChecked() && notifyclient->isValid() ) {
		notifyclient->sendNotification(text, LONG_NAME);
	}
	
	return;
}

//
//	Function to query connman.manager.GetProperties
//	Return a bool, true on success, false otherwise
bool ControlBox::getProperties()
{
	// call connman and GetProperties
	QDBusMessage reply = iface_manager->call("GetProperties");
		
	// call the function to get the map values
	properties_map.clear();
	return getMap(properties_map, reply);
}

//
//	Function to query connman.manager.GetTechnologies
//	Return a bool, true on success, false otherwise
bool ControlBox::getTechnologies()
{
	// call connman and GetTechnologies
	QDBusMessage reply = iface_manager->call("GetTechnologies");
		
	// call the function to get the map values
	technologies_list.clear();
	return getArray(technologies_list, reply);		
}

//
//	Function to query connman.manager.GetServices
//	Return a bool, true on success, false otherwise
bool ControlBox::getServices()
{
	// call connman and GetServices
	QDBusMessage reply = iface_manager->call("GetServices");
		
	// call the function to get the map values
	services_list.clear();
	return getArray(services_list, reply);		
}

//
//	Function to extract arrayElements from a DBus reply message (that contains an array).
//	This data type is returned by GetServices and GetTechnologies. 
//
//	Return value a bool, true on success, false otherwise
//	A QList of arrayElements is sent by reference (called r_list here) 
//	and is modified by this function.  r_msg is a constant reference
//	to the DBus reply message.
bool ControlBox::getArray(QList<arrayElement>& r_list, const QDBusMessage& r_msg )
{
	//	make sure we got a result back in the r_msg
	if (! r_msg.type() == QDBusMessage::ReplyMessage ) return false;
	
	// make sure r_msg is a QDBusArgument
	if ( ! r_msg.arguments().at(0).canConvert<QDBusArgument>() ) return false;	
		
	// make sure the QDBusArgument holds an array
	const QDBusArgument &qdb_arg = r_msg.arguments().at(0).value<QDBusArgument>();
	if (! qdb_arg.currentType() == QDBusArgument::ArrayType ) return false;
	
	// iterate over the QDBusArgument pulling array elements out and inserting into
	// an arrayElement structure.
	qdb_arg.beginArray();
	r_list.clear();
		
	while ( ! qdb_arg.atEnd() ) {	
		// make sure the argument is a structure type
		if (! qdb_arg.currentType() == QDBusArgument::StructureType ) return false;
		
		arrayElement ael;
		qdb_arg.beginStructure();
		qdb_arg >> ael.objpath >> ael.objmap;
	  qdb_arg.endStructure();
		r_list.append (ael);
		}
	qdb_arg.endArray();		
	
	return true;
}
		
//	Function to extract a QMap from a DBus reply message (that contains a map).
//	This data type is returned by GetProperties
//
//	Return value a bool, true on success, false otherwise.
//	The map is sent by reference (called r_map here) and is modified by this function.
//	r_msg is a constant reference to the DBus reply message.
bool ControlBox::getMap(QMap<QString,QVariant>& r_map, const QDBusMessage& r_msg )
{
	//	make sure we got a result back in the r_msg
	if (! r_msg.type() == QDBusMessage::ReplyMessage ) return false;
	
	// make sure r_msg is a QDBusArgument
	if ( ! r_msg.arguments().at(0).canConvert<QDBusArgument>() ) return false;
	
	// make sure the QDBusArgument holds a map
	const QDBusArgument &qdb_arg = r_msg.arguments().at(0).value<QDBusArgument>();
	if (! qdb_arg.currentType() == QDBusArgument::MapType ) return false;	
	
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
//	Function to extract the data from a QDBusArgument that contains a map.
//	Some of the arrayElements can contain a QDBusArgument as the object
//	instead of a primitive (string, bool, int, etc.). This function
//	will extract the data from the QDBusArgument and write it into a map.
//
//	Return value a bool, true on success, false otherwise.
//	The map is sent by reference (called r_map here) and is modified by this function.
//	r_var is a constant reference to the QDBusArgument.
bool ControlBox::extractMapData(QMap<QString,QVariant>& r_map, const QVariant& r_var)
{
	//	make sure we can convert the QVariant into a QDBusArgument
	if (! r_var.canConvert<QDBusArgument>() ) return false;
	const QDBusArgument qdba =  r_var.value<QDBusArgument>();
	
	// make sure the QDBusArgument holds a map
	if (! qdba.currentType() == QDBusArgument::MapType ) return false;	
	
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
		}	// while
		qdba.endMap();	
}

//
//	Function to log errors to the system log
void ControlBox::logErrors(const quint8& err)
{
	//	store the error in a data element
	q8_errors |= err;
	
	//	Log the error in the system log
	//	LOG_PID 	Include PID with each message
	//	LOG_CONS	Write to console if there is a problem writing to system log
	//	LOG_USER	User Level Message
	//	LOG_ERR		Error condition
	//	LOG_WARNING		Warning contition
	//		Defined in resource.h	 
	openlog(PROGRAM_NAME, LOG_PID|LOG_CONS, LOG_USER);
	switch (err)
	{ 
		case  CMST::Err_No_DBus:
			syslog(LOG_ERR, tr("Could not find a connection to the system bus").toUtf8().constData() );
			QMessageBox::critical(this, tr("%1 - Critical Error").arg(PROGRAM_NAME),
				tr("Unable to find a connection to the system bus.<br><br>%1 will not be able to communicate with connman.").arg(PROGRAM_NAME) );			
			break;
		case  CMST::Err_Invalid_Iface:
			syslog(LOG_ERR, tr("Could not create an interface to connman on the system bus").toUtf8().constData());	
			QMessageBox::critical(this, tr("%1 - Critical Error").arg(PROGRAM_NAME),
				tr("Unable to create an interface to connman on the system bus.<br><br>%1 will not be able to communicate with connman.").arg(PROGRAM_NAME) );					
			break;
		case  CMST::Err_Properties:
			syslog(LOG_ERR, tr("Error reading or parsing connman.Manager.GetProperties").toUtf8().constData() );	
			QMessageBox::warning(this, tr("%1 - Warning").arg(PROGRAM_NAME),
				tr("There was an error reading or parsing the reply from method connman.Manager.GetProperties.<br><br>It is unlikely any portion of %1 will be functional.").arg(PROGRAM_NAME) );
			break;			
		case  CMST::Err_Technologies:
			syslog(LOG_ERR, tr("Error reading or parsing connman.Manager.GetTechnologies").toUtf8().constData() );
			QMessageBox::warning(this, tr("%1 - Warning").arg(PROGRAM_NAME),
				tr("There was an error reading or parsing the reply from method connman.Manager.GetTechnologies.<br><br>Some portion of %1 may still be functional.").arg(PROGRAM_NAME) );
			break;						
 		case  CMST::Err_Services:
			syslog(LOG_ERR, tr("Error reading or parsing connman.Manager.GetServices").toUtf8().constData() );	
			QMessageBox::warning(this, tr("%1 - Warning").arg(PROGRAM_NAME),
				tr("There was an error reading or parsing the reply from method connman.Manager.GetServices.<br><br>Some portion of %1 may still be functional.").arg(PROGRAM_NAME) );
			break;
 		default:
			break;			
		}	
 closelog();
 
 return;
}

//
//	Function to read text contained in a resource file.  Input is a const char* to the resource,
//	Return value is a QString of the text
QString ControlBox::readResourceText(const char* textfile)
{
	QString rtnstring = QString();
		
	QFile file(textfile);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QTextStream in(&file);
		while (!in.atEnd()) {
			rtnstring.append(in.readLine() );
		}	// while
	}	// if
	
	return rtnstring;
} 

//
// Function to return the object path of the service currently online
QDBusObjectPath ControlBox::serviceOnline()
{
	QDBusObjectPath service_online = QDBusObjectPath();	
	
	for (int i = 0; i < services_list.size(); ++i) {
		if (services_list.at(i).objmap.value("State").toString().contains("online", Qt::CaseInsensitive)) {
			service_online = services_list.at(i).objpath; 					
			break;
		}	// if
	}	// for	
		
	return service_online;
}

//
// Function to clear the counters if selected in the ui.  Called from the constructor
// and from dbsServicesChanged
void ControlBox::clearCounters()
{	
	if (ui.checkBox_resetcounters->isChecked() ) {			
		QDBusInterface* iface_serv = new QDBusInterface(DBUS_SERVICE, serviceOnline().path(), "net.connman.Service", QDBusConnection::systemBus(), this);	
		iface_serv->call(QDBus::NoBlock, "ResetCounters");
		iface_serv->deleteLater();
	}	
	
	return;
}
