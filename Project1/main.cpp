#include "DxLib.h"
#include "Debug.h"
#include "State_UI.h"
#include "World.h"
#include "Char.h"
#include "Player.h"
#include <list>
using namespace std;

int process(char key[256])
{
	if (ScreenFlip() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	if (ClearDrawScreen() != 0) return -1;
	if (GetHitKeyStateAll(key) != 0) return -1;
	return 0;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	/*		‰Šúİ’è		*/
	ChangeWindowMode(TRUE);
	SetGraphMode(1216, 672, 16);
	DxLib_Init();
	SetBackgroundColor(150, 150, 255);
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("BUGGY!!");
	DxLib_Init();			            	//‚c‚wƒ‰ƒCƒuƒ‰ƒŠ‚Ì‰Šú‰»

	Debug debug;
	State_UI ui;
	World world;
	list<Char*> chara;
	list<Char*>::iterator char_it;
	chara.push_back(new Player());

	while(process)
	{
		world.Draw();
		ui.Draw();
		for(char_it = chara.begin(); char_it != chara.end(); char_it++)
			(*char_it)->Main();

		//debug.Main();
	}

	DxLib_End();
	return 0;
}