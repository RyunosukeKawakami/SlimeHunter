#include <stdio.h>
#include "DxLib.h"
#include "Score.h"

Score::Score()
{
	draw.x= 820;
	draw.y = 32 * 19;
	color = GetColor(255,0,0); 
	score = 0;
	strcpy_s(value_str,"000000\0");
	strcpy_s(score_str,"SCORE:\0");
	strcat_s(score_str,value_str);
}

int Score::Calculate()
{
	return 0;
}

void Score::Draw()
{
	DrawString(draw.x,draw.y,score_str,color);
}