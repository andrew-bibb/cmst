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
# include <QMessageBox>
# include <QInputDialog>

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
  filename="";
  
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
  
  // add Menu's to UI
  menubar->addMenu(menu_global);
  menubar->addMenu(menu_service);
  menubar->addMenu(menu_wifi);
	
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
  connect(ui.pushButton_open, SIGNAL(clicked()), this, SLOT(requestFileList()));
  connect(ui.pushButton_save, SIGNAL(clicked()), this, SLOT(createConfFile()));
  
  // signals from dbus
  QDBusConnection::systemBus().connect("org.cmst.roothelper", "/", "org.cmst.roothelper", "obtainedFileList", this, SLOT(processFileList(const QStringList&)));
}

/////////////////////////////////////////////// Private Slots /////////////////////////////////////////////
//
//  Slot to enter whats this mode
//  Called when the ui.toolButton_whatsthis clicked() signal is emitted
void ProvisioningEditor::showWhatsThis()
{
  QWhatsThis::enterWhatsThisMode();
}

//
// Function to clear the contents of the specified page.  If the page
// argument is less than one (default value is -1) then clear the
// current toolbox page. Called when ui.pushButton_resetpage is clicked()
void ProvisioningEditor::resetPage()
{
  // find the page (index) to clear.
  //int toolboxindex = ui.toolBox_prov_ed->currentIndex();
  //if (page >= 0 ) toolboxindex = page;

  //switch (toolboxindex) {
    //case 0:
			//ui.lineEdit_name->clear();
      //ui.plainTextEdit_description->clear();
      //break;
    //case 1:
			//ui.comboBox_type->setCurrentIndex(0);
			//ui.comboBox_ipv4method->setCurrentIndex(0);
			//ui.lineEdit_ipv4address->clear();
			//ui.lineEdit_ipv4netmask->clear();
			//ui.lineEdit_ipv4gateway->clear();
			//ui.comboBox_ipv6method->setCurrentIndex(0);
			//ui.spinBox_ipv6prefixlength->setValue(0);
      //ui.lineEdit_ipv6address->clear();
      //ui.lineEdit_ipv6gateway->clear();
      //ui.comboBox_ipv6privacy->setCurrentIndex(0);
      //ui.lineEdit_macaddress->clear();
      //ui.lineEdit_domain->clear();
      //ui.lineEdit_nameservers->clear();
      //ui.lineEdit_timeservers->clear();
      //ui.lineEdit_searchdomains->clear();
      //break;
    //case 2:
			//ui.lineEdit_wifiname->clear();
			//ui.lineEdit_wifissid->clear();
			//ui.checkBox_wifihidden->setChecked(false);		
			//ui.comboBox_eaptype->setCurrentIndex(0);
			//ui.lineEdit_eaptype->clear();
			//ui.lineEdit_cacertfile->clear();
			//ui.lineEdit_clientcertfile->clear();
			//ui.lineEdit_privatekeyfile->clear();
			//ui.lineEdit_privatekeypassphrase->clear();
			//ui.comboBox_privatekeypassphrasetype->setCurrentIndex(0);
			//ui.comboBox_securitytype->setCurrentIndex(0);
			//ui.lineEdit_passphrase->clear();
			//ui.lineEdit_phase2->clear();
      //break;
    //default:
      //break;
  //} // switch

  return;
}

//
// Slot to request a file list from the roothelper.  Connected to the 
// ui.pushButton_open control
void ProvisioningEditor::requestFileList()
{
	QDBusMessage msg = QDBusMessage::createMethodCall ("org.cmst.roothelper", "/", "org.cmst.roothelper", QLatin1String("getFileList"));
	QDBusMessage reply = QDBusConnection::systemBus().call(msg, QDBus::NoBlock);
	//qDebug() << reply;
	return;
}

//
// Slot to process the file list from /var/lib/connman.  Connected to
// the readCompleted signal in roothelper
void ProvisioningEditor::processFileList(const QStringList& sl_conf)
{
	// variables
	bool ok;
		
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
			
	return;
}

//
// Slot to create a QByteArray representing the .conf file and send it to roothelper
// write to disk
void ProvisioningEditor::createConfFile()
{
	//QString s_working = "";
	
	//// global section
	//if (! ui.lineEdit_name->text().isEmpty() || ! ui.plainTextEdit_description->document()->toPlainText().isEmpty() )  {
		//s_working.append("[global]\n");
		//if (! ui.lineEdit_name->text().isEmpty() ) s_working.append(QString("Name = %1\n").arg(ui.lineEdit_name->text()) );
		//if (! ui.plainTextEdit_description->document()->toPlainText().isEmpty() )
			//s_working.append(QString("Description = %1\n").arg(ui.plainTextEdit_maincument()->toPlainText()) );
		//s_working.append("\n");
			
	//}	// global section
	
	//qDebug() << "working string";
	//qDebug() << s_working;
	
	return;
}
