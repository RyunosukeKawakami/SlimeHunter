#pragma once
#include "Monster.h"
#include <cmath>
class Ghost :public Monster{
private:
	int image[4];
	int init_y;
	int vector_y;
	int speed;
public:
	Ghost();
	virtual ~Ghost();
	void Main();
	void Move();
	void Draw();
	void Delete() {};
};

