/****************** prov_ed.cpp ***********************************

Code to manage the Provisioning Editor dialog.

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
# include <QRegularExpression>
# include <QRegularExpressionValidator>
# include <QDBusMessage>
# include <QDBusConnection>
# include <QDBusInterface>
# include <QMessageBox>
# include <QInputDialog>
# include <QList>
# include <QVariant>
# include <QAction>
# include <QFile>

# include "./prov_ed.h"
# include "../resource.h"

#define DBUS_SERVICE "net.connman"

ProvisioningEditor::ProvisioningEditor(QWidget* parent)
    : QDialog(parent)
{
  // Setup the user interface
  ui.setupUi(this);

  // Data members
  menubar = new QMenuBar(this);
  ui.verticalLayout01->setMenuBar(menubar);

  statusbar = new QStatusBar(this);
  ui.verticalLayout01->addWidget(statusbar);
  statustimeout = 2000;
  
  filename = "";
  i_sel = CMST::ProvEd_No_Selection;
  
  // Setup the buttongroup
  bg01 = new QButtonGroup(this);
  bg01->addButton(ui.pushButton_open);
  bg01->addButton(ui.pushButton_save);
  bg01->addButton(ui.pushButton_delete);
  
  // Add Actions from UI to menu's
  menu_global = new QMenu(tr("Global"), this);
  menu_global->addAction(ui.actionGlobal);
  menu_global->addSeparator();
  menu_global->addAction(ui.actionGlobalName);
  menu_global->addAction(ui.actionGlobalDescription);
  
  menu_service = new QMenu(tr("Service"), this);
  menu_service->addAction(ui.actionService);
  menu_service->addSeparator();
  menu_service->addAction(ui.actionServiceType);
  menu_service->addAction(ui.actionServiceDomain);
  menu_service->addAction(ui.actionServiceMAC);
  menu_service->addSeparator();
  menu_service->addAction(ui.actionServiceIPv4);
  menu_service->addAction(ui.actionServiceIPv6);
  menu_service->addSeparator();
	menu_service->addAction(ui.actionServiceNameServers);
	menu_service->addAction(ui.actionServiceTimeServers);
	menu_service->addAction(ui.actionServiceSearchDomains);
	
	menu_wifi = new QMenu(tr("WiFi"), this);
  menu_wifi->addAction(ui.actionWifi);
  menu_wifi->addSeparator();
  menu_wifi->addAction(ui.actionWifiName);
  menu_wifi->addAction(ui.actionWifiSSID);
  menu_wifi->addSeparator();
  menu_wifi->addAction(ui.actionWifiSecurity);
  menu_wifi->addAction(ui.actionWifiPassphrase);
  menu_wifi->addAction(ui.actionWifiHidden);
  menu_wifi->addAction(ui.actionWifiPhase2);
  menu_wifi->addSeparator();
	menu_wifi->addAction(ui.actionWifiEAP);
  menu_wifi->addAction(ui.actionWifiIdentity);	
  menu_wifi->addSeparator();
  menu_wifi->addAction(ui.actionWifiCACertFile);
  menu_wifi->addAction(ui.actionWifiClientCertFile);
  menu_wifi->addSeparator();
  menu_wifi->addAction(ui.actionWifiPrivateKeyFile);
  menu_wifi->addAction(ui.actionWifiPrivateKeyPassphrase);
  menu_wifi->addAction(ui.actionWifiPrivateKeyPassphraseType);
  
  menu_template = new QMenu(tr("Templates"), this);menu_template->addAction(ui.actionTemplateEduroamShort);
  menu_template->addAction(ui.actionTemplateEduroamLong);
  menu_template->addAction(ui.actionTemplateEduroamShort);
  
  // add menus to UI
  menubar->addMenu(menu_global);
  menubar->addMenu(menu_service);
  menubar->addMenu(menu_wifi);
  menubar->addMenu(menu_template);
  
  // add actions to actiongroups (signals from actiongroups are connected to slots)
  group_template = new QActionGroup(this);
  group_template->addAction(ui.actionTemplateEduroamLong);
  group_template->addAction(ui.actionTemplateEduroamShort);
  
  group_freeform = new QActionGroup(this);
  group_freeform->addAction(ui.actionGlobal);
  group_freeform->addAction(ui.actionGlobalName);
  group_freeform->addAction(ui.actionGlobalDescription);
  group_freeform->addAction(ui.actionService);
  group_freeform->addAction(ui.actionWifiName);
  group_freeform->addAction(ui.actionWifiPrivateKeyPassphrase);
  group_freeform->addAction(ui.actionWifiIdentity);
  group_freeform->addAction(ui.actionWifiPassphrase);	
	
  // Setup the address validator and apply it to any ui QLineEdit.
  // The lev validator will validate an IP address or up to one white space character (to allow
  // editing of the line edit).
  QString s_ip4 = "(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])";
  QString s_ip6 = "(?:[0-9a-fA-F]{1,4})";
  QString s_mac = "(?:[0-9a-fA-F]{1,2})";

  // QLineEdits that allow single address
  QRegularExpression rx4("\\s?|^" + s_ip4 + "(?:\\." + s_ip4 + "){3}" + "$");
  QRegularExpression rx6("\\s?|^" + s_ip6 + "(?::" + s_ip6 + "){7}" + "$");
  QRegularExpression rxm("\\s?|^" + s_mac + "(?::" + s_mac + "){5}" + "$");
  QRegularExpressionValidator* lev_4 = new QRegularExpressionValidator(rx4, this);
  QRegularExpressionValidator* lev_6 = new QRegularExpressionValidator(rx6, this);
  QRegularExpressionValidator* lev_m = new QRegularExpressionValidator(rxm, this); 

  
  // now QLineEdits that allow multiple addresses
  QRegularExpression rx46("\\s?|((" + s_ip4 + "(?:\\." + s_ip4 + "){3}|" + s_ip6 + "(?::" + s_ip6 + "){7})(\\s*[,|;|\\s]\\s*))+");
  QRegularExpressionValidator* lev_46 = new QRegularExpressionValidator(rx46, this);


  // connect signals to slots
  connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));
  connect(ui.pushButton_resetpage, SIGNAL(clicked()), this, SLOT(resetPage()));
  connect(bg01, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(requestFileList(QAbstractButton*)));
  connect(group_template, SIGNAL(triggered(QAction*)), this, SLOT(templateTriggered(QAction*)));
  connect(group_freeform, SIGNAL(triggered(QAction*)), this, SLOT(inputFreeForm(QAction*)));
  
  // signals from dbus
  QDBusConnection::systemBus().connect("org.cmst.roothelper", "/", "org.cmst.roothelper", "obtainedFileList", this, SLOT(processFileList(const QStringList&)));
  QDBusConnection::systemBus().connect("org.cmst.roothelper", "/", "org.cmst.roothelper", "fileReadCompleted", this, SLOT(seedTextEdit(const QString&)));
  QDBusConnection::systemBus().connect("org.cmst.roothelper", "/", "org.cmst.roothelper", "fileDeleteCompleted", this, SLOT(deleteCompleted(bool)));
  QDBusConnection::systemBus().connect("org.cmst.roothelper", "/", "org.cmst.roothelper", "fileWriteCompleted", this, SLOT(writeCompleted(quint64)));
}

/////////////////////////////////////////////// Private Slots /////////////////////////////////////////////
//
// Slot called when a member of the QActionGroup group_freeform is triggered
void ProvisioningEditor::inputFreeForm(QAction* act)
{
	// variables
	const QLineEdit::EchoMode echomode = QLineEdit::Normal;
	QString str;
	bool ok;	
	QString key = act->text();
	
	// create some prompts
	if (act == ui.actionService) str = tr("Tag which will replace the * with<br>an identifier unique to the config file.");
  if (act == ui.actionGlobalName) str = tr("Enter the network name.");
  if (act == ui.actionGlobalDescription) 	str = tr("Enter a description of the network.");
  if (act == ui.actionWifiName)	str = tr("Enter the string representation of an 802.11 SSID.");
  if (act == ui.actionWifiPrivateKeyPassphrase)	str = tr("Password/Passphrase for the private key file.");
  if (act == ui.actionWifiIdentity) str = tr("Identity string for EAP.");
  if (act == ui.actionWifiPassphrase) str = tr("RSN/WPA/WPA2 Passphrase");		
	
	if (act == ui.actionGlobal) {
		key.append("\n");
		ui.plainTextEdit_main->insertPlainText(key);
	}
	else {
		act == ui.actionService ? key = "[service_%1]\n" : key.append(" = %1\n");	
		
		// get the string from the user
		QString text = "";
			text = QInputDialog::getText(this,
				tr("%1 - Text Input").arg(PROGRAM_NAME),
				str,
				echomode,
				"",
				&ok);
	
		if (ok) ui.plainTextEdit_main->insertPlainText(key.arg(text));
	}	// else 	
	
	return;
}

//
// Slot called when a member of the QActionGroup group_template is triggered
void ProvisioningEditor::templateTriggered(QAction* act)
{
	// variable
	QString source;
	
	// get the source string depending on the action
	if (act == ui.actionTemplateEduroamLong) source = ":/text/text/eduroam_long.txt";
	else if (act == ui.actionTemplateEduroamShort) source = ":/text/text/eduroam_short.txt";
	
	// get the text
  QFile file(source);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {  
		QByteArray ba = file.readAll();
		
		// seed the textedit with the template
		this->seedTextEdit(QString(ba));
	}	// if 
	

	return;
}

//
//  Slot to enter whats this mode
//  Called when the ui.toolButton_whatsthis clicked() signal is emitted
void ProvisioningEditor::showWhatsThis()
{
  QWhatsThis::enterWhatsThisMode();
}

//
// Function to clear the contents of the textedit
void ProvisioningEditor::resetPage()
{
	ui.plainTextEdit_main->document()->clear();

  return;
}

//
// Slot to request a file list from the roothelper.
// Roothelper will emit an obtainedFileList signal when finished.  This slot 
// is connected to the QButtonGroup bg01
void ProvisioningEditor::requestFileList(QAbstractButton* button)
{
	// initialize the selection
	if (button == ui.pushButton_open) i_sel = CMST::ProvEd_File_Read;
  else if (button == ui.pushButton_save) i_sel = CMST::ProvEd_File_Write;
		else if (button == ui.pushButton_delete) i_sel = CMST::ProvEd_File_Delete;
			else i_sel = CMST::ProvEd_No_Selection;
	
	
	QDBusMessage msg = QDBusMessage::createMethodCall ("org.cmst.roothelper", "/", "org.cmst.roothelper", QLatin1String("getFileList"));
	QDBusMessage reply = QDBusConnection::systemBus().call(msg, QDBus::NoBlock);
	//qDebug() << reply;
	
	return;
}

//
// Slot to process the file list from /var/lib/connman.  Connected to
// the obtainedFileList signal in roothelper
void ProvisioningEditor::processFileList(const QStringList& sl_conf)
{
	// variables
	bool ok;
	filename.clear();
	QList<QVariant> vlist;
  QDBusInterface* iface_pfl = new QDBusInterface("org.cmst.roothelper", "/", "org.cmst.roothelper", QDBusConnection::systemBus(), this);
  
	// If we are trying to open and read the file
	if (i_sel & CMST::ProvEd_File_Read) {
		// display dialogs based on the length of the stringlist
		switch (sl_conf.size()) {
			case 0:
				QMessageBox::information(this, 
					QString(PROGRAM_NAME) + tr("- Information"),
					tr("<center>No configuration files were found.<br>You may use this dialog to create one."),
					QMessageBox::Ok,
					QMessageBox::Ok);
				break; 
			case 1:
				QMessageBox::information(this,
					tr("%1 - Information").arg(PROGRAM_NAME),
					tr("<center>Reading configuration file: %1").arg(sl_conf.at(0)),
					QMessageBox::Ok,
					QMessageBox::Ok);
				filename = sl_conf.at(0);
				break;
			default:
				QString item = QInputDialog::getItem(this,
						tr("%1 - Select File").arg(PROGRAM_NAME),
						tr("Select a file to load."),
						sl_conf,
						0,
						false,
						&ok);
				if (ok) filename = item;		
				break;
			}	// switch	
		// if we have a filename try to open the file
		if (! filename.isEmpty() ) {
			vlist.clear();
			vlist << QVariant::fromValue(filename);
		  QDBusMessage reply01 = iface_pfl->callWithArgumentList(QDBus::AutoDetect, QLatin1String("readFile"), vlist);	
		}	// if there is a file name
	}	// if i_sel is File_Read
	
	// If we are trying to delete the file
	else if (i_sel & CMST::ProvEd_File_Delete) {
		// // user will have to select the file to delete it
		switch (sl_conf.size()) {			
			case 0:
				QMessageBox::information(this, 
					QString(PROGRAM_NAME) + tr("- Information"),
					tr("<center>No configuration files were found.<br>Nothing will be deleted."),
					QMessageBox::Ok,
					QMessageBox::Ok);
				break; 
			default:
				QString item = QInputDialog::getItem(this,
						tr("%1 - Select File").arg(PROGRAM_NAME),
						tr("Select a file to be deleted."),
						sl_conf,
						0,
						false,
						&ok);
				if (ok) filename = item;		
				break;
			}	// switch
		// if we have a filename try to delete the file
		if (! filename.isEmpty() ) {
			vlist.clear();
			vlist << QVariant::fromValue(filename);
		  QDBusMessage reply02 = iface_pfl->callWithArgumentList(QDBus::AutoDetect, QLatin1String("deleteFile"), vlist);
		  // qDebug() << reply02			
		}	// if there is a file name
	}	// if i_sel is File_Delete			
	
	// If we are trying to save the file
	else if (i_sel & CMST::ProvEd_File_Write) {
	QString item = QInputDialog::getItem(this,
			tr("%1 - Select File").arg(PROGRAM_NAME),
			tr("Enter a new file name or select an existing file to overwrite."),
			sl_conf,
			0,
			true,
			&ok);
		if (ok) filename = item;		
		// if we have a filename try to save the file
		if (! filename.isEmpty() ) {
			vlist.clear();
			vlist << QVariant::fromValue(filename);
			vlist << QVariant::fromValue(ui.plainTextEdit_main->toPlainText() );
		  QDBusMessage reply03 = iface_pfl->callWithArgumentList(QDBus::AutoDetect, QLatin1String("saveFile"), vlist);	
		  //qDebug() << reply03;		
		}	// if there is a file name
	}	// if i_sel is File_Save	
			
	// cleanup
	i_sel = CMST::ProvEd_No_Selection;
  iface_pfl->deleteLater();		
	return;
}

//
// Slot to seed the QTextEdit window with data read from file.  Connected to
// fileReadCompleted signal in root helper.  Also called directly from
// the templateTriggered slot. 
void ProvisioningEditor::seedTextEdit(const QString& data)
{
	// clear the text edit and seed it with the read data
	ui.plainTextEdit_main->document()->clear();
	ui.plainTextEdit_main->setPlainText(data);
	
	// show a statusbar message
	statusbar->showMessage(tr("File read completed"), statustimeout);
	
	return;
}

//
// Slot to show a statusbar message when a file delete is completed
void ProvisioningEditor::deleteCompleted(bool success)
{
	QString msg;
	
	if (success)
		msg = tr("File deleted");
	else
		msg = tr("Error encountered deleting.");
	
	statusbar->showMessage(msg, statustimeout);
	return;
}	

//
// Slot to show a statusbar message when a file write is completed
void ProvisioningEditor::writeCompleted(quint64 bytes)
{
	// display a status bar message showing the results of the write
	QString msg;
	
	if (bytes < 0 )
		msg = tr("File save failed.");
	else {
		if (bytes > 1024)
			msg = tr("%L1 KB written").arg(bytes / 1024);
		else	
			msg = tr("%L1 Bytes written").arg(bytes);
	}
	
	statusbar -> showMessage(msg, statustimeout);
	return;
}

