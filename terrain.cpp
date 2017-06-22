#include"main.h"
//#include"terrain.h"
//конструктор

    D3DSURFACE_DESC textureDesc;
    D3DLOCKED_RECT lockedRect;



bool CTerrain::readRawFile(char* fileName)
{
     // Высота для каждой вершины
	if (access(fileName, 0) == -1)
		return false;
	std::vector<byte> in(_numVertices);

     ifstream inFile(fileName, ios::binary);

     if(inFile == 0)
          return false;

     inFile.read(
          (char*)&in[0], // буффер
          in.size());    // количество читаемых в буфер байт

     inFile.close();

     // копируем вектор BYTE в вектор int
     _heightmap.resize(_numVertices);
     for(int i = 0; i < in.size(); i++)
          _heightmap[i] = in[i]*(int)_heightScale;

     return true;
}

bool CTerrain::Create(IDirect3DDevice9* device,
          char* heightmapFileName,
          int numVertsPerRow,
          int numVertsPerCol,
          int cellSpacing,    // расстояние между вершинами
          float heightScale)
{
		if (access(heightmapFileName, 0) == -1)
		return false;
	_device=device;
	_heightmapFileName=heightmapFileName;
	_numVertsPerRow=numVertsPerRow;
	_numVertsPerCol=numVertsPerCol;
	_cellSpacing=cellSpacing;
	_heightScale=heightScale;
	_numCellsPerRow = _numVertsPerRow - 1;
	_numCellsPerCol = _numVertsPerCol - 1;
	_width = _numCellsPerRow * _cellSpacing;
	_depth = _numCellsPerCol * _cellSpacing;
	_numVertices = _numVertsPerRow * _numVertsPerCol;
	_numTriangles = _numCellsPerRow * _numCellsPerCol * 2;
	return TRUE;
};

bool CTerrain::computeVertices()
{
     HRESULT hr = 0;

	 double tempv,tempu;
     hr = _device->CreateVertexBuffer(
                      _numVertices * sizeof(TerrainVertex),
                      D3DUSAGE_WRITEONLY,
                      FVFTV,
                      D3DPOOL_MANAGED,
                      &_vb,
                      0);

     if(FAILED(hr))
          return false;

     // координаты, с которых начинается генерация вершин
     int startX = -_width / 2;
     int startZ =  _depth / 2;

     // координаты, на которых завершается генерация вершин
     int endX =  _width / 2;
     int endZ = -_depth / 2;

     // вычисляем приращение координат текстуры
     // при переходе от одной вершины к другой.
     float uCoordIncrementSize = 1.0f / (float)_numCellsPerRow;
     float vCoordIncrementSize = 1.0f / (float)_numCellsPerCol;
//	float hm;
     TerrainVertex* v = 0;
     _vb->Lock(0, 0, (void**)&v, 0);

     int i = 0;
     for(int z = startZ; z >= endZ; z -= _cellSpacing)
     {
          int j = 0;
          for(int x = startX; x <= endX; x += _cellSpacing)
          {
               // вычисляем правильный индекс в буфере вершин
               // и карте высот на основании счетчиков вложенных циклов
               int index = i * _numVertsPerRow + j;
				
			   if((j%16)>8) tempv=(8-(j%8))/8.0; else tempv=(j%16)/8.0;
				if((i%16)>8) tempu=(8-(i%8))/8.0; else tempu=(i%16)/8.0;
			   //tempv=j%8;
			   //tempu=i%8;
				if((getValueGMatrix((float)x, (float)z)==1)||(getValueGMatrix((float)x, (float)z)==6)||(getValueGMatrix((float)x, (float)z)==5))
					_heightmap[index]=0;
				if(getValueGMatrix((float)x, (float)z)==8)
					_heightmap[index]=20;
				if(getValueGMatrix((float)x, (float)z)==9)
					_heightmap[index]=-20;

               v[index] = TerrainVertex(
                                   (float)x,
                                   (float)_heightmap[index],
                                   (float)z,
//                                   j%2,
//                                   i%2);
	                                  (float)tempv,
	                                  (float)tempu);

               j++; // следующий столбец
          }
          i++; // следующая строка
     }

     _vb->Unlock();

     return true;
};

