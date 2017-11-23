#include "CToolCamera.h"
#include "CBaseView.h"

#include <windows.h>

///////////////////////////////////////////////////////////////////////////////////////////
// Constructor en Deconstructor
///////////////////////////////////////////////////////////////////////////////////////////
CToolCamera::CToolCamera()
{
}

CToolCamera::~CToolCamera()
{
}

// Left Mouse Button actions

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnLMouseDown(CBaseView* pView, int x, int y, long wKeys)
{
	m_nDownX = x;
	m_nDownY = y;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnLMouseUp(CBaseView* pView, int x, int y, long wKeys)
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnLMouseDblClk(CBaseView* pView, int x, int y, long wKeys)
{
	return 0;
}

// Middle Mouse Button actions

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnMMouseDown(CBaseView* pView, int x, int y, long wKeys)
{
	m_nDownX = x;
	m_nDownY = y;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnMMouseUp(CBaseView* pView, int x, int y, long wKeys)
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnMMouseDblClk(CBaseView* pView, int x, int y, long wKeys)
{
	return 0;
}

// Right Mouse Button actions

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnRMouseDown(CBaseView* pView, int x, int y, long wKeys)
{
	m_nDownX = x;
	m_nDownY = y;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnRMouseUp(CBaseView* pView, int x, int y, long wKeys)
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnRMouseDblClk(CBaseView* pView, int x, int y, long wKeys)
{
	return 0;
}

// Other Mouse actions

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnMouseMove(CBaseView* pView, int x, int y, long wKeys)
{
	if ( pView )
	{		
		if ( wKeys == MK_LBUTTON )
		{
			if ( (m_nDownX-x) != 0 )
			{
				pView->GetCamera()->TurnAround(-(float)(m_nDownX-x) / 500.0f);
				pView->GetCamera()->LookUpDown(-(float)(m_nDownY-y) / 500.0f);
				pView->Invalidate();
			}
		}
		else if ( wKeys == MK_RBUTTON )
		{
			if ( (m_nDownY-y) != 0 )
			{	
				pView->GetCamera()->MoveForward((float)(m_nDownY-y)/50.0f);
				pView->Invalidate();
			}
		}
		else if ( wKeys == MK_MBUTTON )
		{
				pView->GetCamera()->MoveRight(-(float)(m_nDownX-x)/100.0f);
				pView->Invalidate();
		}
		m_nDownX = x;
		m_nDownY = y;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnMouseWheel(CBaseView* pView, int x, int y, long wKeys, int nRotation)
{
	return 0;
}

// Key actions

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnKeyDown(CBaseView* pView, int nVK)
{
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CToolCamera::OnKeyUp(CBaseView* pView, int nVK)
{
	return 0;
}
