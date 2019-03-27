#include "Player.h"
#include "GenerateMonster.h"

Player::Player()
{
    p.x = RIGHT_MAX / 2;
    p.y = 10 * 15;
    p.x2 = p.x + 32;
    p.y2 = p.y + 32;
	floor = DOWN_MAX / 32;
    speed.x = 5;
    speed.y = 0;
    vectorr = STOP;
    hitpoint = 100;
    life = 3;
	attack_f = false;
	damage_f = false;
	collision = new Collision();

	damage_sound = LoadSoundMem(".\\image\\damage.wav");
    image = LoadGraph(".\\image\\haert.png"); 
}

Player::~Player()
{
	delete collision;
	DeleteSoundMem(damage_sound);
}

void Player::Main(GenerateMonster* genemon)
{
	
	floor = w.Set(p);
	Move();
	Jump();
	Attack();
	ResetHitpoint();
	Damage(genemon->SetPlayer());
	Draw();
}

void Player::Draw()
{
    DrawGraph(p.x,p.y,image,TRUE);  
}

void Player::Move()
{
	GetHitKeyStateAll(buf);
    if( buf[KEY_INPUT_LEFT]  == 1 || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) vectorr = LEFT;
    if( buf[KEY_INPUT_RIGHT] == 1 || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) vectorr = RIGHT;
	if( (buf[KEY_INPUT_UP] == 1  || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1) && p.y2 >= floor) speed.y = -20;

    if(vectorr == LEFT  && p.x > LEFT_MAX)  p.x -= speed.x;
    if(vectorr == RIGHT && p.x < RIGHT_MAX) p.x += speed.x; 
	p.x2 = p.x + 32;
	p.y2 = p.y + 32;
}

void Player::Jump()
{
	p.y += speed.y;
	p.y2 = p.y + 32;
	if (p.y2 < floor)
		speed.y += 1;

	else if (p.y2 >= floor)
	{
		speed.y = 0;
		speed.y = 0;
		p.y = floor - 32;
		p.y2 = floor;
	}
}

void Player::Attack()
{

	if ((buf[KEY_INPUT_Z] == 1 || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_2) && attack_f == false )
	{
		weapon = new Weapon(p, vectorr);
		attack_f = true;
		time_start = GetNowCount();
	}

	if (attack_f == true)
	{
		if (GetNowCount() - time_start < 500)
		{
			weapon->Move(speed, vectorr);
			weapon->Draw();
		}
		else
			attack_f = false;
	}
	else if (attack_f == false && GetNowCount() - time_start > 500)
	{
		delete weapon;
		weapon = NULL;
	}
}

void Player::ResetHitpoint()
{
	if (hitpoint < 0 && life > 0)
	{
		life--;
		hitpoint = 100;
	}
}

void Player::Damage(vector<Monster*> monster)
{
	for (auto monster_it = monster.begin(); monster_it != monster.end(); monster_it++)
	{
		if (collision->Main(p, (*monster_it)->SetPoint())) {
			hitpoint -= 1;
			PlaySoundMem(damage_sound, DX_PLAYTYPE_BACK, TRUE);
			damage_f = true;
		}
		else
			damage_f = false;
	}

}

int Player::SetHitpoint() { return hitpoint; }

int Player::SetLife() { return life; }

Point Player::SetPoint()
{
	if (weapon != NULL)
		return weapon->SetPoint();
	else
		Point(0, 0, 0);
}