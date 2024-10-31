#pragma once

#include "Location.h"
#include "Graphics.h"

class Board {

public:
	Board(Graphics& gfx);
	void DrawFullCell(const Location& loc, Color c);
	void DrawEdgeCell(const Location& loc, Color c);
	static int GetWidth();
	static int GetHeight();

private:
	static constexpr int dimension = 20;
	static constexpr int width = Graphics::ScreenWidth / dimension;
	static constexpr int height = Graphics::ScreenWidth / dimension;
	Graphics& gfx;

};