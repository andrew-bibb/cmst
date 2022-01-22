/**************************** main.cpp *********************************

C++ main routine.

Copyright (C) 2013-2022
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

# include <QtGlobal>
# include <QtCore/QDebug>
# include <QApplication>
# include <QCommandLineOption>
# include <QCommandLineParser>
# include <QStringList>
# include <QStyleFactory>
# include <QLocalSocket>
# include <QSessionManager>
# include <QTranslator>
# include <QLibraryInfo>

# include <signal.h>

# include "./control_box/controlbox.h"
# include "../resource.h"


// Create a signal handler to catch ^C from console
void signalhandler(int sig) {
   if(sig == SIGINT || sig == SIGTERM) {
      qApp->quit();
   }

   return;
}

int main(int argc, char *argv[])
{
   // set core application attributes
   QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
//   #if QT_VERSION >= 0x050600
//   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//   #endif

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

   QCommandLineOption bypassState(QStringList() << "b" << "bypass-restore-state",
      QCoreApplication::translate("main.cpp", "Bypass restoring the window state if restoring window state is specified in the settings file.") );
   parser.addOption(bypassState);

   QCommandLineOption bypassStartOptions(QStringList() << "B" << "bypass-start-options",
      QCoreApplication::translate("main.cpp", "Bypass restoring any start options in the settings file.") );
   parser.addOption(bypassStartOptions);

   QCommandLineOption enableCounters(QStringList() << "c" << "enable-counters",
      QCoreApplication::translate("main.cpp", "[Experimental] Enable data counters.") );
   parser.addOption(enableCounters);

   QCommandLineOption disableTrayIcon(QStringList() << "d" << "disable-tray-icon",
      QCoreApplication::translate("main.cpp", "Disable the system tray icon.  May be needed for system trays not compliant with the Freedesktop.org system tray specification.") );
   parser.addOption(disableTrayIcon);

   parser.addHelpOption();

   QCommandLineOption useIconTheme(QStringList() << "i" << "icon-theme",
      QCoreApplication::translate("main.cpp", "Use an icon theme from your system."),
      QCoreApplication::translate("main.cpp", "Icon Theme Name"),
      QString("") );
   parser.addOption(useIconTheme);

   QCommandLineOption logInputRequest(QStringList() << "l" << "log-input-request",
      QCoreApplication::translate("main.cpp", "Log the connman inputRequest for debugging purposes.") );
   parser.addOption(logInputRequest);

   QCommandLineOption startMinimized(QStringList() << "m" << "minimized",
      QCoreApplication::translate("main.cpp", "Start the GUI minimized in the system tray.") );
   parser.addOption(startMinimized);

   QCommandLineOption disableMinimize(QStringList() << "M" << "disable-minimize",
      QCoreApplication::translate("main.cpp", "Disable the minimize button. Use when you want to have the window manager have sole control of minimizing the interface.") );
   parser.addOption(disableMinimize);

   QCommandLineOption disableVPN(QStringList() << "n" << "disable-vpn",
      QCoreApplication::translate("main.cpp", "Disable VPN support.") );
   parser.addOption(disableVPN);

   parser.addVersionOption();

   QCommandLineOption waitTime(QStringList() << "w" << "wait-time",
      QCoreApplication::translate("main.cpp", "Specify the wait time in seconds before starting the system tray icon."),
      QCoreApplication::translate("main.cpp", "seconds"),
      "0");
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

   # ifdef XFCE
   // Added on 2014.11.24 to work around a bug where QT5.3 won't show an icon in XFCE,  My fix may not work, but keep it in for now.  If this gets fixed in
   // QT5.4 keep the command line option so users start up commands don't break, but make it a NOP.
   QCommandLineOption useXFCE(QStringList() << "use-xfce",
      QCoreApplication::translate("main.cpp", "Use XFCE specific code.") );
   parser.addOption(useXFCE);

   // Added on 2014.12.16 to work around a similar bug where QT5.3 won't show an icon in MATE.
   QCommandLineOption useMATE(QStringList() << "use-mate",
      QCoreApplication::translate("main.cpp", "Use MATE DE specific code.") );
   parser.addOption(useMATE);
   # endif

   // Setup translations
   QTranslator qtTranslator;
   qtTranslator.load("qt_" + QLocale::system().name(),
   QLibraryInfo::location(QLibraryInfo::TranslationsPath));
   app.installTranslator(&qtTranslator);

   QTranslator cmstTranslator;
   if (cmstTranslator.load(":/i18n/cmst_" + QLocale::system().name()) ) {
      app.installTranslator(&cmstTranslator);
   }
   // else use en_US as it contains Connman strings properized and some singular/plural strings
   else if (cmstTranslator.load(":/i18n/cmst_en_US") ) {
      app.installTranslator(&cmstTranslator);
   }

   // Make sure all the command lines can be parsed
   // using parse() instead of process() as process stops on an error if an option needs a value
   // and it is not specified, even if we provide a default.  We're supposed to catch errors if we
   // use parse(), but parse.errorText() returns an empty string on this.  Bag the error checking
   // for now.
   parser.parse(QCoreApplication::arguments() );
   QStringList sl = parser.unknownOptionNames();
   if (sl.size() > 0 ) parser.showHelp(1);
   if (parser.isSet("help") ) parser.showHelp(1);
   if (parser.isSet("version") ) {
   #if QT_VERSION >= 0x050400
      parser.showVersion();
   #else
      QTextStream out(stdout);
      out << qPrintable(LONG_NAME) << " " << qPrintable(VERSION) << endl;
      return 0;
   #endif
   }

   // signal handler
   signal(SIGINT, signalhandler);

   // Showing the dialog (or not) is controlled in the createSystemTrayIcon() function
   // called from the ControlBox constructor.   We don't show it from here.
   ControlBox ctlbox(parser);
   return app.exec();
}
