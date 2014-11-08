#include "LogManager.h"
#include "WinSystem.h"

CLogManager::CLogManager() : log(NULL)
{
}
CLogManager::~CLogManager()
{
	if(log!=NULL)
	{
		fprintf(log, "- log end\n\n") ;
		fclose(log) ;
	}
}

void CLogManager::Log(char *str)
{
	log = fopen("log.txt", "a") ;
	if(log==NULL)
		return ;

	fprintf(log, str) ;

	fclose(log) ;

	log = NULL ;
}