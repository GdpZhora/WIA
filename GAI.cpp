#include"main.h"

float CalcAIPos(GBot Bot, DWORD raznica)
{
	D3DXVECTOR3 pos,postemp;
	GBot Bott;
	float lon;
	bool povleft=true;
	bool povright=true;
	Bott=Bot;
	Bott.getPosition(&pos);
	Bott.walk(10*(rand()%40+1)/1.0f,0.0f);
	Bott.getPosition(&postemp);
	if(getValueGMatrix(postemp.x, postemp.z)==5)
			return 0.0;
	if(getValueGMatrix(postemp.x, postemp.z)!=0)
			return 0.0;
	lon=30.0f;
	while((povleft)&&(povright))
	{
	Bott=Bot;
	Bott.yaw(D3DX_PI/2.0f);
	Bott.walk(lon,0.0f);
	Bott.getPosition(&postemp);
	povleft=(getValueGMatrix(postemp.x, postemp.z)!=0);
	Bott=Bot;
	Bott.yaw(-D3DX_PI/2.0f);
	Bott.walk(lon,0.0f);
	Bott.getPosition(&postemp);
	povright=(getValueGMatrix(postemp.x, postemp.z)!=0);
	lon+=30.0f;
	};
	if(povleft) return D3DX_PI/2.0f;
	if(povright) return -D3DX_PI/2.0f;
	return 0.0;
};