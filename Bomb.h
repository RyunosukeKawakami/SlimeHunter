#pragma once
#include "Monster.h"
class Bomb: public Monster {
private:
	int i;
	int yuka;
	int image[60];
	bool dead_f;
	World w;
public:
	Bomb(Point bird);
	virtual~Bomb();
	void Main();
	void Move();
	void Delete();
	void Draw();
	bool SetDeadFlag();
};

