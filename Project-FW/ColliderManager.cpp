#include "ColliderManager.h"
#include "Collider.h"
#include "ColliderBox.h"

CColliderManager::CColliderManager()
{
}
CColliderManager::~CColliderManager()
{
}

bool CColliderManager::CollisionCheck(CColliderBox A, CColliderBox B)
{
	bool bState=false ;

	if((A.rect.left + A.m_fX) < (B.rect.right + B.m_fX) &&
	   (A.rect.right + A.m_fX) > (B.rect.left + B.m_fX) &&
	   (A.rect.top + A.m_fY) > (B.rect.bottom + B.m_fY) &&
	   (A.rect.bottom + A.m_fY) < (B.rect.top + B.m_fY))
	{
		bState = true ;
	}
	
	return bState ;
}