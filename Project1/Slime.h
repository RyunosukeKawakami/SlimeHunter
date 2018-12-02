#pragma once
#include "Monster.h"
#include "Collision.h"

class Slime : public Monster{
private:
	int temp;
	int image[4];
public:
	Slime();
	virtual ~Slime();
	void Main();
	void Generate();
	void Move();
	void Draw();
	void Temp();
	void Damage();
	void Delete() {};
};

