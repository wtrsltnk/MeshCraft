#include "CSMDFile.h"

///////////////////////////////////////////////////////////////////////////////////////////
// External Symbols
///////////////////////////////////////////////////////////////////////////////////////////
CPluginFile* CreatePlugin()
{
	CPluginFile* p = new CSMDFile();
	return p;
}

void DeletePlugin(CPluginFile* plg)
{
	delete plg;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Constructor en Deconstructor
///////////////////////////////////////////////////////////////////////////////////////////
CSMDFile::CSMDFile()
{
	strcpy(Name, "SMDFile");
	this->Openable = true;
	this->Saveable = true;
}

CSMDFile::~CSMDFile()
{
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
const char* CSMDFile::GetName()
{
	return this->Name;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
bool CSMDFile::IsOpenable()
{
	return this->Openable;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
bool CSMDFile::IsSaveable()
{
	return this->Saveable;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
Mesh* CSMDFile::OpenModel(HWND hOwner)
{
	OPENFILENAME ofn = {0};
	char szFile[MAX_PATH+1] = {0};
	
	ofn.Flags             = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
	ofn.hwndOwner         = hOwner;
	ofn.lpstrCustomFilter = 0;
	ofn.lpstrFile         = szFile;
	ofn.lpstrFileTitle    = 0;
	ofn.lpstrFilter       = "SMD file (*.smd)\0*.smd\0";
	ofn.lpstrDefExt		  = "smd";
	ofn.lpstrInitialDir   = 0;
	ofn.lpstrTitle        = "Open SMD file";
	ofn.lStructSize       = sizeof( OPENFILENAME );
	ofn.nMaxFile          = MAX_PATH;


	if( GetOpenFileName( &ofn ) == 0 )
		return NULL;
		
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
bool CSMDFile::SaveModel(Mesh* mesh, HWND hOwner)
{
	OPENFILENAME ofn = {0};
	char szFile[MAX_PATH+1] = {0};
	
	ofn.Flags             = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
	ofn.hwndOwner         = hOwner;
	ofn.lpstrCustomFilter = 0;
	ofn.lpstrFile         = szFile;
	ofn.lpstrFileTitle    = 0;
	ofn.lpstrFilter       = "SMD file (*.smd)\0*.smd\0";
	ofn.lpstrDefExt		  = "smd";
	ofn.lpstrInitialDir   = 0;
	ofn.lpstrTitle        = "Save SMD file";
	ofn.lStructSize       = sizeof( OPENFILENAME );
	ofn.nMaxFile          = MAX_PATH;


	if( GetSaveFileName( &ofn ) == 0 )
		return false;
		
	/*
	FILE* pfile;
	char cmd[1024];
	int option;
	int res;

	if ( !szFile || !pModel )
		return NULL_POINTER;

	if ( (pfile = fopen(szFile, "r")) == 0 )
		return WRONG_FILE;

	
	while (fgets( line, sizeof( line ), pfile ) != NULL)
	{
		linecount++;
		sscanf( line, "%s %d", cmd, &option );
		if ( strcmp(cmd, "version") == 0 )
		{
			if ( option != 1 )
				return WRONG_VERSION;
		}
		else if ( strcmp(cmd, "nodes") == 0 )
		{
			res = LoadNodes(pfile, pModel);
			if ( res != ALL_OK )
				return res;
		}
		else if ( strcmp(cmd, "skeleton") == 0 )
		{
			res = LoadSkeleton(pfile, pModel);
			if ( res != ALL_OK )
				return res;
		}
		else if ( strcmp(cmd, "triangles") == 0 )
		{
			res = LoadTriangles(pfile, pModel);
			if ( res != ALL_OK )
				return res;
		}
	}
	fclose( pfile );
	*/
	return false;
}


