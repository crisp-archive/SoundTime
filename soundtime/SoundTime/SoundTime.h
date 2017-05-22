// SoundTime.h : main header file for the SOUNDTIME application
//

#if !defined(AFX_SOUNDTIME_H__DD279EF0_5011_4204_AC3C_D3F3BE00DBFA__INCLUDED_)
#define AFX_SOUNDTIME_H__DD279EF0_5011_4204_AC3C_D3F3BE00DBFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSoundTimeApp:
// See SoundTime.cpp for the implementation of this class
//

class CSoundTimeApp : public CWinApp
{
public:
	CSoundTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSoundTimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSoundTimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOUNDTIME_H__DD279EF0_5011_4204_AC3C_D3F3BE00DBFA__INCLUDED_)
