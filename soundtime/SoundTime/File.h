
#ifndef _FILE_H
#define _FILE_H

typedef int BOOL;

typedef struct tagBELL_INFO
{
		short Hour;
		short Minute;
		char  Path[255];
		char  Message[255];
} BELL_INFO;

typedef struct tagINIT_FILE
{
	short     Language;
	BOOL      Is_bell;
	BOOL      Is_transparent;
	BELL_INFO Bell_info;
} ST_PROFILE;

class CProfile{
	
public:
	ST_PROFILE GetProfile();
	BOOL       WriteProfile(ST_PROFILE sp);
	void       GenerateProfile();

};

#endif