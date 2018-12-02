#pragma once
#include "Point.h"
#include "DxLib.h"

class Weapon{
private:
	Point p;
	int vectorr;
	int image;
	double angle;
	enum {
		RIGHT,
		LEFT,
		UP,
		DOWN,
		STOP
	};
public:
	Weapon(Point, int vector);
	virtual~Weapon();
	void Move(Point speed ,int vector);
	void Draw(); 
	Point SetPoint();
};

