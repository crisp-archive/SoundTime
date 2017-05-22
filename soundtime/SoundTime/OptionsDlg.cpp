// OptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SoundTime.h"
#include "SoundTimeDlg.h"
#include "OptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog


COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
: CDialog(COptionsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptionsDlg)
	m_nID = -1;
	//}}AFX_DATA_INIT
}


void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsDlg)
	DDX_Radio(pDX, IDC_1, m_nID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
//{{AFX_MSG_MAP(COptionsDlg)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
ON_BN_CLICKED(IDC_1, On1)
ON_BN_CLICKED(IDC_2, On2)
ON_BN_CLICKED(IDC_3, On3)
ON_BN_CLICKED(IDC_4, On4)
ON_BN_CLICKED(IDC_5, On5)
ON_BN_CLICKED(IDC_6, On6)
ON_BN_CLICKED(IDC_7, On7)
ON_BN_CLICKED(IDC_8, On8)
ON_BN_CLICKED(IDC_9, On9)
ON_BN_CLICKED(IDC_10, On10)
ON_BN_CLICKED(IDC_PLAY, OnPlay)
ON_BN_CLICKED(IDC_DOWNLOAD, OnDownload)
ON_BN_CLICKED(IDC_CLEAR, OnClear)
ON_BN_CLICKED(IDC_CODE, OnCode)
ON_BN_CLICKED(IDC_ALARM_ON, OnAlarmOn)
ON_BN_CLICKED(IDC_ALARM_OFF, OnAlarmOff)
ON_BN_CLICKED(IDC_TRANS_ON, OnTransOn)
ON_BN_CLICKED(IDC_TRANS_OFF, OnTransOff)
ON_BN_CLICKED(IDC_CANCEL, OnCancel)
ON_BN_CLICKED(IDC_OK, OnOk)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg message handlers

BOOL COptionsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetTimer(0,0,NULL);
	
	CProfile pro;
	m_profile=pro.GetProfile();
	if(m_profile.Language==CHINESE){
		SetWindowText("选项");
		SetDlgItemText(IDC_1,"少女的祈祷");
		SetDlgItemText(IDC_2,"花之圆舞曲");
		SetDlgItemText(IDC_3,"土耳其进行曲");
		SetDlgItemText(IDC_4,"命运交响曲");
		SetDlgItemText(IDC_5,"拉德斯基进行曲");
		SetDlgItemText(IDC_6,"雷电波尔卡");
		SetDlgItemText(IDC_7,"狩猎波尔卡");
		SetDlgItemText(IDC_8,"闲聊波尔卡");
		SetDlgItemText(IDC_9,"南国玫瑰圆舞曲");
		SetDlgItemText(IDC_10,"维也纳森林的故事");
		
		SetDlgItemText(IDC_BELL,"选择铃声");
		SetDlgItemText(IDC_ALARM,"闹铃设置");
		SetDlgItemText(IDC_TRANSPARENT,"半透明窗体效果");
		SetDlgItemText(IDC_BROWSE,"浏览");
		SetDlgItemText(IDC_OK,"确定");
		SetDlgItemText(IDC_CANCEL,"取消");
		SetDlgItemText(IDC_PLAY,"试听");
		SetDlgItemText(IDC_CODE,"代码");
		SetDlgItemText(IDC_CLEAR,"清空");
		SetDlgItemText(IDC_DOWNLOAD,"下载铃声");
		
		SetDlgItemText(IDC_SET,"设置时间");
		SetDlgItemText(IDC_MESSAGE,"提示信息");
		
		SetDlgItemText(IDC_ALARM_ON,"开启");
		SetDlgItemText(IDC_ALARM_OFF,"关闭");
		SetDlgItemText(IDC_TRANS_ON,"开启");
		SetDlgItemText(IDC_TRANS_OFF,"关闭");
	}
	if(m_profile.Language==ENGLISH){
		SetWindowText("Options");
		SetDlgItemText(IDC_1,"Maiden's Pray");
		SetDlgItemText(IDC_2,"the Waltz of Flowers");
		SetDlgItemText(IDC_3,"Turkey March");
		SetDlgItemText(IDC_4,"Destiny");
		SetDlgItemText(IDC_5,"Radetzky March");
		SetDlgItemText(IDC_6,"Thunder and Lightning");
		SetDlgItemText(IDC_7,"the Hunt");
		SetDlgItemText(IDC_8,"Chitchat Polka");
		SetDlgItemText(IDC_9,"Roses from the South");
		SetDlgItemText(IDC_10,"Tales from the Vienna Woods");
		
		SetDlgItemText(IDC_BELL,"Bell");
		SetDlgItemText(IDC_ALARM,"Alarm settings");
		SetDlgItemText(IDC_TRANSPARENT,"Semi-transparent effect");
		SetDlgItemText(IDC_BROWSE,"Browse");
		SetDlgItemText(IDC_OK,"OK");
		SetDlgItemText(IDC_CANCEL,"Cancel");
		SetDlgItemText(IDC_PLAY,"Play");
		SetDlgItemText(IDC_CODE,"Code");
		SetDlgItemText(IDC_CLEAR,"Clear");
		SetDlgItemText(IDC_DOWNLOAD,"Download");
		
		SetDlgItemText(IDC_SET,"Set time");
		SetDlgItemText(IDC_MESSAGE,"Message");
		
		SetDlgItemText(IDC_ALARM_ON,"On");
		SetDlgItemText(IDC_ALARM_OFF,"Off");
		SetDlgItemText(IDC_TRANS_ON,"On");
		SetDlgItemText(IDC_TRANS_OFF,"Off");
	}
	
	if(m_profile.Is_transparent==TRUE){
		SetDlgItemText(IDC_TRANS_STAT,"On");
	}
	else{
		SetDlgItemText(IDC_TRANS_STAT,"Off");
	}
	
	if(m_profile.Is_bell==TRUE){
		SetDlgItemText(IDC_ALARM_STAT,"On");
		itoa(m_profile.Bell_info.Hour,szStr,10);
		SetDlgItemText(IDC_INPUT_HOUR,szStr);
		itoa(m_profile.Bell_info.Minute,szStr,10);
		SetDlgItemText(IDC_INPUT_MIN,szStr);
		SetDlgItemText(IDC_PATH,m_profile.Bell_info.Path);
		SetDlgItemText(IDC_INPUT_MESSAGE,m_profile.Bell_info.Message);
	}
	else{
		SetDlgItemText(IDC_ALARM_STAT,"Off");
	}
	
	
	return TRUE;
}

