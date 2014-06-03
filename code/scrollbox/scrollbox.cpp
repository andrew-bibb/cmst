/**************************** scrollbox.cpp ***************************

Dialog to display text to the user.  Kind of like a neutered QMessageBox
except it has scroll bars built in. 

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

# include "./code/scrollbox/scrollbox.h"

// constructor
// Most of the interface is defined in the ui
ScrollBox::ScrollBox(QWidget *parent)
    : QDialog(parent)
{
	
  // setup the user interface
  ui.setupUi(this);	
  
  // initialize the display text
  ui.label_displaytext->clear();
	
}  

////////////////////////////////////////////// Public Functions //////////////////////////////////////
//
void ScrollBox::execScrollBox(QString title, QString text, QWidget* parent)
{
	ScrollBox scrollBox (parent);
	scrollBox.setDisplayText(text);
	scrollBox.setWindowTitle(title);
	
	scrollBox.exec();
}

////////////////////////////////////////////////// Public Slots //////////////////////////////////////
//
//	Slot to set the display text
void ScrollBox::setDisplayText(const QString& s)
{
	ui.label_displaytext->setText(s);
	
	return;
}


