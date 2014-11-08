#pragma once

#include "Singleton.h"
#include <stdio.h>

class CLogManager : public Singleton<CLogManager>
{
private :
	FILE *log ;

public :
	CLogManager() ;
	~CLogManager() ;

	void Log(char *str) ;
} ;

#define g_LogManager CLogManager::GetInstance()