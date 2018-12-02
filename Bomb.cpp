#include "Bomb.h"
#include "World.h"

Bomb::Bomb(Point bird)
{
	i = 0;
	dead_f = false;
	p = bird;
	yuka = DOWN_MAX;
	name = "bomb";
	score = 5000;
	LoadDivGraph(".\\image\\bomb.png", 60, 6, 10, 32, 32, image);
}

Bomb::~Bomb()
{
	for (int i = 0; i < 60; i++) {
		DeleteGraph(image[i]);
		image[i] = NULL;
	}
}

void Bomb::Main()
{
	yuka = w.Set(p);
	Move();
	Draw();
}

void Bomb::Move()
{
	if (p.y2 < yuka)
	{
		p.y += 2;
		p.y2 = p.y + 32;
	}
	else if (p.y2 >= yuka)
		Delete();
}

void Bomb::Delete()
{
	if (i == 35)
		dead_f = true;
}

void Bomb::Draw()
{
	if(p.y2 < yuka) 
		i = (GetNowCount() / 50) % 2 + 3;
	else if(p.y2 >= yuka)
		i = (GetNowCount() / 50) % 6 + 31;

	DrawGraph(p.x, p.y, image[i], TRUE);
	//DrawBox(p.x, p.y, p.x2, p.y2, GetColor(80,80,80), true);
}

bool Bomb::SetDeadFlag() { return dead_f; }
