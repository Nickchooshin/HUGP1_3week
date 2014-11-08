#include "MapObjects.h"
#include "Sprite.h"

CMapObjects::CMapObjects() : m_nMapObjectType(0)
{
}
CMapObjects::~CMapObjects()
{
}

const int CMapObjects::GetMapObjectType() const
{
	return m_nMapObjectType ;
}

void CMapObjects::Effect()
{
}