#include "DeveloperScene.h"

#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"

#include "CameraManager.h"
#include "MusicManager.h"

#include "D3dDevice.h"

#include "SceneManager.h"
#include "TitleScene.h"

#include "Sprite.h"

DeveloperScene::DeveloperScene() : m_pBackground(NULL)
{
}
DeveloperScene::~DeveloperScene()
{
	if(m_pBackground!=NULL)
		delete m_pBackground ;
}

Scene* DeveloperScene::scene()
{
	Scene *scene = new DeveloperScene ;

	return scene ;
}

void DeveloperScene::Init()
{
	float WinWidth = g_D3dDevice->GetWinWidth() ;
	float WinHeight = g_D3dDevice->GetWinHeight() ;

	g_CameraManager->AddCamera(new CCamera(), 0) ;

	m_pBackground = new CSprite ;
	m_pBackground->Init("Resource/Image/Developer/Developer.png") ;
	m_pBackground->SetPosition(WinWidth/2.0f, WinHeight/2.0f) ;
}

void DeveloperScene::Destroy()
{
}

void DeveloperScene::Update(float dt)
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

void DeveloperScene::Render()
{
	g_CameraManager->CameraRun() ;

	m_pBackground->Render() ;
}