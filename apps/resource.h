/**************************** resource.h *******************************

Header file that contains program #defines.  It used to be that we kept
all program update and version information in this single file.  Now
we've moved a lot of that to txt files inside the /text directory which
are compiled in as a resource.  This seems to result in a faster
compile, but we now have manage information in two locations.

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

#ifndef RESOURCE_H
#define RESOURCE_H


// As of 2021.12.19 removed the old xfce and mate code hacks.
// Code still exists in the cpp files.  If we need it back
// add #define XFCE here.  Also the manual page and controlbox ui
// have .save files contiaining the old code.  Keep these around
// for a while then delete if nobody complains.
//

///////////////////////////////// Program Values ///////////////////////
//
// Program Info (may be visible, but don't mark for tranalation)
#define VERSION "2022.01.10-1"

#define RELEASE_DATE "05 January 2022"
#define COPYRIGHT_DATE "2013-2022"

// Program Values:
//  QApplication (not user visible)
//  QSettings (visible in filesystem only)
//  System Logging (visible in system logs only)
#define LONG_NAME "CMST - Connman System Tray"
#define ORG "cmst"
#define APP "cmst"
#define LOG_NAME "CMST"

// Program Values - Misc. (not user visible)
#define SOCKET_NAME "cmst_single_app_socket"
#define INTERNAL_THEME "CMST_Icon_Theme"
#define IPT_REQ_LOG_PATH "/tmp/cmst"
#define IPT_REQ_LOG_FILE "input_request.log"

//////////////////////////// CMST Namespace/////////////////////////////
//  Used for enum's local to this program
namespace CMST
{
  enum {
    // errors
    No_Errors             = 0x00,
    Err_No_DBus           = (1 << 0), // Can't find DBus
    Err_Invalid_Con_Iface = (1 << 1), // Invalid interface
    Err_Properties        = (1 << 2), // There was an error reading connman.Manager.GetProperties
    Err_Technologies      = (1 << 3), // There was an error reading connman.Manager.GetTechnologies
    Err_Services          = (1 << 4), // There was an error reading connman.Manager.GetServices
    Err_Invalid_VPN_Iface = (1 << 5), // Invalid interface

    // provisioning editor
    ProvEd_No_Selection = 0x00,
    ProvEd_File_Read    = (1 << 0),
    ProvEd_File_Delete  = (1 << 1),
    ProvEd_File_Write   = (1 << 2),

    // validating dialog validator input
    ValDialog_None    = 0x00,
    ValDialog_IPv4    = 0x01,
    ValDialog_nmask   = 0x02,
    ValDialog_IPv6    = 0x03,
    ValDialog_MAC     = 0x04,
    ValDialog_46      = 0x05,
    ValDialog_Hex     = 0x06,
    ValDialog_Int     = 0x07,
    ValDialog_Dom     = 0x08,
    ValDialog_Word    = 0x09,
    ValDialog_min1ch  = 0x0a,
    ValDialog_min8ch  = 0x0b,
    ValDialog_46d     = 0x0c,

  };  // enum
} // namespace CMST

#endif

