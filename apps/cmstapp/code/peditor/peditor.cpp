/****************** peditor.cpp ***********************************

Code to manage the Properties Editor dialog.

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

# include "./peditor.h"
# include "./code/shared/shared.h"
# include "./code/trstring/tr_strings.h"

#define DBUS_SERVICE "net.connman"

PropertiesEditor::PropertiesEditor(QWidget* parent, const arrayElement& ae)
    : QDialog(parent)
{
  // Setup the user interface
  ui.setupUi(this);

  // Data members
  objpath = ae.objpath;
  objmap = ae.objmap;
  sl_ipv4_method << "dhcp" << "manual" << "off"; 
	sl_ipv6_method << "auto" << "manual" << "off";
	sl_ipv6_privacy << "disabled" << "enabled" << "prefered";	// misspelling prefered is necessary
	sl_proxy_method << "direct" << "auto" << "manual";
	
	// Setup comboboxes
	ui.comboBox_ipv4method->addItems(TranslateStrings::cmtr_sl(sl_ipv4_method) );
	ui.comboBox_ipv6method->addItems(TranslateStrings::cmtr_sl(sl_ipv6_method) );
	ui.comboBox_ipv6privacy->addItems(TranslateStrings::cmtr_sl(sl_ipv6_privacy) );
	ui.comboBox_proxymethod->addItems(TranslateStrings::cmtr_sl(sl_proxy_method) );

  // Setup the address validator and apply it to any ui QLineEdit.
  // The lev validator will validate an IP address or up to one white space character (to allow
  // editing of the line edit).
  const QString s_ip4 = "(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])";
  const QString s_ip6 = "(?:[0-9a-fA-F]{1,4})";
  const QString s_dom = "((?!-)[A-Za-z0-9-]{1,63}(?<!-)\\.)+[A-Za-z]{2,6}";

  // QLineEdits that allow single address
  QRegularExpression rx4("\\s?|^" + s_ip4 + "(?:\\." + s_ip4 + "){3}" + "$");
  QRegularExpression rx6("\\s?|^" + s_ip6 + "(?::" + s_ip6 + "){7}" + "$");
  QRegularExpressionValidator* lev_4 = new QRegularExpressionValidator(rx4, this);
  QRegularExpressionValidator* lev_6 = new QRegularExpressionValidator(rx6, this);
  ui.lineEdit_ipv4address->setValidator(lev_4);
  ui.lineEdit_ipv4netmask->setValidator(lev_4);
  ui.lineEdit_ipv4gateway->setValidator(lev_4);
  ui.lineEdit_ipv6address->setValidator(lev_6);
  ui.lineEdit_ipv6gateway->setValidator(lev_6);

  // now QLineEdits that allow multiple addresses
  QRegularExpression rx46d("\\s?|((" + s_ip4 + "(?:\\." + s_ip4 + "){3}|"+ s_ip6 + "(?::" + s_ip6 + "){7}|" + s_dom + ")(\\s*[,|;|\\s]\\s*))+");
  QRegularExpressionValidator* lev_m = new QRegularExpressionValidator(rx46d, this);
  ui.lineEdit_nameservers->setValidator(lev_m);
  ui.lineEdit_timeservers->setValidator(lev_m);

  // initialize and populate submaps
  ipv4map.clear();
  ipv6map.clear();
  proxmap.clear();
  shared::extractMapData(ipv4map, objmap.value("IPv4.Configuration") );
  shared::extractMapData(ipv6map, objmap.value("IPv6.Configuration") );
  shared::extractMapData(proxmap, objmap.value("Proxy.Configuration") );

  // Seed initial values in the dialog.
  ui.checkBox_autoconnect->setChecked(objmap.value("AutoConnect").toBool() );
  ui.lineEdit_nameservers->setText(objmap.value("Nameservers.Configuration").toStringList().join("\n") );
  ui.lineEdit_timeservers->setText(objmap.value("Timeservers.Configuration").toStringList().join("\n"));
  ui.lineEdit_domains->setText(objmap.value("Domains.Configuration").toStringList().join("\n"));

  // ipv4 page
  if (! ipv4map.value("Method").toString().isEmpty() ) {
    ui.comboBox_ipv4method->setCurrentIndex(sl_ipv4_method.indexOf(QRegExp(ipv4map.value("Method").toString())) );
  }
  ui.lineEdit_ipv4address->setText(ipv4map.value("Address").toString() );
  ui.lineEdit_ipv4netmask->setText(ipv4map.value("Netmask").toString() );
  ui.lineEdit_ipv4gateway->setText(ipv4map.value("Gateway").toString() );

  // ipv6 page
  if (! ipv6map.value("Method").toString().isEmpty() ) {
    ui.comboBox_ipv6method->setCurrentIndex(sl_ipv6_method.indexOf(QRegularExpression(ipv6map.value("Method").toString())) );
  }
  ui.spinBox_ipv6prefixlength->setValue(ipv6map.value("PrefixLength").toUInt() );
  ui.lineEdit_ipv6address->setText(ipv6map.value("Address").toString() );
  ui.lineEdit_ipv6gateway->setText(ipv6map.value("Gateway").toString() );
  if (! ipv6map.value("Privacy").toString().isEmpty() ) {	
		ui.comboBox_ipv6privacy->setCurrentIndex(sl_ipv6_privacy.indexOf(QRegularExpression(ipv6map.value("Privacy").toString())) );
  }

  // proxy page
  if (! proxmap.value("Method").toString().isEmpty() ) {
    ui.comboBox_proxymethod->setCurrentIndex(sl_proxy_method.indexOf(QRegularExpression(proxmap.value("Method").toString())) );
  }
  ui.lineEdit_proxyservers->setText(proxmap.value("Servers").toStringList().join("\n") );
  ui.lineEdit_proxyexcludes->setText(proxmap.value("Excludes").toStringList().join("\n") );
  ui.lineEdit_proxyurl->setText(proxmap.value("URL").toString() );


  // connect signals to slots
  connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));
  connect(ui.pushButton_resetpage, SIGNAL(clicked()), this, SLOT(resetPage()));
  connect(ui.pushButton_resetall, SIGNAL(clicked()), this, SLOT(resetAll()));
  connect(ui.pushButton_ok, SIGNAL(clicked()), this, SLOT(updateConfiguration()));

}

///////////////////////////////////////////////// Private Slots /////////////////////////////////////////////
//
//  Slot to enter whats this mode
//  Called when the ui.toolButton_whatsthis clicked() signal is emitted
void PropertiesEditor::showWhatsThis()
{
  QWhatsThis::enterWhatsThisMode();
}

//
// Function to clear the contents of the specified page.  If the page
// argument is less than one (default value is -1) then clear the
// current toolbox page. Called when ui.pushButton_resetpage is clicked()
void PropertiesEditor::resetPage(int page)
{
  // find the page (index) to clear.
  int toolboxindex = ui.toolBox_peditor->currentIndex();
  if (page >= 0 ) toolboxindex = page;

  switch (toolboxindex) {
    case 0:
      ui.checkBox_autoconnect->setChecked(objmap.value("AutoConnect").toBool() );
      break;
    case 1:
      ui.lineEdit_nameservers->clear();
      break;
    case 2:
      ui.lineEdit_timeservers->clear();
      break;
    case 3:
      ui.lineEdit_domains->clear();
      break;
    case 4:
      ui.comboBox_ipv4method->setCurrentIndex(0);
      ui.lineEdit_ipv4address->clear();
      ui.lineEdit_ipv4netmask->clear();
      ui.lineEdit_ipv4gateway->clear();
      break;
    case 5:
      ui.comboBox_ipv6method->setCurrentIndex(0);
      ui.spinBox_ipv6prefixlength->setValue(0);
      ui.lineEdit_ipv6address->clear();
      ui.lineEdit_ipv6gateway->clear();
      ui.comboBox_ipv6privacy->setCurrentIndex(0);
      break;
    case 6:
      ui.comboBox_proxymethod->setCurrentIndex(0);
      ui.lineEdit_proxyurl->clear();
      ui.lineEdit_proxyservers->clear();
      ui.lineEdit_proxyexcludes->clear();
      break;
    default:
      break;
  } // switch

  return;
}

//
// Slot to reset all pages.  Called when ui.pushButton_resetall
// is clicked().
void PropertiesEditor::resetAll()
{
  for (int i = 0; i < ui.toolBox_peditor->count(); ++i) {
    this->resetPage(i);
  }

  return;
}

//
// Slot to update the configuration then exit.  Called when  ui.pushButton_ok
// is clicked. Step through each page of the QToolBox and send any entries
// to connman.
void PropertiesEditor::updateConfiguration()
{
  // Some variables
  QString s;
  QStringList sl;
  QList<QVariant> vlist;
  QMap<QString,QVariant> dict;
  QDBusInterface* iface_serv = new QDBusInterface(DBUS_SERVICE, objpath.path(), "net.connman.Service", QDBusConnection::systemBus(), this);
  QList<QLineEdit*> lep;
  QStringList slp;

  // QCheckboxes
  // Only update if changed
  if (ui.checkBox_autoconnect->isChecked() != objmap.value("AutoConnect").toBool() ) {
    vlist.clear();
    vlist << "AutoConnect";
    vlist << QVariant::fromValue(QDBusVariant(ui.checkBox_autoconnect->isChecked()) );
    shared::processReply(iface_serv->callWithArgumentList(QDBus::AutoDetect, "SetProperty", vlist) );
  }

  // QLineEdits (nameservers, timeservers and domains)
  lep.clear();
  slp.clear();
  lep << ui.lineEdit_nameservers << ui.lineEdit_timeservers << ui.lineEdit_domains;
  slp << "Nameservers.Configuration" << "Timeservers.Configuration" << "Domains.Configuration";
  for (int i = 0; i < lep.count(); ++i) {
    s = lep.at(i)->text();
    s.replace(',', ' ');
    s.replace(';', ' ');
    s = s.simplified();

    if (s.isEmpty() ) sl.clear();
    else sl = s.split(' ');

    // Only update if an entry has changed.
    if (sl != objmap.value(slp.at(i)).toStringList()) {
      vlist.clear();
      vlist << slp.at(i);
      vlist << QVariant::fromValue(QDBusVariant(sl) );
      shared::processReply(iface_serv->callWithArgumentList(QDBus::AutoDetect, "SetProperty", vlist) );
    } // if
  } //for

  // ipv4
  // Only update if an entry has changed.
  if ((ui.comboBox_ipv4method->currentText() != TranslateStrings::cmtr(ipv4map.value("Method").toString()) )	|
      (ui.lineEdit_ipv4address->text() != TranslateStrings::cmtr(ipv4map.value("Address").toString()) )      	|
      (ui.lineEdit_ipv4netmask->text() != TranslateStrings::cmtr(ipv4map.value("Netmask").toString()) )				|
      (ui.lineEdit_ipv4gateway->text() != TranslateStrings::cmtr(ipv4map.value("Gateway").toString())) )			{

    vlist.clear();
    lep.clear();
    slp.clear();
    dict.clear();
    vlist << "IPv4.Configuration";
    dict.insert("Method", sl_ipv4_method.at(ui.comboBox_ipv4method->currentIndex()) );

    lep << ui.lineEdit_ipv4address << ui.lineEdit_ipv4netmask << ui.lineEdit_ipv4gateway;
    slp << "Address" << "Netmask" << "Gateway";
    for (int i = 0; i < lep.count(); ++i) {
      s = lep.at(i)->text();
      s = s.simplified(); // really should not be needed with the validator
      if (s.isEmpty() ) s.clear();
      dict.insert(slp.at(i), s);
    } // for

    vlist << QVariant::fromValue(QDBusVariant(dict) );
    shared::processReply(iface_serv->callWithArgumentList(QDBus::AutoDetect, "SetProperty", vlist) );
  } // if ipv4 changed

  // ipv6
  // Only update if an entry has changed.
  if ((ui.comboBox_ipv6method->currentText() != TranslateStrings::cmtr(ipv6map.value("Method").toString()) ) 		|
      (static_cast<uint>(ui.spinBox_ipv6prefixlength->value()) != ipv6map.value("PrefixLength").toUInt() )    	|
      (ui.lineEdit_ipv6address->text() != TranslateStrings::cmtr(ipv6map.value("Address").toString()) )    	    |
      (ui.lineEdit_ipv6gateway->text() != TranslateStrings::cmtr(ipv6map.value("Gateway").toString()) )				  |
      (ui.comboBox_ipv6privacy->currentText() != TranslateStrings::cmtr(ipv6map.value("Privacy").toString())) ) {

    vlist.clear();
    lep.clear();
    slp.clear();
    dict.clear();
    vlist << "IPv6.Configuration";
    dict.insert("Method", sl_ipv6_method.at(ui.comboBox_ipv6method->currentIndex()) );
    dict.insert("PrefixLength", QVariant::fromValue(static_cast<quint8>(ui.spinBox_ipv6prefixlength->value())) );
    dict.insert("Privacy", sl_ipv6_privacy.at(ui.comboBox_ipv6privacy->currentIndex()) );

    lep << ui.lineEdit_ipv6address <<  ui.lineEdit_ipv6gateway;
    slp << "Address" << "Gateway";
    for (int i = 0; i < lep.count(); ++i) {
      s = lep.at(i)->text();
      s = s.simplified(); // really should not be needed with the validator
      if (s.isEmpty() ) s.clear();
      dict.insert(slp.at(i), s);
    } // for

    vlist << QVariant::fromValue(QDBusVariant(dict) );
    shared::processReply(iface_serv->callWithArgumentList(QDBus::AutoDetect, "SetProperty", vlist) );
  } // if ipv6 changed

  // proxy
  // Only update if an entry has changed.
  if ((ui.comboBox_proxymethod->currentText() != TranslateStrings::cmtr(proxmap.value("Method").toString()) )	|
      (ui.lineEdit_proxyservers->text() != proxmap.value("Servers").toStringList().join("\n") )								|
      (ui.lineEdit_proxyexcludes->text() != proxmap.value("Excludes").toStringList().join("\n") )							|
      (ui.lineEdit_proxyurl->text() != proxmap.value("URL").toString()) )																			{

    vlist.clear();
    lep.clear();
    slp.clear();
    dict.clear();
    vlist << "Proxy.Configuration";
    dict.insert("Method", sl_proxy_method.at(ui.comboBox_proxymethod->currentIndex()) );

    lep << ui.lineEdit_proxyurl << ui.lineEdit_proxyservers << ui.lineEdit_proxyexcludes;
    slp << "URL" << "Servers" << "Excludes";
    for (int i = 0; i < lep.count(); ++i) {
      s = lep.at(i)->text();
      s = s.simplified();
      // URL is a single string
      if ( i == 0 ) {
        if (s.isEmpty() ) s.clear();
        dict.insert(slp.at(i), s);
      } // if
      // remanider are an array of strings
      else {
        if (s.isEmpty() ) sl.clear();
        else sl = s.split(' ');
        dict.insert(slp.at(i), sl);
      } //else
    } // for

    vlist << QVariant::fromValue(QDBusVariant(dict) );
    qDebug() << dict;
    shared::processReply(iface_serv->callWithArgumentList(QDBus::AutoDetect, "SetProperty", vlist) );
  } // if proxy changed

  // cleanup
  iface_serv->deleteLater();
  this->accept();
}
