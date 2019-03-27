#include "GSlime.h"

GSlime::GSlime()
{
	if(GetRand(100) % 2 == 1)
	{
		p.x = 40 * 32;
		p.y = 10 * 32;
		generate_vectorr = RIGHT;
	}
	else
	{
		generate_vectorr = LEFT;
		p.x = 0;
		p.y = 10 * 32;
	}

	generate_f = true;
	p.x2 = p.x + 32;
	p.y2 = p.y + 32;
	hitpoint = 4;
	temp = 0;
	i = 0;
	vectorr = STOP;
	name = "gslime";
	score = 30000;
	LoadDivGraph(".\\image\\goldenslime.png", 4, 4, 1, 32, 32, image);
}

GSlime::~GSlime()
{
	for (int i = 0; i < 4; i++)
		DeleteGraph(image[i]);
}

void GSlime::Main()
{
	if (p.x < LEFT_MAX + 10 || RIGHT_MAX - 10 < p.x2) generate_f = true;
	else generate_f = false;

	if(generate_f == true) Generate();
	else Move();
	Draw();
}

void GSlime::Generate()
{
	if (generate_f == RIGHT) p.x -= 3;
	if (generate_f == LEFT ) p.x += 3;
	p.x2 = p.x + 32;
}

void GSlime::Move()
{
	bool wool_fx = LEFT_MAX - 32 * 3 < p.x && p.x2 < RIGHT_MAX + 32 * 3;
	bool wool_fy = UP_MAX - 32 * 3 < p.y && p.y2 < DOWN_MAX + 32 * 5;

	if (wool_fy && wool_fx && 0 == temp)
	{
		if (GetRand(50) == 0)
		{
			temp += GetRand(32 * 4) + 1;
			vectorr = RIGHT;
		}
		else if (GetRand(50) == 1)
		{
			temp += GetRand(32 * 4) + 1;
			vectorr = LEFT;
		}
		else if (GetRand(50) == 2)
		{
			temp += GetRand(32 * 4) + 1;
			vectorr = UP;
		}
		else if (GetRand(50) == 3)
		{
			temp += GetRand(32 * 4) + 1;
			vectorr = DOWN;
		}

	}
	else if (0 < temp)
	{
		temp -= 2;
		if (vectorr == RIGHT) p.x += 5;
		if (vectorr == LEFT)	 p.x -= 5;
		if (vectorr == UP)	 p.y -= 5;
		if (vectorr == DOWN)  p.y += 5;
		i += 3;

		p.x2 = p.x + 32;
		p.y2 = p.y + 32;
	}
	else if (temp < 0) temp = 0;

	p.x2 = p.x + 32;
}

void GSlime::Damage()
{

}

void GSlime::Temp()
{
}

void GSlime::Draw()
{
	DrawGraph(p.x, p.y, image[i % 4], true);
	//DrawBox(p.x, p.y, p.x2, p.y2, GetColor(50, 255, 50), true);
}