#pragma once

#include "Scene.h"
#include <fmod.hpp>

class CSprite ;

class GameOverScene : public Scene
{
private :
	CSprite *m_pBackground ;
	FMOD::Sound *m_pBGM ;

public :
	static Scene* scene() ;

	GameOverScene() ;
	virtual ~GameOverScene() ;

	void Init() ;
	void Destroy() ;

	void Update(float dt) ;
	void Render() ;
} ;