#include "TitleScene.h"

#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"

#include "CameraManager.h"
#include "MusicManager.h"

#include "D3dDevice.h"

#include "SceneManager.h"
#include "GameScene.h"
#include "TutorialScene.h"
#include "DeveloperScene.h"

#include "Sprite.h"
#include "Button.h"
#include "ButtonManager.h"

//
#include "LogManager.h"

TitleScene::TitleScene() : m_pBackground(NULL),
						   m_pPlay(NULL), m_pHelp(NULL), m_pDeveloper(NULL), m_pQuit(NULL)
{
}
TitleScene::~TitleScene()
{
	if(m_pBackground!=NULL)
		delete m_pBackground ;

	g_ButtonManager->DeleteAllButtons() ;
}

Scene* TitleScene::scene()
{
	Scene *scene = new TitleScene ;

	return scene ;
}

void TitleScene::Init()
{
	float WinWidth = g_D3dDevice->GetWinWidth() ;
	float WinHeight = g_D3dDevice->GetWinHeight() ;

	g_CameraManager->AddCamera(new CCamera(), 0) ;

	m_pBackground = new CSprite ;
	m_pBackground->Init("Resource/Image/Title/Title.png") ;
	m_pBackground->SetPosition(WinWidth/2.0f, WinHeight/2.0f) ;

	m_pPlay = new CButton ;
	m_pPlay->Init(180.0f, 60.0f, "Resource/Image/Title/Play_Button.png") ;
	m_pPlay->SetPosition(120.0f, WinHeight - 420.0f) ;
	m_pPlay->SetIndex(0, 1, 1) ;
	g_ButtonManager->AddButton(m_pPlay) ;

	m_pHelp = new CButton ;
	m_pHelp->Init(180.0f, 60.0f, "Resource/Image/Title/Help_Button.png") ;
	m_pHelp->SetPosition(360.0f, WinHeight - 420.0f) ;
	m_pHelp->SetIndex(0, 1, 1) ;
	g_ButtonManager->AddButton(m_pHelp) ;

	m_pDeveloper = new CButton ;
	m_pDeveloper->Init(180.0f, 60.0f, "Resource/Image/Title/Developer_Button.png") ;
	m_pDeveloper->SetPosition(600.0f, WinHeight - 420.0f) ;
	m_pDeveloper->SetIndex(0, 1, 1) ;
	g_ButtonManager->AddButton(m_pDeveloper) ;
	
	m_pQuit = new CButton ;
	m_pQuit->Init(180.0f, 60.0f, "Resource/Image/Title/Quit_Button.png") ;
	m_pQuit->SetPosition(840.0f, WinHeight - 420.0f) ;
	m_pQuit->SetIndex(0, 1, 1) ;
	g_ButtonManager->AddButton(m_pQuit) ;

	m_pBGM = g_MusicManager->LoadMusic("Resource/Sound/Main.mp3", true) ;
	g_MusicManager->StopMusic(0) ;
	g_MusicManager->PlayMusic(m_pBGM, 0) ;
}

void TitleScene::Destroy()
{
}

void TitleScene::Update(float dt)
{
	g_Keyboard->Update() ;
	g_Mouse->Update() ;
	g_Joystick->Update() ;
	g_MusicManager->Loop() ;

	g_ButtonManager->Update() ;

	if(m_pPlay->BeClick())
	{
		g_MusicManager->StopMusic(0) ;
		g_SceneManager->ChangeScene(GameScene::scene()) ;
		return ;
	}
	else if(m_pHelp->BeClick())
	{
		g_SceneManager->ChangeScene(TutorialScene::scene()) ;
		return ;
	}
	else if(m_pDeveloper->BeClick())
	{
		g_SceneManager->ChangeScene(DeveloperScene::scene()) ;
		return ;
	}
	else if(m_pQuit->BeClick())
	{
		g_MusicManager->StopMusic(0) ;
		PostQuitMessage(0) ;
		return ;
	}
}

void TitleScene::Render()
{
	g_CameraManager->CameraRun() ;

	m_pBackground->Render() ;

	m_pPlay->Render() ;
	m_pHelp->Render() ;
	m_pDeveloper->Render() ;
	m_pQuit->Render() ;
}