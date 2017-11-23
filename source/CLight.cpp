#include "CLight.h"

int CLight::lightCount = 0;

///////////////////////////////////////////////////////////////////////////////////////////
// Constructor en Deconstructor
///////////////////////////////////////////////////////////////////////////////////////////
CLight::CLight()
{
	m_nlightNum = GL_LIGHT0 + lightCount;
	lightCount++;

	m_fPosition[0] = -1.0f;
	m_fPosition[1] = -4.0f;
	m_fPosition[2] = 0;
	m_fPosition[3] = 0.0f;

	m_cAmbient.Set(1.0f, 1.0f, 0.0f, 1.0f);
	m_cDiffuse.Set(0.1f, 0.1f, 0.1f, 1.0f);
	m_cSpecular.Set(1.0f, 1.0f, 1.0f, 1.0f);
	m_cEmissive.Set(0.0f, 0.0f, 0.0f, 1.0f);
}

CLight::~CLight()
{
	lightCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CLight::Initialize()
{
	//glEnable(m_nlightNum);

	// Ambient
//	glLightfv(m_nlightNum, GL_AMBIENT, m_cAmbient.GetP());
	// Diffuse
//	glLightfv(m_nlightNum, GL_DIFFUSE, m_cDiffuse.GetP());
	// Specular
//	glLightfv(m_nlightNum, GL_SPECULAR, m_cSpecular.GetP());
	// Position
	//glLightfv(m_nlightNum, GL_POSITION, m_fPosition);
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CLight::Switch(bool onoff)
{
	// Light aan of uit
	if ( onoff )
		glEnable(m_nlightNum);						// Zet het licht aan
	else
		glDisable(m_nlightNum);						// Zet het licht uit
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CLight::SetPosition(Vector position)
{
	m_fPosition[0] = position.X;
	m_fPosition[1] = position.Y;
	m_fPosition[2] = position.Z;
	m_fPosition[3] = 0.0f;
}