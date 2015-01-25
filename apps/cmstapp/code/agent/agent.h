/**************************** agent.h **********************************

Code for the user agent registered on DBus.  When the connman daemon
needs to communicate with the user it does so through this agent.

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


# ifndef CONNMANAGENT
#	define CONNMANAGENT

# include <QObject>
# include <QString>
# include <QMap>
# include <QVariant>
# include <QVariantMap>
# include <QtDBus/QDBusObjectPath>
# include <QtDBus/QDBusContext>

# include "./code/agent/agent_dialog.h"

class ConnmanAgent : public QObject, protected QDBusContext
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "net.connman.Agent")
 
    public:
			ConnmanAgent(QObject*);	
			inline void setLogInputRequest(bool b) {b_loginputrequest = b;}
			inline QString getBrowser() {return uiDialog->getBrowser();}
			inline void setBrowser(const QString& b) {uiDialog->setBrowser(b);}
 
    public Q_SLOTS:
      void Release();
      void ReportError(QDBusObjectPath, QString);
      //void RequestBrowser(QDBusObjectPath, QString);
      void RequestBrowser(QString url="http://google.com");
      QVariantMap RequestInput(QDBusObjectPath, QMap<QString,QVariant>);
      void Cancel();
     
    private:
	    AgentDialog* uiDialog;   
	    QMap<QString,QString> input_map;
	    bool b_loginputrequest;
	    
	    void createInputMap(const QMap<QString,QVariant>&); 
	    
	  public:
			inline void setWhatsThisIcon(QIcon icon) {uiDialog->setWhatsThisIcon(icon);}  
};    

#endif
