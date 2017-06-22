/*
Заголовочный файл содержит объявление компоненты движка - камеры
*/
#ifndef CAMERA_H
#define CAMERA_H

#include"main.h"

class CCamera
{
public:
     enum CameraType { LANDOBJECT, AIRCRAFT };

     CCamera();
     //CCamera(CameraType cameraType);
     //~CCamera();

     void strafe(float units); // влево/вправо
     void fly(float units);    // вверх/вниз
     void walk(float units);   // вперед/назад

     void pitch(float angle); // вращение относительно правого вектора
     void yaw(float angle);   // вращение относительно верхнего вектора
     void roll(float angle);  // вращение относительно вектора взгляда

     void getViewMatrix(D3DXMATRIX* V);//функция возвращает матрицу вида
     void setCameraType(CameraType cameraType);//функция для установки типа камеры
     void getPosition(D3DXVECTOR3* pos);//функция возвращает позицию камеры
     void setPosition(D3DXVECTOR3* pos);//функция устанавливает позицию камеры
     void getRight(D3DXVECTOR3* right);
     void getUp(D3DXVECTOR3* up);
     void getLook(D3DXVECTOR3* look);
	 void setLook(D3DXVECTOR3* look);

private:
     CameraType  _cameraType;//тип камеры
     D3DXVECTOR3 _right;//вектор в право
     D3DXVECTOR3 _up;//вектор
     D3DXVECTOR3 _look;//вектор вперед
     D3DXVECTOR3 _pos;//точка позиции камеры
};

#endif