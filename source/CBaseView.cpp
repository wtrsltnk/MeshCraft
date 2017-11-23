#include "CBaseView.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Koppeling WIN32 -> Klasse
/////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK GLProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CBaseView *wnd = 0; 

	if(uMsg == WM_NCCREATE) 
	{ 
		wnd = reinterpret_cast<CBaseView *>(((LPCREATESTRUCT)lParam)->lpCreateParams); 
		::SetWindowLong(hWnd, GWL_USERDATA, reinterpret_cast<long>(wnd));

		wnd->SetHandle( hWnd );
	} 
	else 
		wnd = reinterpret_cast<CBaseView *>(::GetWindowLong(hWnd, GWL_USERDATA)); 

		return wnd->ViewProc(hWnd, uMsg, wParam, lParam);
}

///////////////////////////////////////////////////////////////////////////////////////////
// Constructor en Deconstructor
///////////////////////////////////////////////////////////////////////////////////////////
CBaseView::CBaseView()
{
	this->m_hWnd				= NULL;
	this->m_hParent				= NULL;
	this->m_hInstance			= NULL;
	this->m_nId					= NULL;
	this->m_dwWindowStyle		= WS_VISIBLE | WS_CHILD | WS_BORDER;
	this->m_dwExWindowStyle		= WS_EX_WINDOWEDGE;
 	this->m_dwCreationFlags		= SW_SHOW;
	this->m_hbrWindowColor		= (HBRUSH)(COLOR_WINDOW+1);
	this->m_rcSize.left			= 0;
	this->m_rcSize.right		= 100;
	this->m_rcSize.top			= 0;
	this->m_rcSize.bottom		= 100;

	WNDCLASS	wc;
	
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc		= (WNDPROC) GLProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= m_hInstance;
	wc.hIcon			= NULL;
	wc.hCursor			= LoadCursor( NULL, IDC_ARROW );
	wc.hbrBackground	= m_hbrWindowColor;
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= "GLWindow";

	::RegisterClass(&wc);
}

CBaseView::~CBaseView()
{
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CBaseView::Create(HWND hParent, HINSTANCE hInstance, int nID)
{
	this->m_hParent = hParent;
	this->m_hInstance = hInstance;
	this->m_nId = nID;

	m_hWnd = ::CreateWindowEx(	this->m_dwExWindowStyle,
							"GLWindow",
							"",
							this->m_dwWindowStyle |
							WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
							m_rcSize.left, m_rcSize.top,
							m_rcSize.right,
							m_rcSize.bottom,
							hParent,
							NULL,
							m_hInstance,
							this
						 );
	
	::ShowWindow(m_hWnd, m_dwCreationFlags);
	::UpdateWindow(m_hWnd);

	InitView();
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CBaseView::Resize(RECT rcSize)
{
	this->m_rcSize = rcSize;
	::MoveWindow( m_hWnd, m_rcSize.left, m_rcSize.top, m_rcSize.right, m_rcSize.bottom, true );
	OnResize();
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CBaseView::Invalidate()
{
	InvalidateRect(m_hWnd, NULL, true);
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CBaseView::Activate(bool bActive)
{
	 m_bActive = bActive;
}
///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
bool CBaseView::IsActive()
{
	return m_bActive;
}