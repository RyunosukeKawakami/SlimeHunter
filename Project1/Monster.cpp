#include "Monster.h"

void Monster::Damage(Player* player)
{
	if (col.Main(p, player->SetPoint()))
		hitpoint -= 1;

	if (hitpoint < 0)
		dead_f = true;
}

void Monster::Fps()
{
	fps++;
	if (fps % 4 == 0)
	{
		i++;
		if (i == 4) i = 0;
	}
}

int Monster::SetScore() { return score; }

Point Monster::SetPoint() {return p;}

bool Monster::SetDeadFlag() { return dead_f; }

string Monster::SetType() { return name; }