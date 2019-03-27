#pragma once
#include <vector>
#include "Slime.h"
#include "GSlime.h"
#include "Bird.h"
#include "Ghost.h"
#include "Monster.h"
#include "DropScore.h"
#include "VanishMonster.h"
using namespace std;

class Player;

class GenerateMonster{
private:
	vector<Monster*> monster;
	vector<DropScore*> drop_score;
	vector<VanishMonster*> vanimon;
	int num_slime;
	int num_gslime;
	int num_bird;
	int num_ghost;
	int max_slime;
	int max_gslime;
	int max_bird;
	int max_ghost;
	int slime_rand;
	int gslime_rand;
	int bird_rand;
	int ghost_rand;

	int score;
	int start_time;

public:
	GenerateMonster();
	virtual~GenerateMonster();
	void Generate();
	void Control(Player*);
	void LimitCont();
	int Delete();
	vector<Monster*> SetPlayer() { return monster; };
};