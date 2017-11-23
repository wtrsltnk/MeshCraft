#ifndef CVIEW3D_H
#define CVIEW3D_H

#include "CBaseView.h"
#include "CScene.h"

class CView3D : public CBaseView
{
private:
protected:
    HDC	m_hDC;
    HGLRC m_hRC;

	CToolManager* m_pToolMan;
public:
	CView3D();
	~CView3D();
	
	LRESULT ViewProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
	void InitView();
	void DrawView();
	void KillView();
	void OnResize();
	void UseView();

};
#endif