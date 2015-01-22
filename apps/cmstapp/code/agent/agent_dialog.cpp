/****************** agent_dialog.cpp *********************************** 

Code to manage the agent user interface.  When the connman daemon
needs to communicate with the user it does so through the agent.  The
agent has a QDialog as a class member, and agent_dialog.cpp manages
that dialog.  

Copyright (C) 2013-2015
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
# include <QProcess>.
# include <QProcessEnvironment>
# include <QDir>
# include <QMessageBox>

# include "./agent_dialog.h"
# include "./code/trstring/tr_strings.h"

AgentDialog::AgentDialog(QWidget* parent)
    : QDialog(parent)
{
	// setup the user interface
  ui.setupUi(this);
  	  
  // connect signals to slots
	connect(ui.toolButton_whatsthis, SIGNAL(clicked()), this, SLOT(showWhatsThis()));  
  connect (ui.checkBox_hide_passphrase, SIGNAL(clicked(bool)), this, SLOT(hidePassphrase(bool)));
  connect (ui.checkBox_wps_no_pin, SIGNAL(clicked(bool)), this, SLOT(useWPSPushButton(bool)));  
  connect (ui.pushButton_launch_browser,SIGNAL(clicked()), this, SLOT(launchBrowser())); 
  
	// find the PATH of the current environment
	sys_env_path = QString();
	QProcessEnvironment se = QProcessEnvironment::systemEnvironment();
	if (se.keys().contains("PATH")) {
		sys_env_path = se.toStringList().at(se.keys().indexOf("PATH"));
		sys_env_path.remove("PATH=");
	}  		  
}    

///////////////////////////////////////////////// Public Functions /////////////////////////////////////////////
//
//	Function to show page 0 of the stackWidget
//	imap - is map of QStrings with input keys that connman has requested the user to fill in, and any values
//	that it has sent back for informational purposes.  Return the accept state of the dialog
int AgentDialog::showPage0(const QMap<QString,QString>& imap)
{
	// set all input widgets to disabled
	this->initialize();
	
	// turn on the boxes that need to be filled in
	if (imap.contains("Passphrase")) {
		ui.lineEdit_passphrase->setEnabled(true);
		ui.lineEdit_passphrase->setText(imap.value("Passphrase") );
		ui.checkBox_hide_passphrase->setEnabled(true);
	} 
	if (imap.contains("PreviousPassphrase")) {
		ui.lineEdit_old_passphrase->setEnabled(true);
		ui.lineEdit_old_passphrase->setText(imap.value("PreviousPassphrase") );
	}
	if (imap.contains("SSID")) {
		ui.lineEdit_ssid->setEnabled(true);
		ui.lineEdit_ssid->setText(imap.value("SSID") );
	}
	if (imap.contains("Name")) {
		ui.lineEdit_hidden_name->setEnabled(true); 
		ui.lineEdit_hidden_name->setText(imap.value("Name") );
	}		
	if (imap.contains("Userame")) {
		ui.lineEdit_wispr_username->setEnabled(true); 
		ui.lineEdit_wispr_username->setText(imap.value("Username") );
	}
	if (imap.contains("Password")) {
		ui.lineEdit_wispr_password->setEnabled(true);
		ui.lineEdit_wispr_password->setText(imap.value("Password") );
	}
	if (imap.contains("Identity")) {
		ui.lineEdit_eap_identity->setEnabled(true); 	
		ui.lineEdit_eap_identity->setText(imap.value("Identity") );
	}		
	if (imap.contains("WPS")) {
		ui.lineEdit_wps_pin->setEnabled(true);
		ui.lineEdit_wps_pin->setText(imap.value("WPS") );
		ui.checkBox_wps_no_pin->setEnabled(true);
	} 	
	
	this->ui.stackedWidget->setCurrentIndex(0);
	return this->exec();
}

//
//	Function to show page 1 of the stackWidget
//	url - is the url that the user needs to open
//	Return the accept state of the dialog
int AgentDialog::showPage1(const QString& url)
{
	// set all input widgets to disabled
	this->initialize();	
	
	// show the url connman is requesting we connect to
	ui.lineEdit_url->setText(url);
	
	// find browser executables
	QStringList sl_browsers;	
	if (! sys_env_path.isEmpty() ) {
		QStringList sl_loop = sys_env_path.split(':');
		QStringList sl_targets;
		sl_targets << "firefox" << "opera" << "luakit" << "lynx";
		sl_browsers.clear();
		for (int i = 0; i < sl_loop.size(); ++i) {
			QDir dir = QDir(sl_loop.at(i));
			sl_browsers.append(dir.entryList(sl_targets, QDir::Files|QDir::Executable));
		}	// for dir in path
	}	// if path not empty	
	
	// add found browsers to the combobox
	ui.comboBox_browser->addItems(sl_browsers);
	ui.comboBox_browser->setEnabled(true);
	
	this->ui.stackedWidget->setCurrentIndex(1);
	return this->exec();	
}

//
//	Function to extract the input data from the QLineEdit's in the dialog and put it into
//	a QMap<QString,QVariant>.  The QMap is sent to this function as a reference and is modified by the function.
void AgentDialog::createDict(QMap<QString,QVariant>& r_map)
{
	// Initialize the map
	r_map.clear();
	
	// Create the dict entries
	if (! ui.lineEdit_passphrase->text().isEmpty() ) 
		r_map["Passphrase"] = ui.lineEdit_passphrase->text();
	
	if (! ui.lineEdit_ssid->text().isEmpty() )
		r_map["SSID"] = ui.lineEdit_ssid->text().toLatin1();	
	
	if (! ui.lineEdit_hidden_name->text().isEmpty() )
		r_map["Name"] = ui.lineEdit_hidden_name->text();
	
	if (! ui.lineEdit_wispr_username->text().isEmpty() )
		r_map["Username"] = ui.lineEdit_wispr_username->text();
	
	if (! ui.lineEdit_wispr_password->text().isEmpty() )
		r_map["Password"] = ui.lineEdit_wispr_password->text();
	
	if (! ui.lineEdit_eap_identity->text().isEmpty() )
		r_map["Identity"] = ui.lineEdit_eap_identity->text();
	
	if (! ui.lineEdit_wps_pin->text().isEmpty() )
		r_map["WPS"] = ui.lineEdit_wps_pin->text();
	
	return;
}
///////////////////////////////////////////////// Private Functions /////////////////////////////////////////////
//
//	Function to initialize the fields in the dialog box, everything is disabled to start
void AgentDialog::initialize()
{
	// QList of widget pointers
	QList <QWidget*> list;
	list.clear();
	list.append(ui.lineEdit_passphrase);
	list.append(ui.lineEdit_old_passphrase);
	list.append(ui.checkBox_hide_passphrase);	
	list.append(ui.lineEdit_ssid);
	list.append(ui.lineEdit_hidden_name);
	list.append(ui.lineEdit_wispr_username);
	list.append(ui.lineEdit_wispr_password);
	list.append(ui.lineEdit_eap_identity);
	list.append(ui.lineEdit_wps_pin);
	list.append(ui.checkBox_wps_no_pin);	
	list.append(ui.comboBox_browser);
	
	//	set disabled true for all widgets in the list and clear contents
	for (int i = 0; i < list.size(); ++i) {
		list.at(i)->setDisabled(true);
		if (qobject_cast<QLineEdit *> (list.at(i)) != NULL ) qobject_cast<QLineEdit *> (list.at(i))->clear();
		if (qobject_cast<QAbstractButton *> (list.at(i)) != NULL ) qobject_cast<QAbstractButton *> (list.at(i))->setChecked(false);
	}
}

///////////////////////////////////////////////// Private Slots /////////////////////////////////////////////
//
//	Slot to show or obscure the passphrase
void AgentDialog::hidePassphrase(bool checked)
{
	checked ? ui.lineEdit_passphrase->setEchoMode(QLineEdit::Password) : ui.lineEdit_passphrase->setEchoMode(QLineEdit::Normal);
}

//
//	Slot to use WPS PushButton Authentication
//	Called when ui.checkBox_wps_no_pin is checked or unchecked
void AgentDialog::useWPSPushButton(bool checked)
{
	if (checked) ui.lineEdit_wps_pin->clear(); 
	ui.lineEdit_wps_pin->setDisabled(checked);	
}

//
//  Slot to enter whats this mode
//	Called when the ui.toolButton_whatsthis clicked() signal is emitted
void AgentDialog::showWhatsThis()
{
  QWhatsThis::enterWhatsThisMode();
}

//
//	Slot to launch the selected browser
//	Called when ui.pushButton_launch_browser is pressed
void AgentDialog::launchBrowser()
{
	// variables
	QProcess* process = new QProcess(this);

	// find installed terminals that we can deal with
	QStringList sl_terminals = QStringList();	
	if (! sys_env_path.isEmpty() ) {
		QStringList sl_loop = sys_env_path.split(':');
		QStringList sl_targets;
		sl_targets << "roxterm" << "xterm";
		for (int i = 0; i < sl_loop.size(); ++i) {
			QDir dir = QDir(sl_loop.at(i));
			sl_terminals.append(dir.entryList(sl_targets, QDir::Files|QDir::Executable));
		}	// for dir in path
	}	// if path not empty	
		
	QString chosenBrowser = ui.comboBox_browser->currentText();
	if (chosenBrowser == "lynx") {
	// lynx (CLI browser) is chosen
		QStringList sl_args = QStringList();
		if (sl_terminals.contains("roxterm")) {
			sl_args << "-T" << "Web Login" << "--execute" << "lynx" << ui.lineEdit_url->text();
			 process->startDetached(QString("roxterm"), sl_args);
		 }
		 else if (sl_terminals.contains("xterm")) {
			 sl_args << "-T"  << "Web Login" << "-e" << "lynx" << ui.lineEdit_url->text();
			 process->startDetached(QString("xterm"), sl_args);
		 }
		 else
		 	QMessageBox::information(qobject_cast<QWidget *> (parent()),
		 	QString(TranslateStrings::cmtr("cmst")) + tr(" Information"),
				tr("You have requested the %1 browser, but we cannot find a terminal program to open it with.  "	\
				"Currenty we can start %1 using these terminals: <b>roxterm</b> and <b>xterm</b>." \
				"<br><br>To continue you need to manually open a terminal and then enter: \"lynx %2\"").arg("Lynx").arg(ui.lineEdit_url->text()) );
	} else {
		process->startDetached(chosenBrowser, QStringList(ui.lineEdit_url->text()) );	
	}
}
