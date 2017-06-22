/*
Заголовчный файл, в котором объявлен класс самого ядра движка
Engine.h
*/
#ifndef ENGINE_H
#define ENGINE_H

//#include "main.h"
#include"Left/Direct3D.h"
#include"Left/XFile.h"
#include"Left/XParser.h"
#include "terrain.h"
#include "camera.h"
#include "world.h"
#include "GInput.h"
#include "GObjects.h"
#include "GPlayer.h"
#include "GMenu.h"
#include "GMatrix.h"
#include "GAI.h"
#include "GTrassa.h"
#include "GLevel.h"


typedef GBot* pGBot; 


class GameEngine //класс ядра движка
{
public:
	enum TypeEngine {TE_MENU, TE_GAME, TE_LOAD};
	GameEngine();//Конструктор класса
	void Create(HWND hWnd);
	VOID Delete();
	BOOL LoadGame();//Загрузка данных об игре
	BOOL RenderScene();//рендеринг графики
	long BTime;
	bool fail;//переменная для определении провала при работе движка
	HINSTANCE* hIns;
private:
	DWORD TimeStartZabeg;//Время начала забега
	bool ActiveZab;//Активность забега
	bool Pusk;//флаг запуска отсчёта
	LPDIRECT3D9 m_pD3D;//Объект Direct3D
	LPDIRECT3DDEVICE9 m_pd3dDevice;//Устройство Direct3D
	CGInput Inp; //объект устройств ввода
	CTerrain MainMap;//объект ландшафта
	int CountPlayers;//количество игроков
	GObj *pTree;//дерево
	GBot *pMainPlayer;//объект игрока
	pGBot Players;//игроки
	CCamera vid;
	CWorld Mir;//объект мира
	D3DLIGHT9 Light;
	TypeEngine _type;
	GMenuClass* Menu;
	GObj *pBotinok;
	GObj *pBoson;
	GObj *pKross;
	ID3DXFont* pFont;
	ID3DXFont* pFontSt;
	LevelClass* LevelInfo;
	GTrassaClass* Trassa;
	enum ModeGame {MG_SINGLE,MG_MULTI};
	enum ModeMulti {MM_SERVER,MM_CLIENT};
	bool GameLoaded;
	bool Finished;
	DWORD TimeFinished;

};

void MyTextOut(ID3DXFont* pFont,char *TextString, long x1, long y1, long x2, long y2, D3DCOLOR TextColor);

#endif