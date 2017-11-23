#include "CScene.h"

CScene* CScene::m_pInstance = NULL;

///////////////////////////////////////////////////////////////////////////////////////////
// Constructor en Deconstructor
///////////////////////////////////////////////////////////////////////////////////////////
CScene::CScene()
{
	m_pModel = new Model();

	int material = m_pModel->AddMaterial(/*"H:\\Wood.bmp"*/);
	Material* mat = m_pModel->GetMaterial(material);
	mat->SetAmbient(1.0f, 1.0f, 1.0f, 1.0f);
	mat->SetDiffuse(0.0f, 0.0f, 0.0f, 1.0f);
//	mat->SetSpecular(0.0f, 0.0f, 1.0f, 1.0f);
	mat->SetShininess(5.0f);


	m_pModel->AddMesh(material);
	Mesh* mesh = m_pModel->GetMesh(0);
	int tri = mesh->AddTriangle(Vector(0.0f, 1.0f, 0.0f), Vector(1.0f, 1.0f, 0.0f), Vector(1.0f, 0.0f, 0.0f));

	Triangle* pTriangle = mesh->GetTriangleAt(tri);
	pTriangle->SetUVVertex(0, 0.0f, 0.0f);
	pTriangle->SetUVVertex(1, 0.0f, 1.0f);
	pTriangle->SetUVVertex(2, 1.0f, 1.0f);
}

CScene::~CScene()
{
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
CScene* CScene::GetInstance()
{
	if ( m_pInstance == NULL )
		m_pInstance = new CScene();

	return m_pInstance;
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CScene::ClearInstance()
{
	if ( m_pInstance )
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CScene::Draw()
{
	if (m_pModel)
	{
		for (int i = 0; i < m_pModel->GetNumMesh(); i++)
		{
			Mesh* pMesh = m_pModel->GetMesh(i);

			Material* pMaterial = m_pModel->GetMaterial(pMesh->GetMaterial());
			if (pMaterial)
			{
				pMaterial->Use();
			}

			for (int j = 0; j < pMesh->GetNumTriangles(); j++)
			{
				Triangle* pTriangle = pMesh->GetTriangleAt(j);

				Vector normal;
				normal.Fill(1.0f, 1.0f, 1.0f);
				glNormal3f(normal.X, normal.Y, normal.Z);

				int vertices[3];
				pTriangle->GetVertices(vertices);
				uv uvmaps[3];
				uvmaps[0] = *pTriangle->GetUVMap(0);
				uvmaps[1] = *pTriangle->GetUVMap(1);
				uvmaps[2] = *pTriangle->GetUVMap(2);

				glBegin(GL_TRIANGLES);
				for (int k = 0; k < 3; k++)
				{
					Vertex* pVertex = pMesh->GetVertexAt(vertices[k]);
					if (pVertex)
					{
						Vector v = pVertex->GetPosition();
						glTexCoord2f(uvmaps[k].x, uvmaps[k].y);
						glVertex3f(v.X, v.Y, v.Z);
					}
				}
				glEnd();
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// Purpose : 
// Input   : 
// Output  : 
///////////////////////////////////////////////////////////////////////////////////////////
void CScene::ReloadTextures()
{
	for (int i = 0; i < m_pModel->GetNumMaterial(); i++)
	{
		if (m_pModel->GetMaterial(i)->GetTextureName() != "")
			CTextureManager::GetInstance()->AddTexture(m_pModel->GetMaterial(i)->GetTextureName());
	}
}