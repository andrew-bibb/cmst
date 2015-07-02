/**************************** notify.cpp ******************************** 

Code for a notify client to interface with a desktop notification 
server.

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
# include <QtDBus/QDBusConnection>
# include <QTextDocument>
# include <QIcon>
# include <QPixmap>
# include <QTemporaryFile>
# include <QFile>

# include "./notify.h"
                     
#define DBUS_SERVICE "org.freedesktop.Notifications"
#define DBUS_PATH "/org/freedesktop/Notifications"
#define DBUS_INTERFACE "org.freedesktop.Notifications"

//  constructor
NotifyClient::NotifyClient(QObject* parent)
    : QObject(parent)
{ 
  
  // Data members
  s_name.clear();
  s_vendor.clear();
  s_version.clear();
  s_spec_version.clear();
  sl_capabilities.clear();
  b_validconnection = false;
  current_id = 0;
  file_map.clear();
  this->init();

  // Create our client and try to connect to the notify server
  if (! QDBusConnection::sessionBus().isConnected() )
    qCritical("CMST - Cannot connect to the session bus.");
  // else try to connect to a notification server
  else 
		connectToServer();
		
	// Signals and slots
	connect(qApp, SIGNAL(aboutToQuit()), this, SLOT(cleanUp()));	
    
  return;   
}


/////////////////////////////////////// PUBLIC FUNCTIONS ////////////////////////////////
//
// Function to connect to a notification server.
void NotifyClient::connectToServer()
{
	// return now if we already have a valid connection
  if (b_validconnection) return;
    
  notifyclient = new QDBusInterface(DBUS_SERVICE, DBUS_PATH, DBUS_INTERFACE, QDBusConnection::sessionBus(), this); 
  if (notifyclient->isValid() ) {
    b_validconnection = true;
    getServerInformation();
    getCapabilities();  
    QDBusConnection::sessionBus().connect(DBUS_SERVICE, DBUS_PATH, DBUS_INTERFACE, "NotificationClosed", this, SLOT(notificationClosed(quint32, quint32)));
    QDBusConnection::sessionBus().connect(DBUS_SERVICE, DBUS_PATH, DBUS_INTERFACE, "ActionInvoked", this, SLOT(actionInvoked(quint32, QString)));
    } // if connection is valid 
  else {
    notifyclient->deleteLater();
    b_validconnection = false;
  }	// else connection not valid
}
//
// Function to initialize data members that are used to hold information sent to the server
void NotifyClient::init()
{
  s_summary.clear();
  s_app_name.clear();
  s_body.clear();
  s_icon.clear();
  i_urgency = Nc::UrgencyNormal;
  i_expire_timeout = -1;
  b_overwrite = true;
  
  return;
}
  
//
// Function to send a notification to the server.  There is basically a one to one correspondence
// of arguments to the org.freedesktop.Notifications.Notify method.  The arguments are mandatory
// and must be arranged from outside this class. The getxxx functions may be used to obtain server
// information for this purpose.
///////// COMMENTED OUT SINCE WE DON'T USE IT IN CMST /////////////////////
//void NotifyClient::notify (QString app_name, quint32 replaces_id, QString app_icon, QString summary, QString body, QStringList actions, QVariantMap hints, qint32 expire_timeout)
//{
  //// make sure we have a connection we can send the notification to.
  //if (! b_validconnection) return;
  
  //QDBusReply<quint32> reply = notifyclient->call(QLatin1String("Notify"), app_name, replaces_id, app_icon, summary, body, actions, hints, expire_timeout);
  
  //if (reply.isValid() )
    //current_id = reply.value();
  //else
  	//#if QT_VERSION >= 0x050400 
  	//qCritical("CMST - Error reply received to the Notify method: %s", qUtf8Printable(reply.error().message()) );
		//#else
    //qCritical("CMST - Error reply received to the Notify method: %s", qPrintable(reply.error().message()) );
    //#endif
  
  //return;
//}   

// Convienence function to send notifications.  This function does some processing
// of the arguments.  In these functions:
//    expire_timeout: The amount of time in milliseconds the message is shown.
//                    A value of -1 means timeout is based on server's settings.
//    overwrite     : Will overwrite the previous message sent from this function.
//                    It will not overwrite notifications sent by other programs. 
//
//
// Show notification with summary, app_name, and body text
void NotifyClient::sendNotification ()
{
  // make sure we have a connection we can send the notification to.
  if (! b_validconnection) return;  
  
  // variables
  QString app_name = s_app_name;  
  quint32 replaces_id = 0;
  QString app_icon = "";
  QString body = ""; 
  QString summary = s_summary;
  QStringList actions = QStringList();
  QVariantMap hints;
  int expire_timeout = i_expire_timeout;
  
  // set replaces_id
  if (b_overwrite) replaces_id = current_id;
  
  // assemble the hints
  hints.clear();
  hints.insert("urgency", QVariant::fromValue(static_cast<uchar>(i_urgency)) );
  //if (! app_icon.isEmpty() ) hints.insert("image-path", QVariant::fromValue(app_icon));
  
  // make sure we can display the text on this server
  if (sl_capabilities.contains("body", Qt::CaseInsensitive) ) {
    body = s_body;
    if (! sl_capabilities.contains ("body-markup", Qt::CaseInsensitive) ) {
      QTextDocument td;
      td.setHtml(body);
      body = td.toPlainText();
    } // if server cannot display markup
  } // if capabilities contains body
  
  // process the icon, if we are using a fallback icon create a temporary file to hold it
    QTemporaryFile*  tempfileicon = NULL; 
    if (! s_icon.isEmpty() ) {   
			if (QFile::exists(s_icon) ) {
				tempfileicon = new QTemporaryFile(this);
				tempfileicon->setAutoRemove(false);
				if (tempfileicon->open() ) {
					QPixmap px = QPixmap(s_icon);
					px.save(tempfileicon->fileName(),"PNG");
					app_icon =  tempfileicon->fileName().prepend("file://");
				} // if tempfileicon could be opened
			} // if s_icon exists as a disk file

			// assume s_icon exists as a theme icon, don't check it here.  That
			// check needs to be done in the calling program.
			else app_icon = s_icon;
		} // if s_icon is not empty
    
  QDBusReply<quint32> reply = notifyclient->call(QLatin1String("Notify"), app_name, replaces_id, app_icon, summary, body, actions, hints, expire_timeout);
  
  if (reply.isValid() ) {
		current_id = reply.value();
    if (file_map.contains(current_id) && tempfileicon != NULL) {
			if (b_overwrite) {
				file_map.value(current_id)->remove();
				delete file_map.value(current_id);
				file_map.remove(current_id);				
			}	// if
			else {
				tempfileicon->remove();
				delete tempfileicon;
				tempfileicon = NULL;
			}	// else
		}	// if contains current_id and not NULL
		if (tempfileicon != NULL) file_map[current_id] = tempfileicon;
  }	// if reply is valid
  
  else
	#if QT_VERSION >= 0x050400 
		qCritical("CMST - Error reply received to the Notify method: %s", qUtf8Printable(reply.error().message()) );
  #else
    qCritical("CMST - Error reply received to the Notify method: %s", qPrintable(reply.error().message()) );
  #endif
  
  return;
} 
  
/////////////////////////////////////// PRIVATE FUNCTIONS////////////////////////////////
//
//  Function to get information about the server and write results to data members
void NotifyClient::getServerInformation()
{
  // return if we don't have valid connection
  if (! b_validconnection) return; 
  
  // get the server information
  QDBusMessage reply = notifyclient->call(QLatin1String("GetServerInformation"));
  
  if (reply.type() == QDBusMessage::ReplyMessage) {
    QList<QVariant> outargs = reply.arguments();
    s_name = outargs.at(0).toString();
    s_vendor = outargs.at(1).toString();
    s_version = outargs.at(2).toString();
    s_spec_version = outargs.at(3).toString();
  }
  
  else {
    if (reply.type() == QDBusMessage::InvalidMessage)
      qCritical("CMST - Invalid reply received to GetServerInformation method.");
    
    else if (reply.type() == QDBusMessage::ErrorMessage) 
    #if QT_VERSION >= 0x050400 
			qCritical("CMST - Error reply received to GetServerInforation method: %s", qUtf8Printable(reply.errorMessage()) );
    #else
      qCritical("CMST - Error reply received to GetServerInforation method: %s", qPrintable(reply.errorMessage()) );
    #endif
  } // else some error occured
  

  return;
}

//
// Function to get the capabilities of the server and write to a qstringlist data member
void NotifyClient::getCapabilities()
{
  // return if we don't have valid connection
  if (! b_validconnection) return;  
  
  // get the server capabilities
  QDBusReply<QStringList> reply = notifyclient->call(QLatin1String("GetCapabilities") );

  if (reply.isValid()) 
    sl_capabilities = reply.value();
  else
  #if QT_VERSION >= 0x050400 
		qCritical("CMST - Error reply received to GetCapabilities method: %s", qUtf8Printable(reply.error().message()) );
  #else
    qCritical("CMST - Error reply received to GetCapabilities method: %s", qPrintable(reply.error().message()) );
  #endif
  
  return;
}

//
//  Function to force a close of a notification
void NotifyClient::closeNotification(quint32 id)
{
  // return if we don't have valid connection
  if (! b_validconnection) return; 
  
  QDBusMessage reply = notifyclient->call(QLatin1String("CloseNotification"), id);
  
  if (reply.type() == QDBusMessage::InvalidMessage)
    qCritical("CMST - Invalid reply received to CloseNotification method.");
  
  else if (reply.type() == QDBusMessage::ErrorMessage) 
  #if QT_VERSION >= 0x050400 
		qCritical("CMST - Error reply received to CloseNotification method: %s", qUtf8Printable(reply.errorMessage()) );
  #else
    qCritical("CMST - Error reply received to CloseNotification method: %s", qPrintable(reply.errorMessage()) );
  #endif
  
  return;
}

/////////////////////////////// PRIVATE SLOTS /////////////////////////////////////
//
// Slot called when a notification was closed
void NotifyClient::notificationClosed(quint32 id, quint32 reason)
{
	if (file_map.contains(id) ) {
		file_map.value(id)->remove();
		delete file_map.value(id);
		file_map.remove(id);
	}	
  
  return;
}

//
// Slot called when some action from the notification is invoked
// RIght now we don't do anything with the information
void NotifyClient::actionInvoked(quint32 id, QString action_key)
{
  
  //qDebug() << "Action invoked signal received" << id << action_key;
  
  return;
}

//
// Slot to tidy up things, mainly the temp files created if we made icons
// Called when qApp issues an aboutToQuit signal
void NotifyClient::cleanUp()
{
	
	QMapIterator<quint32, QTemporaryFile*> itr(file_map);
	while (itr.hasNext()) {
    itr.next();
		file_map.value(itr.key())->remove();
		delete file_map.value(itr.key() );
		file_map.remove(itr.key() );    
}
	
	return;
}

