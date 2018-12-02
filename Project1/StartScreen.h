#pragma once
#include "Mystring.h"
#include "Select.h"

class StartScreen{
private:
	Mystring* start;
	Mystring* ranking;
	Select* select;
	Point title_pos;
	int title_image;
	int select_f;
	int bright;
	bool bright_f;
	enum {
		START,
		RANKING,
	};
public:
	StartScreen();
	~StartScreen();
	void Choose();
	void Draw();
	int SetScreen();
};

