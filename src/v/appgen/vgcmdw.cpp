//=======================================================================
//@V@:Note: This file generated by vappgen V 1.00.
//	vgcmdw.cpp:	Source for vgCmdWindow class
//=======================================================================

#include <v/vnotice.h>	// for vNoticeDialog
#include <v/vkeys.h>	// to map keys
#include <v/vos.h>	// OS helper
#include <v/vynreply.h>	// for overwrite
#include <fstream.h>

#include "vgcmdw.h"	// our header
#include "vgcode.h"

//	Start defines for the main window with 100

    enum {
	m_Generate = 100,	// Generate menu
	m_GenStdApp,		// A standard app
	m_GenExtraDialog	// An extra dialog
      };

    static vMenu FileMenu[] =
      {
	{"Exit", M_Exit, isSens, notChk, noKeyLbl, noKey, noSub},
	{NULL}
      };

    static vMenu GenerateMenu[] =
      {
	{"Standard Application",m_GenStdApp , isSens, notChk, noKeyLbl, noKey, noSub},
	{"Extra Dialog",m_GenExtraDialog , isSens, notChk, noKeyLbl, noKey, noSub},
	{NULL}
      };

    static vMenu StandardMenu[] =
      {
	{"File", M_File, isSens, notUsed, notUsed, noKey, &FileMenu[0]},
	{"Generate", m_Generate, isSens, notUsed, notUsed, noKey, &GenerateMenu[0]},
	{NULL}
      };
 
    static CommandObject ToolBar[] =
      {
	{C_Button,m_GenStdApp,0,"Standard App",NoList,CA_None,isSens,NoFrame,0,0,0,
		"Generate a Standard V Application"},
	{C_Button,m_GenExtraDialog,0,"Extra Dialog",NoList,CA_None,isSens,NoFrame,0,0,0,
		"Generate an additional Dialog"},
	{C_EndOfList,0,0,0,0,CA_None,0,0,0}
      }; 


//====================>>> vgCmdWindow::vgCmdWindow <<<====================
  vgCmdWindow::vgCmdWindow(VCONST char* name, int width, int height) :
    vCmdWindow(name, width, height)
  {
    UserDebug1(Constructor,"vgCmdWindow::vgCmdWindow(%s) Constructor\n",name)

    // The Menu Bar
    vgMenu = new vMenuPane(StandardMenu);
    AddPane(vgMenu);

    // The Command Pane
    vgCmdPane = new vCommandPane(ToolBar);
    AddPane(vgCmdPane);

    // The Canvas
    vgCanvas = new vgTextCanvasPane;
    AddPane(vgCanvas);

    // Show Window

    ShowWindow();

    // Setup default options
    strcpy(opts.appName,"my");
    strcpy(opts.fileName,"my");
    strcpy(opts.title, "My V App");
    vOS vos;
    if (vos.vGetEnvVal("HOMEV",opts.home,99) < 1)
	strcpy(opts.home, DEF_HOMEV);

    opts.addDialog = 1;
    opts.addModal = 1;
    opts.extraDialog = 0;
    opts.addMake = 1;
    opts.addVproj = 1;
    opts.addMenu = 1;
    opts.addToolBar = 1;
    opts.addStatus = 1;
    opts.addDate = 0;
    opts.addTimer = 0;
    opts.vScroll = 1;
    opts.hScroll = 1;
    opts.winSDI = 0;
    opts.canvasType = Canvas;

  }

//====================>>> vgCmdWindow::~vgCmdWindow <<<====================
  vgCmdWindow::~vgCmdWindow()
  {
    UserDebug(Destructor,"vgCmdWindow::~vgCmdWindow() destructor\n")

    // Now put a delete for each new in the constructor.

    delete vgMenu;
    delete vgCmdPane;
    delete vgCanvas;

  }

//====================>>> vgCmdWindow::KeyIn <<<====================
  void vgCmdWindow::KeyIn(vKey keysym, unsigned int shift)
  {
    vCmdWindow::KeyIn(keysym, shift);
  }

