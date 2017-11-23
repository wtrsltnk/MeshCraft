#ifndef CPLUGINFILE_H
#define CPLUGINFILE_H

#ifdef PLUGIN_DLL
#define _DYNLINK __declspec( dllexport)
#else
#define _DYNLINK __declspec( dllimport)
#endif

#include "simple_format.h"

class _DYNLINK CPluginFile
{
private:
protected:
	char Name[64];
	bool Openable;
	bool Saveable;
public:
	CPluginFile(){};
	virtual ~CPluginFile(){};

	virtual const char* GetName() = 0;
	virtual bool IsOpenable() = 0;
	virtual bool IsSaveable() = 0;
	virtual Mesh* OpenModel(HWND hOwner) = 0;
	virtual bool SaveModel(Mesh* mesh, HWND hOwner) = 0;
};

typedef CPluginFile* (*PFN_CREATEPLUGIN)();
CPluginFile* CreatePlugin();

typedef void (*PFN_DELETEPLUGIN)(CPluginFile*);
void DeletePlugin(CPluginFile* plg);

#endif