bool CTerrain::computeIndices()
{
     HRESULT hr = 0;

     hr = _device->CreateIndexBuffer(
                  _numTriangles * 3 * sizeof(WORD), // 3 индекса на треугольник
                  D3DUSAGE_WRITEONLY,
                  D3DFMT_INDEX16,
                  D3DPOOL_MANAGED,
                  &_ib,
                  0);

     if(FAILED(hr))
          return false;

     WORD* indices = 0;
     _ib->Lock(0, 0, (void**)&indices, 0);

     // Индекс, с которого начинается группа из 6 индексов,
     // описывающая два треугольника, образующих квадрат
     int baseIndex = 0;

     // В цикле вычисляем треугольники для каждого квадрата
     for(int i = 0; i < _numCellsPerCol; i++)
     {
          for(int j = 0; j < _numCellsPerRow; j++)
          {
			   //indices[baseIndex]     = i * _numVertsPerRow + j;
               //indices[baseIndex + 1] = i * _numVertsPerRow + j + 1;
               //indices[baseIndex + 2] = (i+1) * _numVertsPerRow + j;
               //indices[baseIndex + 3] = (i+1) * _numVertsPerRow + j;
               //indices[baseIndex + 4] = i * _numVertsPerRow + j + 1;
               //indices[baseIndex + 5] = (i+1) * _numVertsPerRow + j + 1;
               indices[baseIndex]     = i * _numVertsPerRow + j;
               indices[baseIndex + 1] = (i+1) * _numVertsPerRow + j;
               indices[baseIndex + 2] = i * _numVertsPerRow + j + 1;
               indices[baseIndex + 3] = i * _numVertsPerRow + j + 1;
               indices[baseIndex + 4] = (i+1) * _numVertsPerRow + j;
               indices[baseIndex + 5] = (i+1) * _numVertsPerRow + j + 1;


               // следующий квадрат
               baseIndex += 6;
          }
     }

     _ib->Unlock();


     return true;
};

bool CTerrain::loadTexture(std::string fileName,std::string fileName2)
{
     HRESULT hr = 0;

      hr = D3DXCreateTextureFromFile(
                      _device,
                      "data\\Terrain\\Textures\\finish.jpg",
                      &_tex[3]);
     if(FAILED(hr))
          return false;

     hr = D3DXCreateTextureFromFile(
                      _device,
                      "data\\Terrain\\Textures\\wood1.jpg",
                      &_tex[2]);
     if(FAILED(hr))
          return false;

     hr = D3DXCreateTextureFromFile(
                      _device,
                      fileName.c_str(),
                      &_tex[0]);

     if(FAILED(hr))
          return false;

     hr = D3DXCreateTextureFromFile(
                      _device,
                      fileName2.c_str(),
                      &_tex[1]);

     if(FAILED(hr))
          return false;

	 hr = D3DXCreateTextureFromFile(
                      _device,
                      "data\\Terrain\\Textures\\water1.jpg",
                      &_tex[4]);

     if(FAILED(hr))
          return false;


     return true;
};

