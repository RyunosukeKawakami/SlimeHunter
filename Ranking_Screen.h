#pragma once
//#include "Mystring.h"
#include "Gameover.h"

class Ranking_Screen{
private:
	int music;
	Mystring* ranking_str;
	Mystring* konkai;
	Mystring* number[5];
	Mystring* back;
	int rank[6];
	int font_num;
	int temp_score_max;
public:
	Ranking_Screen();
	~Ranking_Screen();
	void Draw();
	void Sort();
	bool SetScreen();

	void GetScore(int);
};

