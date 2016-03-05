/**************************** shared.cpp ***************************
Functions shared across various classes

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
  buttonbox->button(QDialogButtonBox::Ok)->setDisabled(true);	// disable OK until input validates
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
  QString s_ip4   = "(?:25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])";
  QString s_ip6   = "(?:[0-9a-fA-F]{1,4})";
  QString s_mac   = "(?:[0-9a-fA-F]{1,2})";
  QString s_hex   = "[0-9a-fA-F]*";
  QString s_int		= "[0-9]*";
  QString s_dom   = "[0-9a-zA-Z]*[\\.]?[0-9a-zA-Z]*";
  QString s_wd    = "[0-9,a-zA-Z_\\.\\!\\@\\#\\$\\%\\^\\&\\*\\+\\-]*";
  QString s_ch		= "\\S";
  QString s_start = (plural ? "\\s?|(" : "^");
  QString s_end   = (plural ? "(\\s*[,|;|\\s]\\s*))+" : "$");
  
  switch (vd){
    case CMST::ValDialog_IPv4: {
      QRegularExpression rx4(s_start + s_ip4 + "(?:\\." + s_ip4 + "){3}" + s_end);
      QRegularExpressionValidator* lev_4 = new QRegularExpressionValidator(rx4, this);
      lineedit->setValidator(lev_4); }
      break;
    case CMST::ValDialog_IPv6: {
      QRegularExpression rx6(s_start + s_ip6 + "(?::" + s_ip6 + "){7}" + s_end);
      QRegularExpressionValidator* lev_6 = new QRegularExpressionValidator(rx6, this);
      lineedit->setValidator(lev_6); }
      break;
    case CMST::ValDialog_MAC: {
      QRegularExpression rxm(s_start + s_mac + "(?::" + s_mac + "){5}" + s_end);
      QRegularExpressionValidator* lev_m = new QRegularExpressionValidator(rxm, this); 
      lineedit->setValidator(lev_m); }
      break;
    case CMST::ValDialog_46: {
      QRegularExpression rx46(s_start + "(" + s_ip4 + "(?:\\." + s_ip4 + "){3}|" + s_ip6 + "(?::" + s_ip6 + "){7})" + s_end);    
      QRegularExpressionValidator* lev_46 = new QRegularExpressionValidator(rx46, this);  
      lineedit->setValidator(lev_46); }
      break;  
    case CMST::ValDialog_Hex: {
      QRegularExpression rxh(s_start + s_hex + s_end);
      QRegularExpressionValidator* lev_h = new QRegularExpressionValidator(rxh, this);
      lineedit->setValidator(lev_h); }
      break;
    case CMST::ValDialog_Int: {
			QRegularExpression rxint(s_start + s_int + s_end);
      QRegularExpressionValidator* lev_int = new QRegularExpressionValidator(rxint, this);
      lineedit->setValidator(lev_int); }
      break;		  
    case CMST::ValDialog_Dom: {
      QRegularExpression rxdom(s_start + s_dom + s_end);
      QRegularExpressionValidator* lev_dom = new QRegularExpressionValidator(rxdom, this);
      lineedit->setValidator(lev_dom); }
      break;
    case CMST::ValDialog_Wd: {
      QRegularExpression rxwd(s_start + s_wd + s_end);
      QRegularExpressionValidator* lev_wd = new QRegularExpressionValidator(rxwd, this);
      lineedit->setValidator(lev_wd); }
      break;
    case CMST::ValDialog_min1ch: {
			QRegularExpression rx1char(s_start + s_ch + "{1,}" + s_end);
			QRegularExpressionValidator* lev_1char = new QRegularExpressionValidator(rx1char, this);
			lineedit->setValidator(lev_1char); }
			break;    
		case CMST::ValDialog_min8ch: {
			QRegularExpression rx8char(s_start + s_ch + "{8,}" + s_end);
			QRegularExpressionValidator* lev_8char = new QRegularExpressionValidator(rx8char, this);
			lineedit->setValidator(lev_8char); }
			break; 
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