void COptionsDlg::OnTimer(UINT nIDEvent) 
{
	UpdateData(TRUE);
	
	CDialog::OnTimer(nIDEvent);
}

void COptionsDlg::OnBrowse() 
{
	char temp[255];
	CFileDialog dlg(TRUE,NULL,NULL,OFN_OVERWRITEPROMPT,"WAV Files|*.wav",NULL);
	if(dlg.DoModal()){
		strcpy(temp,dlg.GetPathName());
		SetDlgItemText(IDC_PATH,temp);
		UpdateData(FALSE);
	}
}

void COptionsDlg::OnCancel() 
{
	EndDialog(TRUE);
}

void COptionsDlg::On1() 
{
	SetDlgItemText(IDC_PATH,"Bell\\1.wav");
}

void COptionsDlg::On2() 
{
	SetDlgItemText(IDC_PATH,"Bell\\2.wav");	
}

void COptionsDlg::On3() 
{
	SetDlgItemText(IDC_PATH,"Bell\\3.wav");
}

void COptionsDlg::On4() 
{
	SetDlgItemText(IDC_PATH,"Bell\\4.wav");
}

void COptionsDlg::On5() 
{
	SetDlgItemText(IDC_PATH,"Bell\\5.wav");
}

void COptionsDlg::On6() 
{
	SetDlgItemText(IDC_PATH,"Bell\\6.wav");
}

