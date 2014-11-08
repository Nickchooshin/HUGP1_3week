#include "MapManager.h"
#include "D3dDevice.h"
#include "Sprite.h"

#include "LoadManager.h"
#include "ColliderManager.h"

#include "Player.h"
#include "CameraManager.h"

#include "MapObjects.h"
#include "MapObjectsTopBottom.h"
#include "Dust.h"
#include "Virus.h"

CMapManager::CMapManager() : m_fTopX(0.0f), m_fBottomX(0.0f),
							 m_fItemX(0.0f)
{
	char str[100] ;
	float WinWidth = g_D3dDevice->GetWinWidth() ;
	float WinHeight = g_D3dDevice->GetWinHeight() ;

	for(int i=0; i<2; i++)
	{
		m_pBackground[i] = NULL ;
		m_pBackground[i] = new CSprite ;
		wsprintf(str, "Resource/Image/Map/Background%d.png", i+1) ;
		m_pBackground[i]->Init(str) ;
		m_pBackground[i]->SetPosition((WinWidth / 2.0f) + (WinWidth * i), (WinHeight / 2.0f)) ;
	}

	m_fItemX = WinWidth ;
}
CMapManager::~CMapManager()
{
	int i ;
	const int num = m_MapObjectsList.size() ;

	for(i=0; i<num; i++)
		delete m_MapObjectsList[i] ;

	m_MapObjectsList.clear() ;

	for(i=0; i<2; i++)
	{
		if(m_pBackground[i]!=NULL)
			delete m_pBackground[i] ;
	}
}

void CMapManager::Init()
{
	int i ;
	const int num = m_MapObjectsList.size() ;

	float WinWidth = g_D3dDevice->GetWinWidth() ;
	float WinHeight = g_D3dDevice->GetWinHeight() ;

	for(i=0; i<num; i++)
		delete m_MapObjectsList[i] ;

	m_MapObjectsList.clear() ;

	for(i=0; i<2; i++)
		m_pBackground[i]->SetPosition((WinWidth / 2.0f) + (WinWidth * i), (WinHeight / 2.0f)) ;

	m_fTopX = m_fBottomX = 0.0f ;
	m_fItemX = WinWidth ;
}

void CMapManager::Update()
{
	CreateMapObject() ;

	DeleteMapObject() ;

	MoveBackground() ;

	CollisionCheck() ;
}

void CMapManager::Render()
{
	int i ;
	const int num = m_MapObjectsList.size() ;

	for(i=0; i<2; i++)
		m_pBackground[i]->Render() ;

	for(i=0; i<num; i++)
		m_MapObjectsList[i]->Render() ;
}

void CMapManager::MoveBackground()
{
	float WinWidth = g_D3dDevice->GetWinWidth() ;
	//float playerX = g_Player->GetPositionX() - WinWidth ;
	float playerX = g_CameraManager->GetPosition().x - WinWidth ;
	float backgroundX ;

	for(int i=0; i<2; i++)
	{
		backgroundX = m_pBackground[i]->GetPosition().x ;

		if(backgroundX <= playerX)
			m_pBackground[i]->SetPosition(backgroundX + (WinWidth * 2.0f), m_pBackground[i]->GetPosition().y) ;
	}
}

void CMapManager::CreateMapObject()
{
	float playerX = g_Player->GetPositionX() + g_D3dDevice->GetWinWidth() ;
	bool bLoop = true ;

	while(bLoop)
	{
		bLoop = false ;

		if(playerX >= m_fItemX)
		{
			CreateMapObjectDust() ;
			CreateMapObjectVirus() ;
			m_fItemX += 210.0f ;
			bLoop = true ;
		}

		if(playerX >= m_fTopX)
		{
			CreateMapObjectTop() ;
			bLoop = true ;
		}

		if(playerX >= m_fBottomX)
		{
			CreateMapObjectBottom() ;
			bLoop = true ;
		}
	}
}

