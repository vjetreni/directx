#pragma once

#include "Snake.h"
#include "Colors.h"
#include "Board.h"


class Trash {

private:
	class Piece {

	public:
		void InitPiece(Location& loc_in);
		void Draw(Board& brd) const;
		Location GetLoc() const;

	private:
		Color c;
		Location loc;
	};

public:
	Trash(Location& loc);
	void Draw(Board& brd) const;
	void PolluteMore();
	void AppearNew(Location& loc);
	bool IsEaten(Snake& snake) const;

private:

	int numPieces = 1;
	static constexpr int maxNumPieces = 50;
	Piece pieces[maxNumPieces];
	static constexpr Color trashColor = Colors::Gray;

};