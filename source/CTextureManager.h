#ifndef CTEXTUREMANAGER_H
#define CTEXTUREMANAGER_H

#include <windows.h>
#include <stdio.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include <string>
using namespace std;

class CTextureManager
{
protected:
	CTextureManager();
	AUX_RGBImageRec* LoadBMP(string filename);

	static CTextureManager* m_pInstance;

public:
	~CTextureManager();
	static CTextureManager* GetInstance();

	int AddTexture(string filename);
	void UseTexture(int index);
	void ClearTexture(GLuint index);
};
#endif