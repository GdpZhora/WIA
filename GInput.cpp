#include "main.h"
#define KEYDOWN(name,key) (name[key]&0x80)


CGInput::~CGInput()
{
	pInput = NULL;
	pKeyboard = NULL;
	pMouse = NULL;
};

int CGInput::GCreateInput(HINSTANCE** phinstanceMain)
{		
/*	if (*phinstanceMain=NULL)
	{
		::MessageBox(NULL, "Пустое", "Ошибка", MB_ICONERROR);
		return 0;
	}*/
	OldTime=timeGetTime();
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&pInput, NULL)))
		return 0;
	if (pInput==NULL) 
	{
		::MessageBox(NULL, "Плохи дела!!!", "Ошибка", MB_ICONERROR);
		return 0;
	};
	return 1;
};

CGInput::CGInput()
{
	pInput = NULL;
	pKeyboard = NULL;
	pMouse = NULL;
	Up=0;
	Left=0;
};

int CGInput::CreateKeyboard(HWND hwn)
{
	HRESULT hr;

	hr=pInput->CreateDevice(GUID_SysKeyboard,&pKeyboard,NULL);
	if FAILED(hr)
	{
		DeleteKeyboard();
		return FALSE;
	}

	hr=pKeyboard->SetDataFormat(&c_dfDIKeyboard);
	if FAILED(hr)
	{
		DeleteKeyboard();
		return FALSE;
	}

	hr=pKeyboard->SetCooperativeLevel(hwn,DISCL_FOREGROUND|DISCL_NONEXCLUSIVE);
	if FAILED(hr)
	{
		DeleteKeyboard();
		return FALSE;
	}
	hr=pKeyboard->Acquire();
	if FAILED(hr)
	{
		DeleteKeyboard();
		return FALSE;
	};

	return TRUE;
};

int CGInput::CreateMouse(HWND hwn)
{
	HRESULT hr;
	hr=pInput->CreateDevice(GUID_SysMouse,&pMouse,NULL);
	if FAILED(hr)
	{
		DeleteMouse();
		return FALSE;
	}
	hr=pMouse->SetDataFormat(&c_dfDIMouse);
	if FAILED(hr)
	{
		DeleteMouse();
		return FALSE;
	}
	hr=pMouse->SetCooperativeLevel(hwn,DISCL_FOREGROUND|DISCL_NONEXCLUSIVE);//DISCL_FOREGROUND|DISCL_EXCLUSIVE);
	if FAILED(hr)
	{
		DeleteMouse();
		return FALSE;
	}
	hr=pMouse->Acquire();
	if FAILED(hr)
	{
		DeleteMouse();
		return FALSE;
	};
		return TRUE;
};

void CGInput::DeleteKeyboard()
{
	if(pKeyboard!=NULL)
		pKeyboard->Unacquire();
	if(pKeyboard!=NULL)
		pKeyboard->Release();
	pKeyboard=NULL;
};

void CGInput::DeleteMouse()
{
	if(pMouse!=NULL)
		pMouse->Unacquire();
	if(pMouse!=NULL)
		pMouse->Release();
	pMouse=NULL;
};

int CGInput::Reset()
{
	DWORD NewTime=timeGetTime();
	if (FAILED(pMouse->GetDeviceState(sizeof(DIMOUSESTATE),(LPVOID)&Mouse)))
	{
		::MessageBox(NULL, "Fatal Error", "Жалко", MB_ICONERROR);
		return E_FAIL;
	}
	if (FAILED(pKeyboard->GetDeviceState(sizeof(Keyboard),(LPVOID)&Keyboard)))
	{
		::MessageBox(NULL, "Fatal Error", "Жалко", MB_ICONERROR);
		return E_FAIL;
	}
/*	if (Up>0) Up=timeGetTime()-Up;
	if (Up<0) Up=-(timeGetTime()+Up);
	if (Left>0) Left=timeGetTime()-Left;
	if (Left<0) Left=-(timeGetTime()+Left);*/
	if (KEYDOWN(Keyboard,DIK_UP)) Up=NewTime-OldTime;
		else 
		{if (KEYDOWN(Keyboard,DIK_DOWN)) Up=-(NewTime-OldTime);
		else Up=0;}

	if (KEYDOWN(Keyboard,DIK_LEFT)) Left=-(NewTime-OldTime);
	else
	{if (KEYDOWN(Keyboard,DIK_RIGHT)) Left=NewTime-OldTime;
				else Left=0;}

	OldTime=NewTime;
	Esc=KEYDOWN(Keyboard,DIK_ESCAPE);
	
	return TRUE;

};

int CGInput::Reread()
{
	if (KEYDOWN(Keyboard,DIK_UP)) {Up=timeGetTime();}
//	::MessageBox(NULL, "Ошибка ренедеринга ландщафта", "Ошибка", MB_ICONERROR);}
		else 
		{if (KEYDOWN(Keyboard,DIK_DOWN)) Up=-timeGetTime();
		else Up=0;}
	if (KEYDOWN(Keyboard,DIK_LEFT)) Left=-timeGetTime();
	else
	{if (KEYDOWN(Keyboard,DIK_RIGHT)) Left=timeGetTime();
				else Left=0;}
	return TRUE;
};