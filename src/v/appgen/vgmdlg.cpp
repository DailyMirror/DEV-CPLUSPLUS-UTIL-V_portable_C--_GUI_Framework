//=======================================================================
//@V@:Note: This file generated by vappgen V 1.00.
//	vgmdlg.cpp:	Source for vgModalDialog class
//=======================================================================

#include "vgmdlg.h"
#include <v/vnotice.h>
#include <v/vfilesel.h>

//@V@:BeginIDs
    enum {
    lblMainMsg = 1000,

    frmNames,
    lblAppName,			// App name
    txiAppName,
    lblFileName,		// file base name
    txiFileName,
    lblTitle,			// app title
    txiTitle,

    frmCmdWin,			// frame for cmdwin stuff
    lblCmdWin,
    blkCmdWin,
    chkGenMenu,			// if include menu par
    chkGenTool,			// if generate toolbar
    chkWinSDI,			// if Windows SDI
    chkGenStatus,		// if generate status bar
    chkGenDate,
    chkAddTimer, 		// if add code for a timer

    frmCanvas,			// frame for canvas stuff
    lblCanvas,
    blkCanvas,
    chkVScroll,			// for vert scroll
    chkHScroll,			// for horiz scroll
    rdbStdCnv,			// Standard Canvas
    rdbTextCnv,			// Text Canvas
    rdbNoCnv,			// no canvas
    rdbOGLCnv,			// vBaseGLCanvasPane

    frmOther,			// frame for other options
    lblOther,
    blkOther,
    chkGenDialog,		// if generate a dialog
    chkGenModal,		// if generate a modal dialog
    chkGenMake,			// if generate make file
    chkGenProj,			// if generate project file
    lblHOMEV,
    txiHOMEV,

    btnSetPath,			// to set save path
    blkLast
  };
//@V@:EndIds

