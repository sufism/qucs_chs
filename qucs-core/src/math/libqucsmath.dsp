# Microsoft Developer Studio Project File - Name="libqucsmath" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
#
# libqucsmath.dsp generated by autodsp 1.0.2 from libqucsmath.ap
#

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!MESSAGE There are 2 configurations.
!MESSAGE "libqucsmath - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libqucsmath - Win32 Debug" (based on "Win32 (x86) Static Library")

# Begin Project
CPP=cl.exe
RSC=rc.exe
BSC32=bscmake.exe
LINK32=link.exe
LIB32=link.exe -lib
MTL=midl.exe

!IF "$(CFG)" == "libqucsmath - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Opt"
# PROP Intermediate_Dir "Opt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GX /O2 /Ob2 /I ".." /I "../.." /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /FD /c
# ADD RSC /l 0x409 /d "NDEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /dll /pdb:none /incremental:no /machine:I386

!ELSEIF "$(CFG)" == "libqucsmath - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Dbg"
# PROP Intermediate_Dir "Dbg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I ".." /I "../.." /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /D "DEBUG" /FD /c
# ADD RSC /l 0x409 /d "_DEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /dll /pdb:none /incremental:no /debug /machine:I386

!ENDIF

# Begin Target
# Name "libqucsmath - Win32 Release"
# Name "libqucsmath - Win32 Debug"

# Begin Source File
SOURCE="complex.cpp"
# End Source File

# Begin Source File
SOURCE="cmplx.cpp"
# End Source File

# Begin Source File
SOURCE="fspecial.cpp"
# End Source File

# Begin Source File
SOURCE="real.cpp"
# End Source File

# Begin Source File
SOURCE="cbesselj.cpp"
# End Source File

# Begin Source File
SOURCE="precision.c"
# End Source File

# End Target
# End Project
