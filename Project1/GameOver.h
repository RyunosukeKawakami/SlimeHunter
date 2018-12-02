#pragma once
#include "UI.h"
#include "World.h"
#include "Mystring.h"
#include <string>
#include <math.h>
using namespace std;

class GameOver : public UI {
private:
	Mystring* gam;
	Mystring* eo;
	Mystring* ver;
	Mystring* please_any;
	bool push_f;
	bool bright_f;
	double bright;
	int fps;

public:
	GameOver();
	virtual ~GameOver();
	void Draw();
	void Move();
	void Sort_Ranking();
	bool SetPushflag();
};