void CMapManager::CreateMapObjectTop()
{
	int type = rand()%20+1 ;
	float x, y ;

	CMapObjectsTopBottom *MapObjects = new CMapObjectsTopBottom ;
	MapObjects->Init(type, 't') ;

	x = m_fTopX + MapObjects->GetObjectWidth() / 2.0f ;
	y = g_D3dDevice->GetWinHeight() - MapObjects->GetObjectHeight() / 2.0f ;
	MapObjects->SetPosition(x, y) ;

	m_fTopX += MapObjects->GetObjectWidth() ;

	m_MapObjectsList.push_back(MapObjects) ;
}

void CMapManager::CreateMapObjectBottom()
{
	int type = rand()%20+1 ;
	float x, y ;

	CMapObjectsTopBottom *MapObject = new CMapObjectsTopBottom ;
	MapObject->Init(type, 'b') ;

	x = m_fBottomX + MapObject->GetObjectWidth() / 2.0f ;
	y = MapObject->GetObjectHeight() / 2.0f ;
	MapObject->SetPosition(x, y) ;

	m_fBottomX += MapObject->GetObjectWidth() ;
	
	m_MapObjectsList.push_back(MapObject) ;
}

void CMapManager::CreateMapObjectDust()
{
	int pattern = rand()%12+1 ;
	char filepath[100] ;
	char item[100] ;

	wsprintf(filepath, "Resource/Data/Dust/Dust_%d.dat", pattern) ;

	g_LoadManager->OpenDat(filepath) ;

	while(g_LoadManager->GetItem(item))
	{
		int len = strlen(item) ;

		if(len==13 && strcmp(item, "DUST_POSITION")==0)
		{
			char pos[100] ;
			float x, y ;

			g_LoadManager->GetString(pos) ;
			x = (float)strtod(pos, NULL) ;
			g_LoadManager->GetString(pos) ;
			y = (float)strtod(pos, NULL) ;

			CMapObjects *MapObject = new CDust ;
			MapObject->Init() ;
			MapObject->SetPosition(m_fItemX + x, g_D3dDevice->GetWinHeight() - y) ;
			m_MapObjectsList.push_back(MapObject) ;
		}
	}

	g_LoadManager->CloseDat() ;
}

void CMapManager::CreateMapObjectVirus()
{
	int pattern = rand()%12+1 ;
	char filepath[100] ;
	char item[100] ;

	wsprintf(filepath, "Resource/Data/Virus/Virus_%d.dat", pattern) ;

	g_LoadManager->OpenDat(filepath) ;

	while(g_LoadManager->GetItem(item))
	{
		int len = strlen(item) ;

		if(len==14 && strcmp(item, "VIRUS_POSITION")==0)
		{
			char pos[100] ;
			float x, y ;

			g_LoadManager->GetString(pos) ;
			x = (float)strtod(pos, NULL) ;
			g_LoadManager->GetString(pos) ;
			y = (float)strtod(pos, NULL) ;

			CMapObjects *MapObject = new CVirus ;
			MapObject->Init() ;
			MapObject->SetPosition(m_fItemX + x, g_D3dDevice->GetWinHeight() - y) ;
			m_MapObjectsList.push_back(MapObject) ;
		}
	}

	g_LoadManager->CloseDat() ;
}

void CMapManager::DeleteMapObject()
{
	int num = m_MapObjectsList.size() ;
	float PlayerX = g_Player->GetPositionX() ;
	float WinWidth = g_D3dDevice->GetWinWidth() ;
	float MinX = PlayerX - WinWidth ;

	for(int i=0; i<num; i++)
	{
		if(m_MapObjectsList[i]->GetPositionX() < MinX)
		{
			delete m_MapObjectsList[i] ;
			m_MapObjectsList.erase(m_MapObjectsList.begin() + i) ;
			--i ;
			--num ;
		}
		else
			break ;
	}
}

void CMapManager::CollisionCheck()
{
	int num = m_MapObjectsList.size() ;

	for(int i=0; i<num; i++)
	{
		bool bCheck = g_ColliderManager->CollisionCheck(g_Player->GetColliderBox(), m_MapObjectsList[i]->GetColliderBox()) ;

		if(bCheck)
		{
			m_MapObjectsList[i]->Effect() ;

			if(m_MapObjectsList[i]->GetMapObjectType()==1)
			{
				delete m_MapObjectsList[i] ;
				m_MapObjectsList.erase(m_MapObjectsList.begin() + i) ;
				--num ;
				--i ;
			}
		}
	}
}