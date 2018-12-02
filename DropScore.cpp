#include "DropScore.h"

DropScore::DropScore(Point temp ,int temp_score) : DOWN_MAX(32 * 16)
{
	p = temp;
	p.x -= 5;
	speed = -10;
	score = temp_score;
	combo = 0;
	time_end = 0;
	ratio = 1;
	dead_f = false;
	color = GetColor(255, 255, 56);
	font = CreateFontToHandle("EmbossedBlackWide", 32, 4, DX_FONTTYPE_EDGE);
}

DropScore::~DropScore()
{
	DeleteFontToHandle(font);
}

void DropScore::CalculateCombo(int temp)
{
	if (temp > 0)
	{
		time_end = GetNowCount() + 3000;
		combo++;
	}
	ContinueCombo();

	if (combo < 5) ratio = 1;
	if (combo > 5) ratio = 5;
	if (combo > 15) ratio = 15;
	score += temp * ratio;
}

bool DropScore::ContinueCombo()
{
	if (GetNowCount() < time_end)
		return true;
	else
	{
		combo = 0;
		return false;
	}
}

void DropScore::Draw()
{
	snprintfDx(score_str, 20, "%d", score);
	DrawStringToHandle(p.x, p.y, score_str, color, font);
}

void DropScore::Move()
{
	speed += 1;
	p.y += speed;

	if (p.y > DOWN_MAX)
		dead_f = true;
	else
		dead_f = false;
}

bool DropScore::SetDeadFlag() { return dead_f; }