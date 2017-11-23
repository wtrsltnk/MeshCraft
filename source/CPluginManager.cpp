#include "CPluginManager.h"

CPluginManager* CPluginManager::m_pInstance = NULL;

///////////////////////////////////////////////////////////////////////////////////////////
// Constructor en Deconstructor
///////////////////////////////////////////////////////////////////////////////////////////
CPluginManager::CPluginManager()
{
}

CPluginManager::~CPluginManager()
{
	for ( int i = 0; i < m_vFilePlugins.size(); i++ )
	{
		FreeLibrary(m_vFilePlugins[i].hInst);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
CPluginManager* CPluginManager::GetInstance()
{
	if (m_pInstance == NULL)
		m_pInstance = new CPluginManager();

	return m_pInstance;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////	
int CPluginManager::AddPlugin(string path)
{
	HINSTANCE			hInst = 0;
	PFN_CREATEPLUGIN	pfnCreatePlugin;
	PFN_DELETEPLUGIN	pfnDeletePlugin;
	CPluginFile*		pPlugin = 0;
	
	if (path.length() <= 0)
		return 0;

	hInst = LoadLibrary(path.c_str());
	if ( hInst )
	{
		pfnCreatePlugin = (PFN_CREATEPLUGIN)GetProcAddress(hInst, "CreatePlugin");
		pfnDeletePlugin = (PFN_DELETEPLUGIN)GetProcAddress(hInst, "DeletePlugin");
		if ( pfnCreatePlugin && pfnDeletePlugin )
		{
			FilePlugin plg;
			plg.hInst = hInst;
			plg.pPlugin = (pfnCreatePlugin)();

			m_vFilePlugins.push_back(plg);

			return 1;
		}
		FreeLibrary(hInst);
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////	
int CPluginManager::LoadPlugins(string path)
{
	WIN32_FIND_DATA FileData; 
	HANDLE hSearch;
	string tmp;

	if (path.find_last_of('\\') )
		path.append("\\");

	tmp = path;
	tmp.append("*.dll");

	hSearch = FindFirstFile(tmp.c_str(), &FileData); 
	if (hSearch == INVALID_HANDLE_VALUE) 
		return 0;

	do
	{
		AddPlugin(path + FileData.cFileName);
	}
	while (FindNextFile(hSearch, &FileData));
	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////	
int CPluginManager::GetFilePluginCount()
{
	return m_vFilePlugins.size();
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////	
const char* CPluginManager::GetFilePluginName(int index)
{
	if ( index < m_vFilePlugins.size() )
		return m_vFilePlugins[index].pPlugin->GetName();

	return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////	
FilePlugin* CPluginManager::GetFilePlugin(int index)
{
	if ( index < m_vFilePlugins.size() )
		return &m_vFilePlugins[index];

	return NULL;
}
