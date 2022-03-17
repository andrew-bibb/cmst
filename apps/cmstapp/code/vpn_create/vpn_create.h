/**************************** vpn_create.h ***************************

Code to manage the VPN Create dialog.

Copyright (C) 2022-2022
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

# ifndef VPN_CREATE_H
# define VPN_CREATE_H
# include <QDialog>
# include <QWhatsThis>
# include <QtDBus/QtDBus>

# include "ui_vpn_create.h"

//  The class to control the properties editor UI based on a QDialog
class VPN_Create : public QDialog
{
   Q_OBJECT

   public:
      VPN_Create(QWidget*, const float&);

   private:
   // members
      Ui::VPN_Create ui;

   private slots:
      void checkInput();
      void writeFile();
      void showWhatsThis();

   public:
      inline void setWhatsThisIcon(QIcon icon) {ui.toolButton_whatsthis->setIcon(icon);}
      inline void setIconSize (float sz) {ui.toolButton_whatsthis->setIconSize(ui.toolButton_whatsthis->icon().actualSize(QSize(16,16) *= sz) ); }
};


#endif
