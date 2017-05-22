
#if !defined(AFX_SPELL_H__29AEF81E_9550_468A_9627_F45688F32866__INCLUDED_)
#define AFX_SPELL_H__29AEF81E_9550_468A_9627_F45688F32866__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Spell.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpell dialog

class CSpell : public CDialog
{
	// Construction
public:
	CSpell(CWnd* pParent = NULL);   // standard constructor
	
	typedef struct tagCURRENTTIME
	{
		WORD wHour;
		WORD wMin;
	}CURRTIME;
	
	typedef struct tagTIMEPART
	{
		WORD wHourCarry;
		WORD wHour;
		WORD wMinCarry;
		WORD wMin;
		BOOL bIsMinZero;
	} TIMEPART;
	
	CURRTIME ConvertTime(SYSTEMTIME SysTime);
	TIMEPART DivTime(CURRTIME CurrTime);
	void SpellTime(SYSTEMTIME SysTime);
	void PlayTime(int nSoundId,int nLang);
	void PlaySpecial(int nSpecialId);
	// Dialog Data
	//{{AFX_DATA(CSpell)
	enum { IDD = IDD_SOUNDTIME_DIALOG };
	// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpell)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(CSpell)
	// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPELL_H__29AEF81E_9550_468A_9627_F45688F32866__INCLUDED_)
