#pragma once

#include "Collider.h"

typedef struct _Rect
{
	float left ;
	float top ;
	float right ;
	float bottom ;
} Rect ;

class CColliderBox : public CCollider
{
private :
	Rect rect ;

public :
	CColliderBox() ;
	~CColliderBox() ;

	void SetRect(float left, float top, float right, float bottom) ;

	friend CColliderManager ;
} ;