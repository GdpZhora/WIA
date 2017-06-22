#include"main.h"

short GameMatrix[256][256];

BOOL LoadGameMatrix()
{
/*	for(int i=0;i<255;i++)
	{
		for(int j=0;j<255;j++)
		{
			GameMatrix[i][j]=0;
		};
	};
	
	for(int i=0;i<255;i++)
	{
		for(int j=50;j<150;j++)
		{
			GameMatrix[i][j]=1;
		};
	};*/
	char* fileName="data\\Terrain\\plan_1.wia";
	std::vector<byte> in5(256*256);
	ofstream OutFile;
	OutFile.open("Debug.log",ios::app);
	OutFile<<endl<<"---Чтение с файла... ";
	OutFile.close();

     ifstream inFile(fileName, ios::binary);

     if(inFile == 0)
          return false;

     inFile.read(
          (char*)&in5[0], // буффер
          in5.size());    // количество читаемых в буфер байт

     inFile.close();
	OutFile.open("Debug.log",ios::app);
	OutFile<<"Завершено"<<endl<<"---Заполнение матрицы... ";
	OutFile.close();

     // копируем вектор BYTE в вектор int
//	OutFile.open("Matrix.log");
//	 int j;
     for(int i=0;i<256;i++)
		 for(int j=0;j<256;j++)
		 {
           GameMatrix[i][j] = in5[i*256+j]-48;
//			OutFile<<GameMatrix[i][j];
		 };

//	 OutFile.close();
	OutFile.open("Debug.log",ios::app);
	OutFile<<"Завершено"<<endl;
	OutFile.close();

return true;
};

int getValueGMatrix(float x, float z)
{
	x/=60;
	z/=60;
	int xi=(int)(((float)256 / 2.0f) + x);
	int zj=(int)(((float)256 / 2.0f) - z);
	return GameMatrix[xi][zj];
};

int getValueGMatrixSK(float x, float z,int* i,int* j)
{
	x/=60;
	z/=60;
	int xi=(int)(((float)256 / 2.0f) + x);
	int zj=(int)(((float)256 / 2.0f) - z);
	*i=xi;
	*j=zj;
	return GameMatrix[xi][zj];
};

int getValueGMatrixZ(int i, int j)
{
	return GameMatrix[i][j];
};

D3DXVECTOR3 StartGame()
{
D3DXVECTOR3	pos;
pos.x=0.0;
pos.y=0.0;
pos.z=0.0;
for(int i=0;i<256;i++)
for(int j=0;j<256;j++)
if(GameMatrix[i][j]==6)
{
	pos.x=(i-(256.0f/2))*60;
	pos.z=((256.0f/2)-j)*60;
	return pos;
};
return pos;
};

float StartUgol()
{
	float run=0.0;
for(int i=0;i<256;i++)
for(int j=0;j<256;j++)
if(GameMatrix[i][j]==6)
{
	if(GameMatrix[i][j-1]==1)
		run=-D3DX_PI/2;
	if(GameMatrix[i][j-1]==1)
		run=D3DX_PI/2;
	if(GameMatrix[i-1][j]==1)
		run=0;
	if(GameMatrix[i+1][j]==1)
		run=D3DX_PI;
};
return run;
};

D3DXVECTOR3 PosGame(int i, int j)
{
D3DXVECTOR3	pos;
//pos.x=0.0;
//pos.y=0.0;
//pos.z=0.0;
pos.x=(i-(256.0f/2))*60;
pos.z=((256.0f/2)-j)*60;
	return pos;
};

void setValueGMatrix(int x, int y, int value)
{
	GameMatrix[x][y]=value;
};