#include "Hitpoint.h"

Hitpoint::Hitpoint()
{
	length = 250;
	height = 30;
    p.x = 50;
    p.y = 32 * 19;
	p.y2 = p.y + height;
	temp = p;
    hp_max = 100;
    hp_now = hp_max; 
    hp_per = 1;   
    color  = GetColor(0,255,0);
	old_p_hp = 100;
}

void Hitpoint::Calculate(int player_hp)
{
    hp_per = (float)player_hp / hp_max;
	if (old_p_hp != player_hp)
		Move();
	old_p_hp = player_hp;

    if(hp_per >= 0.5) 
        color = GetColor(0,255,0);
    else if(hp_per < 0.5 && hp_per > 0.2) 
        color = GetColor(255,255,0);
    else if(hp_per <= 0.2)
        color = GetColor(255,0,0);
}

void Hitpoint::ResetHitpoint(int player_hp)
{
}

void Hitpoint::Move()
{
	int rand = GetRand(5);

	switch (GetRand(3)) {
	case 0:
		p.x += rand;
		p.y += rand;
		p.x2 += rand;
		p.y2 += rand;
		break;
	case 1:
		p.x -= rand;
		p.y += rand;
		p.x2 -= rand;
		p.y2 += rand;
		break;
	case 2:
		p.x += rand;
		p.y -= rand;
		p.x2 += rand;
		p.y2 -= rand;
		break;
	case 3:
		p.x -= rand;
		p.y -= rand;
		p.x2 -= rand;
		p.y2 -= rand;
		break;
	};
}

void Hitpoint::Draw()
{
    DrawString(p.x - 20,p.y - 2,"HP",GetColor(255,255,255));
    DrawBoxAA(p.x,p.y,p.x+(length*hp_per),p.y2,color,TRUE);
    DrawBoxAA(p.x,p.y,p.x+length,p.y2,GetColor(255,255,255),FALSE);

	p = temp;
}
