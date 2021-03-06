#include "Button.h"
#include "Sprite.h"

#include "Mouse.h"
#include "TextureManager.h"

CButton::CButton() : m_fX(0.0f), m_fY(0.0f),
					 m_fWidth(0.0f), m_fHeight(0.0f),
					 m_nState(0), m_nPrevState(-1),
					 m_bActivate(true), m_bClick(false),
					 m_bVisible(true),
					 m_pSprite(NULL)
{
	for(int i=0; i<3; i++)
		m_nIndex[i] = 0 ;
}
CButton::~CButton()
{
	if(m_pSprite!=NULL)
		delete m_pSprite ;
}

void CButton::Init(char *texfile)
{
	m_pSprite = new CSprite ;
	m_pSprite->Init(texfile) ;

	D3DXIMAGE_INFO TexInfo = g_TextureManager->GetTexInfo(texfile) ;
	m_fWidth = TexInfo.Width ;
	m_fHeight = TexInfo.Height ;
}

void CButton::Init(float Width, float Height, char *texfile)
{
	m_pSprite = new CSprite ;
	m_pSprite->Init(Width, Height, texfile) ;

	m_fWidth = Width ;
	m_fHeight = Height ;
}

void CButton::SetPosition(float fX, float fY)
{
	m_fX = fX ;
	m_fY = fY ;
}

void CButton::SetIndex(int normalIndex, int clickIndex, int disableIndex)
{
	m_nIndex[0] = normalIndex ;
	m_nIndex[1] = clickIndex ;
	m_nIndex[2] = disableIndex ;
}

void CButton::SetActivate(bool bActivate)
{
	m_bActivate = bActivate ;
}

void CButton::SetVisible(bool bVisible)
{
	m_bVisible = bVisible ;
}

void CButton::ClickState(int x, int y, bool bClick, bool bPress)
{
	m_bClick = false ;
	if(!m_bActivate || !m_bVisible)
		return ;

	if(bPress && CollisionCheck(x, y))
	{
		m_bClick = true ;
	}
	else if(bClick && CollisionCheck(x, y))
	{
		m_nState = m_nIndex[1] ;
	}
	else
	{
		m_nState = m_nIndex[0] ;
	}
}

const bool CButton::BeClick() const
{
	return m_bClick ;
}

const bool CButton::BeActivate() const
{
	return m_bActivate ;
}

const bool CButton::BeVisible() const
{
	return m_bVisible ;
}

void CButton::Render()
{
	if(!m_bVisible)
		return ;

	if(!m_bActivate)
		m_nState = m_nIndex[2] ;

	if(m_nState!=m_nPrevState)
	{
		m_pSprite->SetTextureUV((m_nState * m_fWidth), 0.0f, ((m_nState+1) * m_fWidth), m_fHeight) ;
		m_nPrevState = m_nState ;
	}

	m_pSprite->SetPosition(m_fX, m_fY) ;
	m_pSprite->Render() ;
}

bool CButton::CollisionCheck(int x, int y)
{
	float widthHalf = m_fWidth/2.0f ;
	float heightHalf = m_fHeight/2.0f ;

	if( (x>=(m_fX-widthHalf) && x<=(m_fX+widthHalf)) &&
		(y>=(m_fY-heightHalf) && y<=(m_fY+heightHalf)) )
	{
		return true ;
	}

	return false ;
}