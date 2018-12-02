#include "Slime.h"
#include <math.h>

Slime::Slime()
{
	p.x = rand() % RIGHT_MAX + LEFT_MAX - 32;
	p.y = 21 * 32;
	p.x2 = p.x + 32;
	p.y2 = p.y + 32;
	hitpoint = 4;
	temp = 0;
	i = 0;
	fps = 0;
	vectorr = STOP;
	name = "slime";
	score = 1000;
	LoadDivGraph(".\\image\\slime.png", 4, 4, 1, 32, 32, image);
}

Slime::~Slime()
{
	for (int i = 0; i < 4; i++)
		DeleteGraph(image[i]);
}

void Slime::Main()
{
	if(p.y2 >  DOWN_MAX) Generate();
	if(p.y2 <= DOWN_MAX) Move();
	Draw();
}

void Slime::Generate()
{
	p.y -= 4;
	p.y2 = p.y + 32;
}

void Slime::Move()
{
	if (LEFT_MAX < p.x && p.x2 < RIGHT_MAX && 0 == temp)
	{
		if (GetRand(200) == 0)
		{
			temp += GetRand(32 * 3) + 1;
			if (p.x2 + temp > RIGHT_MAX) temp = 1;
			vectorr = RIGHT;
		}
		else if (GetRand(200) == 1)
		{
			temp += GetRand(32 * 3) + 1;
			if (p.x - temp < LEFT_MAX) temp = 1;
			vectorr = LEFT;
		}
	}
	else if(0 < temp)
	{
		temp -= 2;
		if (vectorr == RIGHT) p.x += 2;
		if (vectorr == LEFT ) p.x -= 2;

		if (fps % 4 == 0)
		{
			i++;
			if (i == 4) i = 0;
		}
	}
	else if (temp < 0) temp = 0;
	
	p.x2 = p.x + 32;
	fps++;
}

void Slime::Damage()
{

}

void Slime::Temp()
{
}

void Slime::Draw()
{
	Fps();
	if(vectorr == STOP)DrawGraph(p.x, p.y, image[i], true);
	if(vectorr == RIGHT)DrawGraph(p.x, p.y, image[i], true);
	if (vectorr == LEFT)DrawTurnGraph(p.x, p.y, image[i], true);
	//DrawBox(p.x, p.y, p.x2, p.y2, GetColor(50, 255, 50), true);
}