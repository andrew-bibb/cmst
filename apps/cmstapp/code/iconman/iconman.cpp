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
# include "../resource.h"

# include <QDir>
# include <QFile>
# include <QFileInfo>
# include <QTextStream>
# include <QStringList>
# include <QDebug>

// Constructor
IconManager::IconManager(QObject* parent) : QObject(parent) 
{
	
	// Set the filepath data member
	// APP defined in resource.h
	filepath = QDir::homePath();
	filepath.append(QString("/.config/%1").arg(QString(APP).toLower()) );	
	
	// Make the local conf file if necessary
	this->makeLocalFile();	
	
	// Create the fallback map.  The fallback map is only used in case
	// somebody removes the fallback line or the entire icon definition  
	// in their local .config file.  Read from the icon_def resource file.  
	QFile f0(qPrintable(QString(":/text/text/icon_def.txt")) );	
	if (!f0.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Error reading from icon_def resource file" ;
		return;
	}
			
	QTextStream in(&f0);
	QString line;
	while (!in.atEnd()) {
		line = in.readLine();
		line = line.simplified();
		if (line.contains("[icon]", Qt::CaseInsensitive) ) {
			QString key = "";
			QString val = "";
			do {
				line = in.readLine();
				line = line.simplified();
				if (line.startsWith("icon_name", Qt::CaseInsensitive) )	key = line.section('=', 1, 1);
				if (line.startsWith("resource", Qt::CaseInsensitive) )	val = line.section('=', 1, 1);
			} while ( key.isEmpty() || val.isEmpty() );
			fallback_map[key.simplified()] = val.simplified();
		}	// if [icon]
	}	// while not atEnd()
	f0.close();
	
	return;
}


////////////////////////////// Private Functions ////////////////////////////
//
// Function to make a local version of the configuration fiqle
void IconManager::makeLocalFile()
{
	// if the conf file exists return now
	if (QFileInfo::exists(qPrintable(QString(filepath + "/%1.icons").arg(QString(APP).toLower()))) )
		return;

	// make the directory if it does not exist and copy the hardconded
	// conf file to the directory
	QDir d;
	if (d.mkpath(filepath)) {
		QFile s(qPrintable(QString(":/text/text/icon_def.txt")) );	
		if (s.copy(qPrintable(QString(filepath + "/%1.icons").arg(QString(APP).toLower()))) )
			QFile::setPermissions(qPrintable(QString(filepath + "/%1.icons").arg(QString(APP).toLower())), QFileDevice::ReadOwner | QFileDevice::WriteOwner);
		else	
			qDebug("Failed copying the icon definition file");
	}	// if mkpath returned ture			
  
	return;
}


