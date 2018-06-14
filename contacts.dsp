# Microsoft Developer Studio Project File - Name="contacts" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=contacts - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "contacts.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "contacts.mak" CFG="contacts - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "contacts - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "contacts - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "contacts - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "contacts - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "contacts - Win32 Release"
# Name "contacts - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CheckInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\Contact.cpp
# End Source File
# Begin Source File

SOURCE=.\ContactInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\MainDelMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\MainMdfMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\MainNewMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\MainStrategy.cpp
# End Source File
# Begin Source File

SOURCE=.\MainTestMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\MainVewMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\MainVewMenuInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\Person.cpp
# End Source File
# Begin Source File

SOURCE=.\PrtMenuInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\ViewAllMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewCategoryMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewExactMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewFuzzyMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewStrategy.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CheckInterface.h
# End Source File
# Begin Source File

SOURCE=.\Contact.h
# End Source File
# Begin Source File

SOURCE=.\ContactInit.h
# End Source File
# Begin Source File

SOURCE=.\ContactInterface.h
# End Source File
# Begin Source File

SOURCE=.\MainDelMenu.h
# End Source File
# Begin Source File

SOURCE=.\MainMdfMenu.h
# End Source File
# Begin Source File

SOURCE=.\MainNewMenu.h
# End Source File
# Begin Source File

SOURCE=.\MainStrategy.h
# End Source File
# Begin Source File

SOURCE=.\MainTestMenu.h
# End Source File
# Begin Source File

SOURCE=.\MainVewMenu.h
# End Source File
# Begin Source File

SOURCE=.\MainVewMenuInterface.h
# End Source File
# Begin Source File

SOURCE=.\person.h
# End Source File
# Begin Source File

SOURCE=.\PrtMenuInterface.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\ViewAllMenu.h
# End Source File
# Begin Source File

SOURCE=.\ViewCategoryMenu.h
# End Source File
# Begin Source File

SOURCE=.\ViewExactMenu.h
# End Source File
# Begin Source File

SOURCE=.\ViewFuzzyMenu.h
# End Source File
# Begin Source File

SOURCE=.\ViewStrategy.h
# End Source File
# End Group
# End Target
# End Project
