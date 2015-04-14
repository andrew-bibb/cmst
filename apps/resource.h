/**************************** resource.h *******************************

Header file that contains program #defines.  It used to be that we kept
all program update and version information in this single file.  Now
we've moved a lot of that to txt files inside the /text directory which
are compiled in as a resource.  This seems to result in a faster 
compile, but we now have manage information in two locations.

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

#ifndef RESOURCE_H
#define RESOURCE_H

///////////////////////////////// Program Values ///////////////////////
//
// Program Info (may be visible, but don't mark for tranalation) 
#define VERSION "15.04.14-1"
#define RELEASE_DATE "1 March 2015"
#define COPYRIGHT_DATE "2013-2015"

// Program Values:
//	QApplication (not user visible)
//  QSettings (visible in filesystem only)
//	System Logging (visible in system logs only)
#define LONG_NAME "CMST - Connman System Tray"
#define ORG "cmst"
#define APP "cmst"
#define LOG_NAME "CMST" 

// Program Values - Misc. (not user visible)
#define SOCKET_NAME "cmst_single_app_socket"

//////////////////////////// CMST Namespace/////////////////////////////
//  Used for enum's local to this program
namespace CMST 
{
  enum {
    // errors
    No_Errors         = 0x00,
    Err_No_DBus       = (1 << 0), // Can't find DBus 
    Err_Invalid_Iface = (1 << 1), // Invalid interface
    Err_Properties    = (1 << 2), // There was an error reading connman.Manager.GetProperties
    Err_Technologies  = (1 << 3), // There was an error reading connman.Manager.GetTechnologies       
    Err_Services      = (1 << 4), // There was an error reading connman.Manager.GetServices  
    
    // methods
    Manager_Properties    = (1 << 1), // scan for properties
    Manager_Technologies  = (1 << 2), // scan for technologies  
    Manager_Services      = (1 << 3), // scan for services
    Manager_All           = (CMST::Manager_Properties | CMST::Manager_Technologies | CMST::Manager_Services),
    
    // provisioning editor
    ProvEd_No_Selection = 0x00,
    ProvEd_File_Read    = (1 << 0),
    ProvEd_File_Delete  = (1 << 1),
    ProvEd_File_Write   = (1 << 2),
    
    // provisioning editor validator input
    ProvEd_Vd_None    = 0x00,
    ProvEd_Vd_IPv4    = (1 << 0),
    ProvEd_Vd_IPv6    = (1 << 1),
    ProvEd_Vd_MAC     = (1 << 2),
    ProvEd_Vd_46      = (1 << 3),
    ProvEd_Vd_Hex     = (1 << 4),
    ProvEd_Vd_Dom     = (1 << 5),
    ProvEd_Vd_Wd      = (1 << 6),
  };	// enum
} // namespace CMST

#endif

