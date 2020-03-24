/**************************** gen_conf_ed.h ***************************

Code to edit already existing config files

Copyright (C) 2016-2020
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

# ifndef GEN_CONFIG_EDITOR_H
# define GEN_CONFIG_EDITOR_H

# include <QWidget>
# include <QString>
# include <QStringList>
# include <QtDBus/QtDBus>


// Class to edit already existing config files in place 
class GEN_Editor : public QWidget
{
  Q_OBJECT

  public:
    GEN_Editor(QWidget*);
    void editInPlace(const QString&, const QString&, const QStringList&);

  private:  
  // members
    QStringList filecontents;
    QString filename;
    QString path;
    QString process;
    QStringList args;
    QStringList changed;
    QProcess* proc;

  //functions  
    void readFile();
    void writeFile();

  private slots:
    void storeContents(const QString&);
    void executeProcess();
    void processExitCode(int);
    void editBuffer();
    void writeCompleted(qint64);
    void callbackErrorHandler(QDBusError);

  signals:
    void readCompleted();
    void finished(int exitcode = -1);
        
};


#endif
