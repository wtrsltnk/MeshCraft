#ifndef CDIALOGPLUGIN_H
#define CDIALOGPLUGIN_H

#include <windows.h>
#include <commctrl.h>
#include "resource.h"
#include "CBaseDialog.h"

#include "CPluginManager.h"

class CDialogPlugin : public CBaseDialog
{
protected:
public:
	CDialogPlugin();
	~CDialogPlugin();

	void Init(HWND hOwner, HINSTANCE hInstance);
	int Show();

	static BOOL PluginProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static void InitPluginView(HWND hDlg);
};
#endif