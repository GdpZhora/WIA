/*
������������ ���� �������� ���������� ���������� ������ - ����
*/
#ifndef WORLD_H
#define WORLD_H

#include"main.h"


//��������� �������
typedef struct WVERTEXWORLD
{
	FLOAT x,y,z;//���������� � ������������
	FLOAT tu,tv;//���������� ��������
} *LPVW;

//��������� ��� �������� ����
typedef struct Dop
{
	int NumberTexture;//����� ��������
	int NumberStartVertex;//����� ��������� ������� �� ������ ������
	int CountPoligon;//���������� ��������� � ������� ���������
} *LPDop;

class CWorld
{
public:	
	enum WorldType {CUBE, SPHERE};

	CWorld();
	VOID Delete();//������� �������� ����
//	~CWorld();
	BOOL Load(char* filename,LPDIRECT3DDEVICE9 *ppDev);//������� �������� ���������� � ����
	BOOL Render(void);//��������� ���������� ����
	D3DXMATRIX matView;//�������

private:
	 WorldType _worldtype;
		LPDIRECT3DTEXTURE9 *textures;//������ �������
//	IDirect3DCubeTexture9 *CubeText;
	INT kt;//���������� �������
	LPDIRECT3DVERTEXBUFFER9 pVB;//����� ������
	INT kv;//���������� ������
	Dop *mas;//������ �������� ������ � ����
	IDirect3DDevice9 **ppDevice;//������ �� ��������� ���������� Direct3D � ����
	D3DXMESHCONTAINER_EX *pMesh; //��� ��� �������� ����
	DWORD numMtrls; //���������� ���������� ��� �������� ����
	LPD3DXBUFFER adjBuffer;//
    LPD3DXBUFFER mtrlBuffer;//���� � ���������� ����
    
};


#endif