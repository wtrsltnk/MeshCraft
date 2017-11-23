#ifndef CCAMERA_H
#define CCAMERA_H

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include "wiskunde.h"

class CCamera
{
private:
protected:
	Vector		m_vPosition;
	Vector		m_vView;
	Vector		m_vUp;
	Vector		m_vRight;

	void CalculateViewMatrix();
public:
	CCamera();
	~CCamera();

	void SetupCamera();
	void KeyHandling();

	void SetCamera(Vector position, Vector view, Vector up);

	void MoveForward(float fDistance);
	void MoveRight(float fDistance);

	void TurnAround(float fDegree);
	void LookUpDown(float fDegree);
};
#endif