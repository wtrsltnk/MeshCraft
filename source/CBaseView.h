#ifndef CBASEVIEW_H
#define CBASEVIEW_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>

#include "CCamera.h"
#include "CLight.h"
#include "CToolManager.h"

class CBaseView
{
private:
protected:
	HWND						m_hWnd, m_hParent;
	HINSTANCE					m_hInstance;
	DWORD						m_nId;
	DWORD						m_dwWindowStyle;
	DWORD						m_dwExWindowStyle;
 	DWORD						m_dwCreationFlags;
	HBRUSH						m_hbrWindowColor;
	RECT						m_rcSize;

	CCamera						m_Camera;
	CLight						m_Light;
	CLight						m_Light2;
	bool						m_bActive;
public:
	CBaseView();
	~CBaseView();
	virtual LRESULT ViewProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) = 0;
	void SetHandle( HWND hWnd ) { m_hWnd = hWnd; };
	
	void Create(HWND hParent, HINSTANCE hInstance, int nID);
	void Resize(RECT rcSize);
	void Invalidate();

	virtual void InitView() = 0;
	virtual void DrawView() = 0;
	virtual void KillView() = 0;
	virtual void OnResize() = 0;
	virtual void UseView() = 0;

	virtual void Activate(bool bActive);
	virtual bool IsActive();

	CCamera* GetCamera() { return &m_Camera; }
};
#endif