#pragma once
#include "Char.h"
#include "World.h"
#include "Weapon.h"
#include "Collision.h"
#include "Monster.h"

class GenerateMonster;
class Monster;

class Player : public Char{
private:
	World w;
    Point speed;
	Weapon* weapon;
	Collision* collision;
	GenerateMonster* genemon;
    int life;
    int vectorr;
	int floor;
	int time_start;
	int damage_sound;
	char buf[256];
	bool attack_f;
	bool damage_f;

public:
    Player();
	~Player();
	void Main() {};
	void Main(GenerateMonster*);
    void Draw();
    void Move();
    void Jump();
	void ResetHitpoint();
	void Damage(vector<Monster*>);
    void Attack();
	
	int SetHitpoint();
	int SetLife();
	Point SetPoint();

};