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
#include <random>
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	board(gfx),
	rng(rd()),
	snake(start_loc),
	xDist(1, 38), //because of borders
	yDist(1, 28), //because of borders
	goal(locGoal),
	border(0, 40, 0, 30),
	trash(locNewTrash)
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
	//frameTimer
	const float dt = frameTimer.Mark();

	if ((GameStart) && (!GameOver)) {

		delta_loc = DetermineDirection();

		//trash
		if (trashAppearanceCounter >= trashAppearanceRatePeriod) {
			trashAppearanceCounter = 0.0f;
			trash.PolluteMore();
			locNewTrash = { xDist(rng), yDist(rng) };
			trash.AppearNew(locNewTrash);
		}
		else {
			trashAppearanceCounter += 1.0f * dt * 60;
		}


		//snake
	    //snake rate
		if (snakeRateCounter >= snakeRatePeriod) {
			snakeRateCounter = 0.0f;
			//goal
			if (snake.isEaten(goal.GetLoc())) {
				snake.Grow();
				snakeRatePeriod = std::max(snakeRatePeriod - 1.0f * dt * 60, 0.0f);
				locGoal = { xDist(rng), yDist(rng) };
				goal.Replace(locGoal);
			}
			snake.MoveBy(delta_loc);
			//failure test
			if ((snake.isBitten()) || (border.isHit(snake)) || (trash.IsEaten(snake))) {
				GameOver = 1;
			}
		}
		else {
			snakeRateCounter += 1.0f * dt * 60;
		}
		
	}
	else {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			GameStart = 1;
		}
	}
}
Location Game::DetermineDirection()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		delta_loc = { -1 ,0 };
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		delta_loc = { 1 , 0 };
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		delta_loc = { 0, 1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		delta_loc = { 0,-1 };
	}

	return delta_loc;
}
void Game::ComposeFrame()
{
	if ((GameStart) && (!GameOver)) {
		
		snake.Draw(board);
		goal.Draw(board);
		border.Draw(board);
		trash.Draw(board);
	}
	else if (GameOver) {
		SpriteCodex::DrawGameOver(300, 250, gfx);
	}
	else if (!GameStart){
		SpriteCodex::DrawTitle(250, 250, gfx);
	}
}

