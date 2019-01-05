/**************************** roothelper.h *****************************

Code for the root helper registered on DBus.  When registered the CMST
provisioning editor will communicate with object using signals.  As the
name implies roothelper is run as the root user, since we need to read
and write to /var/lib/connman. This program is started by DBus and the
configuration files necessary to make that happen are in the system dir.

Copyright (C) 2013-2019
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


# ifndef ROOTHELPER
# define ROOTHELPER

# include <QObject>
# include <QString>
# include <QStringList>
# include <QtDBus/QDBusContext>

class RootHelper : public QObject, protected QDBusContext
{
  Q_OBJECT
  Q_CLASSINFO("D-Bus Interface", "org.cmst.roothelper")

  public:
    RootHelper(QObject* parent = 0);
    
  public slots:
    void startHelper();
    QStringList getFileList(const QString&);
    QString readFile(const QString&, const QString&);
    bool deleteFile(const QString& , const QString&);
    qint64 saveFile(const QString&, const QString&, const QString&);
    inline bool isConnected() {return b_connected;} // may not actually use this
    
  private:
    // members
    bool b_connected;
    
   //functions
   QString sanitizeInput(QString);
   bool pathAllowed(QString);    
};  

#endif
