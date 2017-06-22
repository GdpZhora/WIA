#include "main.h"

WVERTEXWORLD Koord(float x, float y, float z, float u, float v)
{
	WVERTEXWORLD temp;
	temp.x=x;
	temp.y=y;
	temp.z=z;
	temp.tu=u;
	temp.tv=v;
	return temp;
};

bool GMenuClass::Reset()
{
	NumPunkt=0;
	POINT Position;
	GetCursorPos(&Position);
	double vx=-(800.0/2.0-Position.x)/(800.0/2.0);
	double vy=(600.0/2.0-Position.y)/(600.0/2.0);
	for(int i=0;i<8;i++)
	{
		if((vx<But1[i*4].x)&&(vx>But1[i*4+3].x)&&(vy>But1[i*4].y)&&(vy<But1[i*4+3].y)) NumPunkt=i+1;
	};
	return true;
};

int GMenuClass::Click()
{
	if(_page==PM_MAIN)
	{
	if(NumPunkt==1) return 0;
	if(NumPunkt==5) 
	{
//		return 1;
		_page=PM_SINGLE;
		NumPunkt=0;
		return 10;
	};
/*	if(NumPunkt==4) 
	{
		_page=PM_MULTI;
		NumPunkt=0;
		return 10;
	};*/
/*	if(NumPunkt==3) 
	{
		_page=PM_OPTIONS;
		NumPunkt=0;
		return 10;
	};*/
	if(NumPunkt==2) 
	{
		_page=PM_CREDIT;
		NumPunkt=0;
		return 10;
	}
	};

	if(_page==PM_SINGLE)
	{

	POINT Position;
	GetCursorPos(&Position);
	float vx=-(800.0f/2.0f-Position.x)/(800.00f/2.0f);
	float vy=(600.0f/2.0f-Position.y)/(600.0f/2.0f);
	for(int i=0;i<4;i++)
	{
		if((vx<Bot1[i*4].x)&&(vx>Bot1[i*4+3].x)&&(vy>Bot1[i*4].y)&&(vy<Bot1[i*4+3].y)) NumBot=i+1;
	};

	if(NumPunkt==6) 
	{
		_page=PM_MAIN;
		NumPunkt=0;
		return 10;
	};

	if(NumPunkt==8) 
	{
		return 1;
		NumPunkt=0;
	};
	};

	if(_page==PM_MULTI)
	{
	if(NumPunkt==6) 
	{
		_page=PM_MAIN;
		NumPunkt=0;
		return 10;
	};
	};

	if(_page==PM_OPTIONS)
	{
	if(NumPunkt==6) 
	{
		_page=PM_MAIN;
		NumPunkt=0;
		return 10;
	};
	};

	if(_page==PM_CREDIT)
	{
//	if(NumPunkt==7) 
//	{
		_page=PM_MAIN;
		NumPunkt=0;
//	};
	};

	return 10;
};

void GMenuClass::Delete()
{
	pVBButton->Release();
	pIBButton->Release();
	pVBFon->Release();
	pIBFon->Release();
	//TexButton=NULL;
	TexFonMain=NULL;
	Mas=NULL;
};

GMenuClass::GMenuClass()
{
	NumUr=0;
	NumPunkt=0;
	TexFonMain=NULL;
	_page=PM_MAIN;
	//TexButton=NULL;
//	TexFon = new 

};

