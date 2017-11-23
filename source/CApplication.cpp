#include "CApplication.h"
#include <tchar.h>

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CApplication::CApplication()
{
	this->m_hWnd = NULL;
	this->m_dwCreationFlags  = 0L;
	this->m_dwWindowStyle	 = WS_OVERLAPPEDWINDOW;
	this->m_dwExWindowStyle	 = WS_EX_WINDOWEDGE;
	this->m_dwCreationFlags  = SW_SHOW;
	this->m_PosX			 = CW_USEDEFAULT;	
	this->m_PosY			 = CW_USEDEFAULT;	
	this->m_dwCreationWidth  = CW_USEDEFAULT;
	this->m_dwCreationHeight = CW_USEDEFAULT;
	this->m_hbrWindowColor	 = (HBRUSH)(COLOR_WINDOW);
	this->m_hIcon			 = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_MESHCRAFT));
	this->m_strWindowTitle	 = _T("Mesh Craft");
	this->m_hMenu			 = LoadMenu(m_hInstance, MAKEINTRESOURCE(IDR_MAIN_MENU)); 	
}


CApplication::~CApplication()
{
	m_pScene = NULL;
}

/////////////////////////////////////
// Memberfuncties                  //
/////////////////////////////////////

LRESULT CApplication::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			m_pToolManager = CToolManager::GetInstance();
			m_pToolManager->SelectTool(tool_camera);
			m_pPluginManager = CPluginManager::GetInstance();
            m_pPluginManager->LoadPlugins("../Plugins/bin");
			FillPluginMenu();

			m_ViewManager.InitViews(hWnd, m_hInstance);
			m_DialogMananger.InitDialogs(hWnd, m_hInstance);

			m_ViewManager.UseView(1);
			m_pScene = CScene::GetInstance();
			break;
		}

	case WM_SIZE:
		{
			m_ViewManager.ResizeViews(LOWORD(lParam), HIWORD(lParam));
			break;
		}

	case WM_CLOSE:
		{
			CScene::ClearInstance();
			break;
		}

	case WM_QUIT:
		{
			m_ViewManager.KillViews();
			break;
		}

	case WM_COMMAND:
		{
			switch( LOWORD(wParam) )
			{
			case ID_BESTAND_OPEN:
				{
					break;
				}

			case ID_HELP_ABOUT:
				m_DialogMananger.ShowDialog(About);
				break;

			case ID_PLUGIN_PLUGINMANAGER:
				m_DialogMananger.ShowDialog(Plugin);
				break;

			default:
				{
					int id = LOWORD(wParam);
					int max = ID_PLUGIN_PLUGINMANAGER+m_pPluginManager->GetFilePluginCount();
					if (id > ID_PLUGIN_PLUGINMANAGER && id <= max)
					{
						int index = LOWORD(wParam) - ID_PLUGIN_PLUGINMANAGER - 1;
						MessageBox(hWnd, m_pPluginManager->GetFilePluginName(index), "Test", MB_OK);
					}
					break;
				}
			}
			break;
		}
	}
	return CWin::MsgProc(hWnd, uMsg, wParam, lParam);
}

void CApplication::FillPluginMenu()
{
	HMENU hPlugin = GetSubMenu(m_hMenu, 1);


	for (int i = 0; i < m_pPluginManager->GetFilePluginCount(); i++)
	{
		InsertMenu(hPlugin, 1, 0, (UINT)ID_PLUGIN_PLUGINMANAGER + 1 + i, m_pPluginManager->GetFilePluginName(i));
	}

}
