#pragma once

struct Point{
    int x,y;
    int x2,y2;
public:
	void operator=(Point& a) {
		x = a.x;
		y = a.y;
		x2 = a.x2;
		y2 = a.y2;
	};
};