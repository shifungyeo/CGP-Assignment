#pragma once
#include <stdio.h>
#include "GameState.h"
#include "GGraphic.h"
#include "GInput.h"

class GameLevel
{
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE sprite;
	LPD3DXLINE line;
	LPD3DXFONT font;
	RECT spriteRect;
	RECT textRect;
	RECT rectList[16];
	int rectIndex = 0;
	HRESULT hr;
	D3DXVECTOR2 characterSize;
	int animationFrame;

public:
	GameLevel();
	~GameLevel();

	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
};

