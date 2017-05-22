/* 
** Sound Time - File.cpp
** Copyright: David Zhang
** E-Mail   : crispgm@gmail.com
** Edited   : 2006-07-27
*/

#include "stdafx.h"

#include "File.h"
#include <stdio.h>

#define CHINESE 0x522
#define ENGLISH 0x806


BOOL CProfile::WriteProfile(ST_PROFILE sp)
{
    FILE* op=fopen("soundtime.sti","wb");
	if(!op)
		return 0;
	fwrite(&sp,sizeof(ST_PROFILE),1,op);
	fclose(op);
	return 1;
}

ST_PROFILE CProfile::GetProfile()
{
	ST_PROFILE sp;
	FILE* op=fopen("soundtime.sti","rb");
	if(!op){
		GenerateProfile();
		return GetProfile();
	}
	else{
		fread(&sp,sizeof(ST_PROFILE),1,op);
		fclose(op);
		return sp;
	}
}

void CProfile::GenerateProfile()
{
	CProfile pro;
	ST_PROFILE sp;
	
	sp.Is_bell=1;
	sp.Is_transparent=1;

	sp.Language=ENGLISH;

	sp.Bell_info.Hour=12;
	sp.Bell_info.Minute=0;
	strcpy(sp.Bell_info.Message,"Hello, world!");
	strcpy(sp.Bell_info.Path,"Bell\\1.wav");

	pro.WriteProfile(sp);
	return;
}