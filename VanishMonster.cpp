#include "VanishMonster.h"

VanishMonster::VanishMonster(Point temp)
{
	p = temp;
	image = LoadGraph(".\\image\\badhaert.png");
	alpha = 0;
	i = 0;
	dead = 0;
}

VanishMonster::~VanishMonster()
{
	DeleteGraph(image);
}

void VanishMonster::Draw()
{
	p.y -= 3;
	if(i % 10 == 1) dead++;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - i * 8);
	DrawGraph(p.x, p.y, image, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	i++;
}

bool VanishMonster::SetDeadFlag()
{
	if (dead != 3) 
		return false;
	else
		return true;
}
