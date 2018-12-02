#include "Bird.h"

Bird::Bird()
{
	if (GetRand(100) % 2 == 0) vectorr = RIGHT;
	else					   vectorr = LEFT;

	if (vectorr == LEFT)  p.x = 39 * 32;
	if (vectorr == RIGHT) p.x = -1 * 32;
	p.y = 4 * 32;
	p.x2 = p.x + 32;
	p.y2 = p.y + 32;
	hitpoint = 4;
	name = "bird";
	score = 2000;
	LoadDivGraph(".\\image\\slime3.png", 4, 4, 1, 32, 32, image);
	i = 0;
	fps = 0;
}

Bird::~Bird()
{
	for(int i = 0; i < 4; i++ )
		DeleteGraph(image[i]);
}

void Bird::Main()
{
	Move();
	Attack();
	DeleteBomb();
	Draw();
}

void Bird::Move()
{
	if (vectorr == LEFT)  p.x -= 5;
	if (vectorr == RIGHT) p.x += 5;
	p.x2 = p.x + 32;

	if (p.x2 < -3 * 32) vectorr = RIGHT;
	if (p.x  > 42 * 32) vectorr = LEFT;
}

void Bird::Attack()
{
	if(LEFT_MAX < p.x && p.x2 < RIGHT_MAX)
	{
		if (GetRand(150) == 0)
			bomb.push_back(new Bomb(p));
	}

	for (bomb_it = bomb.begin(); bomb_it != bomb.end(); bomb_it++)
		(*bomb_it)->Main();
}

void Bird::DeleteBomb()
{
	for (auto bomb_it = bomb.begin(); bomb_it != bomb.end();)
	{
		if ((*bomb_it)->SetDeadFlag())
		{
			delete *bomb_it;
			//*bomb_it = 0;
			bomb_it = bomb.erase(bomb_it);
			continue;
		}
		else
			bomb_it++;
	}
	bomb.shrink_to_fit();
}

void Bird::Draw()
{
	Fps();
	if(vectorr == LEFT) DrawGraph(p.x, p.y, image[i], TRUE);
	if (vectorr == RIGHT) DrawTurnGraph(p.x, p.y, image[i], TRUE);
	//DrawBox(p.x, p.y, p.x2, p.y2, GetColor(50, 50, 255), true);
}

