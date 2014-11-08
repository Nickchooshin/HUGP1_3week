#pragma once

class CColliderManager ;

class CCollider
{
private :
	float m_fX, m_fY ;

public :
	CCollider() ;
	virtual ~CCollider() ;

	void SetPosition(float fX, float fY) ;

	friend CColliderManager ;
} ;