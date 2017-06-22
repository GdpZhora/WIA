#ifndef GTRASSA_H
#define GTRASSA_H

class GTrassaClass
{
public:
	GTrassaClass();
	bool LoadTrassa(char* filename,LPDIRECT3DDEVICE9 *ppDev);
	bool Render();
	bool CalcValueMatrix();

private:
	LPDIRECT3DDEVICE9 *_ppDev;
	D3DXMATRIX matView;
	D3DXMESHCONTAINER_EX *pStart;//0
	D3DXMESHCONTAINER_EX *pMount;//1
	D3DXMESHCONTAINER_EX *pStraight;//2
	D3DXMESHCONTAINER_EX *pLeft;//3
	D3DXMESHCONTAINER_EX *pRight;//4
	short ElTrasMatrix[151][151];
	short PovElTrasMatrix[151][151];
	int CountPoint;
	D3DXVECTOR3* point;
};

#endif