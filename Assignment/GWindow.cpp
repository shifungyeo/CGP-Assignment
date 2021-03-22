#include "GWindow.h"

int GWindow::keyPressed = 0;

//	Window Procedure, for event handling
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		//	The message is post when we destroy the window.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			exit(1);
		}
		GWindow::keyPressed = wParam;
		break;

		//	Default handling for other messages.
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
//--------------------------------------------------------------------

GWindow::GWindow() {

	HINSTANCE hInstance = GetModuleHandle(NULL);

	//	Set all members in wndClass to 0.
	ZeroMemory(&wndClass, sizeof(wndClass));

	//	Filling wndClass. You are to refer to MSDN for each of the members details.
	//	These are the fundamental structure members to be specify, in order to create your window.
	wndClass.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
	//wndClass.hIcon = LoadIcon(GetModuleHandle(NULL), NULL);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hInstance = hInstance;	//	GetModuleHandle(NULL);
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "My Window";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//	Register the window.
	RegisterClass(&wndClass);

	//  Create the window.
	//	You are to refer to MSDN for each of the parameters details.
	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "My Window's Name", WS_OVERLAPPEDWINDOW, 0, 100, 800, 900, NULL, NULL, hInstance, NULL);
	ShowWindow(g_hWnd, 1);

	//	Some interesting function to try out.
	//	ShowCursor(false);

	ZeroMemory(&msg, sizeof(msg));

}

int GWindow::messageLoop() {

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT) break;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return msg.message != WM_QUIT;
}

GWindow::~GWindow() {

	UnregisterClass(wndClass.lpszClassName, hInstance);
}

GWindow* GWindow::instance = NULL;

GWindow* GWindow::getInstance() {
	if (instance == NULL) {
		instance = new GWindow();
	}
	return instance;
}

void GWindow::releaseInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}