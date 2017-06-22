#ifndef GPLAYER_H
#define GPLAYER_H

#include "main.h"

typedef struct sKeyframe {
	DWORD Time;
	D3DMATRIX matTransformation;
} sKeyframe;

class GBot
{
public:
	GBot();
	BOOL Draw(LPDIRECT3DDEVICE9 pDev);//функция для вывода объекта
	BOOL Load(char *file,LPDIRECT3DDEVICE9 *ppDev);//функция загрузки объекта
	BOOL ReBuild(int ttime);//функция перестройки объекта
	BOOL Go(float unit);
	void Delete();
	D3DXMATRIX matLeft;
	D3DXMATRIX matRight;
	D3DXVECTOR3 _pos;//позиция
	void getPosition(D3DXVECTOR3* pos);//функция возвращает позицию камеры
     void setPosition(D3DXVECTOR3* pos);//функция устанавливает позицию камеры
     void getRight(D3DXVECTOR3* right);
     void getUp(D3DXVECTOR3* up);
     void getLook(D3DXVECTOR3* look);
     void setLook(D3DXVECTOR3* look);
     void setRight(D3DXVECTOR3* right);

     void strafe(float units); // влево/вправо
     void walk(float units,float time);   // вперед/назад

     void pitch(float angle); // вращение относительно правого вектора
     void yaw(float angle);   // вращение относительно верхнего вектора
	 void Reset(DWORD Time);
	 GObj *pModel;
	bool beg;
	int MaxSpeed;
	int Uscor;
	int Upravl;
	float Speed;
	byte _typeBot;
	bool FactRemont;
	DWORD TimeRemont;
	DWORD TimeFinish;//время финиширования
	bool Finish;//на финише?
	char* NamePlayer;//Имя Игрока
	byte place;
	byte typeremont;
private:
//	GObj *pRight;
    D3DXVECTOR3 _right;//вектор в право
    D3DXVECTOR3 _look;//вектор вперед
    D3DXVECTOR3 _up;//вектор
//	sKeyframe kfLeft[6];
//	sKeyframe kfRight[6];
	unsigned long BeginAnim;
	bool Anim;
	float Ugol;//угол поворота
	ID3DXFont* pFont;

};


/*sKeyframe kfLeft[6] = { 
		{0,  1.00000f, 0.00000f, 0.00000f, 0.00000f,
   			 0.00000f, 1.00000f, 0.00000f, 0.00000f,
		     0.00000f, 0.00000f, 1.00000f, 0.00000f,
			 0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{200, 0.510563f, 0.0869504f, -0.855433f, 76.0512f,
		   0.00523346f, 0.994541f, 0.104214f, -9.265000f,
		   0.859824f, -0.0576845f, 0.507321f, 84.4272f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{400, -0.477733f, 0.263651f, -0.838009f, 74.50210f,
		   -0.00783551f, 0.952587f, 0.304166f, -27.04150f,
		   0.87847f, 0.151876f, -0.453017f, 164.10470f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{600, -0.999048f, -0.00000f, -0.0436191f, 3.87790f,
		   -0.0184344f, 0.906308f, 0.422216f, -37.53650f,
		   0.0395323f, 0.422619f, -0.905445f, 170.30470f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{800, -0.546394f, -0.281721f, 0.788725f, -70.12070f,
		   -0.00896155f, 0.943642f, 0.330847f, -29.41350f,
		   -0.83748f, 0.173704f, -0.518125f, 168.85970f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
   		{1000, 0.437777f, -0.111753f, 0.892111f, -79.31190f,
		   0.00448743f, 0.992504f, 0.122126f, -10.85760f,
		   -0.899072f, -0.0494609f, 0.434997f, 89.81370f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f}
	};*/

#endif