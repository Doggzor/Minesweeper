/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	menu(gfx.Center() - Location(Menu::btn_width / 2, Menu::btn_height / 2 * 5))
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	switch (state)
	{
	case State::Selection:
		if (!menu.isInitialized()) menu.Update(wnd.mouse);
		else if (menu.isInitialized() && board == nullptr)
		{
			board = new Board(menu.getColumns(), menu.getRows(), menu.getMines(), gfx);
			state = State::Playing;
		}
		break;
	case State::Playing:
		board->Update(wnd.mouse);
		if (board->isGameOver())
		{
				if(wnd.mouse.LeftIsPressed() && !bLMB_inhibited) state = State::Over;
				else if (wnd.mouse.RightIsPressed() && !bRMB_inhibited)
				{
					state = State::Over;
					menu.Reset();
				}
		}
		break;
	case State::Over:
			delete board;
			board = nullptr;
			state = State::Selection;
		break;
	}

	bLMB_inhibited = wnd.mouse.LeftIsPressed();
	bRMB_inhibited = wnd.mouse.RightIsPressed();
}

void Game::ComposeFrame()
{
	if (!menu.isInitialized()) menu.Draw(gfx);
	if (state != State::Selection) board->Draw(gfx);
}

