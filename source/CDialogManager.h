#ifndef CDIALOGMANAGER_H
#define CDIALOGMANAGER_H

#include "CDialogAbout.h"
#include "CDialogPlugins.h"

enum Dialogs
{
	About = 0,
	Plugin
};

class CDialogManager
{
private:
	HWND		m_hOwner;
	HINSTANCE	m_hInstance;
protected:
	CDialogAbout	m_About;
	CDialogPlugin	m_Plugin;
public:
	CDialogManager();
	~CDialogManager();

	int ShowDialog(int nDialog);
	void InitDialogs(HWND hOwner, HINSTANCE hInstance);
};
#endif