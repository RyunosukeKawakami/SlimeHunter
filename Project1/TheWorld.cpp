#include "TheWorld.h"

TheWorld::TheWorld(Point temp) : DOWN_MAX(32 * 16)
{
	p = temp;
	speed = 0;
	end_time = GetNowCount() + 5000;
	stop_f = false;
	image = LoadGraph(".\\image\\StopItem.png");
}

TheWorld::~TheWorld()
{

}

void TheWorld::Move()
{
	if (p.y > DOWN_MAX) {
		p.y += speed;
		speed += 0.5;
	}
}

void TheWorld::Vanish()
{
	if (GetNowCount() > end_time)
	{
		
	}
}

void TheWorld::Draw()
{
	DrawGraph(p.x, p.y, image, TRUE);
}

