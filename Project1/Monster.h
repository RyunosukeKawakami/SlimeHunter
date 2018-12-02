#pragma once
#include "Char.h"
#include "Player.h"

class Player;

class Monster :public Char {
protected:
	Collision col;
	bool dead_f = false;
	string name;
	int score;
	int fps;
	int i;
public:
	virtual ~Monster() {};
	virtual void Main() = 0;
	virtual void Move() = 0;
	virtual void Delete() = 0;

	void Damage(Player*);
	bool SetDeadFlag();
	int SetScore();
	void Fps();
	string SetType();
	Point SetPoint();
};