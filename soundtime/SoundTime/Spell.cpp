/* 
** Sound Time - Bell.cpp
** Copyright: David Zhang
** E-Mail   : crispgm@gmail.com
** Edited   : 2006-07-26
*/

#include "stdafx.h"
#include "SoundTime.h"
#include "Spell.h"
#include "SoundTimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CSpell::CSpell(CWnd* pParent /*=NULL*/)
: CDialog(CSpell::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpell)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSpell::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpell)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSpell, CDialog)
//{{AFX_MSG_MAP(CSpell)
// NOTE: the ClassWizard will add message map macros here
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpell message handlers
CSpell::CURRTIME CSpell::ConvertTime(SYSTEMTIME SysTime)
{
	CSpell::CURRTIME CurrTime;
	CurrTime.wHour=SysTime.wHour;
	CurrTime.wMin=SysTime.wMinute;
	return CurrTime;
}

CSpell::TIMEPART CSpell::DivTime(CURRTIME CurrTime)
{
	TIMEPART TimePart;
	
	if(CurrTime.wMin==0)
		TimePart.bIsMinZero=TRUE;
	
	if(CurrTime.wHour<10 || CurrTime.wHour%10==0)
		TimePart.wHour=CurrTime.wHour;
	
	else if(CurrTime.wHour>10 && CurrTime.wHour<20){
		TimePart.wHourCarry=10;
		TimePart.wHour=CurrTime.wHour-10;
	}
	else if(CurrTime.wHour>20 && CurrTime.wHour<30){
		TimePart.wHourCarry=20;
		TimePart.wHour=CurrTime.wHour-20;
	}
	else if(CurrTime.wHour>30 && CurrTime.wHour<40){
		TimePart.wHourCarry=30;
		TimePart.wHour=CurrTime.wHour-30;
	}
	else if(CurrTime.wHour>40 && CurrTime.wHour<50){
		TimePart.wHourCarry=40;
		TimePart.wHour=CurrTime.wHour-40;
	}
	else if(CurrTime.wHour>50){
		TimePart.wHourCarry=50;
		TimePart.wHour=CurrTime.wHour-50;
	}
	
	if(CurrTime.wMin<10 || CurrTime.wMin%10==0)
		TimePart.wMin=CurrTime.wMin;
	else if(CurrTime.wMin>10 && CurrTime.wMin<20){
		TimePart.wMinCarry=10;
		TimePart.wMin=CurrTime.wMin-10;
	}
	else if(CurrTime.wMin>20 && CurrTime.wMin<30){
		TimePart.wMinCarry=20;
		TimePart.wMin=CurrTime.wMin-20;
	}
	else if(CurrTime.wMin>30 && CurrTime.wMin<40){
		TimePart.wMinCarry=30;
		TimePart.wMin=CurrTime.wMin-30;
	}
	else if(CurrTime.wMin>40 && CurrTime.wMin<50){
		TimePart.wMinCarry=40;
		TimePart.wMin=CurrTime.wMin-40;
	}
	else if(CurrTime.wMin>50){
		TimePart.wMinCarry=50;
		TimePart.wMin=CurrTime.wMin-50;
	}
	
	return TimePart;
}

void CSpell::SpellTime(SYSTEMTIME SysTime)
{
	
	CProfile pro;
	ST_PROFILE sp;
	sp=pro.GetProfile();
	
	if(sp.Language==CHINESE)
		PlaySound("Time/cur_cn.wav",NULL,SND_ALIAS);
	if(sp.Language==ENGLISH)
		PlaySound("Time/cur_en.wav",NULL,SND_ALIAS);
	
	CURRTIME CurrTime=CSpell::ConvertTime(SysTime);
	TIMEPART TimePart=CSpell::DivTime(CurrTime);
	
	if(sp.Language==CHINESE){
		CSpell::PlayTime(TimePart.wHourCarry,sp.Language);
		CSpell::PlayTime(TimePart.wHour,sp.Language);
		CSpell::PlayTime(61,sp.Language);
		CSpell::PlayTime(TimePart.wMinCarry,sp.Language);
		CSpell::PlayTime(TimePart.wMin,sp.Language);
		CSpell::PlayTime(62,sp.Language);
	}
	
	if(sp.Language==ENGLISH){
		
		if(CurrTime.wHour<20 && CurrTime.wHour>10)
			PlaySpecial(CurrTime.wHour);
		else{
			CSpell::PlayTime(TimePart.wHourCarry,sp.Language);
			CSpell::PlayTime(TimePart.wHour,sp.Language);
		}
		
		if(TimePart.bIsMinZero==TRUE)
			CSpell::PlayTime(63,sp.Language);
		else{
			if(CurrTime.wMin<20 && CurrTime.wMin>10)
				PlaySpecial(CurrTime.wMin);		
			else{
				CSpell::PlayTime(TimePart.wMinCarry,sp.Language);
				CSpell::PlayTime(TimePart.wMin,sp.Language);
			}
		}
	}
	
}

