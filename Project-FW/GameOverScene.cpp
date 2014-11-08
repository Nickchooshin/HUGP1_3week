#include "GameOverScene.h"

#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"

#include "CameraManager.h"
#include "MusicManager.h"

#include "D3dDevice.h"

#include "SceneManager.h"
#include "TitleScene.h"

#include "Sprite.h"

GameOverScene::GameOverScene() : m_pBackground(NULL),
								 m_pBGM(NULL)
{
}
GameOverScene::~GameOverScene()
{
	if(m_pBackground!=NULL)
		delete m_pBackground ;
}

Scene* GameOverScene::scene()
{
	Scene *scene = new GameOverScene ;

	return scene ;
}

void GameOverScene::Init()
{
	float WinWidth = g_D3dDevice->GetWinWidth() ;
	float WinHeight = g_D3dDevice->GetWinHeight() ;

	g_CameraManager->AddCamera(new CCamera(), 0) ;

	m_pBackground = new CSprite ;
	m_pBackground->Init("Resource/Image/GameOver/Game_Over.png") ;
	m_pBackground->SetPosition(WinWidth/2.0f, WinHeight/2.0f) ;

	m_pBGM = g_MusicManager->LoadMusic("Resource/Sound/Over.mp3", true) ;
	g_MusicManager->PlayMusic(m_pBGM, 0) ;
}

void GameOverScene::Destroy()
{
	g_MusicManager->StopMusic(0) ;
}

void GameOverScene::Update(float dt)
{
	g_Keyboard->Update() ;
	g_Mouse->Update() ;
	g_Joystick->Update() ;
	g_MusicManager->Loop() ;

	if(g_Mouse->IsMousePress(g_Mouse->LBUTTON_DOWN))
	{
		g_SceneManager->ChangeScene(TitleScene::scene()) ;
		return ;
	}
}

void GameOverScene::Render()
{
	g_CameraManager->CameraRun() ;

	m_pBackground->Render() ;
}