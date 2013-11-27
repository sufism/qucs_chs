# Microsoft Developer Studio Project File - Name="libqucsator" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
#
# libqucsator.dsp generated by autodsp 1.0.2 from libqucsator.ap
#

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!MESSAGE There are 2 configurations.
!MESSAGE "libqucsator - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libqucsator - Win32 Debug" (based on "Win32 (x86) Static Library")

# Begin Project
CPP=cl.exe
RSC=rc.exe
BSC32=bscmake.exe
LINK32=link.exe
LIB32=link.exe -lib
MTL=midl.exe

!IF "$(CFG)" == "libqucsator - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Opt"
# PROP Intermediate_Dir "Opt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GX /O2 /Ob2 /I ".." /I "../.." /I "math" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /FD /c
# ADD RSC /l 0x409 /d "NDEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /dll /pdb:none /incremental:no /machine:I386

!ELSEIF "$(CFG)" == "libqucsator - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Dbg"
# PROP Intermediate_Dir "Dbg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I ".." /I "../.." /I "math" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /D "DEBUG" /FD /c
# ADD RSC /l 0x409 /d "_DEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /dll /pdb:none /incremental:no /debug /machine:I386

!ENDIF

# Begin Target
# Name "libqucsator - Win32 Release"
# Name "libqucsator - Win32 Debug"

# Begin Source File
SOURCE="dataset.cpp"
# End Source File

# Begin Source File
SOURCE="check_dataset.cpp"
# End Source File

# Begin Source File
SOURCE="parse_dataset.cpp"
# End Source File

# Begin Source File
SOURCE="scan_dataset.cpp"
# End Source File

# Begin Source File
SOURCE="check_touchstone.cpp"
# End Source File

# Begin Source File
SOURCE="vector.cpp"
# End Source File

# Begin Source File
SOURCE="object.cpp"
# End Source File

# Begin Source File
SOURCE="property.cpp"
# End Source File

# Begin Source File
SOURCE="parse_touchstone.cpp"
# End Source File

# Begin Source File
SOURCE="scan_touchstone.cpp"
# End Source File

# Begin Source File
SOURCE="variable.cpp"
# End Source File

# Begin Source File
SOURCE="matvec.cpp"
# End Source File

# Begin Source File
SOURCE="strlist.cpp"
# End Source File

# Begin Source File
SOURCE="logging.c"
# End Source File

# Begin Source File
SOURCE="exception.cpp"
# End Source File

# Begin Source File
SOURCE="exceptionstack.cpp"
# End Source File

# Begin Source File
SOURCE="parse_citi.cpp"
# End Source File

# Begin Source File
SOURCE="scan_citi.cpp"
# End Source File

# Begin Source File
SOURCE="sweep.cpp"
# End Source File

# Begin Source File
SOURCE="check_mdl.cpp"
# End Source File

# Begin Source File
SOURCE="parse_mdl.cpp"
# End Source File

# Begin Source File
SOURCE="scan_mdl.cpp"
# End Source File

# Begin Source File
SOURCE="parse_zvr.cpp"
# End Source File

# Begin Source File
SOURCE="scan_zvr.cpp"
# End Source File

# Begin Source File
SOURCE="check_zvr.cpp"
# End Source File

# Begin Source File
SOURCE="parse_csv.cpp"
# End Source File

# Begin Source File
SOURCE="scan_csv.cpp"
# End Source File

# Begin Source File
SOURCE="check_csv.cpp"
# End Source File

# Begin Source File
SOURCE="matrix.cpp"
# End Source File

# Begin Source File
SOURCE="check_citi.cpp"
# End Source File

# End Target
# End Project