#include "Life.h"
#include "DxLib.h"

Life::Life()
{
    draw.x= 320;
    draw.y = 32 * 19;
    image = LoadGraph(".\\image\\haert.png");
    life = 5;
    strcpy_s(value_str,"9999\0");
    strcpy_s(x_str,"X \0");
    strcat_s(x_str,value_str);
}

void Life::Draw()
{
    
    DrawString(draw.x + 40,32 * 19,x_str,GetColor(255,255,255));
    DrawGraph(draw.x , draw.y , image , TRUE);
}