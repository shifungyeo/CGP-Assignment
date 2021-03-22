#include "GGraphic.h"

GGraphic::GGraphic() {
	direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	ZeroMemory(&d3dPP, sizeof(d3dPP));

	d3dPP.Windowed = true;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = 800;
	d3dPP.BackBufferHeight = 900;
	d3dPP.hDeviceWindow = GWindow::getInstance()->g_hWnd;

	HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GWindow::getInstance()->g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);
}

GGraphic::~GGraphic() {
	//	Release the device when exiting.
	d3dDevice->Release();
	//	Reset pointer to NULL, a good practice.
	d3dDevice = NULL;
}

GGraphic* GGraphic::instance = NULL;

GGraphic* GGraphic::getInstance() {
	if (instance == NULL) {
		instance = new GGraphic();
	}
	return instance;
}

void GGraphic::releaseInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}

void GGraphic::begin() {
	//	Clear the back buffer.
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//	Begin the scene
	d3dDevice->BeginScene();
}

void GGraphic::end() {
	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}