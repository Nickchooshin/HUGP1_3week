#pragma once

#include "MapObjects.h"

class CMapObjectsTopBottom : public CMapObjects
{
public :
	CMapObjectsTopBottom() ;
	~CMapObjectsTopBottom() ;

	void Init() ;
	void Init(int nType, char tb) ;

	const float GetObjectWidth() const ;
	const float GetObjectHeight() const ;

	void Effect() ;
} ;