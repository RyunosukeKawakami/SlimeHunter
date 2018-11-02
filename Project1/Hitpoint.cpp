#include "Hitpoint.h"
#include "DxLib.h"

Hitpoint::Hitpoint()
{
    draw.x = 50;
    draw.y = 32 * 19;
    hp_max = 200;
    hp_now = hp_max; 
    hp_per = 100;   
    length = 250;
    height = 30;
    color  = GetColor(0,255,0); 
}

float Hitpoint::Calculate(float hp_per)
{
    hp_per = hp_now / hp_max;
    
    if(hp_per >= 0.5) 
        color = GetColor(0,255,0);
    if(hp_per < 0.5 && hp_per > 0.2) 
        color = GetColor(255,255,0);
    if(hp_per <= 0.2)
        color = GetColor(255,0,0);
        
    return hp_per;
}

void Hitpoint::Draw()
{
    hp_per = Calculate(hp_per);
    DrawString(draw.x - 20,draw.y - 2,"HP",GetColor(255,255,255));
    DrawBoxAA(draw.x,draw.y,draw.x+(length*hp_per),draw.y+height,color,TRUE);
    DrawBoxAA(draw.x,draw.y,draw.x+length,draw.y+height,GetColor(0,0,0),FALSE);
}


