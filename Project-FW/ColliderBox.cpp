#include "ColliderBox.h"

CColliderBox::CColliderBox()
{
}
CColliderBox::~CColliderBox()
{
}

void CColliderBox::SetRect(float left, float top, float right, float bottom)
{
	rect.left = left ;
	rect.top = top ;
	rect.right = right ;
	rect.bottom = bottom ;
}