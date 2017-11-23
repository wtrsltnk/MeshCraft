#ifndef CPLUGINMANAGER_H
#define CPLUGINMANAGER_H

#include "CPluginFile.h"
#include <vector>
#include <string>
using namespace std;

typedef struct FilePlugin
{
	HINSTANCE		hInst;
	CPluginFile*	pPlugin;
} FilePlugin;

class CPluginManager
{
private:
	static CPluginManager* m_pInstance;
protected:
	CPluginManager();

	vector <FilePlugin> m_vFilePlugins;

	// Memberfunctions
	int AddPlugin(string path);
public:
	~CPluginManager();
	static CPluginManager* GetInstance();

	// Memberfunctions
	int LoadPlugins(string path);
	int GetFilePluginCount();
	const char* GetFilePluginName(int index);
	FilePlugin* GetFilePlugin(int index);
};
#endif