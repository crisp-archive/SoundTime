/* 
** Sound Time - SoundTimeDlg.cpp
** Copyright: David Zhang
** E-Mail   : crispgm@gmail.com
** Edited   : 2006-07-28
*/

#include "stdafx.h"
#include "SoundTime.h"
#include "OptionsDlg.h"
#include "SoundTimeDlg.h"
#include "Spell.h"
#include "File.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CSoundTimeDlg::CSoundTimeDlg(CWnd* pParent /*=NULL*/)
: CDialog(CSoundTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSoundTimeDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSoundTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSoundTimeDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSoundTimeDlg, CDialog)
//{{AFX_MSG_MAP(CSoundTimeDlg)
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_ABOUT, OnAbout)
ON_BN_CLICKED(IDC_GIVETIME, OnGivetime)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_HIDE, OnHide)
ON_WM_CONTEXTMENU()
ON_COMMAND(IDC_EXIT, OnExit)
ON_COMMAND(IDC_CHINESE, OnChinese)
ON_COMMAND(IDC_ENGLISH, OnEnglish)
ON_WM_MOUSEMOVE()
ON_WM_CLOSE()
ON_BN_CLICKED(IDC_OPTIONS, OnOptions)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoundTimeDlg message handlers

BOOL CSoundTimeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// get init file
	CProfile pro;
	m_profile=pro.GetProfile();
	// get local time
	::GetLocalTime(&m_SysTime);
	// transparent effect
	if(m_profile.Is_transparent==TRUE){
		SetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE,GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)^0x80000);
		HINSTANCE hInst=LoadLibrary("User32.DLL");
		if(hInst){
			typedef BOOL (WINAPI* MYFUNC)(HWND,COLORREF,BYTE,DWORD);
			MYFUNC fun=NULL;
			fun=(MYFUNC)GetProcAddress(hInst,"SetLayeredWindowAttributes");
			if(fun){
				fun(this->GetSafeHwnd(),0,128,2);
			}
			FreeLibrary(hInst);
		}
	}
	// set on top
	::SetWindowPos(AfxGetMainWnd()->m_hWnd,HWND_TOPMOST,-1,-1,-1,-1,SWP_NOMOVE|SWP_NOSIZE);
	// display language
	SetInterface();
	// init timer
	SetTimer(0,0,NULL);
	
	return TRUE;
}

void CSoundTimeDlg::OnPaint() 
{
	if (IsIconic()){
		CPaintDC dc(this);
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else{
		CDialog::OnPaint();
	}
}

HCURSOR CSoundTimeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSoundTimeDlg::OnAbout()
{
	ShellExecute(NULL,"open","st9.htm",NULL,NULL,SW_SHOWNORMAL);
}

void CSoundTimeDlg::SetInterface()
{
	MoveWindow(350,0,150,20,TRUE);
}

void CSoundTimeDlg::OnGivetime() 
{
	CSpell spell;
	ShowWindow(SW_HIDE);
	spell.SpellTime(CSoundTimeDlg::m_SysTime);
	ShowWindow(SW_SHOW);
}

void CSoundTimeDlg::OnTimer(UINT nIDEvent)
{
	GetLocalTime(&m_SysTime);
	strcpy(m_szStr,"Sound Time ");
	if(m_SysTime.wHour<10){
		strcat(m_szStr,"0");
	}
	itoa(m_SysTime.wHour,temp,10);
	strcat(m_szStr,temp);
	strcat(m_szStr,":");
	if(m_SysTime.wMinute<10){
		strcat(m_szStr,"0");
	}
	itoa(m_SysTime.wMinute,temp,10);
	strcat(m_szStr,temp);
	strcat(m_szStr,":");
	if(m_SysTime.wSecond<10){
		strcat(m_szStr,"0");
	}
	itoa(m_SysTime.wSecond,temp,10);
	strcat(m_szStr,temp);
	strcat(m_szStr,":");
	itoa(m_SysTime.wMilliseconds,temp,10);
	strcat(m_szStr,temp);
	SetWindowText(m_szStr);
	

	int nCmdID;
	if(m_profile.Is_bell==TRUE && m_profile.Bell_info.Hour==m_SysTime.wHour && m_profile.Bell_info.Minute==m_SysTime.wMinute && m_SysTime.wSecond==0){
		ShowWindow(SW_HIDE);
		PlaySound(m_profile.Bell_info.Path,NULL,SND_ALIAS);
		ShowWindow(SW_SHOW);
		nCmdID=SpecialMessage(m_profile.Bell_info.Message);
		if(nCmdID!=0){
			CSoundTimeDlg::DoAsCommand(nCmdID);
		}
		else{
			MessageBox(m_profile.Bell_info.Message,"Sound Time",MB_OK|MB_ICONINFORMATION);
		}
	}

	UpdateData(FALSE);
	
	CDialog::OnTimer(nIDEvent);
}

void CSoundTimeDlg::OnHide() 
{
	int nIsHide;
	if(m_profile.Language==CHINESE){
		nIsHide=MessageBox("ÄúÊÇ·ñÏ£ÍûÒþ²ØSound Time?","Sound Time",MB_OKCANCEL|MB_ICONQUESTION|MB_DEFBUTTON2);
	}
	if(m_profile.Language==ENGLISH){
		nIsHide=MessageBox("Do you wish to hide Sound Time?","Sound Time",MB_OKCANCEL|MB_ICONQUESTION|MB_DEFBUTTON2);
	}
	if(nIsHide==IDOK){
		ShowWindow(SW_HIDE);
	}
	else{
		return;
	}
}

void CSoundTimeDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CMenu menu;
	if(m_profile.Language==ENGLISH){
		VERIFY(menu.LoadMenu(IDR_POPUP_EN));
		menu.CheckMenuItem(IDC_ENGLISH,MF_CHECKED);
	}
	if(m_profile.Language==CHINESE){
		VERIFY(menu.LoadMenu(IDR_POPUP_CN));
		menu.CheckMenuItem(IDC_CHINESE,MF_CHECKED);
	}
	CMenu* pPopup=menu.GetSubMenu(0);
	ASSERT(pPopup!=NULL);
	CWnd* pWndPopupOwner=this;
	while (pWndPopupOwner->GetStyle() & WS_CHILD){
		pWndPopupOwner=pWndPopupOwner->GetParent();
	}
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, pWndPopupOwner);
}

