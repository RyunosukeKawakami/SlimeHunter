#include "GameOver.h"

GameOver::GameOver()
{
	gam = new Mystring(Point(12*32,-60,32), "Gam"
						, GetColor(255, 0, 0), "Cheese", 70);

	eo = new Mystring(Point(16*32+20,32*25,32), "e O"
						, GetColor(0, 255, 0), "Cheese", 70);

	ver = new Mystring(Point(20*32+20,-60,32), "ver"
						, GetColor(0, 0, 255), "Cheese", 70);

	please_any = new Mystring(Point(10*32,32*13,32), "Press Any Key"
						, GetColor(255, 0, 0), "Cheese", 60);

	push_f = false;
	bright_f = true;
	bright = 0;
	fps = 0;
}

GameOver::~GameOver()
{
	delete gam;
	delete eo;
	delete ver;
	delete please_any;
}

void GameOver::Sort_Ranking()
{
}

void GameOver::Move()
{
	if (gam->p.y != 32 * 5) gam->p.y += 5;
	if (eo->p.y >= 32 * 5) eo->p.y -= 14;
	if (ver->p.y != 32 * 5) ver->p.y += 5;

	if (gam->p.y >= 32 * 5 && eo->p.y >= 32 * 5 && ver->p.y >= 32 * 5)
		push_f = true;
}

void GameOver::Draw()
{
	gam->Draw();
	eo->Draw();
	ver->Draw();

	if (push_f == true)
	{
		if (bright >= 255) bright_f = false;
		if (0 >= bright) bright_f = true;

		if (bright_f == true) bright += 5;
		if (bright_f == false) bright -= 5;

		SetDrawBright(bright, 0, 0);
		please_any->Draw();
		SetDrawBright(255, 255, 255);
	}
}

bool GameOver::SetPushflag()
{
	if (push_f == true)
		if(CheckHitKey(KEY_INPUT_Z) || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1))
		return true;

	return false;
}