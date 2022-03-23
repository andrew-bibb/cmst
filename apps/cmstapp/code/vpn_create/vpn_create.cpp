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

   // Set OK button to disable
   ui.buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);

   // Assign validators to input boxes
   QRegularExpressionValidator* qrex_46cidr= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_46cidr, false)), this);
      ui.lineEdit_host->setValidator(qrex_46cidr);

   QRegularExpressionValidator* qrex_46cidrp= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_46cidr, true)), this);
      ui.lineEdit_05_dns->setValidator(qrex_46cidrp);
      ui.lineEdit_05_allowedips->setValidator(qrex_46cidrp);

   QRegularExpressionValidator* qrex_dom= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_Dom, false)), this);
      ui.lineEdit_domain->setValidator(qrex_dom);

   QRegularExpressionValidator* qrex_networks= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_networks, true)), this);
      ui.lineEdit_networks->setValidator(qrex_networks);
      ui.lineEdit_05_address->setValidator(qrex_networks);

   // disable newer features if Connman does not support them
   if (ver <= 1.37f) {
      ui.stackedWidget->widget(5)->setDisabled(true); // no wireguard
   } // if

   // QActionGroup and QActions
   qag = new QActionGroup(this);
   action_03_authfile = new QAction(fileicon, "Authority File", qag);
   action_03_authfile->setToolTip(tr("Select the L2TP Authority file"));
   ui.lineEdit_03_authfile->addAction(action_03_authfile, QLineEdit::TrailingPosition);



   // Connect signals and slots
   connect (ui.lineEdit_name, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_host, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_domain, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_networks, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_02_groupusername, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_address, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_dns, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_privatekey, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_publickey, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_05_allowedips, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (this, SIGNAL(accepted()), this, SLOT(createFile()));
   connect (qag, SIGNAL(triggered(QAction*)), this, SLOT(processAction(QAction*)));
   connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));

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
         qDebug() << "OpenConnect";
         break;
      case 1:
         qDebug() << "OpenVPN";
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
         qDebug() << "L2TP";
         break;
      case 4:
         if (! ui.lineEdit_04_user->text().isEmpty()) rtnstr.append("PPTP.User = ").append(ui.lineEdit_04_user->text().append(newline));
         if (! ui.lineEdit_04_password->text().isEmpty()) rtnstr.append("PPTP.Password = ").append(ui.lineEdit_04_password->text().append(newline));
         if (ui.checkBox_04_debug->isChecked()) rtnstr.append("PPPD.Debug").append(eqyes);
         if (ui.checkBox_04_refuseeap->isChecked()) rtnstr.append("PPPD.RefuseEAP").append(eqyes);
         if (ui.checkBox_04_refusepap->isChecked()) rtnstr.append("PPPD.RefusePAP").append(eqyes);
         if (ui.checkBox_04_refusechap->isChecked()) rtnstr.append("PPPD.RefuseCHAP").append(eqyes);
         if (ui.checkBox_04_refusemschap->isChecked()) rtnstr.append("PPPD.RefuseMSCHAP").append(eqyes);
         if (ui.checkBox_04_refusemschap2->isChecked()) rtnstr.append("PPPD.RefuseMSCHAP2").append(eqyes);
         if (ui.checkBox_04_nobsdcomp->isChecked()) rtnstr.append("PPPD.NoBSDComp").append(eqyes);
         if (ui.checkBox_04_nodeflate->isChecked()) rtnstr.append("PPPD.NoDeflate").append(eqyes);
         if (ui.checkBox_04_novj->isChecked()) rtnstr.append("PPPD.NoVJ").append(eqyes);
         if (ui.checkBox_04_requiremppe->isChecked()) rtnstr.append("PPPD.RequirMPPE").append(eqyes);
         if (ui.checkBox_04_requiremppe40->isChecked()) rtnstr.append("PPPD.RequirMPPE40").append(eqyes);
         if (ui.checkBox_04_requiremppe128->isChecked()) rtnstr.append("PPPD.RequirMPPE128").append(eqyes);
         if (ui.checkBox_04_mppestateful->isChecked()) rtnstr.append("PPPD.RequirMPPEStateful").append(eqyes);
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
      (! ui.lineEdit_name->text().isEmpty())                                                                                        &&
      ui.lineEdit_host->hasAcceptableInput()                                                                                        &&
      (ui.lineEdit_domain->text().isEmpty() || ui.lineEdit_domain->hasAcceptableInput())                                            &&
      (ui.lineEdit_networks->text().isEmpty() || ui.lineEdit_networks->hasAcceptableInput())                                        &&
      (ui.comboBox_type->currentIndex() != 2 || ! ui.lineEdit_02_groupusername->text().isEmpty())                                   &&
      (ui.comboBox_type->currentIndex() != 5 || ui.lineEdit_05_address->hasAcceptableInput())                                       &&
      (ui.comboBox_type->currentIndex() != 5 || ui.lineEdit_05_dns->text().isEmpty() || ui.lineEdit_05_dns->hasAcceptableInput())   &&
      (ui.comboBox_type->currentIndex() != 5 || ! ui.lineEdit_05_privatekey->text().isEmpty())                                      &&
      (ui.comboBox_type->currentIndex() != 5 || ! ui.lineEdit_05_publickey->text().isEmpty())                                       &&
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
   QString filepath = QDir::homePath();

   if (act == action_03_authfile) ui.lineEdit_03_authfile->setText(QFileDialog::getOpenFileName(this, act->toolTip(), filepath, filterstring));

   return;
}

//
// Slot to enter whats this mode
// Called when the ui.toolButton_whatsthis clicked() signal is emitted
void VPN_Create::showWhatsThis()
{
   QWhatsThis::enterWhatsThisMode();
}


