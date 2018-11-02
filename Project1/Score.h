#ifndef _SCORE_DEFINE_
#define _SCORE_DEFINE_
#include "UI.h"

class Score :public UI{
private:
	  int score;
     char value_str[20];
	 char score_str[20];
    char* score_cat;
public:
	Score();
	void Draw();
	int Calculate(); 
};

#endif