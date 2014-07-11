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
# include <QIcon>

//	Used for enum's local to this program
namespace Nc
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
			inline void setSummary(QString s) {s_summary = s;}
			inline QString getSummary() {return s_summary;}
			inline void setAppName(QString s) {s_app_name = s;}
			inline QString getAppName() {return s_app_name;}
			inline void setBody(QString s) {s_body = s;}
			inline QString getBody() {return s_body;}
			inline void setIcon(QString s) {s_icon = s;}
			inline QString getIcon() {return s_icon;}
			inline void setUrgency(int i) {i_urgency = i;}
			inline int getUrgency() {return i_urgency;}
			inline void setExpireTimeout(int i) {i_expire_timeout = i;}
			inline void setOverwrite(bool b) {b_overwrite = b;}
			
			void init();
			void notify	(QString, 
									quint32,
									QString,
									QString,
									QString,
									QStringList,
									QVariantMap hint,
									qint32 expire_timeout = -1);
			void sendNotification();																

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
			QString s_summary;
			QString s_app_name;
			QString s_body;
			QString s_icon;
			int i_urgency;
			int i_expire_timeout;
			bool b_overwrite;
			
			// functions
			void getServerInformation();
			void getCapabilities();
			void closeNotification(quint32);
			
		private slots:
			void notificationClosed(quint32, quint32);
			void actionInvoked(quint32, QString);

};    

#endif
