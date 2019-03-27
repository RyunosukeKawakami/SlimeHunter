#pragma once
#include "UI.h"

class Hitpoint : public UI{
private:
    int hp_now;
    int hp_max;
  float hp_per;
    int length;
    int height;
	int old_p_hp;
	Point temp;

public:
         Hitpoint();
    void Calculate(int player_hp);
	void ResetHitpoint(int);
	void Move();
    void Draw();
	int SetHp();
    
};