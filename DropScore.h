#pragma once
#include "UI.h"
class DropScore : public UI{
private:
	int font;
	int speed;
	int score;
	bool dead_f;
	char score_str[20];

	int combo;
	int time_end;
	int ratio;

	const int  DOWN_MAX;
public:
	DropScore(Point, int);
	virtual ~DropScore();
	void CalculateCombo(int);
	bool ContinueCombo();
	void Move();
	void Draw();
	bool SetDeadFlag();
};

