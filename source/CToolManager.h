#ifndef CTOOLMANAGER_H
#define CTOOLMANAGER_H

#include "CToolCamera.h"

enum tools_t
{
	tool_camera = 0,
	tool_select
};

class CToolManager
{
private:
	CToolManager();
	~CToolManager();
protected:
	static CToolManager* m_pInstance;
	CBaseTool* m_pCurrentTool;

	CToolCamera* m_pCamera;
public:

	static CToolManager* GetInstance();
	CBaseTool* GetCurrentTool();
	CBaseTool* SelectTool(tools_t tool);
	void DeselectTool();
};
#endif