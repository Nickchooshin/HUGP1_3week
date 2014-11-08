#pragma once

#include "Scene.h"

class CSprite ;

class TutorialScene : public Scene
{
private :
	CSprite *m_pTutorial[2] ;
	int m_nState ;

public :
	static Scene* scene() ;

	TutorialScene() ;
	virtual ~TutorialScene() ;

	void Init() ;
	void Destroy() ;

	void Update(float dt) ;
	void Render() ;
} ;