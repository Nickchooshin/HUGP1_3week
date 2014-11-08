#include "TutorialScene.h"

#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"

#include "CameraManager.h"
#include "MusicManager.h"

#include "D3dDevice.h"

#include "SceneManager.h"
#include "TitleScene.h"

#include "Sprite.h"

TutorialScene::TutorialScene() : m_nState(0)
{
	for(int i=0; i<2; i++)
		m_pTutorial[i] = NULL ;
}
TutorialScene::~TutorialScene()
{
	for(int i=0; i<2; i++)
	{
		if(m_pTutorial[i]!=NULL)
			delete m_pTutorial[i] ;
	}
}

Scene* TutorialScene::scene()
{
	Scene *scene = new TutorialScene ;

	return scene ;
}

void TutorialScene::Init()
{
	float WinWidth = g_D3dDevice->GetWinWidth() ;
	float WinHeight = g_D3dDevice->GetWinHeight() ;

	g_CameraManager->AddCamera(new CCamera(), 0) ;

	for(int i=0; i<2; i++)
	{
		char filepath[100] ;
		wsprintf(filepath, "Resource/Image/Tutorial/Help%d.png", i+1) ;

		m_pTutorial[i] = new CSprite ;
		m_pTutorial[i]->Init(filepath) ;
		m_pTutorial[i]->SetPosition(WinWidth/2.0f, WinHeight/2.0f) ;
	}
}

void TutorialScene::Destroy()
{
}

void TutorialScene::Update(float dt)
{
	g_Keyboard->Update() ;
	g_Mouse->Update() ;
	g_Joystick->Update() ;
	g_MusicManager->Loop() ;

	if(g_Mouse->IsMousePress(g_Mouse->LBUTTON_DOWN))
		++m_nState ;

	if(m_nState==2)
	{
		g_SceneManager->ChangeScene(TitleScene::scene()) ;
		return ;
	}
}

void TutorialScene::Render()
{
	g_CameraManager->CameraRun() ;

	m_pTutorial[m_nState]->Render() ;
}