void COptionsDlg::On7() 
{
	SetDlgItemText(IDC_PATH,"Bell\\7.wav");
}

void COptionsDlg::On8() 
{
	SetDlgItemText(IDC_PATH,"Bell\\8.wav");
}

void COptionsDlg::On9() 
{
	SetDlgItemText(IDC_PATH,"Bell\\9.wav");
}

void COptionsDlg::On10() 
{
	SetDlgItemText(IDC_PATH,"Bell\\10.wav");
}

void COptionsDlg::OnPlay() 
{
	GetDlgItemText(IDC_PATH,szStr,255);
	FILE* op=fopen(szStr,"r");
	if(op){
		fclose(op);
		ShowWindow(SW_HIDE);
		PlaySound(szStr,NULL,SND_ALIAS);
		ShowWindow(SW_SHOW);
	}
}

void COptionsDlg::OnDownload() 
{
	ShellExecute(NULL,"open","http://crispgm.googlepages.com/bell",NULL,NULL,SW_SHOWNORMAL);
}

void COptionsDlg::OnClear() 
{
	SetDlgItemText(IDC_INPUT_HOUR,"");
	SetDlgItemText(IDC_INPUT_MIN,"");
	SetDlgItemText(IDC_INPUT_MESSAGE,"");
}

void COptionsDlg::OnCode() 
{
	MessageBox("com:shutdown\r\ncom:exit\r\n","Sound Time",MB_ICONINFORMATION);
}

void COptionsDlg::OnAlarmOn() 
{
	SetDlgItemText(IDC_ALARM_STAT,"On");
	m_profile.Is_bell=TRUE;
}

void COptionsDlg::OnAlarmOff() 
{
	SetDlgItemText(IDC_ALARM_STAT,"Off");
	m_profile.Is_bell=FALSE;
}

void COptionsDlg::OnTransOn() 
{
	SetDlgItemText(IDC_TRANS_STAT,"On");
	if(m_profile.Language==CHINESE){
		MessageBox("需要重新启动本软件","Sound Time",MB_OK|MB_ICONINFORMATION);
	}
	if(m_profile.Language==ENGLISH){
		MessageBox("Need restart","Sound Time",MB_OK|MB_ICONINFORMATION);
	}
	m_profile.Is_transparent=TRUE;
}

void COptionsDlg::OnTransOff() 
{
	SetDlgItemText(IDC_TRANS_STAT,"Off");
	if(m_profile.Language==CHINESE){
		MessageBox("需要重新启动本软件","Sound Time",MB_OK|MB_ICONINFORMATION);
	}
	if(m_profile.Language==ENGLISH){
		MessageBox("Need restart","Sound Time",MB_OK|MB_ICONINFORMATION);
	}
	m_profile.Is_transparent=FALSE;
}

void COptionsDlg::OnOk() 
{
	CProfile pro;
	if(m_profile.Is_bell==TRUE){
		GetDlgItemText(IDC_INPUT_MESSAGE,m_profile.Bell_info.Message,255);
		
		GetDlgItemText(IDC_PATH,m_profile.Bell_info.Path,255);
		FILE* op=fopen(m_profile.Bell_info.Path,"r");
		if(!op){
			goto end;
		}
		else{
			fclose(op);
		}
		
		GetDlgItemText(IDC_INPUT_HOUR,szStr,255);
		int i;
		i=atoi(szStr);
		if(i<0 || i>23){
			goto end;
		}
		m_profile.Bell_info.Hour=i;
		
		GetDlgItemText(IDC_INPUT_MIN,szStr,255);
		i=atoi(szStr);
		if(i<0 || i>59){
			goto end;
		}
		m_profile.Bell_info.Minute=i;
	}
	pro.WriteProfile(m_profile);
end:
	EndDialog(TRUE);
}
