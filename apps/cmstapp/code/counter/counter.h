/**************************** counter.h **********************************

Code for the connection counter registered on DBus.  When registered the
connman daemon will communicate to this object with signals.

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


# ifndef CONNMANCOUNTER
#	define CONNMANCOUNTER

# include <QObject>
# include <QString>
# include <QVariantMap>
# include <QtDBus/QDBusObjectPath>

# define CNTR_SERVICE "org.cmst"
# define CNTR_INTERFACE "net.connman.Counter"
# define CNTR_OBJECT "/org/cmst/Counter"


class ConnmanCounter : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", CNTR_INTERFACE)
 
    public:
			ConnmanCounter(QObject*);
			QString getLabel(const QVariantMap&);
			inline int cnxns() {return receivers(SIGNAL(usageUpdated(const QDBusObjectPath&, const QString&, const QString&)));}
							
		signals:
			void usageUpdated(const QDBusObjectPath&, const QString&, const QString&);	
 
    public Q_SLOTS:
      void Release();
			void Usage(QDBusObjectPath, QVariantMap, QVariantMap);
     
    private:
			QVariantMap home_data;
			QVariantMap roam_data;
};    

#endif
