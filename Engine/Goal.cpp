#include "Goal.h"
#include "Snake.h"
#include "Board.h"
#include "Colors.h" 
#include <random>

Goal::Goal(Location& loc_in)
{
	locGoal = loc_in;
}

//bool Goal::TestCollision(Snake& snake) const {
//
//	int rightRect = x + width;
//	int rightDude = dude.GetX() + dude.width;
//	int	downRect = y + height;
//	int	downDude = dude.GetY() + dude.height;
//
//	return (rightRect >= dude.GetX()) && (x <= rightDude) && (y <= downDude) && (downRect >= dude.GetY());
//}


void Goal::Draw(Board& brd) const
{

	brd.DrawEdgeCell(locGoal, c);

}

void Goal::Replace(Location& loc)
{
	locGoal = loc;
}

Location Goal::GetLoc() const
{
	return locGoal;
}



