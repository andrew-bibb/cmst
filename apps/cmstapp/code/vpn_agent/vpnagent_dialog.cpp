/****************** vpnagent_dialog.cpp *********************************** 

Code to manage the agent user interface.  When the connman daemon
needs to communicate with the user it does so through the agent.  The
agent has a QDialog as a class member, and agent_dialog.cpp manages
that dialog.  

Copyright (C) 2016
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

# include "./vpnagent_dialog.h"
# include "./code/trstring/tr_strings.h"

VPNAgentDialog::VPNAgentDialog(QWidget* parent)
    : QDialog(parent)
{
	// setup the user interface
  ui.setupUi(this);
  	  
  // data members	  
  	  
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
		r_map["Password"] = ui.lineEdit_password->text().toLatin1();	
	
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
	
	/////////NEED RADIO BUTTONS !!!!!!!!!!!!!!!!!!
	return;
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
	
	//	set disabled true for all widgets in the list and clear contents
	for (int i = 0; i < list.size(); ++i) {
		list.at(i)->setDisabled(true);
		if (qobject_cast<QLineEdit *> (list.at(i)) != NULL ) qobject_cast<QLineEdit *> (list.at(i))->clear();
		if (qobject_cast<QAbstractButton *> (list.at(i)) != NULL ) qobject_cast<QAbstractButton *> (list.at(i))->setChecked(false);
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




