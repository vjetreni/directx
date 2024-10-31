#pragma once

#include "Board.h"
#include "Graphics.h"

class Location {
public:

	void Add(Location& loc) {

		if (x + loc.x == borderWidth) {
			x = 0;
		}
		else if (x + loc.x == -1) {
			x = borderWidth - 1;
		}
		else {
			x = x + loc.x;
		}
		if (y + loc.y == borderHeight) {
			y = 0;
		}
		else if (y + loc.y == -1) {
			y = borderHeight - 1;
		}
		else {
			y = y + loc.y;
		}
	}
	bool operator==(Location& rhs){
		return x == rhs.x && y == rhs.y;
	}

	int x;
	int y;

	int dimension = 20;
	int borderWidth = Graphics::ScreenWidth / dimension;
	int borderHeight = Graphics::ScreenHeight / dimension;
};