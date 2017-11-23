#ifndef CSCENE_H
#define CSCENE_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>

#include "simple_format.h"

class CScene
{
private:
	Model* m_pModel;
	static CScene* m_pInstance;
protected:
public:
	CScene();
	~CScene();

	void Draw();
	void ReloadTextures();

	static CScene* GetInstance();
	static void ClearInstance();
};
#endif