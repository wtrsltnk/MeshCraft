# Microsoft Developer Studio Project File - Name="MeshCraft" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MeshCraft - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MeshCraft.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MeshCraft.mak" CFG="MeshCraft - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MeshCraft - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MeshCraft - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MeshCraft - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "MeshCraft - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../resource" /I "../../_shared" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glu32.lib glaux.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "MeshCraft - Win32 Release"
# Name "MeshCraft - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\source\CApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CWin.cpp
# End Source File
# Begin Source File

SOURCE=..\source\WinMain.cpp
# End Source File
# Begin Source File

SOURCE=..\..\_shared\wiskunde.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\source\CApplication.h
# End Source File
# Begin Source File

SOURCE=..\source\CWin.h
# End Source File
# Begin Source File

SOURCE=..\resource\resource.h
# End Source File
# Begin Source File

SOURCE=..\..\_shared\wiskunde.h
# End Source File
# End Group
# Begin Group "tools"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\CBaseTool.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CBaseTool.h
# End Source File
# Begin Source File

SOURCE=..\source\CToolCamera.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CToolCamera.h
# End Source File
# Begin Source File

SOURCE=..\source\CToolManager.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CToolManager.h
# End Source File
# End Group
# Begin Group "configs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\CBaseConfig.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CBaseConfig.h
# End Source File
# Begin Source File

SOURCE=..\source\CConfigManager.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CConfigManager.h
# End Source File
# End Group
# Begin Group "objects"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\CBaseObject.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CBaseObject.h
# End Source File
# Begin Source File

SOURCE=..\source\CScene.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CScene.h
# End Source File
# Begin Source File

SOURCE=..\source\CTextureManager.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CTextureManager.h
# End Source File
# Begin Source File

SOURCE=..\source\format.h
# End Source File
# Begin Source File

SOURCE=..\source\simple_format.cpp
# End Source File
# Begin Source File

SOURCE=..\source\simple_format.h
# End Source File
# End Group
# Begin Group "views"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\CBaseView.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CBaseView.h
# End Source File
# Begin Source File

SOURCE=..\source\CCamera.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CCamera.h
# End Source File
# Begin Source File

SOURCE=..\source\CLight.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CLight.h
# End Source File
# Begin Source File

SOURCE=..\source\CView3D.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CView3D.h
# End Source File
# Begin Source File

SOURCE=..\source\CViewManager.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CViewManager.h
# End Source File
# End Group
# Begin Group "dialogs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\CBaseDialog.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CBaseDialog.h
# End Source File
# Begin Source File

SOURCE=..\source\CDialogAbout.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CDialogAbout.h
# End Source File
# Begin Source File

SOURCE=..\source\CDialogManager.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CDialogManager.h
# End Source File
# Begin Source File

SOURCE=..\source\CDialogPlugins.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CDialogPlugins.h
# End Source File
# End Group
# Begin Group "plugins"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\source\CPluginFile.h
# End Source File
# Begin Source File

SOURCE=..\source\CPluginManager.cpp
# End Source File
# Begin Source File

SOURCE=..\source\CPluginManager.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\resource\meshcraft.ico
# End Source File
# Begin Source File

SOURCE=..\resource\resource.rc
# End Source File
# Begin Source File

SOURCE=..\resource\screen.bmp
# End Source File
# End Group
# End Target
# End Project
