#include"ControlTime.h"

ControlTime::ControlTime()
{
	p.x = 20 * 32;
	p.y = 20;
	color = GetColor(255,255,255);
	time_now = GetNowCount();
	time_limit = GetNowCount() + 60000 * 5;
}

void ControlTime::Draw()
{
	time_now = (time_limit - GetNowCount()) * 1000;
	DrawFormatString(p.x, p.y, color, "ÇÃÇ±ÇËÅF%d ïb",time_now);
}