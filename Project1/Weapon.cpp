#include "Weapon.h"

Weapon::Weapon(Point player , int vector_p)
{
	p = player;
	vectorr = vector_p;
	if (vector_p == RIGHT)
	{
		p.x += 32 + 7;
		p.x2 += 64 + 7;
	}
	else if (vector_p == LEFT)
	{
		p.x -= (64 + 7);
		p.x2 -= (32 + 7);
	}

	image = LoadGraph(".\\image\\ken.png");
}

Weapon::~Weapon()
{

}

void Weapon::Move(Point speed , int vector)
{
	if (vectorr == RIGHT) 
	{
		p.x += speed.x;
		p.y += speed.y;
		p.x2 += speed.x;
		p.y2 += speed.y;
	}
	else if (vectorr == LEFT)
	{
		p.x -= speed.x;
		p.y += speed.y;
		p.x2 -= speed.x;
		p.y2 += speed.y;
	}
}

void Weapon::Draw()
{
	if (vectorr == RIGHT) DrawGraph(p.x, p.y, image, true);
	if (vectorr == LEFT ) DrawTurnGraph(p.x, p.y, image, true);
}

Point Weapon::SetPoint() { return p;}
