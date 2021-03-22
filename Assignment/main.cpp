#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "GWindow.h"
#include "GGraphic.h"
#include "GInput.h"
#include "menu.h"
#include "GLevel.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	GWindow* gWindow = GWindow::getInstance();
	GGraphic* gGraphic = GGraphic::getInstance();
	GInput* gInput = GInput::getInstance();

	Menu* menu = new Menu();
	menu->init();
	GameLevel* gLevel = new GameLevel();
	gLevel->init();

	int currentState = 1;

	while (gWindow->messageLoop())
	{
		gInput->update();

		if (gInput->isKeyDown(DIK_L))
		{
			currentState = 1;
		}
		else if (gInput->isKeyDown(DIK_K))
		{
			currentState = 2;
		}

		switch (currentState)
		{
		case 1: menu->update(); break;
		case 2: gLevel->update(); break;
		default: break;
		}
		
		gGraphic->begin();

		switch (currentState)
		{
		case 1: menu->draw(); break;
		case 2: gLevel->draw(); break;
		default: break;
		}

		gGraphic->end();

	}

	menu->release();
	delete menu;
	gLevel->release();
	delete gLevel;

	GInput::releaseInstance();
	GGraphic::releaseInstance();
	GWindow::releaseInstance();

	return(0);
}