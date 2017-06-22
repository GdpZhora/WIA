#include "main.h"

//	LPDIRECT3D9 g_pD3D;//Объект Direct3D

//LPDIRECT3DDEVICE9 g_pD3DDevice;//Устройство Direct3D
float predug=0.0;
bool flagm=false;
bool flagz=true;
DWORD StOldTime;
DWORD FrameCnt;    // Количество выведенных кадров
DWORD TimeElapsed; // Прошедшее время
DWORD FPS;         // Частота визуализации кадров
DWORD m_dwClearFlags = D3DCLEAR_TARGET;
char* MasName[20];
DWORD MasTime[20];
bool MasYou[20];
char* bun;
DWORD but;
bool buy;
ID3DXFont* pFontZas;
ID3DXFont* pFontZas1;

void CalcFPS(DWORD timeDelta)
{
     FrameCnt++;
     TimeElapsed += timeDelta;

     if(TimeElapsed >= 1)
     {
          FPS = (FrameCnt*1000) / TimeElapsed;
          TimeElapsed = 0;
          FrameCnt = 0;
     }
}


GameEngine::GameEngine()
{
	m_pD3D = NULL;
	m_pd3dDevice = NULL;
	pMainPlayer = new GBot;
	//*ppPlayers=new GBot;
	_type=TE_MENU;
	pBotinok = new GObj;
	pBoson = new GObj;
	pKross = new GObj;
	pTree = new GObj;
	Menu = new GMenuClass;
	pFont = NULL;
	LevelInfo = new LevelClass;
	Trassa = new GTrassaClass;
};

void GameEngine::Create(HWND hWnd)
{
	ofstream OutFile;
	OutFile.open("Debug.log",ios::app);
	OutFile<<"-Создание движка... "<<endl;
	OutFile.close();
	fail=true;
	ShowCursor(TRUE);
	OutFile.open("Debug.log",ios::app);
	OutFile<<"--Создание Direct3D... ";
	OutFile.close();

//	InitD3D(&m_pD3D,&m_pd3dDevice,hWnd);
	BOOL m_bWindowed			=	FALSE;
	BOOL m_bUseDepthBuffer	=	TRUE;	// Whether to autocreate depthbuffer
	DWORD m_dwMinDepthBits	=	16;		// Minimum number of bits needed in depth buffer
	DWORD m_dwMinStencilBits	=	0;		// Minimum number of bits needed in stencil buffer
	DWORD m_dwCreationWidth	=	800;	// Width used to create window
	DWORD m_dwCreationHeight	=	600;	// Height used to create window
	DWORD m_dwColorDepth		=	16;
	DWORD m_bLoadMainMenu		=	1;
	DWORD m_bInvertMouse       =	1;

	DWORD m_dwAlphaDepth		=	0;
	DWORD m_dwRedDepth		=	5;
	DWORD m_dwGreenDepth		=	6;
	DWORD m_dwBlueDepth		=	5;

	D3DFORMAT				m_fmtDepthStencil;
	D3DFORMAT				m_fmtBack;
	RECT					m_rcWindowClient;
	GetClientRect( hWnd, &m_rcWindowClient );

	OutFile.open("Debug.log",ios::app);
	OutFile<<endl<<"Формат ";

		m_fmtDepthStencil = D3DFMT_D16;
		m_dwClearFlags |= D3DCLEAR_ZBUFFER;

		m_fmtBack = D3DFMT_R5G6B5;

	OutFile.close();

	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if( m_pD3D == NULL ) 
	{	//	Add Message - In Future We will Add message to Log File
		return;
	}
	OutFile.open("Debug.log",ios::app);
	OutFile<<"Успешно "<<endl;
	OutFile.close();

//		::MessageBox(NULL, "4", "Fatal Error", MB_ICONERROR);
	
	OutFile.open("Debug.log",ios::app);
	OutFile<<"--Создание Direct3D Device... ";
	OutFile.close();

	// Get Display Mode For Windowed Mode
	D3DDISPLAYMODE d3ddm;
	D3DPRESENT_PARAMETERS m_d3dpp;
    if( FAILED( m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm ) ) )
	{
		m_pD3D->Release(); // Clean Existing
		return;
	}
		
