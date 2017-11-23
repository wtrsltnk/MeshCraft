#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#define null 0

#include "CWin.h"
#include "resource.h"

#include "CViewManager.h"
#include "CToolManager.h"
#include "CDialogManager.h"
#include "CPluginManager.h"


class CApplication : public CWin
{
private:
	CViewManager		m_ViewManager;
	CDialogManager		m_DialogMananger;
	CPluginManager*		m_pPluginManager;
	CToolManager*		m_pToolManager;

	CScene*				m_pScene;
public:
	CApplication();
	~CApplication();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);

	void FillPluginMenu();
};

#endif
