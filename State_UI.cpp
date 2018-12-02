#include "State_UI.h"

State_UI::State_UI()
{
	p.x = 0;
	p.y = 32 * 18;
	length = 32 * 40;
	height = 32 * 3;
	color = GetColor(0,0,0);
}

void State_UI::Control(int player_hp , int temp_score)
{
	hp.Calculate(player_hp);
	life.Calculate(player_hp);
	score.CalculateCombo(temp_score);
	Draw();
}

void State_UI::Draw()
{
	DrawBoxAA(p.x,p.y,p.x+length,p.y+height,color,TRUE);
	score.Draw();
    hp.Draw();
    life.Draw();
}

int State_UI::SetScore() {
	return score.SetScore();
}