//@V@:BeginDialogCmd DefaultCmds
    static DialogCmd DefaultCmds[] =
      {
	{C_Label, lblMainMsg, 0,"X",NoList,CA_MainMsg,isSens,NoFrame, 0, 0},

	{C_Frame, frmNames, 0, "",NoList,CA_NoBorder,isSens,NoFrame, 0,lblMainMsg},
	{C_Label, lblAppName, 0,"Application Base Name:",
	    NoList, CA_None, isSens,frmNames,0, 0, 0,
	    "Specify base part of dialog class name"},
	{C_TextIn, txiAppName, 0,"x",
	    NoList, CA_None, isSens,frmNames,lblAppName, 0, 0,
	    "Specify base part of dialog class name"},
	{C_Label, lblFileName, 0,"       File Base Name:",
	    NoList, CA_None, isSens,frmNames,0, txiAppName,0,
		"Specify base part of generated file names"},
	{C_TextIn, txiFileName, 0,"x",
	    NoList, CA_None, isSens,frmNames,lblAppName, txiAppName,0,
		"Specify base part of generated file names"},
	{C_Label, lblTitle, 0,  "    Application Title:",
	    NoList, CA_None, isSens,frmNames,0, txiFileName,0,
		"Specify title for application"},
	{C_TextIn, txiTitle, 0,"x",
	    NoList, CA_None, isSens,frmNames,lblAppName, txiFileName,0,
		"Specify title for application"},


	{C_Frame, frmCmdWin, 0, "",NoList,CA_NoBorder,isSens,NoFrame, 0,frmNames},
	{C_Label, lblCmdWin, 0, "Command Window Options",
	    NoList, CA_None, isSens,frmCmdWin,0, 0},
	{C_Blank, blkCmdWin, 0, " ",
	    NoList, CA_None, isSens,frmCmdWin,0, lblCmdWin},
	{C_CheckBox, chkGenTool, 1, "Include Tool Bar         ",
	    NoList, CA_None, isSens,frmCmdWin,blkCmdWin, lblCmdWin,0,
		"Include a Tool Bar in App command window"},
	{C_CheckBox, chkGenStatus, 1, "Include Status Bar",
	    NoList, CA_None, isSens,frmCmdWin,chkGenTool, lblCmdWin,0,
		"Include a Status Bar in App command window"},
  	{C_CheckBox, chkGenMenu, 1, "Include Menu Bar         ",
	    NoList, CA_None, isSens,frmCmdWin,blkCmdWin, chkGenTool,0,
		"Include a menu bar in command window"},
	{C_CheckBox, chkGenDate, 0, "Time/Date on Status Bar",
	    NoList, CA_None, isSens,frmCmdWin,chkGenMenu, chkGenStatus,0,
		"Include code to display time/date on Status Bar"},
  	{C_CheckBox, chkWinSDI, 0,  "Windows SDI (MDI Default)",
	    NoList, CA_None, isSens,frmCmdWin,blkCmdWin,chkGenMenu, 0,
		"Generate MS-Windows SDI App (MDI is default Windows App)"},
  	{C_CheckBox, chkAddTimer, 0,  "Add vTimer to CommandWindow",
	    NoList, CA_None, isSens,frmCmdWin,chkGenMenu,chkGenDate, 0,
		"Add code for a vTimer to the CommandWindow"},


	{C_Frame, frmCanvas, 0, "",NoList,CA_NoBorder,isSens,NoFrame, 0,frmCmdWin},
	{C_Label, lblCanvas, 0, "Canvas Options",
	    NoList, CA_None, isSens,frmCanvas,0, 0},
	{C_Blank, blkCanvas, 0, " ",
	    NoList, CA_None, isSens,frmCanvas,0, lblCanvas},
	{C_CheckBox, chkVScroll, 1, "Vertical Scroll Bar      ",
	    NoList, CA_None, isSens,frmCanvas,blkCanvas, lblCanvas,0,
		"Start app with vertical scroll bar shown"},
	{C_CheckBox, chkHScroll, 1, "Horizontal Scroll Bar",
	    NoList, CA_None, isSens,frmCanvas,chkVScroll, lblCanvas,0,
		"Start app with horizontal scroll bar shown"},
	{C_RadioButton, rdbStdCnv, 1, "vCanvasPane              ",
	    NoList, CA_None, isSens,frmCanvas,blkCanvas, chkVScroll, 0,
		"App based on vCanvasPane"},
	{C_RadioButton, rdbTextCnv, 0, "vTextCanvasPane",
	    NoList, CA_None, isSens,frmCanvas,rdbStdCnv, chkVScroll,0,
		"App based on vTextCanvasPane"},
	{C_RadioButton, rdbOGLCnv, 0, "vBaseGLCanvasPane",
	    NoList, CA_None, isSens,frmCanvas,blkCanvas, rdbStdCnv,0,
		"App based on vBaseGLCanvasPane"},
	{C_RadioButton, rdbNoCnv, 0, "No Canvas Pane",
	    NoList, CA_None, isSens,frmCanvas,rdbStdCnv, rdbStdCnv,0,
		"App has no canvas pane"},

	{C_Frame, frmOther, 0, "",NoList,CA_NoBorder,isSens,NoFrame, 0,frmCanvas},
	{C_Label, lblOther, 0, "Other Options",
	    NoList, CA_None, isSens,frmOther,0, 0},
	{C_Blank, blkOther, 0, " ",
	    NoList, CA_None, isSens,frmOther,0, lblOther},

	{C_CheckBox, chkGenDialog, 1, "Generate Modeless Dialog ",
	    NoList, CA_None, isSens,frmOther,blkOther, lblOther,0,
		"Generate code for one modeless dialog with app"},
	{C_CheckBox, chkGenModal, 0, "Generate Modal Dialog",
	    NoList, CA_None, isSens,frmOther,chkGenDialog, lblOther,0,
		"Generate code for one modal dialog with app"},
  	{C_CheckBox, chkGenMake, 0, "Generate GNU makefile",
	    NoList, CA_None, isSens,frmOther,blkOther, chkGenModal,0,
		"Generate GNU make compatible makefile"},
  	{C_CheckBox, chkGenProj, 1, "Generate V IDE Project",
	    NoList, CA_None, isSens,frmOther,chkGenDialog, chkGenModal,0,
		"Generate V IDE Project file"},
	{C_Label, lblHOMEV, 0," HOMEV:",
	    NoList, CA_None, isSens,frmOther,blkOther, chkGenMake,0,
		"Default location of V files - HOMEV in makefile"},
	{C_TextIn, txiHOMEV, 0,"x",
	    NoList, CA_Small, isSens,frmOther,lblHOMEV, chkGenMake,20,
		"Default location of V files - HOMEV in makefile"},
  
	{C_Button, btnSetPath, 0, " Set Save Path ",NoList,CA_None,
	    isSens,NoFrame,0, frmOther,0,
		"Specify file path to save generated files"},
	{C_Blank, blkLast, 0, "           ",
	    NoList,CA_None, isSens,NoFrame,btnSetPath, frmOther},
	{C_Button, M_Cancel, 0, " Cancel ",NoList,CA_None,
	    isSens,NoFrame,blkLast, frmOther},
	{C_Button, M_OK, 0, " Generate ", NoList, CA_DefaultButton, 
	    isSens, NoFrame, M_Cancel, frmOther,0,
		"Generate code"},

	{C_EndOfList,0,0,0,0,CA_None,0,0,0}
    };
