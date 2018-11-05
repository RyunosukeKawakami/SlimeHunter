#ifndef _PLAYER_DEFINE_
#define _PLAYER_DEFINE_
#include "Char.h"
#include "Weapon.h"

class Player : public Char{
private:
    Point speed;
	Weapon* main;
	bool attack_f;
    int accel;
    int life;
    int hp;
    int vector;
    const int RIGHT_MAX;
    const int LEFT_MAX;
    const int DOWN_MAX;
    enum{
        RIGHT,
        LEFT,
        UP,
        DOWN,
        STOP 
    };

public:
    Player();
	void Main();
    void Draw();
    void Move();
    void Jump();
    void Attack();
};

#endif