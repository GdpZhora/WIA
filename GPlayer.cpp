#include "main.h"

char* NamesBot[33]=
{"Smith","Clark","Mitchell","Johnson","Thomas","Williams","Jackson","Roberts","Jones","Scott","Turner","Harris","Walker","Davis","Martin","Adams","Miller",
"Wilson","Martinez","Nelson","Edwards","Taylor","Robinson","Collins","Jennifer","Mary","Barbara","Lisa","Nancy","Helen","Patricia","Linda","Margaret"};

sKeyframe kfLeft[7] = { 
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
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{1200,  1.00000f, 0.00000f, 0.00000f, 0.00000f,
   			 0.00000f, 1.00000f, 0.00000f, 0.00000f,
		     0.00000f, 0.00000f, 1.00000f, 0.00000f,
			 0.00000f, 0.00000f, 0.00000f, 1.00000f}
			};
sKeyframe kfRight[7] = { 
		{0,  1.00000f, 0.00000f, 0.00000f, 0.00000f,
   			 0.00000f, 1.00000f, 0.00000f, 0.00000f,
		     0.00000f, 0.00000f, 1.00000f, 0.00000f,
			 0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{200, 0.510563f, -0.0869502f, -0.855433f, -74.8247f,
		   -0.00523352f, 0.994541f, -0.104213f, -9.11550f,
		   0.859824f, 0.0576844f, 0.507321f,-15.246f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{400, -0.477733f, -0.263651f, -0.838009f, -73.30060f,
		   -0.00783566f, 0.952587f, -0.304165f, -26.60540f,
		   0.87847f, -0.151876f, -0.453017f, -105.6630f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{600, -0.999048f, 0.00000f, -0.0436191f, -3.81540f,
		   0.0184348f, 0.906308f, -0.422216f, -36.93130f,
		   0.0395324f, -0.422618f, -0.905445f, -173.97570f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{800, -0.546394f, 0.281721f, 0.788725f, 68.98980f,
		   0.00896185f, 0.943642f, -0.330847f, -28.93920f,
		   -0.83748f, -0.173704f, -0.518125f, -108.0990f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
   		{1000, 0.437777f, 0.111753f, 0.892112f, 78.0330f,
		   -0.00448737f, 0.992504f, -0.122127f, -10.68240f,
		   -0.899073f, 0.0494609f, 0.434997f, -18.2550f,
		   0.00000f, 0.00000f, 0.00000f, 1.00000f},
		{1200,  1.00000f, 0.00000f, 0.00000f, 0.00000f,
   			 0.00000f, 1.00000f, 0.00000f, 0.00000f,
		     0.00000f, 0.00000f, 1.00000f, 0.00000f,
			 0.00000f, 0.00000f, 0.00000f, 1.00000f}
			};


GBot::GBot()
{
	_right=D3DXVECTOR3(1,0,0);
	_up=D3DXVECTOR3(0,1,0);
	_look=D3DXVECTOR3(0,0,1);
	_pos.x=0.0f;
	_pos.y=0.0f;
	_pos.z=0.0f;
//	pLeft = new GObj[2];
	//pRight = new GObj;
	Ugol=3.140f/2.0f;
	Anim=false;
};

BOOL GBot::Load(char *file,LPDIRECT3DDEVICE9 *ppDev)

{
	place=0;
	TimeRemont=timeGetTime()-5000;
	Finish=FALSE;
	FactRemont=FALSE;
	beg=FALSE;
	if(_typeBot==1)
{
	Speed=0.0f;
	MaxSpeed=5;
	Uscor=5;
	Upravl=5;
	D3DXMatrixIdentity(&matLeft);
	D3DXMatrixTranspose(&matLeft,&matLeft);
	D3DXMATRIX MatrixTemp;
	D3DXMatrixRotationX(&MatrixTemp,-3.140f/2);
    matLeft*=MatrixTemp;
	D3DXMatrixTranslation(&MatrixTemp,0,50,0);
    matLeft*=MatrixTemp;
	NamePlayer=NamesBot[rand()%24];
};

if(GBot::_typeBot==2)
{
	Speed=0.0f;
	MaxSpeed=7;
	Uscor=5;
	Upravl=3;
	D3DXMatrixIdentity(&matLeft);
	D3DXMatrixTranspose(&matLeft,&matLeft);
	D3DXMATRIX MatrixTemp;
	D3DXMatrixRotationX(&MatrixTemp,-3.140f/2);
    matLeft*=MatrixTemp;
	D3DXMatrixRotationY(&MatrixTemp,-3.140f);
    matLeft*=MatrixTemp;
	D3DXMatrixScaling(&MatrixTemp,2,2,2);
	matLeft*=MatrixTemp;
	D3DXMatrixTranslation(&MatrixTemp,0,20,0);
    matLeft*=MatrixTemp;
	NamePlayer=NamesBot[rand()%9+24];
};

if(GBot::_typeBot==3)
{
	Speed=0.0f;
	MaxSpeed=5;
	Uscor=6;
	Upravl=4;
	D3DXMatrixIdentity(&matLeft);
	D3DXMatrixTranspose(&matLeft,&matLeft);
	D3DXMATRIX MatrixTemp;
	D3DXMatrixRotationX(&MatrixTemp,-3.140f/2);
    matLeft*=MatrixTemp;
	D3DXMatrixRotationY(&MatrixTemp,3.140f/2);
    matLeft*=MatrixTemp;
	D3DXMatrixScaling(&MatrixTemp,2,2,2);
	matLeft*=MatrixTemp;
	D3DXMatrixTranslation(&MatrixTemp,0,20,0);
    matLeft*=MatrixTemp;
	NamePlayer=NamesBot[rand()%33];
};

   D3DXFONT_DESCA lf;
   pFont=NULL;
   ZeroMemory(&lf, sizeof(D3DXFONT_DESCA));
   lf.Height    = 20;    // в логических единицах
   lf.Width     = 10;    // в логических единицах
   lf.Weight    = 500;   // насыщенность, диапазон 0(тонкий) - 1000(жирный)
   lf.Italic    = false;
   lf.CharSet   = DEFAULT_CHARSET;
   lstrcpy(lf.FaceName, "Times New Roman"); // гарнитура шрифта
if (pFont == NULL)
D3DXCreateFontIndirect(*ppDev, &lf, &pFont);

	return true;
};

BOOL GBot::Draw(LPDIRECT3DDEVICE9 pDev)
{
	D3DXMATRIX MatrixTempL;
	D3DXMATRIX MatrixTemp;
	D3DXMATRIX MatrixTempR;
	D3DXMatrixRotationY(&MatrixTemp,Ugol);
	MatrixTempL=matLeft*MatrixTemp;
	MatrixTempR=matRight*MatrixTemp;
	D3DXMatrixTranslation(&MatrixTemp,_pos.x,_pos.y,_pos.z);
	MatrixTempL*=MatrixTemp;
	MatrixTempR*=MatrixTemp;
	pDev->SetTransform(D3DTS_WORLD, &MatrixTempL);
	if(!(pModel->Draw()))
     {
           return false;
	};
	//if (pFont!=NULL) MyTextOut(pFont,NamePlayer,10,550,300,570,0xff000000);

return true;

};

void GBot::Delete()
{
	
	pModel->Delete();
	pModel=NULL;
};

void GBot::pitch(float angle)
{
     D3DXMATRIX T;
     D3DXMatrixRotationAxis(&T, &_right, angle);

     // Поворот векторов _up и _look относительно вектора _right
     D3DXVec3TransformCoord(&_up,&_up, &T);
     D3DXVec3TransformCoord(&_look,&_look, &T);
}

void GBot::yaw(float angle)
{
	if ((Speed-abs(angle)*(1.0f/Upravl)*10)>=0)
		Speed-=abs(angle)*(1.0f/Upravl)*10;
	else Speed=0;
     D3DXMATRIX T;

     // Для наземных объектов выполняем вращение
     // вокруг мировой оси Y (0, 1, 0)
          D3DXMatrixRotationY(&T, angle);
	  Ugol+=angle;

     // Поворот векторов _right и _look относительно
     // вектора _up или оси Y
     D3DXVec3TransformCoord(&_right, &_right, &T);
     D3DXVec3TransformCoord(&_look, &_look, &T);
}


void GBot::walk(float units,float time)
{
		if(time==0.0f)
		{_pos += D3DXVECTOR3(_look.x, 0.0f, _look.z) * units;
		return;};
	if(((Speed<MaxSpeed)&&(units>0.0f))||((Speed>0)&&(units<0.0f)))
		Speed+=units*Uscor/2000.0f;
	else
		if(Speed>0.0f)
		Speed-=time*Uscor/2000.0f;

		if(Speed<0.0f)
		Speed=0.0f;

	
	float Rast=time*Speed/5;
	_pos += D3DXVECTOR3(_look.x, 0.0f, _look.z) * Rast;


}

void GBot::strafe(float units)
{
          _pos += D3DXVECTOR3(_right.x, 0.0f, _right.z) * units;

}


void GBot::getPosition(D3DXVECTOR3 *pos)
{
	(*pos)=_pos;

};

void GBot::setPosition(D3DXVECTOR3* pos)//функция устанавливает позицию камеры
{
	_pos=*pos;
};

void GBot::getLook(D3DXVECTOR3 *look)
{
	(*look)=_look;
};

void GBot::setLook(D3DXVECTOR3 *look)
{
	_look=*look;
};

void GBot::setRight(D3DXVECTOR3 *right)
{
	_right=*right;
};

void GBot::getRight(D3DXVECTOR3 *right)
{
	(*right)=_right;
};



void GBot::Reset(DWORD Time)
{
	if(!(Anim))
	{
		Anim=true;
		BeginAnim=Time;
	};
	DWORD Elapsed=Time-BeginAnim;
	if (Elapsed>=1200){
		BeginAnim+=1200;
		Elapsed=Time-BeginAnim;
	};
	DWORD Keyframe=0;
	for(DWORD i=0;i<7;i++)
	{
		if(Elapsed>=kfLeft[i].Time) 
			Keyframe=i;
	};
	DWORD Keyframe2 = (Keyframe==6) ? Keyframe:Keyframe+1;
	DWORD TimeDiff = kfLeft[Keyframe2].Time-kfLeft[Keyframe].Time;
	if(!TimeDiff) TimeDiff=1;
	float Scalar = (Elapsed-kfLeft[Keyframe].Time)/TimeDiff;
	D3DXMATRIX matInt=D3DXMATRIX(kfLeft[Keyframe2].matTransformation)-D3DXMATRIX(kfLeft[Keyframe].matTransformation);
	matInt*=Scalar;
	matInt+=D3DXMATRIX(kfLeft[Keyframe].matTransformation);
	matLeft=matInt;
	/*matLeft._14-=(-21.9351);
	matLeft._24-=(-74.8095);
	matLeft._34-=39.9993;
/*	matLeft._14+=(-18.1628);
	matLeft._24+=53.7196;
	matLeft._34+=213.593;*/

	D3DXMatrixTranspose(&matLeft,&matLeft);
	D3DXMATRIX MatrixTemp;
	D3DXMatrixRotationX(&MatrixTemp,-3.140f/2);
	matLeft*=MatrixTemp;

	matInt=D3DXMATRIX(kfRight[Keyframe2].matTransformation)-D3DXMATRIX(kfRight[Keyframe].matTransformation);
	matInt*=Scalar;
	matInt+=D3DXMATRIX(kfRight[Keyframe].matTransformation);
	matRight=matInt;
	/*matRight._14-=(-18.1628);
	matRight._24-=53.7196;
	matRight._34-=213.593;
	/*matRight._14+=(-21.9351);
	matRight._24+=(-74.8095);
	matRight._34+=39.9993;*/
	
	D3DXMatrixTranspose(&matRight,&matRight);
	matRight*=MatrixTemp;



};