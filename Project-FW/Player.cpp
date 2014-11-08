#include "Player.h"
#include "Sprite.h"
#include "D3dDevice.h"

#include "Mouse.h"
#include "MusicManager.h"

CPlayer::CPlayer() : m_fAcc(0.0f), m_fSpeed(0.0f),
					 m_fDamageCooldown(0.0f),
					 m_fAnimationTime(0.0f),
					 m_nNowFrame(0),
					 MaxFrame(0),
					 m_nDust(0), m_nLife(0),
					 m_pEDust(NULL), m_pEHeart(NULL)
{
	m_pSprite = new CSprite ;
	m_pSprite->Init(60.0f, 60.0f, "Resource/Image/Player/P_Normal.png") ;
	m_pSprite->SetTextureUV(0.0f, 0.0f, 60.0f, 60.0f) ;

	//m_ColBox.SetRect(-30.0f, 30.0f, 30.0f, -30.0f) ;
	m_ColBox.SetRect(-24.0f, 25.0f, 22.0f, -16.0f) ;

	MaxFrame = 8 ;

	m_pEDust = g_MusicManager->LoadMusic("Resource/Sound/Dust.mp3", false, false) ;
	m_pEHeart = g_MusicManager->LoadMusic("Resource/Sound/Heart.mp3", false, false) ;
}
CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
	m_fX = 100.0f ;
	m_fY = g_D3dDevice->GetWinHeight() / 2.0f ;

	m_nDust = 0 ;
	m_nLife = 5 ;

	m_fAcc = 0.0f ;
	m_fSpeed = 0.05f ;
	m_fDamageCooldown = 0.0f ;
	m_fAnimationTime = 0.0f ;
	m_nNowFrame = 0 ;
}

void CPlayer::Update()
{
	if(m_fDamageCooldown>0.0f)
		m_fDamageCooldown -= g_D3dDevice->GetTime() ;

	m_fX += g_D3dDevice->GetMoveTime() * 3.0f ;

	if(g_Mouse->IsMousePress(g_Mouse->LBUTTON_DOWN))
		m_fAcc = g_D3dDevice->GetMoveTime() * 1.5f ;
	else
		m_fAcc -= g_D3dDevice->GetMoveTime() * m_fSpeed ;

	m_fY += m_fAcc ;

	Animation() ;

	if(m_fY<0.0f)
		m_fY = 0.0f ;
	else if(m_fY>480.0f)
		m_fY = 480.0f ;
}

const int CPlayer::GetDustNum() const
{
	return m_nDust ;
}

const int CPlayer::GetLifeNum() const
{
	return m_nLife ;
}

const float CPlayer::GetViewX() const
{
	float WinWidth = g_D3dDevice->GetWinWidth() ;

	return g_Player->GetPositionX() + (WinWidth / 2.0f) - 100.0f ;
}

void CPlayer::AddDust()
{
	++m_nDust ;
	g_MusicManager->PlayMusic(m_pEDust, 1) ;
}

void CPlayer::Damage()
{
	if(m_fDamageCooldown<=0.0f)
	{
		m_fDamageCooldown = 2.0f ;
		--m_nLife ;
		g_MusicManager->PlayMusic(m_pEHeart, 1) ;
	}
}

void CPlayer::Render()
{
	if(m_fDamageCooldown>0.0f)
	{
		int temp = (int)(m_fDamageCooldown * 10.0f) % 10 ;

		if(temp%2==0)
			return ;
	}

	m_pSprite->SetPosition(m_fX, m_fY) ;
	m_pSprite->Render() ;
}

void CPlayer::Animation()
{
	// Animation
	m_fAnimationTime += g_D3dDevice->GetTime() ;

	if(m_fAnimationTime>=0.15f)
	{
		int Frame = (int)(m_fAnimationTime / 0.15f) ;
		m_fAnimationTime -= Frame * 0.15f ;
		Frame %= MaxFrame ;
		m_nNowFrame += Frame ;
		m_nNowFrame %= MaxFrame ;

		float left, top, right, bottom ;
		left = (float)(m_nNowFrame * 60.0f) ;
		top = 0.0f ;
		right = left + 60.0f ;
		bottom = 60.0f ;

		m_pSprite->SetTextureUV(left, top, right, bottom) ;
	}
}