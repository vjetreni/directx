#include "Board.h"
#include "assert.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{}

void Board::DrawFullCell( const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension , dimension, dimension, c);
}

void Board::DrawEdgeCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * dimension + 2, loc.y * dimension + 2, dimension - 4, dimension - 4, c);
}

int Board::GetWidth()
{
	return width;
}

int Board::GetHeight()
{
	return height;
}


