/****************** prov_ed.cpp ***********************************

Code to manage the Provisioning Editor dialog.

Copyright (C) 2013-2020
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
# include <QDBusMessage>
# include <QDBusConnection>
# include <QDBusInterface>
# include <QMessageBox>
# include <QInputDialog>
# include <QList>
# include <QVariant>
# include <QAction>
# include <QFile>
# include <QFileDialog>
# include <QRegularExpression>

# include "./prov_ed.h"
# include "../resource.h"
# include "./code/trstring/tr_strings.h"
# include "./code/shared/shared.h"
//
// Provisioning Editor constructor
ProvisioningEditor::ProvisioningEditor(QWidget* parent, const float& ver) : QDialog(parent)
{
  // Setup the user interface
  ui.setupUi(this);

  // Data members
  menubar = new QMenuBar(this);
  ui.verticalLayout01->setMenuBar(menubar);
  con_path = "/var/lib/connman";

  statusbar = new QStatusBar(this);
  ui.verticalLayout01->addWidget(statusbar);
  statustimeout = 2000;
  i_sel = CMST::ProvEd_No_Selection;
  
  // Setup the buttongroup
  bg01 = new QButtonGroup(this);
  bg01->addButton(ui.pushButton_open);
  bg01->addButton(ui.pushButton_save);
  bg01->addButton(ui.pushButton_delete);
    
  // Add actions to actiongroups (signals from actiongroups are connected to slots)
  group_template = new QActionGroup(this);
  group_template->addAction(ui.actionTemplateEduroamLong);
  group_template->addAction(ui.actionTemplateEduroamShort);
  group_template->addAction(ui.actionTemplateeap_peap);
  group_template->addAction(ui.actionTemplateeap_tls);
  group_template->addAction(ui.actionTemplateeap_ttls);
  
  group_freeform = new QActionGroup(this);
  group_freeform->addAction(ui.actionGlobal);
  group_freeform->addAction(ui.actionGlobalName);
  group_freeform->addAction(ui.actionGlobalDescription);
  group_freeform->addAction(ui.actionService);
  group_freeform->addAction(ui.actionWifiPrivateKeyPassphrase);
  group_freeform->addAction(ui.actionWifiIdentity);
  group_freeform->addAction(ui.actionWifiAnonymousIdentity);
  group_freeform->addAction(ui.actionWifiPassphrase); 
  group_freeform->addAction(ui.actionWifiPhase2);
  group_freeform->addAction(ui.actionServiceDeviceName);
  
  group_combobox = new QActionGroup(this);
  group_combobox->addAction(ui.actionServiceType);
  group_combobox->addAction(ui.actionWifiEAP);
  group_combobox->addAction(ui.actionWifiPrivateKeyPassphraseType);
  group_combobox->addAction(ui.actionWifiSecurity);
  group_combobox->addAction(ui.actionWifiHidden);
  group_combobox->addAction(ui.actionServiceIPv6Privacy);
  group_combobox->addAction(ui.actionServiceIPv4);
  group_combobox->addAction(ui.actionServiceIPv6);
  group_combobox->addAction(ui.actionServicemDNS);

  group_validated = new QActionGroup(this);
  group_validated->addAction(ui.actionServiceMAC);
  group_validated->addAction(ui.actionWifiSSID);
  group_validated->addAction(ui.actionServiceNameServers);
  group_validated->addAction(ui.actionServiceTimeServers);
  group_validated->addAction(ui.actionServiceSearchDomains);
  group_validated->addAction(ui.actionServiceDomain);
  group_validated->addAction(ui.actionWifiName);
  group_validated->addAction(ui.actionWifiSubjectMatch);
  group_validated->addAction(ui.actionWifiAltSubjectMatch);
  group_validated->addAction(ui.actionWifiDomainMatch);
  group_validated->addAction(ui.actionWifiDomainSuffixMatch);
  
  group_selectfile = new QActionGroup(this);
  group_selectfile->addAction(ui.actionWifiCACertFile);
  group_selectfile->addAction(ui.actionWifiClientCertFile);
  group_selectfile->addAction(ui.actionWifiPrivateKeyFile);
  
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
  if (ver > 1.37f) {
    menu_service->addAction(ui.actionServiceDeviceName);
    menu_service->addAction(ui.actionServicemDNS);
  }
  menu_service->addSeparator();
  menu_service->addAction(ui.actionServiceIPv4);
  menu_service->addSeparator();
  menu_service->addAction(ui.actionServiceIPv6);
  menu_service->addAction(ui.actionServiceIPv6Privacy);
  menu_service->addSeparator();
  menu_service->addAction(ui.actionServiceNameServers);
  menu_service->addAction(ui.actionServiceTimeServers);
  menu_service->addAction(ui.actionServiceSearchDomains);
  
  menu_wifi = new QMenu(tr("WiFi"), this);
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
  if (ver > 1.37f) {
  menu_wifi->addAction(ui.actionWifiAnonymousIdentity);
  menu_wifi->addAction(ui.actionWifiSubjectMatch);
  menu_wifi->addAction(ui.actionWifiAltSubjectMatch);
  menu_wifi->addAction(ui.actionWifiDomainMatch);
  menu_wifi->addAction(ui.actionWifiDomainSuffixMatch);
  }
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
  menu_template->addSeparator();
  menu_template->addAction(ui.actionTemplateeap_peap);
  menu_template->addAction(ui.actionTemplateeap_tls);
  menu_template->addAction(ui.actionTemplateeap_ttls);
  
  // add menus to UI
  menubar->addMenu(menu_global);
  menubar->addMenu(menu_service);
  menubar->addMenu(menu_wifi);
  menubar->addMenu(menu_template);  
  
  // connect signals to slots
  connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));
  connect(ui.pushButton_resetpage, SIGNAL(clicked()), this, SLOT(resetPage()));
  connect(bg01, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(requestFileList(QAbstractButton*)));
  connect(group_template, SIGNAL(triggered(QAction*)), this, SLOT(templateTriggered(QAction*)));
  connect(group_freeform, SIGNAL(triggered(QAction*)), this, SLOT(inputFreeForm(QAction*)));
  connect(group_combobox, SIGNAL(triggered(QAction*)), this, SLOT(inputComboBox(QAction*)));
  connect(group_validated, SIGNAL(triggered(QAction*)), this, SLOT(inputValidated(QAction*)));
  connect(group_selectfile, SIGNAL(triggered(QAction*)), this, SLOT(inputSelectFile(QAction*)));
}

/////////////////////////////////////////////// Private Slots /////////////////////////////////////////////
//
// Slot called when a member of the QActionGroup group_selectfile
void ProvisioningEditor::inputSelectFile(QAction* act)
{
  // variables
  QString key = act->text();
  QString title;
  
  if (act == ui.actionWifiCACertFile) title = tr("File Path to the CA Certificate File");
  if (act == ui.actionWifiClientCertFile) title = tr("File Path to the Client Certificate File");
  if (act == ui.actionWifiPrivateKeyFile) title = tr("File path to the Client Private Key File");;
    
  
  QString fname = QFileDialog::getOpenFileName(this, title,
                      QDir::homePath(),
                      tr("Key Files (*.pem);;All Files (*.*)"));

  // return if the file name returned is empty (cancel pressed in the dialog)
  if (fname.isEmpty() ) return;

  // put the path into the text edit
  key.append(" = %1\n");
  ui.plainTextEdit_main->insertPlainText(key.arg(fname) );
  
  return;
}


//
// Slot called when a member of the QActionGroup group_validated is triggered
void ProvisioningEditor::inputValidated(QAction* act)
{
  // variables
  QString key = act->text();
  QChar delim(','); // default delim character for plurals
  
  // create the dialog
  shared::ValidatingDialog* vd = new shared::ValidatingDialog(this);
  
  // create some prompts and set validator
  if (act == ui.actionServiceMAC) {vd->setLabel(tr("MAC address.")); vd->setValidator(CMST::ValDialog_MAC);}
  if (act == ui.actionWifiSSID) {vd->setLabel(tr("SSID: hexadecimal representation of an 802.11 SSID")); vd->setValidator(CMST:: ValDialog_Hex);}
  if (act == ui.actionServiceNameServers) {vd->setLabel(tr("List of Nameservers")); vd->setValidator(CMST::ValDialog_46d, true);}
  if (act == ui.actionServiceTimeServers) {vd->setLabel(tr("List of Timeservers")); vd->setValidator(CMST::ValDialog_46d, true);}
  if (act == ui.actionServiceSearchDomains) {vd->setLabel(tr("List of DNS Search Domains")); vd->setValidator(CMST::ValDialog_Dom, true);}
  if (act == ui.actionServiceDomain) {vd->setLabel(tr("Domain name to be used")); vd->setValidator(CMST::ValDialog_Dom);}
  if (act == ui.actionWifiName) {vd->setLabel(tr("Enter the string representation of an 802.11 SSID.")); vd->setValidator(CMST::ValDialog_Word);}
  if (act == ui.actionWifiSubjectMatch) { vd->setLabel(tr("Substring to be matched against the subject of the authentication server")); vd->setValidator(CMST::ValDialog_Word);}
  if (act == ui.actionWifiAltSubjectMatch) {vd->setLabel(tr("List of entries to be matched against the alternative subject name.")); vd->setValidator(CMST::ValDialog_Word, true); delim=';';}
  if (act == ui.actionWifiDomainMatch) {vd->setLabel(tr("A fully qualified domain name used as a full match requirement for the authentication server")); vd->setValidator(CMST::ValDialog_Dom);}
  if (act == ui.actionWifiDomainSuffixMatch) {vd->setLabel(tr("A fully qualified domain name used as a suffix match requirement for the authentication server")); vd->setValidator(CMST::ValDialog_Dom);}
  
  // if accepted put an entry in the textedit
  if (vd->exec() == QDialog::Accepted) {
    QString s = vd->getText();
    key.append(" = %1\n");
    
    // format strings with multiple entries
    if (vd->isPlural() ) {
      s.replace(',', ' ');
      s.replace(';', ' ');
      s = s.simplified();
      s.replace(' ', delim);
    }
    
    ui.plainTextEdit_main->insertPlainText(key.arg(s) );
  }  
  
  // cleanup
  vd->deleteLater();
  return;
}

//
// Slot called when a member of the QActionGroup group_combobox is triggered
void ProvisioningEditor::inputComboBox(QAction* act)
{
  // variables
  QString key = act->text();
  QString str;
  bool ok;
  QStringList sl;
  
  // create some prompts
  if (act == ui.actionServiceType) {str = tr("Service type."); sl << "ethernet" << "wifi";}
  if (act == ui.actionWifiEAP) {str = tr("EAP type."); sl << "tls" << "ttls" << "peap";}
  if (act == ui.actionWifiPrivateKeyPassphraseType) {str = tr("Private key passphrase type."); sl << "fsid";}
  if (act == ui.actionWifiSecurity) {str = tr("Network security type."); sl << "psk" << "ieee8021x" << "wep" << "none";}
  if (act == ui.actionWifiHidden) {str = tr("Hidden network"); sl << "true" << "false";}
  if (act == ui.actionServiceIPv6Privacy) {str = tr("IPv6 Privacy"); sl << "disabled" << "enabled" << "preferred";}	
  if (act == ui.actionServiceIPv4) {str = tr("IPv4 Settings"); sl << "off" << "dhcp" << "address";}  
  if (act == ui.actionServiceIPv6) {str = tr("IPv6 Settings"); sl << "off" << "auto" << "address";}
  if (act == ui.actionServicemDNS) {str = tr("Enable mDNS"); sl << "false" << "true";}

  QStringList sl_tr = TranslateStrings::cmtr_sl(sl);
  QString item = QInputDialog::getItem(this,
    tr("%1 - Item Input").arg(TranslateStrings::cmtr("cmst")),
    str,
    sl_tr,
    0,
    false,
    &ok);
   
  // if we need ipv4  or ipv6 address information go there
  if (act == ui.actionServiceIPv4 && sl.at(sl_tr.indexOf(QRegularExpression(item))) == "address" ) ipv4Address();
  else{ 
    if (act == ui.actionServiceIPv6 && sl.at(sl_tr.indexOf(QRegularExpression(item))) == "address" ) ipv6Address();
    else { 
      key.append(" = %1\n");
    if (ok) ui.plainTextEdit_main->insertPlainText(key.arg(sl.at(sl_tr.indexOf(QRegularExpression(item)))) );
    }  // else not ipv4 or ipv6
  } //else not ipv4
    return;
}
//
// Slot called when a member of the QActionGroup group_freeform is triggered
// Freeform strings may have spaces in them.  For strings that cannot have spaces
// use validated text and set b_multiple to false.
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
  if (act == ui.actionGlobalDescription)  str = tr("Enter a description of the network.");
  if (act == ui.actionWifiPrivateKeyPassphrase) str = tr("Password/Passphrase for the private key file.");
  if (act == ui.actionWifiIdentity) str = tr("Identity string for EAP.");
  if (act == ui.actionWifiAnonymousIdentity) str = tr("Anonymous identity string for EAP.");
  if (act == ui.actionWifiPassphrase) str = tr("RSN/WPA/WPA2 Passphrase");
  if (act == ui.actionWifiPhase2) str = tr("Phase 2 (inner authentication with TLS tunnel)<br>authentication method.");   
  if (act == ui.actionServiceDeviceName) str = tr("The interface name in which to apply the provisioning (ex. eth0)") ; 
  
  if (act == ui.actionGlobal) {
    key.append("\n");
    ui.plainTextEdit_main->insertPlainText(key);
  }
  else {
    act == ui.actionService ? key = "[service_%1]\n" : key.append(" = %1\n"); 
    
    // get the string from the user
    QString text = "";
      text = QInputDialog::getText(this,
        tr("%1 - Text Input").arg(TranslateStrings::cmtr("cmst")),
        str,
        echomode,
        "",
        &ok);
  
    if (ok) ui.plainTextEdit_main->insertPlainText(key.arg(text));
  } // else   
  
  return;
}

//
//  Not a real slot anymore as we only call this directly when we need to get ipv4 address/netmask/gateway
//  information from the user.
void ProvisioningEditor::ipv4Address()
{
  // variables
  QString s = "IPv4 = %1\n";
  QString val;

  // process string item
  shared::ValidatingDialog* vd = new shared::ValidatingDialog(this);
    vd->setLabel(tr("IPv4 Address. <br><br>Enter the IPv4 network address in the form xxx.xxx.xxx.xxx"));
    vd->setValidator(CMST::ValDialog_IPv4);
    if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) {
      val = vd->getText();
      vd->clear();
      vd->setLabel(tr("IPv4 Netmask. <br><br>The entry can be a mask length (example 24) or in the form xxx:xxx:xxx:xxx")); 
      vd->setValidator(CMST::ValDialog_nmask);
      if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) {
	val.append("/" + vd->getText() );
	vd->clear();
	vd->setLabel(tr("IPv4 Gateway.<br><br>This is an optional entry, press cancel if there is no entry for gateway")); 
	vd->setValidator(CMST::ValDialog_IPv4);
	if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) { 
	  val.append("/" + vd->getText() );
	} // if gateway accpted
	ui.plainTextEdit_main->insertPlainText(s.arg(val) );
      } // if netmask accepted
    } // if address accepted 
    vd->deleteLater();

  return;
}

//
//  Not a real slot anymore as we only call this directly when we need to get ipv6 address/prefix/gateway
//  information from the user.
void ProvisioningEditor::ipv6Address()
{
  // variables
  QString s = "IPv6 = %1\n";
  bool ok;
  QString val;

  shared::ValidatingDialog* vd = new shared::ValidatingDialog(this);
    vd->setLabel(tr("IPv6 Address"));
    vd->setValidator(CMST::ValDialog_IPv6);
    if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) {
      val = vd->getText();
      int i = QInputDialog::getInt(this,
	tr("%1 - Integer Input").arg(TranslateStrings::cmtr("cmst")),
	tr("Enter the IPv6 prefix length"),
	0, 0, 255, 1,
	&ok);
      if (ok) {
	val.append(QString("/%1").arg(i) );
	shared::ValidatingDialog* vd = new shared::ValidatingDialog(this);
	vd->setLabel(tr("IPv6 Gateway .<br><br>This is an optional entry, press cancel if there is no entry for gateway")); 
	vd->setValidator(CMST::ValDialog_IPv6);
	if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) {
	  val.append(QString("/" + vd->getText()) );
	} // if gateway was accepted
	ui.plainTextEdit_main->insertPlainText(s.arg(val) );
      } // if prefix provided 
    } // if tddress accepted
    vd->deleteLater();

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
		else if (act == ui.actionTemplateeap_peap) source = ":/text/text/eap-peap.txt";
			else if (act == ui.actionTemplateeap_tls) source = ":/text/text/eap-tls.txt";
				else if (act == ui.actionTemplateeap_ttls) source = ":/text/text/eap-ttls.txt";
					else return;

  // get the text
  QFile file(source);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {  
    QByteArray ba = file.readAll();
    
    // append the template to the textedit
    ui.plainTextEdit_main->appendPlainText(QString(ba) );
  } // if 
  

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
  
  // request a list of config files from roothelper
  QList<QVariant> vlist;
  vlist << QVariant::fromValue(con_path);
  QDBusInterface* iface_rfl = new QDBusInterface("org.cmst.roothelper", "/", "org.cmst.roothelper", QDBusConnection::systemBus(), this);
  iface_rfl->callWithCallback(QLatin1String("getFileList"), vlist, this, SLOT(processFileList(const QStringList&)), SLOT(callbackErrorHandler(QDBusError)));
  
  iface_rfl->deleteLater();  
  return;
}

//
// Slot to process the file list from /var/lib/connman.  Connected to
// the obtainedFileList signal in roothelper
void ProvisioningEditor::processFileList(const QStringList& sl_conf)
{
  // variables
  bool ok;
  QString filename = "";
  QList<QVariant> vlist;
  QDBusInterface* iface_pfl = new QDBusInterface("org.cmst.roothelper", "/", "org.cmst.roothelper", QDBusConnection::systemBus(), this);
  
  // If we are trying to open and read the file
  if (i_sel & CMST::ProvEd_File_Read) {
    // display dialogs based on the length of the stringlist
    switch (sl_conf.size()) {
      case 0:
        QMessageBox::information(this, 
          QString(TranslateStrings::cmtr("cmst")) + tr(" Information"),
          tr("<center>No configuration files were found.<br>You may use this dialog to create one."),
          QMessageBox::Ok,
          QMessageBox::Ok);
        break; 
      case 1:
        QMessageBox::information(this,
          tr("%1 - Information").arg(TranslateStrings::cmtr("cmst")),
          tr("<center>Reading configuration file: %1").arg(sl_conf.at(0)),
          QMessageBox::Ok,
          QMessageBox::Ok);
        filename = sl_conf.at(0);
        break;
      default:
        QString item = QInputDialog::getItem(this,
            tr("%1 - Select File").arg(TranslateStrings::cmtr("cmst")),
            tr("Select a file to load."),
            sl_conf,
            0,      // current item 0
            false,  // non-editable
            &ok);
        if (ok) filename = item;    
        break;
      } // switch 
    // if we have a filename try to open the file
    if (! filename.isEmpty() ) {
      vlist.clear();
      vlist << QVariant::fromValue(con_path);
      vlist << QVariant::fromValue(filename); 
      iface_pfl->callWithCallback(QLatin1String("readFile"), vlist, this, SLOT(seedTextEdit(const QString&)), SLOT(callbackErrorHandler(QDBusError)));    
    } // if there is a file name
  } // if i_sel is File_Read
  
  // If we are trying to delete the file
  else if (i_sel & CMST::ProvEd_File_Delete) {
    // // user will have to select the file to delete it
    switch (sl_conf.size()) {     
      case 0:
        QMessageBox::information(this, 
          QString(TranslateStrings::cmtr("cmst")) + tr(" Information"),
          tr("<center>No configuration files were found.<br>Nothing will be deleted."),
          QMessageBox::Ok,
          QMessageBox::Ok);
        break; 
      default:
        QString item = QInputDialog::getItem(this,
            tr("%1 - Select File").arg(TranslateStrings::cmtr("cmst")),
            tr("Select a file to be deleted."),
            sl_conf,
            0,      // current item 0
            false,  // non-editable
            &ok);
        if (ok) filename = item; 
        break;
      } // switch
    // if we have a filename try to delete the file
    if (! filename.isEmpty() ) {
      vlist.clear();
      vlist << QVariant::fromValue(con_path);
      vlist << QVariant::fromValue(filename);
      iface_pfl->callWithCallback(QLatin1String("deleteFile"), vlist, this, SLOT(deleteCompleted(bool)), SLOT(callbackErrorHandler(QDBusError)));    
    } // if there is a file name
  } // if i_sel is File_Delete      
  
  // If we are trying to save the file
  else if (i_sel & CMST::ProvEd_File_Write) {
  QString item = QInputDialog::getItem(this,
      tr("%1 - Select File").arg(TranslateStrings::cmtr("cmst")),
      tr("Enter a new file name or select<br>an existing file to overwrite."),
      sl_conf,
      0,    // current item 0 
      true, // editable
      &ok);  
    if (ok) {
			filename = item.simplified();    				// multiple whitespace to one space
			filename = filename.replace(' ', '_');	// replace spaces with underscores
		}	// if ok
    // if we have a filename try to save the file
    if (! filename.isEmpty() ) {
      vlist.clear();
      vlist<< QVariant::fromValue(con_path);
      vlist << QVariant::fromValue(filename);
      vlist << QVariant::fromValue(ui.plainTextEdit_main->toPlainText() );
      iface_pfl->callWithCallback(QLatin1String("saveFile"), vlist, this, SLOT(writeCompleted(qint64)), SLOT(callbackErrorHandler(QDBusError)));   
    } // if there is a file name
  } // if i_sel is File_Save  
      
  // cleanup
  i_sel = CMST::ProvEd_No_Selection;
  iface_pfl->deleteLater();   
  return;
}

//
// Slot to seed the QTextEdit window with data read from file.  Connected to
// fileReadCompleted signal in root helper. 
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
void ProvisioningEditor::writeCompleted(qint64 bytes)
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

//
// Slot to handle errors from callWithCallback functions
void ProvisioningEditor::callbackErrorHandler(QDBusError err)
{
  QMessageBox::critical(this,
    QString(TranslateStrings::cmtr("cmst")) + tr(" Critical"),
    QString(tr("<b>DBus Error Name:</b> %1<br><br><b>String:</b> %2<br><br><b>Message:</b> %3")).arg(err.name()).arg(err.errorString(err.type())).arg(TranslateStrings::cmtr(err.message()) ),
    QMessageBox::Ok,
    QMessageBox::Ok);
    
  return;
}
