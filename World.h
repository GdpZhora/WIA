/*
Заголовочный файл содержит объявление компоненты движка - мира
*/
#ifndef WORLD_H
#define WORLD_H

#include"main.h"


//структура врешины
typedef struct WVERTEXWORLD
{
	FLOAT x,y,z;//координаты в пространстве
	FLOAT tu,tv;//координаты текстуры
} *LPVW;

//структура для удобства мира
typedef struct Dop
{
	int NumberTexture;//номер текстуры
	int NumberStartVertex;//номер начальной вершины из буфера вершин
	int CountPoligon;//количество полигонов с текущей текстурой
} *LPDop;

class CWorld
{
public:	
	enum WorldType {CUBE, SPHERE};

	CWorld();
	VOID Delete();//функция удаления мира
//	~CWorld();
	BOOL Load(char* filename,LPDIRECT3DDEVICE9 *ppDev);//функция загрузки информации о мире
	BOOL Render(void);//процедура рендеринга мира
	D3DXMATRIX matView;//Матрица

private:
	 WorldType _worldtype;
		LPDIRECT3DTEXTURE9 *textures;//массив текстур
//	IDirect3DCubeTexture9 *CubeText;
	INT kt;//количество текстур
	LPDIRECT3DVERTEXBUFFER9 pVB;//буфер вершин
	INT kv;//количество вершин
	Dop *mas;//массив хранения данных о мире
	IDirect3DDevice9 **ppDevice;//ссылка на созданное устройство Direct3D в ядре
	D3DXMESHCONTAINER_EX *pMesh; //меш для сферного мира
	DWORD numMtrls; //количество материалов для сферного мира
	LPD3DXBUFFER adjBuffer;//
    LPD3DXBUFFER mtrlBuffer;//инфа о материалах мира
    
};


#endif