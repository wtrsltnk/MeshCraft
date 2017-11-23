#include "CDialogPlugins.h"

///////////////////////////////////////////////////////////////////////////////////////////
// Constructor en Deconstructor
///////////////////////////////////////////////////////////////////////////////////////////
CDialogPlugin::CDialogPlugin()
{
	m_wResourceDialog = IDD_PLUGIN;
}

CDialogPlugin::~CDialogPlugin()
{
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CDialogPlugin::Init(HWND hOwner, HINSTANCE hInstance)
{
	this->m_hOwner = hOwner;
	this->m_hInstance = hInstance;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
int CDialogPlugin::Show()
{
	return DialogBox(m_hInstance, MAKEINTRESOURCE(m_wResourceDialog), m_hOwner, (DLGPROC)PluginProc);
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
BOOL CDialogPlugin::PluginProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		{
			InitPluginView(hDlg);
			break;
		}

	case WM_PAINT:
		{
			break;
		}

	case WM_CLOSE:
		{
			EndDialog( hDlg, IDOK );
			break;
		}

	case WM_COMMAND:
		{
			switch( LOWORD(wParam) )
			{
  			case IDOK:
				EndDialog( hDlg, IDOK );
				break;
			}
			break;
		}
	}
	return FALSE;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CDialogPlugin::InitPluginView(HWND hDlg)
{
	HWND hPluginView = GetDlgItem(hDlg, IDC_PLUGINS);

			
	ListView_SetExtendedListViewStyle(hPluginView, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	LVCOLUMN col;
	col.mask = LVCF_TEXT | LVCF_WIDTH;
    col.cx = 200;
    col.pszText = "Name";
    col.cchTextMax = 4;
	ListView_InsertColumn(hPluginView, 0, &col);
	
	col.mask = LVCF_TEXT | LVCF_WIDTH;
    col.cx = 40;
    col.pszText = "Open";
    col.cchTextMax = 4;
	ListView_InsertColumn(hPluginView, 1, &col);
	
	col.mask = LVCF_TEXT | LVCF_WIDTH;
    col.cx = 40;
    col.pszText = "Save";
    col.cchTextMax = 4;
	ListView_InsertColumn(hPluginView, 2, &col);

	for (int i = 0; i < CPluginManager::GetInstance()->GetFilePluginCount(); i++)
	{
		FilePlugin* fp = CPluginManager::GetInstance()->GetFilePlugin(i);

		LVITEM item;

		item.mask = LVIF_TEXT;
		item.iItem = i;
		item.iSubItem = 0;
		item.pszText = const_cast <char*>(fp->pPlugin->GetName());
		item.cchTextMax = sizeof(item.pszText);
		ListView_InsertItem(hPluginView, &item);

		if (fp->pPlugin->IsOpenable()) {
			ListView_SetItemText(hPluginView, i, 1, "true");
		}
		else {
			ListView_SetItemText(hPluginView, i, 1, "false");
		}
		if (fp->pPlugin->IsSaveable()) {
			ListView_SetItemText(hPluginView, i, 2, "true");
		}
		else {
			ListView_SetItemText(hPluginView, i, 2, "false");
		}
	}
}