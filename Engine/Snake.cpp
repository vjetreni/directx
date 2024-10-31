#include "Snake.h"
#include "assert.h"
#include "Goal.h" 
#include "Location.h"
#include "Board.h"
#include "Border.h"

Snake::Snake(Location& loc)
{
	segments[0].InitHead( loc );
}

void Snake::Draw(Board& brd)
{
	for (int i = 1; i < numberSegments; i++ ) {
		segments[i].InitBody(i);
		segments[i].Draw(brd);
	}
	segments[0].Draw(brd);
}

void Snake::MoveBy(Location& delta_loc)
{
	for (int i = numberSegments - 1; i > 0; i--) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
	
}

void Snake::Grow()
{
	if (numberSegments < numberSegmentsMax){
		numberSegments++;
	}
}

void Snake::Segment::InitHead(Location& loc_in)
{
	loc = loc_in;
	c = colorHead;
}

void Snake::Segment::InitBody(int i)
{
	switch (i % 3){
	case 0: 
		c = colorBody0;
		break;
	case 1:
		c = colorBody1;
		break;
	case 2:
		c = colorBody2;
		break;
	}
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawEdgeCell(loc, c);
}

void Snake::Segment::Follow(Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) <= 1);
	loc.Add(delta_loc);
}

Location Snake::Segment::GetLoc() const
{
	return loc;
}

bool Snake::isEaten(Location& loc_in) const
{
	return segments[0].GetLoc() == loc_in;
}

bool Snake::isBitten()
{
	for (int i = 1; i < numberSegments; i++) {
		if (segments[0].GetLoc() == segments[i].GetLoc()) {
			return true;
		}
	}
	return false;
}


Location Snake::getHeadLoc() const
{
	return segments[0].GetLoc();
}


