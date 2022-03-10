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
//
// The ipv6 validator string is from:
// https://stackoverflow.com/questions/53497/regular-expression-that-matches-valid-ipv6-addresses
// leaving out the IPv4 mapped or embedded tests
QString shared::ValidatingDialog::getPattern(const int& vd, bool plural)
{
   // setup a switch to set the validator
   const QString ip4seg = "(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])";
   const QString s_ip4  = (ip4seg + "(\\." + ip4seg + "){3}");
   const QString s_nmask4 = "(3[0-2]|[1-2][0-9]|[0-9])";
   const QString s_nmask6 = "(12[0-8]|1[0-1][0-9]|[1-9][0-9]|[0-9])";
   const QString ip6seg = "[0-9a-fA-F]{1,4}";
   const QString s_ip6 =  (
      QString("(") +
      QString("(" + ip6seg + ":){7,7}" + ip6seg + "|") +
      QString("(" + ip6seg + ":){1,7}:" + "|") +
      QString("(" + ip6seg + ":){1,6}:" + ip6seg + "|") +
      QString("(" + ip6seg + ":){1,5}(:" + ip6seg + "){1,2}" + "|") +
      QString("(" + ip6seg + ":){1,4}(:" + ip6seg + "){1,3}" + "|") +
      QString("(" + ip6seg + ":){1,3}(:" + ip6seg + "){1,4}" + "|") +
      QString("(" + ip6seg + ":){1,2}(:" + ip6seg + "){1,5}" + "|") +
      QString(ip6seg + ":((:" + ip6seg + "){1,6})" + "|") +
      QString(":((:" + ip6seg + "){1,7}|:)" + "|") +
      QString("fe80:(:" + ip6seg + "){0,4}%[0-9a-zA-Z]{1,}") +
      QString(")") );

   const QString s_mac   = "(?:[0-9a-fA-F]{1,2})";
   const QString s_hex   = "[0-9a-fA-F]*";
   const QString s_int   = "[0-9]*";
   const QString s_dom   = "((?!-)[A-Za-z0-9-]{1,63}(?<!-)\\.)+[A-Za-z]{2,6}";
   const QString s_word  = "[0-9,a-zA-Z_\\.\\!\\@\\#\\$\\%\\^\\&\\*\\+\\-]*";
   const QString s_ch    = "\\S";
   const QString s_start = (plural ? "^(" : "^");
   const QString s_end   = (plural ? "([,;|\\s]\\s*|$))+" : "$");

   QString rs;

   switch (vd){
      case CMST::ValDialog_IPv4:
      rs = QString(s_start + s_ip4 + s_end);
      break;
   case CMST::ValDialog_IPv4cidr:
      rs = QString(s_start + s_ip4 + "(/" + s_nmask4 + ")?" + s_end);
      break;
   case CMST::ValDialog_nmask4:
      rs = (s_start +  "(" + s_nmask4 + "|" + s_ip4 + ")" + s_end);
      break;
   case CMST::ValDialog_IPv6:
      rs = (s_start + s_ip6 + s_end);
      break;
   case CMST::ValDialog_IPv6cidr:
      rs = (s_start + s_ip6 + "(/" + s_nmask6 + ")?" + s_end);
      break;
   case CMST::ValDialog_MAC:
      rs = (s_start + s_mac + "(?::" + s_mac + "){5}" + s_end);
      break;
   case CMST::ValDialog_46:
      rs = (s_start + "(" + s_ip4 + "|" + s_ip6 + ")" + s_end);
      break;
   case CMST::ValDialog_46cidr:
      rs = (s_start + "(" + s_ip4 + "(/" + s_nmask4 + ")?" + "|" + s_ip6 + "(/" + s_nmask6 + ")?" + ")" + s_end);
      break;
   case CMST::ValDialog_Hex:
      rs = (s_start + s_hex + s_end);
      break;
   case CMST::ValDialog_Int:
      rs = (s_start + s_int + s_end);
      break;
   case CMST::ValDialog_Dom:
      rs = (s_start + s_dom + s_end);
      break;
   case CMST::ValDialog_Word:
      rs = (s_start + s_word + s_end);
      break;
   case CMST::ValDialog_min1ch:
      rs = (s_start + s_ch + "{1,}" + s_end);
      break;
   case CMST::ValDialog_min8ch:
      rs = (s_start + s_ch + "{8,}" + s_end);
      break;
  case CMST::ValDialog_networks:
      rs = s_start;
      rs.append("(");
      rs.append("(" + s_ip4 + "/(" + s_nmask4 + "|" + s_ip4 + ")(/" + s_ip4 + ")?)");
      rs.append("|");
      rs.append("(" + s_ip6 + "/" + s_nmask6 + ")" );
      rs.append(")");
      rs.append(s_end);
      break;
   default:
      QRegularExpression qrex;
      rs = qrex.pattern();
      break;
   } // switch

   return rs;
}

// Slot to set the lineedit validator. If plural is true multiple values can
// be supplied separated by comma, semi-colon or white space
//
void shared::ValidatingDialog::setValidator(const int& vd, bool plural)
{

   QRegularExpressionValidator* qrex_val= new QRegularExpressionValidator(QRegularExpression(this->getPattern(vd, plural)) );
   lineedit->setValidator(qrex_val);
   qrex_val->deleteLater();

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


