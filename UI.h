#ifndef _UI_
#define _UI_
#include "Point.h"
#include "DxLib.h"

class UI{
protected:
	Point p;
	int image;
	int color;

public: 
	virtual void Draw() = 0;
};

#endif