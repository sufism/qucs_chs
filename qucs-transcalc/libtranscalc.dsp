# Microsoft Developer Studio Project File - Name="libtranscalc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
#
# libtranscalc.dsp generated by autodsp 1.0.2 from libtranscalc.ap
#

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!MESSAGE There are 2 configurations.
!MESSAGE "libtranscalc - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libtranscalc - Win32 Debug" (based on "Win32 (x86) Static Library")

# Begin Project
CPP=cl.exe
RSC=rc.exe
BSC32=bscmake.exe
LINK32=link.exe
LIB32=link.exe -lib
MTL=midl.exe

!IF "$(CFG)" == "libtranscalc - Win32 Release"

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

!ELSEIF "$(CFG)" == "libtranscalc - Win32 Debug"

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
# Name "libtranscalc - Win32 Release"
# Name "libtranscalc - Win32 Debug"

# Begin Source File
SOURCE="microstrip.cpp"
# End Source File

# Begin Source File
SOURCE="transline.cpp"
# End Source File

# Begin Source File
SOURCE="coax.cpp"
# End Source File

# Begin Source File
SOURCE="rectwaveguide.cpp"
# End Source File

# Begin Source File
SOURCE="c_microstrip.cpp"
# End Source File

# Begin Source File
SOURCE="coplanar.cpp"
# End Source File

# End Target
# End Project
