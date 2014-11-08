#pragma once

#include "Objects.h"

class CMapObjects : public CObjects
{
protected :
	int m_nMapObjectType ;

public :
	CMapObjects() ;
	virtual ~CMapObjects() ;

	const int GetMapObjectType() const ;

	virtual void Effect() ;
} ;