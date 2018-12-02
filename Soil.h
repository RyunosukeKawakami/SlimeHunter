#ifndef _SOIL_
#define _SOIL_
#include "Box.h"

class Soil : public Box{
private:
	int r, g, b;
public:
	Soil(int x,int y){
		color = GetColor(0,255,0);
		p.x = 32 * x;
		p.y = 32 * y;
		p.x2 = p.x + 32;
		p.y2 = p.y + 32;
	}
	void Draw() {
		DrawBox(p.x, p.y, p.x2, p.y2, color, FALSE);
	}
};
#endif