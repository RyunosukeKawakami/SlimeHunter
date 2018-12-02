#include <stdio.h>
#include "Score.h"

Score::Score()
{
	p.x= 820;
	p.y = 32 * 19;
	combo = 0;
	ratio = 1;
	score = 0;
	time_end = 0;
	color = GetColor(255,255,56);
	font[0] = CreateFontToHandle("EmbossedBlackWide",32,4,DX_FONTTYPE_EDGE);
	font[1] = CreateFontToHandle("Cheese", 32, 5, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

Score::~Score()
{
	DeleteFontToHandle(font[0]);
	DeleteFontToHandle(font[1]);
}

void Score::CalculateCombo(int temp)
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

bool Score::ContinueCombo()
{
	if (GetNowCount() < time_end)
		return true;
	else
	{
		combo = 0;
		return false;
	}
}

void Score::Draw()
{
	snprintfDx(value_str, 20, "%d", score);
	strcpy_s(score_str, "Byte:\0");
	DrawStringToHandle(p.x,p.y,score_str,color,font[1]);
	DrawStringToHandle(p.x + 32 * 6,p.y,value_str,color,font[0]);
}

int Score::SetScore() { return score; }

