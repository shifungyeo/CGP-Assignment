#include "GInput.h"

GInput::GInput() {
	DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);
	dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);
	dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	dInputKeyboardDevice->SetCooperativeLevel(GWindow::getInstance()->g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	dInput->CreateDevice(GUID_SysMouse, &mouseDevice, NULL);
	mouseDevice->SetDataFormat(&c_dfDIMouse);
	mouseDevice->SetCooperativeLevel(GWindow::getInstance()->g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	ZeroMemory(diKeys, sizeof(diKeys));
	ZeroMemory(&mouseState, sizeof(mouseState));
}

GInput::~GInput() {
	dInputKeyboardDevice->Unacquire();
	dInputKeyboardDevice->Release();
	dInputKeyboardDevice = NULL;
	dInput->Release();
	dInput = NULL;
}

GInput* GInput::instance = NULL;

GInput* GInput::getInstance() {
	if (instance == NULL) {
		instance = new GInput();
	}
	return instance;
}

void GInput::releaseInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}

void GInput::update() {
	result = dInputKeyboardDevice->GetDeviceState(256, diKeys);
	if (FAILED(result))
	{
		if ((result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED))
		{
			dInputKeyboardDevice->Acquire();
		}
	}

	result = mouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&mouseState);
	if (FAILED(result))
	{
		if ((result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED))
		{
			mouseDevice->Acquire();
		}
	}
}

bool GInput::isKeyDown(int index) {
	return diKeys[index] & 0x80;
}