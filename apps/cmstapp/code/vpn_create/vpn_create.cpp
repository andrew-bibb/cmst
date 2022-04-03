/****************** vpn_create.cpp ***********************************

Code to manage the VPN Provisioning Editor dialog.

Copyright (C) 2022-2022
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

// Class to provide the functionallity of the VPNmanager.Create() method.

# include <QtCore/QDebug>
# include <QRegularExpression>
# include <QRegularExpressionValidator>
# include <QFileDialog>
# include <QDir>

# include "./code/vpn_create/vpn_create.h"
# include "./code/trstring/tr_strings.h"
# include "./code/shared/shared.h"
# include "../resource.h"


# define VPN_PATH "/var/lib/connman-vpn"

//
// Constructor
VPN_Create::VPN_Create(QWidget* parent, const float& ver, const QIcon& fileicon) : QDialog(parent)
{
   // Setup the user interface
   ui.setupUi(this);

   // Setup the QDBusInterface
   iface_rh1 = new QDBusInterface("org.cmst.roothelper", "/", "org.cmst.roothelper", QDBusConnection::systemBus(), this);

   // Setup the QInputDialog
   qid = new QInputDialog(this);
      qid->setOption(QInputDialog::UseListViewForComboBoxItems);
      qid->setWindowModality(Qt::WindowModality::ApplicationModal);
      qid->setInputMode(QInputDialog::TextInput); qid->setWindowTitle(tr("%1 - Select File").arg(TranslateStrings::cmtr("cmst")) );

   // Set up environment for where we need to store the file
   QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
   datahome = QString(env.value("XDG_DATA_HOME", QString(QDir::homePath()) + "/.local/share") + "/%1").arg(QString(APP).toLower());

   // Set OK button to disable
   ui.buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);

   // Assign validators to input boxes
   // note:
   // L2TP.DefaultRoute and L2TP.LisenAddr could have validators on them but the documentation is so sparse I don't actually know
   // what they should be.  For now don't put a validator on those fields.
   //
   // OpenVPN Do not validate any of the Mandatory fields as seems some (maybe all) can be provided in the config file
   QRegularExpressionValidator* qrex_46cidr= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_46cidr, false)), this);
      ui.lineEdit_host->setValidator(qrex_46cidr);

   QRegularExpressionValidator* qrex_46cidrp= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_46cidr, true)), this);
      ui.lineEdit_05_dns->setValidator(qrex_46cidrp);
      ui.lineEdit_05_allowedips->setValidator(qrex_46cidrp);

   QRegularExpressionValidator* qrex_46= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_46, false)), this);
      ui.lineEdit_00_vpnhost->setValidator(qrex_46);

   QRegularExpressionValidator* qrex_dom= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_Dom, false)), this);
      ui.lineEdit_domain->setValidator(qrex_dom);

   QRegularExpressionValidator* qrex_networks= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_networks, true)), this);
      ui.lineEdit_networks->setValidator(qrex_networks);
      ui.lineEdit_05_address->setValidator(qrex_networks);

   // disable newer features if Connman does not support them
   if (ver <= 1.37f) {
      ui.checkBox_00_allowselfsignedcert->setDisabled(true);   // no OpenConnect self signed certs
      ui.checkBox_00_disableipv6->setDisabled(true);   // no OpenConnect option to disable ipv6
      ui.checkBox_00_disabledtls->setDisabled(true);   // no OpenConnect option to disable no-dtls
      ui.checkBox_00_nokeepalive->setDisabled(true);   // no OpenConnect option for https keep alive
      ui.comboBox_00_authtype->setDisabled(true);      // no OpenConnect Authorization type, also forces ClientCert, PKSCClientCert and UserPrivateKey to stay disabled
      ui.lineEdit_00_usergroup->setDisabled(true);     // no OpenConnect usergroup
      ui.comboBox_02_interfacemode->setDisabled(true); // no VPNC interface mode
      ui.stackedWidget->widget(5)->setDisabled(true);  // no wireguard
   } // if

   // QActionGroup and QActions
   qag = new QActionGroup(this);
   action_00_cacert = new QAction(fileicon, "CA Certificate File", qag);
   action_00_cacert->setToolTip(tr("Select the file containing other Certificate Authorities"));
   ui.lineEdit_00_cacert->addAction(action_00_cacert, QLineEdit::TrailingPosition);

   action_00_clientcert = new QAction(fileicon, "Client Certificate File", qag);
   action_00_clientcert->setToolTip(tr("Select the file containing the Client Certificate"));
   ui.lineEdit_00_clientcert->addAction(action_00_clientcert, QLineEdit::TrailingPosition);

   action_00_pkcsclientcert = new QAction(fileicon, "PKCS Client Certificate File", qag);
   action_00_pkcsclientcert->setToolTip(tr("Select the file containing the PKCS Client Certificate"));
   ui.lineEdit_00_pkcsclientcert->addAction(action_00_pkcsclientcert, QLineEdit::TrailingPosition);

   action_01_cacert = new QAction(fileicon, "Certificate Authority File", qag);
   action_01_cacert->setToolTip(tr("Select the file containing the Certificate Authority"));
   ui.lineEdit_01_cacert->addAction(action_01_cacert, QLineEdit::TrailingPosition);

   action_01_cert = new QAction(fileicon, "Local Peer Signed Certificate", qag);
   action_01_cert->setToolTip(tr("Select the file containing the Local Peer's Signed Certificate"));
   ui.lineEdit_01_cert->addAction(action_01_cert, QLineEdit::TrailingPosition);

   action_01_key = new QAction(fileicon, "Local Peer Private Key", qag);
   action_01_key->setToolTip(tr("Select the file containing the Local Peer's Private Key"));
   ui.lineEdit_01_key->addAction(action_01_key, QLineEdit::TrailingPosition);

   action_01_config = new QAction(fileicon, "Extra Options", qag);
   action_01_config->setToolTip(tr("Select the file containing extra OpenVPN options"));
   ui.lineEdit_01_config->addAction(action_01_config, QLineEdit::TrailingPosition);

   action_01_authuserpass = new QAction(fileicon, "User/Password File", qag);
   action_01_authuserpass->setToolTip(tr("Select the file containing the User and Password credentials"));
   ui.lineEdit_01_authuserpass->addAction(action_01_authuserpass, QLineEdit::TrailingPosition);

   action_01_askpass = new QAction(fileicon, "Private Password Key File", qag);
   action_01_askpass->setToolTip(tr("Select the file containing the password to unlock the private key"));
   ui.lineEdit_01_askpass->addAction(action_01_askpass, QLineEdit::TrailingPosition);

   action_03_authfile = new QAction(fileicon, "Authority File", qag);
   action_03_authfile->setToolTip(tr("Select the L2TP Authority file"));
   ui.lineEdit_03_authfile->addAction(action_03_authfile, QLineEdit::TrailingPosition);

   // Connect signals and slots
   connect (ui.lineEdit_name, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_host, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_domain, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_networks, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_00_vpnhost, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_02_groupusername, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_address, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_dns, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_privatekey, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_publickey, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_allowedips, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (this, SIGNAL(accepted()), this, SLOT(createFile()));
   connect (qag, SIGNAL(triggered(QAction*)), this, SLOT(processAction(QAction*)));
   connect (ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));
   connect (ui.comboBox_00_authtype, SIGNAL(currentIndexChanged(int)), this, SLOT(openConnectAuthTypeChanged(int)));
   connect (ui.pushButton_01_importopvn, SIGNAL(clicked()), this, SLOT(importOpenVPN()));
   connect (ui.pushButton_01_createuserpass, SIGNAL(clicked()), this, SLOT(createUserPass()));

   // Load the OpenVPN cipher comboBox, this is way too long to enter via the QDesigner ui editor.
   QStringList sl;
   sl << "AES-128-CBC" << "AES-128-CFB" << "AES-128-CFB1" << "AES-128-CFB8" << "AES-128-GCM" << "AES-128-OFB" << "AES-192-CBC" << "AES-192-CFB" << "AES-192-CFB1" << "AES-192-CFB8" << "AES-192-GCM"  << "AES-192-OFB" << "AES-256-CBC" << "AES-256-CFB" << "AES-256-CFB1" << "AES-256-CFB8" << "AES-256-GCM" << "AES-256-OFB" << "ARIA-128-CBC" << "ARIA-128-CFB"  << "ARIA-128-CFB1" << "ARIA-128-CFB" << "ARIA-128-OFB" << "ARIA-192-CBC" << "ARIA-192-CFB" << "ARIA-192-CFB1" << "ARIA-192-CFB8" << "ARIA-192-OFB" << "ARIA-256-CBC" << "ARIA-256-CFB" << "ARIA-256-CFB1" << "ARIA-256-CFB8" << "ARIA-256-OFB" << "CAMELLIA-128-CBC" << "CAMELLIA-128-CFB" << "CAMELLIA-128-CFB1" << "CAMELLIA-128-CFB8" << "CAMELLIA-128-OFB" << "CAMELLIA-192-CBC" << "CAMELLIA-192-CFB" << "CAMELLIA-192-CFB1" << "CAMELLIA-192-CFB8" << "CAMELLIA-192-OFB" << "CAMELLIA-256-CBC" << "CAMELLIA-256-CFB" << "CAMELLIA-256-CFB1" << "CAMELLIA-256-CFB8" << "CAMELLIA-256-OFB" << "CHACHA20-POLY1305" << "SEED-CBC" << "SEED-CFB" << "SEED-OFB" << "SM4-CBC" << "SM4-CFB" << "SM4-OFB" << "BF-CBC" << "BF-CFB" << "BF-OFB" << "CAST5-CBC" << "CAST5-CFB" << "CAST5-OFB" << "DES-CBC" << "DES-CFB" << "DES-CFB1" << "DES-CFB8" << "DES-EDE-CBC" << "DES-EDE-CFB" << "DES-EDE-OFB" << "DES-EDE3-CBC" << "DES-EDE3-CFB" << "DES-EDE3-CFB1" << "DES-EDE3-CFB8" << "DES-EDE3-OFB" << "DES-OFB" << "DESX-CBC" << "IDEA-CBC" << "IDEA-CFB" << "IDEA-OFB" << "RC2-40-CBC" << "RC2-64-CBC" << "RC2-CBC" << "RC2-CFB" << "RC2-OFB";
   ui.comboBox_01_cipher->insertItems(1, sl);

   // set index to something we're working on
   ui.comboBox_type->setCurrentIndex(4);
      return;
}

//////////////////////////////////////////////// Private Slots /////////////////////////////////////////
//
// Slot called when this emits an accepted() signal (user clicks OK).
// Write the provisioning file
void VPN_Create::createFile()
{
   // data members
   const QString newline(QString("\n"));
   const QString eqyes(QString(" = yes\n"));
   const QString eqtrue(QString(" = true\n"));
   QString rtnstr(QString("[provider_"));

   // typical information
   rtnstr.append(ui.comboBox_type->currentText().toLower() );
   rtnstr.append("]");
   rtnstr.append(newline);

   rtnstr.append("Type = ");
   rtnstr.append(ui.comboBox_type->currentText() );
   rtnstr.append(newline);

   rtnstr.append("Name = ");
   rtnstr.append(ui.lineEdit_name->text() );
   rtnstr.append(newline);

   rtnstr.append("Host = ");
   rtnstr.append(ui.lineEdit_host->text() );
   rtnstr.append(newline);

   if (! ui.lineEdit_domain->text().isEmpty() ) {
      rtnstr.append("Domain = ");
      rtnstr.append(ui.lineEdit_domain->text() );
      rtnstr.append(newline);
   } // if

   if (! ui.lineEdit_networks->text().isEmpty() ) {
      rtnstr.append("Networks = ");
      rtnstr.append(ui.lineEdit_networks->text() );
      rtnstr.append(newline);
   } // if

   // information specific to each VPN type
   // lines which don't start with an "if" are validated with checkInput() before we get here.
   switch (ui.comboBox_type->currentIndex() )
   {
      case 0:
         if (! ui.lineEdit_00_servercert->text().isEmpty()) rtnstr.append("OpenConnect.ServerCert = ").append(ui.lineEdit_00_servercert->text().append(newline));
         if (! ui.lineEdit_00_cacert->text().isEmpty()) rtnstr.append("OpenConnect.CACert = ").append(ui.lineEdit_00_cacert->text().append(newline));
         if (! ui.lineEdit_00_vpnhost->text().isEmpty()) rtnstr.append("OpenConnect.VPNHost = ").append(ui.lineEdit_00_vpnhost->text().append(newline));
         if (ui.spinBox_00_mtu->value() > 0) rtnstr.append(QString("OpenConnect.MTU = %1").arg(ui.spinBox_00_mtu->value()).append(newline));
         if (ui.checkBox_00_allowselfsignedcert->isEnabled() && ui.checkBox_00_allowselfsignedcert->isChecked()) rtnstr.append("OpenConnect.AllowSelfSignedCert = %1").append(eqtrue);
         if (ui.checkBox_00_cookie->isChecked()) rtnstr.append("OpenConnect.Cookie = %1").append(eqtrue);
         if (ui.checkBox_00_disableipv6->isEnabled() && ui.checkBox_00_disableipv6->isChecked()) rtnstr.append("OpenConnect.DisableIPv6 = %1").append(eqtrue);
         if (ui.checkBox_00_disabledtls->isEnabled() && ui.checkBox_00_disabledtls->isChecked()) rtnstr.append("OpenConnect.NoDTLS = %1").append(eqtrue);
         if (ui.checkBox_00_nokeepalive->isEnabled() && ui.checkBox_00_nokeepalive->isChecked()) rtnstr.append("OpenConnect.NoHTTPKeepAlive = %1").append(eqtrue);
         rtnstr.append(QString("OpenConnect.AuthType = %1\n").arg(ui.comboBox_00_authtype->currentText()));
         if (ui.lineEdit_00_pkcsclientcert->isEnabled() && (! ui.lineEdit_00_pkcsclientcert->text().isEmpty())) rtnstr.append("OpenConnect.PKCSClientCert = ").append(ui.lineEdit_00_pkcsclientcert->text().append(newline));
         if (ui.lineEdit_00_usergroup->isEnabled() && (! ui.lineEdit_00_usergroup->text().isEmpty())) rtnstr.append("OpenConnect.Usergroup = ").append(ui.lineEdit_00_usergroup->text().append(newline));
         if (ui.lineEdit_00_clientcert->isEnabled() && (! ui.lineEdit_00_clientcert->text().isEmpty())) rtnstr.append("OpenConnect.ClientCert = ").append(ui.lineEdit_00_clientcert->text().append(newline));
         if (ui.lineEdit_00_userprivatekey->isEnabled() && (! ui.lineEdit_00_userprivatekey->text().isEmpty())) rtnstr.append("OpenConnect.UserPrivateKey = ").append(ui.lineEdit_00_userprivatekey->text().append(newline));
         break;
      case 1:
         if (! ui.lineEdit_01_cacert->text().isEmpty()) rtnstr.append("OpenVPN.CACert = ").append(ui.lineEdit_01_cacert->text().append(newline));
         if (! ui.lineEdit_01_cert->text().isEmpty()) rtnstr.append("OpenVPN.Cert = ").append(ui.lineEdit_01_cert->text().append(newline));
         if (! ui.lineEdit_01_key->text().isEmpty()) rtnstr.append("OpenVPN.Key = ").append(ui.lineEdit_01_key->text().append(newline));
         if (! ui.lineEdit_01_config->text().isEmpty()) rtnstr.append("OpenVPN.ConfigFile = ").append(ui.lineEdit_01_config->text().append(newline));
         if (! ui.lineEdit_01_authuserpass->text().isEmpty()) rtnstr.append("OpenVPN.AuthUserPass = ").append(ui.lineEdit_01_authuserpass->text().append(newline));
         if (! ui.lineEdit_01_askpass->text().isEmpty()) rtnstr.append("OpenVPN.AskPass = ").append(ui.lineEdit_01_askpass->text().append(newline));
         if (ui.checkBox_01_authnocache->isChecked()) rtnstr.append("OpenVPN.AuthNoCache").append(eqyes);
         if (ui.comboBox_01_proto->currentIndex() > 0) rtnstr.append(QString("OpenVPN.Proto = %1\n").arg(ui.comboBox_01_proto->currentText()));
         if (ui.spinBox_01_mtu->value() > 0) rtnstr.append(QString("OpenVPN.MTU = %1").arg(ui.spinBox_01_mtu->value()).append(newline));
         if (ui.comboBox_01_certtype->currentIndex() > 0) rtnstr.append(QString("OpenVPN.NSCertType = %1\n").arg(ui.comboBox_01_certtype->currentText()));
         if (ui.comboBox_01_devtype->currentIndex() > 0) rtnstr.append(QString("OpenVPN.DeviceType = %1\n").arg(ui.comboBox_01_devtype->currentText()));
         if (ui.spinBox_01_port->value() > 0) rtnstr.append(QString("OpenVPN.Port = %1").arg(ui.spinBox_01_port->value()).append(newline));
         if (ui.comboBox_01_cipher->currentIndex() > 0) rtnstr.append(QString("OpenVPN.Cipher = %1\n").arg(ui.comboBox_01_cipher->currentText()));
         if (ui.comboBox_01_complzo->currentIndex() > 0) rtnstr.append(QString("OpenVPN.CompLZO = %1\n").arg(ui.comboBox_01_complzo->currentText()));
         if (! ui.lineEdit_01_auth->text().isEmpty()) rtnstr.append("OpenVPN.Auth").append(ui.lineEdit_01_auth->text().append(newline));
         if (ui.comboBox_01_remotecerttls->currentIndex() > 0) rtnstr.append(QString("OpenVPN.RemoteCertTls = %1\n").arg(ui.comboBox_01_remotecerttls->currentText()));
         break;
      case 2:
         if (! ui.lineEdit_02_groupusername->text().isEmpty()) rtnstr.append("VPNC.IPSec.ID = ").append(ui.lineEdit_02_groupusername->text().append(newline));
         if (! ui.lineEdit_02_grouppassword->text().isEmpty()) rtnstr.append("VPNC.IPSec.Secret = ").append(ui.lineEdit_02_grouppassword->text().append(newline));
         if (! ui.lineEdit_02_username->text().isEmpty()) rtnstr.append("VPNC.Xauth.Username = ").append(ui.lineEdit_02_username->text().append(newline));
         if (! ui.lineEdit_02_password->text().isEmpty()) rtnstr.append("VPNC.Xauth.Password = ").append(ui.lineEdit_02_password->text().append(newline));
         if (! ui.lineEdit_02_applicationversion->text().isEmpty()) rtnstr.append("VPNC.AppVersion = ").append(ui.lineEdit_02_applicationversion->text().append(newline));
         if (! ui.lineEdit_02_domain->text().isEmpty()) rtnstr.append("VPNC.Domain = ").append(ui.lineEdit_02_domain->text().append(newline));
         rtnstr.append("VPNC.IKE.Authmode = ").append(ui.comboBox_02_ikeauthenticationmode->currentText().append(newline));
         rtnstr.append("VPNC.IKE.DHGroup = ").append(ui.comboBox_02_ikedhgroup->currentText().append(newline));
         rtnstr.append("VPNC.PFS = ").append(ui.comboBox_02_pfs->currentText().append(newline));
         rtnstr.append(QString("VPNC.LocalPort = %1").arg(ui.spinBox_02_localport->value()).append(newline));
         rtnstr.append(QString("VPNC.CiscoPort = %1").arg(ui.spinBox_02_udpport->value()).append(newline));
         rtnstr.append("VPNC.Vendor = ").append(ui.comboBox_02_vendor->currentText().append(newline));
         rtnstr.append("VPNC.NATTMode = ").append(ui.comboBox_02_nattmode->currentText().append(newline));
         rtnstr.append(QString("VPNC.DPDTimeout = %1").arg(ui.spinBox_02_dpdt->value()).append(newline));
         rtnstr.append("VPNC.DeviceType = ").append(ui.comboBox_02_interfacemode->currentText().append(newline));
         if (ui.checkBox_02_singledes->isChecked()) rtnstr.append("VPNC.SingleDES").append(eqyes);
         if (ui.checkBox_02_noencryption->isChecked()) rtnstr.append("VPNC.NoEncryption").append(eqyes);
         break;
      case 3:
         if (! ui.lineEdit_03_user->text().isEmpty()) rtnstr.append("L2TP.User = ").append(ui.lineEdit_03_user->text().append(newline));
         if (! ui.lineEdit_03_password->text().isEmpty()) rtnstr.append("L2TP.Password = ").append(ui.lineEdit_03_password->text().append(newline));
         if (ui.spinBox_03_bps->value() > 0) rtnstr.append(QString("L2TP.BPS = %1").arg(ui.spinBox_03_bps->value()).append(newline));
         if (ui.spinBox_03_txbps->value() > 0) rtnstr.append(QString("L2TP.TXBPS = %1").arg(ui.spinBox_03_txbps->value()).append(newline));
         if (ui.spinBox_03_rxbps->value() > 0) rtnstr.append(QString("L2TP.RXBPS = %1").arg(ui.spinBox_03_rxbps->value()).append(newline));
         if (ui.spinBox_03_tunnelrws->value() > 0) rtnstr.append(QString("L2TP.TunnelRWS = %1").arg(ui.spinBox_03_tunnelrws->value()).append(newline));
         if (! ui.lineEdit_03_defaultroute->text().isEmpty()) rtnstr.append("L2TP.DefaultRoute = ").append(ui.lineEdit_03_defaultroute->text().append(newline));
         if (! ui.lineEdit_03_listenaddress->text().isEmpty()) rtnstr.append("L2TP.ListenAddr = ").append(ui.lineEdit_03_listenaddress->text().append(newline));
         if (ui.spinBox_03_port->value() > 0) rtnstr.append(QString("L2TP.Port = %1").arg(ui.spinBox_03_port->value()).append(newline));
         if (ui.checkBox_03_requirepap->isChecked()) rtnstr.append("L2TP.RequirePAP").append(eqyes);
         if (ui.checkBox_03_requirechap->isChecked()) rtnstr.append("L2TP.RequireCHAP").append(eqyes);
         if (ui.checkBox_03_challenge->isChecked()) rtnstr.append("L2TP.Challenge").append(eqyes);
         if (ui.checkBox_03_requireauth->isChecked()) rtnstr.append("L2TP.ReqAuth").append(eqyes);
         if (ui.checkBox_03_redial->isChecked()) rtnstr.append("L2TP.Redial").append(eqyes);
         if (ui.checkBox_03_lengthbit->isChecked()) rtnstr.append("L2TP.LengthBit").append(eqyes);
         if (ui.checkBox_03_flowbit->isChecked()) rtnstr.append("L2TP.FlowBit").append(eqyes);
         if (ui.checkBox_03_accesscontrol->isChecked()) rtnstr.append("L2TP.AccessControl").append(eqyes);
         if (ui.checkBox_03_exclusive->isChecked()) rtnstr.append("L2TP.Exclusive").append(eqyes);
         if (ui.checkBox_03_ipsecsaref->isChecked()) rtnstr.append("L2TP.IPsecSaref").append(eqyes);
         if (ui.checkBox_03_redial->isChecked() && ui.spinBox_03_redialtimeout->value() > 0) rtnstr.append(QString("L2TP.RedialTimeout = %1").arg(ui.spinBox_03_redialtimeout->value()).append(newline));
         if (ui.checkBox_03_redial->isChecked() && ui.spinBox_03_maxredials->value() > 0) rtnstr.append(QString("L2TP.MaxRedials = %1").arg(ui.spinBox_03_maxredials->value()).append(newline));

         if (ui.checkBox_03_refuseeap->isChecked()) rtnstr.append("PPPD.RefuseEAP").append(eqyes);
         if (ui.checkBox_03_refusepap->isChecked()) rtnstr.append("PPPD.RefusePAP").append(eqyes);
         if (ui.checkBox_03_refusechap->isChecked()) rtnstr.append("PPPD.RefuseCHAP").append(eqyes);
         if (ui.checkBox_03_refusemschap->isChecked()) rtnstr.append("PPPD.RefuseMSCHAP").append(eqyes);
         if (ui.checkBox_03_refusemschap2->isChecked()) rtnstr.append("PPPD.RefuseMSCHAP2").append(eqyes);
         if (ui.checkBox_03_requiremppe->isChecked()) rtnstr.append("PPPD.ReqMPPE").append(eqyes);
         if (ui.checkBox_03_mppestateful->isChecked()) rtnstr.append("PPPD.ReqMPPEStateful").append(eqyes);
         if (ui.checkBox_03_debug->isChecked()) rtnstr.append("PPPD.Debug").append(eqyes);
         if (ui.checkBox_03_nobsdcomp->isChecked()) rtnstr.append("PPPD.NoBSDComp").append(eqyes);
         if (ui.checkBox_03_nodeflate->isChecked()) rtnstr.append("PPPD.NoDeflate").append(eqyes);
         if (ui.checkBox_03_nopcomp->isChecked()) rtnstr.append("PPPD.NoPcomp").append(eqyes);
         if (ui.checkBox_03_noaccomp->isChecked()) rtnstr.append("PPPD.UseAccomp").append(eqyes);
         if (ui.checkBox_03_novj->isChecked()) rtnstr.append("PPPD.NoVJ").append(eqyes);
         if (ui.checkBox_03_requiremppe40->isChecked()) rtnstr.append("PPPD.ReqMPPE40").append(eqyes);
         if (ui.checkBox_03_requiremppe128->isChecked()) rtnstr.append("PPPD.ReqMPPE128").append(eqyes);
         break;
      case 4:
         if (! ui.lineEdit_04_user->text().isEmpty()) rtnstr.append("PPTP.User = ").append(ui.lineEdit_04_user->text().append(newline));
         if (! ui.lineEdit_04_password->text().isEmpty()) rtnstr.append("PPTP.Password = ").append(ui.lineEdit_04_password->text().append(newline));
         if (ui.checkBox_04_refuseeap->isChecked()) rtnstr.append("PPPD.RefuseEAP").append(eqyes);
         if (ui.checkBox_04_refusepap->isChecked()) rtnstr.append("PPPD.RefusePAP").append(eqyes);
         if (ui.checkBox_04_refusechap->isChecked()) rtnstr.append("PPPD.RefuseCHAP").append(eqyes);
         if (ui.checkBox_04_refusemschap->isChecked()) rtnstr.append("PPPD.RefuseMSCHAP").append(eqyes);
         if (ui.checkBox_04_refusemschap2->isChecked()) rtnstr.append("PPPD.RefuseMSCHAP2").append(eqyes);
         if (ui.checkBox_04_requiremppe->isChecked()) rtnstr.append("PPPD.RequirMPPE").append(eqyes);
         if (ui.checkBox_04_mppestateful->isChecked()) rtnstr.append("PPPD.RequirMPPEStateful").append(eqyes);
         if (ui.checkBox_04_nobsdcomp->isChecked()) rtnstr.append("PPPD.NoBSDComp").append(eqyes);
         if (ui.checkBox_04_nodeflate->isChecked()) rtnstr.append("PPPD.NoDeflate").append(eqyes);
         if (ui.checkBox_04_novj->isChecked()) rtnstr.append("PPPD.NoVJ").append(eqyes);
         if (ui.checkBox_04_debug->isChecked()) rtnstr.append("PPPD.Debug").append(eqyes);
         if (ui.checkBox_04_requiremppe40->isChecked()) rtnstr.append("PPPD.RequirMPPE40").append(eqyes);
         if (ui.checkBox_04_requiremppe128->isChecked()) rtnstr.append("PPPD.RequirMPPE128").append(eqyes);
         if (ui.spinBox_04_echofailure->value() > 0) rtnstr.append(QString("PPPD.EchoFailure = %1").arg(ui.spinBox_04_echofailure->value()).append(newline));
         if (ui.spinBox_04_echointerval->value() > 0) rtnstr.append(QString("PPPD.EchoInterval = %1").arg(ui.spinBox_04_echointerval->value()).append(newline));
         break;
      case 5:
         rtnstr.append("WireGuard.Address = ").append(ui.lineEdit_05_address->text().append(newline));
         if (ui.spinBox_05_listport->value() > 0) rtnstr.append(QString("WireGuard.ListPort = %1").arg(ui.spinBox_05_listport->value()).append(newline));
         if (! ui.lineEdit_05_dns->text().isEmpty()) rtnstr.append("WireGuard.DNS = ").append(ui.lineEdit_05_dns->text().append(newline));
         rtnstr.append("WireGuard.PrivateKey = ").append(ui.lineEdit_05_privatekey->text().append(newline));
         rtnstr.append("WireGuard.PublicKey = ").append(ui.lineEdit_05_publickey->text().append(newline));
         if (! ui.lineEdit_05_presharedkey->text().isEmpty()) rtnstr.append("WireGuard.PresharedKey = ").append(ui.lineEdit_05_presharedkey->text().append(newline));
         rtnstr.append("WireGuard.AllowedIPs = ").append(ui.lineEdit_05_allowedips->text().append(newline));
         if (ui.spinBox_05_endpointport->value() > 0) rtnstr.append(QString("WireGuard.EndpointPort = %1").arg(ui.spinBox_05_endpointport->value()).append(newline));
         if (ui.spinBox_05_keepalive->value() > 9) rtnstr.append(QString("WireGuard.PersistentKeepalive = %1").arg(ui.spinBox_05_keepalive->value()).append(newline));
         break;
      default:
         break;
   }

   // request a list of config files from roothelper
   QList<QVariant> vlist;
   vlist << QVariant::fromValue(QString(VPN_PATH));
   QDBusMessage reply = iface_rh1->callWithArgumentList(QDBus::AutoDetect, QLatin1String("getFileList"), vlist);
   if (shared::processReply(reply) != QDBusMessage::ReplyMessage) return;

   QStringList sl_conf = reply.arguments().at(0).toStringList();
   QString filename = QString();
   qid->setLabelText(tr("Enter a new file name or select<br>an existing file to overwrite.") );
   qid->setComboBoxEditable(true);
   qid->setComboBoxItems(sl_conf);
   qid->exec();
   if (qid->result() == QDialog::Accepted) {
      filename = qid->textValue();
      filename = filename.simplified();      // multiple whitespace to one space
      filename = filename.replace(' ', '_'); // replace spaces with underscores
   } // if accepted
   else return;

   // if we have a filename try to save the file
   if (! filename.isEmpty() ) {
      vlist.clear();
      vlist<< QVariant::fromValue(QString(VPN_PATH));
      vlist << QVariant::fromValue(filename);
      vlist << QVariant::fromValue(rtnstr);
      shared::processReply(iface_rh1->callWithArgumentList(QDBus::AutoDetect, QLatin1String("saveFile"), vlist));
   } // if there is a file name

   return;
}

//
// Slot called when a lineEdit emits the textChanged() signal
// Used to enable the OK button if the input passes basic validation checks.
// Pass means the input is sufficient to provision a service.  Does not mean
// it is without error or complete, but it meets the minimum requirements.
void VPN_Create::checkInput()
{
   if (
      (! ui.lineEdit_name->text().isEmpty())                                                                                              &&
      ui.lineEdit_host->hasAcceptableInput()                                                                                              &&
      (ui.lineEdit_domain->text().isEmpty() || ui.lineEdit_domain->hasAcceptableInput())                                                  &&
      (ui.lineEdit_networks->text().isEmpty() || ui.lineEdit_networks->hasAcceptableInput())                                              &&
      (ui.comboBox_type->currentIndex() != 0 || ui.lineEdit_00_vpnhost->text().isEmpty() || ui.lineEdit_00_vpnhost->hasAcceptableInput()) &&
      (ui.comboBox_type->currentIndex() != 2 || ! ui.lineEdit_02_groupusername->text().isEmpty())                                         &&
      (ui.comboBox_type->currentIndex() != 5 || ui.lineEdit_05_address->hasAcceptableInput())                                             &&
      (ui.comboBox_type->currentIndex() != 5 || ui.lineEdit_05_dns->text().isEmpty() || ui.lineEdit_05_dns->hasAcceptableInput())         &&
      (ui.comboBox_type->currentIndex() != 5 || ! ui.lineEdit_05_privatekey->text().isEmpty())                                            &&
      (ui.comboBox_type->currentIndex() != 5 || ! ui.lineEdit_05_publickey->text().isEmpty())                                             &&
      (ui.comboBox_type->currentIndex() != 5 || ui.lineEdit_05_allowedips->hasAcceptableInput())
      )
      ui.buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
   else
      ui.buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);

    return;
}

//
// Slot called when the QActionGroup qag issues a triggered action
void VPN_Create::processAction(QAction* act)
{
   QString filterstring = tr("All Files (*.*)");
   QDir target_dir(QDir::homePath());

   if (act == action_00_cacert) {
      filterstring = tr("Cert Files (*.ca *.cert *.crt *.pem);;All Files (*.*)");
      ui.lineEdit_00_cacert->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));
      }

   if (act == action_00_clientcert) {
      filterstring = tr("Cert Files (*.ca *.cert *.crt *.pem);;All Files (*.*)");
      ui.lineEdit_00_clientcert->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));
      }

   if (act == action_00_pkcsclientcert) {
      filterstring = tr("Cert Files (*.ca *.cert *.crt *.pem);;All Files (*.*)");
      ui.lineEdit_00_pkcsclientcert->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));
      }

   if (act == action_01_cacert) {
      filterstring = tr("Cert Files (*.ca *.cert *.crt *.pem);;All Files (*.*)");
      ui.lineEdit_00_cacert->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));
      }

   if (act == action_01_cert) {
      filterstring = tr("Cert Files (*.ca *.cert *.crt *.pem);;All Files (*.*)");
      ui.lineEdit_01_cert->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));
      }

   if (act == action_01_key) {
      filterstring = tr("Key Files (*.key *.ca *.cert *.crt *.pem);;All Files (*.*)");
      ui.lineEdit_01_key->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));
      }

   if (act == action_01_config) {
      target_dir.setPath(QString(datahome + "/openvpn"));
      if (! target_dir.exists()) target_dir.mkpath(target_dir.absolutePath() );
      filterstring = tr("Config files (*.conf);;All Files (*.*)");
      ui.lineEdit_01_config->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));
      }

   if (act == action_01_authuserpass) {
      target_dir.setPath(QString(datahome + "/openvpn/userpass"));
      if (! target_dir.exists()) target_dir.mkpath(target_dir.absolutePath() );
      filterstring = tr("User/Pass Files (*.up)");
      ui.lineEdit_01_authuserpass->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));
      }

   if (act == action_01_askpass) {
      ui.lineEdit_01_askpass->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));
      }

   if (act == action_03_authfile)
      ui.lineEdit_03_authfile->setText(QFileDialog::getOpenFileName(this, act->toolTip(), target_dir.absolutePath(), filterstring));

   return;
}

//
// Slot to enter whats this mode
// Called when the ui.toolButton_whatsthis clicked() signal is emitted
void VPN_Create::showWhatsThis()
{
   QWhatsThis::enterWhatsThisMode();
}

//
// Slot to enable and disable OpenConnect options when authentication type changes
// Called when ui.comboBox_00_authtype emits a currentIndexChanged(int) signal
void VPN_Create::openConnectAuthTypeChanged(const int& idx)
{
   ui.lineEdit_00_pkcsclientcert->setDisabled(idx != 4);
   ui.lineEdit_00_clientcert->setDisabled(idx != 3);
   ui.lineEdit_00_userprivatekey->setDisabled(idx != 3);

   return;
}

// Slot to import an OpenVPN configuration file
// Called when ui.pushButton_01_importopvn is pressed
void VPN_Create::importOpenVPN()
{
   // To start things off we need some input from the user
   QString fname = QFileDialog::getOpenFileName(this, tr("Select the configuration file to import"),
                                QDir::homePath(),
                                QString(tr("OpenVPN Configurations (*.ovpn  *.conf);;All Files (*.*)"))
                                );
   if (fname.isEmpty() ) return;

   // Read the source file
   QFile sourcefile(fname);
   if (sourcefile.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QString contents = QString(sourcefile.readAll());
      sourcefile.close();

      // Get the base name where we are going to store the .conf file created from the .opvn file
      bool ok = false;
      QFileInfo fi(fname); // need for a default in the QInputDialog
      QString basename = QInputDialog::getText(this, tr("Base Name"),
         tr("Please enter a name for the connection to be created from the imported .opvn file"),
         QLineEdit::Normal,
         fi.baseName(),
         &ok);
      if (! ok) return;

      // Setup the data directories
      QDir target_dir = QDir(QString(datahome + "/openvpn/" + basename));
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
               QMessageBox::Yes) == QMessageBox::Yes) {

            // Remove auth-user-pass from conf file
            contents.remove("auth-user-pass\n");

            // Check to see if a user:pass file needs to be created.
            if (QMessageBox::question (this,
                  tr("Create User:Password File"),
                  tr("Do you wish to create a user:password file for this connection?"),
                  QMessageBox::Yes | QMessageBox::No,
                  QMessageBox::Yes) == QMessageBox::Yes) {
               this->createUserPass(basename);
            } // if want to creat user/pass file
         } // if we want to delete the auth-user-pass entry
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
            ui.lineEdit_01_config->setText(outfile.fileName() );
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

   } // if we could read the source file

   else {
      QMessageBox::critical(this, QString("%1 - Critical").arg(TranslateStrings::cmtr("cmst")),
         tr("Unable to read <b>%1</b> - Aborting the import").arg(sourcefile.fileName() ),
         QMessageBox::Ok,
         QMessageBox::Ok);
      return;
   } // else sourcefile failed to open

   // Print a done message
   QMessageBox::information(this, QString("%1 - Information").arg(TranslateStrings::cmtr("cmst")),
      tr("OpenVPN import is complete."),
      QMessageBox::Ok,
      QMessageBox::Ok);


   return;
}

//
// Slot to create a user/password file which can be used by OpenVPN.AuthUserPass
// Called when ui.pushButton_01_createuserpass is pressed
// and from the importOpenVPN() function
void VPN_Create::createUserPass(QString basename)
{
   // Data members
   bool ok = false;
   ui.lineEdit_01_authuserpass->clear();

   // Get the base  name if none was provided
   if (basename.isEmpty()) {
      basename = QInputDialog::getText(this, tr("Base Name"),
         tr("Please enter a name for the user/pass file"),
         QLineEdit::Normal,
         QString(),
         &ok);
      if (! ok) return;
   } // if

   // Get the user name
   QString user = QInputDialog::getText(this, tr("User"),
      tr("Enter the user name for this connection."),
      QLineEdit::Normal,
      QString(),
      &ok);
   if (! ok) return;

   // Get the password
   QString pass = QInputDialog::getText(this, tr("Password"),
      tr("Enter the password for this connection."),
      QLineEdit::Normal,
      QString(),
      &ok);
   if (! ok) return;

   // Make sure the user/pass directory exists
   QDir target_dir = QDir(QString(datahome + "/openvpn/userpass"));
   if (! target_dir.exists()) target_dir.mkpath(target_dir.absolutePath() );

   // Write the user/pass file
   QFile outfile(QString(target_dir.absolutePath() + "/%1%2")
      .arg(basename)
      .arg(".up") );

   if (outfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QTextStream outstream(&outfile);
      outstream << user << "\n" << pass << "\n";
      outfile.close();
      ui.lineEdit_01_authuserpass->setText(outfile.fileName());
   } // if outfile (up) could be opened for writing

   else {
      QMessageBox::warning(this, QString("%1 - Warning").arg(TranslateStrings::cmtr("cmst")),
         tr("Unable to write user:password file <b>%1</b>").arg(outfile.fileName() ),
         QMessageBox::Ok,
         QMessageBox::Ok);
   } // else outfile (up) failed to open

return;
}

