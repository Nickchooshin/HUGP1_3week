#include "LifeUI.h"
#include "Sprite.h"

#include "Player.h"

CLifeUI::CLifeUI() : m_fX(0.0f), m_fY(0.0f),
					 m_pSprite(NULL)
{
}
CLifeUI::~CLifeUI()
{
	if(m_pSprite!=NULL)
		delete m_pSprite ;
}

void CLifeUI::Init()
{
	m_pSprite = new CSprite ;
	m_pSprite->Init("Resource/Image/UI/Heart.png") ;

	m_nLife = g_Player->GetLifeNum() ;
}

void CLifeUI::SetPosition(float fX, float fY)
{
	m_fX = fX ;
	m_fY = fY ;
}

const bool CLifeUI::Dead() const
{
	return (m_nLife <= 0) ;
}

void CLifeUI::Update()
{
	m_nLife = g_Player->GetLifeNum() ;
}

void CLifeUI::Render()
{
	for(int i=0; i<m_nLife; i++)
	{
		m_pSprite->SetPosition(m_fX + (16.0f * i), m_fY) ;
		m_pSprite->Render() ;
	}
}