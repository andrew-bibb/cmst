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

# include <QtCore/QDebug>
# include <QRegularExpression>
# include <QRegularExpressionValidator>

# include "./code/vpn_create/vpn_create.h"
# include "./code/shared/shared.h"
# include "../resource.h"


// # define VPN_PATH "/var/lib/connman-vpn"

//
// Constructor
VPN_Create::VPN_Create(QWidget* parent, const float& ver) : QDialog(parent)
{
   // Setup the user interface
   ui.setupUi(this);

   // Set OK button to disable
   ui.buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);

   // Assign validators to input boxes
   QRegularExpressionValidator* qrex_46cidr= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_46cidr, false)), this);
      ui.lineEdit_host->setValidator(qrex_46cidr);

   QRegularExpressionValidator* qrex_networks= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_networks, true)), this);
      ui.lineEdit_networks->setValidator(qrex_networks);

   // Connect signals and slots
   connect (ui.lineEdit_name, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_host, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_domain, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (ui.lineEdit_networks, SIGNAL(textChanged(const QString&)), this, SLOT(checkInput()));
   connect (this, SIGNAL(accepted()), this, SLOT(writeFile()));
   connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));

   // set index to something we're working on
   ui.comboBox_type->setCurrentIndex(4);

   return;
}


//////////////////////////////////////////////// Private Slots /////////////////////////////////////////
//
// Slot called when a lineEdit emits the textChanged() signal
// Used to enable the OK button if the input passes basic validation checks.
// Pass means the input is sufficient to provision a service.  Does not mean
// it is without error or complete, but it meets the minimum requirements.
void VPN_Create::checkInput()
{
   if (
      (! ui.lineEdit_name->text().isEmpty())           &&
      ui.lineEdit_host->hasAcceptableInput()           &&
      (ui.lineEdit_networks->text().isEmpty() || ui.lineEdit_networks->hasAcceptableInput())
      )
      ui.buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
   else
      ui.buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);

    return;
 }

//
// Slot called when this emits an accepted() signal (user clicks OK).
// Write the provisioning file
void VPN_Create::writeFile()
{
   // data members
   const QString newline(QString("\n"));
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
   switch (ui.comboBox_type->currentIndex() )
   {
      case 0:
         qDebug() << "OpenConnect";
         break;
      case 1:
         qDebug() << "OpenVPN";
         break;
      case 2:
         qDebug() << "VPNC";
         break;
      case 3:
         qDebug() << "L2TP";
         break;
      case 4:
         qDebug() << "PPTP";
         break;
      case 5:
         qDebug() << "WireGuard";
         break;
      default:
         break;
   }


   qDebug() << rtnstr;


   return;
}

//
// Slot to enter whats this mode
// Called when the ui.toolButton_whatsthis clicked() signal is emitted
void VPN_Create::showWhatsThis()
{
   QWhatsThis::enterWhatsThisMode();
}