bool GMenuClass::Load(LPDIRECT3DDEVICE9 *ppDev)
{
	NumBot=4;
//------------------Загрузка фонов меню--------------------
	LPVW But;
	if (FAILED((*ppDev)->CreateVertexBuffer(4*sizeof(WVERTEXWORLD),0,D3DFVF_XYZ|D3DFVF_TEX1,D3DPOOL_DEFAULT,&pVBFon,NULL)))
		return (false);
	if (FAILED(pVBFon->Lock(0,sizeof(WVERTEXWORLD),(void**)&But,0)))
		return (false);

	But[0]=Koord(1.0f,-1.0f,0.0f,1.0f,1.0f);
	But[1]=Koord(1.0f,1.0f,0.0f,1.0f,0.0f);
	But[2]=Koord(-1.0f,-1.0f,0.0f,0.0f,1.0f);
	But[3]=Koord(-1.0f,1.0f,0.0f,0.0f,0.0f);
	
	pVBFon->Unlock();

if (FAILED((*ppDev)->CreateIndexBuffer(6*sizeof(WORD),D3DUSAGE_WRITEONLY,D3DFMT_INDEX16,D3DPOOL_MANAGED,&pIBFon,NULL)))
		return (false);
WORD* indices = 0;
pIBFon->Lock(0,0,(void**)&indices,0);
indices[0]=0;
indices[1]=1;
indices[2]=3;
indices[3]=3;
indices[4]=2;
indices[5]=0;
pIBFon->Unlock();

//------------------Конец загрузки фонов меню--------------------

//------------------Загрузка кнопок управления меню--------------------
		if (FAILED((*ppDev)->CreateVertexBuffer(32*sizeof(WVERTEXWORLD),0,D3DFVF_XYZ|D3DFVF_TEX1,D3DPOOL_DEFAULT,&pVBButton,NULL)))
		return (false);
	if (FAILED(pVBButton->Lock(0,sizeof(WVERTEXWORLD),(void**)&But1,0)))
		return (false);

	But1[0]=Koord(0.1714f,-0.2621f,0.0f,1.0f,1.0f);
	But1[1]=Koord(0.1714f,-0.0638f,0.0f,1.0f,0.0f);
	But1[2]=Koord(-0.1481f,-0.2621f,0.0f,0.0f,1.0f);
	But1[3]=Koord(-0.1481f,-0.0638f,0.0f,0.0f,0.0f);

	But1[4]=Koord(0.2234f,-0.0276f,0.0f,1.0f,1.0f);
	But1[5]=Koord(0.2234f,0.1776f,0.0f,1.0f,0.0f);
	But1[6]=Koord(-0.2026f,-0.0276f,0.0f,0.0f,1.0f);
	But1[7]=Koord(-0.2026f,0.1776f,0.0f,0.0f,0.0f);

	But1[8]=Koord(0.23377f,0.18966f,0.0f,1.0f,1.0f);
	But1[9]=Koord(0.23377f,0.3896f,0.0f,1.0f,0.0f);
	But1[10]=Koord(-0.2351f,0.18966f,0.0f,0.0f,1.0f);
	But1[11]=Koord(-0.2351f,0.3896f,0.0f,0.0f,0.0f);

	But1[12]=Koord(0.25454f,0.40172f,0.0f,1.0f,1.0f);
	But1[13]=Koord(0.25454f,0.60172f,0.0f,1.0f,0.0f);
	But1[14]=Koord(-0.27662f,0.40172f,0.0f,0.0f,1.0f);
	But1[15]=Koord(-0.27662f,0.60172f,0.0f,0.0f,0.0f);

	But1[16]=Koord(0.322078f,0.6069f,0.0f,1.0f,1.0f);
	But1[17]=Koord(0.322078f,0.82069f,0.0f,1.0f,0.0f);
	But1[18]=Koord(-0.324675f,0.6069f,0.0f,0.0f,1.0f);
	But1[19]=Koord(-0.324675f,0.82069f,0.0f,0.0f,0.0f);

	But1[20]=Koord(0.112987013f,-0.889655172f,0.0f,1.0f,1.0f);
	But1[21]=Koord(0.112987013f,-0.675862069f,0.0f,1.0f,0.0f);
	But1[22]=Koord(-0.176623377f,-0.889655172f,0.0f,0.0f,1.0f);
	But1[23]=Koord(-0.176623377f,-0.675862069f,0.0f,0.0f,0.0f);

	But1[24]=Koord(0.427272727f,-0.89137931f,0.0f,1.0f,1.0f);
	But1[25]=Koord(0.427272727f,-0.677586207f,0.0f,1.0f,0.0f);
	But1[26]=Koord(0.162337662f,-0.89137931f,0.0f,0.0f,1.0f);
	But1[27]=Koord(0.162337662f,-0.677586207f,0.0f,0.0f,0.0f);

	But1[28]=Koord(0.977922078f,-0.89137931f,0.0f,1.0f,1.0f);
	But1[29]=Koord(0.977922078f,-0.677586207f,0.0f,1.0f,0.0f);
	But1[30]=Koord(0.453246753f,-0.89137931f,0.0f,0.0f,1.0f);
	But1[31]=Koord(0.453246753f,-0.677586207f,0.0f,0.0f,0.0f);


	pVBButton->Unlock();

	if (FAILED((*ppDev)->CreateIndexBuffer(48*sizeof(WORD),D3DUSAGE_WRITEONLY,D3DFMT_INDEX16,D3DPOOL_MANAGED,&pIBButton ,NULL)))
		return (false);
WORD* indices1 = 0;
pIBButton->Lock(0,0,(void**)&indices1,0);

indices1[0]=0;
indices1[1]=1;
indices1[2]=3;
indices1[3]=3;
indices1[4]=2;
indices1[5]=0;

indices1[6]=4;
indices1[7]=5;
indices1[8]=7;
indices1[9]=7;
indices1[10]=6;
indices1[11]=4;

indices1[12]=8;
indices1[13]=9;
indices1[14]=11;
indices1[15]=11;
indices1[16]=10;
indices1[17]=8;

indices1[18]=12;
indices1[19]=13;
indices1[20]=15;
indices1[21]=15;
indices1[22]=14;
indices1[23]=12;

indices1[24]=16;
indices1[25]=17;
indices1[26]=19;
indices1[27]=19;
indices1[28]=18;
indices1[29]=16;

indices1[30]=20;
indices1[31]=21;
indices1[32]=23;
indices1[33]=23;
indices1[34]=22;
indices1[35]=20;

indices1[36]=24;
indices1[37]=25;
indices1[38]=27;
indices1[39]=27;
indices1[40]=26;
indices1[41]=24;

indices1[42]=28;
indices1[43]=29;
indices1[44]=31;
indices1[45]=31;
indices1[46]=30;
indices1[47]=28;

pIBButton->Unlock();

	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\main_background.jpg", &TexFonMain);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\menu_background.jpg", &TexFonMenu);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\credit_background.jpg", &TexFonCredit);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\exit_pas.jpg", &TexButton[0]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\credit_pas.jpg", &TexButton[1]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\option_pas.jpg", &TexButton[2]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\multi_pas.jpg", &TexButton[3]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\single_pas.jpg", &TexButton[4]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\exit_act.jpg", &TexButton[5]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\credit_act.jpg", &TexButton[6]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\option_act.jpg", &TexButton[7]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\multi_act.jpg", &TexButton[8]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\single_act.jpg", &TexButton[9]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\back_pas.jpg", &TexButton[10]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\back_act.jpg", &TexButton[11]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\next_pas.jpg", &TexButton[12]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\next_act.jpg", &TexButton[13]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\begin_pas.jpg", &TexButton[14]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\begin_act.jpg", &TexButton[15]);
