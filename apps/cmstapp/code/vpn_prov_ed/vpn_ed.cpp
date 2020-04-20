/****************** vpn_ed.cpp ***********************************

Code to manage the VPN Provisioning Editor dialog.

Copyright (C) 2016-2020
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
# include <QProcessEnvironment>

# include "./vpn_ed.h"
# include "../resource.h"
# include "./code/trstring/tr_strings.h"
# include "./code/shared/shared.h"
   
//
// This class is based on the ProvisioningEditor class,  There are a few improvements
// mainly in more efficient packaging of the text data into each QAction.
//
// In this class:
// QAction->text() contains the key for the Connman config file and display
// text for the menus. NOTE: This text cannot be translated.  
// QAction->toolTip() contains the text displayed in dialogs
//
// I've also removed the template section since the new group_provider actions
// ask for all mandatory fields for each type of connection.

//
//  Constructor  
VPN_Editor::VPN_Editor(QWidget* parent, const float& ver) : QDialog(parent)
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
  group_provider->addAction(ui.actionProviderWireGuard);
 
  group_freeform = new QActionGroup(this);
  group_freeform->addAction(ui.actionGlobal);
  group_freeform->addAction(ui.actionGlobalName);
  group_freeform->addAction(ui.actionGlobalDescription);
  group_freeform->addAction(ui.actionPPTP_User);
  group_freeform->addAction(ui.actionPPTP_Password);
  group_freeform->addAction(ui.actionPPPD_Debug);
  group_freeform->addAction(ui.actionL2TP_User);
  group_freeform->addAction(ui.actionL2TP_Password);
  group_freeform->addAction(ui.actionVPNC_IPSec_ID);
  group_freeform->addAction(ui.actionVPNC_IPSec_Secret);
  group_freeform->addAction(ui.actionVPNC_Xauth_Username);
  group_freeform->addAction(ui.actionVPNC_Xauth_Password);
  group_freeform->addAction(ui.actionVPNC_Domain);
  group_freeform->addAction(ui.actionVPNC_AppVersion);
  group_freeform->addAction(ui.actionOpenVPN_Cipher);
  group_freeform->addAction(ui.actionOpenVPN_Auth);
  group_freeform->addAction(ui.actionOpenConnect_Usergroup);
  group_freeform->addAction(ui.actionWireGuard_Address);
      
  group_combobox = new QActionGroup(this);
  group_combobox->addAction(ui.actionVPNC_IKE_Authmode);
  group_combobox->addAction(ui.actionVPNC_IKE_DHGroup);
  group_combobox->addAction(ui.actionVPNC_PFS);
  group_combobox->addAction(ui.actionVPNC_Vendor);
  group_combobox->addAction(ui.actionVPNC_NATTMode);
  group_combobox->addAction(ui.actionVPNC_DeviceType);
  group_combobox->addAction(ui.actionOpenVPN_NSCertType);
  group_combobox->addAction(ui.actionOpenVPN_Proto);
  group_combobox->addAction(ui.actionOpenVPN_CompLZO);
  group_combobox->addAction(ui.actionOpenVPN_RemoteCertTls);
  group_combobox->addAction(ui.actionOpenVPN_DeviceType);
  group_combobox->addAction(ui.actionOpenConnect_AllowSelfSignedCert);
  group_combobox->addAction(ui.actionOpenConnect_AuthType);
  group_combobox->addAction(ui.actionOpenConnect_DisableIPv6);
  group_combobox->addAction(ui.actionOpenConnect_NoDTLS);
  group_combobox->addAction(ui.actionOpenConnect_NoHTTPKeepalive);

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
  group_yes->addAction(ui.actionOpenVPN_AuthNoCache);
  group_yes->addAction(ui.actionOpenConnect_MTU);
  group_yes->addAction(ui.actionOpenConnect_Cookie);
   
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
  group_validated->addAction(ui.actionOpenVPN_MTU);
  group_validated->addAction(ui.actionOpenVPN_Port);
  group_validated->addAction(ui.actionOpenConnect_ServerCert);
  group_validated->addAction(ui.actionOpenConnect_VPNHost);
  group_validated->addAction(ui.actionWireGuard_ListPort);
  group_validated->addAction(ui.actionWireGuard_DNS);
  group_validated->addAction(ui.actionWireGuard_PrivateKey);
  group_validated->addAction(ui.actionWireGuard_PublicKey);
  group_validated->addAction(ui.actionWireGuard_PresharedKey);
  group_validated->addAction(ui.actionWireGuard_AllowedIPs);
  group_validated->addAction(ui.actionWireGuard_EndpointPort);
  group_validated->addAction(ui.actionWireGuard_PersistentKeepalive);
     
  group_selectfile = new QActionGroup(this);
  group_selectfile->addAction(ui.actionL2TP_AuthFile);
  group_selectfile->addAction(ui.actionOpenVPN_CACert);
  group_selectfile->addAction(ui.actionOpenVPN_Cert);
  group_selectfile->addAction(ui.actionOpenVPN_Key);
  group_selectfile->addAction(ui.actionOpenVPN_ConfigFile);
  group_selectfile->addAction(ui.actionOpenConnect_CACert);
  group_selectfile->addAction(ui.actionOpenConnect_ClientCert);
  group_selectfile->addAction(ui.actionOpenVPN_AuthUserPass);
  group_selectfile->addAction(ui.actionOpenVPN_AskPass);
  group_selectfile->addAction(ui.actionOpenConnect_PKCSClientCert);
  group_selectfile->addAction(ui.actionOpenConnect_UserPrivateKey);

  // Add Actions from UI to menu's
  menu_global = new QMenu(tr("Global"), this);
  menu_global->addAction(ui.actionGlobal);
  menu_global->addSeparator();
  menu_global->addAction(ui.actionGlobalName);
  menu_global->addAction(ui.actionGlobalDescription);
  
  menu_OpenConnect = new QMenu(tr("OpenConnect"), this);
  menu_OpenConnect->addAction(ui.actionProviderOpenConnect);
  menu_OpenConnect->addSeparator();
  menu_OpenConnect->addAction(ui.actionOpenConnect_ServerCert); 
  menu_OpenConnect->addAction(ui.actionOpenConnect_CACert);
  menu_OpenConnect->addAction(ui.actionOpenConnect_ClientCert);
  menu_OpenConnect->addSeparator(); 
  menu_OpenConnect->addAction(ui.actionOpenConnect_MTU);
  menu_OpenConnect->addAction(ui.actionOpenConnect_Cookie);
  menu_OpenConnect->addSeparator();
  menu_OpenConnect->addAction(ui.actionOpenConnect_VPNHost);  
  if (ver > 1.37f) {
    menu_OpenConnect->addSeparator();
    menu_OpenConnect->addAction(ui.actionOpenConnect_AllowSelfSignedCert);
    menu_OpenConnect->addAction(ui.actionOpenConnect_AuthType);
    menu_OpenConnect->addAction(ui.actionOpenConnect_DisableIPv6);
    menu_OpenConnect->addAction(ui.actionOpenConnect_NoDTLS);
    menu_OpenConnect->addAction(ui.actionOpenConnect_NoHTTPKeepalive);
    menu_OpenConnect->addAction(ui.actionOpenConnect_PKCSClientCert);
    menu_OpenConnect->addAction(ui.actionOpenConnect_Usergroup);
    menu_OpenConnect->addAction(ui.actionOpenConnect_UserPrivateKey);
  }
     
  menu_OpenVPN = new QMenu(tr("OpenVPN"), this);
  menu_OpenVPN->addAction(ui.actionProviderOpenVPN);
  menu_OpenVPN->addAction(ui.actionOpenVPN_Import);
  menu_OpenVPN->addSeparator();
  menu_OpenVPN->addAction(ui.actionOpenVPN_CACert);
  menu_OpenVPN->addAction(ui.actionOpenVPN_Cert);
  menu_OpenVPN->addAction(ui.actionOpenVPN_Key);
  menu_OpenVPN->addSeparator();
  menu_OpenVPN->addAction(ui.actionOpenVPN_MTU);
  menu_OpenVPN->addAction(ui.actionOpenVPN_NSCertType);
  menu_OpenVPN->addAction(ui.actionOpenVPN_Proto);
  menu_OpenVPN->addAction(ui.actionOpenVPN_Port);
  menu_OpenVPN->addSeparator();
  menu_OpenVPN->addAction(ui.actionOpenVPN_AuthUserPass); 
  menu_OpenVPN->addAction(ui.actionOpenVPN_AskPass);      
  menu_OpenVPN->addAction(ui.actionOpenVPN_AuthNoCache);  
  menu_OpenVPN->addSeparator();
  menu_OpenVPN->addAction(ui.actionOpenVPN_Cipher);
  menu_OpenVPN->addAction(ui.actionOpenVPN_Auth);
  menu_OpenVPN->addAction(ui.actionOpenVPN_CompLZO);
  menu_OpenVPN->addAction(ui.actionOpenVPN_RemoteCertTls); 
  menu_OpenVPN->addSeparator();  
  menu_OpenVPN->addAction(ui.actionOpenVPN_ConfigFile);
  if (ver > 1.37f) {
    menu_OpenVPN->addSeparator();
    menu_OpenVPN->addAction(ui.actionOpenVPN_DeviceType);
  }
  menu_VPNC = new QMenu(tr("VPNC"), this);
  menu_VPNC->addAction(ui.actionProviderVPNC);
  menu_VPNC->addSeparator();
  menu_VPNC->addAction(ui.actionVPNC_IPSec_ID);
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
  if (ver > 1.37f) {
    menu_VPNC->addSeparator();
    menu_VPNC->addAction(ui.actionVPNC_DeviceType);
  }

  menu_L2TP = new QMenu(tr("L2TP"), this);
  menu_L2TP->addAction(ui.actionProviderL2TP);
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
    
  menu_WireGuard = new QMenu(tr("WireGuard"), this);
  menu_WireGuard->addAction(ui.actionProviderWireGuard);
  menu_WireGuard->addSeparator();
  menu_WireGuard->addAction(ui.actionWireGuard_Address);
  menu_WireGuard->addAction(ui.actionWireGuard_ListPort);
  menu_WireGuard->addAction(ui.actionWireGuard_DNS);
  menu_WireGuard->addSeparator();
  menu_WireGuard->addAction(ui.actionWireGuard_PrivateKey);
  menu_WireGuard->addAction(ui.actionWireGuard_PublicKey);
  menu_WireGuard->addAction(ui.actionWireGuard_PresharedKey);
  menu_WireGuard->addAction(ui.actionWireGuard_AllowedIPs);
  menu_WireGuard->addAction(ui.actionWireGuard_EndpointPort);
  menu_WireGuard->addAction(ui.actionWireGuard_PersistentKeepalive);

  // add menus to UI
  menubar->addMenu(menu_global);
  menubar->addMenu(menu_OpenConnect);
  menubar->addMenu(menu_OpenVPN);
  menubar->addMenu(menu_VPNC);
  menubar->addMenu(menu_L2TP);
  menubar->addMenu(menu_PPTP);
  if (ver > 1.37f) {
    menubar->addMenu(menu_WireGuard);
  }
  
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
  connect (ui.actionOpenVPN_Import, SIGNAL(triggered()), this, SLOT(importOpenVPN()));
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
  if (act == ui.actionOpenVPN_AuthUserPass) filterstring = tr("User:Pass Files (*.up *.txt *.conf);;All Files (*.*)");
  
  filepath = "/etc/openvpn";
  if (act == ui.actionOpenVPN_CACert) filterstring = tr("CA Files (*.ca *.cert *.crt *.pem);;All Files (*.*)");
  if (act == ui.actionOpenVPN_Cert) filterstring = tr("Cert Files (*.ca *.cert *.crt *.pem);;All Files (*.*)");
  if (act == ui.actionOpenVPN_Key) filterstring = tr("Key Files (*.key *.ca *.cert *.crt *.pem);;All Files (*.*)");
  if (act == ui.actionOpenVPN_ConfigFile) filterstring = tr("Config Files (*.ovpn *.conf *.config);;All Files (*.*)");
  
  filepath = "/etc/openconnect";  
  if (act == ui.actionOpenConnect_CACert) filterstring = tr("Cert Files (*.pem *.ca *.crt *.cert);;All Files (*.*)");
  if (act == ui.actionOpenConnect_ClientCert) filterstring = tr("Cert Files (*.pem *.ca *.crt *.cert);;All Files (*.*)");
  if (act == ui.actionOpenConnect_PKCSClientCert) filterstring = tr("Cert Files (*.pem *.ca *.crt *.cert);;All Files (*.*)");
  if (act == ui.actionOpenConnect_UserPrivateKey) filterstring = tr("Cert Files (*.pem *.ca *.crt *.cert);;All Files (*.*)");
  
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
  QChar delim(','); // default delim character for plurals
  if (key.isEmpty() ) key = act->text();
  
  // create the dialog
  shared::ValidatingDialog* vd = new shared::ValidatingDialog(this);
  
  // create some prompts and set validator
  if (key == "Host") {vd->setLabel(tr("VPN server IP address (ex: 1.2.3.4)")), vd->setValidator(CMST::ValDialog_46, false);}
  else vd->setLabel(act->toolTip() );
  
  if (act == ui.actionPPPD_EchoFailure) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionPPPD_EchoInterval) vd->setValidator(CMST::ValDialog_Int, false);    
  if (act == ui.actionL2TP_BPS) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionL2TP_TXBPS) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionL2TP_RXBPS) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionL2TP_TunnelRWS) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionL2TP_RedialTImeout) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionL2TP_MaxRedials) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionL2TP_ListenAddr) vd->setValidator(CMST::ValDialog_46, false);
  if (act == ui.actionVPNC_LocalPort) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionVPNC_CiscoPort) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionVPNC_DPDTimeout) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionOpenVPN_MTU) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionOpenVPN_Port) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionOpenConnect_ServerCert) vd->setValidator(CMST:: ValDialog_Hex, false);
  if (act == ui.actionOpenConnect_VPNHost) vd->setValidator(CMST::ValDialog_46, false);
  if (act == ui.actionWireGuard_ListPort) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionWireGuard_DNS) vd->setValidator(CMST::ValDialog_46, true);
  if (act == ui.actionWireGuard_PrivateKey) vd->setValidator(CMST::ValDialog_Word, false);
  if (act == ui.actionWireGuard_PublicKey) vd->setValidator(CMST::ValDialog_Word, false);
  if (act == ui.actionWireGuard_PresharedKey) vd->setValidator(CMST::ValDialog_Word, false);
  if (act == ui.actionWireGuard_AllowedIPs) vd->setValidator(CMST::ValDialog_46, true);
  if (act == ui.actionWireGuard_EndpointPort) vd->setValidator(CMST::ValDialog_Int, false);
  if (act == ui.actionWireGuard_PersistentKeepalive) vd->setValidator(CMST::ValDialog_Int, false);

// if accepted put an entry in the textedit
  if (vd->exec() == QDialog::Accepted) {
    QString s = vd->getText();
    key.append(" = %1\n");
    
    // format strings with multiple entries
    if (vd->isPlural() ) {
      s.replace(',', ' ');
      s.replace(';', ' ');
      s.replace('|', ' ');
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
  if (act == ui.actionVPNC_DeviceType) sl << "tun" << "tap";
  if (act == ui.actionOpenVPN_NSCertType) sl << "client" << "server";
  if (act == ui.actionOpenVPN_Proto) sl << "udp" << "tcp-client" << "tcp-server";
  if (act == ui.actionOpenVPN_CompLZO) sl << "adaptive" << "yes" << "no";
  if (act == ui.actionOpenVPN_RemoteCertTls) sl << "client" << "server";
  if (act == ui.actionOpenVPN_DeviceType) sl << "tun" << "tap";
  if (act == ui.actionOpenConnect_AllowSelfSignedCert) sl << "false" << "true";
  if (act == ui.actionOpenConnect_AuthType) sl << "cookie" << "cookie_with_userpass" << "userpass" << "publickey" << "pkcs";
  if (act == ui.actionOpenConnect_DisableIPv6) sl << "false" << "true";
  if (act == ui.actionOpenConnect_NoDTLS) sl << "false" << "true";
  if (act == ui.actionOpenConnect_NoHTTPKeepalive) sl << "false" << "true";

  QStringList sl_tr = TranslateStrings::cmtr_sl(sl);
  QString item = QInputDialog::getItem(this,
    tr("%1 - Item Input").arg(TranslateStrings::cmtr("cmst")),
    str,
    sl_tr,
    0,
    false,
    &ok);
    
  key.append(" = %1\n");
  if (ok) ui.plainTextEdit_main->insertPlainText(key.arg(sl.at(sl_tr.indexOf(QRegularExpression(item)))) );   
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
  else if (key == "Domain") str = tr("Domain name for the VPN Service\n(ex: corporate.com)");
  else if (key == "Networks") str = tr("Networks behind the VPN link, if more than one separate by a comma.\n"
                                        "Format is network/netmask/gateway, and gateway can be omitted.\n"
                                        "Ex: 10.10.20.0/255.255.255.0/10.20.1.5,192.168.99.1/24,2001:Ldb8::1/16\n\n"
                                        "Networks = entry is optional and may be left blank.");
  else if (act == ui.actionWireGuard_Address) str = tr("Network address in the form address/netmask/peer.\n"
				        "Ex: 10.2.0.2/24" );
  
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
// Slot to process the file list from /var/lib/connman-vpn.  Connected to
// the callWithCallback signal in requestFileList() 
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
      filename = item.simplified();           // multiple whitespace to one space
      filename = filename.replace(' ', '_');  // replace spaces with underscores
    } // if ok
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
// fileReadCompleted signal in root helper.  
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
	    else if (act == ui.actionProviderWireGuard) ui.plainTextEdit_main->insertPlainText("\n[provider_wireguard]\nType = WireGuard\n");
  inputFreeForm(act, "Name");
  inputValidated(act, "Host");
  inputFreeForm(act, "Domain");
  inputFreeForm(act, "Networks");
  
  // individual provider mandatory fields
  if (act == ui.actionProviderVPNC) inputFreeForm(ui.actionVPNC_IPSec_ID, "VPNC.IPSec.ID");
  if (act == ui.actionProviderOpenVPN) {
    inputSelectFile(ui.actionOpenVPN_CACert);
    inputSelectFile(ui.actionOpenVPN_Cert);
    inputSelectFile(ui.actionOpenVPN_Key);
  }
  
  return;
}

//
// Slot to import an OpenVPN configuration file
void VPN_Editor::importOpenVPN()
{
  // Variables
  QString filterstring = tr("OpenVPN Configurations (*.ovpn  *.conf);;All Files (*.*)");
  QString filepath = QDir::homePath();  
  
  // To start things off we need some input from the user
  ui.plainTextEdit_main->insertPlainText("\n[provider_openvpn]\nType = OpenVPN\n");
  inputFreeForm(ui.actionProviderOpenConnect, "Name");
  inputValidated(ui.actionProviderOpenConnect, "Host");
  inputFreeForm(ui.actionProviderOpenConnect, "Domain");
  inputFreeForm(ui.actionProviderOpenConnect, "Networks");  
  QString fname = QFileDialog::getOpenFileName(this, tr("Select the configuration file to import"),
                      filepath,
                      filterstring);
  // Return if the file name returned is empty (cancel pressed in the dialog)
  if (fname.isEmpty() ) return;
  
  // Read the source file
  QFile sourcefile(fname);
  if (sourcefile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QString contents = QString(sourcefile.readAll());
    sourcefile.close();
    
    // Setup the data directories 
    // APP defined in resource.h
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    QFileInfo fi(fname);  // need to extract the baseName
    QDir target_dir = QDir(QString(env.value("XDG_DATA_HOME", QString(QDir::homePath()) + "/.local/share") + "/%1/openvpn/%2").arg(QString(APP).toLower()).arg(fi.baseName()) );
    if (! target_dir.exists()) target_dir.mkpath(target_dir.absolutePath() ); 
           
    // If auth-user-pass will be in the conf file ask to remove it
    if (contents.contains("auth-user-pass\n", Qt::CaseSensitive) ) {
      if (QMessageBox::question (this, 
        tr("Keep --auth-user-pass"),
        tr( "The conf file will contain the <b>auth-user-pass</b> entry which will require "
            "prompts sent to stdout and a reply on stdin.  This cannot be handled by "
            "Connman nor by CMST.<p>If this entry is removed you will need to create a "
            "\"user:pass\" file in order to have Connman make the VPN connection. In the "
            "next step you will be asked if you want to create this file and you will prompted "
            "for the user name and password.<p><b>Do you wish to remove this entry?</b>"),
        QMessageBox::Yes | QMessageBox::No,
        QMessageBox::Yes) == QMessageBox::Yes) contents.remove("auth-user-pass\n");
    } // if contents contains auth-user-pass

    // If there is anything left write it to a conf file
    contents = contents.trimmed();    
    if (! contents.isEmpty()) {
      QFile outfile(QString(target_dir.absolutePath() + "/%1%2")
        .arg(fi.baseName())
        .arg(".conf") );
      
      if (outfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outstream(&outfile);
        outstream << contents;
        outfile.close();
        ui.plainTextEdit_main->insertPlainText(QString(ui.actionOpenVPN_ConfigFile->text() + " = " + outfile.fileName() + "\n") );
      } // if outfile opened for writing      
      
      else {
        QMessageBox::warning(this, QString("%1 - Warning").arg(TranslateStrings::cmtr("cmst")),
        tr("Unable to write conf file <b>%1</b>").arg(outfile.fileName() ),
        QMessageBox::Ok,
        QMessageBox::Ok);
      } // else outfile (conf) failed to open        
    } // if contents not empty
    
    // Copy the original conf file for safekeeping
    if (target_dir.exists(fi.fileName()) ) target_dir.remove(fi.fileName());  
    sourcefile.copy(target_dir.absoluteFilePath(fi.fileName()) );
    
    // Check to see if a user:pass file needs to be created.
    if (QMessageBox::question (this, 
          tr("Create User:Password File"),
          tr("Do you wish to create a user:password file for this connection?"),
          QMessageBox::Yes | QMessageBox::No,
          QMessageBox::Yes) == QMessageBox::Yes) {
      bool b_continue = false;
      QString pass;
      QString user = QInputDialog::getText(this, tr("User"),
        tr("Enter the user name for this connection."),
        QLineEdit::Normal,
        "",
        &b_continue);
      if (b_continue) {
        pass = QInputDialog::getText(this, tr("Password"),
        tr("Enter the password for this connection."),
        QLineEdit::Normal,
        "",
        &b_continue);
      } // if
      if (b_continue) {
        QFile outfile(QString(target_dir.absolutePath() + "/%1%2")
        .arg(fi.baseName())
        .arg(".up") );
        if (outfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
          QTextStream outstream(&outfile);
          outstream << user << "\n" << pass << "\n";
          outfile.close();
          ui.plainTextEdit_main->insertPlainText(QString(ui.actionOpenVPN_AuthUserPass->text() + " = " + outfile.fileName() + "\n") );
        } // if outfile (up) could be opened for writing
        else {
          QMessageBox::warning(this, QString("%1 - Warning").arg(TranslateStrings::cmtr("cmst")),
            tr("Unable to write user:password file <b>%1</b>").arg(outfile.fileName() ),
            QMessageBox::Ok,
            QMessageBox::Ok);
        } // else outfile (up) failed to open
      } // b_continue - we have user and pass
    } // messagebox yes - we wanted to create a user:pass file    
  } // If sourcefile opened for reading
  
  else {
    QMessageBox::critical(this, QString("%1 - Critical").arg(TranslateStrings::cmtr("cmst")),
      tr("Unable to read <b>%1</b> - Aborting the import").arg(sourcefile.fileName() ),
      QMessageBox::Ok,
      QMessageBox::Ok);
    return;
  } // else sourcefile failed to open 
  
  // Print a done message
  QMessageBox::information(this, QString("%1 - Information").arg(TranslateStrings::cmtr("cmst")),
    tr("OpenVPN import is complete.  The provisioning file may now be saved."),
    QMessageBox::Ok,
    QMessageBox::Ok);

  return;
}

