/****************** gen_conf_ed.cpp ***********************************

Code to edit already existing config files

Copyright (C) 2016-2023
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
# include <QDBusMessage>
# include <QDBusConnection>
# include <QDBusInterface>
# include <QMessageBox>
# include <QVariant>
# include <QFileInfo>

# include "./gen_conf_ed.h"
# include "../resource.h"
# include "./code/trstring/tr_strings.h"

// Function to execute a process which may modify a /cmst/config file
// in /var/lib/connman or /var/lib/connman-vpn.  It will send a finished(int) 
// signal when completed.  Exit codes:
//  negative number = this function never really executed
//  0 = everything completed normally
//  1 = one of the DBUS calls failed to complete
//  2 = the external process failed to start 
//  3 = the external process returned a nonzero exit code
//
//  Constructor  
GEN_Editor::GEN_Editor(QWidget* parent) : QWidget(parent)
{

  // data members
  filename.clear();
  path.clear();
  process.clear();
  args.clear();
  filecontents.clear();
  proc = NULL;
  
  // signals and slots
  connect(this, SIGNAL(readCompleted()), this, SLOT(executeProcess()));
  
  return;
 }

////////////////////////////////////////////// Public Functions /////////////////////////////////////////
//
//  Function to start the process rolling
void GEN_Editor::editInPlace(const QString& fn, const QString& ps, const QStringList& ag)
{

  // store variables
  filename = fn;
  process = ps;
  args = ag;

  // Start things off.  Once started it just keeps going.  DBUS calls are asyncronous so most
  // everhthing is called from signals connected to slots.
  this->readFile();
  
  return;
}

  
////////////////////////////////////////////// Private Functions /////////////////////////////////////////
//
//  Function to read the config file.  
void GEN_Editor::readFile()
{

  // this class only deals with config files in /var/lib/connman or /var/lib/commman-vpn
  if (filename.isEmpty()) return;
  path = "/var/lib/connman";
  if (! QFileInfo::exists(path + "/" + filename) ) {
    path.append("-vpn");
    if (! QFileInfo::exists(path + "/" + filename)) return;
    }
  
  QDBusInterface* iface_rf1 = new QDBusInterface("org.cmst.roothelper", "/", "org.cmst.roothelper", QDBusConnection::systemBus(), this);
  QList<QVariant> vlist;
    
  vlist.clear();
  vlist << QVariant::fromValue(path); 
  vlist << QVariant::fromValue(filename); 
  iface_rf1->callWithCallback(QLatin1String("readFile"), vlist, this, SLOT(storeContents(const QString&)), SLOT(callbackErrorHandler(QDBusError)));    
  iface_rf1->deleteLater();
  
  return;
}

//
//  Function to write the config file
void GEN_Editor::writeFile()
{
  QDBusInterface* iface_wf1 = new QDBusInterface("org.cmst.roothelper", "/", "org.cmst.roothelper", QDBusConnection::systemBus(), this);
  QList<QVariant> vlist;
    
  vlist.clear();
  vlist << QVariant::fromValue(path); 
  vlist << QVariant::fromValue(filename); 
  vlist << QVariant::fromValue(filecontents.join('\n'));
  iface_wf1->callWithCallback(QLatin1String("saveFile"), vlist, this, SLOT(writeCompleted(qint64)), SLOT(callbackErrorHandler(QDBusError)));   
  iface_wf1->deleteLater();

  return;
}

/////////////////////////////////////////////// Private Slots /////////////////////////////////////////////
//
//  Slot to store the contenents of a file as a string
void GEN_Editor::storeContents(const QString& data)
{
  // store the filecontents
  filecontents = data.split('\n');
  emit readCompleted();

  return;
}

//
// Slot to execute the process.  
void GEN_Editor::executeProcess()
{
  proc = new QProcess(this);
  proc->start(process, args);
  if (! proc->waitForStarted() ) {
    emit finished(2);
    return;
  }

  connect (proc, SIGNAL(finished(int)), this, SLOT(processExitCode(int)));

  return; 

}

//
// Slot to process the return codes from executeProcess
void GEN_Editor::processExitCode(int exitcode)
{
  if (exitcode == 0) {
    changed = QString(proc->readAll()).split('\n');
    editBuffer();   
  }
  else
    emit (finished(3));

  return;
}
 

//
//  Slot to edit the buffer containing the contents of the config file.  Connected to  processExitCode() function
void GEN_Editor::editBuffer()
{
  if (changed.size() > 0 ) {
    for (int i = 0; i < filecontents.size(); ++i) {
      if (filecontents.at(i).size() == 0) {
	filecontents.removeAt(i);
	continue;
	}
      for (int j = 0; j < changed.size(); ++j) {
	if (changed.at(j).size() == 0) {
	  changed.removeAt(j);
	  continue;
	  }
	if(filecontents.at(i).split('=').at(0).simplified() == changed.at(j).split('=').at(0).simplified()) {
	  filecontents.removeAt(i);
	  filecontents.insert(i, changed.at(j));
	  changed.removeAt(j);
	}	// if
      }// j for
    } // i for
    if (changed.size() > 0) filecontents.append(changed);
    
    this->writeFile();
  } // if we changed something

  else emit finished(0);

  return;
}

//
//
void GEN_Editor::writeCompleted(qint64 bytes)
{
  // create message showing the results of the write
  // we may or may not display it.
  QString msg;
  
  if (bytes < 0 )
    msg = tr("File save failed.");
  else {
    if (bytes > 1024)
      msg = tr("%L1 KB written").arg(bytes / 1024);
    else  
      msg = tr("%L1 Bytes written").arg(bytes);
  }
  
  emit finished(0);

  return;
}

//
// Slot to handle errors from callWithCallback functions
void GEN_Editor::callbackErrorHandler(QDBusError err)
{
  QMessageBox::critical(this,
    QString(TranslateStrings::cmtr("cmst")) + tr(" Critical"),
    QString(tr("<b>DBus Error Name:</b> %1<br><br><b>String:</b> %2<br><br><b>Message:</b> %3")).arg(err.name()).arg(err.errorString(err.type())).arg(TranslateStrings::cmtr(err.message()) ),
    QMessageBox::Ok,
    QMessageBox::Ok);
 
  emit finished(1);

  return;
}


