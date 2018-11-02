#include "DxLib.h"
#include "State_UI.h"

State_UI::State_UI()
{
	draw.x = 0;
	draw.y = 32 * 18;
	length = 32 * 40;
	height = 32 * 3;
	color = GetColor(0,0,0);
}

void State_UI::Draw()
{
	DrawBoxAA(draw.x,draw.y,draw.x+length,draw.y+height,color,TRUE);
	score.Draw();
    hp.Draw();
    life.Draw();
}