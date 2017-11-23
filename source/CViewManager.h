#ifndef CVIEWMANAGER_H
#define CVIEWMANAGER_H

#include "CView3D.h"

#define VIEW_ID_1	1
#define VIEW_ID_2	2
#define VIEW_ID_3	3
#define VIEW_ID_4	4
#define VIEW_ID_5	5

class CViewManager
{
private:
	HWND			m_hParent;
	HINSTANCE		m_hInstance;

	CView3D			m_View1;
	//CView3D			m_View2;
protected:
public:
	CViewManager();
	~CViewManager();

	void InitViews(HWND hParent, HINSTANCE hInstance);
	void ResizeViews(int nWidth, int nHeight);
	void KillViews();
	void UseView(int index);
};
#endif