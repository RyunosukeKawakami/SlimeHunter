#pragma once
#include "Monster.h"
#include "Bomb.h"
#include "Collision.h"
#include <vector>
using namespace std;

class Bird :public Monster{
private:
	vector<Bomb*> bomb;
	vector<Bomb*>::iterator bomb_it;
	Collision collison;
	int image[4];
public:
	Bird();
	virtual ~Bird();
	void Main();
	void Move();
	void Attack();
	void Delete() {};
	void DeleteBomb();
	void Draw(); 
};

