#pragma once

#include "Scene.h"
#include <fmod.hpp>

class CScoreUI ;
class CLifeUI ;

class GameScene : public Scene
{
private :
	CScoreUI *m_pScoreUI ;
	CLifeUI *m_pLifeUI ;
	FMOD::Sound *m_pBGM ;

public :
	static Scene* scene() ;

	GameScene() ;
	virtual ~GameScene() ;

	void Init() ;
	void Destroy() ;

	void Update(float dt) ;
	void Render() ;
} ;