//------------------Конец загрузки кнопок управления меню--------------------

//------------------Загрузка курсора--------------------
	LPVW Cur;
	if (FAILED((*ppDev)->CreateVertexBuffer(4*sizeof(WVERTEXWORLD),0,D3DFVF_XYZ|D3DFVF_TEX1,D3DPOOL_DEFAULT,&pVBCur,NULL)))
		return (false);
	if (FAILED(pVBCur->Lock(0,sizeof(WVERTEXWORLD),(void**)&Cur,0)))
		return (false);
	Cur[0]=Koord(-0.994805195f,0.994827586f,0.0f,0.08f,0.06f);
	Cur[1]=Koord(-0.985714286f,0.929310345f,0.0f,0.22f,0.82f);
	Cur[2]=Koord(-0.97012987f,0.956896552f,0.0f,0.46f,0.5f);
	Cur[3]=Koord(-0.942857143f,0.953448276f,0.0f,0.88f,0.54f);
	pVBCur->Unlock();

	if (FAILED((*ppDev)->CreateIndexBuffer(6*sizeof(WORD),D3DUSAGE_WRITEONLY,D3DFMT_INDEX16,D3DPOOL_MANAGED,&pIBCur ,NULL)))
		return (false);
WORD* indices2 = 0;
pIBCur->Lock(0,0,(void**)&indices2,0);

indices2[0]=0;
indices2[1]=1;
indices2[2]=2;
indices2[3]=0;
indices2[4]=2;
indices2[5]=3;

pIBCur->Unlock();
pFontCredit=NULL;
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\Cursor.jpg", &TexCur);
//------------------Конец загрузки курсора--------------------


