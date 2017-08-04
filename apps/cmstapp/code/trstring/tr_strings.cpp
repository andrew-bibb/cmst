/**************************** tr_strings.cpp ***************************

Class to manage and present strings that need to be translated. These
are typically not inline strings, rather strings used globally or strings
returned by third parties, for instance, Connman.

Copyright (C) 2013-2017
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
  sl << tr("wps", "connman security string");
  
  sl << tr("Invalid arguments", "connman error string");
  sl << tr("Permission denied", "connman error string");
  sl << tr("Passphrase required", "connman error string");
  sl << tr("Not registered", "connman error string");
  sl << tr("Not unique", "connman error string");
  sl << tr("Not supported", "connman error string");
  sl << tr("Not implemented", "connman error string");
  sl << tr("Not found", "connman error string");
  sl << tr("No carrier", "connman error string");
  sl << tr("In progress", "connman error string");
  sl << tr("Already exists", "connman error string");
  sl << tr("Already enabled", "connman error string");
  sl << tr("Already disabled", "connman error string");
  sl << tr("Already connected", "connman error string");
  sl << tr("Not connected", "connman error string");
  sl << tr("Operation aborted", "connman error string");
  sl << tr("Operation timeout", "connman error string");
  sl << tr("Invalid service", "connman error string");
  sl << tr("Invalid property", "connman error string");
  
  sl << tr("disabled", "connman privacy string");
  sl << tr("enabled", "connman privacy string");
  sl << tr("prefered", "connman privacy string - known misspelling but needed to avoid breaking code");
  sl << tr("preferred", "connman privacy string");
  
  sl << tr("auto", "connman ethernet connection method");
  sl << tr("manual", "connman ethernet connection method");
  
  sl << tr("dhcp", "connman ipv4 method string");
  sl << tr("manual", "connman ipv4 method string");
  sl << tr("off", "connman ipv4 method string");
  sl << tr("fixed", "connman ipv4 method string");
  
  sl << tr("auto", "connman ipv6 method string");
  sl << tr("manual", "connman ipv6 method string");
  sl << tr("6to4", "connman ipv6 method string");
  sl << tr("off", "connman ipv6 method string");
  
  sl << tr("openconnect", "connman vpn connection type");
  sl << tr("openvpn", "connman vpn connection type");
  sl << tr("vpnc", "connman vpn connection type");
  sl << tr("l2tp", "connman vpn connection type");
  sl << tr("pptp", "connman vpn connection type");
  
  	
	return;
}

//
// Function to return a stringlist with entries translated
QStringList TranslateStrings::cmtr_sl(const QStringList& sl_src)
{
	QStringList sl_rtn;
	sl_rtn.clear();
	for (int i = 0; i < sl_src.count(); ++i) {
		sl_rtn << TranslateStrings::cmtr(sl_src.at(i) );
	}

	return sl_rtn;
}

