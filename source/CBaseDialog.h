#ifndef CBASEDIALOG_H
#define CBASEDIALOG_H

#include <windows.h>

class CBaseDialog
{
private:
protected:
	WORD		m_wResourceDialog;
	HWND		m_hOwner;
	HINSTANCE	m_hInstance;
public:
	CBaseDialog();
	~CBaseDialog();

	virtual void Init(HWND hOwner, HINSTANCE hInstance) = 0;
	virtual int Show() = 0;
};
#endif