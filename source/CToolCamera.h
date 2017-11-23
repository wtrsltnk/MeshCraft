#ifndef CTOOLCAMERA_H
#define CTOOLCAMERA_H

#include "CBaseTool.h"

class CToolCamera : public CBaseTool
{
private:
	int m_nDownX;
	int m_nDownY;
protected:
public:
	CToolCamera();
	~CToolCamera();

	// Left Mouse Button actions
	int OnLMouseDown(CBaseView* pView, int x, int y, long wKeys);
	int OnLMouseUp(CBaseView* pView, int x, int y, long wKeys);
	int OnLMouseDblClk(CBaseView* pView, int x, int y, long wKeys);

	// Middle Mouse Button actions
	int OnMMouseDown(CBaseView* pView, int x, int y, long wKeys);
	int OnMMouseUp(CBaseView* pView, int x, int y, long wKeys);
	int OnMMouseDblClk(CBaseView* pView, int x, int y, long wKeys);

	// Right Mouse Button actions
	int OnRMouseDown(CBaseView* pView, int x, int y, long wKeys);
	int OnRMouseUp(CBaseView* pView, int x, int y, long wKeys);
	int OnRMouseDblClk(CBaseView* pView, int x, int y, long wKeys);

	// Other Mouse actions
	int OnMouseMove(CBaseView* pView, int x, int y, long wKeys);
	int OnMouseWheel(CBaseView* pView, int x, int y, long wKeys, int nRotation);

	// Key actions
	int OnKeyDown(CBaseView* pView, int nVK);
	int OnKeyUp(CBaseView* pView, int nVK);
};
#endif