#include"main.h"

CWorld::CWorld()
{
	//очищаем массив текстур,буфер вершин и массив данных мира 
	textures=NULL;
	pVB=NULL;
	mas=NULL;
	_worldtype=SPHERE;
	pMesh= new D3DXMESHCONTAINER_EX;
}

BOOL CWorld::Load(char* filename,LPDIRECT3DDEVICE9 *ppDev)
{
	LPVW Lan;
	ppDevice = ppDev;
	if(_worldtype==CUBE)
	{
	//открываем файл
	ifstream infile;
	infile.open(filename);
	infile>>kt;//читаем количество текстур
	textures = new LPDIRECT3DTEXTURE9[kt];//выделяем размер дин. массива текстур
	mas = new Dop[kt];//выделяем размер массива данных текстур
	infile>>kv;//читаем кол-во вершин
	int nt=0;
	int nv=0;
	int kvt;
	float tmp;
	char nametex[40];
	//создаем и заполняем буфер вершин
	if (FAILED((*ppDevice)->CreateVertexBuffer(kv*sizeof(WVERTEXWORLD),0,D3DFVF_XYZ|D3DFVF_TEX1,D3DPOOL_DEFAULT,&pVB,NULL)))
		return (false);
	if (FAILED(pVB->Lock(0,sizeof(WVERTEXWORLD),(void**)&Lan,0)))
		return (false);
	//пробегаем по каждой текстуре
	for (int i=0;i<kt;i++)
	{
		infile>>nametex;//получаем имя тексуры
		//создаем текстуру и проверяем на корректность создания
		D3DXCreateTextureFromFile(*ppDevice,nametex, &textures[i]);
		if (textures[i]==NULL) {
		return false;
		exit(0);
		}
		infile>>kvt;//кол-во вершин для этой текстуры
		mas[i].NumberTexture=i;//номер текстуры
		mas[i].NumberStartVertex=nv;//получаем стартовую вершину
		mas[i].CountPoligon=kvt/3;//получаем кол-во полигонов
		//записываем вершины в буфер
		for (int j=1;j<=kvt;j++)
		{
			infile>>tmp;
			Lan->x = tmp*50;
			infile>>tmp;
			Lan->y = tmp*50;
			infile>>tmp;
			Lan->z = tmp*50;
			infile>>tmp;
			Lan->tu = tmp;
			infile>>tmp;
			Lan->tv = tmp;
			Lan++;
		}
		nv+=kvt;
	}
	pVB->Unlock();//закрывает буфер
	infile.close();
	}
	else
	{
		char* PathTex="data\\world\\sphere\\";
		filename="data\\world\\sphere\\ds.x";
		HRESULT hr;
		hr=LoadMesh(&pMesh,
			*ppDevice,
			filename,
			PathTex);
	
     if(FAILED(hr))
     {
          return false;
     }

	}
	return (true);
};



BOOL CWorld::Render()
{
	if(_worldtype==CUBE)
	{
	(*ppDevice)->SetStreamSource(0,pVB,0,sizeof(WVERTEXWORLD));//устанавливаем источник вершин
	(*ppDevice)->SetFVF(D3DFVF_XYZ|D3DFVF_TEX1);//устан. формат вершин
	//по каждой тектуре пробегаем и выводим полигоны для каждой тектуры
//	(*ppDevice)->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_ANISOTROPIC);
	for (int i=0;i<kt;i++)
	{
		(*ppDevice)->SetTexture(0,textures[mas[i].NumberTexture]);
		(*ppDevice)->DrawPrimitive(D3DPT_TRIANGLELIST,mas[i].NumberStartVertex,mas[i].CountPoligon);
	}
	}
	else
	{
	HRESULT hr;

	hr=DrawMesh(pMesh);

     if(FAILED(hr))
     {
          return false;
	};
	};
return true;
}
VOID CWorld::Delete()
{
 pMesh = NULL;
}