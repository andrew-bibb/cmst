/**************************** notify.h **********************************

Code for a notify client to interface with a desktop notification 
server.

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


# ifndef NOTIFY_CLIENT
#	define NOTIFY_CLIENT

# include <QObject>
# include <QString>
# include <QStringList>
# include <QtDBus/QDBusObjectPath>


class NotifyClient : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.freedesktop.Notifications")
 
    public:
			NotifyClient(QObject*);

		//signals:
			//NotificationClosed();
			//NotificationClosed(quint32, quint32);
 
    public Q_SLOTS:
     
    //private:
    //QStringList GetCapabilities();
    //quint32 Notify (QString, quint32, QString, QString, QString, QStringList, QVariantMap, qint32);
    void CloseNotifications(quint32 id = 0);
    void GetServerInformation (QString, QString, QString, QString);
   // QStringList GetCapabilities()
    
    private:
			// members
			QString s_name;
			QString s_vendor;
			QString s_version;
			QString s_spec_version;
			QStringList sl_capabilities;

};    

#endif
