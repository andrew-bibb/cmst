/**************************** main.cpp *********************************

C++ main routine.  

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
# include <QApplication>
# include <QLocale>
# include <QCommandLineOption>
# include <QCommandLineParser>
# include <QStringList>
# include <QStyleFactory>
# include <QSharedMemory>

# include "./code/control_box/controlbox.h"
# include "./code/resource.h"	

// uncomment to install translation code
//#define USE_TRANSLATIONS

int main(int argc, char *argv[])
{  
	QApplication::setApplicationName(LONG_NAME);
	QApplication::setApplicationVersion(VERSION);
	QApplication::setOrganizationName(ORG);	
	QApplication::setDesktopSettingsAware(true);
	QApplication app(argc, argv);		
	
	// make sure only one instance of the program is run at a time
	QSharedMemory sharedMemory;
	sharedMemory.setKey(LONG_NAME);
	if(sharedMemory.attach()) return 1;
	else sharedMemory.create(1);

	// setup the command line parser
	QCommandLineParser parser;
	QCommandLineOption disableCounters(QStringList() << "c" << "disable-counters", QCoreApplication::translate("main.cpp", "Disable data counters.  May be used to minimize load on your system.") );
	parser.addOption(disableCounters);	
	
	QCommandLineOption disableTrayIcon(QStringList() << "d" << "disable-tray-icon", QCoreApplication::translate("main.cpp", "Disable the system tray icon.  May be needed for system trays not compliant with the Freedesktop.org system tray specification.") );
	parser.addOption(disableTrayIcon);	
	
	parser.setApplicationDescription(QApplication::translate("main.cpp", "Connman System Tray.") );
	parser.addHelpOption();
	
	QCommandLineOption useIconTheme(QStringList() << "i" << "icon-theme", QCoreApplication::translate("main.cpp", "Use the icon theme from your system if one is defined.") );
	parser.addOption(useIconTheme);	
	
	QCommandLineOption logInputRequest(QStringList() << "l" << "log-input-request", QCoreApplication::translate("main.cpp", "Log the connman inputRequest for debugging purposes.") );
	parser.addOption(logInputRequest);

	QCommandLineOption startMinimized(QStringList() << "m" << "minimized", QCoreApplication::translate("main.cpp", "Start the GUI minimized in the system tray.") );
	parser.addOption(startMinimized);
		
	parser.addVersionOption();	
	
	QCommandLineOption waitTime(QStringList() << "w" << "wait-time", QCoreApplication::translate("main.cpp", "Specify the wait time in seconds before starting the system tray icon (default is 0 seconds)."), QCoreApplication::translate("main.cpp", "wait-time"), "0" );
	parser.addOption(waitTime); 	
	   
	#ifdef USE_TRANSLATIONS
   QTranslator qtTranslator;
   qtTranslator.load("qt_" + QLocale::system().name(),
   QLibraryInfo::location(QLibraryInfo::TranslationsPath));
   app.installTranslator(&qtTranslator);

   QTranslator connmanqtTranslator;
   connmanqtTranslator.load("connmanqt_" + QLocale::system().name());
   app.installTranslator(&connmanqtTranslator);
	#endif
   
  parser.process(app);   
	QStringList sl = parser.unknownOptionNames();
	if (sl.size() > 0 ) parser.showHelp(1);
								
	// Showing the dialog (or not) is controlled in the createSystemTrayIcon() function
	// called from the ControlBox constructor.  We don't show it from here.							
	ControlBox ctlbox(parser);
	return app.exec();
}

