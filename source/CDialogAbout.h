#ifndef CDIALOGABOUT_H
#define CDIALOGABOUT_H

#include <windows.h>
#include "resource.h"
#include "CBaseDialog.h"

class CDialogAbout : public CBaseDialog
{
private:
protected:
public:
	CDialogAbout();
	~CDialogAbout();

	void Init(HWND hOwner, HINSTANCE hInstance);
	int Show();

	static BOOL AboutProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

};
#endif