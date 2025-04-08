#pragma once
#include "Vector2d.h"

class Cell
{
	
public:
	Cell(int x = 0, int y = 0);
	Cell(Vector2d pos);

	Vector2d pos;
};

