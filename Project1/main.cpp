#include "DxLib.h"
#include "Debug.h"
#include "State_UI.h"
#include "World.h"
#include "Char.h"
#include "Player.h"
#include <list>
using namespace std;

int Process() {

	if (ScreenFlip() == -1) return -1;
	if (ProcessMessage() == -1) return -1;
	if (ClearDrawScreen() == -1) return -1;
	if (SetDrawScreen(DX_SCREEN_BACK) == -1) return -1;
	if (SetDrawMode(DX_DRAWMODE_BILINEAR) == -1) return -1;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	/*		�����ݒ�		*/
	SetGraphMode(1216, 672, 16);
	ChangeWindowMode(TRUE);		        	//�E�B���h�E���[�h�̕ύX
	DxLib_Init();			            	//�c�w���C�u�����̏�����
	SetBackgroundColor(0, 0, 0);
	SetWindowText("BUGGY!!");
	DxLib_Init();			            	//�c�w���C�u�����̏�����

	Debug debug;
	State_UI ui;
	World world;
	list<Char*> chara;
	list<Char*>::iterator char_it;
	chara.push_back(new Player());

	while(Process() != -1)
	{
		world.Draw();
		ui.Draw();
		for(char_it = chara.begin(); char_it != chara.end(); char_it++)
			(*char_it)->Main();
		if (CheckHitKey(KEY_INPUT_LEFT) != 0) DrawBox(100, 100, 100, 100, GetColor(255, 0, 0), TRUE);
		//debug.Main();
	}

	DxLib_End();
	return 0;
}