//модуль класса обработки устройств ввода

#ifndef GINPUT_H
#define GINPUT_H

#include "main.h"


class CGInput
{
public:
	CGInput();
	~CGInput();
	LPDIRECTINPUT8 pInput;
	LPDIRECTINPUTDEVICE8 pKeyboard;
	LPDIRECTINPUTDEVICE8 pMouse;
	int GCreateInput(HINSTANCE **phinstanceMain);
	int CreateKeyboard(HWND);
	int CreateMouse(HWND);
	int Reset();
	int Reread();
	void DeleteKeyboard();
	void DeleteMouse();
	long Up;
	long Left;
	unsigned long OldTime;
	bool Esc;
//private:
	 
	HINSTANCE *phMain;
	char Keyboard[256];
	DIMOUSESTATE Mouse;

};

#endif
