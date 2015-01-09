/**************************** main.cpp *********************************

C++ main routine.  

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
# include <QApplication>
# include <QCommandLineOption>
# include <QCommandLineParser>
# include <QStringList>
# include <QStyleFactory>
# include <QLocalSocket>
# include <signal.h>   

# include "./control_box/controlbox.h"
# include "../resource.h" 


// Create a signal handler to catch ^C from console
void signalhandler(int sig) {
  if(sig==SIGINT) {
    qApp->quit();
  }
  
  return;
}

int main(int argc, char *argv[])
{  
  QApplication::setApplicationName(LONG_NAME);
  QApplication::setApplicationVersion(VERSION);
  QApplication::setOrganizationName(ORG); 
  QApplication::setDesktopSettingsAware(true);
  QApplication app(argc, argv);   
  
  // make sure only one instance is running
  QLocalSocket* socket = new QLocalSocket();
  socket->connectToServer(SOCKET_NAME);
  bool b_connected = socket->waitForConnected(500);
  socket->abort();
  delete socket;  
  if (b_connected) { 
    qDebug() <<  QCoreApplication::translate("main.cpp", "Another running instance of CMST has been detected.  This instance is aborting");  
    return 1;
  }

  // setup the command line parser
  QCommandLineParser parser;
  parser.setApplicationDescription(QApplication::translate("main.cpp", "Connman System Tray.") );
  
  QCommandLineOption disableCounters(QStringList() << "c" << "disable-counters",
		QCoreApplication::translate("main.cpp", "[Experimental] Disable data counters.  May be used to minimize load on your system.") );
  parser.addOption(disableCounters);  
  
  QCommandLineOption disableTrayIcon(QStringList() << "d" << "disable-tray-icon",
		QCoreApplication::translate("main.cpp", "Disable the system tray icon.  May be needed for system trays not compliant with the Freedesktop.org system tray specification.") );
  parser.addOption(disableTrayIcon);  
 
  parser.addHelpOption();
  
  QCommandLineOption useIconTheme(QStringList() << "i" << "icon-theme",
		QCoreApplication::translate("main.cpp", "Use the icon theme from your system if one is defined.") );
  parser.addOption(useIconTheme); 
  
  QCommandLineOption logInputRequest(QStringList() << "l" << "log-input-request",
		QCoreApplication::translate("main.cpp", "Log the connman inputRequest for debugging purposes.") );
  parser.addOption(logInputRequest);

  QCommandLineOption startMinimized(QStringList() << "m" << "minimized",
		QCoreApplication::translate("main.cpp", "Start the GUI minimized in the system tray.") );
  parser.addOption(startMinimized);
    
  parser.addVersionOption();  
    
  QCommandLineOption waitTime(QStringList() << "w" << "wait-time",
		QCoreApplication::translate("main.cpp", "Specify the wait time in seconds before starting the system tray icon."),
		QCoreApplication::translate("main.cpp", "seconds"),
		"0" );
  parser.addOption(waitTime); 

  QCommandLineOption counterUpdateKb (QStringList() << "counter-update-kb",
		QCoreApplication::translate("main.cpp", "[Experimental] The number of kb that have to be transmitted before the counter updates."),
		QCoreApplication::translate("main.cpp", "KB"),
		"1024" );
  parser.addOption(counterUpdateKb);

  QCommandLineOption counterUpdateRate (QStringList() << "counter-update-rate",
		QCoreApplication::translate("main.cpp", "[Experimental] The interval in seconds between counter updates."),
		QCoreApplication::translate("main.cpp", "seconds"),
		"10" );
  parser.addOption(counterUpdateRate);

	// Added on 2015.01.04 to work around QT5.4 bug with transparency not always working
  QCommandLineOption fakeTransparency(QStringList() << "fake-transparency",
		QCoreApplication::translate("main.cpp", "If tray icon fake transparency is required, specify the background color to use (format: 0xRRGGBB)"),
		QCoreApplication::translate("main.cpp", "RRGGBB"),
		"0x222222" );
  parser.addOption(fakeTransparency); 

  // Added on 2014.11.24 to work around a bug where QT5.3 won't show an icon in XFCE,  My fix may not work, but keep it in for now.  If this gets fixed in 
  // QT5.4 keep the command line option so users start up commands don't break, but make it a NOP. 
  QCommandLineOption useXFCE(QStringList() << "use-xfce",
		QCoreApplication::translate("main.cpp", "Use XFCE specific code.") );
  parser.addOption(useXFCE);   
  
  // Added on 2014.12.16 to work around a similar bug where QT5.3 won't show an icon in MATE.   
  QCommandLineOption useMATE(QStringList() << "use-mate",
		QCoreApplication::translate("main.cpp", "Use MATE DE specific code.") );
  parser.addOption(useMATE); 
  
  // Setup translations   
  QTranslator qtTranslator;
  qtTranslator.load("qt_" + QLocale::system().name(),
  QLibraryInfo::location(QLibraryInfo::TranslationsPath));
  app.installTranslator(&qtTranslator);

  QTranslator cmstTranslator;
  if (cmstTranslator.load("cmst_" + QLocale::system().name(), ":/translations/translations" ) ) {  
		app.installTranslator(&cmstTranslator);	
	}
	// else use en_US as it contains Connman strings properized and some singular/plural strings
	else if (cmstTranslator.load("cmst_en_US", ":/translations/translations" ) ) {
		app.installTranslator(&cmstTranslator);	
	}

	// I'm not entirely sure we want, since I'm not sure comment out instead of removing.
  //QCommandLineOption runOnStartup(QStringList() << "run-on-startup", QCoreApplication::translate("main.cpp", "Run application when user the user logins."));
  //parser.addOption(runOnStartup);

  //QCommandLineOption noRunOnStartup(QStringList() << "no-run-on-startup", QCoreApplication::translate("main.cpp", "Do not run application when user the user logins."));
  //parser.addOption(noRunOnStartup);
	  	
  // Make sure all the command lines can be parsed 
  parser.process(app);   
  QStringList sl = parser.unknownOptionNames();
  if (sl.size() > 0 ) parser.showHelp(1);

  // Make sure that mutually exclusive options are not both set
  //if (parser.isSet(runOnStartup) + parser.isSet(noRunOnStartup) > 1) {
      //parser.showHelp(1);
  //}
                
  // signal handler             
  signal(SIGINT, signalhandler);                
             
  // Showing the dialog (or not) is controlled in the createSystemTrayIcon() function
  // called from the ControlBox constructor.  We don't show it from here.             
  ControlBox ctlbox(parser);
  return app.exec(); 
}

