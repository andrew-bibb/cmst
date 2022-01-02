/**************************** iconman.cpp ******************************

Class to manage icons and allow the user to provide substitutions based
on the the system theme.

Copyright (C) 2015-2022
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

# include "./iconman.h"

# include <QDir>
# include <QFile>
# include <QFileInfo>
# include <QTextStream>
# include <QDebug>
# include <QList>
# include <QPainter>
# include <QCryptographicHash>
# include <QSettings>
# include <QMessageBox>
# include <QProcessEnvironment>
# include <QDirIterator>
# include <QtGlobal>

// Constructor
IconManager::IconManager(QObject* parent) : QObject(parent)
{
   // Setup the config path and file name (where we the store icon_def file)
   // APP defined in resource.h
   QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
   QString home = env.value("HOME");
   cfg = QString(env.value("XDG_CONFIG_HOME", QString(QDir::homePath()) + "/.config") + "/%1/%1.icon").arg(QString(APP).toLower() );

   // Set the qrc data member
   qrc = QString(":/text/text/icon_def.txt");

   // Initialize icon_map
   icon_map.clear();

   // Make the local conf file if necessary
   this->makeLocalFile();

   // Create the icon_ map.
   QFile f1(qPrintable(cfg) );
   if (!f1.open(QIODevice::ReadOnly | QIODevice::Text)) {
      #if QT_VERSION >= 0x050400
         qCritical("Error opening icon_def file: %s", qUtf8Printable(cfg) );
      # else
         qCritical("Error opening icon_def file: %s", qPrintable(cfg) );
      # endif
   }

   QTextStream in(&f1);
   QString line;
   while (!in.atEnd()) {
      line = in.readLine();
      line = line.simplified();
      if (line.startsWith("[icon]", Qt::CaseInsensitive) ) {
         IconElement ie;
         QString iconame;
         do {
            line = in.readLine();
            if (line.startsWith("icon_name", Qt::CaseInsensitive) ) iconame = extractValue(line);
            else if (line.startsWith("resource", Qt::CaseInsensitive) ) ie.resource_path = extractValue(line);
               else if (line.startsWith("colorize", Qt::CaseInsensitive) ) ie.colorize = extractValue(line);
                  else if (line.startsWith("fdo_name", Qt::CaseInsensitive) ) ie.fdo_name = extractValue(line);
                     else if (line.startsWith("theme_names", Qt::CaseInsensitive) )

            #if QT_VERSION >= 0x050e00
               ie.theme_names = extractValue(line).split(',', Qt::SkipEmptyParts) ;
            #else
               ie.theme_names = extractValue(line).split(',', QString::SkipEmptyParts) ;
            #endif
         } while ( ! line.isEmpty() );

         icon_map[iconame] = ie;
      }  // if [icon]
   }  // while not atEnd()
   f1.close();

   return;
}

////////////////////////////// Public Functions ////////////////////////////
//
// Function to return a QIcon based on the name provided
QIcon IconManager::getIcon(const QString& name)
{
   // Data members
   IconElement ie = icon_map.value(name);
   QIcon ico = QIcon();

   // If the internal theme is being used (and the user has not
   // messed up the local config file) use that first.
   if (QIcon::themeName() == INTERNAL_THEME) {
      if (buildResourceIcon(ico, ie.resource_path, ie.colorize) )
         return ico;
   } // if using internal theme

   // Next look for a user specified theme icon
   if (ie.theme_names.size() > 0 ) {
      for (int i = 0; i < ie.theme_names.size(); ++i) {
         if (buildThemeIcon(ico, ie.theme_names.at(i) )  )
            return ico;
      }  // for
   } // if theme_names.size() > 0

   // Next look for a freedesktop.org named icon
   if (! ie.fdo_name.isEmpty() ) {
      if (buildThemeIcon(ico, ie.fdo_name) )
         return ico;
   } // if freedesktop name not empty

   // Then look for hardcoded name in the users config dir
   if (buildResourceIcon(ico, ie.resource_path, ie.colorize) )
      return ico;

   // Last stop is our fallback hard coded into the program
   buildResourceIcon(ico, getFallback(name), ie.colorize);
   return ico;
}

//
// Function to return a QString containing the fully qualified icon name or resource path
QString IconManager::getIconName(const QString& name)
{
   // Data members
   IconElement ie = icon_map.value(name);

   // If the internal theme is being used (and the user has not
   // messed up the local config file) use that first.
   if (QIcon::themeName() == INTERNAL_THEME ) {
      const QString res_path = ie.resource_path.section(' ', 0, 0).simplified();
      if (QFileInfo(res_path).exists() )
         return res_path;
   } // if using internal theme

   // Next look for a user specified theme icon
   if (ie.theme_names.size() > 0 ) {
      for (int i = 0; i < ie.theme_names.size(); ++i) {
         QString theme_icon = ie.theme_names.at(i).section('|', 0, 0).simplified();
         if (QIcon::hasThemeIcon(theme_icon) ) {
            QStringList filter_list;
            filter_list << "24x24" << "22x22" << "16x16";
            QString rtn = findQualifiedName(theme_icon, filter_list);
            if (! rtn.isEmpty() ) return rtn;
         } // if has ThemeIcon
      } // for
   } // if namelist contains entries

   // Next look for a freedesktop.org named icon
   if (! ie.fdo_name.isEmpty() ) {
      QString theme_icon = ie.fdo_name.section('|', 0, 0).simplified();
      if (QIcon::hasThemeIcon(theme_icon) ) {
         QStringList filter_list;
         filter_list << "24x24" << "22x22" << "16x16";
         QString rtn = findQualifiedName(theme_icon, filter_list);
         if (! rtn.isEmpty() ) return rtn;
      } // if has ThemeIcon
   } // if freedesktop name not empty

   // Then look for hardcoded name in the users config dir
   if (! ie.resource_path.isEmpty() ) {
      const QString res_path = ie.fdo_name.section(' ', 0, 0).simplified();
      if (QFileInfo(res_path).exists() )
         return  res_path;
   }

   // Last stop is our fallback hard coded into the program
   const QString res_path = getFallback(name).section(' ', 0, 0).simplified();
   return res_path;
}

////////////////////////////// Private Functions ////////////////////////////
//
// Function to make an icon from resource file(s).  A reference to the Icon
// is sent to this function and is modified by this function.  If the name
// argument contains a | the name to the left is used for the "on" state
// and the next name is used for the "off" state.  Additional text is ignored.
// return true if we could find the resource files
bool IconManager::buildResourceIcon(QIcon& icon, const QString& name, const QString& s_col)
{
   // constants from name
   const QString name_on = name.section('|', 0, 0).simplified();
   const QString name_off = name.section('|', 1, 1).simplified();

   // see if we need to colorize
   QColor qc_col = QColor();
   if (s_col.contains("yes", Qt::CaseInsensitive) || s_col == "1" ) qc_col = icon_color;
   else if (s_col.size() == 6) qc_col.setNamedColor(QString("#" + s_col) );


   // check to see if the names exist, if they do build the icon
   if (QFileInfo(name_on.section(' ', 0, 0)).exists() ) {
      if (! name_off.isEmpty() ) {
         if (QFileInfo(name_off.section(' ', 0, 0)).exists() )
            icon.addPixmap(processArt(name_off, qc_col), QIcon::Normal, QIcon::Off);
      } // if name_off not empty

      icon.addPixmap(processArt(name_on, qc_col), QIcon::Normal, QIcon::On);
      return true;
   } // if name_on exists

   return false;
}


//
// Function to make an icon from theme file(s).  A reference to the Icon
// is sent to this function and is modified by this function.  If the name
// argument contains a | the name to the left is used for the "on" state
// and the next name is used for the "off" state.  Additional text is ignored.
// return true if we could find the theme files
bool IconManager::buildThemeIcon(QIcon& icon, const QString& name)
{
   const QString name_on = name.section('|',  0, 0).simplified();
   const QString name_off = name.section('|', 1, 1).simplified();

   // check to see if the names exist, if they do build the icon
   if (QIcon::hasThemeIcon(name_on) ) {
      QList<QSize> sizes;
      if (! name_off.isEmpty() ) {
         if (QIcon::hasThemeIcon(name_off) ) {
            sizes = QIcon::fromTheme(name_off).availableSizes(QIcon::Normal, QIcon::On);
            for (int i = 0; i < sizes.count(); ++i) {
               QPixmap pix02 = QIcon::fromTheme(name_off).pixmap(sizes.at(i), QIcon::Normal, QIcon::On);
               icon.addPixmap(pix02, QIcon::Normal, QIcon::Off);
            } //for
         } // if name_off
         else
            return false;
      } // if name_off not empty

      sizes = QIcon::fromTheme(name_on).availableSizes(QIcon::Normal, QIcon::On);
      for (int i = 0; i < sizes.count(); ++i) {
         QPixmap pix01 = QIcon::fromTheme(name_on).pixmap(sizes.at(i), QIcon::Normal, QIcon::On);
         icon.addPixmap(pix01, QIcon::Normal, QIcon::On);
      } // for
      return true;
   } // if name_on exists

   return false;
}

//
// Function to return the resource name of an icon. Read from the resource file
// and only used in case the user has totally messed up his local copy of the
// cmst.icon file
QString IconManager::getFallback(const QString& name)
{
   // Variables
   QString rtnstr = QString();

   // Open the resource file for reading
   QFile f0(qrc);
   if (!f0.open(QIODevice::ReadOnly | QIODevice::Text)) {
   #if QT_VERSION >= 0x050400
      qCritical("Error opening resource file: %s", qUtf8Printable(qrc) );
   #else
      qCritical("Error opening resource file: %s", qPrintable(qrc) );
   #endif
      return rtnstr;
   }

   // Look for icon in the resource file and extract the resource value
   QTextStream in(&f0);
   QString line;
   while (!in.atEnd()) {
      line = in.readLine();
      line = line.simplified();
      if (line.startsWith("[icon]", Qt::CaseInsensitive) ) {
         QString key = "";
         QString val = "";
         do {
            line = in.readLine();
            if (line.startsWith("icon_name", Qt::CaseInsensitive) )  key = extractValue(line);
            else if (line.startsWith("resource", Qt::CaseInsensitive) ) val = extractValue(line);
         } while ( key.isEmpty() || val.isEmpty() );
         if (key == name) {
            rtnstr = val;
            break;
         } // key = name
      } // if [icon]
   } // while not atEnd()
   f0.close();

   return rtnstr;
}

//
// Function to make a local version of the configuration fiqle
void IconManager::makeLocalFile()
{
   // constants
   const int maxloop = 50;

   // Get information about the last installed icon def file from the settings
   QSettings* settings = new QSettings(ORG, APP, this);
   settings->beginGroup("IconManager");
  QString lastmd5 = settings->value("last_installed_icon_def_file").toString();
  settings->endGroup();

  // Get the MD5 sum of the current
  QFile src(qrc);
  src.open(QIODevice::ReadOnly);
  QCryptographicHash hash(QCryptographicHash::Md5);
  hash.addData(&src);
  src.close();
  QString currentmd5 = QString::fromLatin1(hash.result().toHex() );

   // If the user's local conf file exists
   if (QFileInfo::exists(cfg) ) {
      if (lastmd5 == currentmd5) {  // this should be the typical case
         settings->deleteLater();
         return;
      }

      // MD5 sums don't match so make a backup of the existing local file
      else {
         // Find a backup name we can use
         int ctr = 0;
         QString bak;
         do {
            bak = QString(cfg + ".%1").arg(++ctr, 2, 10, QChar('0'));
         } while (QFileInfo::exists(bak) && ctr <= maxloop);

         // Now make the backup
         QFile f_cfg(cfg);
         if (ctr <= maxloop && f_cfg.copy(bak) ) {
            QMessageBox::StandardButton dia_rtn = QMessageBox::information(0, QString(APP),
               tr("A new icon definition file will be installed to <b>%1</b> and a backup of the old definition file has been created as <b>%2</b> \
                  <p>If the original definition file was customized and you wish to retain those changes you will need to manually merge them into the new file.  \
                  <p>If the original was never customized or you just wish to delete the backup now you may select <i>Discard</i> to delete the backup or <i>Save</i> to retain it.").arg(cfg).arg(bak),
               QMessageBox::Save | QMessageBox::Discard,
               QMessageBox::Save);
            if (dia_rtn == QMessageBox::Discard)
               if (! QFile::remove(bak))
               #if QT_VERSION >= 0x050400
                  qCritical("Failed to remove the backup file: %s", qUtf8Printable(bak) );
               #else
                  qCritical("Failed to remove the backup file: %s", qPrintable(bak) );
               #endif
         }  // if creating a backup copy worked
         else {
         #if QT_VERSION >= 0x050400
            qCritical("Failed creating the icon definition backup file: %s", qUtf8Printable(bak) );
         #else
            qCritical("Failed creating the icon definition backup file: %s", qPrintable(bak) );
         #endif
            settings->deleteLater();
            return;
         }  // else creating a backup failed so return, don't continue

         // Have a backup, now create the new file
         QFile::remove(cfg);
         QFile s(qrc);
         if (s.copy(cfg) ) {
            QFile::setPermissions(cfg, QFileDevice::ReadOwner | QFileDevice::WriteOwner);
            settings->beginGroup("IconManager");
            settings->setValue("last_installed_icon_def_file", currentmd5);
            settings->endGroup();
         } // if creating new file worked
         else {
         #if QT_VERSION >= 0x050400
            qCritical("Failed creating a new icon definition file: %s", qUtf8Printable(qrc) );
         #else
            qCritical("Failed creating a new icon definition file: %s", qPrintable(qrc) );
         #endif
         } // failed creating the new file (next step is return so no reason to call it here)
      } // qrc is different than the last installed
   } // if local icon_def exists

   // Local icon_def does not exist so create the directory (if need be) and copy the icon_def file
   else {
      QDir d;
      if (d.mkpath(QFileInfo(cfg).path()) ) {
         QFile s(qrc);
         if (s.copy(cfg) ) {
            QFile::setPermissions(cfg, QFileDevice::ReadOwner | QFileDevice::WriteOwner);
            settings->beginGroup("IconManager");
            settings->setValue("last_installed_icon_def_file", currentmd5);
            settings->endGroup();
         } // if creating new file worked
         else
         #if QT_VERSION >= 0x050400
            qCritical("Failed creating a new icon definition file: %s", qUtf8Printable(qrc) );
         #else
            qCritical("Failed creating a new icon definition file: %s", qPrintable(qrc) );
         #endif
      } // if mkpath returned true
      else
      #if QT_VERSION >= 0x050400
         qCritical("Failed creating directory %s for the icon definition file.", qUtf8Printable(QFileInfo(cfg).path()) );
      #else
         qCritical("Failed creating directory %s for the icon definition file.", qPrintable(QFileInfo(cfg).path()) );
      #endif
   } // else local icon_def did not exist

   settings->deleteLater();
   return;
}

//
// Function to extract the value in the data line.  The value is the part
// after the = sign, with all white space and comments removed.  Argument
// sv is the entire line containing the value.
QString IconManager::extractValue(const QString& sv)
{
   QString s = sv.section('=', 1, 1);
   s = s.section("#", 0, 0);

   return s.simplified();
}

//
// Function to extract the key in the data line.  The key is the part
// before the = sign, with all white space removed.  Argument sk is the
// entire line containing the key
QString IconManager::extractKey(const QString& sk)
{
   QString s = sk.section('=', 0, 0);

   return s.simplified();
}

// Function to colorize an icon.  Called from buildResourceIcon and if we
// get here we've already checked that the resource exists
QPixmap IconManager::processArt(const QString& res, const QColor& color)
{
   // Extract the parts of the icon
   const QString base = res.section(' ', 0, 0);
   const QString over = res.section(' ', 1, 1);

   QImage src = QImage(base);
   QImage dest = QImage(src.width(), src.height(), QImage::Format_ARGB32);
   QPainter painter(&dest);

   // Colorize the base (if specified)
   if (color.isValid() ) {
      painter.setCompositionMode(QPainter::CompositionMode_Source);
      painter.fillRect(dest.rect(), color);
      painter.setCompositionMode(QPainter::CompositionMode_DestinationAtop);
      painter.drawImage(0, 0, src);
   }
   else {
      painter.setCompositionMode(QPainter::CompositionMode_Source);
      painter.drawImage(0, 0, src);
   }

// Now add overlays - overlay names have the same name as the icon they
// need to overlay.
   if (! over.isEmpty() ) {
      QFileInfo fi = QFileInfo(over);
      if (fi.exists() ) {
         QImage ovl = QImage(fi.absoluteFilePath() );
         painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
         painter.drawImage(0, 0, ovl);
      }
   }

   return QPixmap::fromImage(dest);
}

//
// Function to find an icon file somewhere in the system.  Return value is
// the fully qualified path to the icon file if found, a null string otherwise.
//
// iconname - the icon name to search for
// filter - a string list containing an order preference for subdirectory names to return
// to search for,
//
// Called from the getIconName function
QString IconManager::findQualifiedName(const QString& iconname, const QStringList& sl_filter)
{
   // variables
   QStringList sl_results = QStringList();

   // get search paths
   QStringList sl_dirs = QIcon::themeSearchPaths();
   if (sl_dirs.size() < 1) return QString();

   // iterate over the search paths
   for (int i = 0; i < sl_dirs.size(); ++i) {
      QDirIterator dit(QString(sl_dirs.at(i) + '/' + QIcon::themeName()) , QDirIterator::Subdirectories);
      while (dit.hasNext()) {
         QFileInfo fi(dit.next());
         if (fi.completeBaseName() == iconname) sl_results << fi.canonicalFilePath();
      } // while
   } // for

   // search the list for icons matching the filter list and return first found
   if (sl_results.size() < 1) return QString();
   if (sl_filter.size() < 1) return sl_results.at(0);
   for (int i = 0; i < sl_filter.size(); ++i) {
      for (int j = 0; j < sl_results.size(); ++j) {
         if (sl_results.at(j).contains(sl_filter.at(i)) ) return sl_results.filter(sl_filter.at(i)).at(0);
      } // j for
   } // i for

   // if no filter matches
   return sl_results.at(0);
}
