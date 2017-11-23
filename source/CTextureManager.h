#ifndef CTEXTUREMANAGER_H
#define CTEXTUREMANAGER_H

#include <windows.h>
#include <stdio.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <string>
using namespace std;

class CTextureManager
{
protected:
    CTextureManager();

	static CTextureManager* m_pInstance;

public:
	~CTextureManager();
	static CTextureManager* GetInstance();

	int AddTexture(string filename);
	void UseTexture(int index);
	void ClearTexture(GLuint index);
};
#endif
