#pragma once
#include "Box.h"

class Soil : public Box{
private:
public:
	Soil(int x,int y){
		color = GetColor(0,255,0);
		draw.x = 32 * x;
		draw.y = 32 * y;
		draw.x2 = draw.x + 32;
		draw.y2 = draw.y + 32;
	}
	void Draw() {
		DrawBox(draw.x, draw.y, draw.x2, draw.y2, color, FALSE);
	}
};