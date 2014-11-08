#include "MapObjectsTopBottom.h"
#include "Sprite.h"

#include "Player.h"

CMapObjectsTopBottom::CMapObjectsTopBottom()
{
}
CMapObjectsTopBottom::~CMapObjectsTopBottom()
{
}

void CMapObjectsTopBottom::Init()
{
	SetColBox() ;
}

void CMapObjectsTopBottom::Init(int nType, char tb)
{
	char filename[1024] ;
	char direction[10] ;

	if(tb=='t')
		strcpy(direction, "Top") ;
	else if(tb=='b')
		strcpy(direction, "Bottom") ;

	wsprintf(filename, "Resource/Image/Map/%s/%s%d.png", direction, direction, nType) ;

	m_pSprite = new CSprite ;
	m_pSprite->Init(filename) ;

	Init() ;
}

const float CMapObjectsTopBottom::GetObjectWidth() const
{
	return m_pSprite->GetTexInfo().Width ;
}

const float CMapObjectsTopBottom::GetObjectHeight() const
{
	return m_pSprite->GetTexInfo().Height ;
}

void CMapObjectsTopBottom::Effect()
{
	g_Player->Damage() ;
}