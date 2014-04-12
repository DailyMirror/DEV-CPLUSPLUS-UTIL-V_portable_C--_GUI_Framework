//=======================================================================
//@V@:Note: This file generated by vgen V1.00 (10:45:42 AM 12 Sep 1996).
//	tglcmdw.cpp:	Source for testGLCmdWindow class
//=======================================================================

#include <v/vnotice.h>	// for vNoticeDialog
#include <v/vkeys.h>	// to map keys

#include "tglcmdw.h"	// our header
#include "tglcnv.h"

//	Start defines for the main window with 100

//@V@:BeginIDs
    enum {
	m_FirstCmd = 100, // Dummy Command
	lblSpin,	// label for spin
	sldSpeed,	// speed of spin
	lblTestStat,	// Status Bar test
	blkLast		// Last item
      };
//@V@:EndIDs

//@V@:BeginPulldownMenu FileMenu
    static vMenu FileMenu[] =
      {
	{"E&xit", M_Exit, isSens, notChk, noKeyLbl, noKey, noSub},
	{NULL}
      };
//@V@:EndPulldownMenu


//@V@:BeginMenu StandardMenu
    static vMenu StandardMenu[] =
      {
	{"&File", M_File, isSens, notUsed, notUsed, noKey, &FileMenu[0]},
	{NULL}
      };
//@V@:EndMenu

//@V@:BeginCmdPane ToolBar
    static CommandObject ToolBar[] =
      {
	{C_Button,M_Exit,0,"Quit",NoList,CA_None,isSens,NoFrame,0,0},
	{C_Label,lblSpin,0,"Spin Speed:",NoList,CA_None,isSens,NoFrame,0,0},
	{C_Slider,sldSpeed,0,"",NoList,CA_Horizontal,isSens,NoFrame,0,0},
	{C_EndOfList,0,0,0,0,CA_None,0,0,0}
      };
//@V@:EndCmdPane

//@V@:BeginStatPane StatBar
    static vStatus StatBar[] =
      {
	{"OpenGL/V Demo Program", lblTestStat, CA_NoBorder, isSens, 0},
	{0,0,0,0,0}
      };
//@V@:EndStatPane

//====================>>> testGLTimer::TimerTick <<<====================
  void testGLTimer::TimerTick()
  {
    cmdw->testGLCanvas->Spin();
  }

//====================>>> testGLCmdWindow::testGLCmdWindow <<<====================
  testGLCmdWindow::testGLCmdWindow(char* name, int height, int width) :
    vCmdWindow(name, height, width)
  {
    UserDebug1(Constructor,"testGLCmdWindow::testGLCmdWindow(%s) Constructor\n",name)

    // The Menu Bar
    testGLMenu = new vMenuPane(StandardMenu);
    AddPane(testGLMenu);

    // The Command Pane
    testGLCmdPane = new vCommandPane(ToolBar);
    AddPane(testGLCmdPane);

    // The Canvas
    testGLCanvas = new testGLCanvasPane();
    AddPane(testGLCanvas);

    // The Status Bar
    testGLStatus = new vStatusPane(StatBar);
    AddPane(testGLStatus);

    _timer = new testGLTimer(this);             // create timer
    _spinSpeed = 0;

    // Show Window

    ShowWindow();

  }

//====================>>> testGLCmdWindow::~testGLCmdWindow <<<====================
  testGLCmdWindow::~testGLCmdWindow()
  {
    UserDebug(Destructor,"testGLCmdWindow::~testGLCmdWindow() destructor\n")

    // Now put a delete for each new in the constructor.

    delete testGLMenu;
    delete testGLCanvas;
    delete testGLCmdPane;
    delete testGLStatus;
  }

//====================>>> testGLCmdWindow::KeyIn <<<====================
  void testGLCmdWindow::KeyIn(vKey keysym, unsigned int shift)
  {
    vCmdWindow::KeyIn(keysym, shift);
  }

//====================>>> testGLCmdWindow::WindowCommand <<<====================
  void testGLCmdWindow::WindowCommand(ItemVal id, ItemVal val, CmdType cType)
  {
    // Default: route menu and toolbar commands here


    UserDebug1(CmdEvents,"testGLCmdWindow:WindowCommand(%d)\n",id)

    switch (id)
      {
	//@V@:Case M_Exit
	case M_Exit:
	  {
	    theApp->Exit();
	    break;
	  }	//@V@:EndCase


	//@V@:Case btnTestTool
	case sldSpeed:
	  {
	    if (val != 0)			// Start spinning
	      {
		_timer->TimerStop();
		_timer->TimerSet((100-val)*2);
 	      }
	    else
	      {
		_timer->TimerStop();
	      }

	    break;
	  }	//@V@:EndCase


	default:		// route unhandled commands up
	  {
	    vCmdWindow::WindowCommand(id, val, cType);
	    break;
	  }
      }
  }
