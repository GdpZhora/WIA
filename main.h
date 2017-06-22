#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <mmsystem.h>
#include <d3dx9math.h>
#include <d3dx9core.h>
#include <stdlib.h>
#include <math.h>
#include <dinput.h>
#include <vector>
#include <io.h>
//#include "Common\Direct3D.h"
#include "Engine.h"
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

//Прототипы функций
//ваще эти функции кажись почти все ненужны
//VOID InitLand(void);
LRESULT CALLBACK MessageProc(HWND,UINT,WPARAM,LPARAM);
/*BOOL Initialization(HWND);
VOID Deinitialization(void);
BOOL InitD3D(HWND);
BOOL InitTexture(void);
BOOL InitScene(void);
VOID DoMatrices(void);
VOID RenderScene(void);*/

//ID3DXFont*          g_pFont = NULL;

#define D3DFVF_VERTEXWORLD (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_TEX1)

#endif