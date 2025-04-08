#include "Cell.h"

Cell::Cell(int x, int y) 
	: pos({x, y})
{

}

Cell::Cell(Vector2d pos)
	: pos(pos)
{

}
