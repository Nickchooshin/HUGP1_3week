#include "GameScene.h"

#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"

#include "CameraManager.h"
#include "MusicManager.h"

#include "D3dDevice.h"
#include "Player.h"
#include "MapManager.h"
#include "ScoreUI.h"
#include "LifeUI.h"

#include "SceneManager.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

#include "LogManager.h"

GameScene::GameScene() : m_pScoreUI(NULL),
						 m_pLifeUI(NULL),
						 m_pBGM(NULL)
{
}
GameScene::~GameScene()
{
	if(m_pScoreUI!=NULL)
		delete m_pScoreUI ;
	if(m_pLifeUI!=NULL)
		delete m_pLifeUI ;
}

Scene* GameScene::scene()
{
	Scene *scene = new GameScene ;

	return scene ;
}

void GameScene::Init()
{
	float WinWidth = g_D3dDevice->GetWinWidth() ;
	float WinHeight = g_D3dDevice->GetWinHeight() ;

	g_CameraManager->AddCamera(new CCamera(), 0) ;
	
	g_Player->Init() ;
	g_MapManager->Init() ;
	
	m_pScoreUI = new CScoreUI ;
	m_pScoreUI->Init() ;

	m_pLifeUI = new CLifeUI ;
	m_pLifeUI->Init() ;
	
	m_pBGM = g_MusicManager->LoadMusic("Resource/Sound/Play.mp3", true) ;
	g_MusicManager->PlayMusic(m_pBGM, 0) ;
}

void GameScene::Destroy()
{
	g_MusicManager->StopMusic(0) ;
}

void GameScene::Update(float dt)
{
	g_Keyboard->Update() ;
	g_Mouse->Update() ;
	g_Joystick->Update() ;
	g_MusicManager->Loop() ;
	
	g_Player->Update() ;
	g_MapManager->Update() ;
	
	m_pScoreUI->Update() ;
	m_pLifeUI->Update() ;
	
	if(m_pScoreUI->AchieveAScore())
	{
		g_SceneManager->ChangeScene(GameClearScene::scene()) ;
		return ;
	}
	else if(m_pLifeUI->Dead())
	{
		g_SceneManager->ChangeScene(GameOverScene::scene()) ;
		return ;
	}

	//g_D3dDevice->GetD3dDevice()->ShowCursor(true) ;
	//g_D3dDevice->GetD3dDevice()->SetCursorPosition(0, 0, true) ;
}

void GameScene::Render()
{
	float WinWidth = g_D3dDevice->GetWinWidth() ;
	float WinHeight = g_D3dDevice->GetWinHeight() ;
	
	g_CameraManager->CameraRun() ;
	g_CameraManager->SetPosition(g_Player->GetPositionX() + (WinWidth / 2.0f) - 100.0f, WinHeight / 2.0f) ;
	
	g_MapManager->Render() ;
	
	g_Player->Render() ;
	
	float CameraX = g_CameraManager->GetPosition().x ;
	float CameraY = g_CameraManager->GetPosition().y ;
	
	m_pScoreUI->SetPosition(CameraX + 460.0f, CameraY + 215.0f) ;
	m_pScoreUI->Render() ;
	
	m_pLifeUI->SetPosition(CameraX + 392.0f, CameraY - 215.0f) ;
	m_pLifeUI->Render() ;
}