//@V@:EndDialogCmd

//==========================>>> SetCmdObjAttr <<<==============================
  void SetCmdObjTitle(CommandObject* cList, ItemVal id, char* newtitle)
  {
    // This is called to change the attrs field of the item with given id

    // scan the entire list

    int ix;
    for (ix = 0 ; cList && (cList[ix].cmdType != C_EndOfList) ; ++ix)
      {
	if (cList[ix].cmdId == id)		// the one we want!
	  {
	    cList[ix].title = newtitle;		// change
	    break;
	  }
      }
   }

//======================>>> vgModalDialog::vgModalDialog <<<==================
  vgModalDialog::vgModalDialog(vBaseWindow* bw, char* title) :
    vModalDialog(bw,title)
  {
    UserDebug(Constructor,"vgModalDialog::vgModalDialog()\n")
  }

//===================>>> vgModalDialog::~vgModalDialog <<<====================
  vgModalDialog::~vgModalDialog()
  {
    UserDebug(Destructor,"vgModalDialog::~vgModalDialog() destructor\n")
  }

//====================>>> vgModalDialog::vgAction <<<====================
  int vgModalDialog::vgAction(char* msg, vgOptions& op)
  {
    ItemVal ans,rval;

    SetCmdObjTitle(DefaultCmds,txiAppName,op.appName);
    SetCmdObjTitle(DefaultCmds,txiFileName,op.fileName);
    SetCmdObjTitle(DefaultCmds,txiTitle,op.title);
    SetCmdObjTitle(DefaultCmds,txiHOMEV,op.home);

    AddDialogCmds(DefaultCmds);		// add the predefined commands

TRYAGAIN:
    ans = ShowModalDialog(msg,rval);
    if (ans == M_Cancel)
	return 0;

    // Retrieve values from fields of the dialog

    (void) GetTextIn(txiAppName,op.appName,99);
    (void) GetTextIn(txiFileName,op.fileName,99);
    (void) GetTextIn(txiTitle,op.title,99);
    (void) GetTextIn(txiHOMEV,op.home,99);
    op.addDialog = GetValue(chkGenDialog);
    op.addModal = GetValue(chkGenModal);
    op.addMake = GetValue(chkGenMake);
    op.addVproj = GetValue(chkGenProj);
    op.addToolBar = GetValue(chkGenTool);
    op.addStatus = GetValue(chkGenStatus);
    op.addMenu = GetValue(chkGenMenu);
    op.addTimer = GetValue(chkAddTimer);
    if (op.addStatus)
	op.addDate = GetValue(chkGenDate);
    else
	op.addDate = 0;
    op.vScroll = GetValue(chkVScroll);
    op.hScroll = GetValue(chkHScroll);
    if (GetValue(rdbStdCnv) == 1)
	op.canvasType = Canvas;
    else if (GetValue(rdbTextCnv) == 1)
	op.canvasType = Text;
    else if (GetValue(rdbOGLCnv) == 1)
	op.canvasType = OpenGL;
    else
	op.canvasType = NoCanvas;

    op.winSDI = GetValue(chkWinSDI);

    if (!op.addMenu && !op.addToolBar)
      {
	vNoticeDialog note(this);
	note.Notice("You must include at least a Menu OR a Tool Bar.");
	goto TRYAGAIN;
      }

    // *** Add code to process dialog values here

    return ans == M_OK;
  }

//====================>>> vgModalDialog::DialogCommand <<<====================
  void vgModalDialog::DialogCommand(ItemVal id, ItemVal retval, CmdType ctype)
  {
    UserDebug2(CmdEvents,"vgModalDialog::DialogCommand(id:%d, val:%d)\n",id, retval)

    switch (id)		// We will do some things depending on value
      {
	 case chkGenStatus:	// Need to toggle sensitivity of Date
	  {
	    if (retval == 1)
	      {
		SetValue(chkGenDate,1,Sensitive);
	      }
	    else
	      {
		SetValue(chkGenDate,0,Value);
		SetValue(chkGenDate,0,Sensitive);
	      }
	    break;
	  }

	case btnSetPath:		// set path to save in
	  {
	    char path[100];
	    int tmp = 0;
	    (void) GetTextIn(txiFileName,path,99);
	    strcat(path,"app.cpp");	// use xxapp.cpp as default name
	    vFileSelect fsel(this);

	    int oans = fsel.FileSelectSave("Generate code to directory",
		path,99,NULL,tmp);
	    break;
	  }
      }

    vModalDialog::DialogCommand(id,retval,ctype);
  }