void CSpell::PlaySpecial(int nSpecialId)
{
	switch(nSpecialId){
	case 11:
		PlaySound("Time/11.wav",NULL,SND_ALIAS);
		break;
	case 12:
		PlaySound("Time/12.wav",NULL,SND_ALIAS);
		break;
	case 13:
		PlaySound("Time/13.wav",NULL,SND_ALIAS);
		break;
	case 14:
		PlaySound("Time/14.wav",NULL,SND_ALIAS);
		break;
	case 15:
		PlaySound("Time/15.wav",NULL,SND_ALIAS);
		break;
	case 16:
		PlaySound("Time/16.wav",NULL,SND_ALIAS);
		break;
	case 17:
		PlaySound("Time/17.wav",NULL,SND_ALIAS);
		break;
	case 18:
		PlaySound("Time/18.wav",NULL,SND_ALIAS);
		break;
	case 19:
		PlaySound("Time/19.wav",NULL,SND_ALIAS);
		break;
	default:
		return;
		break;
	}
}

void CSpell::PlayTime(int nSoundId,int nLang)
{
	if(nLang==CHINESE){
		switch(nSoundId){
		case 0:
			PlaySound("Time/zcn.wav",NULL,SND_ALIAS);
			break;
		case 1:
			PlaySound("Time/1cn.wav",NULL,SND_ALIAS);
			break;
		case 2:
			PlaySound("Time/2cn.wav",NULL,SND_ALIAS);
			break;
		case 3:
			PlaySound("Time/3cn.wav",NULL,SND_ALIAS);
			break;
		case 4:
			PlaySound("Time/4cn.wav",NULL,SND_ALIAS);
			break;
		case 5:
			PlaySound("Time/5cn.wav",NULL,SND_ALIAS);
			break;
		case 6:
			PlaySound("Time/6cn.wav",NULL,SND_ALIAS);
			break;
		case 7:
			PlaySound("Time/7cn.wav",NULL,SND_ALIAS);
			break;
		case 8:
			PlaySound("Time/8cn.wav",NULL,SND_ALIAS);
			break;
		case 9:
			PlaySound("Time/9cn.wav",NULL,SND_ALIAS);
			break;
		case 10:
			PlaySound("Time/10cn.wav",NULL,SND_ALIAS);
			break;
		case 20:
			PlaySound("Time/20cn.wav",NULL,SND_ALIAS);
			break;
		case 30:
			PlaySound("Time/30cn.wav",NULL,SND_ALIAS);
			break;
		case 40:
			PlaySound("Time/40cn.wav",NULL,SND_ALIAS);
			break;
		case 50:
			PlaySound("Time/50cn.wav",NULL,SND_ALIAS);
			break;
		case 61:
			PlaySound("Time/dian.wav",NULL,SND_ALIAS);
			break;
		case 62:
			PlaySound("Time/fen.wav",NULL,SND_ALIAS);
			break;
		default:
			break;
		}
	}
	
	if(nLang==ENGLISH){
		switch(nSoundId){
		case 0:
			PlaySound("Time/zen.wav",NULL,SND_ALIAS);
			break;
		case 1:
			PlaySound("Time/1en.wav",NULL,SND_ALIAS);
			break;
		case 2:
			PlaySound("Time/2en.wav",NULL,SND_ALIAS);
			break;
		case 3:
			PlaySound("Time/3en.wav",NULL,SND_ALIAS);
			break;
		case 4:
			PlaySound("Time/4en.wav",NULL,SND_ALIAS);
			break;
		case 5:
			PlaySound("Time/5en.wav",NULL,SND_ALIAS);
			break;
		case 6:
			PlaySound("Time/6en.wav",NULL,SND_ALIAS);
			break;
		case 7:
			PlaySound("Time/7en.wav",NULL,SND_ALIAS);
			break;
		case 8:
			PlaySound("Time/8en.wav",NULL,SND_ALIAS);
			break;
		case 9:
			PlaySound("Time/9en.wav",NULL,SND_ALIAS);
			break;
		case 10:
			PlaySound("Time/10en.wav",NULL,SND_ALIAS);
			break;
		case 20:
			PlaySound("Time/20en.wav",NULL,SND_ALIAS);
			break;
		case 30:
			PlaySound("Time/30en.wav",NULL,SND_ALIAS);
			break;
		case 40:
			PlaySound("Time/40en.wav",NULL,SND_ALIAS);
			break;
		case 50:
			PlaySound("Time/50en.wav",NULL,SND_ALIAS);
			break;
		case 63:
			PlaySound("Time/ocloc.wav",NULL,SND_ALIAS);
			break;
		default:
			break;
		}
	}
	
}