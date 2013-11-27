# Microsoft Developer Studio Project File - Name="qucs" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
#
# qucs.dsp generated by autodsp 1.0.2 from qucs.ap
#

# TARGTYPE "Win32 (x86) Application" 0x0101

!MESSAGE There are 2 configurations.
!MESSAGE "qucs - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "qucs - Win32 Debug" (based on "Win32 (x86) Application")

# Begin Project
CPP=cl.exe
RSC=rc.exe
BSC32=bscmake.exe
LINK32=link.exe
LIB32=link.exe -lib
MTL=midl.exe

!IF "$(CFG)" == "qucs - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Opt"
# PROP Intermediate_Dir "Opt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GX /O2 /Ob2 /I "." /I ".." /I "$(QTDIR)/include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /D "QT_THREAD_SUPPORT" /D "_REENTRANT" /D "UNICODE" /D "QT_DLL" /D "QT_NO_DEBUG" /FD /c
# ADD RSC /l 0x409 /d "NDEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib libcomponents.lib libdiagrams.lib libpaintings.lib libdialogs.lib qtmain.lib qt-mt3.lib /nologo /subsystem:windows /pdb:none /incremental:no /machine:I386 /nodefaultlib:"msvcrtd" /libpath:"components/Opt" /libpath:"diagrams/Opt" /libpath:"paintings/Opt" /libpath:"dialogs/Opt" /libpath:"$(QTDIR)/lib"

!ELSEIF "$(CFG)" == "qucs - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Dbg"
# PROP Intermediate_Dir "Dbg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I "." /I ".." /I "$(QTDIR)/include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /D "QT_THREAD_SUPPORT" /D "_REENTRANT" /D "UNICODE" /D "QT_DLL" /D "DEBUG" /FD /c
# ADD RSC /l 0x409 /d "_DEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib libcomponents.lib libdiagrams.lib libpaintings.lib libdialogs.lib qtmain.lib qt-mt3.lib /nologo /subsystem:windows /pdb:none /incremental:no /debug /machine:I386 /libpath:"components/Dbg" /libpath:"diagrams/Dbg" /libpath:"paintings/Dbg" /libpath:"dialogs/Dbg" /libpath:"$(QTDIR)/lib"

!ENDIF

# Begin Target
# Name "qucs - Win32 Release"
# Name "qucs - Win32 Debug"

# Begin Source File
SOURCE="node.cpp"
# End Source File

# Begin Source File
SOURCE="element.cpp"
# End Source File

# Begin Source File
SOURCE="qucsdoc.cpp"
# End Source File

# Begin Source File
SOURCE="wire.cpp"
# End Source File

# Begin Source File
SOURCE="mouseactions.cpp"
# End Source File

# Begin Source File
SOURCE="qucs.cpp"
# End Source File

# Begin Source File
SOURCE="main.cpp"
# End Source File

# Begin Source File
SOURCE="wirelabel.cpp"
# End Source File

# Begin Source File
SOURCE="qucs_init.cpp"
# End Source File

# Begin Source File
SOURCE="qucs_actions.cpp"
# End Source File

# Begin Source File
SOURCE="viewpainter.cpp"
# End Source File

# Begin Source File
SOURCE="mnemo.cpp"
# End Source File

# Begin Source File
SOURCE="schematic.cpp"
# End Source File

# Begin Source File
SOURCE="schematic_element.cpp"
# End Source File

# Begin Source File
SOURCE="textdoc.cpp"
# End Source File

# Begin Source File
SOURCE="schematic_file.cpp"
# End Source File

# Begin Source File
SOURCE="syntax.cpp"
# End Source File

# Begin Source File
SOURCE="module.cpp"
# End Source File

# Begin Source File
SOURCE="octave_window.cpp"
# End Source File

# Begin Source File
SOURCE="qucs.h"

!IF "$(CFG)" == "qucs - Win32 Release"

# Begin Custom Build - MOC'ing qucs.h ...
InputPath=qucs.h
InputName=qucs
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ELSEIF "$(CFG)" == "qucs - Win32 Debug"

# Begin Custom Build - MOC'ing qucs.h ...
InputPath=qucs.h
InputName=qucs
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ENDIF

# End Source File

# Begin Source File
SOURCE="qucs.moc.cpp"
USERDEP_qucs="qucs.h"
# End Source File

# Begin Source File
SOURCE="schematic.h"

!IF "$(CFG)" == "qucs - Win32 Release"

# Begin Custom Build - MOC'ing schematic.h ...
InputPath=schematic.h
InputName=schematic
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ELSEIF "$(CFG)" == "qucs - Win32 Debug"

# Begin Custom Build - MOC'ing schematic.h ...
InputPath=schematic.h
InputName=schematic
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ENDIF

# End Source File

# Begin Source File
SOURCE="schematic.moc.cpp"
USERDEP_schematic="schematic.h"
# End Source File

# Begin Source File
SOURCE="textdoc.h"

!IF "$(CFG)" == "qucs - Win32 Release"

# Begin Custom Build - MOC'ing textdoc.h ...
InputPath=textdoc.h
InputName=textdoc
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ELSEIF "$(CFG)" == "qucs - Win32 Debug"

# Begin Custom Build - MOC'ing textdoc.h ...
InputPath=textdoc.h
InputName=textdoc
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ENDIF

# End Source File

# Begin Source File
SOURCE="textdoc.moc.cpp"
USERDEP_textdoc="textdoc.h"
# End Source File

# Begin Source File
SOURCE="octave_window.h"

!IF "$(CFG)" == "qucs - Win32 Release"

# Begin Custom Build - MOC'ing octave_window.h ...
InputPath=octave_window.h
InputName=octave_window
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ELSEIF "$(CFG)" == "qucs - Win32 Debug"

# Begin Custom Build - MOC'ing octave_window.h ...
InputPath=octave_window.h
InputName=octave_window
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ENDIF

# End Source File

# Begin Source File
SOURCE="octave_window.moc.cpp"
USERDEP_octave_window="octave_window.h"
# End Source File

# End Target
# End Project
