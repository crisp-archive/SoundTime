#if !defined(AFX_OPTIONSDLG_H__3A5E4F84_4BF7_4C3D_A28F_D24E89B75D16__INCLUDED_)
#define AFX_OPTIONSDLG_H__3A5E4F84_4BF7_4C3D_A28F_D24E89B75D16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsDlg.h : header file
//
#include "file.h"

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog

class COptionsDlg : public CDialog
{
// Construction
public:
	COptionsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptionsDlg)
	enum { IDD = IDD_OPTION_DIALOG };
	int		m_nID;
	//}}AFX_DATA

	ST_PROFILE m_profile;
	char szStr[255];
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptionsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBrowse();
	afx_msg void OnCancel();
	afx_msg void On1();
	afx_msg void On2();
	afx_msg void On3();
	afx_msg void On4();
	afx_msg void On5();
	afx_msg void On6();
	afx_msg void On7();
	afx_msg void On8();
	afx_msg void On9();
	afx_msg void On10();
	afx_msg void OnPlay();
	afx_msg void OnDownload();
	afx_msg void OnClear();
	afx_msg void OnCode();
	afx_msg void OnAlarmOn();
	afx_msg void OnAlarmOff();
	afx_msg void OnTransOn();
	afx_msg void OnTransOff();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSDLG_H__3A5E4F84_4BF7_4C3D_A28F_D24E89B75D16__INCLUDED_)
