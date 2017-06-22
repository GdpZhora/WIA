#include "main.h"

//���������� ����������
/*LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVBL = NULL;
LPDIRECT3DTEXTURE9 g_pTexture1 = NULL;
LPDIRECT3DTEXTURE9 g_pTexture2 = NULL;
LPDIRECT3DTEXTURE9 g_pTexture3 = NULL;
LPDIRECT3DTEXTURE9 g_pTexture4 = NULL;
LPDIRECT3DTEXTURE9 g_pTexture5 = NULL;
LPDIRECT3DTEXTURE9 g_pTexture6 = NULL;
LPDIRECT3DTEXTURE9 g_pMap = NULL;*/

//float Land[301][301];

D3DTEXTUREFILTERTYPE CurrentFilter;

WNDCLASSEX wclass;

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	ofstream OutFile;
	OutFile.open("Debug.log");
	OutFile<<"������ ���������..."<<endl;
	OutFile.close();

	HWND hWnd;
	wclass.cbSize = sizeof(WNDCLASSEX);
	wclass.style = CS_DBLCLKS;
	wclass.lpfnWndProc = &MessageProc;
	wclass.cbClsExtra = 0;
	wclass.cbWndExtra = 0;
	wclass.hInstance = hInst;
	wclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wclass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wclass.hbrBackground = GetSysColorBrush(COLOR_APPWORKSPACE);
	wclass.lpszMenuName = NULL;
	wclass.lpszClassName = "WiaClass";
	wclass.hIconSm = NULL;

	if (!::RegisterClassEx(&wclass))
		return 0;

/*		hWnd = ::CreateWindow("WiaClass", "War in Afganistan",
		WS_SYSMENU|WS_OVERLAPPED|WS_MINIMIZEBOX, 0, 0, 800, 600, NULL, NULL,
		hInst, NULL);*/
	if (!(hWnd = CreateWindowEx(NULL,              // ����� ����
                       "WiaClass",         // �����
					   0,                // �������� ����
					   WS_OVERLAPPEDWINDOW | WS_VISIBLE,
					   0,0,	               // ����� ������� ����
					   GetSystemMetrics(SM_CXSCREEN),// ������
					   GetSystemMetrics(SM_CYSCREEN),// ������
					   NULL,	               // ���������� ������������� ���� 
					   NULL,	               // ���������� ����
					   hInst,              // ���������� ���������� ����������
					   NULL)))	               // ��������� �� ������ ����                                            
return 0;


		GameEngine *Game;
//		Game.hIns = &wclass.hInstance;
		Game = new GameEngine;
		Game->Create(hWnd);
		if (Game->fail) {
			Game->Delete();
			::MessageBox(NULL, "������ ������������� DirectX, ��������� ����� �������", "������", MB_ICONERROR);
			return E_FAIL;
		}
	OutFile.open("Debug.log",ios::app);
	OutFile<<"����������..."<<endl;
	OutFile.close();

		if(!(Game->LoadGame()))
		{
			Game->Delete();
			::MessageBox(NULL, "������ �������� ������, ��������� ����� �������", "������", MB_ICONERROR);
			return E_FAIL;
		};
		::ShowWindow(hWnd,SW_SHOWDEFAULT);
		::UpdateWindow(hWnd);

		MSG msg;
	OutFile.open("Debug.log",ios::app);
	OutFile<<"-���������..."<<endl;
	OutFile.close();


		::ZeroMemory(&msg, sizeof(msg));
		while(msg.message != WM_QUIT)
		{		
			if(::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
			
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}
			else 
		if(!(Game->RenderScene()))
		{
			if(Game->fail)
			{
			Game->Delete();
			::MessageBox(NULL, "������ ����������", "������", MB_ICONERROR);
			return E_FAIL;
			}
			Game->Delete();
			break;
		};

		}
	OutFile.open("Debug.log",ios::app);
	OutFile<<"-��������� ��������..."<<endl;
	OutFile.close();

		Game->Delete();
		OutFile.open("Debug.log",ios::app);
	OutFile<<"���������."<<endl;
	OutFile.close();

	return 0;
}

LRESULT CALLBACK MessageProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_KEYDOWN:
		int VK;
		VK = (int)wParam;
/*		switch(VK)
		{
/*		case VK_ESCAPE:
			PostQuitMessage(0);
			return 0;
		}*/
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
};

