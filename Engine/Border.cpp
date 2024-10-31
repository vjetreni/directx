#include "Border.h"
#include "Board.h"
#include "Snake.h"

Border::Border(int left_in, int right_in, int up_in, int down_in)
{
	left = left_in;
	right = right_in;
	up = up_in;
	down = down_in;
}

void Border::Draw(Board& brd) const
{
	for (int i = left; i < right; i++) {
		Location loc1 = {i, up};
		Location loc2 = { i, down - 1 };
		brd.DrawFullCell(loc1, Colors::Magenta);
		brd.DrawFullCell(loc2, Colors::Magenta);
	}

	for (int i = up; i < down; i++) {
		Location loc1 = { left, i };
		Location loc2 = { right - 1, i };
		brd.DrawFullCell(loc1, Colors::Magenta);
		brd.DrawFullCell(loc2, Colors::Magenta);
	}
}

bool Border::isHit(Snake& snake) const
{
	return ((snake.getHeadLoc().x == left) || (snake.getHeadLoc().x == right - 1) ||
		(snake.getHeadLoc().y == up) || (snake.getHeadLoc().y == down-1));
}



