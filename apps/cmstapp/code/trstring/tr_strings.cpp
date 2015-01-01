/**************************** tr_strings.cpp ***************************

Class to manage and present strings that need to be translated. These
are typically not inline strings, rather strings used globally or strings
returned by third parties, for instance, Connman.

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

# include <QStringList>

# include "./tr_strings.h"

// Constructor
TranslateStrings::TranslateStrings(QObject* parent) : QObject(parent) 
{
	// The stringlist is not actually used for anything other than a means
	// to mark strings for translation.  
	QStringList sl;
	sl.clear();
	
	// Global strings
	sl << tr("connman system tray", "Main Window Title");
	sl << tr("cmst", "Abbreviated Program Name - used for QMessageBox titles");
	
	// Connman strings
	sl << tr("idle", "connman state string");
  sl << tr("association", "connman state string");
  sl << tr("configuration", "connman state string");
  sl << tr("ready", "connman state string");
  sl << tr("online", "connman state string");
  sl << tr("disconnect", "connman state string");
  sl << tr("failure", "connman state string");
  sl << tr("offline", "connman state string");

  sl << tr("system", "connman type string");
  sl << tr("ethernet", "connman type string");
  sl << tr("wifi", "connman type string");
  sl << tr("bluetooth", "connman type string");
  sl << tr("cellular", "connman type string");
  sl << tr("gps", "connman type string");
  sl << tr("vpn", "connman type string");
  sl << tr("gadget", "connman type string");
  sl << tr("p2p", "connman type string");
  sl << tr("wired", "connman type string");

  sl << tr("direct", "connman proxy string");
  sl << tr("manual", "connman proxy string");
  sl << tr("auto", "connman proxy string");
  
  sl << tr("psk", "connman security string");
  sl << tr("ieee8021x", "connman security string");
  sl << tr("none", "connman security string");
  sl << tr("wep", "connman security string");
  	
	return;
}


