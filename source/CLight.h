#ifndef CLIGHT_H
#define CLIGHT_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "wiskunde.h"

class CLight
{
private:
protected:
	static int lightCount;
	int			m_nlightNum;

	Color		m_cAmbient;
	Color		m_cDiffuse;
	Color		m_cSpecular;
	Color		m_cEmissive;

	float		m_fPosition[4];
public:
	CLight();
	~CLight();

	void Initialize();
	void Switch(bool onoff);

	void SetPosition(Vector position);
};
#endif
