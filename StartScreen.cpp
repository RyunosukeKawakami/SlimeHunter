#include "StartScreen.h"

StartScreen::StartScreen()
{
	start   = new Mystring(Point(32*16, 32*10,32),"S T A R T",GetColor(255,100,100),NULL,45);
	ranking = new Mystring(Point(32*16, 32*13,32), "R A N K I N G", GetColor(100,255,100), NULL,45);
	select = new Select();
	title_image = LoadGraph(".\\image\\title.png");
	select_f = START;
	bright = 0;
	bright_f = true;
}

StartScreen::~StartScreen()
{
	delete start;
	delete ranking;
	delete select;
}

void StartScreen::Choose()
{
	if (select_f == START && (CheckHitKey(KEY_INPUT_DOWN) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN)) select_f = RANKING;
	if (select_f == RANKING && (CheckHitKey(KEY_INPUT_UP) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP)) select_f = START;
}

void StartScreen::Draw()
{
	if (bright >= 255) bright_f = false;
	if (0 >= bright) bright_f = true;
	if (bright_f == true) bright += 5;
	if (bright_f == false) bright -= 5;

	DrawGraph(32*10,32*4,title_image,TRUE);

	if(select_f == START) SetDrawBright(bright, 100, 100);
	start->Draw();
	SetDrawBright(255, 255, 255);
	
	if (select_f == RANKING) SetDrawBright(100, bright, 100);
	ranking->Draw();
	SetDrawBright(255, 255, 255);

	select->Move(select_f);
	select->Draw();
}

int StartScreen::SetScreen()
{
	if (select_f == START && (CheckHitKey(KEY_INPUT_Z) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1)) return 2;
	else if (select_f == RANKING && (CheckHitKey(KEY_INPUT_Z) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1)) return 1;

	return 0;
}