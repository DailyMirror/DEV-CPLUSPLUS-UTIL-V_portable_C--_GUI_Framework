//=======================================================================
//@V@:Note: This file generated by vgen V1.05 (17:06:49 22 Apr 1999).
//	abtmdlg.cpp:	Source for abtvideModalDialog class
//=======================================================================

#include "abtvdlg.h"
#include "videapp.h"	// for version string
#include <v/vicon.h>

//@V@:BeginIDs
    enum {
    lblMainMsg = 1000,
    btnTestMDlg		// add your id's here
  };
//@V@:EndIds

//vbm1
#define about_depth 1
#define about_width 86
#define about_height 44
static unsigned char about_bits[] = {
 0x00,0x00,0x80,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0x00,0xf0,0x3f,
 0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0x00,0xfc,0x3f,0x00,0x00,0x00,0x00,
 0x00,0x00,0xc0,0x00,0x00,0xff,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,
 0xc0,0xff,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0xf0,0xff,0x7f,0xc0,
 0x01,0x00,0x00,0x00,0x00,0xc0,0x00,0xfc,0xff,0x7f,0xe0,0x01,0x00,0x00,0x00,
 0x00,0xc0,0x00,0xfe,0xff,0x3f,0xf0,0x01,0x00,0x00,0x00,0x00,0xc0,0x80,0xff,
 0x9f,0x1f,0xf0,0x01,0x00,0x00,0x00,0x00,0xc0,0xc0,0xff,0xc3,0x1f,0xf8,0x00,
 0xe0,0x03,0x00,0x00,0xc0,0xe0,0xff,0xe1,0x0f,0xfc,0x00,0x70,0x83,0x03,0xc0,
 0xc1,0xf8,0x7f,0xe0,0x07,0xfc,0x00,0x3c,0x83,0x03,0xc0,0xc1,0xfc,0x3f,0xf0,
 0x07,0x7e,0x00,0x8e,0x83,0x03,0xc0,0xc1,0xfc,0x0f,0xf8,0x03,0x7e,0x00,0xc7,
 0x81,0x03,0xc0,0xc1,0xfe,0x07,0xf8,0x01,0x3e,0x80,0xf3,0x81,0x03,0xc0,0xc1,
 0xfe,0x01,0xfc,0x01,0x3e,0x80,0xf9,0xfc,0x7f,0xfe,0xff,0xff,0x00,0xfc,0x00,
 0x1e,0xc0,0x7d,0xfc,0x7f,0xfe,0xff,0x7f,0x00,0xfe,0x00,0x1f,0xe0,0x3c,0x80,
 0x03,0xc0,0xc1,0xff,0x1f,0x7f,0x00,0x0f,0xe0,0x1c,0x80,0x03,0xc0,0xc1,0xff,
 0x07,0x7f,0x80,0x0f,0x70,0x80,0x81,0x03,0xc0,0xc1,0x7f,0x80,0x3f,0xc0,0x07,
 0x70,0xc0,0x80,0x03,0xc0,0xc1,0x1f,0x80,0x3f,0xc0,0x07,0x70,0x60,0x00,0x00,
 0x00,0xc0,0x03,0xc0,0x1f,0xe0,0x03,0xf0,0x38,0x00,0x00,0x00,0xc0,0x00,0xc0,
 0x0f,0xe0,0x01,0xf0,0x1f,0x00,0x00,0x00,0xc0,0x00,0xe0,0x0f,0xf0,0x01,0xe0,
 0x07,0x00,0x00,0x00,0xc0,0x00,0xe0,0x07,0xf8,0x00,0x00,0x00,0x00,0x00,0x38,
 0xc0,0x00,0xf0,0x07,0x78,0x00,0x00,0x00,0x00,0x00,0x38,0xc0,0x00,0xf0,0x03,
 0x7c,0x00,0x00,0x00,0x1e,0x00,0x00,0xc0,0x00,0xf0,0x03,0x3e,0x00,0x00,0x80,
 0x0f,0x6f,0x0e,0xc0,0x00,0xf8,0x03,0x1e,0x00,0x00,0xc0,0xbb,0x77,0x0f,0xc0,
 0x00,0xf8,0x01,0x1f,0x00,0x00,0xe0,0xbc,0xbb,0x07,0xc0,0x00,0xf8,0x81,0x0f,
 0x00,0x00,0x60,0xde,0xbc,0x01,0xc0,0x00,0xfc,0xc0,0x07,0x00,0x00,0x60,0xff,
 0xdf,0x19,0xc0,0x00,0xfc,0xe0,0x07,0x00,0x00,0xc0,0xdd,0xff,0x0f,0xc0,0x00,
 0xfc,0xf0,0x03,0x00,0x00,0x00,0x8e,0x3d,0x07,0xc0,0x00,0xfc,0xf0,0x01,0x00,
 0x00,0x00,0x07,0x00,0x00,0xc0,0x00,0xfc,0xfc,0x00,0x00,0x00,0x80,0x03,0x00,
 0x00,0xc0,0x00,0xfc,0xff,0x00,0x00,0x00,0xc0,0x03,0x00,0x00,0xc0,0x00,0xf8,
 0x7f,0x00,0x00,0x00,0xe0,0x01,0x00,0x00,0xc0,0x00,0xf8,0x3f,0x00,0x00,0x00,
 0xe0,0x00,0x00,0x00,0xc0,0x00,0xf8,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0xc0,0x00,0xf0,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0xe0,0x07,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x00,0xc0,0x03,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0xc0};

static vIcon about(&about_bits[0], about_height, about_width, about_depth);
static CommandObject About[] =
  {
    {C_Frame,799,0,"",
	NoList,CA_None,isSens,0,0,0},
    {C_Icon,800,0,"",&about,CA_None,isSens,799,0,0},
    {C_Label,801,0,VIDE_VERS ,NoList,CA_None,isSens,0,799,0},
    {C_Label,802,0,"Copyright 1999, Bruce E. Wampler" ,NoList,CA_None,isSens,0,799,801},
    {C_Label,810,0,"Free IDE for GNU gcc and Sun Java.",
	NoList,CA_None,isSens,0,0,799},
    {C_Label,820,0,"This software comes with absolutely NO WARRANTY!",
	NoList,CA_None,isSens,0,0,810},
    {C_Label,830,0,"This executable version is free to use and share!",
	NoList,CA_None,isSens,0,0,820},
    {C_Label,840,0,"Please see www.objectcentral.com for the GPL Source code.",
	NoList,CA_None,isSens,0,0,830},

    {C_Button,M_OK,0," OK ", NoList,CA_DefaultButton,isSens,0,840,840},
    {C_EndOfList,0,0,0,0,CA_None,0,0,0}
  };


//======================>>> abtvideModalDialog::abtvideModalDialog <<<==================
  abtvideModalDialog::abtvideModalDialog(vBaseWindow* bw, char* title) :
    vModalDialog(bw, title)
  {
    AddDialogCmds(About);		// add the predefined commands
  }

//===================>>> abtvideModalDialog::~abtvideModalDialog <<<====================
  abtvideModalDialog::~abtvideModalDialog()
  {
  }

//====================>>> abtvideModalDialog::abtvideAction <<<====================
  int abtvideModalDialog::abtvideAction(char* msg)
  {
    ItemVal ans,rval;

    ans = ShowModalDialog(msg,rval);

    return ans == M_OK;
  }

//====================>>> abtvideModalDialog::DialogCommand <<<====================
  void abtvideModalDialog::DialogCommand(ItemVal id, ItemVal retval, CmdType ctype)
  {
    vModalDialog::DialogCommand(id,retval,ctype);
  }
