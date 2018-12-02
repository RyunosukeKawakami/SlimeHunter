#include "Ghost.h"

Ghost::Ghost()
{
	if (GetRand(100) % 2 == 0) vectorr = RIGHT;
	else					   vectorr = LEFT;
	vector_y = UP;

	if(vectorr == LEFT)  p.x = 39 * 32;
	if(vectorr == RIGHT) p.x = -1 * 32;
	p.y = (GetRand(8) + 7) * 32;
	p.x2 = p.x + 32;
	p.y2 = p.y + 32;
	init_y = p.y;
	i = 0;
	fps = 0;
	hitpoint = 5;
	name = "ghost";
	score = 1000;
	LoadDivGraph(".\\image\\slime2.png", 4, 4, 1, 32, 32, image);
}

Ghost::~Ghost()
{
	for (int i = 0; i < 4; i++)
		DeleteGraph(image[i]);
}

void Ghost::Main()
{
	Move();
	Draw();
}

void Ghost::Move()
{
	if (vectorr == LEFT)  p.x -= 3;
	if (vectorr == RIGHT) p.x += 3;
	
	if (init_y - 32 < p.y && vector_y == UP) p.y -= 3;
	else if (init_y - 32 > p.y)vector_y = DOWN;

	if (init_y + 32 > p.y && vector_y == DOWN) p.y += 3;
	else if (init_y + 32 < p.y)vector_y = UP;

	p.x2 = p.x + 32;
	p.y2 = p.y + 32;

	if (p.x2 < -1 * 32) vectorr = RIGHT;
	if (p.x  > 39 * 32) vectorr = LEFT;
}

void Ghost::Draw()
{
	Fps();
	if (vectorr == STOP) DrawGraph(p.x, p.y, image[i], true);
	if(vectorr == LEFT )DrawGraph(p.x, p.y, image[i], true);
	if(vectorr == RIGHT)DrawTurnGraph(p.x, p.y, image[i], true);
	//DrawBox(p.x, p.y, p.x2, p.y2, GetColor(255, 50, 50), true);
}