#ifndef GOBJECTS_H
#define GOBJECTS_H

#include "main.h"

class GObj
{
public:
	GObj();
	~GObj();
	BOOL Draw(void);//������� ��� ������ �������
	BOOL Load(char *path, char *PathTex,LPDIRECT3DDEVICE9 *ppDev);//������� �������� �������
	BOOL ReBuild(int ttime);//������� ����������� �������
	BOOL Go(float unit);
	D3DXMATRIX matView;
	void Delete();
private:
	LPDIRECT3DDEVICE9 *_ppDev;
	D3DXMESHCONTAINER_EX *pMesh;//��� ������
//	ID3DXMesh *pMeshToDraw; //��� ������� ��� ������������
	D3DXVECTOR3 Pos;//�������
	float UgolAnim;
	int Anime;//��� ������� ��������
	int TimeAnime;//����� ��������
	int RepeatNeed;//���������� ����������� ��������
	int RepeatFact;//������� �������� �������
	float Ugol;//���� ��������

};

#endif