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
# include <QtDBus/QtDBus>
# include <QtDBus/QDBusInterface>

//	Used for enum's local to this program
namespace NOTIFYCLIENT
{
  enum {
		// urgency levels
		UrgencyLow				= 0,
		UrgencyNormal 		= 1,
		UrgencyCritical		=	2
  };	
} // namespace		


class NotifyClient : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.freedesktop.Notifications")
 
    public:
			NotifyClient(QObject*);
			inline bool isValid() {return b_validconnection;}
			inline QString getServerName() {return s_name;}
			inline QString getServerVendor() {return s_vendor;}
			inline QString getServerVersion() {return s_version;}
			inline QString getServerSpecVersion() {return s_spec_version;}
			inline QStringList getServerCapabilities() {return sl_capabilities;}
			
			void notify	(QString app_name, 
									quint32,
									QString,
									QString,
									QString,
									QStringList,
									QVariantMap hint,
									qint32 expire_timeout = -1);
			void sendNotification (QString, int urgency = NOTIFYCLIENT::UrgencyNormal,  bool overwrite = true,  qint32 expire_timeout = -1);
			void sendNotification (QString, QString, int urgency = NOTIFYCLIENT::UrgencyNormal,  bool overwrite = true,  qint32 expire_timeout = -1);
			void sendNotification (QString, QString, QString, int urgency = NOTIFYCLIENT::UrgencyNormal,  bool overwrite = true,  qint32 expire_timeout = -1);																

    private:
			// members
			QDBusInterface* notifyclient;
			QString s_name;
			QString s_vendor;
			QString s_version;
			QString s_spec_version;
			QStringList sl_capabilities;
			bool b_validconnection;
			quint32 current_id;
			
			// functions
			void getServerInformation();
			void getCapabilities();
			void closeNotification(quint32);
			
		private slots:
			void notificationClosed(quint32, quint32);
			void actionInvoked(quint32, QString);

};    

#endif
