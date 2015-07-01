/**************************** iconman.cpp ******************************

Class to manage icons and allow the user to provide substitutions based
on the the system theme. 

Copyright (C) 2015
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

# include "./iconman.h"

# include <QDir>
# include <QFile>
# include <QFileInfo>
# include <QTextStream>
# include <QDebug>
# include <QList>

// Constructor
IconManager::IconManager(QObject* parent) : QObject(parent) 
{
	// Set the cfg member (path to ${home}/.config/cmst
	// APP defined in resource.h
	cfg = QString(qPrintable(QDir::homePath().append(QString("/.config/%1/%1.icon").arg(QString(APP).toLower()))) );	
	
	// Set the qrc data member
	qrc = QString(qPrintable(QString(":/text/text/icon_def.txt")) );
	
	// Initialize icon_map
	icon_map.clear();
	
	// Make the local conf file if necessary
	this->makeLocalFile();	
	
	// Create the icon_ map.   
	QFile f1(cfg);
	if (!f1.open(QIODevice::ReadOnly | QIODevice::Text)) {
		#if QT_VERSION >= 0x050400 
			qCritical("Error opening icon_def file: %s", qUtf8Printable(cfg) );
		# else	
			qCritical("Error opening icon_def file: %s", qPrintable(cfg) );
		# endif
	}
			
	QTextStream in(&f1);
	QString line;
	while (!in.atEnd()) {
		line = in.readLine();
		line = line.simplified();
		if (line.startsWith("[icon]", Qt::CaseInsensitive) ) {
			IconElement ie;
			QString iconame;
			do {
				line = in.readLine();
				if (line.startsWith("icon_name", Qt::CaseInsensitive) ) iconame = extractValue(line);
					else if (line.startsWith("resource", Qt::CaseInsensitive) ) ie.resource_path = extractValue(line);
						else if (line.startsWith("fdo_name", Qt::CaseInsensitive) ) ie.fdo_name = extractValue(line);
							else if (line.startsWith("theme_names", Qt::CaseInsensitive) ) ie.name_list = extractValue(line).split(',', QString::SkipEmptyParts) ;
			} while ( ! line.isEmpty() );
		
			icon_map[iconame] = ie;
		}	// if [icon]
	}	// while not atEnd()
	f1.close();
	
	return;
}

////////////////////////////// Public Functions ////////////////////////////
//
// Function to return a QIcon based on the name provided
QIcon IconManager::getIcon(const QString& name)
{
	// Data members
	IconElement ie = icon_map.value(name);
	QIcon ico;
	
	// If the internal theme is being used (and the user has not
	// messed up the local config file) use that first.
	if (QIcon::themeName() == INTERNAL_THEME) {
		if (buildResourceIcon(ico, ie.resource_path) )
			return ico;
	}	// if using internal theme
	
	// Next look for a user specified theme icon
	if (ie.name_list.size() > 0 ) {
		for (int i = 0; i < ie.name_list.size(); ++i) {
			if (buildThemeIcon(ico, ie.name_list.at(i) )  )
				return ico;
		}	// for
	}	// if name_list.size() > 0
	
	// Next look for a freedesktop.org named icon
	if (! ie.fdo_name.isEmpty() ) {
		if (buildThemeIcon(ico, ie.fdo_name) )
			return ico;
	}	// if freedesktop name not empty
			
	// Then look for hardcoded name in the users config dir
	if (buildResourceIcon(ico, ie.resource_path) )
		return ico;
	
	// Last stop is our fallback hard coded into the program
	 buildResourceIcon(ico, getFallback(name) );
		return ico;
}

//
// Function to return a QString containing the icon theme name or resource path
QString IconManager::getIconName(const QString& name)
{
	// Data members
	IconElement ie = icon_map.value(name);
	
	// If the internal theme is being used (and the user has not
	// messed up the local config file) use that first.
	if (QIcon::themeName() == INTERNAL_THEME ) {
		const QString res_path = ie.resource_path.section('|', 0, 0).simplified();
		if (QFileInfo(res_path).exists() )
			return res_path;
	}	// if using internal theme
	
	// Next look for a user specified theme icon
	if (ie.name_list.size() > 0 ) {
		for (int i = 0; i < ie.name_list.size(); ++i) {
			QString theme_icon = ie.name_list.at(i).section('|', 0, 0).simplified(); 
			if (QIcon::hasThemeIcon(theme_icon) )
				return theme_icon;
		}	// for		
	}	// if namelist contains entries
	
	// Next look for a freedesktop.org named icon
	if (! ie.fdo_name.isEmpty() ) {
		QString theme_icon = ie.fdo_name.section('|', 0, 0).simplified();
		if (QIcon::hasThemeIcon(theme_icon) )
			return theme_icon;
	}	// if freedesktop name not empty
		
	// Then look for hardcoded name in the users config dir
	if (! ie.resource_path.isEmpty() ) {
		const QString res_path = ie.fdo_name.section('|', 0, 0).simplified();
		if (QFileInfo(res_path).exists() )
			return  res_path;
	}
	
	// Last stop is our fallback hard coded into the program
	const QString res_path = getFallback(name).section('|', 0, 0).simplified();
	return res_path;
 }

////////////////////////////// Private Functions ////////////////////////////
//
// Function to make an icon from resource file(s).  A reference to the Icon
// is sent to this function and is modified by this function.  If the name
// argument contains a comma the name to the left is used for the on state
// and the next name is used for the off state.  Additional text is ignored.
// return true if we could find the resource files
bool IconManager::buildResourceIcon(QIcon& icon, const QString& name)
{
	const QString name_on = name.section('|',  0, 0).simplified();
	const QString name_off = name.section('|', 1, 1).simplified();
	
	// check to see if the names exist, if they do build the icon
	if (QFileInfo(name_on).exists() ) {
		if (! name_off.isEmpty() ) {
			if (QFileInfo(name_off).exists() )
				icon.addPixmap(name_off, QIcon::Normal, QIcon::Off);
			else
				return false;
		}	// if name_off not empty
		
		icon.addPixmap(name_on, QIcon::Normal, QIcon::On);
		return true;
	}	// if name_on exists
		
	return false;
}


//
// Function to make an icon from theme file(s).  A reference to the Icon
// is sent to this function and is modified by this function.  If the name
// argument contains a comma the name to the left is used for the on state
// and the next name is used for the off state.  Additional text is ignored.
// return true if we could find the theme files
bool IconManager::buildThemeIcon(QIcon& icon, const QString& name)
{
	const QString name_on = name.section('|',  0, 0).simplified();
	const QString name_off = name.section('|', 1, 1).simplified();	
	
	// check to see if the names exist, if they do build the icon
	if (QIcon::hasThemeIcon(name_on) ) {
		QList<QSize> sizes;
		if (! name_off.isEmpty() ) {
			if (QIcon::hasThemeIcon(name_off) ) {
				sizes = QIcon::fromTheme(name_off).availableSizes(QIcon::Normal, QIcon::On);
				for (int i = 0; i < sizes.count(); ++i) {
					QPixmap pix02 = QIcon::fromTheme(name_off).pixmap(sizes.at(i), QIcon::Normal, QIcon::On);
					icon.addPixmap(pix02, QIcon::Normal, QIcon::Off);
				}	//for
			}	// if name_off
			else
				return false;
		}	// if name_off not empty	
		
		sizes = QIcon::fromTheme(name_on).availableSizes(QIcon::Normal, QIcon::On);
		for (int i = 0; i < sizes.count(); ++i) {
			QPixmap pix01 = QIcon::fromTheme(name_on).pixmap(sizes.at(i), QIcon::Normal, QIcon::On);
			icon.addPixmap(pix01, QIcon::Normal, QIcon::On);
		}	// for
		return true;
	}	// if name_on exists
		
	return false;
}		
	  
//
// Function to return the resource name of an icon. Read from the resource file
// and only used in case the user has totally messed up his local copy of the
// cmst.icon file
QString IconManager::getFallback(const QString& name)
{
	// Variables
	QString rtnstr = QString();
	
	// Open the resource file for reading
	QFile f0(qrc);	
	if (!f0.open(QIODevice::ReadOnly | QIODevice::Text)) {
	#if QT_VERSION >= 0x050400 
		qCritical("Error opening resource file: %s", qUtf8Printable(qrc) );
	#else	
			qCritical("Error opening resource file: %s", qPrintable(qrc) );		
	#endif	
		return rtnstr;
	}
	
	// Look for icon in the resource file and extract the resource value
	QTextStream in(&f0);
	QString line;
	while (!in.atEnd()) {
		line = in.readLine();
		line = line.simplified();
		if (line.startsWith("[icon]", Qt::CaseInsensitive) ) {
			QString key = "";
			QString val = "";
			do {
				line = in.readLine();
				if (line.startsWith("icon_name", Qt::CaseInsensitive) )	key = extractValue(line);
				else if (line.startsWith("resource", Qt::CaseInsensitive) )	val = extractValue(line);
			} while ( key.isEmpty() || val.isEmpty() );
			if (key == name) {
				rtnstr = val;
				break;
			}	// key = name
		}	// if [icon]
	}	// while not atEnd()
	f0.close();	
	
	return rtnstr;
}

//
// Function to make a local version of the configuration fiqle
void IconManager::makeLocalFile()
{
	// if the conf file exists return now
	if (QFileInfo::exists(cfg) )
		return;
		
		
	// make the directory if it does not exist and copy the hardconded
	// conf file to the directory
	QDir d;
	if (d.mkpath(QFileInfo(cfg).path()) ) {
		QFile s(qrc);	
		if (s.copy(cfg) ) 
			QFile::setPermissions(cfg, QFileDevice::ReadOwner | QFileDevice::WriteOwner);
		else	
		#if QT_VERSION >= 0x050400 
			qCritical("Failed copying the icon definition file from %s to %s", qUtf8Printable(qrc), qUtf8Printable(cfg) );
		#else	
			qCritical("Failed copying the icon definition file from %s to %s", qPrintable(qrc), qPrintable(cfg) );		
		#endif
	}	// if mkpath returned ture			
  
	return;
}

//
// Function to extract the value in the data line.  The value is the part
// after the = sign, with all white space and comments removed.  Argument
// sv is the entire line containing the value.
QString IconManager::extractValue(const QString& sv)
{
	QString s = sv.section('=', 1, 1);
	s = s.section("#", 0, 0);
	
	return s.simplified();
}

//
// Function to extract the key in the data line.  The key is the part
// before the = sign, with all white space removed.  Argument sk is the 
// entire line containing the key
QString IconManager::extractKey(const QString& sk)
{
	QString s = sk.section('=', 0, 0);
	
	return s.simplified();
}



