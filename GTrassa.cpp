#include"main.h"

GTrassaClass::GTrassaClass()
{
	point=NULL;
};

bool GTrassaClass::LoadTrassa(char *filename,LPDIRECT3DDEVICE9 *ppDev)
{
	ifstream infile;
	infile.open(filename);
	if(!infile) return false;
	infile>>CountPoint;
	point = new D3DXVECTOR3[CountPoint];
	for(int i=0;i<CountPoint;i++)
	{
		infile>>point[i].x;
		infile>>point[i].y;
		infile>>point[i].z;
	};
	infile.close();
		HRESULT hr;
		_ppDev=ppDev;
		hr=LoadMesh(&pStart,*ppDev,"data\\Objects\\Roads\\start.x","data\\Objects\\Roads\\");
	D3DXMatrixIdentity(&matView);
	D3DXMATRIX MatrixTemp;
	D3DXMatrixRotationX(&MatrixTemp,-D3DX_PI/2.0f);
	matView*=MatrixTemp;
	D3DXMatrixRotationY(&MatrixTemp,-D3DX_PI/2.0f);
	matView*=MatrixTemp;
	D3DXMatrixScaling(&MatrixTemp,20,20,20);
	matView*=MatrixTemp;

     if(FAILED(hr))
     {
          return false;
     }

	return true;
};

bool GTrassaClass::Render()
{
		HRESULT hr;
		(*_ppDev)->SetTransform(D3DTS_WORLD, &matView);
		hr=DrawMesh(pStart);

     if(FAILED(hr))
     {
          return false;
	};

 return true;

};


bool GTrassaClass::CalcValueMatrix()
{
     for(int i=0;i<256;i++)
		 for(int j=0;j<256;j++)
		 {
           setValueGMatrix(i,j,1);
		 };


/*	for(int i=0;i<CountPoint-1;i++)
	{
		int xn;
		int xk;
		int yn;
		int yk;
		if(point[i].x>point[i+1].x) 
		{
			xn=(int)point[i+1].x-8;
			xk=(int)point[i].x+8;
		}
		else {
			xn=(int)point[i].x-8;
			xk=(int)point[i+1].x+8;
		};
		if(point[i].y>point[i+1].y) 
		{
			yn=(int)point[i+1].y-8;
			yk=(int)point[i].y+8;
		}
		else {
			yn=(int)point[i].y-8;
			yk=(int)point[i+1].y+8;
		};

		for(int k=xn;k<xk+1;k++)
			for(int l=yn;l<yk+1;l++)
			{
				if(rand()%50) setValueGMatrix(l,k,1);
				else if(rand()%2) setValueGMatrix(l,k,8);
				else	setValueGMatrix(l,k,9);

			};
	};
	setValueGMatrix((int)point[0].y,(int)point[0].x,6);
	
	int xn=(int)point[CountPoint-1].x-8;
	int xk=(int)point[CountPoint-1].x+8;
	int yn=(int)point[CountPoint-1].y-8;
	int yk=(int)point[CountPoint-1].y+8;

	
	for(int i=xn;i<=xk;i++)
		for(int j=yn;j<=yk;j++)
		{
			setValueGMatrix(j,i,5);
		};

*/

	return true;
};