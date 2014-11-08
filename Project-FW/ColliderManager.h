#pragma once

#include "Singleton.h"

class CCollider ;
class CColliderBox ;

class CColliderManager : public Singleton<CColliderManager>
{
public :
	CColliderManager() ;
	~CColliderManager() ;

	bool CollisionCheck(CColliderBox A, CColliderBox B) ;
} ;

#define g_ColliderManager CColliderManager::GetInstance()