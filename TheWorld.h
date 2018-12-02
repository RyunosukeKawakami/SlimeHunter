#pragma once
#include "UI.h"

class TheWorld : public UI{
private:
	int speed;
	bool stop_f;
	const int DOWN_MAX;
	int end_time;
public:
	TheWorld(Point);
	~TheWorld();
	void Move();
	void Vanish();
	void Draw();
};

