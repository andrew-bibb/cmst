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

   // Assign validators to input boxes
   QRegularExpressionValidator* qrex_46cidr= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_46cidr, false)), this);
      ui.lineEdit_host->setValidator(qrex_46cidr);

   QRegularExpressionValidator* qrex_networks= new QRegularExpressionValidator(QRegularExpression(shared::ValidatingDialog(this).getPattern(CMST::ValDialog_networks, true)), this);
      ui.lineEdit_networks->setValidator(qrex_networks);


   return;
}


