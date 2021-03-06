//===============================================================
// vframec.cxx	- a frame for holding commands - Windows
//
// Copyright (C) 1995,1996, 1997, 1998  Bruce E. Wampler
//
// This file is part of the V C++ GUI Framework, and is covered
// under the terms of the GNU Library General Public License,
// Version 2. This library has NO WARRANTY. See the source file
// vapp.cxx for more complete information about license terms.
//===============================================================

#include <v/vwin32.h>		// for Win 32 stuff
#include <v/vapp.h>
#include <v/vframec.h>	// our definitions
#include <v/vcmdprnt.h>	// a command parent

//=====================>>> vFrameCmd::vFrameCmd <<<=======================
  vFrameCmd::vFrameCmd(vCmdParent* dp, CommandObject* dc) :
    vCmd(dp, dc)
  {
    initialize();
  }

//=====================>>> vFrameCmd::~vFrameCmd <<<=======================
  vFrameCmd::~vFrameCmd()
  {

    SysDebug(Destructor,"vFrameCmd::~vFrameCmd() destructor\n")

  }

//=====================>>> vFrameCmd::initialize <<<=======================
  void vFrameCmd::initialize(void)
  {
    // build a button command for use in a parent window


    SysDebug(Constructor,"vFrameCmd::vFrameCmd() constructor\n")

    
    long style = BS_OWNERDRAW | WS_GROUP;	// default for a button

    CopyToLocal();			// Make local copies of CmdObject

    _title = "";				// never a label, sigh...

   // if (!(dlgCmd->attrs & CA_NoBorder))		// Check for Hidden
	style |= WS_VISIBLE;


    _w = StdMargin;				// set my width
    _h = StdMargin; /* +2 */		      	// default height

    _parentWin->SetPosition(_x, _y, _w, _h, dlgCmd->cFrame, dlgCmd->cRightOf,
	dlgCmd->cBelow);

    _CtrlOffset = _parentWin->AddDlgControl(_x, _y, _w, _h, _cmdId,
	  style, "BUTTON", _title, sizeof(vCmd*), (LPBYTE)this);
  }

//================>>> vFrameCmd::SetCmdVal <<<============================
  void vFrameCmd::SetCmdVal(ItemVal val, ItemSetType st)
  {

    SysDebug1(Misc,"vFrameCmd::SetCmdVal(val:%d)\n",val)

    HWND myHwnd = GetMyHwnd(_cmdId);
    if (st == Sensitive)		// used so icons won't get
      {                                 // focus -- icons use ownerdraw,
	_Sensitive = val;	// which behave like buttons, not
	::EnableWindow(myHwnd, val);    // static labels -- this fixes that
      }
    else if (st == Hidden)		// hide or unhide
      {
	if (val)
	  {
	    ::ShowWindow(myHwnd,SW_HIDE);
	  }
	else
	  {
	    ::ShowWindow(myHwnd,SW_SHOW);
	  }
      }
    else if (st == Value && dlgCmd->cmdType == C_ToggleFrame)  	// Toggle?
      {
	if (val)		// have to hide/show me first
	  {
	    ::ShowWindow(myHwnd,SW_SHOW);
	  }
	else
	  {
	    ::ShowWindow(myHwnd,SW_HIDE);
	  }
	_parentWin->SetFrameChildren(_cmdId,val); // and now set value of childern
      }
 }

//================>>> vFrameCmd::MEASUREITEM <<<============================
  int vFrameCmd::MEASUREITEM(int id, MEASUREITEMSTRUCT* mis)
  {
    mis->CtlType = ODT_BUTTON;
    mis->CtlID = id;
    mis->itemWidth = _w;
    mis->itemHeight = _h;
    
    return 1;
  }

//================>>> vFrameCmd::DRAWITEM <<<============================
  int vFrameCmd::DRAWITEM(int /*id */, DRAWITEMSTRUCT* dis)
  {
    switch (dis->itemAction)
      {
	case ODA_DRAWENTIRE:	// redraw entire control
	  {
	    // This gets called after the CTLCOLOR message has been
	    // processed in the dialog/commandpane procs.
	    // We are using LTGRAY_BRUSH for dialogs and command bars.
	    // We need to draw the icon properly on the background.
	    // We will use a null pen, and the same background. We have
	    // to use left-1, top-1, right+1, and bottom+1 to have the
	    // interior of the rectangle in the icon's area. We end up
	    // with a white line otherwise. First, fill gray background

	    HPEN oldpen = (HPEN) ::SelectObject(dis->hDC, GetStockObject(NULL_PEN));

	    HBRUSH oldbrush = static_cast<HBRUSH>(::SelectObject(dis->hDC, theApp->_BarBrush));

	    (void)::Rectangle(dis->hDC,dis->rcItem.left, dis->rcItem.top,
		dis->rcItem.right+1, dis->rcItem.bottom+1);

	    if (!(dlgCmd->attrs & CA_NoBorder))
	      {
	    ::SelectObject(dis->hDC, theApp->_ShadowPen);
	    ::MoveTo(dis->hDC, dis->rcItem.left+1, dis->rcItem.bottom-1);
	    ::LineTo(dis->hDC, dis->rcItem.left+1, dis->rcItem.top+1);
	    ::LineTo(dis->hDC, dis->rcItem.right-1, dis->rcItem.top+1);
	   
	    ::SelectObject(dis->hDC,theApp->_LightPen);
	    ::MoveTo(dis->hDC, dis->rcItem.right-1, dis->rcItem.top+1);
	    ::LineTo(dis->hDC, dis->rcItem.right-1, dis->rcItem.bottom-1);
	    ::LineTo(dis->hDC, dis->rcItem.left+1, dis->rcItem.bottom-1);
              }


	    ::SelectObject(dis->hDC, oldpen);	// restore hdc
	    ::SelectObject(dis->hDC, oldbrush);

	    return 1;
	  }

	case ODA_SELECT:	// indicated selected
	  {
	    return 1;		// no op for icon Frame
	  }

	case ODA_FOCUS:		// gets focus
	  {
	    return 1;		// no op for icon Frame
	  }
      }
    return 0;
  }

//===================>>> vFrameCmd::vCmdCallback <<<=======================
  void vFrameCmd::CmdCallback(int /*id*/, WORD codeNotify)
  {
   // No Op for a Frame - the icon button may generate one of these!
  }
