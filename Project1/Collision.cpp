#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

bool Collision::Main(Point a, Point b)
{
	if (Distance(a,b))
		return Temp(a,b);
	else
		return false;
}

bool Collision::Distance(Point a, Point b)
{
	bool x;
	bool y;

	x = a.x - 32 * 4 < b.x < a.x + 32 * 4;
	y = a.y - 32 * 4 < b.y < a.y + 32 * 4;

	if (x == true && y == true)
		return true;
	else
		return false;
}

bool Collision::Temp(Point a, Point b)
{
	bool x;
	bool y;

	x = a.x2 >= b.x && a.x <= b.x2;
	y = a.y2 >= b.y && a.y <= b.y2;

	if (x == true && y == true)
		return true;
	else
		return false;
}
