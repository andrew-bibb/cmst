/**************************** peditor.h ***************************

Code to manage the Properties Editor dialog.

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

# ifndef PROPERTIES_EDITOR_H
# define PROPERTIES_EDITOR_H

# include <QDialog>
# include <QMap>
# include <QVariant>
# include <QStringList>
# include <QWhatsThis>

# include "ui_peditor.h"

//	The class to control the properties editor UI based on a QDialog
class PropertiesEditor : public QDialog
{
  Q_OBJECT

  public:
  // members
    PropertiesEditor(QWidget*, QMap<QString,QVariant>);
    
  
  private:  
  // members
		Ui::Peditor ui;
		QMap<QString,QVariant> objmap;
		
	// functions
		inline QStringList getNameservers() {return objmap.value("Nameservers.Configuration").toStringList();}
		inline QStringList getTimeservers() {return objmap.value("Timeservers.Congiguration").toStringList();}
		inline QStringList getDomains() {return objmap.value("Domains.configuration").toStringList();}
		   
  private slots:
  	void showWhatsThis();
		void resetPage(int page = -1);
		void resetAll();
				
	public:
		inline void setWhatsThisIcon(QIcon icon) {ui.toolButton_whatsthis->setIcon(icon);}
};


#endif
