#ifndef _DEFINE_STATE_
#define _DEFINE_STATE_
#include "UI.h"
#include "Score.h"
#include "Hitpoint.h"
#include "Life.h"

class State_UI :public UI{
private:
	int length;
	int height;
	Score score;
    Hitpoint hp;
    Life life;

public:
	State_UI();
	void Control(int , int);
	void Draw();
	int SetScore();
};	

#endif