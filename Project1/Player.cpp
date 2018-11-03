#include "Player.h"
#include "DxLib.h"

Player::Player(): RIGHT_MAX(5*32), LEFT_MAX(0), DOWN_MAX(32*15)
{
    p.x = 50;
    p.y = DOWN_MAX;
    p.x2 = p.x + 32;
    p.y2 = p.y + 32;
	draw = p;
    speed.x = 5;
    speed.y = 5;
    accel = 0;
    vector = STOP;
    hp = 100;
    life = 3;
	
    image = LoadGraph("Player.png"); 
}

void Player::Main()
{
	Move();
	Draw();
}

void Player::Draw()
{
    //DrawGraph(draw.x,draw.y,image,TRUE);  
	DrawBox(draw.x, draw.y, draw.x2, draw.y2, GetColor(255, 0, 0), TRUE);
}

void Player::Move()
{
    if( CheckHitKey(KEY_INPUT_UP) != 0) Jump(); 
    if( CheckHitKey(KEY_INPUT_LEFT) != 0 ) vector = LEFT;
    if( CheckHitKey(KEY_INPUT_RIGHT) != 0) vector = RIGHT;

    if(vector == LEFT && p.x > LEFT_MAX)  p.x -= speed.x;
    if(vector == RIGHT&& p.x < RIGHT_MAX) p.x += speed.x; 
	p.x2 = p.x + 32;
	p.y2 = p.y + 32;
	draw = p;
}

void Player::Jump()
{
    while(p.y2 < DOWN_MAX)
    {
        accel = -15;
        accel += GRAVITY;
        speed.y += accel;
        p.y += speed.y;
    }
	accel = 0;
    p.y2 = DOWN_MAX;
}

void Player::Attack()
{
    
}