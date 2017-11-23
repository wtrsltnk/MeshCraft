#ifndef CBASETOOL_H
#define CBASETOOL_H

#include <windows.h>

enum tToolName
{
	Camera = 0,
	Select
};

class CBaseView;
class CBaseTool
{
private:
protected:
	bool m_bActive;
public:
	CBaseTool();
	~CBaseTool();

	// Left Mouse Button actions
	virtual int OnLMouseDown(CBaseView* pView, int x, int y, long wKeys) { return false; };
	virtual int OnLMouseUp(CBaseView* pView, int x, int y, long wKeys) { return false; };
	virtual int OnLMouseDblClk(CBaseView* pView, int x, int y, long wKeys) { return false; };

	// Middle Mouse Button actions
	virtual int OnMMouseDown(CBaseView* pView, int x, int y, long wKeys) { return false; };
	virtual int OnMMouseUp(CBaseView* pView, int x, int y, long wKeys) { return false; };
	virtual int OnMMouseDblClk(CBaseView* pView, int x, int y, long wKeys) { return false; };

	// Right Mouse Button actions
	virtual int OnRMouseDown(CBaseView* pView, int x, int y, long wKeys) { return false; };
	virtual int OnRMouseUp(CBaseView* pView, int x, int y, long wKeys) { return false; };
	virtual int OnRMouseDblClk(CBaseView* pView, int x, int y, long wKeys) { return false; };

	// Other Mouse actions
	virtual int OnMouseMove(CBaseView* pView, int x, int y, long wKeys) { return false; };
	virtual int OnMouseWheel(CBaseView* pView, int x, int y, long wKeys, int nRotation) { return false; };

	// Key actions
	virtual int OnKeyDown(CBaseView* pView, int nVK) { return false; };
	virtual int OnKeyUp(CBaseView* pView, int nVK) { return false; };
};
#endif