//------------------Загрузка кнопок меню--------------------
		if (FAILED((*ppDev)->CreateVertexBuffer(16*sizeof(WVERTEXWORLD),0,D3DFVF_XYZ|D3DFVF_TEX1,D3DPOOL_DEFAULT,&pVBBot,NULL)))
		return (false);
	if (FAILED(pVBBot->Lock(0,sizeof(WVERTEXWORLD),(void**)&Bot1,0)))
		return (false);

	Bot1[0]=Koord(-0.50f,0.50f,0.0f,1.0f,1.0f);
	Bot1[1]=Koord(-0.50f,0.8f,0.0f,1.0f,0.0f);
	Bot1[2]=Koord(-0.8f,0.50f,0.0f,0.0f,1.0f);
	Bot1[3]=Koord(-0.8f,0.8f,0.0f,0.0f,0.0f);

	Bot1[4]=Koord(-0.10f,0.50f,0.0f,1.0f,1.0f);
	Bot1[5]=Koord(-0.10f,0.8f,0.0f,1.0f,0.0f);
	Bot1[6]=Koord(-0.40f,0.50f,0.0f,0.0f,1.0f);
	Bot1[7]=Koord(-0.40f,0.8f,0.0f,0.0f,0.0f);

	Bot1[8]=Koord(0.30f,0.50f,0.0f,1.0f,1.0f);
	Bot1[9]=Koord(0.30f,0.8f,0.0f,1.0f,0.0f);
	Bot1[10]=Koord(0.0f,0.50f,0.0f,0.0f,1.0f);
	Bot1[11]=Koord(0.0f,0.8f,0.0f,0.0f,0.0f);

	Bot1[12]=Koord(0.70f,0.50f,0.0f,1.0f,1.0f);
	Bot1[13]=Koord(0.70f,0.8f,0.0f,1.0f,0.0f);
	Bot1[14]=Koord(0.40f,0.50f,0.0f,0.0f,1.0f);
	Bot1[15]=Koord(0.40f,0.8f,0.0f,0.0f,0.0f);

	pVBBot->Unlock();

	if (FAILED((*ppDev)->CreateIndexBuffer(24*sizeof(WORD),D3DUSAGE_WRITEONLY,D3DFMT_INDEX16,D3DPOOL_MANAGED,&pIBBot ,NULL)))
		return (false);
WORD* indices3 = 0;
pIBBot->Lock(0,0,(void**)&indices3,0);

indices3[0]=0;
indices3[1]=1;
indices3[2]=3;
indices3[3]=3;
indices3[4]=2;
indices3[5]=0;

indices3[6]=4;
indices3[7]=5;
indices3[8]=7;
indices3[9]=7;
indices3[10]=6;
indices3[11]=4;

indices3[12]=8;
indices3[13]=9;
indices3[14]=11;
indices3[15]=11;
indices3[16]=10;
indices3[17]=8;

indices3[18]=12;
indices3[19]=13;
indices3[20]=15;
indices3[21]=15;
indices3[22]=14;
indices3[23]=12;


pIBBot->Unlock();

	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\Person\\bot_pas.jpg", &TexBot[0]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\Person\\bos_pas.jpg", &TexBot[1]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\Person\\cross_pas.jpg", &TexBot[2]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\Person\\rand_pas.jpg", &TexBot[3]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\Person\\bot_act.jpg", &TexBot[4]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\Person\\bos_act.jpg", &TexBot[5]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\Person\\cross_act.jpg", &TexBot[6]);
	D3DXCreateTextureFromFile(*ppDev,"data\\Menu\\Person\\rand_act.jpg", &TexBot[7]);
//------------------Конец загрузки кнопок меню--------------------


   D3DXFONT_DESCA lf;
   
   ZeroMemory(&lf, sizeof(D3DXFONT_DESCA));
   lf.Height    = 25;    // в логических единицах
   lf.Width     = 12;    // в логических единицах
   lf.Weight    = 500;   // насыщенность, диапазон 0(тонкий) - 1000(жирный)
   lf.Italic    = false;
   lf.CharSet   = DEFAULT_CHARSET;
   lstrcpy(lf.FaceName, "Times New Roman"); // гарнитура шрифта
if (pFontCredit == NULL)
D3DXCreateFontIndirect(*ppDev, &lf, &pFontCredit);

   D3DXFONT_DESCA lfl;
   
   ZeroMemory(&lfl, sizeof(D3DXFONT_DESCA));
   lfl.Height    = 25;    // в логических единицах
   lfl.Width     = 12;    // в логических единицах
   lfl.Weight    = 1000;   // насыщенность, диапазон 0(тонкий) - 1000(жирный)
   lfl.Italic    = false;
   lfl.CharSet   = DEFAULT_CHARSET;
   lstrcpy(lfl.FaceName, "Arial"); // гарнитура шрифта