//		::MessageBox(NULL, "5", "Fatal Error", MB_ICONERROR);

	ZeroMemory( &m_d3dpp, sizeof(m_d3dpp) );

	m_d3dpp.Windowed			   = m_bWindowed;
	m_d3dpp.BackBufferCount 	   = 1;
	m_d3dpp.MultiSampleType 	   = D3DMULTISAMPLE_NONE;
	m_d3dpp.SwapEffect			   = D3DSWAPEFFECT_FLIP;
	m_d3dpp.EnableAutoDepthStencil = m_bUseDepthBuffer;
	m_d3dpp.AutoDepthStencilFormat = m_fmtDepthStencil;
	m_d3dpp.hDeviceWindow		   = hWnd;
    m_d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;


		m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;// Tweak Out Vertical Sync
		m_d3dpp.BackBufferWidth  = m_dwCreationWidth;
		m_d3dpp.BackBufferHeight = m_dwCreationHeight;
		m_d3dpp.BackBufferFormat = m_fmtBack;


//	HRESULT hr; 

	// Create the device
    if( FAILED( m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_MIXED_VERTEXPROCESSING,//|D3DCREATE_MULTITHREADED,
                                      &m_d3dpp, &m_pd3dDevice ) ) )
 return;

	// Set the default render states
  m_pd3dDevice->SetRenderState(D3DRS_LIGHTING,         FALSE);
  m_pd3dDevice->SetRenderState(D3DRS_ZENABLE,          D3DZB_TRUE);
  m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
  m_pd3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE,  FALSE);

  // Set the default texture stage states
  m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
  m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
  m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP,   D3DTOP_MODULATE);

  // Set the default texture filters
 m_pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
  m_pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);


	OutFile.open("Debug.log",ios::app);
	OutFile<<"Успешно"<<endl;
	OutFile.close();

//			::MessageBox(NULL, "9", "Fatal Error", MB_ICONERROR);


	ZeroMemory(&Light, sizeof(D3DLIGHT9));
	Light.Type=D3DLIGHT_POINT;
	Light.Diffuse.r=1.0f;
	Light.Diffuse.g=1.0f;
	Light.Diffuse.b=0.0f;
	Light.Range=1000.0f;
    Light.Position=D3DXVECTOR3(0.0f,200.0f,0.0f);

	OutFile.open("Debug.log",ios::app);
	OutFile<<"--Создание DirectInput... ";
	OutFile.close();

	//Создаем устройства ввода
	if (!(Inp.GCreateInput(&hIns)))
	{
		return;
	}
	if (!(Inp.CreateKeyboard(hWnd)))
	{
		return;
	};
	if (!(Inp.CreateMouse(hWnd)))
	{
		return;
	}

	OutFile.open("Debug.log",ios::app);
	OutFile<<"Успешно"<<endl;
	OutFile.close();

   D3DXFONT_DESCA lf;
   
   ZeroMemory(&lf, sizeof(D3DXFONT_DESCA));
   lf.Height    = 20;    // в логических единицах
   lf.Width     = 10;    // в логических единицах
   lf.Weight    = 500;   // насыщенность, диапазон 0(тонкий) - 1000(жирный)
   lf.Italic    = false;
   lf.CharSet   = DEFAULT_CHARSET;
   lstrcpy(lf.FaceName, "Times New Roman"); // гарнитура шрифта
if (pFont == NULL)
D3DXCreateFontIndirect(m_pd3dDevice, &lf, &pFont);

   D3DXFONT_DESCA lfst;
   pFontSt=NULL;
   ZeroMemory(&lfst, sizeof(D3DXFONT_DESCA));
   lfst.Height    = 200;    // в логических единицах
   lfst.Width     = 100;    // в логических единицах
   lfst.Weight    = 500;   // насыщенность, диапазон 0(тонкий) - 1000(жирный)
   lfst.Italic    = false;
   lfst.CharSet   = DEFAULT_CHARSET;
   lstrcpy(lfst.FaceName, "Arial"); // гарнитура шрифта
   if (pFontSt == NULL)
D3DXCreateFontIndirect(m_pd3dDevice, &lfst, &pFontSt);

   D3DXFONT_DESCA lfzas;
   pFontZas=NULL;
   ZeroMemory(&lfzas, sizeof(D3DXFONT_DESCA));
   lfzas.Height    = 150;    // в логических единицах
   lfzas.Width     = 75;    // в логических единицах
   lfzas.Weight    = 500;   // насыщенность, диапазон 0(тонкий) - 1000(жирный)
   lfzas.Italic    = false;
   lfzas.CharSet   = DEFAULT_CHARSET;
   lstrcpy(lfzas.FaceName, "Arial"); // гарнитура шрифта
   if (pFontZas == NULL)
