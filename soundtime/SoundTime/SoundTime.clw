; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COptionsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SoundTime.h"

ClassCount=3
Class1=CSoundTimeApp
Class2=CSoundTimeDlg

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDD_OPTION_DIALOG
Resource3=IDR_ACCELERATOR1
Resource4=IDR_POPUP_EN
Resource5=IDD_SOUNDTIME_DIALOG
Class3=COptionsDlg
Resource6=IDR_POPUP_CN

[CLS:CSoundTimeApp]
Type=0
HeaderFile=SoundTime.h
ImplementationFile=SoundTime.cpp
Filter=N
LastObject=CSoundTimeApp

[CLS:CSoundTimeDlg]
Type=0
HeaderFile=SoundTimeDlg.h
ImplementationFile=SoundTimeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_ENGLISH



[DLG:IDD_SOUNDTIME_DIALOG]
Type=1
Class=CSoundTimeDlg
ControlCount=0

[ACL:IDR_ACCELERATOR1]
Type=1
Class=?
Command1=IDC_DIS
Command2=IDC_EXPAND
Command3=IDC_GIVETIME
Command4=IDC_LIST
CommandCount=4

[MNU:IDR_POPUP_CN]
Type=1
Class=CSoundTimeDlg
Command1=IDC_GIVETIME
Command2=ID_CHINESE
Command3=ID_ENGLISH
Command4=IDC_OPTIONS
Command5=IDC_ABOUT
Command6=IDC_HIDE
Command7=IDC_EXIT
CommandCount=7

[MNU:IDR_POPUP_EN]
Type=1
Class=CSoundTimeDlg
Command1=IDC_GIVETIME
Command2=ID_CHINESE
Command3=ID_ENGLISH
Command4=IDC_OPTIONS
Command5=IDC_ABOUT
Command6=IDC_HIDE
Command7=IDC_EXIT
CommandCount=7

[DLG:IDD_OPTION_DIALOG]
Type=1
Class=COptionsDlg
ControlCount=33
Control1=IDC_1,button,1342311689
Control2=IDC_2,button,1342180617
Control3=IDC_3,button,1342180617
Control4=IDC_4,button,1342180617
Control5=IDC_5,button,1342180617
Control6=IDC_6,button,1342180617
Control7=IDC_7,button,1342180617
Control8=IDC_8,button,1342180617
Control9=IDC_9,button,1342180617
Control10=IDC_10,button,1342180617
Control11=IDC_PATH,edit,1342242944
Control12=IDC_BELL,button,1342177287
Control13=IDC_OK,button,1342275585
Control14=IDC_BROWSE,button,1342275584
Control15=IDC_INPUT_HOUR,edit,1342251136
Control16=IDC_STATIC,static,1342308352
Control17=IDC_INPUT_MIN,edit,1342251136
Control18=IDC_CLEAR,button,1342275584
Control19=IDC_PLAY,button,1342275584
Control20=IDC_SET,static,1342308352
Control21=IDC_MESSAGE,static,1342308352
Control22=IDC_ALARM,button,1342177287
Control23=IDC_CODE,button,1342275584
Control24=IDC_INPUT_MESSAGE,edit,1342242944
Control25=IDC_TRANSPARENT,button,1342177287
Control26=IDC_CANCEL,button,1342275584
Control27=IDC_DOWNLOAD,button,1342275584
Control28=IDC_TRANS_ON,button,1342311689
Control29=IDC_TRANS_OFF,button,1342180617
Control30=IDC_ALARM_ON,button,1342311689
Control31=IDC_ALARM_OFF,button,1342180617
Control32=IDC_ALARM_STAT,static,1342177280
Control33=IDC_TRANS_STAT,static,1342177280

[CLS:COptionsDlg]
Type=0
HeaderFile=OptionsDlg.h
ImplementationFile=OptionsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=COptionsDlg
VirtualFilter=dWC

