# Microsoft Developer Studio Project File - Name="libverilog" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
#
# libverilog.dsp generated by autodsp 1.0.2 from libverilog.ap
#

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!MESSAGE There are 2 configurations.
!MESSAGE "libverilog - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libverilog - Win32 Debug" (based on "Win32 (x86) Static Library")

# Begin Project
CPP=cl.exe
RSC=rc.exe
BSC32=bscmake.exe
LINK32=link.exe
LIB32=link.exe -lib
MTL=midl.exe

!IF "$(CFG)" == "libverilog - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Opt"
# PROP Intermediate_Dir "Opt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GX /O2 /Ob2 /I ".." /I "../.." /I "../../.." /I "../devices" /I "../../math" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /FD /c
# ADD RSC /l 0x409 /d "NDEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /dll /pdb:none /incremental:no /machine:I386

!ELSEIF "$(CFG)" == "libverilog - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Dbg"
# PROP Intermediate_Dir "Dbg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I ".." /I "../.." /I "../../.." /I "../devices" /I "../../math" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "__MINGW32__" /D "HAVE_CONFIG_H" /D __STDC__=0 /D "DEBUG" /FD /c
# ADD RSC /l 0x409 /d "_DEBUG"
# ADD BSC32 /nologo
# ADD LIB32 /nologo
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /dll /pdb:none /incremental:no /debug /machine:I386

!ENDIF

# Begin Target
# Name "libverilog - Win32 Release"
# Name "libverilog - Win32 Debug"

# Begin Source File
SOURCE="HBT_X.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="HBT_X.core.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL2V2p1.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL2V2p1.core.cpp"
# End Source File

# Begin Source File
SOURCE="mod_amp.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="mod_amp.core.cpp"
# End Source File

# Begin Source File
SOURCE="hic2_full.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="hic2_full.core.cpp"
# End Source File

# Begin Source File
SOURCE="log_amp.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="log_amp.core.cpp"
# End Source File

# Begin Source File
SOURCE="hic0_full.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="hic0_full.core.cpp"
# End Source File

# Begin Source File
SOURCE="potentiometer.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="potentiometer.core.cpp"
# End Source File

# Begin Source File
SOURCE="MESFET.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="MESFET.core.cpp"
# End Source File

# Begin Source File
SOURCE="EKV26MOS.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="EKV26MOS.core.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL0V1p2.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL0V1p2.core.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL0V1p2g.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL0V1p2g.core.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL2V2p23.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL2V2p23.core.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL2V2p24.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="hicumL2V2p24.core.cpp"
# End Source File

# Begin Source File
SOURCE="photodiode.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="photodiode.core.cpp"
# End Source File

# Begin Source File
SOURCE="phototransistor.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="phototransistor.core.cpp"
# End Source File

# Begin Source File
SOURCE="nigbt.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="nigbt.core.cpp"
# End Source File

# Begin Source File
SOURCE="dff_SR.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="dff_SR.core.cpp"
# End Source File

# Begin Source File
SOURCE="tff_SR.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="tff_SR.core.cpp"
# End Source File

# Begin Source File
SOURCE="jkff_SR.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="jkff_SR.core.cpp"
# End Source File

# Begin Source File
SOURCE="gatedDlatch.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="gatedDlatch.core.cpp"
# End Source File

# Begin Source File
SOURCE="logic_0.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="logic_0.core.cpp"
# End Source File

# Begin Source File
SOURCE="logic_1.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="logic_1.core.cpp"
# End Source File

# Begin Source File
SOURCE="mux2to1.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="mux2to1.core.cpp"
# End Source File

# Begin Source File
SOURCE="mux4to1.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="mux4to1.core.cpp"
# End Source File

# Begin Source File
SOURCE="mux8to1.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="mux8to1.core.cpp"
# End Source File

# Begin Source File
SOURCE="DLS_nto1.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="DLS_nto1.core.cpp"
# End Source File

# Begin Source File
SOURCE="DLS_1ton.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="DLS_1ton.core.cpp"
# End Source File

# Begin Source File
SOURCE="andor4x2.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="andor4x2.core.cpp"
# End Source File

# Begin Source File
SOURCE="andor4x3.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="andor4x3.core.cpp"
# End Source File

# Begin Source File
SOURCE="andor4x4.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="andor4x4.core.cpp"
# End Source File

# Begin Source File
SOURCE="dmux2to4.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="dmux2to4.core.cpp"
# End Source File

# Begin Source File
SOURCE="dmux3to8.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="dmux3to8.core.cpp"
# End Source File

# Begin Source File
SOURCE="dmux4to16.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="dmux4to16.core.cpp"
# End Source File

# Begin Source File
SOURCE="ha1b.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="ha1b.core.cpp"
# End Source File

# Begin Source File
SOURCE="fa1b.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="fa1b.core.cpp"
# End Source File

# Begin Source File
SOURCE="fa2b.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="fa2b.core.cpp"
# End Source File

# Begin Source File
SOURCE="pad2bit.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="pad2bit.core.cpp"
# End Source File

# Begin Source File
SOURCE="pad3bit.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="pad3bit.core.cpp"
# End Source File

# Begin Source File
SOURCE="pad4bit.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="pad4bit.core.cpp"
# End Source File

# Begin Source File
SOURCE="binarytogrey4bit.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="binarytogrey4bit.core.cpp"
# End Source File

# Begin Source File
SOURCE="greytobinary4bit.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="greytobinary4bit.core.cpp"
# End Source File

# Begin Source File
SOURCE="comp_1bit.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="comp_1bit.core.cpp"
# End Source File

# Begin Source File
SOURCE="comp_2bit.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="comp_2bit.core.cpp"
# End Source File

# Begin Source File
SOURCE="comp_4bit.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="comp_4bit.core.cpp"
# End Source File

# Begin Source File
SOURCE="hpribin4bit.analogfunction.cpp"
# End Source File

# Begin Source File
SOURCE="hpribin4bit.core.cpp"
# End Source File

# End Target
# End Project