D3DXCreateFontIndirect(m_pd3dDevice, &lfzas, &pFontZas);

   D3DXFONT_DESCA lfzas1;
   pFontZas1=NULL;
   ZeroMemory(&lfzas1, sizeof(D3DXFONT_DESCA));
   lfzas1.Height    = 75;    // в логических единицах
   lfzas1.Width     = 30;    // в логических единицах
   lfzas1.Weight    = 500;   // насыщенность, диапазон 0(тонкий) - 1000(жирный)
   lfzas1.Italic    = false;
   lfzas1.CharSet   = DEFAULT_CHARSET;
   lstrcpy(lfzas1.FaceName, "Arial"); // гарнитура шрифта
   if (pFontZas1 == NULL)
D3DXCreateFontIndirect(m_pd3dDevice, &lfzas1, &pFontZas1);

	StOldTime=timeGetTime();
	fail=false;
	OutFile.open("Debug.log",ios::app);
	OutFile<<"-Создание движка завершена"<<endl;
	OutFile.close();
	ShowCursor(FALSE);
	ShowCursor(FALSE);
	flagz=false;

  ZeroMemory(&Light, sizeof(D3DLIGHT9));
  Light.Type = D3DLIGHT_DIRECTIONAL;
  Light.Diffuse.r = Light.Diffuse.g = Light.Diffuse.b = Light.Diffuse.a = 1.0f;
  Light.Direction = D3DXVECTOR3(0.0f, 150.5f, 0.5f);
  m_pd3dDevice->SetLight(0, &Light);
  m_pd3dDevice->LightEnable(0, TRUE);
  GameLoaded=FALSE;

}



