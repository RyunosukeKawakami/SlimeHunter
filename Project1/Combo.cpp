#include "Combo.h"

Combo::Combo()
{
	p.x = 32 * 40;
	p.y = 5;
	combo = 1;
	strcpy_s(combo_str, "COMBO!!!\0");
	meter = new Meter();
	color[0] = GetColor(224,107,45);
	color[1] = GetColor(231,238,255);
	color[2] = GetColor(221,200,21);
	now_color = color[0];
	font[0] = CreateFontToHandle("Cheese", 32, 4, DX_FONTTYPE_EDGE);
	font[1] = CreateFontToHandle("EmbossedBlackWide", 32, 4, DX_FONTTYPE_EDGE);
	time_start = GetNowCount();
	time_end = 0;
	sound[0] = LoadSoundMem(".\\image\\do.wav");
	sound[1] = LoadSoundMem(".\\image\\re.wav");
	sound[2] = LoadSoundMem(".\\image\\mi.wav");
}

Combo::~Combo()
{
	DeleteFontToHandle(font[0]);
	DeleteFontToHandle(font[1]);
	delete meter;
}

void Combo::Main(int score)
{
	ChangeColor();
	meter->Calculate(score);
	Calculate(score);
	Move();
	Draw();
	meter->Draw();
}

void Combo::Sound(int temp)
{
	if(combo < 5 && temp > 0)
		PlaySoundMem(sound[0],DX_PLAYTYPE_BACK);

	if(5 < combo < 10 && temp > 0)
		PlaySoundMem(sound[1], DX_PLAYTYPE_BACK);

	if (10< combo < 15 && temp > 0)
		PlaySoundMem(sound[2], DX_PLAYTYPE_BACK);
}

void Combo::Calculate(int score)
{
	Sound(score);
	if(score > 0)
	{
		time_end = GetNowCount() + 3000;
		combo++;
	}
}

void Combo::ChangeColor()
{
	if (combo < 5) now_color = color[0];
	if (combo > 5) now_color = color[1];
	if (combo > 15) now_color = color[2];
}

bool Combo::ContinueCombo() 
{
	if (GetNowCount() < time_end)
		return true;
	else
	{
		combo = 0;
		return false;
	}
}

void Combo::Move()
{
	if (ContinueCombo() && p.x > 32 * 30)    p.x -= 15;
	if (!(ContinueCombo()) && p.x < 32 * 38) p.x += 10;
}

void Combo::Draw()
{
	snprintfDx(value_str, 20, "%d", combo);
	DrawStringToHandle(p.x - 64, p.y, value_str, now_color, font[1]);
	DrawStringToHandle(p.x, p.y, combo_str, now_color, font[0]);
}