#pragma once

#include "Scene.h"

#include <fmod.hpp>

class CSprite ;
class CButton ;

class TitleScene : public Scene
{
private :
	CSprite *m_pBackground ;
	CButton *m_pPlay, *m_pHelp, *m_pDeveloper, *m_pQuit ;

	FMOD::Sound *m_pBGM ;

public :
	static Scene* scene() ;

	TitleScene() ;
	virtual ~TitleScene() ;

	void Init() ;
	void Destroy() ;

	void Update(float dt) ;
	void Render() ;
} ;