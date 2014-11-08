#pragma once

#include "Singleton.h"
#include <vector>

class CMapObjects ;
class CSprite ;

class CMapManager : public Singleton<CMapManager>
{
private :
	std::vector<CMapObjects*> m_MapObjectsList ;
	CSprite *m_pBackground[2] ;
	float m_fTopX, m_fBottomX ;
	float m_fItemX ;

public :
	CMapManager() ;
	~CMapManager() ;

	void Init() ;

	void Update() ;

	void Render() ;
private :
	void MoveBackground() ;

	void CreateMapObject() ;
	void CreateMapObjectTop() ;
	void CreateMapObjectBottom() ;

	void CreateMapObjectDust() ;
	void CreateMapObjectVirus() ;

	void DeleteMapObject() ;

	void CollisionCheck() ;
} ;

#define g_MapManager CMapManager::GetInstance()