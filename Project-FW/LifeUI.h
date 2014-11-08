#pragma once

class CSprite ;

class CLifeUI
{
private :
	float m_fX, m_fY ;
	int m_nLife ;
	CSprite *m_pSprite ;

public :
	CLifeUI() ;
	~CLifeUI() ;

	void Init() ;

	void SetPosition(float fX, float fY) ;

	const bool Dead() const ;

	void Update() ;

	void Render() ;
} ;