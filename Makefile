#############################################################################
# Makefile for building: SnapViewer
# Generated by qmake (2.01a) (Qt 4.4.3) on: Mon Jan 12 15:22:20 2009
# Project:  SnapViewer.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.4.3/bin/qmake -unix -o Makefile SnapViewer.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/Qt-4.4.3/mkspecs/linux-g++ -I. -I/usr/local/Trolltech/Qt-4.4.3/include/QtCore -I/usr/local/Trolltech/Qt-4.4.3/include/QtCore -I/usr/local/Trolltech/Qt-4.4.3/include/QtGui -I/usr/local/Trolltech/Qt-4.4.3/include/QtGui -I/usr/local/Trolltech/Qt-4.4.3/include/QtOpenGL -I/usr/local/Trolltech/Qt-4.4.3/include/QtOpenGL -I/usr/local/Trolltech/Qt-4.4.3/include -I. -I/usr/X11R6/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/usr/local/Trolltech/Qt-4.4.3/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/Qt-4.4.3/lib -L/usr/X11R6/lib -lQtOpenGL -L/usr/local/Trolltech/Qt-4.4.3/lib -L/usr/X11R6/lib -pthread -pthread -pthread -pthread -pthread -pthread -pthread -pthread -lQtGui -pthread -lpng -lSM -lICE -pthread -pthread -lXi -lXrender -lXrandr -lfreetype -lfontconfig -lXext -lX11 -lQtCore -lz -lm -pthread -lgthread-2.0 -lrt -lglib-2.0 -ldl -lGLU -lGL -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/Qt-4.4.3/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = glwidget.cpp \
		main.cpp \
		snap.cpp \
		window.cpp moc_glwidget.cpp \
		moc_window.cpp
OBJECTS       = glwidget.o \
		main.o \
		snap.o \
		window.o \
		moc_glwidget.o \
		moc_window.o
DIST          = /usr/local/Trolltech/Qt-4.4.3/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/opengl.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/lex.prf \
		SnapViewer.pro
QMAKE_TARGET  = SnapViewer
DESTDIR       = 
TARGET        = SnapViewer

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: SnapViewer.pro  /usr/local/Trolltech/Qt-4.4.3/mkspecs/linux-g++/qmake.conf /usr/local/Trolltech/Qt-4.4.3/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/opengl.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.4.3/lib/libQtOpenGL.prl \
		/usr/local/Trolltech/Qt-4.4.3/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.4.3/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile SnapViewer.pro
/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/g++.conf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/release.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/opengl.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.4.3/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.4.3/lib/libQtOpenGL.prl:
/usr/local/Trolltech/Qt-4.4.3/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.4.3/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile SnapViewer.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/SnapViewer1.0.0 || $(MKDIR) .tmp/SnapViewer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/SnapViewer1.0.0/ && $(COPY_FILE) --parents glwidget.h snap.h window.h .tmp/SnapViewer1.0.0/ && $(COPY_FILE) --parents glwidget.cpp main.cpp snap.cpp window.cpp .tmp/SnapViewer1.0.0/ && (cd `dirname .tmp/SnapViewer1.0.0` && $(TAR) SnapViewer1.0.0.tar SnapViewer1.0.0 && $(COMPRESS) SnapViewer1.0.0.tar) && $(MOVE) `dirname .tmp/SnapViewer1.0.0`/SnapViewer1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/SnapViewer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_glwidget.cpp moc_window.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_glwidget.cpp moc_window.cpp
moc_glwidget.cpp: snap.h \
		glwidget.h
	/usr/local/Trolltech/Qt-4.4.3/bin/moc $(DEFINES) $(INCPATH) glwidget.h -o moc_glwidget.cpp

moc_window.cpp: window.h
	/usr/local/Trolltech/Qt-4.4.3/bin/moc $(DEFINES) $(INCPATH) window.h -o moc_window.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

glwidget.o: glwidget.cpp glwidget.h \
		snap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o glwidget.o glwidget.cpp

main.o: main.cpp window.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

snap.o: snap.cpp snap.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o snap.o snap.cpp

window.o: window.cpp glwidget.h \
		snap.h \
		window.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o window.o window.cpp

moc_glwidget.o: moc_glwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_glwidget.o moc_glwidget.cpp

moc_window.o: moc_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_window.o moc_window.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

