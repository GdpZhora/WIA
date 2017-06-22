/*
Заголовочный файл содержит объявление компоненты движка - ландшафта
*/
#ifndef TERRAIN_H
#define TERRAIN_H

#include"main.h"

typedef struct TerrainVertex //структура вершин ландшафта
{
	TerrainVertex(){}
     TerrainVertex(float x, float y, float z, float u, float v)
     {
          _x = x; _y = y; _z = z; _u = u; _v = v;
     }

     float _x, _y, _z;
     float _u, _v;
} *LPTerrainVertex;

const DWORD FVFTV=D3DFVF_XYZ|D3DFVF_TEX1;

class CTerrain
{
public:
     bool Create(
          IDirect3DDevice9* device,
          char* heightmapFileName,
          int numVertsPerRow,
          int numVertsPerCol,
          int cellSpacing,    // расстояние между вершинами
          float heightScale); // коэффициент масштабирования высоты
	 

	 bool readRawFile(char* fileName);//загрузка из файла
	 bool computeVertices();//загрузка буфера вершин
	 bool computeIndices();//загрузка буфера индексов
	 bool loadTexture(std::string fileName,std::string fileName2);//загрузка текстуры из файла
	 bool genTexture(D3DXVECTOR3* directionToLight);//генерация текстуры
	 int getHeightmapEntry(int row, int col);
	 void setHeightmapEntry(int row, int col, int value);
	 float computeShade(int cellRow, int cellCol,
							D3DXVECTOR3* directionToLight);
	 bool lightTerrain(D3DXVECTOR3* lightDirection);
	 float getHeight(float x, float z);//высота
	 void draw();
	 void Delete();



//     ... методы пропущены

private:

//     ...устройство, буфер вершин и т.п. пропущены
	 IDirect3DDevice9* _device;
	 IDirect3DVertexBuffer9* _vb;
	 IDirect3DIndexBuffer9* _ib;
	 std::vector<int> _heightmap;
     int _numVertsPerRow;
     int _numVertsPerCol;
     int _cellSpacing;
     int _numCellsPerRow;
     int _numCellsPerCol;
     int _width;
     int _depth;
     int _numVertices;
     int _numTriangles;
     float _heightScale;
	 char* _heightmapFileName;
	 LPDIRECT3DTEXTURE9 _tex[5];
	/*LPDIRECT3DTEXTURE9 _tex2;
	LPDIRECT3DTEXTURE9 _tex3;
	LPDIRECT3DTEXTURE9 _tex4;
	LPDIRECT3DTEXTURE9 _tex5;*/

};



#endif