void CSoundTimeDlg::OnExit() 
{
	int nIsExit;
	if(m_profile.Language==CHINESE)
		nIsExit=MessageBox("ÄúÊÇ·ñÏ£Íû¹Ø±ÕSound Time?","Sound Time",MB_OKCANCEL|MB_ICONQUESTION|MB_DEFBUTTON2);
	if(m_profile.Language==ENGLISH)
		nIsExit=MessageBox("Do you wish to exit Sound Time?","Sound Time",MB_OKCANCEL|MB_ICONQUESTION|MB_DEFBUTTON2);
	if(nIsExit==IDOK){
		CSoundTimeDlg::EndDialog(TRUE);
	}
}

void CSoundTimeDlg::OnChinese()
{
	m_profile.Language=CHINESE;
	CProfile pro;
	pro.WriteProfile(m_profile);
}

void CSoundTimeDlg::OnEnglish()
{
	m_profile.Language=ENGLISH;
	CProfile pro;
	pro.WriteProfile(m_profile);
}

int CSoundTimeDlg::SpecialMessage(char* szMessage)
{
	int nRetID;
	if(strcmp(szMessage,"com:shutdown")==0)
		nRetID=ID_SHUTDOWN;
	else if(strcmp(szMessage,"com:exit")==0)
		nRetID=ID_EXIT;
	else
		nRetID=0;
	return nRetID;
	
}

void CSoundTimeDlg::DoAsCommand(int nCmdID)
{
	HANDLE hToken; 
	TOKEN_PRIVILEGES tkp; 
	switch(nCmdID){
	case ID_SHUTDOWN:
		if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) 
		{
			MessageBox("OpenProcessToken");
		}
		LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid); 		
		tkp.PrivilegeCount = 1;
		tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 		
		AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,(PTOKEN_PRIVILEGES)NULL, 0); 		
		if (GetLastError() != ERROR_SUCCESS){
			MessageBox("AdjustTokenPrivileges");
		}
		if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0)){
			MessageBox("ExitWindowsEx"); 
		}
		break;
	case ID_EXIT:
		CSoundTimeDlg::EndDialog(TRUE);
		break;
	default:
		break;
	}
	return;
}

void CSoundTimeDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	CDialog::OnMouseMove(nFlags, point);
}

void CSoundTimeDlg::OnClose() 
{
	CProfile pro;
	pro.WriteProfile(m_profile);
	KillTimer(0);
	CDialog::OnClose();
}

void CSoundTimeDlg::OnOptions()
{
	COptionsDlg dlg;
	dlg.DoModal();
	CProfile pro;
	m_profile=pro.GetProfile();
}
