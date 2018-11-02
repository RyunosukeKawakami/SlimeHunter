#pragma once
#include "DxLib.h"
#include "Point.h"

class UI{
protected:
    Point draw;
	int image;
	int color;
public: 
	virtual void Draw() = 0;
};