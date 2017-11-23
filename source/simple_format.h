#ifndef SIMPLE_FORMAT_H
#define SIMPLE_FORMAT_H

#include "CTextureManager.h"
#include "wiskunde.h"

#include <vector>
#include <string>
using namespace std;

typedef struct
{
	float x;
	float y;
} uv;

////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////


////////////////////////////////////////////////
// Vertex
////////////////////////////////////////////////
class Vertex
{
protected:
	Vector m_vPosition;
	Vector m_vNormal;

	static int m_nNextID;
	int m_nID;
public:
	Vertex();
	Vertex(Vector position);
	Vertex(Vector position, Vector normal);
	~Vertex();
	void SetPosition(Vector position);
	void SetNormal(Vector normal);

	Vector GetPosition();
	Vector GetNormal();

	int GetID() {return m_nID;};
};


////////////////////////////////////////////////
// Triangle
////////////////////////////////////////////////
class Triangle
{
protected:
	int m_nVertices[3];
	uv m_UVMap[3];

	static int m_nNextID;
	int m_nID;
public:
	Triangle();
	Triangle(int vertices[3]);
	~Triangle();
	void SetVertices(int vertices[3]);
	void SetUVVertex(int vertex, float x, float y);

	void GetVertices(int vertices[3]);
	int GetVertexIndexAt(int index);
	uv* GetUVMap(int index);

	int GetID() {return m_nID;};
};


////////////////////////////////////////////////
// Mesh
////////////////////////////////////////////////
class Material
{
protected:
	Color m_cAmbient;
	Color m_cDiffuse;
	Color m_cSpecular;
	Color m_cEmissive;

	float m_fShininess;
	float m_fTransparency;

	string m_strTexture;
	int m_nTextureIndex;

	static int m_nNextID;
	int m_nID;
public:
	Material();
	Material(string texture);
	~Material();

	void SetAmbient(float R, float G, float B, float A);
	void SetDiffuse(float R, float G, float B, float A);
	void SetSpecular(float R, float G, float B, float A);
	void SetEmissive(float R, float G, float B, float A);
	void SetShininess(float shininess);
	void SetTransparency(float transparency);
	void SetTexture(string texture);

	float* GetAmbient();
	float* GetDiffuse();
	float* GetSpecular();
	float* GetEmissive();
	float GetShininess();
	string GetTextureName();
	int GetTextureIndex();

	void Use();

	int GetID() {return m_nID;};
};


////////////////////////////////////////////////
// Mesh
////////////////////////////////////////////////
class Mesh
{
protected:
	vector <Vertex*> m_pVertices;
	vector <Triangle*> m_pTriangles;
	int m_nMaterial;
	
	static int m_nNextID;
	int m_nID;
public:
	Mesh();
	~Mesh();
	int AddVertex(Vector position);
	int AddTriangle(Vector vertex1, Vector vertex2, Vector vertex3);
	void SetMaterial(int texture);

	Vertex* GetVertexAt(int index);
	Triangle* GetTriangleAt(int index);
	int GetMaterial();

	int GetNumVertices();
	int GetNumTriangles();

	int GetID() {return m_nID;};
};


////////////////////////////////////////////////
// Model
////////////////////////////////////////////////
class Model
{
protected:
	vector <Mesh*> m_pMeshes;
	vector <Material*> m_pMaterials;
public:
	Model();
	~Model();

	int AddMesh();
	int AddMesh(int texture);
	int AddMaterial();
	int AddMaterial(string texture);

	Mesh* GetMesh(int index);
	Material* GetMaterial(int index);

	int GetNumMesh();
	int GetNumMaterial();
};
#endif