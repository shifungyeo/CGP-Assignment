#include "GLevel.h"

GameLevel::GameLevel() {

}
GameLevel::~GameLevel() {

}

void GameLevel::init() {
	hr = D3DXCreateTextureFromFile(GGraphic::getInstance()->d3dDevice, "Gamebg.jpg", &texture);

	hr = D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);

	spriteRect.left = 0;
	spriteRect.top = 0;
	spriteRect.right = spriteRect.left + characterSize.x;
	spriteRect.bottom = spriteRect.top + characterSize.y;
}

void GameLevel::update() {

}

void GameLevel::fixedUpdate() {

}

void GameLevel::draw() {
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();
}

void GameLevel::release() {
	sprite->Release();
	sprite = NULL;
	texture->Release();
	texture = NULL;
}