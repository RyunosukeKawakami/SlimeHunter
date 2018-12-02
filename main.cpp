#include "DxLib.h"
#include "Debug.h"
#include "State_UI.h"
#include "World.h"
#include "Player.h"
#include "GenerateMonster.h"
#include "Combo.h"
#include "GameOver.h"
#include "Ranking_Screen.h"
#include "StartScreen.h"
#include "Count.h"
#include <list>
#include <time.h>
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
	/*		‰ŠúÝ’è		*/
	SetGraphMode(1216, 672, 16);
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetBackgroundColor(0, 0, 0);
	SetWindowText("BUGGY!!");
	DxLib_Init();
	SRand((int)time(NULL));

	StartScreen* start = NULL;
	GameOver* gameover = NULL;
	Ranking_Screen ranking;

	World world;
	Debug debug;
	Count* count = NULL;
	State_UI* ui = NULL;
	Combo* combo = NULL;
	GenerateMonster* genemon = NULL;
	Player* player = NULL;

	enum {
		START,
		RANKING,
		GAME,
		GAMEOVER,
	};

	int score = 0;
	int temp_score = 0;
	int screen = START; 
	int push_f = 0;
	int music_game = LoadSoundMem(".\\image\\game.mp3");
	int music_gameover = LoadSoundMem(".\\image\\gameover.mp3");
	int music_start = LoadSoundMem(".\\image\\start.mp3");
	int music_select = LoadSoundMem(".\\image\\select.wav");

	bool init_start = true;
	bool init_ranking = false;
	bool init_game = false;
	bool init_gameover = false;

	while (Process() != -1)
	{
		
		if (screen == GAMEOVER || screen == RANKING)
			SetDrawBright(0, 100, 0);

		world.Draw();
		SetDrawBright(255, 255, 255);

		switch (screen) {
		case START:
			if (init_start) {
				PlaySoundMem(music_start, DX_PLAYTYPE_BACK);
				start = new StartScreen();
				init_start = false;
			}

			start->Choose();
			start->Draw();

			if (start->SetScreen() == RANKING && push_f == 2) {
				PlaySoundMem(music_select, DX_PLAYTYPE_BACK);
				StopSoundMem(music_start);
				screen = start->SetScreen();
				delete start;
				init_ranking = true;
			}
			else if (start->SetScreen() == GAME && push_f == 2){
				PlaySoundMem(music_select, DX_PLAYTYPE_BACK);
				StopSoundMem(music_start);
				screen = start->SetScreen();
				delete start;
				init_game = true;
			}
			break;

		case GAME:
			if (init_game)
			{	
				ui = new State_UI();
				combo = new Combo();
				genemon = new GenerateMonster();
				player = new Player();
				count = new Count();
				
				while (count->Start_f() != true)
					count->Draw();

				init_game = false;
			}
			if(CheckSoundMem(music_game) == 0)
				PlaySoundMem(music_game, DX_PLAYTYPE_BACK);

			ui->Control(player->SetHitpoint(), score);
			combo->Main(score);
			genemon->Generate();
			genemon->Control(player);
			score = genemon->Delete();
			player->Main(genemon);

			if (player->SetHitpoint() <= 0 && player->SetLife() <= 0)
			{
				StopSoundMem(music_game);
				init_gameover = true;
				screen = GAMEOVER;
				temp_score = ui->SetScore();
				delete ui;
				delete combo;
				delete genemon;
				delete player;
			}
			break;

		case GAMEOVER:
			if (init_gameover == true)
			{
				PlaySoundMem(music_gameover, DX_PLAYTYPE_BACK);
				init_gameover = false;
				gameover = new GameOver();
			}

			gameover->Move();
			gameover->Draw();
			if (gameover->SetPushflag() == true && push_f == 2)
			{
				delete gameover;
				screen = RANKING;
				init_ranking = true;
			}
			break;

		case RANKING:
			if (init_ranking == true)
			{
				init_ranking = false;
				ranking.GetScore(temp_score);
				ranking.Sort();
			}

			ranking.Draw();

			if (ranking.SetScreen() && push_f == 5)
			{
				StopSoundMem(music_gameover);
				screen = START;
				temp_score = 0;
				init_start = true;
			}
			break;
		}
		
		if (CheckHitKey(KEY_INPUT_Z) == 1 || (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1)) 
			push_f++;
		else 
			push_f = 0;
	//5	printfDx("%d\n",music_select);
	}

	DxLib_End();
	return 0;
}