// SoundTimeDlg.h : header file
//
#include "File.h"

#if !defined(AFX_SOUNDTIMEDLG_H__848B161E_CF7E_4FEF_91D4_48B6F3EE4405__INCLUDED_)
#define AFX_SOUNDTIMEDLG_H__848B161E_CF7E_4FEF_91D4_48B6F3EE4405__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSoundTimeDlg dialog

#define CHINESE 0x522
#define ENGLISH 0x806

#define ID_SHUTDOWN 1001
#define ID_EXIT		1002
#define ID_NOGREET  1003
#define ID_GREET    1004


class CSoundTimeDlg : public CDialog
{
// Construction
public:
	CSoundTimeDlg(CWnd* pParent = NULL);	// standard constructor

	ST_PROFILE m_profile;
	SYSTEMTIME m_SysTime;
	char temp[10];
	char m_szStr[255];

	void SetInterface();
	int  SpecialMessage(char* szMessage);
	void DoAsCommand(int nCmdID);
	
// Dialog Data
	//{{AFX_DATA(CSoundTimeDlg)
	enum { IDD = IDD_SOUNDTIME_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoundTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSoundTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbout();
	afx_msg void OnGivetime();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnHide();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnExit();
	afx_msg void OnChinese();
	afx_msg void OnEnglish();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCallhelp();
	afx_msg void OnClose();
	afx_msg void OnOptions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOUNDTIMEDLG_H__848B161E_CF7E_4FEF_91D4_48B6F3EE4405__INCLUDED_)
