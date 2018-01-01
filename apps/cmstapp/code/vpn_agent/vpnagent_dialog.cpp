/****************** vpnagent_dialog.cpp *********************************** 

Code to manage the agent user interface.  When the connman daemon
needs to communicate with the user it does so through the agent.  The
agent has a QDialog as a class member, and agent_dialog.cpp manages
that dialog.  

Copyright (C) 2016-2018
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
# include <QList>
#	include <QWhatsThis>
# include <QProcess>
# include <QProcessEnvironment>
# include <QDir>
# include <QMessageBox>
# include <QStringListModel>
# include <QCheckBox>

# include "./vpnagent_dialog.h"
# include "./code/trstring/tr_strings.h"

VPNAgentDialog::VPNAgentDialog(QWidget* parent)
    : QDialog(parent)
{
	// setup the user interface
  ui.setupUi(this);
  	  
  	  
  // connect signals to slots
	connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));  
   		  
}    

///////////////////////////////////////////////// Public Functions /////////////////////////////////////////////
//
//	Function to extract the input data from the QLineEdit's in the dialog and put it into
//	a QMap<QString,QVariant>.  The QMap is sent to this function as a reference and is modified by the function.
void VPNAgentDialog::createDict(QMap<QString,QVariant>& r_map)
{
	// Initialize the map
	r_map.clear();
	
	// Create the dict entries
	if (! ui.lineEdit_username->text().isEmpty() ) 
		r_map["Username"] = ui.lineEdit_username->text();
	
	if (! ui.lineEdit_password->text().isEmpty() )
		r_map["Password"] = ui.lineEdit_password->text();	
	
	if (! ui.lineEdit_host->text().isEmpty() )
		r_map["Host"] = ui.lineEdit_host->text();
	
	if (! ui.lineEdit_name->text().isEmpty() )
		r_map["Name"] = ui.lineEdit_name->text();
	
	if (! ui.lineEdit_cacert->text().isEmpty() )
		r_map["OpenConnect.CaCert"] = ui.lineEdit_cacert->text();
	
	if (! ui.lineEdit_cookie->text().isEmpty() )
		r_map["OpenConnect.Cookie"] = ui.lineEdit_cookie->text();
	
	if (! ui.lineEdit_servercert->text().isEmpty() )
		r_map["OpenConnect.ServerCert"] = ui.lineEdit_servercert->text();
		
	if (! ui.lineEdit_vpnhost->text().isEmpty() )
		r_map["OpenConnect.VPNHost"] = ui.lineEdit_vpnhost->text();	
	
	if (ui.checkBox_savecredentials->isEnabled() )
		r_map["SaveCredentials"] =  ui.checkBox_savecredentials->isChecked();
		
	return;
}

//
//	Function to show the dialog.
//	imap - is map of QStrings with input keys that connman has requested the user to fill in, and any values
//	that it has sent back for informational purposes.  Return the accept state of the dialog
int VPNAgentDialog::showPage(const QMap<QString,QString>& imap)
{
	// set all input widgets to disabled
	this->initialize();
	
	// turn on the boxes that need to be filled in
	if (imap.contains("Username")) { 
		ui.lineEdit_username->setEnabled(true);
		ui.lineEdit_username->setText(imap.value("Username") );
	}
	if (imap.contains("Password")) {
		ui.lineEdit_password->setEnabled(true);
		ui.lineEdit_password->setText(imap.value("Password") );
	}	
	if (imap.contains("Host")) {
		ui.lineEdit_host->setEnabled(true);
		ui.lineEdit_host->setText(imap.value("Host") );
	}
	if (imap.contains("Name")) {
		ui.lineEdit_name->setEnabled(true);
		ui.lineEdit_name->setText(imap.value("Name") );
	}
	if (imap.contains("OpenConnect.CaCert")) {
		ui.lineEdit_cacert->setEnabled(true);
		ui.lineEdit_cacert->setText(imap.value("OpenConnect.CaCert") );
	}
	if (imap.contains("OpenConnect.Cookie")) {
		ui.lineEdit_cookie->setEnabled(true);
		ui.lineEdit_cookie->setText(imap.value("OpenConnect.CaCert") );
	}
	if (imap.contains("OpenConnect.ServerCert")) {
		ui.lineEdit_servercert->setEnabled(true);
		ui.lineEdit_servercert->setText(imap.value("OpenConnect.ServerCert") );
	}
	if (imap.contains("OpenConnect.VPNHost")) {
		ui.lineEdit_vpnhost->setEnabled(true);
		ui.lineEdit_vpnhost->setText(imap.value("OpenConnect.VPNHost") );
	}
	if (imap.contains("SaveCredentials")) {
		ui.checkBox_savecredentials->setEnabled(true);
	}

	return this->exec();
}

///////////////////////////////////////////////// Private Functions /////////////////////////////////////////////
//
//	Function to initialize the fields in the dialog box, everything is disabled to start
void VPNAgentDialog::initialize()
{
	// QList of widget pointers
	QList <QWidget*> list;
	list.clear();
	list.append(ui.lineEdit_username);
	list.append(ui.lineEdit_password);
	list.append(ui.lineEdit_host);	
	list.append(ui.lineEdit_name);
	list.append(ui.lineEdit_cacert);
	list.append(ui.lineEdit_clientcert);
	list.append(ui.lineEdit_cookie);
	list.append(ui.lineEdit_servercert);
	list.append(ui.lineEdit_vpnhost);
	list.append(ui.checkBox_savecredentials);
	
	//	set disabled true for all widgets in the list and clear contents
	for (int i = 0; i < list.size(); ++i) {
		list.at(i)->setDisabled(true);
		if (qobject_cast<QLineEdit *> (list.at(i)) != NULL ) qobject_cast<QLineEdit *> (list.at(i))->clear();
		if (qobject_cast<QCheckBox *> (list.at(i)) != NULL ) qobject_cast<QCheckBox *> (list.at(i))->setChecked(false);
	}
}

///////////////////////////////////////////////// Private Slots /////////////////////////////////////////////


//
//  Slot to enter whats this mode
//	Called when the ui.toolButton_whatsthis clicked() signal is emitted
void VPNAgentDialog::showWhatsThis()
{
  QWhatsThis::enterWhatsThisMode();
}




