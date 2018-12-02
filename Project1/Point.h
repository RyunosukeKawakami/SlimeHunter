#ifndef _POINT_
#define _POINT_

struct Point{
    int x,y;
    int x2,y2;
public:
	Point() {};
	Point(int a, int b, int width)
	{
		x = a;
		y = b;
		x2 = x + width;
		y2 = y + width;
	};

	void operator=(Point& a) {
		x = a.x;
		y = a.y;
		x2 = a.x2;
		y2 = a.y2;
	};
};

#endif