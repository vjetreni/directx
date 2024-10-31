/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Location.h"
#include "Snake.h"
#include "Goal.h"
#include "Border.h"
#include "Trash.h"
#include <random>



class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

	Board board;
	std::random_device rd;
	std::mt19937 rng;

	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;


	Location start_loc = { 5,5 };
	Location delta_loc = { 1,0 };

	Location locGoal = {xDist(rng), yDist(rng)};
	Location locNewTrash = { xDist(rng), yDist(rng) };
	Snake snake;
	Goal goal;
	Border border;
	Trash trash;

	int snakeRatePeriod = 10;
	int snakeRateCounter = 0;

	int trashAppearanceRate = 100;
	int trashAppearanceCounter = 0;

	int GameStart = 0;
	int GameOver = 0;

	/********************************/

	
};