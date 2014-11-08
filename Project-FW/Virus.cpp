#include "Virus.h"
#include "Sprite.h"

#include "Player.h"

CVirus::CVirus()
{
	m_nMapObjectType = 1 ;
}
CVirus::~CVirus()
{
}

void CVirus::Init()
{
	m_pSprite = new CSprite ;
	m_pSprite->Init("Resource/Image/Objects/Virus.png") ;

	SetColBox() ;
}

void CVirus::Effect()
{
	g_Player->Damage() ;
}