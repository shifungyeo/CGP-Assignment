#pragma once
#include <Windows.h>

class GWindow
{
private:
	GWindow();
	~GWindow();
	static GWindow* instance;


public:
	static GWindow* getInstance();
	static void releaseInstance();
	int messageLoop();

	static int keyPressed;

	HWND g_hWnd = NULL;
	WNDCLASS wndClass;
	MSG msg;
	HINSTANCE hInstance;
};

