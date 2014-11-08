#pragma once

#include "Scene.h"

class CSprite ;

class DeveloperScene : public Scene
{
private :
	CSprite *m_pBackground ;

public :
	static Scene* scene() ;

	DeveloperScene() ;
	virtual ~DeveloperScene() ;

	void Init() ;
	void Destroy() ;

	void Update(float dt) ;
	void Render() ;
} ;