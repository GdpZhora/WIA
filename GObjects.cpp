#include"main.h"

BOOL flag;

GObj::GObj()
{
	pMesh= new D3DXMESHCONTAINER_EX;
//	pMeshToDraw=NULL;

};

GObj::~GObj()
{

};

BOOL GObj::Load(char *path, char *PathTex, LPDIRECT3DDEVICE9 *ppDev)
{
	Pos.x=0.0f;
	Pos.y=0.0f;
	Pos.z=0.0f;
/*	D3DXMatrixIdentity(&matView);
	D3DXMATRIX MatrixTemp;
	D3DXMatrixRotationY(&MatrixTemp,3.14);
	matView*=MatrixTemp;
	D3DXMatrixRotationX(&MatrixTemp,-3.14/2);
	matView*=MatrixTemp;
	D3DXMatrixScaling(&MatrixTemp,2,2,2);
	matView*=MatrixTemp;
	D3DXMatrixTranslation(&MatrixTemp,Pos.x,Pos.y,Pos.z);
	matView*=MatrixTemp;*/

/*	ofstream OutFile;
	OutFile.open("Matrix.log");
	OutFile<<matView._11<<" ";
	OutFile<<matView._12<<" ";
	OutFile<<matView._13<<" ";
	OutFile<<matView._14<<endl;
	OutFile<<matView._21<<" ";
	OutFile<<matView._22<<" ";
	OutFile<<matView._23<<" ";
	OutFile<<matView._24<<endl;
	OutFile<<matView._31<<" ";
	OutFile<<matView._32<<" ";
	OutFile<<matView._33<<" ";
	OutFile<<matView._34<<endl;
	OutFile<<matView._41<<" ";
	OutFile<<matView._42<<" ";
	OutFile<<matView._43<<" ";
	OutFile<<matView._44<<endl;
	OutFile.close();*/

		_ppDev=ppDev;
		HRESULT hr;
		hr=LoadMesh(&pMesh,
			*_ppDev,
			path,
			PathTex);
	flag=true;

     if(FAILED(hr))
     {
          return false;
     }

	
	return true;
};

BOOL GObj::Draw()
{

	HRESULT hr;
//	*_ppDev->SetTransform(D3DTS_WORLD, &matView);
		hr=DrawMesh(pMesh);

     if(FAILED(hr))
     {
          return false;
	};
return true;
};

BOOL GObj::Go(float unit)
{
	D3DXMATRIX MatrixTemp;
	D3DXMatrixIdentity(&matView);
	UgolAnim+=unit/100.0f;
	D3DXMatrixRotationY(&MatrixTemp,UgolAnim);
	matView*=MatrixTemp;
	Pos.x=Pos.x+unit;
	return true;
};

BOOL GObj::ReBuild(int ttime)
{
	D3DXMatrixIdentity(&matView);
	D3DXMATRIX MatrixTemp;
	D3DXMatrixRotationX(&MatrixTemp,-3.140f/2);
	matView*=MatrixTemp;
	D3DXMatrixScaling(&MatrixTemp,2,2,2);
	matView*=MatrixTemp;
	D3DXMatrixTranslation(&MatrixTemp,Pos.x,Pos.y,Pos.z);
	matView*=MatrixTemp;

	return true;
};

void GObj::Delete()
{
	pMesh=NULL;	
};