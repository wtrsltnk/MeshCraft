#include "CView3D.h"

///////////////////////////////////////////////////////////////////////////////////////////
// Constructor en Deconstructor
///////////////////////////////////////////////////////////////////////////////////////////
CView3D::CView3D()
{
    m_hDC = NULL;
    m_hRC = NULL;
}

CView3D::~CView3D()
{
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
LRESULT CView3D::ViewProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	CBaseTool* pTool;

	switch (uMsg)
	{
	case WM_CREATE:
		{
			InitView();
			SetTimer(hWnd, 23, 10, NULL);
			break;
		}

	case WM_TIMER:
		{
			InvalidateRect(hWnd, NULL, true);
			break;
		}

	case WM_PAINT:
		{
			DrawView();
			ValidateRect(hWnd, NULL);
			break;
		}

	case WM_CLOSE:
		{
			KillView();
			break;
		}

	case WM_LBUTTONDOWN:
		{
			SetFocus(hWnd);
			pTool = m_pToolMan->GetCurrentTool();
			if ( pTool )
			{
				return pTool->OnLMouseDown(this, LOWORD(lParam), HIWORD(lParam), wParam);
			}
			break;
		}

	case WM_LBUTTONUP:
		{
			pTool = m_pToolMan->GetCurrentTool();
			if ( pTool )
			{
				return pTool->OnLMouseUp(this, LOWORD(lParam), HIWORD(lParam), wParam);
			}
			break;
		}

	case WM_RBUTTONDOWN:
		{
			SetFocus(hWnd);
			pTool = m_pToolMan->GetCurrentTool();
			if ( pTool )
			{
				return pTool->OnRMouseDown(this, LOWORD(lParam), HIWORD(lParam), wParam);
			}
			break;
		}

	case WM_RBUTTONUP:
		{
			pTool = m_pToolMan->GetCurrentTool();
			if ( pTool )
			{
				return pTool->OnRMouseUp(this, LOWORD(lParam), HIWORD(lParam), wParam);
			}
			break;
		}

	case WM_MOUSEMOVE:
		{
			pTool = m_pToolMan->GetCurrentTool();
			if ( pTool )
			{
				pTool->OnMouseMove(this, LOWORD(lParam), HIWORD(lParam), wParam);
			}
			break;
		}

	case WM_KEYDOWN:
		{
			pTool = m_pToolMan->GetCurrentTool();
			if ( pTool )
			{
				pTool->OnKeyDown(this, wParam);
			}
			break;
		}

	case WM_KEYUP:
		{
			pTool = m_pToolMan->GetCurrentTool();
			if ( pTool )
			{
				pTool->OnKeyUp(this, wParam);
			}
			break;
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void CView3D::InitView()
{
	int		PixelFormat;

	// Pixel format difinieren
	static	PIXELFORMATDESCRIPTOR pfd=
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		16,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	
	// Device Context opvragen
	if (!(m_hDC=GetDC(m_hWnd)))
	{
		KillView();
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return;
	}

	// Huidige Pixel format opvragen
	if (!(PixelFormat=ChoosePixelFormat(m_hDC,&pfd)))
	{
		KillView();
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return;
	}

	// Nieuwe Pixelformat instellen
	if(!SetPixelFormat(m_hDC,PixelFormat,&pfd))
	{
		KillView();
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return;
	}

	// Render Context maken
	if (!(m_hRC=wglCreateContext(m_hDC)))
	{
		KillView();
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return;
	}

	// Render context van dit scherm de huidige OpenGL context maken
	if(!wglMakeCurrent(m_hDC,m_hRC))
	{
		KillView();
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return;
	}
		
	m_pToolMan = CToolManager::GetInstance();

	GLfloat light_position[] = { 0.0, 0.0, 0.0, 0.0 };
	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_FLAT);

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	CScene::GetInstance()->ReloadTextures();
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void CView3D::DrawView()
{
    wglMakeCurrent( m_hDC, m_hRC );
	glLoadIdentity();
	glPushMatrix();

	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);


	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	m_Camera.SetupCamera();
	CScene::GetInstance()->Draw();

	glBegin(GL_QUADS);
		// Front Face
		glNormal3f( 0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		// Back Face
		glNormal3f( 0.0f, 0.0f,-1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		// Top Face
		glNormal3f( 0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		// Bottom Face
		glNormal3f( 0.0f,-1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		// Right face
		glNormal3f( 1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		// Left Face
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
	glEnd();

	glPopMatrix();
	SwapBuffers( m_hDC );
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void CView3D::KillView()
{
	if (m_hRC)
	{
		if (!wglMakeCurrent(NULL,NULL))
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(m_hRC))
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		m_hRC=NULL;
	}

	if (m_hDC && !ReleaseDC(m_hWnd,m_hDC))
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		m_hDC=NULL;
	}

	if (m_hWnd && !DestroyWindow(m_hWnd))
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		m_hWnd=NULL;
	}
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void CView3D::OnResize()
{
    wglMakeCurrent( m_hDC, m_hRC );

	glViewport(0, 0, m_rcSize.right, m_rcSize.bottom);
		
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective( 45.0f, (float)m_rcSize.right/(float)m_rcSize.bottom, 0.01f, 300.0f );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void CView3D::UseView()
{
    wglMakeCurrent( m_hDC, m_hRC );
}