pFontObj=NULL;
if (pFontObj == NULL)
D3DXCreateFontIndirect(*ppDev, &lfl, &pFontObj);

   D3DXFONT_DESCA lflo;
   
   ZeroMemory(&lflo, sizeof(D3DXFONT_DESCA));
   lflo.Height    = 15;    // в логических единицах
   lflo.Width     = 7;    // в логических единицах
   lflo.Weight    = 500;   // насыщенность, диапазон 0(тонкий) - 1000(жирный)
   lflo.Italic    = false;
   lflo.CharSet   = DEFAULT_CHARSET;
   lstrcpy(lflo.FaceName, "Arial"); // гарнитура шрифта
pFontOpis=NULL;
if (pFontOpis == NULL)
D3DXCreateFontIndirect(*ppDev, &lflo, &pFontOpis);


return true;
};

bool GMenuClass::Draw(LPDIRECT3DDEVICE9 *ppDev)
{
	switch (_page)
		{
		case PM_MAIN://главное окно меню
			{

	(*ppDev)->SetStreamSource(0,pVBFon,0,sizeof(WVERTEXWORLD));//устанавливаем источник вершин
	(*ppDev)->SetFVF(D3DFVF_XYZ|D3DFVF_TEX1);//устан. формат вершин
	(*ppDev)->SetTexture(0,TexFonMain);
	(*ppDev)->SetIndices(pIBFon);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,0,2);
	(*ppDev)->SetStreamSource(0,pVBButton,0,sizeof(WVERTEXWORLD));
	(*ppDev)->SetIndices(pIBButton);
	if(NumPunkt==1)(*ppDev)->SetTexture(0,TexButton[5]); else (*ppDev)->SetTexture(0,TexButton[0]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,0,2);
	if(NumPunkt==2)(*ppDev)->SetTexture(0,TexButton[6]); else (*ppDev)->SetTexture(0,TexButton[1]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,6,2);
//	if(NumPunkt==3)(*ppDev)->SetTexture(0,TexButton[7]); else 
	(*ppDev)->SetTexture(0,TexButton[2]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,12,2);
//	if(NumPunkt==4)(*ppDev)->SetTexture(0,TexButton[8]); else 
	(*ppDev)->SetTexture(0,TexButton[3]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,18,2);
	if(NumPunkt==5)(*ppDev)->SetTexture(0,TexButton[9]); else (*ppDev)->SetTexture(0,TexButton[4]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,24,2);
			};break;

		case PM_SINGLE://меню одиночной игры
			{
	(*ppDev)->SetStreamSource(0,pVBFon,0,sizeof(WVERTEXWORLD));//устанавливаем источник вершин
	(*ppDev)->SetFVF(D3DFVF_XYZ|D3DFVF_TEX1);//устан. формат вершин
	(*ppDev)->SetTexture(0,TexFonMenu);
	(*ppDev)->SetIndices(pIBFon);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,0,2);
	(*ppDev)->SetStreamSource(0,pVBButton,0,sizeof(WVERTEXWORLD));
	(*ppDev)->SetIndices(pIBButton);
	if(NumPunkt==6)(*ppDev)->SetTexture(0,TexButton[11]); else (*ppDev)->SetTexture(0,TexButton[10]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,30,2);
//	if(NumPunkt==7)(*ppDev)->SetTexture(0,TexButton[13]); else (*ppDev)->SetTexture(0,TexButton[12]);
//	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,36,2);
	if(NumPunkt==8)(*ppDev)->SetTexture(0,TexButton[15]); else (*ppDev)->SetTexture(0,TexButton[14]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,42,2);

	(*ppDev)->SetStreamSource(0,pVBBot,0,sizeof(WVERTEXWORLD));
	(*ppDev)->SetIndices(pIBBot);
	if(NumBot==1)(*ppDev)->SetTexture(0,TexBot[4]);else
		(*ppDev)->SetTexture(0,TexBot[0]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,0,2);
	if(NumBot==2)(*ppDev)->SetTexture(0,TexBot[5]);else
	(*ppDev)->SetTexture(0,TexBot[1]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,6,2);
	if(NumBot==3)(*ppDev)->SetTexture(0,TexBot[6]);else
	(*ppDev)->SetTexture(0,TexBot[2]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,12,2);
	if(NumBot==4)(*ppDev)->SetTexture(0,TexBot[7]);else
	(*ppDev)->SetTexture(0,TexBot[3]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,18,2);
	if (pFontObj!=NULL) MyTextOut(pFontObj,"Обувь предоставлена торговым домом Руслан",10,30,730,150,0xffffff00);
	if (NumBot==1)
		if (pFontOpis!=NULL) MyTextOut(pFontOpis,"Отличные всесезонные рабочие ботинки от фирмы Unichel",50,180,780,350,0xffffff00);
	if (NumBot==2)
		if (pFontOpis!=NULL) MyTextOut(pFontOpis,"Летние симпотичные туфли-босоножки от фирмы Vistas",50,180,780,350,0xffffff00);
	if (NumBot==3)
		if (pFontOpis!=NULL) MyTextOut(pFontOpis,"Легкие спортивные кроссовки от фирмы Adidas",50,180,780,350,0xffffff00);
	if (NumBot==4)
		if (pFontOpis!=NULL) MyTextOut(pFontOpis,"Обувь по рекомендации продавцев-консультантов магазина Кардинал",50,180,780,350,0xffffff00);
		
			};break;

		case PM_MULTI://меню многопользовательской игры
			{
	(*ppDev)->SetStreamSource(0,pVBFon,0,sizeof(WVERTEXWORLD));//устанавливаем источник вершин
	(*ppDev)->SetFVF(D3DFVF_XYZ|D3DFVF_TEX1);//устан. формат вершин
	(*ppDev)->SetTexture(0,TexFonMenu);
	(*ppDev)->SetIndices(pIBFon);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,0,2);
	(*ppDev)->SetStreamSource(0,pVBButton,0,sizeof(WVERTEXWORLD));
	(*ppDev)->SetIndices(pIBButton);
	if(NumPunkt==6)(*ppDev)->SetTexture(0,TexButton[11]); else (*ppDev)->SetTexture(0,TexButton[10]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,30,2);

			};break;

		case PM_OPTIONS://меню настроек игры
			{
	(*ppDev)->SetStreamSource(0,pVBFon,0,sizeof(WVERTEXWORLD));//устанавливаем источник вершин
	(*ppDev)->SetFVF(D3DFVF_XYZ|D3DFVF_TEX1);//устан. формат вершин
	(*ppDev)->SetTexture(0,TexFonMenu);
	(*ppDev)->SetIndices(pIBFon);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,0,2);
	(*ppDev)->SetStreamSource(0,pVBButton,0,sizeof(WVERTEXWORLD));
	(*ppDev)->SetIndices(pIBButton);
	if(NumPunkt==6)(*ppDev)->SetTexture(0,TexButton[11]); else (*ppDev)->SetTexture(0,TexButton[10]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,30,2);

			};break;

		case PM_CREDIT://создатели игры
			{
	(*ppDev)->SetStreamSource(0,pVBFon,0,sizeof(WVERTEXWORLD));//устанавливаем источник вершин
	(*ppDev)->SetFVF(D3DFVF_XYZ|D3DFVF_TEX1);//устан. формат вершин
	(*ppDev)->SetTexture(0,TexFonCredit);
	(*ppDev)->SetIndices(pIBFon);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,0,2);
