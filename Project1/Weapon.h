#pragma once
#include <time.h>
#include "UI.h"

class Weapon : public UI {
private:
	clock_t start;

public:
	Weapon(Point player);
	~Weapon();
	void Main();
	void Draw();
};
