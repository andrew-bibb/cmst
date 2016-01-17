/****************** vpn_ed.cpp ***********************************

Code to manage the VPN Provisioning Editor dialog.

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
# include <QFileDialog>

# include "./vpn_ed.h"
# include "./code/provisioning/prov_ed.h"	// use ValidatingDialog from ProvEd
# include "../resource.h"
# include "./code/trstring/tr_strings.h"
   
//
// This class is derived from the ProvisioningEditor class, and in fact
// it uses validating code from there.  There are a few improvements
// mainly in packaging text data into each QAction.  In this class
// QAction->text() contains the key for the Connman config file and display
// text for the menus.
// QAction->toolTip() contains the text displayed in dialogs
//  
VPN_Editor::VPN_Editor(QWidget* parent) : QDialog(parent)
{
  // Setup the user interface
  ui.setupUi(this);

  // Data members
  menubar = new QMenuBar(this);
  ui.verticalLayout01->setMenuBar(menubar);
  vpn_path = "/var/lib/connman-vpn";

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
  group_provider = new QActionGroup(this);
  group_provider->addAction(ui.actionProviderOpenConnect);
  group_provider->addAction(ui.actionProviderOpenVPN);
  group_provider->addAction(ui.actionProviderVPNC);
  group_provider->addAction(ui.actionProviderL2TP);
  group_provider->addAction(ui.actionProviderPPTP);
  
  group_freeform = new QActionGroup(this);
  group_freeform->addAction(ui.actionGlobal);
  group_freeform->addAction(ui.actionGlobalName);
  group_freeform->addAction(ui.actionGlobalDescription);
  group_freeform->addAction(ui.actionPPTP_User);
  group_freeform->addAction(ui.actionPPTP_Password);
  group_freeform->addAction(ui.actionPPPD_Debug);
  group_freeform->addAction(ui.actionL2TP_User);
  group_freeform->addAction(ui.actionL2TP_Password);
  group_freeform->addAction(ui.actionVPNC_IPSec_Secret);
  group_freeform->addAction(ui.actionVPNC_Xauth_Username);
  group_freeform->addAction(ui.actionVPNC_Xauth_Password);
  group_freeform->addAction(ui.actionVPNC_Domain);
  group_freeform->addAction(ui.actionVPNC_AppVersion);
  
  group_combobox = new QActionGroup(this);
  group_combobox->addAction(ui.actionVPNC_IKE_Authmode);
  group_combobox->addAction(ui.actionVPNC_IKE_DHGroup);
  group_combobox->addAction(ui.actionVPNC_PFS);
  group_combobox->addAction(ui.actionVPNC_Vendor);
  group_combobox->addAction(ui.actionVPNC_NATTMode);
    
  group_yes = new QActionGroup(this);
  group_yes->addAction(ui.actionPPPD_RefuseEAP);
  group_yes->addAction(ui.actionPPPD_RefusePAP);
  group_yes->addAction(ui.actionPPPD_RefuseCHAP);
  group_yes->addAction(ui.actionPPPD_RefuseMSCHAP);
  group_yes->addAction(ui.actionPPPD_RefuseMSCHAP2);
  group_yes->addAction(ui.actionPPPD_NoBSDComp);
  group_yes->addAction(ui.actionPPPD_NoDeflate);
  group_yes->addAction(ui.actionPPPD_RequirMPPE);
  group_yes->addAction(ui.actionPPPD_RequirMPPE40);
  group_yes->addAction(ui.actionPPPD_RequirMPPE128);
  group_yes->addAction(ui.actionPPPD_RequirMPPEStateful);
  group_yes->addAction(ui.actionPPPD_NoVJ);
  group_yes->addAction(ui.actionL2TP_LengthBit);
  group_yes->addAction(ui.actionL2TP_Challenge);
  group_yes->addAction(ui.actionL2TP_DefaultRoute);
  group_yes->addAction(ui.actionL2TP_FlowBit);
  group_yes->addAction(ui.actionL2TP_Exclusive);
  group_yes->addAction(ui.actionL2TP_Redial);
  group_yes->addAction(ui.actionL2TP_RequirePAP);
  group_yes->addAction(ui.actionL2TP_RequireCHAP);
  group_yes->addAction(ui.actionL2TP_ReqAuth);
  group_yes->addAction(ui.actionL2TP_AccessControl);
  group_yes->addAction(ui.actionL2TP_IPsecSaref);
  group_yes->addAction(ui.actionPPPD_NoPcomp);
  group_yes->addAction(ui.actionPPPD_UseAccomp);
  group_yes->addAction(ui.actionPPPD_ReqMPPE);
  group_yes->addAction(ui.actionPPPD_ReqMPPE40);
  group_yes->addAction(ui.actionPPPD_ReqMPPE128);
  group_yes->addAction(ui.actionPPPD_ReqMPPEStateful);
  group_yes->addAction(ui.actionVPNC_SingleDES);
  group_yes->addAction(ui.actionVPNC_NoEncryption);
      
  group_validated = new QActionGroup(this);
  group_validated->addAction(ui.actionPPPD_EchoFailure);
  group_validated->addAction(ui.actionPPPD_EchoInterval);
  group_validated->addAction(ui.actionL2TP_BPS);
  group_validated->addAction(ui.actionL2TP_TXBPS);
  group_validated->addAction(ui.actionL2TP_RXBPS);
  group_validated->addAction(ui.actionL2TP_TunnelRWS);
  group_validated->addAction(ui.actionL2TP_RedialTImeout);
  group_validated->addAction(ui.actionL2TP_MaxRedials);
  group_validated->addAction(ui.actionL2TP_ListenAddr);
  group_validated->addAction(ui.actionL2TP_Port);
  group_validated->addAction(ui.actionVPNC_LocalPort);
  group_validated->addAction(ui.actionVPNC_CiscoPort);
  group_validated->addAction(ui.actionVPNC_DPDTimeout);
       
  group_selectfile = new QActionGroup(this);
  group_selectfile->addAction(ui.actionL2TP_AuthFile);
  
  group_ipv4 = new QActionGroup(this);

  group_ipv6 = new QActionGroup(this);
  
  group_template = new QActionGroup(this);
  
  // Add Actions from UI to menu's
  menu_global = new QMenu(tr("Global"), this);
  menu_global->addAction(ui.actionGlobal);
  menu_global->addSeparator();
  menu_global->addAction(ui.actionGlobalName);
  menu_global->addAction(ui.actionGlobalDescription);
  
  menu_OpenConnect = new QMenu(tr("OpenConnect"), this);
  menu_OpenConnect->addAction(ui.actionProviderOpenConnect);
  menu_OpenConnect->addSeparator();
    
  menu_OpenVPN = new QMenu(tr("OpenVPN"), this);
  menu_OpenVPN->addAction(ui.actionProviderOpenVPN);
  menu_OpenVPN->addSeparator();
  
  menu_VPNC = new QMenu(tr("VPNC"), this);
  menu_VPNC->addAction(ui.actionProviderVPNC);
  menu_VPNC->addSeparator();
  menu_VPNC->addAction(ui.actionVPNC_IPSec_Secret);
  menu_VPNC->addAction(ui.actionVPNC_Xauth_Username);
  menu_VPNC->addAction(ui.actionVPNC_Xauth_Password);
  menu_VPNC->addSeparator();
  menu_VPNC->addAction(ui.actionVPNC_IKE_Authmode);
  menu_VPNC->addAction(ui.actionVPNC_IKE_DHGroup);
  menu_VPNC->addAction(ui.actionVPNC_PFS);
  menu_VPNC->addSeparator();
  menu_VPNC->addAction(ui.actionVPNC_Domain);
  menu_VPNC->addAction(ui.actionVPNC_Vendor);
  menu_VPNC->addAction(ui.actionVPNC_LocalPort);
  menu_VPNC->addAction(ui.actionVPNC_CiscoPort);
  menu_VPNC->addAction(ui.actionVPNC_AppVersion);
  menu_VPNC->addAction(ui.actionVPNC_NATTMode);
  menu_VPNC->addAction(ui.actionVPNC_DPDTimeout);
  menu_VPNC->addSeparator();
  menu_VPNC->addAction(ui.actionVPNC_SingleDES);
  menu_VPNC->addAction(ui.actionVPNC_NoEncryption);

  menu_L2TP = new QMenu(tr("L2TP"), this);
  menu_L2TP->addAction(ui.actionProviderL2TP);
  menu_L2TP->addSeparator();
  menu_L2TP->addSeparator();
  menu_L2TP->addAction(ui.actionL2TP_User);
  menu_L2TP->addAction(ui.actionL2TP_Password);
  menu_L2TP->addSeparator();
  menu_L2TP->addAction(ui.actionL2TP_BPS);
  menu_L2TP->addAction(ui.actionL2TP_TXBPS);
  menu_L2TP->addAction(ui.actionL2TP_RXBPS); 
  menu_L2TP->addAction(ui.actionL2TP_LengthBit);
  menu_L2TP->addAction(ui.actionL2TP_Challenge);
  menu_L2TP->addAction(ui.actionL2TP_DefaultRoute);
  menu_L2TP->addAction(ui.actionL2TP_FlowBit);
  menu_L2TP->addAction(ui.actionL2TP_TunnelRWS);
  menu_L2TP->addAction(ui.actionL2TP_Exclusive);
  menu_L2TP->addSeparator();
  menu_L2TP->addAction(ui.actionL2TP_Redial);
  menu_L2TP->addAction(ui.actionL2TP_RedialTImeout);
  menu_L2TP->addAction(ui.actionL2TP_MaxRedials);
  menu_L2TP->addSeparator();
  menu_L2TP->addAction(ui.actionL2TP_RequirePAP);
  menu_L2TP->addAction(ui.actionL2TP_RequireCHAP);
  menu_L2TP->addAction(ui.actionL2TP_ReqAuth);
  menu_L2TP->addSeparator();
  menu_L2TP->addAction(ui.actionL2TP_AccessControl);
  menu_L2TP->addAction(ui.actionL2TP_AuthFile);
  menu_L2TP->addSeparator();
  menu_L2TP->addAction(ui.actionL2TP_ListenAddr);
  menu_L2TP->addAction(ui.actionL2TP_IPsecSaref);
  menu_L2TP->addAction(ui.actionL2TP_Port);
  menu_L2TP->addSeparator();
	menu_L2TP->addAction(ui.actionPPPD_EchoFailure);
  menu_L2TP->addAction(ui.actionPPPD_EchoInterval);
  menu_L2TP->addAction(ui.actionPPPD_Debug);
  menu_L2TP->addSeparator();
  menu_L2TP->addAction(ui.actionPPPD_RefuseEAP);
  menu_L2TP->addAction(ui.actionPPPD_RefusePAP);
  menu_L2TP->addAction(ui.actionPPPD_RefuseCHAP);
  menu_L2TP->addAction(ui.actionPPPD_RefuseMSCHAP);
  menu_L2TP->addAction(ui.actionPPPD_RefuseMSCHAP2);
  menu_L2TP->addSeparator();
  menu_L2TP->addAction(ui.actionPPPD_NoBSDComp);  
  menu_L2TP->addAction(ui.actionPPPD_NoPcomp);
  menu_L2TP->addAction(ui.actionPPPD_UseAccomp);
  menu_L2TP->addAction(ui.actionPPPD_NoDeflate);
  menu_L2TP->addAction(ui.actionPPPD_NoVJ);
  menu_L2TP->addSeparator();
  menu_L2TP->addAction(ui.actionPPPD_ReqMPPE);
  menu_L2TP->addAction(ui.actionPPPD_ReqMPPE40);
  menu_L2TP->addAction(ui.actionPPPD_ReqMPPE128);
  menu_L2TP->addAction(ui.actionPPPD_ReqMPPEStateful);
      
  menu_PPTP = new QMenu(tr("PPTP"), this);
  menu_PPTP->addAction(ui.actionProviderPPTP);
  menu_PPTP->addSeparator();
  menu_PPTP->addAction(ui.actionPPTP_User);
  menu_PPTP->addAction(ui.actionPPTP_Password);
  menu_PPTP->addSeparator();
  menu_PPTP->addAction(ui.actionPPPD_EchoFailure);
  menu_PPTP->addAction(ui.actionPPPD_EchoInterval);
  menu_PPTP->addAction(ui.actionPPPD_Debug);
  menu_PPTP->addSeparator();
  menu_PPTP->addAction(ui.actionPPPD_RefuseEAP);
  menu_PPTP->addAction(ui.actionPPPD_RefusePAP);
  menu_PPTP->addAction(ui.actionPPPD_RefuseCHAP);
  menu_PPTP->addAction(ui.actionPPPD_RefuseMSCHAP);
  menu_PPTP->addAction(ui.actionPPPD_RefuseMSCHAP2);
  menu_PPTP->addSeparator();
  menu_PPTP->addAction(ui.actionPPPD_NoBSDComp);
  menu_PPTP->addAction(ui.actionPPPD_NoDeflate);
  menu_PPTP->addAction(ui.actionPPPD_NoVJ);
  menu_PPTP->addSeparator(); 
  menu_PPTP->addAction(ui.actionPPPD_RequirMPPE);
  menu_PPTP->addAction(ui.actionPPPD_RequirMPPE40);
  menu_PPTP->addAction(ui.actionPPPD_RequirMPPE128);
  menu_PPTP->addAction(ui.actionPPPD_RequirMPPEStateful);
    
  menu_template = new QMenu(tr("Templates"), this );
  
  // add menus to UI
  menubar->addMenu(menu_global);
  menubar->addMenu(menu_OpenConnect);
  menubar->addMenu(menu_OpenVPN);
  menubar->addMenu(menu_VPNC);
  menubar->addMenu(menu_L2TP);
  menubar->addMenu(menu_PPTP);
  menubar->addMenu(menu_template);  
  
  // connect signals to slots
  connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));
  connect(ui.pushButton_resetpage, SIGNAL(clicked()), this, SLOT(resetPage()));
  connect(bg01, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(requestFileList(QAbstractButton*)));
  connect(group_provider, SIGNAL(triggered(QAction*)), this, SLOT(createProvider(QAction*)));
  connect(group_freeform, SIGNAL(triggered(QAction*)), this, SLOT(inputFreeForm(QAction*)));
  connect(group_combobox, SIGNAL(triggered(QAction*)), this, SLOT(inputComboBox(QAction*)));
  connect(group_yes, SIGNAL(triggered(QAction*)), this, SLOT(inputYes(QAction*)));
  connect(group_validated, SIGNAL(triggered(QAction*)), this, SLOT(inputValidated(QAction*)));
  connect(group_selectfile, SIGNAL(triggered(QAction*)), this, SLOT(inputSelectFile(QAction*)));
  connect(group_ipv4, SIGNAL(triggered(QAction*)), this, SLOT(ipv4Triggered(QAction*)));
  connect(group_ipv6, SIGNAL(triggered(QAction*)), this, SLOT(ipv6Triggered(QAction*)));
  connect(group_template, SIGNAL(triggered(QAction*)), this, SLOT(templateTriggered(QAction*)));
}

/////////////////////////////////////////////// Private Slots /////////////////////////////////////////////
//
// Slot called when a member of the QActionGroup group_selectfile
void VPN_Editor::inputSelectFile(QAction* act)
{
  // variables
  QString key = act->text();
  QString filterstring = tr("All Files (*.*)");
  QString filepath = QDir::homePath();
  
  if (act == ui.actionL2TP_AuthFile) filepath = "/etc/l2tpd/l2tp-secrets";
  
  QString fname = QFileDialog::getOpenFileName(this, act->toolTip(),
                      filepath,
                      filterstring);

  // return if the file name returned is empty (cancel pressed in the dialog)
  if (fname.isEmpty() ) return;

  // put the path into the text edit
  key.append(" = %1\n");
  ui.plainTextEdit_main->insertPlainText(key.arg(fname) );
  
  return;
}


//
// Slot called when a member of the QActionGroup group_validated is triggered
void VPN_Editor::inputValidated(QAction* act, QString key)
{
  // variables
  if (key.isEmpty() ) key = act->text();
  
  // create the dialog
  ValidatingDialog* vd = new ValidatingDialog(this);
  
  // create some prompts and set validator
  if (key == "Host") {vd->setLabel(tr("VPN server IP address (ex: 1.2.3.4)")), vd->setValidator(CMST::ProvEd_Vd_46, false);}
  else vd->setLabel(act->toolTip() );
  
  if (act == ui.actionPPPD_EchoFailure) vd->setValidator(CMST::ProvEd_Vd_Int, false);
	if (act == ui.actionPPPD_EchoInterval) vd->setValidator(CMST::ProvEd_Vd_Int, false);	  
  if (act == ui.actionL2TP_BPS) vd->setValidator(CMST::ProvEd_Vd_Int, false);
  if (act == ui.actionL2TP_TXBPS) vd->setValidator(CMST::ProvEd_Vd_Int, false);
  if (act == ui.actionL2TP_RXBPS) vd->setValidator(CMST::ProvEd_Vd_Int, false);
  if (act == ui.actionL2TP_TunnelRWS) vd->setValidator(CMST::ProvEd_Vd_Int, false);
  if (act == ui.actionL2TP_RedialTImeout) vd->setValidator(CMST::ProvEd_Vd_Int, false);
  if (act == ui.actionL2TP_MaxRedials) vd->setValidator(CMST::ProvEd_Vd_Int, false);
  if (act == ui.actionL2TP_ListenAddr) vd->setValidator(CMST::ProvEd_Vd_46, false);
  if (act == ui.actionVPNC_LocalPort) vd->setValidator(CMST::ProvEd_Vd_Int, false);
  if (act == ui.actionVPNC_CiscoPort) vd->setValidator(CMST::ProvEd_Vd_Int, false);
  if (act == ui.actionVPNC_DPDTimeout) vd->setValidator(CMST::ProvEd_Vd_Int, false);
		 
  //if (act == ui.actionServiceMAC) {vd->setLabel(tr("MAC address.")); vd->setValidator(CMST::ProvEd_Vd_MAC);}
  //if (act == ui.actionWifiSSID) {vd->setLabel(tr("SSID: hexadecimal representation of an 802.11 SSID")), vd->setValidator(CMST:: ProvEd_Vd_Hex);}
  //if (act == ui.actionServiceNameServers) {vd->setLabel(tr("List of Nameservers")), vd->setValidator(CMST::ProvEd_Vd_46, true);}
  //if (act == ui.actionServiceTimeServers) {vd->setLabel(tr("List of Timeservers")), vd->setValidator(CMST::ProvEd_Vd_46, true);}
  //if (act == ui.actionServiceSearchDomains) {vd->setLabel(tr("List of DNS Search Domains")), vd->setValidator(CMST::ProvEd_Vd_Dom, true);}
  //if (act == ui.actionServiceDomain) {vd->setLabel(tr("Domain name to be used")), vd->setValidator(CMST::ProvEd_Vd_Dom);}
  //if (act == ui.actionWifiName) {vd->setLabel(tr("Enter the string representation of an 802.11 SSID.")), vd->setValidator(CMST::ProvEd_Vd_Wd);}
  
  // if accepted put an entry in the textedit
  if (vd->exec() == QDialog::Accepted) {
    QString s = vd->getText();
    key.append(" = %1\n");
    
    // format strings with multiple entries
    if (vd->isPlural() ) {
      s.replace(',', ' ');
      s.replace(';', ' ');
      s = s.simplified();
      s.replace(' ', ',');
    }
    
    ui.plainTextEdit_main->insertPlainText(key.arg(s) );
  }  
  
  // cleanup
  vd->deleteLater();
  return;
}

//
// Slot called when a member of the QActionGroup group_combobox is triggered
void VPN_Editor::inputComboBox(QAction* act)
{
  // variables
  QString key = act->text();
  QString str = act->toolTip();
  bool ok;
  QStringList sl;
  
  // create some prompts
  if (act == ui.actionVPNC_IKE_Authmode)  sl << "psk" << "cert" << "hybrid";
  if (act == ui.actionVPNC_IKE_DHGroup) sl << "dh1" << "dh2" << "dh5";
  if (act == ui.actionVPNC_PFS) sl << "nopfs" << "dh1" << "dh2" << "dh5" << "server";
  if (act == ui.actionVPNC_Vendor) sl << "cisco" << "netscreen";
  if (act == ui.actionVPNC_NATTMode) sl << "natt" << "none" << "force-natt" << "cisco-udp";
  
  QString item = QInputDialog::getItem(this,
    tr("%1 - Item Input").arg(TranslateStrings::cmtr("cmst")),
    str,
    sl,
    0,
    false,
    &ok);
    
  key.append(" = %1\n");
  if (ok) ui.plainTextEdit_main->insertPlainText(key.arg(item));
  
  return;
}

//
// Slot called when a member of the QActionGroup group_yes is triggered
// This slot is easy, every action sent is set to "yes"
void VPN_Editor::inputYes(QAction* act)
{
	if (QMessageBox::question (this, 
			tr("%1 - Verify Option").arg(TranslateStrings::cmtr("cmst")),
			act->toolTip(),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::Yes) == QMessageBox::Yes) ui.plainTextEdit_main->insertPlainText(QString(act->text() + " = yes\n") );
	
	return;
}
//
// Slot called when a member of the QActionGroup group_freeform is triggered
// Freeform strings may have spaces in them.  For strings that cannot have spaces
// use validated text and set b_multiple to false.
void VPN_Editor::inputFreeForm(QAction* act, QString key)
{
  // variables
  const QLineEdit::EchoMode echomode = QLineEdit::Normal;
  QString str;
  bool ok;  
  if (key.isEmpty() ) key = act->text();
  
  // create some prompts
  if (key == "Name") str = tr("User defined name for the VPN");
  else if (key == "Domain") str = tr("Domain name for the VPN Service\n(example: corporate.com)");
	else str = act->toolTip();
  
  if (act == ui.actionGlobal) {
    key.append("\n");
    ui.plainTextEdit_main->insertPlainText(key);
  }
  else {
    key.append(" = %1\n"); 
    
    // get the string from the user
    QString val= "";
      val = QInputDialog::getText(this,
        tr("%1 - Text Input").arg(TranslateStrings::cmtr("cmst")),
        str,
        echomode,
        "",
        &ok);
  
    if (ok) ui.plainTextEdit_main->insertPlainText(key.arg(val));
  } // else   
  
  return;
}

//
//  Slot called when a member of the QActionGroup group_ipv4 is triggered
void VPN_Editor::ipv4Triggered(QAction* act)
{//////////////////NOT USED
  // variables
  QString s = "IPv4 = %1\n";
  QString val;

  // process action
//  if (act == ui.actionServiceIPv4Off) ui.plainTextEdit_main->insertPlainText(s.arg("off") );
//  if (act == ui.actionServiceIPV4DHCP) ui.plainTextEdit_main->insertPlainText(s.arg("dhcp") );
  //if (act == ui.actionServiceIPv4Address) {
    //QMessageBox::StandardButton but = QMessageBox::information(this, 
                                        //QString(TranslateStrings::cmtr("cmst")) + tr(" Information"),
                                        //tr("The IPv4 <b>Address</b>, <b>Netmask</b>, and optionally <b>Gateway</b> need to be provided."  \
                                        //"<p>Press OK when you are ready to proceed."),
                                        //QMessageBox::Ok | QMessageBox::Abort,QMessageBox::Ok);
    //if (but == QMessageBox::Ok) {
      //VPNValidatingDialog* vd = new VPNValidatingDialog(this);
      //vd->setLabel(tr("IPv4 Address"));
      //vd->setValidator(CMST::ProvEd_Vd_IPv4);
      //if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) {
        //val = vd->getText();
        //vd->clear();
        //vd->setLabel(tr("IPv4 Netmask")); 
        //vd->setValidator(CMST::ProvEd_Vd_IPv4);
        //if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) {
          //val.append("/" + vd->getText() );
          //vd->clear();
          //vd->setLabel(tr("IPv4 Gateway (This is an optional entry)")); 
          //vd->setValidator(CMST::ProvEd_Vd_IPv4);
          //if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) { 
            //val.append("/" + vd->getText() );
          //} // if gateway accpted
          //ui.plainTextEdit_main->insertPlainText(s.arg(val) );
        //} // if netmask accepted
      //} // if address accepted 
      //vd->deleteLater();
    //} // we pressed OK on the information dialog
  //} // act == actionServiceIPv4Address
  
  return;
}

//
// Slot called when a member of the QActonGroup group_ipv6 is triggered
void VPN_Editor::ipv6Triggered(QAction* act)
{ /////////////////NOT USED
  // variables
  QString s = "IPv6 = %1\n";
  bool ok;
  QString val;

  // process action
//  if (act == ui.actionServiceIPv6Off) ui.plainTextEdit_main->insertPlainText(s.arg("off") );
//  if (act == ui.actionServiceIPv6Auto) ui.plainTextEdit_main->insertPlainText(s.arg("auto") );
//  if (act == ui.actionServiceIPv6Address) {
    //QMessageBox::StandardButton but = QMessageBox::information(this, 
                                        //QString(TranslateStrings::cmtr("cmst")) + tr(" Information"),
                                        //tr("The IPv6 <b>Address</b>, <b>Prefix Length</b>, and optionally <b>Gateway</b> need to be provided."  \
                                        //"<p>Press OK when you are ready to proceed."),
                                        //QMessageBox::Ok | QMessageBox::Abort,QMessageBox::Ok);
    //if (but == QMessageBox::Ok) {
      //VPNValidatingDialog* vd = new VPNValidatingDialog(this);
      //vd->setLabel(tr("IPv6 Address"));
      //vd->setValidator(CMST::ProvEd_Vd_IPv6);
      //if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) {
        //val = vd->getText();
        //int i = QInputDialog::getInt(this,
          //tr("%1 - Integer Input").arg(TranslateStrings::cmtr("cmst")),
          //tr("Enter the IPv6 prefix length"),
          //0, 0, 255, 1,
          //&ok);
        //if (ok) {
          //val.append(QString("/%1").arg(i) );
          //VPNValidatingDialog* vd = new VPNValidatingDialog(this);
          //vd->setLabel(tr("IPv6 Gateway (This is an optional entry)")); 
          //vd->setValidator(CMST::ProvEd_Vd_IPv6);
          //if (vd->exec() == QDialog::Accepted && ! vd->getText().isEmpty() ) {
            //val.append(QString("/" + vd->getText()) );
          //} // if gateway was accepted
          //ui.plainTextEdit_main->insertPlainText(s.arg(val) );
        //} // if prefix provided 
      //} // if address accepted
      //vd->deleteLater();
    //} // we pressed OK on the informaion dialog
  //} // act == actionServiceIPv6Address
  
  return;
}

//
// Slot called when a member of the QActionGroup group_template is triggered
void VPN_Editor::templateTriggered(QAction* act)
{ ///////////////NOT USED
  // variable
  QString source;
  
  // get the source string depending on the action
  //if (act == ui.actionTemplateEduroamLong) source = ":/text/text/eduroam_long.txt";
  //else if (act == ui.actionTemplateEduroamShort) source = ":/text/text/eduroam_short.txt";
  
  // get the text
  QFile file(source);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {  
    QByteArray ba = file.readAll();
    
    // seed the textedit with the template
    this->seedTextEdit(QString(ba));
  } // if 
  

  return;
}

//
//  Slot to enter whats this mode
//  Called when the ui.toolButton_whatsthis clicked() signal is emitted
void VPN_Editor::showWhatsThis()
{
  QWhatsThis::enterWhatsThisMode();
}

//
// Function to clear the contents of the textedit
void VPN_Editor::resetPage()
{
  ui.plainTextEdit_main->document()->clear();

  return;
}

//
// Slot to request a file list from the roothelper.
// Roothelper will emit an obtainedFileList signal when finished.  This slot 
// is connected to the QButtonGroup bg01
void VPN_Editor::requestFileList(QAbstractButton* button)
{
  // initialize the selection
  if (button == ui.pushButton_open) i_sel = CMST::ProvEd_File_Read;
  else if (button == ui.pushButton_save) i_sel = CMST::ProvEd_File_Write;
    else if (button == ui.pushButton_delete) i_sel = CMST::ProvEd_File_Delete;
      else i_sel = CMST::ProvEd_No_Selection;
  
  // request a list of config files from roothelper
  QList<QVariant> vlist;
  vlist << QVariant::fromValue(vpn_path);
  QDBusInterface* iface_rfl = new QDBusInterface("org.cmst.roothelper", "/", "org.cmst.roothelper", QDBusConnection::systemBus(), this);
  iface_rfl->callWithCallback(QLatin1String("getFileList"), vlist, this, SLOT(processFileList(const QStringList&)), SLOT(callbackErrorHandler(QDBusError)));
  
  iface_rfl->deleteLater();  
  return;
}

//
// Slot to process the file list from /var/lib/connman.  Connected to
// the obtainedFileList signal in roothelper
void VPN_Editor::processFileList(const QStringList& sl_conf)
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
      vlist << QVariant::fromValue(vpn_path);
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
      vlist << QVariant::fromValue(vpn_path);
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
      vlist<< QVariant::fromValue(vpn_path);
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
// fileReadCompleted signal in root helper.  Also called directly from
// the templateTriggered slot. 
void VPN_Editor::seedTextEdit(const QString& data)
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
void VPN_Editor::deleteCompleted(bool success)
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
void VPN_Editor::writeCompleted(qint64 bytes)
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
void VPN_Editor::callbackErrorHandler(QDBusError err)
{
  QMessageBox::critical(this,
    QString(TranslateStrings::cmtr("cmst")) + tr(" Critical"),
    QString(tr("<b>DBus Error Name:</b> %1<br><br><b>String:</b> %2<br><br><b>Message:</b> %3")).arg(err.name()).arg(err.errorString(err.type())).arg(TranslateStrings::cmtr(err.message()) ),
    QMessageBox::Ok,
    QMessageBox::Ok);
    
  return;
}

// Slot to prompt and create a new Provider section
void VPN_Editor::createProvider(QAction* act)
{
	// common mandatory fields
	if (act == ui.actionProviderOpenConnect) ui.plainTextEdit_main->insertPlainText("\n[provider_openconnect]\nType = OpenConnect\n");
		else if (act == ui.actionProviderOpenVPN) ui.plainTextEdit_main->insertPlainText("\n[provider_openvpn]\nType = OpenVPN\n");
			else if (act == ui.actionProviderVPNC) ui.plainTextEdit_main->insertPlainText("\n[provider_vpnc]\nType = VPNC\n");
				else if (act == ui.actionProviderL2TP) ui.plainTextEdit_main->insertPlainText("\n[provider_l2tp]\nType = L2TP\n");
					else if (act == ui.actionProviderPPTP) ui.plainTextEdit_main->insertPlainText("\n[provider_pptp]\nType = PPTP\n");
	inputFreeForm(act, "Name");
	inputValidated(act, "Host");
	inputFreeForm(act, "Domain");
	
	// individual provider mandatory fields
	if (act == ui.actionProviderVPNC) inputFreeForm(ui.actionVPNC_IPSEC_ID, "VPNC.IPSec.ID");
}