//====================>>> vgCmdWindow::WindowCommand <<<====================
  void vgCmdWindow::WindowCommand(ItemVal id, ItemVal val, CmdType cType)
  {
    // Default: route menu and toolbar commands here


    UserDebug1(CmdEvents,"vgCmdWindow:WindowCommand(%d)\n",id)

    switch (id)
      {
	//@V@:Case M_New
	case M_New:
	  {
	    vNoticeDialog note(this);
	    note.Notice("New");
	    break;
	  }	//@V@:EndCase

	//@V@:Case M_Open
	case M_Open:
	  {
	    vNoticeDialog note(this);
	    note.Notice("Open");
	    break;
	  }	//@V@:EndCase

	//@V@:Case M_Save
	case M_Save:
	  {
	    vNoticeDialog note(this);
	    note.Notice("Save");
	    break;
	  }	//@V@:EndCase

	//@V@:Case M_SaveAs
	case M_SaveAs:
	  {
	    vNoticeDialog note(this);
	    note.Notice("Save As");
	    break;
	  }	//@V@:EndCase

	//@V@:Case M_Exit
	case M_Exit:
	  {
	    theApp->Exit();
	    break;
	  }	//@V@:EndCase

	case m_GenStdApp:
	  {
	    strcpy(opts.appName,"my");		// initial names
	    strcpy(opts.fileName,"my");
	    strcpy(opts.title, "My V App");
	    vgModalDialog vgMDlg(this);
	    if (vgMDlg.vgAction("Generate Standard V Appication", opts))
	      {
		char name[100];
		strcpy(name,opts.fileName); strcat(name,"app.cpp");
		ifstream ifile(name);		// see if open
		if (ifile)
		  {
		    ifile.close();
		    vYNReplyDialog ynd(this);
		    if (ynd.AskYN("An application with this name exists. Overwrite it?") != 1)
			break;
		  }

		opts.extraDialog = 0;
		vgCanvas->DrawText("************************************************\n");
		vgCanvas->DrawText("Generated class ");
		vgCanvas->DrawText(opts.appName); vgCanvas->DrawText("App            -> ");
		vgCanvas->DrawText(opts.fileName); vgCanvas->DrawText("app[.cpp & .h]\n");
		genApp(opts);

		vgCanvas->DrawText("Generated class ");
		vgCanvas->DrawText(opts.appName); vgCanvas->DrawText("CmdWindow      -> ");
		vgCanvas->DrawText(opts.fileName); vgCanvas->DrawText("cmdw[.cpp & .h]\n");
		genCmdw(opts);

		if (opts.canvasType == NoCanvas)
		    vgCanvas->DrawText("No Canvas Pane generated\n");
		else
		 {

		   vgCanvas->DrawText("Generated class ");
		   vgCanvas->DrawText(opts.appName); 
		   if (opts.canvasType == Canvas)
		     {
		       vgCanvas->DrawText("CanvasPane     -> ");
		       genCnv(opts);
		     }
		   else if (opts.canvasType == Text)
		     {
		       vgCanvas->DrawText("TextCanvasPane -> ");
		       genTextCnv(opts);
		     }
		   else if (opts.canvasType == OpenGL)
		     {
		       vgCanvas->DrawText("vOpenGLCnvPane -> ");
		       genOGLCnv(opts);
		     }

		   vgCanvas->DrawText(opts.fileName); vgCanvas->DrawText("cnv[.cpp & .h]\n");
		 }

		if (opts.addDialog)
		  {
		    vgCanvas->DrawText("Generated class ");
		    vgCanvas->DrawText(opts.appName); vgCanvas->DrawText("Dialog         -> ");
		    vgCanvas->DrawText(opts.fileName); vgCanvas->DrawText("dlg[.cpp & .h]\n");
		    genDlg(opts);
		  }

		if (opts.addModal)
		  {
		    vgCanvas->DrawText("Generated class ");
		    vgCanvas->DrawText(opts.appName); vgCanvas->DrawText("ModalDialog    -> ");
		    vgCanvas->DrawText(opts.fileName); vgCanvas->DrawText("mdlg[.cpp & .h]\n");
		    genMDlg(opts);
		  }

		if (opts.addMake)
		  {
		    vgCanvas->DrawText("Generated makefile.");
		    vgCanvas->DrawText(opts.fileName); vgCanvas->DrawText(" for V application ");
		    vgCanvas->DrawText(opts.appName); vgCanvas->DrawText(".\n");
		    genMake(opts);
		  }

		if (opts.addVproj)
		  {
		    vgCanvas->DrawText("Generated V Project File ");
		    vgCanvas->DrawText(opts.appName); vgCanvas->DrawText(".vpj");
		    genProject(opts);
		  }

	        vgCanvas->DrawText("\nDone.\n");
		vgCanvas->DrawText("************************************************\n");
	      }

	    break;
	  }	//@V@:EndCase

        case m_GenExtraDialog:	// An extra dialog
	  {
	    opts.extraDialog = 1;
	    strcpy(opts.appName,"xtra");
	    strcpy(opts.fileName,"xtra");
	    strcpy(opts.title, "Extra Dialog");
	    vgdlgModalDialog vgdlgMDlg(this);
	    if (vgdlgMDlg.vgdlgAction("Generate Extra Dialog", opts))
	      {
		char name[100];
		strcpy(name,opts.fileName);
		if (opts.addDialog)
		    strcat(name,"dlg.cpp");
		else
		    strcat(name,"mdlg.cpp");
		ifstream ifile(name);		// see if open
		if (ifile)
		  {
		    ifile.close();
		    vYNReplyDialog ynd(this);
		    if (ynd.AskYN("A dialog with this name exists. Overwrite it?") != 1)
			break;
		  }
		vgCanvas->DrawText("************************************************\n");
		if (opts.addDialog)
		  {
		    vgCanvas->DrawText("Generated class ");
		    vgCanvas->DrawText(opts.appName); vgCanvas->DrawText("Dialog         -> ");
		    vgCanvas->DrawText(opts.fileName); vgCanvas->DrawText("dlg[.cpp & .h]\n");
		    genDlg(opts);
		  }
		else if (opts.addModal)
		  {
		    vgCanvas->DrawText("Generated class ");
		    vgCanvas->DrawText(opts.appName); vgCanvas->DrawText("ModalDialog    -> ");
		    vgCanvas->DrawText(opts.fileName); vgCanvas->DrawText("mdlg[.cpp & .h]\n");
		    genMDlg(opts);
		  }
	        vgCanvas->DrawText("\n!!!! You must add this dialog to your app manually!\nDone.\n");
		vgCanvas->DrawText("************************************************\n");
	      }
	    break;
	  }

	default:		// route unhandled commands up
	  {
	    vCmdWindow::WindowCommand(id, val, cType);
	    break;
	  }
      }
  }
