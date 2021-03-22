#pragma once
#include <dinput.h>
#include "GWindow.h"

class GInput
{
private:
	GInput();
	~GInput();
	static GInput* instance;

public:
	static GInput* getInstance();
	static void releaseInstance();

	void update();
	bool isKeyDown(int index);

	LPDIRECTINPUT8 dInput;
	LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
	LPDIRECTINPUTDEVICE8  mouseDevice;
	BYTE  diKeys[256];
	DIMOUSESTATE mouseState;
	HRESULT result;
};

