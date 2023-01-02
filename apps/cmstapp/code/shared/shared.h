
/**************************** shared.h ***************************
Functions shared across various classes

Copyright (C) 2013-2023
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

# ifndef CMST_SHARED
# define CMST_SHARED

# include <QMessageBox>
# include <QtDBus/QDBusMessage>
# include <QtDBus/QDBusArgument>
# include <QString>
# include <QVariant>
# include <QDialogButtonBox>
# include <QLineEdit>
# include <QLabel>
# include <QPushButton>
# include <QValidator>
# include <QDBusInterface>

namespace shared {
//
// Class for an QInputDialog knockoff with validator
class ValidatingDialog : public QDialog
{
  Q_OBJECT

  public:
    ValidatingDialog(QWidget*);
    inline void setLabel(const QString& s) {label->setText(s);}
    static QString getPattern(const int&, bool plural = false);
    void setValidator(const int&, bool plural = false);
    inline QString getText() {return lineedit->text().trimmed();}
    inline void setText(const QString& s) {lineedit->setText(s);}
    inline void clear() {initialize();}
    inline bool isPlural() {return plural;}

  private slots:
		void textChanged();
		void initialize();

  private:
    // members
    QLabel* label;
    QLineEdit* lineedit;
    QDialogButtonBox* buttonbox;
    bool plural;
}; // class

QDBusMessage::MessageType processReply(const QDBusMessage& reply);
bool extractMapData(QMap<QString,QVariant>&,const QVariant&);


} // namespace
#endif
