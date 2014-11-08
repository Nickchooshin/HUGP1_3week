#pragma once

#include "ColliderBox.h"

class CSprite ;

class CObjects
{
protected :
	CSprite *m_pSprite ;
	CColliderBox m_ColBox ;
	float m_fX, m_fY ;

public :
	CObjects() ;
	virtual ~CObjects() ;

	virtual void Init() = 0 ;

	virtual void Update() ;

	const float GetPositionX() const ;
	const float GetPositionY() const ;
	const CColliderBox GetColliderBox() ;

	void SetPosition(float fX, float fY) ;

	virtual void Render() const ;
protected :
	void SetColBox() ;
} ;