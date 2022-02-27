/**************************** shared.cpp ***************************
Functions shared across various classes

Copyright (C) 2013-2022
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
LIABILITY, WHETHER IN AN ACTION OF C
* ONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
***********************************************************************/

# include <QtCore/QDebug>
# include <QCoreApplication>
# include <QVBoxLayout>
# include <QRegularExpression>
# include <QRegularExpressionValidator>

# include "../resource.h"
# include "./shared.h"
# include "./code/trstring/tr_strings.h"

//
// Function to process the reply from a dbus call.
QDBusMessage::MessageType shared::processReply(const QDBusMessage& reply)
{
  if (reply.type() != QDBusMessage::ReplyMessage) {
    QMessageBox::warning(0,
        QString(TranslateStrings::cmtr("cmst") + qApp->translate("processReply", " Warning") ),
        qApp->translate("processReply",
          "<center><b>We received a DBUS reply message indicating an error.</b></center>"
          "<br><br>Error Name: %1<br><br>Error Message: %2")
            .arg(reply.errorName())
            .arg(TranslateStrings::cmtr(reply.errorMessage())) );
   } // if reply is something other than a normal reply message

  return reply.type();
}

//
//  Function to extract the data from a QDBusArgument that contains a map.
//  Some of the arrayElements can contain a QDBusArgument as the object
//  instead of a primitive (string, bool, int, etc.). This function
//  will extract the data from the QDBusArgument and write it into a map.
//
//  Return value a bool, true on success, false otherwise.
//  The map is sent by reference (called r_map here) and is modified by this function.
//  r_var is a constant reference to the QDBusArgument.
//
bool shared::extractMapData(QMap<QString,QVariant>& r_map, const QVariant& r_var)
{
  //  make sure we can convert the QVariant into a QDBusArgument
  if (! r_var.canConvert<QDBusArgument>() ) return false;
  const QDBusArgument qdba =  r_var.value<QDBusArgument>();

  // make sure the QDBusArgument holds a map
  if (qdba.currentType() != QDBusArgument::MapType ) return false;

  // iterate over the QDBusArgument pulling map keys and values out
    r_map.clear();
    qdba.beginMap();

    while ( ! qdba.atEnd() ) {
      QString key;
      QVariant value;
      qdba.beginMapEntry();
      qdba >> key >> value;
      qdba.endMapEntry();
      r_map.insert(key, value);
    } // while

    qdba.endMap();
    return true;
}

//
// Validating Dialog - an input dialog knockoff with a validated lineedit.
// In addition to the usual input validation the dialog will only enable
// the OK button when the input is completely validated..
// Constructor
shared::ValidatingDialog::ValidatingDialog(QWidget* parent) : QDialog(parent)
{
  // build the dialog
  label = new QLabel(this);
  lineedit = new QLineEdit(this);
  lineedit->setClearButtonEnabled(true);

  buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
  buttonbox->button(QDialogButtonBox::Ok)->setDisabled(true); // disable OK until input validates
  this->setSizeGripEnabled(true);

  QVBoxLayout* vboxlayout = new QVBoxLayout;
  vboxlayout->addWidget(label);
  vboxlayout->addWidget(lineedit);
  vboxlayout->addWidget(buttonbox);
  this->setLayout(vboxlayout);

  // signals and slots
  connect(buttonbox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonbox, SIGNAL(rejected()), this, SLOT(reject()));
  connect(lineedit, SIGNAL(textChanged(QString)), this, SLOT(textChanged()));
  connect(lineedit, SIGNAL(returnPressed()), this, SLOT(accept()));
}

