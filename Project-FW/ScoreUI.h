#pragma once

class CSprite ;
class CNumberUI ;

class CScoreUI
{
private :
	float m_fX, m_fY ;
	unsigned int m_nScore, m_nMaxScore ;
	int m_nNum ;
	CSprite *m_pSprite ;
	CNumberUI *m_pNumber[3] ;

public :
	CScoreUI() ;
	~CScoreUI() ;

	void Init() ;

	void SetPosition(float fX, float fY) ;
	const bool AchieveAScore() const ;

	void Update() ;

	void Render() ;
private :
	void SetScore() ;
} ;