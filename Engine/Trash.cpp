
#include "Snake.h"
#include "Trash.h"
#include "Board.h"

void Trash::Piece::InitPiece(Location& loc_in)
{
	loc = loc_in;
	c = trashColor;
}

void Trash::Piece::Draw(Board& brd) const
{
	brd.DrawEdgeCell(loc, c);
}

Location Trash::Piece::GetLoc() const
{
	return loc;
}

Trash::Trash(Location& loc)
{
	pieces[0].InitPiece(loc);
}

void Trash::Draw(Board& brd) const
{
	for (int i = 0; i < numPieces; i++) {
		pieces[i].Draw(brd);
	}
}

void Trash::PolluteMore()
{
	numPieces++;
}

void Trash::AppearNew(Location& loc)
{
	pieces[numPieces - 1].InitPiece(loc);
}

bool Trash::IsEaten(Snake& snake) const
{
	for (int i = 0; i < numPieces; i++) {
		if (snake.getHeadLoc() == pieces[i].GetLoc()) {
			return true;
		}
	}
	return false;

}


