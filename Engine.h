/*
����������� ����, � ������� �������� ����� ������ ���� ������
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


class GameEngine //����� ���� ������
{
public:
	enum TypeEngine {TE_MENU, TE_GAME, TE_LOAD};
	GameEngine();//����������� ������
	void Create(HWND hWnd);
	VOID Delete();
	BOOL LoadGame();//�������� ������ �� ����
	BOOL RenderScene();//��������� �������
	long BTime;
	bool fail;//���������� ��� ����������� ������� ��� ������ ������
	HINSTANCE* hIns;
private:
	DWORD TimeStartZabeg;//����� ������ ������
	bool ActiveZab;//���������� ������
	bool Pusk;//���� ������� �������
	LPDIRECT3D9 m_pD3D;//������ Direct3D
	LPDIRECT3DDEVICE9 m_pd3dDevice;//���������� Direct3D
	CGInput Inp; //������ ��������� �����
	CTerrain MainMap;//������ ���������
	int CountPlayers;//���������� �������
	GObj *pTree;//������
	GBot *pMainPlayer;//������ ������
	pGBot Players;//������
	CCamera vid;
	CWorld Mir;//������ ����
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