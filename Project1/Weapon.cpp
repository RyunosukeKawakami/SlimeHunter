#include "Weapon.h"

Weapon::Weapon(Point  player)
{
	draw.x  = player.x + 32;
	draw.x2 = player.x2 + 32;
	draw.y  = player.y;
	draw.y2 = player.y2 - 15;
	start = clock();
}

Weapon::~Weapon()
{
}

void Weapon::Main()
{
	printfDx("two");
	//while (start - clock() < 2000)
	//{
	//	printfDx("three");
	//	Draw();
	//}
}

void Weapon::Draw()
{
	printfDx("fwo");
	DrawBox(draw.x,draw.y,draw.x2,draw.y2,GetColor(255,0,0),true);
}

