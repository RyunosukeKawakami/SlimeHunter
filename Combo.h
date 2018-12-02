#pragma once
#include "UI.h"

class Meter : public UI{
private:
	float length;
	bool count_f;
public:
	Meter() {
		p.x = 32 * 30;
		p.y = 32 ;
		p.x2 = p.x + 32 * 8;
		p.y2 = p.y + 10;
		length = 32 * 38;
		color = GetColor(255, 0, 0);
		count_f = false;
	};

	void Calculate(int score) {
		if (score > 0) {
			length = 32 * 30;
			count_f = true;
		}
		if (count_f) length += 1.3;
		if (p.x > 32 * 38) count_f = false;
	};

	void Draw() {
		DrawBoxAA(length, p.y, p.x2, p.y2, color, TRUE);
	};
};


class Combo : public UI{
private:
	Meter* meter;
	int combo;
	int font[2];
	int time_start;
	int time_end;
	int color[3];
	int now_color;
	char value_str[20];
	char combo_str[30];
	int sound[3];
public:
	Combo();
	~Combo();
	void Main(int);
	bool ContinueCombo();
	void Calculate(int);
	void ChangeColor();
	void Move();
	void Draw();
	void Sound(int);
};

