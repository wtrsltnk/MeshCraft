#include "mathlib.h"

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixZero(matrix44_t m_in)
{
	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 4; j++ )
		{
			m_in[i][j] = 0;
		}
	}
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixIdentity(matrix44_t m_in)
{
	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 4; j++ )
		{
			m_in[i][j] = 0;
		}
		m_in[i][i] = 1;
	}
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixCopy(matrix44_t m_in, matrix44_t m_out)
{
	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 4; j++ )
		{
			m_out[i][j] = m_in[i][j];
		}
	}
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixMultiply(matrix44_t m_in1, matrix44_t m_in2, matrix44_t m_out)
{
	m_out[0][0] =	(m_in1[0][0] * m_in2[0][0]) + (m_in1[0][1] * m_in2[1][0]) +
					(m_in1[0][2] * m_in2[2][0]) + (m_in1[0][3] * m_in2[3][0]);

	m_out[0][1] =	(m_in1[0][0] * m_in2[0][1]) + (m_in1[0][1] * m_in2[1][1]) +
					(m_in1[0][2] * m_in2[2][1]) + (m_in1[0][3] * m_in2[3][1]);

	m_out[0][2] =	(m_in1[0][0] * m_in2[0][2]) + (m_in1[0][1] * m_in2[1][2]) +
					(m_in1[0][2] * m_in2[2][2]) + (m_in1[0][3] * m_in2[3][2]);

	m_out[0][3] =	(m_in1[0][0] * m_in2[0][3]) + (m_in1[0][1] * m_in2[1][3]) +
					(m_in1[0][2] * m_in2[2][3]) + (m_in1[0][3] * m_in2[3][3]);


	m_out[1][0] =	(m_in1[1][0] * m_in2[0][0]) + (m_in1[1][1] * m_in2[1][0]) +
					(m_in1[1][2] * m_in2[2][0]) + (m_in1[1][3] * m_in2[3][0]);

	m_out[1][1] =	(m_in1[1][0] * m_in2[0][1]) + (m_in1[1][1] * m_in2[1][1]) +
					(m_in1[1][2] * m_in2[2][1]) + (m_in1[1][3] * m_in2[3][1]);

	m_out[1][2] =	(m_in1[1][0] * m_in2[0][2]) + (m_in1[1][1] * m_in2[1][2]) +
					(m_in1[1][2] * m_in2[2][2]) + (m_in1[1][3] * m_in2[3][2]);

	m_out[1][3] =	(m_in1[1][0] * m_in2[0][3]) + (m_in1[1][1] * m_in2[1][3]) +
					(m_in1[1][2] * m_in2[2][3]) + (m_in1[1][3] * m_in2[3][3]);


	m_out[2][0] =	(m_in1[2][0] * m_in2[0][0]) + (m_in1[2][1] * m_in2[1][0]) +
					(m_in1[2][2] * m_in2[2][0]) + (m_in1[2][3] * m_in2[3][0]);

	m_out[2][1] =	(m_in1[2][0] * m_in2[0][1]) + (m_in1[2][1] * m_in2[1][1]) +
					(m_in1[2][2] * m_in2[2][1]) + (m_in1[2][3] * m_in2[3][1]);

	m_out[2][2] =	(m_in1[2][0] * m_in2[0][2]) + (m_in1[2][1] * m_in2[1][2]) +
					(m_in1[2][2] * m_in2[2][2]) + (m_in1[2][3] * m_in2[3][2]);

	m_out[2][3] =	(m_in1[2][0] * m_in2[0][3]) + (m_in1[2][1] * m_in2[1][3]) +
					(m_in1[2][2] * m_in2[2][3]) + (m_in1[2][3] * m_in2[3][3]);


	m_out[3][0] =	(m_in1[3][0] * m_in2[0][0]) + (m_in1[3][1] * m_in2[1][0]) +
					(m_in1[3][2] * m_in2[2][0]) + (m_in1[3][3] * m_in2[3][0]);

	m_out[3][1] =	(m_in1[3][0] * m_in2[0][1]) + (m_in1[3][1] * m_in2[1][1]) +
					(m_in1[3][2] * m_in2[2][1]) + (m_in1[3][3] * m_in2[3][1]);

	m_out[3][2] =	(m_in1[3][0] * m_in2[0][2]) + (m_in1[3][1] * m_in2[1][2]) +
					(m_in1[3][2] * m_in2[2][2]) + (m_in1[3][3] * m_in2[3][2]);

	m_out[3][3] =	(m_in1[3][0] * m_in2[0][3]) + (m_in1[3][1] * m_in2[1][3]) +
					(m_in1[3][2] * m_in2[2][3]) + (m_in1[3][3] * m_in2[3][3]);
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixAdition(matrix44_t m_in1, matrix44_t m_in2, matrix44_t m_out)
{
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixSubstraction(matrix44_t m_in1, matrix44_t m_in2, matrix44_t m_out)
{
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixTranslate(vec4_t v_translations, matrix44_t m_out)
{
	MatrixIdentity(m_out);
	m_out[3][0] = v_translations[0];
	m_out[3][1] = v_translations[1];
	m_out[3][2] = v_translations[2];
//	m_out[3][3] = v_translations[3];
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixScale(vec4_t v_scalings, matrix44_t m_out)
{
	MatrixIdentity(m_out);
	m_out[0][0] = v_scalings[0];
	m_out[1][1] = v_scalings[1];
	m_out[2][2] = v_scalings[2];
//	m_out[3][3] = v_scalings[3];
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixRotateXDeg(vec_t v_rotationx, matrix44_t m_out)
{
	MatrixIdentity(m_out);
	m_out[1][1] = cosf( DEG2RAD(v_rotationx) );
	m_out[1][2] = sinf( DEG2RAD(v_rotationx) );
	m_out[2][1] = -sinf( DEG2RAD(v_rotationx) );
	m_out[2][2] = cosf( DEG2RAD(v_rotationx) );
/*
	[ 1,         0,          0, 0]
	[ 0, cos(xrot),  sin(xrot), 0]
	[ 0,-sin(xrot),  cos(xrot), 0]
	[ 0,         0,          0, 1]
*/
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixRotateYDeg(vec_t v_rotationy, matrix44_t m_out)
{
	MatrixIdentity(m_out);
	m_out[0][0] = cosf( DEG2RAD(v_rotationy) );
	m_out[0][2] = -sinf( DEG2RAD(v_rotationy) );
	m_out[2][0] = sinf( DEG2RAD(v_rotationy) );
	m_out[2][2] = cosf( DEG2RAD(v_rotationy) );
/*
	[ cos(yrot), 0,-sin(yrot), 0]
	[         0, 1,         0, 0]
	[ sin(yrot), 0, cos(yrot), 0]
	[         0, 0,         0, 1]
*/
}

////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
////////////////////////////////////////////////////////////////////
void MatrixRotateZDeg(vec_t v_rotationz, matrix44_t m_out)
{
	MatrixIdentity(m_out);
	m_out[0][0] = cosf( DEG2RAD(v_rotationz) );
	m_out[0][1] = sinf( DEG2RAD(v_rotationz) );
	m_out[1][0] = -sinf( DEG2RAD(v_rotationz) );
	m_out[1][1] = cosf( DEG2RAD(v_rotationz) );
/*
	[ cos(zrot),  sin(zrot), 0, 0]
	[-sin(zrot),  cos(zrot), 0, 0]
	[         0,          0, 1, 0]
	[         0,          0, 0, 1]
*/
}
