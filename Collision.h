#pragma once
#include"Point.h"

class Collision{
private:

public:
	Collision();
	~Collision();
	bool Main(Point a, Point b);
	bool Distance(Point a, Point b);
	bool Temp(Point a, Point b);
};

