//=======================================================================
//@V@:Note: This file generated by vappgen V 1.00.
//	vgcnv.h:	Header for vgTextCanvasPane class
//=======================================================================
#ifndef vgTCNV_H
#define vgTCNV_H

#include <v/vtextcnv.h>

    class vgTextCanvasPane : public vTextCanvasPane
      {
      public:		//---------------------------------------- public
	vgTextCanvasPane();
	virtual ~vgTextCanvasPane();

	// Scrolling
	virtual void HPage(int, int);
	virtual void VPage(int, int);

	virtual void HScroll(int);
	virtual void VScroll(int);

	// Events
	virtual void FontChanged(vFont& newFont);
	virtual void ResizeText(const int rows, const int cols);
	virtual void Redraw(int x, int y, int width , int height);
	virtual void TextMouseDown(int row, int col, int button);
	virtual void TextMouseUp(int row, int col, int button);
	virtual void TextMouseMove(int row, int col, int button);

      protected:	//--------------------------------------- protected
      private:		//--------------------------------------- private
      };
#endif
