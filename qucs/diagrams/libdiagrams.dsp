# Microsoft Developer Studio Project File - Name="libdiagrams" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
#
# libdiagrams.dsp generated by autodsp 1.0.2 from libdiagrams.ap
#

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!MESSAGE There are 2 configurations.
!MESSAGE "libdiagrams - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libdiagrams - Win32 Debug" (based on "Win32 (x86) Static Library")

# Begin Project
CPP=cl.exe
RSC=rc.exe
BSC32=bscmake.exe
LINK32=link.exe
LIB32=link.exe -lib
MTL=midl.exe

!IF "$(CFG)" == "libdiagrams - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Opt"
# PROP Intermediate_Dir "Opt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GX /O2 /Ob2 /I ".." /I "../.." /I "$(QTDIR)/include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /D "QT_THREAD_SUPPORT" /D "_REENTRANT" /D "UNICODE" /D "QT_DLL" /D "QT_NO_DEBUG" /FD /c
# ADD RSC /l 0x409 /d "NDEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /dll /pdb:none /incremental:no /machine:I386 /nodefaultlib:"msvcrtd"

!ELSEIF "$(CFG)" == "libdiagrams - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Dbg"
# PROP Intermediate_Dir "Dbg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I ".." /I "../.." /I "$(QTDIR)/include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /D "QT_THREAD_SUPPORT" /D "_REENTRANT" /D "UNICODE" /D "QT_DLL" /D "DEBUG" /FD /c
# ADD RSC /l 0x409 /d "_DEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /dll /pdb:none /incremental:no /debug /machine:I386

!ENDIF

# Begin Target
# Name "libdiagrams - Win32 Release"
# Name "libdiagrams - Win32 Debug"

# Begin Source File
SOURCE="tabdiagram.cpp"
# End Source File

# Begin Source File
SOURCE="smithdiagram.cpp"
# End Source File

# Begin Source File
SOURCE="rectdiagram.cpp"
# End Source File

# Begin Source File
SOURCE="polardiagram.cpp"
# End Source File

# Begin Source File
SOURCE="graph.cpp"
# End Source File

# Begin Source File
SOURCE="diagramdialog.cpp"
# End Source File

# Begin Source File
SOURCE="diagram.cpp"
# End Source File

# Begin Source File
SOURCE="marker.cpp"
# End Source File

# Begin Source File
SOURCE="markerdialog.cpp"
# End Source File

# Begin Source File
SOURCE="psdiagram.cpp"
# End Source File

# Begin Source File
SOURCE="rect3ddiagram.cpp"
# End Source File

# Begin Source File
SOURCE="curvediagram.cpp"
# End Source File

# Begin Source File
SOURCE="timingdiagram.cpp"
# End Source File

# Begin Source File
SOURCE="truthdiagram.cpp"
# End Source File

# Begin Source File
SOURCE="diagramdialog.h"

!IF "$(CFG)" == "libdiagrams - Win32 Release"

# Begin Custom Build - MOC'ing diagramdialog.h ...
InputPath=diagramdialog.h
InputName=diagramdialog
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ELSEIF "$(CFG)" == "libdiagrams - Win32 Debug"

# Begin Custom Build - MOC'ing diagramdialog.h ...
InputPath=diagramdialog.h
InputName=diagramdialog
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ENDIF

# End Source File

# Begin Source File
SOURCE="diagramdialog.moc.cpp"
USERDEP_diagramdialog="diagramdialog.h"
# End Source File

# Begin Source File
SOURCE="markerdialog.h"

!IF "$(CFG)" == "libdiagrams - Win32 Release"

# Begin Custom Build - MOC'ing markerdialog.h ...
InputPath=markerdialog.h
InputName=markerdialog
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ELSEIF "$(CFG)" == "libdiagrams - Win32 Debug"

# Begin Custom Build - MOC'ing markerdialog.h ...
InputPath=markerdialog.h
InputName=markerdialog
"$(InputName).moc.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	%QTDIR%\bin\moc -o $(InputName).moc.cpp $(InputName).h
# End Custom Build

!ENDIF

# End Source File

# Begin Source File
SOURCE="markerdialog.moc.cpp"
USERDEP_markerdialog="markerdialog.h"
# End Source File

# End Target
# End Project