bool CTerrain::genTexture(D3DXVECTOR3* directionToLight)
{
     // Метод программно заполняет текстуру верхнего уровня.
     // Затем выполняется ее освещение. И, в конце, заполняются 
     // остальные уровни детализируемой текстуры с помощью
     // D3DXFilterTexture.

     HRESULT hr = 0;

     // Тексель для каждого квадрата сетки
     int texWidth  = _numCellsPerRow;
     int texHeight = _numCellsPerCol;

     // Создаем пустую текстуру
     hr = D3DXCreateTexture(
            _device,
            texWidth, texHeight, // размеры
            0,                   // создаем полную
                                 // цепочку детализации
            0,                   // использование - нет
            D3DFMT_X8R8G8B8,     // формат 32-разрядный XRGB
            D3DPOOL_MANAGED,     // пул памяти
            &_tex[0]);

     if(FAILED(hr))
          return false;

     _tex[0]->GetLevelDesc(0 /* уровень */, &textureDesc);

     // Проверяем, что получена текстура требуемого формата,
     // поскольку наш код заполнения текстуры работает только
     // с 32-разрядными пикселями
     if(textureDesc.Format != D3DFMT_X8R8G8B8)
          return false;

     _tex[0]->LockRect(0,           // блокируем верхнюю поверхность
                    &lockedRect,
                    0,           // блокируем всю текстуру
                    0);          // флаги

     // Заполняем текстуру
     DWORD* imageData = (DWORD*)lockedRect.pBits;
     for(int i = 0; i < texHeight; i++)
     {
          for(int j = 0; j < texWidth; j++)
          {
               D3DXCOLOR c;
               // Получаем высоту верхней левой вершины квадрата
               float height = (float)getHeightmapEntry(i, j)/_heightScale;

               // Устанавливаем цвет текселя на основе высоты
               // соответствующего ему квадрата
               if( (height) < 42.5f )       c = D3DCOLOR_XRGB(0, 1, 0);
               else if( (height) < 85.0f )  c = D3DCOLOR_XRGB(72, 255, 118);
               else if( (height) < 127.5f ) c = D3DCOLOR_XRGB(118, 255, 118);
               else if( (height) < 170.0f ) c = D3DCOLOR_XRGB(164, 255, 164);
               else if( (height) < 212.5f ) c = D3DCOLOR_XRGB(210, 255, 210);
               else                         c = D3DCOLOR_XRGB(255, 255, 255);

               // Заполняем заблокированный буфер. Обратите внимание, что мы
               // делим шаг на четыре, поскольку шаг измеряется в байтах
               // а одно значение DWORD занимает 4 байта
               imageData[i * lockedRect.Pitch / 4 + j] = (D3DCOLOR)c;
          }
     }
     _tex[0]->UnlockRect(0);

     // Освещаем ландшафт
     if(!(lightTerrain(directionToLight)))
     {
          return false;
     }

     // Заподняем цепочку детализации
     hr = D3DXFilterTexture(
             _tex[0],   // текстура, для которой заполняются уровни детализации
             0,      // палитра по умолчанию
             0,      // используем в качестве источника верхний уровень
             D3DX_DEFAULT); // фильтр по умолчанию

     if(FAILED(hr))
     {
          return false;
     }
     return true;
};

int CTerrain::getHeightmapEntry(int row, int col)
{
     return _heightmap[row * _numVertsPerRow + col];
};

void CTerrain::setHeightmapEntry(int row, int col, int value)
{
     _heightmap[row * _numVertsPerRow + col] = value;
};

float CTerrain::computeShade(int cellRow, int cellCol,
							D3DXVECTOR3* directionToLight)
{
     // Получаем высоты трех вершин квадрата
     int heightA = getHeightmapEntry(cellRow,   cellCol);
     int heightB = getHeightmapEntry(cellRow,   cellCol+1);
     int heightC = getHeightmapEntry(cellRow+1, cellCol);

     // Строим два вектора квадрата
     D3DXVECTOR3 u(_cellSpacing/1.0f, (heightB - heightA)/1.0f, 0.0f);
     D3DXVECTOR3 v(0.0f, (heightC - heightA)/1.0f, -_cellSpacing/1.0f);

     // Находим нормаль, выполнив векторное умножение
     // двух векторов квадрата
     D3DXVECTOR3 n;
     D3DXVec3Cross(&n, &u, &v);
     D3DXVec3Normalize(&n, &n);

     float cosine = D3DXVec3Dot(&n, directionToLight);

     if(cosine < 0.0f)
          cosine = 0.0f;

     return cosine;
};

float Lerp(float a, float b, float t)
{
     return a - (a*t) + (b*t);
};



