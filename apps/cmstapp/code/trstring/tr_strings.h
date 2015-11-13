/**************************** tr_strings.cpp ***************************

Class to manage and present strings that need to be translated. These
are typically not inline strings, rather strings used globally or strings
returned by third parties, for instance, Connman.

Copyright (C) 2013-2015
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

# ifndef TRANSLATE_STRINGS
# define TRANSLATE_STRINGS

# include <QObject>

class TranslateStrings : public QObject
{
  Q_OBJECT

  public:
  // members
    TranslateStrings(QObject*);
  
  // functions
		static inline QString cmtr(const QString& str, const char* disamb = 0) {return tr(qPrintable(str), disamb);}  
};
#endif
