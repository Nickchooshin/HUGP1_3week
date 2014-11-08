#include "Dust.h"
#include "Sprite.h"

#include "Player.h"

CDust::CDust()
{
	m_nMapObjectType = 1 ;
}
CDust::~CDust()
{
}

void CDust::Init()
{
	m_pSprite = new CSprite ;
	m_pSprite->Init("Resource/Image/Objects/Dust.png") ;

	SetColBox() ;
}

void CDust::Effect()
{
	g_Player->AddDust() ;
}