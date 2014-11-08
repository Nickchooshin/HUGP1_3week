#include "Collider.h"

CCollider::CCollider() : m_fX(0.0f), m_fY(0.0f)
{
}
CCollider::~CCollider()
{
}

void CCollider::SetPosition(float fX, float fY)
{
	m_fX = fX ;
	m_fY = fY ;
}