
/**************************** notify.cpp ******************************** 

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

# include <QtCore/QDebug>
# include <QtDBus/QDBusConnection>
#	include "./code/notify/notify.h"
# include <QTextDocument>
                     
#define DBUS_SERVICE "org.freedesktop.Notifications"
#define DBUS_PATH "/org/freedesktop/Notifications"
#define DBUS_INTERFACE "org.freedesktop.Notifications"

//	constructor
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

	// Create our client and connect to the notify server 	
	if (! QDBusConnection::sessionBus().isConnected() ) qCritical("CMST - Cannot connect to the session bus.");
  else {	
		notifyclient = new QDBusInterface(DBUS_SERVICE, DBUS_PATH, DBUS_INTERFACE, QDBusConnection::sessionBus(), this); 
		if (notifyclient->isValid() ) {
			getServerInformation();
			getCapabilities();	
			QDBusConnection::sessionBus().connect(DBUS_SERVICE, DBUS_PATH, DBUS_INTERFACE, "NotificationClosed", this, SLOT(notificationClosed(quint32, quint32)));
			QDBusConnection::sessionBus().connect(DBUS_SERVICE, DBUS_PATH, DBUS_INTERFACE, "ActionInvoked", this, SLOT(actionInvoked(quint32, QString)));
			b_validconnection = true;
		}	// if connection is valid
	}	// else could connect to the sessionBus
		
	return;		
}


/////////////////////////////////////// PUBLIC FUNCTIONS ////////////////////////////////
//
// Function to send a notification to the server.  This is basically a one to one correspondence
// of arguments to the org.freedesktop.Notifications.Notify method.  The arguments are mandatory
// and must be arranged from outside this class. The getxxx functions may be used to obtain server
// information for this purpose.
void NotifyClient::notify (QString app_name, quint32 replaces_id, QString app_icon, QString summary, QString body, QStringList actions, QVariantMap hints, qint32 expire_timeout)
{
	// make sure we have a connection we can send the notification to.
	if (! b_validconnection) return;
	
	QDBusReply<quint32> reply = notifyclient->call(QLatin1String("Notify"), app_name, replaces_id, app_icon, summary, body, actions, hints, expire_timeout);
	
	if (reply.isValid() )
		current_id = reply.value();
	else
		qCritical("CMST - Error reply received to the Notify method: %s", qPrintable(reply.error().message()) );
	
	return;
}		

// Convienence functions to send notifications.  These functions so some processing
// of the arguments.  In these functions:
//		expire_timeout: The amount of time in milliseconds the message is shown.
//										A value of -1 means timeout is based on server's settings.
//		overwrite			: Will overwrite the previous message sent from this function.
//										It will not overwrite notifications sent by other programs. 
//
//	
//
//	Show notification with summary string
void NotifyClient::sendNotification (QString arg_summary, int urgency, bool overwrite,  qint32 expire_timeout)
{
	// make sure we have a connection we can send the notification to.
	if (! b_validconnection) return;	
	
	// variables
	QString app_name = "";
	quint32 replaces_id = 0;
	QString app_icon = "";
	QString summary = arg_summary;
	QString body = "";
	QStringList actions = QStringList();
	QVariantMap hints;
	
	// set replaces_id
	if (overwrite) replaces_id = current_id;
	
	// assemble the hints
	hints.insert("urgency", QVariant::fromValue(static_cast<uchar>(urgency)) );
	
	QDBusReply<quint32> reply = notifyclient->call(QLatin1String("Notify"), app_name, replaces_id, app_icon, summary, body, actions, hints, expire_timeout);
	
	if (reply.isValid() )
		current_id = reply.value();
	else
		qCritical("CMST - Error reply received to the Notify method: %s", qPrintable(reply.error().message()) );
	
	return;
}	

//
// Show notification with summary and app_name
void NotifyClient::sendNotification (QString arg_summary, QString arg_app_name, int urgency, bool overwrite,  qint32 expire_timeout)
{
	// make sure we have a connection we can send the notification to.
	if (! b_validconnection) return;	
	
	// variables
	QString app_name = arg_app_name;
	quint32 replaces_id = 0;
	QString app_icon = "";
	QString summary = arg_summary;
	QString body = "";
	QStringList actions = QStringList();
	QVariantMap hints;
	
	// set replaces_id
	if (overwrite) replaces_id = current_id;
	
	// assemble the hints
	hints.insert("urgency", QVariant::fromValue(static_cast<uchar>(urgency)) );
	
	QDBusReply<quint32> reply = notifyclient->call(QLatin1String("Notify"), app_name, replaces_id, app_icon, summary, body, actions, hints, expire_timeout);
	
	if (reply.isValid() )
		current_id = reply.value();
	else
		qCritical("CMST - Error reply received to the Notify method: %s", qPrintable(reply.error().message()) );
	
	return;
}	

//
// Show notification with summary, app_name, and body text
void NotifyClient::sendNotification (QString arg_summary, QString arg_app_name, QString arg_body, int urgency, bool overwrite,  qint32 expire_timeout)
{
	// make sure we have a connection we can send the notification to.
	if (! b_validconnection) return;	
	
	// variables
	QString app_name = arg_app_name;	
	quint32 replaces_id = 0;
	QString app_icon = "";
	QString summary = arg_summary;
	QString body = "";
	QStringList actions = QStringList();
	QVariantMap hints;
	
	// set replaces_id
	if (overwrite) replaces_id = current_id;
	
	// assemble the hints
	hints.insert("urgency", QVariant::fromValue(static_cast<uchar>(urgency)) );
	
	// make sure we can display the text on this server
	if (sl_capabilities.contains("body", Qt::CaseInsensitive) ) {
		body = arg_body; 
		if (! sl_capabilities.contains ("body-markup", Qt::CaseInsensitive) ) {
			QTextDocument td;
			td.setHtml(body);
			body = td.toPlainText();
		}	// if server cannot display markup
	}	// if capabilities contains body
			
	QDBusReply<quint32> reply = notifyclient->call(QLatin1String("Notify"), app_name, replaces_id, app_icon, summary, body, actions, hints, expire_timeout);
	
	if (reply.isValid() )
		current_id = reply.value();
	else
		qCritical("CMST - Error reply received to the Notify method: %s", qPrintable(reply.error().message()) );
	
	return;
}	
	
/////////////////////////////////////// PRIVATE FUNCTIONS////////////////////////////////
//
//	Function to get information about the server
void NotifyClient::getServerInformation()
{
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
			qCritical("CMST - Error reply received to GetServerInforation method: %s", qPrintable(reply.errorMessage()) );
	}	// else some error occured
	

	return;
}

//
// Function to get the capabilities of the server
void NotifyClient::getCapabilities()
{
	QDBusReply<QStringList> reply = notifyclient->call(QLatin1String("GetCapabilities") );

	if (reply.isValid()) 
		sl_capabilities = reply.value();
	else
		qCritical("CMST - Error reply received to GetCapabilities method: %s", qPrintable(reply.error().message()) );
	
	return;
}

//
//	Function to force a close of a notification
void NotifyClient::closeNotification(quint32 id)
{
	QDBusMessage reply = notifyclient->call(QLatin1String("CloseNotification", id));
	
	if (reply.type() == QDBusMessage::InvalidMessage)
		qCritical("CMST - Invalid reply received to CloseNotification method.");
	
	else if (reply.type() == QDBusMessage::ErrorMessage) 
		qCritical("CMST - Error reply received to CloseNotification method: %s", qPrintable(reply.errorMessage()) );
	
	return;
}

/////////////////////////////// PRIVATE SLOTS /////////////////////////////////////
//
// Slot called when a notification was closed
// Right now we don't do anything with the information
void NotifyClient::notificationClosed(quint32 id, quint32 reason)
{
	
	//qDebug() << "Notification closed signal received" << id << reason; 
	
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
