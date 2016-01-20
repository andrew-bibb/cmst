/**************************** vpnagent_dialog.h ***************************

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

# ifndef VPN_AGENT_DIALOG_H
# define VPN_AGENT_DIALOG_H

# include <QDialog>
# include <QString>
# include <QVariant>

# include "ui_vpnagent.h"

//	The class to control the agent UI based on a QDialog
class VPNAgentDialog : public QDialog
{
  Q_OBJECT

  public:
  // members
    VPNAgentDialog(QWidget*);
    
	// functions
		void createDict(QMap<QString,QVariant>&);
		int showPage(const QMap<QString,QString>&);
  
  private:  
  // members
		Ui::VPNAgent ui;
		
	// functions
		void initialize();
		   
  private slots:		
		void showWhatsThis();
		
	public:
		inline void setWhatsThisIcon(QIcon icon) {ui.toolButton_whatsthis->setIcon(icon);}
};


#endif
