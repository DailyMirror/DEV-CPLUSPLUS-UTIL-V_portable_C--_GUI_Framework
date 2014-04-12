#=======================================================================
#@V@:Note: File automatically generated by VIDE: (14:53:31 04 Mar 2000) (g++).
#  This file regenerated each time you run VIDE, so save under a
#    new name if you hand edit, or it will be overwritten.
#=======================================================================

# Standard defines:
CC  	=	g++

WRES	=	windres

HOMEV	=	c:\mingw32
VPATH	=	$(HOMEV)/include
oDir	=	../objdll
Bin	=	../bin
Src	=	.
libDirs	=	-L../lib

incDirs	=	-I../includew

LIBS	=	-s -mwindows -lVDLL
C_FLAGS	=	-O\
	-DUSE_V_DLL

SRCS	=\
	$(Src)/brshdlg.cpp\
	$(Src)/coldlg.cpp\
	$(Src)/imageio.cpp\
	$(Src)/viedapp.cpp\
	$(Src)/viedcmdw.cpp\
	$(Src)/viedcnv.cpp\
	$(Src)/viconed.rc

EXOBJS	=\
	$(oDir)/brshdlg.o\
	$(oDir)/coldlg.o\
	$(oDir)/imageio.o\
	$(oDir)/viedapp.o\
	$(oDir)/viedcmdw.o\
	$(oDir)/viedcnv.o\
	$(oDir)/viconed.o

ALLOBJS	=	$(EXOBJS)
ALLBIN	=	$(Bin)/viconeddll.exe
ALLTGT	=	$(Bin)/viconeddll.exe

# User defines:

#@# Targets follow ---------------------------------

all:	$(ALLTGT)

objs:	$(ALLOBJS)

cleanobjs:
	rm -f $(ALLOBJS)

cleanbin:
	rm -f $(ALLBIN)

clean:	cleanobjs cleanbin

cleanall:	cleanobjs cleanbin

#@# User Targets follow ---------------------------------


#@# Dependency rules follow -----------------------------

$(Bin)/viconeddll.exe: $(EXOBJS)
	$(CC) -o $(Bin)/viconeddll.exe $(EXOBJS) $(incDirs) $(libDirs) $(LIBS)

$(oDir)/viconed.o : $(Src)/viconed.rc
	$(WRES) $(Src)/viconed.rc $(oDir)/viconed.o

$(oDir)/brshdlg.o: brshdlg.cpp brshdlg.h viedcnv.h viedcmdw.h brush1.vbm \
 brush2.vbm brush3.vbm brush4.vbm brush5.vbm brush6.vbm brush7.vbm \
 brush8.vbm brush9.vbm brush10.vbm
	$(CC) $(C_FLAGS) $(incDirs) -c -o $@ $<

$(oDir)/coldlg.o: coldlg.cpp coldlg.h viedcnv.h viedcmdw.h palclrs.h
	$(CC) $(C_FLAGS) $(incDirs) -c -o $@ $<

$(oDir)/imageio.o: imageio.cpp imageio.h
	$(CC) $(C_FLAGS) $(incDirs) -c -o $@ $<

$(oDir)/viedapp.o: viedapp.cpp viedapp.h viedcmdw.h coldlg.h viedcnv.h \
 brshdlg.h
	$(CC) $(C_FLAGS) $(incDirs) -c -o $@ $<

$(oDir)/viedcmdw.o: viedcmdw.cpp viedapp.h viedcmdw.h coldlg.h viedcnv.h \
 brshdlg.h palett.vbm brushes.vbm snap.vbm clear.vbm undo.vbm \
 drwbnorm.vbm drwbsel.vbm drwbabc.vbm rect.vbm rdrect.vbm ellipse.vbm \
 line.vbm point.vbm fill.vbm dropper.vbm about.vbm
	$(CC) $(C_FLAGS) $(incDirs) -c -o $@ $<

$(oDir)/viedcnv.o: viedcnv.cpp viedcmdw.h viedcnv.h coldlg.h imageio.h \
 paldecla.h
	$(CC) $(C_FLAGS) $(incDirs) -c -o $@ $<