// Slot to set the lineedit validator. If plural is true multiple values can
// be supplied separated by comma, semi-colon or white space
void shared::ValidatingDialog::setValidator(const int& vd, bool plural)
{
  // setup a switch to set the validator
  const QString ip4seg = "(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])";
  const QString s_ip4  = (ip4seg + "(?:\\." + ip4seg + "){3}");
  const QString s_nmask4 = "(?:3[0-2]|[1-2][0-9]|[0-9])";
  const QString s_nmask6 = "(?:12[0-8]|1[0-1][0-9]|[1-9][0-9]|[0-9])";
  const QString ip6seg = "[0-9a-fA-F]{1,4}";
  const QString s_ip6 =  (
    QString("(" + ip6seg + ":){7,7}" + ip6seg + "|") +
    QString("(" + ip6seg + ":){1,7}:" + "|") +
    QString("(" + ip6seg + ":){1,6}:" + ip6seg + "|") +
    QString("(" + ip6seg + ":){1,5}(:" + ip6seg + "){1,2}" + "|") +
    QString("(" + ip6seg + ":){1,4}(:" + ip6seg + "){1,3}" + "|") +
    QString("(" + ip6seg + ":){1,3}(:" + ip6seg + "){1,4}" + "|") +
    QString("(" + ip6seg + ":){1,2}(:" + ip6seg + "){1,5}" + "|") +
    QString(ip6seg + ":((:" + ip6seg + "){1,6})") );
  const QString s_mac   = "(?:[0-9a-fA-F]{1,2})";
  const QString s_hex   = "[0-9a-fA-F]*";
  const QString s_int   = "[0-9]*";
  const QString s_dom   = "((?!-)[A-Za-z0-9-]{1,63}(?<!-)\\.)+[A-Za-z]{2,6}";
  const QString s_word  = "[0-9,a-zA-Z_\\.\\!\\@\\#\\$\\%\\^\\&\\*\\+\\-]*";
  const QString s_ch    = "\\S";
  const QString s_start = (plural ? "^(" : "^");
  const QString s_end   = (plural ? "([,;|\\s]\\s*|$))+" : "$");

  switch (vd){
    case CMST::ValDialog_IPv4: {
      QRegularExpression rx4(s_start + s_ip4 + s_end);
      QRegularExpressionValidator* lev_4 = new QRegularExpressionValidator(rx4, this);
      lineedit->setValidator(lev_4);
      lev_4->deleteLater(); }
      break;
    case CMST::ValDialog_IPv4cidr: {
      QRegularExpression rx4cidr(s_start + s_ip4 + "(/" + s_nmask4 + ")?" + s_end);
      QRegularExpressionValidator* lev_4cidr = new QRegularExpressionValidator(rx4cidr, this);
      lineedit->setValidator(lev_4cidr);
      lev_4cidr->deleteLater(); }
      break;
   case CMST::ValDialog_nmask4: {
      QRegularExpression nmsk(s_start +  "(" + s_nmask4 + "|" + s_ip4 + ")" + s_end);
      QRegularExpressionValidator* lev_nmask = new QRegularExpressionValidator(nmsk, this);
      lineedit->setValidator(lev_nmask);
      lev_nmask->deleteLater(); }
      break;
    case CMST::ValDialog_IPv6: {
      QRegularExpression rx6(s_start + s_ip6 + s_end);
      QRegularExpressionValidator* lev_6 = new QRegularExpressionValidator(rx6, this);
      lineedit->setValidator(lev_6);
      lev_6->deleteLater(); }
      break;
    case CMST::ValDialog_IPv6cidr: {
      QRegularExpression rx6cidr(s_start + s_ip6 + "(/" + s_nmask6 + ")?" + s_end);
      QRegularExpressionValidator* lev_6cidr = new QRegularExpressionValidator(rx6cidr, this);
      lineedit->setValidator(lev_6cidr);
      lev_6cidr->deleteLater(); }
      break;
    case CMST::ValDialog_MAC: {
      QRegularExpression rxm(s_start + s_mac + "(?::" + s_mac + "){5}" + s_end);
      QRegularExpressionValidator* lev_m = new QRegularExpressionValidator(rxm, this);
      lineedit->setValidator(lev_m);
      lev_m->deleteLater(); }
      break;
    case CMST::ValDialog_46: {
      QRegularExpression rx46(s_start + "(" + s_ip4 + "|" + s_ip6 + ")" + s_end);
      QRegularExpressionValidator* lev_46 = new QRegularExpressionValidator(rx46, this);
      lineedit->setValidator(lev_46);
      lev_46->deleteLater(); }
      break;
    case CMST::ValDialog_46cidr: {
      QRegularExpression rx46cidr(s_start + "(" + s_ip4 + "(/" + s_nmask4 + ")?" + "|" + s_ip6 + "(/" + s_nmask6 + ")?" + ")" + s_end);
      QRegularExpressionValidator* lev_46cidr = new QRegularExpressionValidator(rx46cidr, this);
      lineedit->setValidator(lev_46cidr);
      lev_46cidr->deleteLater(); }
      break;
    case CMST::ValDialog_Hex: {
      QRegularExpression rxh(s_start + s_hex + s_end);
      QRegularExpressionValidator* lev_h = new QRegularExpressionValidator(rxh, this);
      lineedit->setValidator(lev_h);
      lev_h->deleteLater(); }
      break;
    case CMST::ValDialog_Int: {
      QRegularExpression rxint(s_start + s_int + s_end);
      QRegularExpressionValidator* lev_int = new QRegularExpressionValidator(rxint, this);
      lineedit->setValidator(lev_int);
      lev_int->deleteLater(); }
      break;
    case CMST::ValDialog_Dom: {
      QRegularExpression rxdom(s_start + s_dom + s_end);
      QRegularExpressionValidator* lev_dom = new QRegularExpressionValidator(rxdom, this);
      lineedit->setValidator(lev_dom);
      lev_dom->deleteLater(); }
      break;
    case CMST::ValDialog_Word: {
      QRegularExpression rxwd(s_start + s_word + s_end);
      QRegularExpressionValidator* lev_wd = new QRegularExpressionValidator(rxwd, this);
      lineedit->setValidator(lev_wd);
      lev_wd->deleteLater(); }
      break;
    case CMST::ValDialog_min1ch: {
      QRegularExpression rx1char(s_start + s_ch + "{1,}" + s_end);
      QRegularExpressionValidator* lev_1char = new QRegularExpressionValidator(rx1char, this);
      lineedit->setValidator(lev_1char);
      lev_1char->deleteLater(); }
      break;
    case CMST::ValDialog_min8ch: {
      QRegularExpression rx8char(s_start + s_ch + "{8,}" + s_end);
      QRegularExpressionValidator* lev_8char = new QRegularExpressionValidator(rx8char, this);
      lineedit->setValidator(lev_8char);
      lev_8char->deleteLater(); }
      break;
// Don't know why this was ever here, comment it out
//    case CMST::ValDialog_46d: {
//      QRegularExpression rx46d(s_start + "(" + s_ip4 + "(?:\\." + s_ip4 + "){3}|" + s_ip6 + "(?::" + s_ip6 + "){7}|" + s_dom + ")" + s_end);
//      QRegularExpressionValidator* lev_46d = new QRegularExpressionValidator(rx46d, this);
//      lineedit->setValidator(lev_46d);
//      lev_46d->deleteLater(); }
//      break;
    default:
      lineedit->setValidator(0);
      break;
    } // switch

  return;
}

//
// Slot to check if the text can be validated
// Called when the lineedit emits a textChanged() signal
void shared::ValidatingDialog::textChanged()
{
  // enable OK button if text can be validated
  buttonbox->button(QDialogButtonBox::Ok)->setEnabled(lineedit->hasAcceptableInput() );

  return;
}

//
// Slot to initialize the dialog children
// Called when dialog finished() signal is triggered
void shared::ValidatingDialog::initialize()
{
  lineedit->clear();
  lineedit->setValidator(0);
  lineedit->setInputMask(QString());
  lineedit->setModified(false);
  lineedit->setFocus(Qt::OtherFocusReason);
  buttonbox->button(QDialogButtonBox::Ok)->setDisabled(true);

  return;
}


