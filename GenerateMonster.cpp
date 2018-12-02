#include "GenerateMonster.h"
#include "Player.h"

GenerateMonster::GenerateMonster()
{
	num_slime = 0;
	num_gslime = 0;
	num_ghost = 0;
	num_bird = 0;
	score = 0;

	slime_rand = 100;
	gslime_rand = 1000;
	ghost_rand = 300;
	bird_rand = 500;

	max_slime = 20;
	max_bird = 3;
	max_ghost = 3;
	max_gslime = 1;

	start_time = GetNowCount();
}

GenerateMonster::~GenerateMonster()
{
}

void GenerateMonster::Generate()
{
	LimitCont();
	if (GetRand(slime_rand) == 0 && num_slime < max_slime)
	{
		monster.emplace_back(new Slime());
		num_slime++;
	}

	if (GetRand(gslime_rand) == 0 && num_gslime < max_gslime)
	{
		monster.emplace_back(new GSlime());
		num_gslime++;
	}

	if (GetRand(ghost_rand) == 0 && num_ghost < max_ghost)
	{
		monster.emplace_back(new Ghost());
		num_ghost++;
	}

	if (GetRand(bird_rand) == 0 && num_bird < max_bird)
	{
		monster.emplace_back(new Bird());
		num_bird++;
	}
}

void GenerateMonster::Control(Player* player)
{
	for (auto monster_it = monster.begin(); monster_it != monster.end(); monster_it++)
		(*monster_it)->Main();

	for (auto monster_it = monster.begin(); monster_it != monster.end(); monster_it++)
		(*monster_it)->Damage(player);

	for (auto drop_it = drop_score.begin(); drop_it != drop_score.end(); drop_it++)
	{
		(*drop_it)->CalculateCombo(score);
	    (*drop_it)->Draw();
		(*drop_it)->Move();
	}
	for (auto vanimon_it = vanimon.begin(); vanimon_it != vanimon.end(); vanimon_it++)
	{
		(*vanimon_it)->Draw();
	}

}

void GenerateMonster::LimitCont()
{
	if (GetNowCount() - start_time > 18000)
	{
		slime_rand = 50;
		ghost_rand = 100;
		bird_rand = 300;
		gslime_rand = 600;

		max_slime = 30;
		max_bird = 6;
		max_ghost = 5;
		max_gslime = 2;
	}
	else if (GetNowCount() - start_time > 12000)
	{
		slime_rand = 50;
		ghost_rand = 100;
		bird_rand = 450;

		max_slime = 25;
		max_bird = 5;
		max_ghost = 5;
		max_gslime = 2;
	}
	else if (GetNowCount() - start_time > 6000)
	{
		slime_rand = 100;
		gslime_rand = 800;
		ghost_rand = 300;
		bird_rand = 500;

		max_bird = 4;
		max_ghost = 4;
	}

}

int GenerateMonster::Delete()
{
	score = 0;
	for (auto monster_it = monster.begin(); monster_it != monster.end();)
	{
		if ((*monster_it)->SetDeadFlag() == true)
		{
			if ((*monster_it)->SetType() == "slime") num_slime--;
			else if ((*monster_it)->SetType() == "gslime") num_gslime--;
			else if ((*monster_it)->SetType() == "ghost") num_ghost--;
			else if ((*monster_it)->SetType() == "bird") num_bird--;
			score = (*monster_it)->SetScore();
			drop_score.emplace_back(new DropScore((*monster_it)->SetPoint(), score));
			vanimon.emplace_back(new VanishMonster((*monster_it)->SetPoint()));
			delete *monster_it;
			*monster_it = NULL;
			monster_it = monster.erase(monster_it);
			continue;
		}
		else
			monster_it++;
	}
	monster.shrink_to_fit();

	for (auto drop_it = drop_score.begin(); drop_it != drop_score.end();)
	{
		if ((*drop_it)->SetDeadFlag())
		{
			delete *drop_it;
			*drop_it = NULL;
			drop_it = drop_score.erase(drop_it);
			continue;
		}
		else
			drop_it++;
	}
	drop_score.shrink_to_fit();

	for (auto vanimon_it = vanimon.begin(); vanimon_it != vanimon.end();)
	{
		if ((*vanimon_it)->SetDeadFlag())
		{
			delete *vanimon_it;
			*vanimon_it = NULL;
			vanimon_it = vanimon.erase(vanimon_it);
			continue;
		}
		else
			vanimon_it++;
	}
	vanimon.shrink_to_fit();


	return score;
}