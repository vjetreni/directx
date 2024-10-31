#pragma once

#include "Board.h"
#include "Snake.h"

class Border {

public:
	Border(int left_in, int right_in, int up_in, int down_in);
	void Draw(Board& brd) const;
	bool isHit(Snake& snake) const;

private:
	int left;
	int right;
	int up;
	int down;

};


