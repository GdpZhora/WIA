#ifndef GOBJECTS_H
#define GOBJECTS_H

#include "main.h"

class GObj
{
public:
	GObj();
	~GObj();
	BOOL Draw(void);//функция для вывода объекта
	BOOL Load(char *path, char *PathTex,LPDIRECT3DDEVICE9 *ppDev);//функция загрузки объекта
	BOOL ReBuild(int ttime);//функция перестройки объекта
	BOOL Go(float unit);
	D3DXMATRIX matView;
	void Delete();
private:
	LPDIRECT3DDEVICE9 *_ppDev;
	D3DXMESHCONTAINER_EX *pMesh;//меш обекта
//	ID3DXMesh *pMeshToDraw; //меш объекта для визуализации
	D3DXVECTOR3 Pos;//позиция
	float UgolAnim;
	int Anime;//вид текущей анимации
	int TimeAnime;//время анимации
	int RepeatNeed;//количество необходимых повторов
	int RepeatFact;//сколько повторов сделано
	float Ugol;//угол поворота

};

#endif