BOOL GameEngine::RenderScene()
{
	DWORD TekTime;
	DWORD Raznica;
	BOOL hl = true;
	D3DXMATRIX MatrixProjection;
	TekTime = timeGetTime();
	if ((TekTime-StOldTime)<20) return true;

	try
{
	Raznica=TekTime-StOldTime;
	DWORD TimePRemont = pMainPlayer->TimeRemont;
	DWORD Otremont=TekTime-TimePRemont;
	CalcFPS(Raznica);
	StOldTime=TekTime;
		D3DXMATRIX MatrixWorld;
		D3DXMATRIX MatrixTemp;
		D3DXMATRIX MatrixView;
		D3DXMATRIX MatrixIdenty;
		
		if(!Finished)
		{
		Finished=TRUE;
		if(!pMainPlayer->Finish) Finished=FALSE;
		for(int i=0;i<CountPlayers;i++)
			if (!Players[i].Finish) Finished=FALSE;
		if(Finished) TimeFinished=TekTime;
		};

		if(Finished)
		{
			MasName[0]=pMainPlayer->NamePlayer;
			MasTime[0]=pMainPlayer->TimeFinish;
			MasYou[0]=TRUE;
			for(int i=0;i<CountPlayers;i++)
			{
				MasName[i+1]=Players[i].NamePlayer;
				MasTime[i+1]=Players[i].TimeFinish;
				MasYou[i+1]=FALSE;
			};
			for(int i=0;i<CountPlayers;i++)
			{
				for(int j=i+1;j<=CountPlayers;j++)
				{
					if(MasTime[i]>MasTime[j])
					{
						but=MasTime[i];
						MasTime[i]=MasTime[j];
						MasTime[j]=but;
						bun=MasName[i];
						MasName[i]=MasName[j];
						MasName[j]=bun;
						buy=MasYou[i];
						MasYou[i]=MasYou[j];
						MasYou[j]=buy;
					};
				};
			};
		};


		Inp.Reset();
		if(Inp.Esc)
		{
			if(Finished)
			{
//				Delete();
				GameLoaded=false;
			};
			_type=TE_MENU;
    D3DXMatrixPerspectiveFovLH( &MatrixProjection, D3DX_PI/4, 1.0f, 1.0f, 100.0f );
    m_pd3dDevice->SetTransform( D3DTS_PROJECTION, &MatrixProjection );
		};
		D3DXVECTOR3 pos,postemp;
		D3DXVECTOR3 look;
		D3DXVECTOR3 Right;
		D3DXMatrixIdentity(&MatrixIdenty);
		switch (_type)
		{
		case TE_GAME:
			{
				if(pMainPlayer->FactRemont)
					if(Otremont>2000) {pMainPlayer->FactRemont=false;pMainPlayer->TimeRemont=TekTime;}
				
		if(predug>StartUgol())
		{
			if(!Pusk)
			{
				Pusk=TRUE;
				TimeStartZabeg=TekTime;
			};
		//поворот игрока от устройств ввода и движение ботов
			if(!pMainPlayer->Finish)
			{
		pMainPlayer->yaw(Inp.Mouse.lX/500.0f);
		pMainPlayer->yaw(Inp.Left/500.0f);
		float forward=Inp.Up/1.0f;
		//перемещение игрока
		pMainPlayer->getPosition(&postemp);
		if((pMainPlayer->beg)&&(!pMainPlayer->FactRemont)) pMainPlayer->walk(forward,Raznica/1.0f);
		pMainPlayer->getPosition(&pos);
		//расположение игрока относительно ландшафта
//		float height = MainMap.getHeight(pos.x, pos.z);
//        pos.y =height + 10.0f;//установка позиции для объекта
		if(getValueGMatrix(pos.x, pos.z)==0)
			pos=postemp;
		int tmpx;
		int tmpy;
		if(((getValueGMatrixSK(pos.x, pos.z,&tmpx,&tmpy)==8)||(getValueGMatrixSK(pos.x, pos.z,&tmpx,&tmpy)==9))&&(Otremont>5000))
		{
			if(getValueGMatrixSK(pos.x, pos.z,&tmpx,&tmpy)==8) pMainPlayer->typeremont=1;
			else pMainPlayer->typeremont=2;
//			pMainPlayer->FactRemont=true;
//			setValueGMatrix(tmpx,tmpy,1);
			pMainPlayer->TimeRemont=TekTime;
			pMainPlayer->Speed=0;

		};
		if(getValueGMatrix(pos.x,pos.z)==5)
		{
			pMainPlayer->Finish=TRUE;
			pMainPlayer->TimeFinish=TekTime;
		};
		pMainPlayer->setPosition(&pos);
			};

			for(int i=0;i<CountPlayers;i++) 
					{
						if (Players[i].Finish)
							continue;
						if(Players[i].FactRemont)
							if((TekTime-Players[i].TimeRemont)>2000) {Players[i].FactRemont=false;Players[i].TimeRemont=TekTime;}

						if((Players[i].beg)&&(!Players[i].FactRemont)){

//						Players[i].yaw(CalcAIPos(Players[i],Raznica));
						Players[i].getPosition(&postemp);
//						Players[i].walk(Raznica/1.0f,Raznica/1.0f);
						Players[i].getPosition(&pos);
						if(getValueGMatrix(pos.x, pos.z)==0)
							pos=postemp;
						if(getValueGMatrix(pos.x, pos.z)==5)
						{pos=postemp;Players[i].beg=false;
						Players[i].Finish=TRUE;
						Players[i].TimeFinish=TekTime;
						}
						if(((getValueGMatrix(pos.x, pos.z)==8)||(getValueGMatrix(pos.x, pos.z)==9))&&((TekTime-Players[i].TimeRemont)>5000))
						{
							Players[i].FactRemont=true;
							Players[i].TimeRemont=TekTime;
							Players[i].Speed=0;
						};

						};


					};
		}
		else
		{//предварительный поворот
			Pusk=FALSE;
			predug+=D3DX_PI*100/1000.0f;
			pMainPlayer->yaw(D3DX_PI*100/1000.0f);
					for(int i=0;i<CountPlayers;i++) 
					{
						Players[i].yaw(D3DX_PI*100/1000.0f);
						
					};
		}
		//расположение игроков относительно ландшафта
//		for(int i=0;i<CountPlayers;i++) 
//		{
//			Players[i].getPosition(&pos);
//			float height = MainMap.getHeight(pos.x, pos.z);
//			pos.y =height + 10.0f;//установка позиции для объекта
//			Players[i].setPosition(&pos);
//		};
		pMainPlayer->getPosition(&pos);
		pMainPlayer->getLook(&look);
		pos-=D3DXVECTOR3(look.x, 0.0f, look.z) * 300;
		pos.y+=50.0f;
	//	float height = MainMap.getHeight(pos.x, pos.z);
//		if ((height+200)>pos.y) pos.y=height+200;
		vid.setPosition(&pos);
		vid.setLook(&look);
		D3DXMatrixTranslation(&Mir.matView,pos.x,pos.y,pos.z);
		vid.getViewMatrix(&MatrixView);
//		m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		m_pd3dDevice->Clear(0, NULL, m_dwClearFlags,D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		m_pd3dDevice->BeginScene();
		m_pd3dDevice->SetLight(0,&Light);
		if(pMainPlayer->FactRemont) m_pd3dDevice->SetRenderState(D3DRS_LIGHTING,TRUE);
		else m_pd3dDevice->SetRenderState(D3DRS_LIGHTING,FALSE);
		m_pd3dDevice->SetTransform(D3DTS_VIEW,&MatrixView);
//		MainMap.draw();
		D3DXMatrixIdentity(&MatrixWorld);
		m_pd3dDevice->SetTransform(D3DTS_WORLD, &MatrixWorld);
		m_pd3dDevice->SetTransform(D3DTS_WORLD, &Mir.matView);
//		if (!(Mir.Render())) 
//			return false;
		m_pd3dDevice->SetTransform(D3DTS_WORLD, &MatrixWorld);
		Trassa->Render();

//		Tree.ReBuild(Raznica);
		pMainPlayer->Draw(m_pd3dDevice);
		for(int i=0;i<CountPlayers;i++) 
			Players[i].Draw(m_pd3dDevice);
//----------------------------------------------
//выводим деревья
//----------------------------------------------
		for(int i=0;i<256;i++)
		{
			for(int j=0;j<256;j++)
			{
				if(getValueGMatrixZ(i,j)==3)
				{
					pos=PosGame(i,j);
//					pos.y=MainMap.getHeight(pos.x, pos.z)+10.0f;
					m_pd3dDevice->SetTransform(D3DTS_WORLD, &MatrixWorld);
					D3DXMatrixTranslation(&MatrixTemp,pos.x,pos.y,pos.z);
					m_pd3dDevice->SetTransform(D3DTS_WORLD,&MatrixTemp);
					pTree->Draw();
				};
			};
		};
//----------------------------------------------
		m_pd3dDevice->SetTransform(D3DTS_WORLD, &MatrixIdenty);
		MyTextOut(pFont,"Скорость: ", 10,550,300,570,0xff00ff00);

		char tmp[17];
		int buf = (int)(pMainPlayer->Speed*10);
		wsprintf(tmp,"%d",buf);
		MyTextOut(pFont,tmp, 150,550,300,570,0xff00ff00);
		m_pd3dDevice->SetRenderState(D3DRS_LIGHTING,FALSE);
		MyTextOut(pFont,"Имя: ", 410,550,500,570,0xff00ff00);
		MyTextOut(pFont,pMainPlayer->NamePlayer, 450,550,600,570,0xff00ff00);
		if(!ActiveZab)
		{
			if(Pusk)
			{
			if((TekTime-TimeStartZabeg)>3000)
			{
				ActiveZab=true;
				TimeStartZabeg=TekTime;
				pMainPlayer->beg=true;
				for(int i=0;i<CountPlayers;i++)
				{
					Players[i].beg=true;
				}
			}
			else
			{
				if((TekTime-TimeStartZabeg)<1000)
					if (pFontSt!=NULL)	MyTextOut(pFontSt,"3", 100,100,700,600,0xffffffff);
				if(((TekTime-TimeStartZabeg)>1000)&&((TekTime-TimeStartZabeg)<2000))
					if (pFontSt!=NULL) MyTextOut(pFontSt,"2", 100,100,700,600,0xffffffff);
				if(((TekTime-TimeStartZabeg)>2000)&&((TekTime-TimeStartZabeg)<3000))
					if (pFontSt!=NULL) MyTextOut(pFontSt,"1", 100,100,700,600,0xffffffff);
			}
			}
		}
		else
		{
			if(pMainPlayer->Finish)
				if (pFontSt!=NULL)	MyTextOut(pFontSt,"Финиш!", 0,100,800,600,0xffffffff);

		if((TekTime-TimeStartZabeg)<1000)
			if (pFontSt!=NULL)	MyTextOut(pFontSt,"GO!", 100,100,700,600,0xffffffff);
		if(pMainPlayer->FactRemont)
			if(pMainPlayer->typeremont==1){
			MyTextOut(pFont,"На кочке ваша обувь повредилась.", 0,400,800,450,0xffffffff);
			MyTextOut(pFont,"Сейчас она ремонтируется в хорошой мастерской Сапожок", 0,450,800,500,0xffffffff);
			}
			else
			{ 
				MyTextOut(pFont,"Вы наступили на лужу и испачкали обувь.", 0,400,800,450,0xffffffff);
				MyTextOut(pFont,"Сейчас она чистится хорошим среством Эффектон", 0,450,800,500,0xffffffff);
			};

		if((!pMainPlayer->FactRemont)&&(Otremont<=5000))
			MyTextOut(pFont,"Ваша обувь приведена в порядок", 150,400,600,600,0xff00ff00);
		};
		if(Finished)
		{
			MyTextOut(pFont,"Место", 150,100,250,150,0xff000000);
			MyTextOut(pFont,"Имя", 250,100,350,150,0xff000000);
			MyTextOut(pFont,"Время", 350,100,450,150,0xff000000);
		

			for(int i=0;i<=CountPlayers;i++)
			{
				wsprintf(tmp,"%d",i+1);
				if(MasYou[i])
				{
					MyTextOut(pFont,tmp, 150,125+i*25,250,150+i*25,0xffff0000);
				}
				else
				{
					MyTextOut(pFont,tmp,150,125+i*25,250,150+i*25,0xff0000ff);
				};

				if(MasYou[i])
				{
					MyTextOut(pFont, MasName[i], 250,125+i*25,350,150+i*25,0xffff0000);
				}
				else
				{
					MyTextOut(pFont, MasName[i], 250,125+i*25,350,150+i*25,0xff0000ff);
				};

				wsprintf(tmp,"%d",(MasTime[i]-TimeStartZabeg)/1000);
				if(MasYou[i])
				{
					MyTextOut(pFont,tmp, 350,125+i*25,450,150+i*25,0xffff0000);
				}
				else
				{
					MyTextOut(pFont,tmp,350,125+i*25,450,150+i*25,0xff0000ff);
				};
					
			};
		};
		m_pd3dDevice->EndScene();
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
			};break;
		case TE_MENU:
			{
				
				if(Inp.Mouse.rgbButtons[0]&0x80) flagm=true;
				else
					if(flagm)
				{   flagm=false;
					int rez=Menu->Click();
					if(rez==0)
					{fail=false;return false;}
					if(rez==1)
					{_type=TE_GAME;
  		D3DXMatrixPerspectiveFovLH(&MatrixProjection, D3DX_PI/2, 800.0f/600.0f, 1, 1000000.0f);
//		D3DXMatrixPerspectiveFovLH(&m_matProj, D3DXToRadian(m_fFOV), m_fAspect, m_fNearPlane, m_fFarPlane);
		m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &MatrixProjection );
						if(!flagz)
							if(!LoadGame()) 
							{
								fail=true;
								return false;
							};
						fail=false;
						if (!GameLoaded)
						{
							StOldTime=TekTime;
							TimeStartZabeg=TekTime;
						};
						return true;}

				};
		Menu->Reset();
		m_pd3dDevice->Clear(0, NULL, m_dwClearFlags,D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		m_pd3dDevice->BeginScene();
 //  UINT  Time  = timeGetTime() % 5000;
 //   FLOAT Angel = Time * (2.0f * D3DX_PI) / 5000.0f;
		FLOAT Angel=0.0f;
D3DXMatrixIdentity(&MatrixWorld);//    D3DXMatrixRotationY( &MatrixWorld, Angel );

    m_pd3dDevice->SetTransform( D3DTS_WORLD, &MatrixWorld );
 
    D3DXMatrixLookAtLH( &MatrixView,  &D3DXVECTOR3 ( 0.0f, 0.0f,-2.5f ),
                                      &D3DXVECTOR3 ( 0.0f, 0.0f, 0.0f ),
                                      &D3DXVECTOR3 ( 0.0f, 1.0f, 0.0f ) );
/*	MatrixView._31=MatrixView._31;
	MatrixView._32=MatrixView._32;
	MatrixView._33=MatrixView._33;
	MatrixView._34=MatrixView._34;*/
    m_pd3dDevice->SetTransform( D3DTS_VIEW, &MatrixView );

	    if(!Menu->Draw(&m_pd3dDevice))return false;
		m_pd3dDevice->EndScene();
		m_pd3dDevice->Present(NULL, NULL, NULL, NULL);

			};break;
		};
}
catch(int e)
{
	return false;
};
return true;
}


