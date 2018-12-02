#include "Life.h"

Life::Life()
{
    p.x= 320;
    p.y = 32 * 19;
    image = LoadGraph(".\\image\\haert.png");
    life = 3;
	font[1] = CreateFontToHandle("Cheese", 32, 4, DX_FONTTYPE_EDGE);
	font[0] = CreateFontToHandle(NULL, 32, 3, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
    strcpy_s(x_str,"X \0");
}

Life::~Life()
{
	DeleteFontToHandle(font[0]);
	DeleteFontToHandle(font[1]);
}

void Life::Calculate(int player_hp)
{
	if (player_hp < 0)
		life--;

}

void Life::Draw()
{
	snprintfDx(value_str, 20, "%d", life);
	DrawStringToHandle(p.x + 40, 32 * 19, x_str, GetColor(255, 255, 255), font[0]);
	DrawStringToHandle(p.x + 55, 32 * 19, value_str, GetColor(255, 255, 255), font[1]);
    DrawGraph(p.x , p.y , image , TRUE);
}