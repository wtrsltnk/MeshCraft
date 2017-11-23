#ifndef CMESHFILE_H
#define CMESHFILE_H

#ifdef PLUGIN_DLL
#define _DYNLINK __declspec( dllexport)
#else
#define _DYNLINK __declspec( dllimport)
#endif

#include "CPluginFile.h"

class _DYNLINK CMeshFile : public CPluginFile
{
protected:
public:
	CMeshFile();
	~CMeshFile();

	const char* GetName();
	bool IsOpenable();
	bool IsSaveable();
	Mesh* OpenModel(HWND hOwner);
	bool SaveModel(Mesh* mesh, HWND hOwner);
};
#endif