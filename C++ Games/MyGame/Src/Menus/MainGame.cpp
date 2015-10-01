#include "MainGame.h"
#include "App.h"
#include "stdincl.h"

REGISTERIMPL(MainGame);

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}


void MainGame::Update(float dtime)
{
	if (g_input->WasPressedThisTurn(KEY_P))
	{
		g_menuHandler->SwitchMenu(GAME_PAUSED_MENU);
	}
}

void MainGame::PostUpdate(float dtime)
{
}
