#include "Vector2d.h"

Vector2d::Vector2d(int x, int y)
	: x(x), y(y)
{
}

void Vector2d::setX(int x) {
	this->x = x;
}

void Vector2d::setY(int y) {
	this->y = y;
}

int Vector2d::getX() const {
	return x;
}

int Vector2d::getY() const {
	return y;
}

bool Vector2d::operator == (const Vector2d& o) {
	return (o.x == x && o.y == y);
}

Vector2d Vector2d::operator + (const Vector2d& o) {
	int _y = y + o.y;
	int _x = x + o.x;
	return { _x, _y };
}

Vector2d Vector2d::operator - (const Vector2d& o) {
	int _y = y - o.y;
	int _x = x - o.x;
	return { _x, _y };
}