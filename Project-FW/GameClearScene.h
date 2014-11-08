#pragma once

#include "Scene.h"
#include <fmod.hpp>

class CSprite ;

class GameClearScene : public Scene
{
private :
	CSprite *m_pBackground ;
	FMOD::Sound *m_pBGM ;

public :
	static Scene* scene() ;

	GameClearScene() ;
	virtual ~GameClearScene() ;

	void Init() ;
	void Destroy() ;

	void Update(float dt) ;
	void Render() ;
} ;