#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "GWindow.h"

class GGraphic
{
private:
	GGraphic();
	~GGraphic();
	static GGraphic* instance;


public:
	static GGraphic* getInstance();
	static void releaseInstance();

	void begin();
	void end();

	IDirect3D9* direct3D9;
	D3DPRESENT_PARAMETERS d3dPP;
	IDirect3DDevice9* d3dDevice;
};

