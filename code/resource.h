/**************************** resource.h *******************************

Header file that contains program #defines.  It used to be that we kept
all program update and version information in this single file.  Now
we've moved a lot of that to txt files inside the /text directory which
are compiled in as a resource.  This seems to result in a faster 
compile, but we now have manage information in two locations.

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

#ifndef RESOURCE_H
#define RESOURCE_H

///////////////////////////////// Program Values ///////////////////////
// Program Info 
#define VERSION "14.06.03-2"
#define RELEASE_DATE "10 May 2014"
#define COPYRIGHT_DATE "2013-2014"

// Program Values
#define WINDOW_TITLE "Connman System Tray"
#define PROGRAM_NAME "CMST"
#define LONG_NAME "CMST - Connman System Tray"
#define ORG "Monkey Business Enterprises"


///////////////////////////////// Locale ///////////////////////////////
// Change lines below as needed. 
# define L_LANG  English
# define L_COUNTRY UnitedStates

#endif

