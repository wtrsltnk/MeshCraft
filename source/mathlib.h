#ifndef MATHLIB_H
#define MATHLIB_H

#include "math.h"

#pragma warning( disable : 4244 ) // double to float

typedef float vec_t;					// Vector item
typedef vec_t vec3_t[3];				// Vector 3 items
typedef vec_t vec4_t[4];				// Vector 4 items
typedef vec3_t matrix33_t[3];			// 3X3 Matrix
typedef vec3_t matrix34_t[4];			// 3X4 Matrix
typedef vec4_t matrix44_t[4];			// 4X4 Matrix

// THX TO http://www.zipcodeworld.com/samples/distance.c.html
#define M_PI 3.14159265358979323846
#define DEG2RAD(deg) (deg * M_PI / 180)

void MatrixZero(matrix44_t m_in);
void MatrixIdentity(matrix44_t m_in);
void MatrixCopy(matrix44_t m_in, matrix44_t m_out);

void MatrixMultiply(matrix44_t m_in1, matrix44_t m_in2, matrix44_t m_out);
void MatrixAdition(matrix44_t m_in1, matrix44_t m_in2, matrix44_t m_out);
void MatrixSubstraction(matrix44_t m_in1, matrix44_t m_in2, matrix44_t m_out);
void MatrixTranslate(vec4_t v_translations, matrix44_t m_out);
void MatrixScale(vec4_t v_scalings, matrix44_t m_out);
void MatrixRotateXDeg(vec_t v_rotationx, matrix44_t m_out);
void MatrixRotateYDeg(vec_t v_rotationy, matrix44_t m_out);
void MatrixRotateZDeg(vec_t v_rotationz, matrix44_t m_out);

#endif