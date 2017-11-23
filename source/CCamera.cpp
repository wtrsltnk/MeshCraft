#include "CCamera.h"

///////////////////////////////////////////////////////////////////////////////////////////
// Constructor en Deconstructor
///////////////////////////////////////////////////////////////////////////////////////////
CCamera::CCamera()
{

	m_vPosition.Fill(0.0f, 0.0f, 5.0f);
	m_vView.Fill(0.0f, 0.0f, 1.0f);
	m_vUp.Fill(0.0f, 1.0f, 0.0f);
	m_vRight.Fill(1.0f, 0.0f, 0.0f);
}

CCamera::~CCamera()
{
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CCamera::SetupCamera()
{
	KeyHandling();
	gluLookAt(	m_vPosition.X, m_vPosition.Y, m_vPosition.Z,
				m_vView.X, m_vView.Y, m_vView.Z,
				m_vUp.X, m_vUp.Y, m_vUp.Z);
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CCamera::SetCamera(Vector position, Vector view, Vector up)
{
	this->m_vPosition = position;
	this->m_vView = view;
	this->m_vUp = up;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CCamera::MoveForward(float fDistance)
{
	Vector v = m_vView.Vectorize(m_vPosition);
	v.Normalize();

	m_vPosition.X += v.X * fDistance;
	m_vPosition.Y += v.Y * fDistance;
	m_vPosition.Z += v.Z * fDistance;

	m_vView.X += v.X * fDistance;
	m_vView.Y += v.Y * fDistance;
	m_vView.Z += v.Z * fDistance;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CCamera::MoveRight(float fDistance)
{
	m_vRight = Wiskunde::Cross(m_vView - m_vPosition, m_vUp);
	m_vRight.Normalize();

	m_vPosition.X += m_vRight.X * fDistance;
	m_vPosition.Z += m_vRight.Z * fDistance;

	m_vView.X += m_vRight.X * fDistance;
	m_vView.Z += m_vRight.Z * fDistance;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CCamera::TurnAround(float fDegree)
{
	Vector vNewView;

	Vector vView = m_vView - m_vPosition;		

	float cosTheta = (float)cos(fDegree);
	float sinTheta = (float)sin(fDegree);

	vNewView.X  = (cosTheta + (1 - cosTheta) * 0 * 0)		* vView.X;
	vNewView.X += ((1 - cosTheta) * 0 * 1 - 0 * sinTheta)	* vView.Y;
	vNewView.X += ((1 - cosTheta) * 0 * 0 + 1 * sinTheta)	* vView.Z;

	vNewView.Y  = ((1 - cosTheta) * 0 * 1 + 0 * sinTheta)	* vView.X;
	vNewView.Y += (cosTheta + (1 - cosTheta) * 1 * 1)		* vView.Y;
	vNewView.Y += ((1 - cosTheta) * 1 * 0 - 0 * sinTheta)	* vView.Z;

	vNewView.Z  = ((1 - cosTheta) * 0 * 0 - 1 * sinTheta)	* vView.X;
	vNewView.Z += ((1 - cosTheta) * 1 * 0 + 0 * sinTheta)	* vView.Y;
	vNewView.Z += (cosTheta + (1 - cosTheta) * 0 * 0)		* vView.Z;

	m_vView = m_vPosition + vNewView;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CCamera::LookUpDown(float fDegree)
{
	Vector vNewView;

	m_vRight = Wiskunde::Cross(m_vView - m_vPosition, m_vUp);
	m_vRight.Normalize();
	Vector vView = m_vView - m_vPosition;		

	float cosTheta = (float)cos(fDegree);
	float sinTheta = (float)sin(fDegree);

	vNewView.X  = (cosTheta + (1 - cosTheta) * m_vRight.X * m_vRight.X)		* vView.X;
	vNewView.X += ((1 - cosTheta) * m_vRight.X * m_vRight.Y - m_vRight.Z * sinTheta)	* vView.Y;
	vNewView.X += ((1 - cosTheta) * m_vRight.X * m_vRight.Z + m_vRight.Y * sinTheta)	* vView.Z;

	vNewView.Y  = ((1 - cosTheta) * m_vRight.X * m_vRight.Y + m_vRight.Z * sinTheta)	* vView.X;
	vNewView.Y += (cosTheta + (1 - cosTheta) * m_vRight.Y * m_vRight.Y)		* vView.Y;
	vNewView.Y += ((1 - cosTheta) * m_vRight.Y * m_vRight.Z - m_vRight.X * sinTheta)	* vView.Z;

	vNewView.Z  = ((1 - cosTheta) * m_vRight.X * m_vRight.Z - m_vRight.Y * sinTheta)	* vView.X;
	vNewView.Z += ((1 - cosTheta) * m_vRight.Y * m_vRight.Z + m_vRight.X * sinTheta)	* vView.Y;
	vNewView.Z += (cosTheta + (1 - cosTheta) * m_vRight.Z * m_vRight.Z)		* vView.Z;

	m_vView = m_vPosition + vNewView;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CCamera::KeyHandling()
{
	float kSpeed = 0.1f;

	if(GetKeyState(VK_UP) & 0x80 || GetKeyState('W') & 0x80)
	{
		MoveForward(kSpeed);
	}

	if(GetKeyState(VK_DOWN) & 0x80 || GetKeyState('S') & 0x80)
	{
		MoveForward(-kSpeed);				
	}

	if(GetKeyState(VK_LEFT) & 0x80 || GetKeyState('A') & 0x80)
	{
		MoveRight(-kSpeed);
	}

	if(GetKeyState(VK_RIGHT) & 0x80 || GetKeyState('D') & 0x80)
	{
		MoveRight(kSpeed);
	}	
}