VOID GameEngine::Delete()
{
//	MainMap.Delete();
switch (_type)
	{
    case TE_MENU:
	{
//	Menu->Delete();
//	Menu=NULL;
	};break;
    case TE_GAME:
		{
	delete [] Players;
	m_pd3dDevice->Release();
    m_pD3D->Release();
	Inp.DeleteKeyboard();
	Inp.DeleteMouse();
	pMainPlayer->Delete();
	pMainPlayer=NULL;
	};break;
};
//	pPlayers=NULL;

}

BOOL GameEngine::LoadGame()
{
	ActiveZab=false;
	Pusk=false;
D3DXMATRIX MatrixProjection;
srand(time(0));
try
{
	switch (_type)
		{
		case TE_GAME:
			{
  		D3DXMatrixPerspectiveFovLH(&MatrixProjection, D3DX_PI/2, 800.0f/600.0f, 1, 1000000.0f);
//		D3DXMatrixPerspectiveFovLH(&m_matProj, D3DXToRadian(m_fFOV), m_fAspect, m_fNearPlane, m_fFarPlane);
		m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &MatrixProjection );

	D3DXVECTOR3 pos;
	D3DXVECTOR3 look;
	if(!LevelInfo->LoadMap("data\\Levels\\Demo\\index.dat")) return false;
	CountPlayers=4;
	fail=true;
	ofstream OutFile;
	OutFile.open("Debug.log",ios::app);
	OutFile<<"Успешно"<<endl<<"-Загрузка игры..."<<endl<<"--Загрузка трассы... ";
	OutFile.close();
	if(!Trassa->LoadTrassa(LevelInfo->filetrassa,&m_pd3dDevice)) throw 11;
	OutFile.open("Debug.log",ios::app);
	OutFile<<"Успешно"<<endl<<"--Создание игровой матрицы...";
	OutFile.close();
	if(!Trassa->CalcValueMatrix()) throw 200;
	OutFile.open("Debug.log",ios::app);
	OutFile<<"Успешно"<<endl<<endl<<"--Загрузка карты... ";
	OutFile.close();

	if (!(MainMap.Create(m_pd3dDevice,LevelInfo->filemap,256,256,60,4))) throw 11;
	if (!(MainMap.readRawFile(LevelInfo->filemap))) throw 11;
	MainMap.computeVertices();
	MainMap.computeIndices();
	//MainMap.genTexture(&(D3DXVECTOR3(0,200,0)));
	if (!MainMap.loadTexture(LevelInfo->filetexmap,LevelInfo->filetextrassa)) throw 11; 

	OutFile.open("Debug.log",ios::app);
	OutFile<<"Успешно"<<endl<<"--Загрузка объектов... ";
	OutFile.close();
		pos.x=0.0f;
		pos.z=0.0f;
		float ugle=StartUgol();
//		float height = MainMap.getHeight(pos.x, pos.z);
        pos.y =-200.0f;//установка позиции для объекта
		pMainPlayer->setPosition(&pos);
		vid.pitch(0.1f);
	OutFile.open("Debug.log",ios::app);
	OutFile<<ugle<<endl;
	OutFile.close();
	D3DXVECTOR3 postr;
	byte k;
		Players = new GBot[CountPlayers];
				if (!pBoson->Load("data\\Objects\\Bosonog\\bosonogki.x","data\\Objects\\Bosonog\\", &m_pd3dDevice)) throw 12;
				if (!pBotinok->Load("data\\Objects\\Botinok\\bots.x","data\\Objects\\Botinok\\", &m_pd3dDevice)) throw 12;
				if (!pKross->Load("data\\Objects\\Krossov\\cross.x","data\\Objects\\Krossov\\", &m_pd3dDevice)) throw 12;
				if (Menu->NumBot==4)
					k=rand()%3+1;
				else k=Menu->NumBot;
				if ( k==1)
				pMainPlayer->pModel=pBotinok;
				if ( k==2)
				pMainPlayer->pModel=pBoson;
				if ( k==3)
				pMainPlayer->pModel=pKross;
				pMainPlayer->_typeBot=k;
				if (!(pMainPlayer->Load("data\\Objects\\Botinok\\load.txt",&m_pd3dDevice))) throw 12;
				for(int i=0;i<CountPlayers;i++) {
				k=rand()%3+1;
				if ( k==1)
				Players[i].pModel=pBotinok;
				if ( k==2)
				Players[i].pModel=pBoson;
				if ( k==3)
				Players[i].pModel=pKross;
				Players[i]._typeBot=k;
//				Players[i].getPosition(&pos);
//				pos.x+=(i+1)*300;
				postr=pos;
				postr.x+=pow(-1.0f,i)*(150*((i+2)/2));
				Players[i].setPosition(&postr);
				Players[i].Load("data",&m_pd3dDevice);
				Players[i].FactRemont=false;
		};

		if(!pTree->Load("data\\Objects\\Trava\\trava.x","data\\Objects\\Trava\\",&m_pd3dDevice))
			throw 13;
//	Tree.Load("data\\Data\\333.x","data\\Data\\",&m_pd3dDevice)))
//		{fail=true;return FALSE;};
	//Создаем мир
	OutFile.open("Debug.log",ios::app);
	OutFile<<"Успешно"<<endl<<"--Загрузка мира... ";
	OutFile.close();
	if (!(Mir.Load(LevelInfo->fileworld,&m_pd3dDevice)))throw 14;
	OutFile.open("Debug.log",ios::app);
	OutFile<<"Успешно"<<endl<<"-Загрузка игры завершена";
	OutFile.close();
	flagz=true;
	GameLoaded=TRUE;
	Finished=FALSE;
			}; break;
		case TE_MENU:
			{
    D3DXMatrixPerspectiveFovLH( &MatrixProjection, D3DX_PI/4, 1.0f, 1.0f, 100.0f );
    m_pd3dDevice->SetTransform( D3DTS_PROJECTION, &MatrixProjection );

	m_pd3dDevice->Clear(0, NULL, m_dwClearFlags,D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	m_pd3dDevice->BeginScene();

if (pFontZas!=NULL)	MyTextOut(pFontZas,"ДАЙВЕР",0,100,800,300,0xffffffff);
if (pFontZas1!=NULL)	MyTextOut(pFontZas1,"представляет...", 0,300,800,600,0xffffffff);


		m_pd3dDevice->EndScene();
		m_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	Sleep(3000);
	m_pd3dDevice->Clear(0, NULL, m_dwClearFlags,D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	m_pd3dDevice->BeginScene();

	if (pFontZas1!=NULL)	MyTextOut(pFontZas1,"Компьютерная игра:", 0,100,800,300,0xffffffff);
	if (pFontZas1!=NULL)	MyTextOut(pFontZas1,"ОБУВКА ДЛЯ ДАЙВЕРА", 0,300,800,600,0xffffffff);


		m_pd3dDevice->EndScene();
		m_pd3dDevice->Present(NULL, NULL, NULL, NULL);


//				vid.pitch(0.1f);
				Menu->Load(&m_pd3dDevice);
		ofstream OutFile;
	 	OutFile.open("Debug.log",ios::app);
		OutFile<<"Успешно"<<endl<<"-Загрузка меню завершена"<<endl;
		OutFile.close();

			};break;
	};
	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_pd3dDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);

}
catch(int e)
{
	fail=true;
	return false;
};
	fail=false;
	return true;

};

void MyTextOut(ID3DXFont* pFont, char *TextString, long x1, long y1, long x2, long y2, D3DCOLOR TextColor)
{   
   RECT myRect;            //переменная, которая будет задавать область вывода на экран
// координаты прямоугольнка	
   myRect.left   = x1;
   myRect.top    = y1;
   myRect.right  = x2;
   myRect.bottom = y2;
   // Вывод текста
   pFont->DrawText(NULL, TextString, -1,&myRect, DT_CENTER, TextColor);
//   pFont->Release();
};