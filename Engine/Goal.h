#pragma once

#include "Snake.h"
#include "Colors.h"


class Goal{

public:
	Goal(Location& loc);
	//bool TestCollision(Snake& snake) const;
	void Draw(Board& brd) const;
	void Replace(Location& loc);
	Location GetLoc() const;

private:

	Location locGoal;
	static constexpr Color c = Colors::Red;

};