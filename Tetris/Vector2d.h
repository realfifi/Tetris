#pragma once
class Vector2d
{
	int x, y;
public:
	Vector2d(int x = 0, int y = 0);
	
	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;

	bool operator == (const Vector2d& o) const;
	Vector2d operator + (const Vector2d& o);
	Vector2d operator - (const Vector2d& o);
};

