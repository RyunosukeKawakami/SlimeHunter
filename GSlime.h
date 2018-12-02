#pragma once
#include "Monster.h"

class GSlime : public Monster {
private:
	int i;
	int temp;
	int image[4];
	int generate_vectorr;
	bool generate_f;
public:
	GSlime();
	virtual ~GSlime();
	void Main();
	void Generate();
	void Move();
	void Draw();
	void Temp();
	void Damage();
	void Delete() {};
};
