#include "main.h"

void CCamera::getViewMatrix(D3DXMATRIX* V)
{
     // Делаем оси камеры ортогональными
     D3DXVec3Normalize(&_look, &_look);

     D3DXVec3Cross(&_up, &_look, &_right);
     D3DXVec3Normalize(&_up, &_up);

     D3DXVec3Cross(&_right, &_up, &_look);
     D3DXVec3Normalize(&_right, &_right);

     // Строим матрицу вида:
     float x = -D3DXVec3Dot(&_right, &_pos);
     float y = -D3DXVec3Dot(&_up, &_pos);
     float z = -D3DXVec3Dot(&_look, &_pos);

     (*V)(0, 0) = _right.x;
     (*V)(0, 1) = _up.x;
     (*V)(0, 2) = _look.x;
     (*V)(0, 3) = 0.0f;

     (*V)(1, 0) = _right.y;
     (*V)(1, 1) = _up.y;
     (*V)(1, 2) = _look.y;
     (*V)(1, 3) = 0.0f;

     (*V)(2, 0) = _right.z;
     (*V)(2, 1) = _up.z;
     (*V)(2, 2) = _look.z;
     (*V)(2, 3) = 0.0f;

     (*V)(3, 0) = x;
     (*V)(3, 1) = y;
     (*V)(3, 2) = z;
     (*V)(3, 3) = 1.0f;
//	 D3DXMatrixLookAtLH(V, &_pos, &_look,
//		 &D3DXVECTOR3(0.0f, 1.0f, 0.0f));

}

void CCamera::pitch(float angle)
{
     D3DXMATRIX T;
     D3DXMatrixRotationAxis(&T, &_right, angle);
     // Поворот векторов _up и _look относительно вектора _right
     D3DXVec3TransformCoord(&_up,&_up, &T);
     D3DXVec3TransformCoord(&_look,&_look, &T);
}

void CCamera::yaw(float angle)
{
     D3DXMATRIX T;

     // Для наземных объектов выполняем вращение
     // вокруг мировой оси Y (0, 1, 0)
     if(_cameraType == LANDOBJECT)
          D3DXMatrixRotationY(&T, angle);

     // Для летающих объектов выполняем вращение
     // относительно верхнего вектора
     if(_cameraType == AIRCRAFT)
          D3DXMatrixRotationAxis(&T, &_up, angle);

     // Поворот векторов _right и _look относительно
     // вектора _up или оси Y
     D3DXVec3TransformCoord(&_right, &_right, &T);
     D3DXVec3TransformCoord(&_look, &_look, &T);
}

void CCamera::roll(float angle)
{
     // Вращение только для летающих объектов
     if(_cameraType == AIRCRAFT)
     {
          D3DXMATRIX T;
          D3DXMatrixRotationAxis(&T, &_look, angle);

          // Поворот векторов _up и _right относительно
          // вектора _look
          D3DXVec3TransformCoord(&_right, &_right, &T);
          D3DXVec3TransformCoord(&_up, &_up, &T);
     }
}

void CCamera::walk(float units)
{
     // Для наземных объектов перемещение только в плоскости xz
     if(_cameraType == LANDOBJECT)
          _pos += D3DXVECTOR3(_look.x, 0.0f, _look.z) * units;

     if(_cameraType == AIRCRAFT)
          _pos += _look * units;
}

void CCamera::strafe(float units)
{
     // Для наземных объектов перемещение только в плоскости xz
     if(_cameraType == LANDOBJECT)
          _pos += D3DXVECTOR3(_right.x, 0.0f, _right.z) * units;

     if(_cameraType == AIRCRAFT)
          _pos += _right * units;
}

void CCamera::fly(float units)
{
     if(_cameraType == AIRCRAFT)
          _pos += _up * units;
}

CCamera::CCamera()
{
	_cameraType=LANDOBJECT;
	_right=D3DXVECTOR3(1,0,0);
	_up=D3DXVECTOR3(0,1,0);
	_look=D3DXVECTOR3(0,0,1);
	_pos=D3DXVECTOR3(0,550,0);
	_pos += _up*0.2f;
};

void CCamera::getPosition(D3DXVECTOR3 *pos)
{
	(*pos)=_pos;

};

void CCamera::setPosition(D3DXVECTOR3* pos)//функция устанавливает позицию камеры
{
	_pos=*pos;
};

void CCamera::setLook(D3DXVECTOR3 *look)
{
	_look=*look;
};