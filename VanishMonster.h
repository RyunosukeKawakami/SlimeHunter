#pragma once
#include "UI.h"
class VanishMonster :public UI{
private:
	int alpha;
	int i;
	int dead;
public:
	VanishMonster(Point);
	~VanishMonster();
	void Draw();
	bool SetDeadFlag();
};

