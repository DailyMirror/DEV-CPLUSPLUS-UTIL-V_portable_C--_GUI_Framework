//=======================================================================
//  testapp.xx:     Source file for test prototype V application
//  Copyright (C) 1995,1996, 1997, 1998  Bruce E. Wampler
//
//  This program is part of the V C++ GUI Framework example programs.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  (see COPYING) along with this program; if not, write to the Free
//  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=======================================================================

//
//
//  Files required for minimal application:
//      testapp.h       Header for the test app
//      testoapp.cxx:   Source code for min app
//      vtcmdwin.h:     Header code for sample command window
//      vtcmdwin.cxx:   Source code for sample command window
//      vtdialog.h:     Header for sample modeless dialog
//      vtdialog.cxx:   Source for sample modeless dialog
//      mymodal.h:      Header for sample modal dialog
//      mymodal.cxx     Soruce for sample modal dialog
//
//      While these files were generated by hand, they are intended to
//      serve as an example of files that could have been generated by
//      the V interface generator (Vigr)
//                                                             

#include <v/vnotice.h>  // so we can use notice

#include "testapp.h"    // our header

    static char newName[] = "[A] Example Subwindow";
    static vWindow* firstWindow = 0;

//=========================>>> testApp::testapp <<<=========================
  testApp::testApp(char* name, int simSDI) : vApp(name,simSDI)
  {
    _defWin = 0;
    _defAppWinInfo = 0;
  }

//=========================>>> testApp::~testapp <<<=========================
  testApp::~testApp()
  {

  }

//=========================>>> myApp::NewAppWin <<<==========================
  vWindow* testApp::NewAppWin(vWindow* win, VCONST char* name, int w, int h,
                vAppWinInfo* winInfo)
  {
    // This version of NewAppWin is provided with the information
    // required to name and size a window.

    // Typically, these would get a file name or other information
    // that will setup the AppWinInfo class for information
    // specific to the application. Thus, each open window
    // usually represents a view of a file or data object.

    vWindow* thisWin = win;             // local copy to use
    vAppWinInfo* awinfo = winInfo;

    VCONST char *myname = (char*)name;

    if (!*name)
      {
        myname = newName;               // make up a name
      }
        
    UserDebug1(Build,"testApp::NewAppWin(%s)\n",myname);

    if (!thisWin)                       // need to new a window
      {
        thisWin = new testCmdWindow(myname, w, h);
        _defWin = firstWindow = thisWin;
      }

    // The real app will no doubt have its own AppWinInfo class.

    if (!awinfo)
      {
        awinfo = new vAppWinInfo(myname);
	if (!_defAppWinInfo)
	    _defAppWinInfo = awinfo;
      }

    if (!*name)
      {
        newName[1]++;           // Cheap way to generate unique name
      }

    return vApp::NewAppWin(thisWin, myname, w, h, awinfo);
  }

//===========================>>> testApp::Exit <<<=============================
  void testApp::Exit(void)
  {
    // This is called to close all windows. If the app needs to
    // do something special, it can. Otherwise, it can call the
    // general vApp::Exit method, which will generate
    // appropriate calls the the specialized testApp::CloseAppWin

    UserDebug(Build,"testApp::Exit()\n");


    vApp::Exit();       // easy default behavior
  }

//=======================>>> testApp::CloseAppWin <<<===========================
  int testApp::CloseAppWin(vWindow* win)
  {
    // This will be called BEFORE a window has been unregistered or
    // closed.  The app can do whatever it needs to to close down
    // the data associated with this window. Then it can call the
    // general vApp::CloseAppWin to unregister and close this window.
    // Note that the win gives a handle that can be used with
    // vApp::getAppWinInfo to retrieve the AppWinInfo class.

    // Code to handle close of window (such as saving/closing a file)
    // would go here...

    // Now unregister and close the window.

    UserDebug(Build,"testApp::CloseAppWin()\n");

    return vApp::CloseAppWin(win);
  }

//==================>>> testApp::CloseLastCmdWindow <<<=======================
  void testApp::CloseLastCmdWindow(vWindow* win, int exitcode)
  {
    // Override - just return, which will leave just the
    // empty MDI frame on windows.  
#ifndef V_VersionWindows
    vApp::CloseLastCmdWindow(win, exitcode);
#endif
  }

//========================>>> testApp::AppCommand <<<===========================
  void testApp::DropFile(const char* fn)
  {
    vNoticeDialog note(this,"Dropped File");
    note.Notice((char*)fn);
  }

//========================>>> testApp::AppCommand <<<===========================
  void testApp::AppCommand(vWindow* win, ItemVal id, ItemVal val, CmdType cType)
  {
    // Any commands not processed by the window will be passed
    // along to here for default treatment.

    UserDebug1(Build,"testApp::AppCmd(ID: %d)\n",id);
    if (id == 901)
      {
        vNoticeDialog note(this);
        note.Notice("This is generated from testApp, not a dialog.\nIt has 2 lines.");
        return;
      }
    else if (id == 902)
      {
        if (firstWindow)
            firstWindow->RaiseWindow();
        return;
      }
    else if (id == 903)         // Shift first window
      {
        if (firstWindow)
          {
            int l,t,r,b;
            firstWindow->GetPosition(l,t,r,b);
            firstWindow->SetPosition(l+30,t+30);
          }
        return;
      }
    else if (id == M_New || id == M_Open)
      {
      (void) theApp->NewAppWin(0, "Prototype V Example", 700, 250, 0);
      return;
      }
    vApp::AppCommand(win, id, val, cType);
  }

//=========================>>> testApp::KeyIn <<<==============================
  void testApp::KeyIn(vWindow* win, vKey key, unsigned int shift)
  {
    // Any key strokes not processed by the window will be passed
    // along to here for default treatment.

    vApp::KeyIn(win, key, shift);
  }

//###########################################################################

  // EVERY V application needs the equivalent of the following line

  static testApp* tApp = new testApp("V test (��)",0); // The instance of the app

//============================>>> AppMain <<<==============================
  int AppMain(int argc, char** argv)
  {
    // Use AppMain to create the main window


    (void) theApp->NewAppWin(0, "Prototype V Example (��)", 720, 300, 0);

    return 0;
  }
