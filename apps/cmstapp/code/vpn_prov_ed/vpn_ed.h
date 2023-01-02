/**************************** vpn_ed.h ***************************

Code to manage the VPN Provisioning Editor dialog.

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

# ifndef VPN_PROVISIONING_EDITOR_H
# define VPN_PROVISIONING_EDITOR_H

# include <QDialog>
# include <QWhatsThis>
# include <QMenuBar>
# include <QMenu>
# include <QStatusBar>
# include <QActionGroup>
# include <QButtonGroup>
# include <QLabel>
# include <QLineEdit>
# include <QDialogButtonBox>
# include <QString>
# include <QStringList>
# include <QtDBus/QtDBus>

# include "ui_vpn_prov_editor.h"

//  The class to control the properties editor UI based on a QDialog
class VPN_Editor : public QDialog
{
  Q_OBJECT

  public:
    VPN_Editor(QWidget*, const float&);

  private:
  // members
    Ui::VPN_Prov ui;
    int i_sel;
    QMenuBar* menubar;
    QMenu* menu_global;
    QMenu* menu_OpenConnect;
    QMenu* menu_OpenVPN;
    QMenu* menu_VPNC;
    QMenu* menu_L2TP;
    QMenu* menu_PPTP;
    QMenu* menu_WireGuard;
    QActionGroup* group_provider;
    QActionGroup* group_freeform;
    QActionGroup* group_combobox;
    QActionGroup* group_yes;
    QActionGroup* group_validated;
    QActionGroup* group_selectfile;
    QActionGroup* group_template;
    QButtonGroup* bg01;
    QStatusBar* statusbar;
    int statustimeout;

  private slots:
    void inputSelectFile(QAction*);
    void inputValidated(QAction*, QString s = QString());
    void inputComboBox(QAction*);
    void inputYes(QAction*);
    void inputFreeForm(QAction*, QString s = QString());
    void showWhatsThis();
    void resetPage();
    void requestFileList(QAbstractButton*);
    void processFileList(const QStringList&);
    void seedTextEdit(const QString&);
    void deleteCompleted(bool);
    void writeCompleted(qint64);
    void callbackErrorHandler(QDBusError);
    void createProvider(QAction*);
    void importOpenVPN();

  public:
    inline void setWhatsThisIcon(QIcon icon) {ui.toolButton_whatsthis->setIcon(icon);}
    inline void setIconSize (float sz) {ui.toolButton_whatsthis->setIconSize(ui.toolButton_whatsthis->icon().actualSize(QSize(16,16) *= sz) ); }
};


#endif
