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

# include "./code/provisioning/prov_ed.h"

#define DBUS_SERVICE "net.connman"

ProvisioningEditor::ProvisioningEditor(QWidget* parent)
    : QDialog(parent)
{
  // Setup the user interface
  ui.setupUi(this);
  
  //
  ui.toolBox_prov_ed->setItemEnabled(2, ui.comboBox_type->currentText().contains("wifi", Qt::CaseInsensitive));

  //// Data members
  //objpath = ae.objpath;
  //objmap = ae.objmap;

  //// Setup the address validator and apply it to any ui QLineEdit.
  //// The lev validator will validate an IP address or up to one white space character (to allow
  //// editing of the line edit).
  //QString s_ip4 = "(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])";
  //QString s_ip6 = "(?:[0-9a-fA-F]{1,4})";

  //// QLineEdits that allow single address
  //QRegularExpression rx4("\\s?|^" + s_ip4 + "(?:\\." + s_ip4 + "){3}" + "$");
  //QRegularExpression rx6("\\s?|^" + s_ip6 + "(?::" + s_ip6 + "){7}" + "$");
  //QRegularExpressionValidator* lev_4 = new QRegularExpressionValidator(rx4, this);
  //QRegularExpressionValidator* lev_6 = new QRegularExpressionValidator(rx6, this);
  //ui.lineEdit_ipv4address->setValidator(lev_4);
  //ui.lineEdit_ipv4netmask->setValidator(lev_4);
  //ui.lineEdit_ipv4gateway->setValidator(lev_4);
  //ui.lineEdit_ipv6address->setValidator(lev_6);
  //ui.lineEdit_ipv6gateway->setValidator(lev_6);

  //// now QLineEdits that allow multiple addresses
  //QRegularExpression rx46("\\s?|((" + s_ip4 + "(?:\\." + s_ip4 + "){3}|" + s_ip6 + "(?::" + s_ip6 + "){7})(\\s*[,|;|\\s]\\s*))+");
  //QRegularExpressionValidator* lev_m = new QRegularExpressionValidator(rx46, this);
  //ui.lineEdit_nameservers->setValidator(lev_m);
  //ui.lineEdit_timeservers->setValidator(lev_m);
  //ui.lineEdit_domains->setValidator(lev_m);

  //// initialize and populate submaps
  //ipv4map.clear();
  //ipv6map.clear();
  //proxmap.clear();
  //extractMapData(ipv4map, objmap.value("IPv4.Configuration") );
  //extractMapData(ipv6map, objmap.value("IPv6.Configuration") );
  //extractMapData(proxmap, objmap.value("Proxy.Configuration") );

  //// Seed initial values in the dialog.
  //ui.checkBox_autoconnect->setChecked(objmap.value("AutoConnect").toBool() );
  //ui.lineEdit_nameservers->setText(objmap.value("Nameservers.Configuration").toStringList().join("\n") );
  //ui.lineEdit_timeservers->setText(objmap.value("Timeservers.Configuration").toStringList().join("\n"));
  //ui.lineEdit_domains->setText(objmap.value("Domains.Configuration").toStringList().join("\n"));

  //// ipv4 page
  //if (! ipv4map.value("Method").toString().isEmpty() ) {
    //ui.comboBox_ipv4method->setCurrentIndex(ui.comboBox_ipv4method->findText(ipv4map.value("Method").toString(), Qt::MatchFixedString) );
  //}
  //ui.lineEdit_ipv4address->setText(ipv4map.value("Address").toString() );
  //ui.lineEdit_ipv4netmask->setText(ipv4map.value("Netmask").toString() );
  //ui.lineEdit_ipv4gateway->setText(ipv4map.value("Gateway").toString() );

  //// ipv6 page
  //if (! ipv6map.value("Method").toString().isEmpty() ) {
    //ui.comboBox_ipv6method->setCurrentIndex(ui.comboBox_ipv6method->findText(ipv6map.value("Method").toString(), Qt::MatchFixedString) );
  //}
  //ui.spinBox_ipv6prefixlength->setValue(ipv6map.value("PrefixLength").toUInt() );
  //ui.lineEdit_ipv6address->setText(ipv6map.value("Address").toString() );
  //ui.lineEdit_ipv6gateway->setText(ipv6map.value("Gateway").toString() );
  //if (! ipv6map.value("Privacy").toString().isEmpty() ) {
    //ui.comboBox_ipv6privacy->setCurrentIndex(ui.comboBox_ipv6privacy->findText(ipv6map.value("Privacy").toString(), Qt::MatchFixedString) );
  //}

  //// proxy page
  //if (! proxmap.value("Method").toString().isEmpty() ) {
    //ui.comboBox_proxymethod->setCurrentIndex(ui.comboBox_proxymethod->findText(proxmap.value("Method").toString(), Qt::MatchFixedString) );
  //}
  //ui.lineEdit_proxyservers->setText(proxmap.value("Servers").toStringList().join("\n") );
  //ui.lineEdit_proxyexcludes->setText(proxmap.value("Excludes").toStringList().join("\n") );
  //ui.lineEdit_proxyurl->setText(proxmap.value("URL").toString() );


  // connect signals to slots
  connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));
  connect(ui.pushButton_resetpage, SIGNAL(clicked()), this, SLOT(resetPage()));
  connect(ui.pushButton_resetall, SIGNAL(clicked()), this, SLOT(resetAll()));
  connect(ui.comboBox_type, SIGNAL(currentTextChanged(const QString&)), this, SLOT(serviceTypeChanged(const QString&)));
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
void ProvisioningEditor::resetPage(int page)
{
  // find the page (index) to clear.
  int toolboxindex = ui.toolBox_prov_ed->currentIndex();
  if (page >= 0 ) toolboxindex = page;

  switch (toolboxindex) {
    case 0:
			ui.lineEdit_name->clear();
      ui.plainTextEdit_description->clear();
      break;
    case 1:
			ui.comboBox_type->setCurrentIndex(0);
			ui.comboBox_ipv4method->setCurrentIndex(0);
			ui.lineEdit_ipv4address->clear();
			ui.lineEdit_ipv4netmask->clear();
			ui.lineEdit_ipv4gateway->clear();
			ui.comboBox_ipv6method->setCurrentIndex(0);
			ui.spinBox_ipv6prefixlength->setValue(0);
      ui.lineEdit_ipv6address->clear();
      ui.lineEdit_ipv6gateway->clear();
      ui.comboBox_ipv6privacy->setCurrentIndex(0);
      ui.lineEdit_macaddress->clear();
      ui.lineEdit_domain->clear();
      ui.lineEdit_nameservers->clear();
      ui.lineEdit_timeservers->clear();
      ui.lineEdit_searchdomains->clear();
      break;
    case 2:
			ui.lineEdit_wifiname->clear();
			ui.lineEdit_wifissid->clear();
			ui.checkBox_wifihidden->setChecked(false);		
			ui.comboBox_eaptype->setCurrentIndex(0);
			ui.lineEdit_eaptype->clear();
			ui.lineEdit_cacertfile->clear();
			ui.lineEdit_clientcertfile->clear();
			ui.lineEdit_privatekeyfile->clear();
			ui.lineEdit_privatekeypassphrase->clear();
			ui.comboBox_privatekeypassphrasetype->setCurrentIndex(0);
			ui.comboBox_securitytype->setCurrentIndex(0);
			ui.lineEdit_passphrase->clear();
			ui.lineEdit_phase2->clear();
      break;
    default:
      break;
  } // switch

  return;
}

//
// Slot to reset all pages.  Called when ui.pushButton_resetall
// is clicked().
void ProvisioningEditor::resetAll()
{
  for (int i = 0; i < ui.toolBox_prov_ed->count(); ++i) {
    this->resetPage(i);
  }

  return;
}

//
// Slot to determine if the Wifi toolbox page is enabled or not
// Called when ui.comboBox_type is changed
void ProvisioningEditor::serviceTypeChanged(const QString& type)
{
	ui.toolBox_prov_ed->setItemEnabled(2, type.contains("wifi", Qt::CaseInsensitive));
		
	return;	
}

