#pragma once
#include "Board.h"
#include "Goal.h"

class Snake {
private:
	class Segment {
	public:
		void InitHead(Location& loc_in);
		void InitBody(int i);
		void Draw(Board& brd) const;
		void Follow( Segment& next);
		void MoveBy(Location& delta_loc);
		//bool TestCollision(Location& loc_in) const;
		Location GetLoc() const;

	private:
		Location loc;
		Color c;
	};
public:
	Snake(Location& loc);
	void Draw(Board& brd);
	void MoveBy(Location& delta_loc);
	void Grow();
	bool isEaten(Location& loc_in) const;
	bool isBitten();
	Location getHeadLoc() const;

private:
	static constexpr int numberSegmentsMax = 100;
	static constexpr Color colorHead = Colors::Blue;
	static constexpr Color colorBody0 = Colors::Green;
	static constexpr Color colorBody1 = Colors::MakeRGB(0u, 200u, 0u);
	static constexpr Color colorBody2 = Colors::MakeRGB(0u, 100u, 0u);
	Segment segments[numberSegmentsMax];
	int numberSegments = 1;
};