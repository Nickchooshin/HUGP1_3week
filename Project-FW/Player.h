#pragma once

#include "Objects.h"
#include "Singleton.h"
#include <fmod.hpp>

class CPlayer : public CObjects, public Singleton<CPlayer>
{
private :
	float m_fAcc, m_fSpeed ;
	float m_fDamageCooldown ;
	float m_fAnimationTime ;
	int m_nNowFrame ;
	int MaxFrame ;

	int m_nDust, m_nLife ;

	FMOD::Sound *m_pEDust, *m_pEHeart ;

public :
	CPlayer() ;
	~CPlayer() ;

	void Init() ;

	void Update() ;

	const int GetDustNum() const ;
	const int GetLifeNum() const ;
	const float GetViewX() const ;

	void AddDust() ;
	void Damage() ;

	void Render() ;
private :
	void Animation() ;
} ;

#define g_Player CPlayer::GetInstance()