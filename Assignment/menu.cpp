#include "menu.h"

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::init() {
	hr = D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);

	hr = D3DXCreateFont(GGraphic::getInstance()->d3dDevice, 25, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &font);

	textRect.left = 300;
	textRect.top = 700;
	textRect.right = 400;
	textRect.bottom = 800;
}

void Menu::update() {

}

void Menu::fixedUpdate() {

}

void Menu::draw() {
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->Draw(texture, &spriteRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	font->DrawText(sprite, "START", 30, &textRect, 0, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();
}

void Menu::release() {
	sprite->Release();
	sprite = NULL;
	font->Release();
	font = NULL;
}