/*	(*ppDev)->SetStreamSource(0,pVBButton,0,sizeof(WVERTEXWORLD));
	(*ppDev)->SetIndices(pIBButton);
	if(NumPunkt==7)(*ppDev)->SetTexture(0,TexButton[13]); else (*ppDev)->SetTexture(0,TexButton[12]);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,42,2);*/

	MyTextOut(pFontCredit,"СОЗДАТЕЛИ:",70,100,730,150,0xffffff00);
	MyTextOut(pFontCredit,"Программирование:",70,200,730,240,0xffffff00);
	MyTextOut(pFontCredit,"Евгений Gdp_Zhora Гаврусь",70,240,730,280,0xffffff00);

			};break;


	};
	POINT Position;
	GetCursorPos(&Position);
	D3DXMATRIX MatrixTemp;
	float vx=(Position.x)/(800.0f/2.0f);
	float vy=-(Position.y)/(600.0f/2.0f);
	D3DXMatrixTranslation(&MatrixTemp,vx,vy,0);
	(*ppDev)->SetTransform(D3DTS_WORLD,&MatrixTemp);
	(*ppDev)->SetStreamSource(0,pVBCur,0,sizeof(WVERTEXWORLD));//устанавливаем источник вершин
	(*ppDev)->SetTexture(0,TexCur);
	(*ppDev)->SetIndices(pIBCur);
	(*ppDev)->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,6,0,2);
	return true;
};