#ifndef _SCORE_DEFINE_
#define _SCORE_DEFINE_
#include "UI.h"

class Score :public UI{
private:
	  int score;
	  int combo;
	  int font[2];
	  int time_end;
	  int ratio;
     char value_str[20];
	 char score_str[20];
    char* score_cat;
public:
	Score();
	~Score();
	void Draw();
	void CalculateCombo(int);
	bool ContinueCombo();
	int SetScore();
};

#endif