float CTerrain::getHeight(float x, float z)
{
     // Выполняем преобразование перемещения для плоскости XZ,
     // чтобы точка START ландшафта совпала с началом координат.
     x = ((float)_width / 2.0f) + x;
     z = ((float)_depth / 2.0f) - z;

     // Масштабируем сетку таким образом, чтобы размер
     // каждой ее ячейки стал равен 1. Для этого используем
     // коэффициент 1 / cellspacing поскольку
     // cellspacing * 1 / cellspacing = 1.
     x /= (float)_cellSpacing;
     z /= (float)_cellSpacing;
	 float col = ::floorf(x);
	 float row = ::floorf(z);
	 // A   B
	 // *---*
	 // | / |
	 // *---*
	 // C   D
	 float A = (float)getHeightmapEntry((int)row,   (int)col);
	 float B = (float)getHeightmapEntry((int)row,   (int)col+1);
	 float C = (float)getHeightmapEntry((int)row+1, (int)col);
	 float D = (float)getHeightmapEntry((int)row+1, (int)col+1);
	 float dx = x - col;
	 float dz = z - row;
	 float height;
	 if(dz < 1.0f - dx) // верхний треугольник ABC
{
     float uy = B - A; // A->B
     float vy = C - A; // A->C

     height = A + Lerp(0.0f, uy, dx) +
                  Lerp(0.0f, vy, dz);
}
else // нижний треугольник DCB
{
     float uy = C - D; // D->C
     float vy = B - D; // D->B

     height = D + Lerp(0.0f, uy, 1.0f - dx) +
                  Lerp(0.0f, vy, 1.0f - dz);
}
return height;
};


void CTerrain::draw()
{
	_device->SetFVF(FVFTV);
	_device->SetStreamSource(0,_vb,0,sizeof(TerrainVertex));
	_device->SetIndices(_ib);

_device->SetTextureStageState(0, D3DTSS_COLOROP,  D3DTOP_MODULATE);
_device->SetTextureStageState(0, D3DTSS_COLORARG1,D3DTA_TEXTURE);
_device->SetTextureStageState(0, D3DTSS_COLORARG2,D3DTA_DIFFUSE);
_device->SetTextureStageState(0, D3DTSS_ALPHAOP,  D3DTOP_DISABLE);

	for(int i=0;i<_numCellsPerRow;i++)
	{
		int j;
		for(j=0;j<_numCellsPerCol;j++)
		{	

			if((getValueGMatrixZ(j,i)==0)) _device->SetTexture(0,_tex[0]);
		else _device->SetTexture(0,_tex[1]);
		if((getValueGMatrixZ(j,i)==8)||(getValueGMatrixZ(j+1,i)==8)||(getValueGMatrixZ(j,i+1)==8)||(getValueGMatrixZ(j+1,i+1)==8))
				_device->SetTexture(0,_tex[0]);

		if((getValueGMatrixZ(j,i)==9)||(getValueGMatrixZ(j+1,i)==9)||(getValueGMatrixZ(j,i+1)==9)||(getValueGMatrixZ(j+1,i+1)==9))
				_device->SetTexture(0,_tex[4]);

			if((getValueGMatrixZ(j,i)==5)) _device->SetTexture(0,_tex[3]);
			if((getValueGMatrixZ(j,i)==0)&&(getValueGMatrixZ(j+1,i)>0))
				_device->SetTexture(0,_tex[2]);
			if((getValueGMatrixZ(j,i)>0)&&(getValueGMatrixZ(j+1,i)==0))
				_device->SetTexture(0,_tex[2]);
			if((getValueGMatrixZ(j,i)==0)&&(getValueGMatrixZ(j,i+1)>0))
				_device->SetTexture(0,_tex[2]);
			if((getValueGMatrixZ(j,i)>0)&&(getValueGMatrixZ(j,i+1)==0))
				_device->SetTexture(0,_tex[2]);



			_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,(i*_numCellsPerCol+j)*6,2);
		};
	};


};

void CTerrain::Delete()
{
	_tex[0]->Release();
	_ib->Release();
	_vb->Release();
};

bool CTerrain::lightTerrain(D3DXVECTOR3* lightDirection)
{
	DWORD* imageData = (DWORD*)lockedRect.pBits;
for(int i = 0; i < textureDesc.Height; i++)
{
     for(int j = 0; j < textureDesc.Width; j++)
     {
          int index = i * lockedRect.Pitch / 4 + j;

          // Получаем текущий цвет ячейки
          D3DXCOLOR c(imageData[index]);

          // Затеняем текущую ячейку
          c *= computeShade(i, j, lightDirection);;

          // Сохраняем затененный цвет
          imageData[index] = (D3DCOLOR)c;
     }
}
 
return 1;

};