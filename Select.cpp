#include "Select.h"

Select::Select()
{
	LoadDivGraph(".\\image\\slime.png", 4, 4, 1, 32, 32, image);
	p.x = 32 * 14;
	p.y = 32 * 10;
	p.x2 = p.x + 32;
	p.y2 = p.y + 32;
	fps = 0; 
	i = 0;
}

Select::~Select()
{
}

void Select::Move(int select_f)
{
	if (select_f == START)
		p.y = 32 * 10;
	if (select_f == RANKING)
		p.y = 32 * 13;
}

void Select::Draw()
{
	fps++;
	if (fps % 4 == 0)
	{
		i++;
		if (i == 4) i = 0;
	}

	DrawGraph(p.x, p.y, image[i], true);
}
