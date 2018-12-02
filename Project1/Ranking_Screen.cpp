#include "Ranking_Screen.h"

Ranking_Screen::Ranking_Screen()
{
	ranking_str = new Mystring(Point(11 * 32, 32 * 2, 32), "R A N K I N G"
		, GetColor(255, 255, 0), "Cheese" , 70);

	number[0] = new Mystring(Point(12 * 32, 32 * 6, 32), "1 :"
		, GetColor(255, 255, 0), "Cheese", 40);

	number[1] = new Mystring(Point(12 * 32, 32 * 8, 32), "2 :"
		, GetColor(221, 200, 21), "Cheese", 40);
	
	number[2] = new Mystring(Point(12 * 32, 32 * 10, 32), "3 :"
		, GetColor(231, 238, 255), "Cheese", 40);

	number[3] = new Mystring(Point(12 * 32, 32 * 12, 32), "4 :"
		, GetColor(224, 107, 45), "Cheese", 40);

	number[4] = new Mystring(Point(12 * 32, 32 * 14, 32), "5 :"
		, GetColor(224, 107, 45), "Cheese", 40);

	konkai = new Mystring(Point(10* 32, 32 * 16, 32), "Your Score"
		, GetColor(255, 255, 0), "Cheese", 40);

	temp_score_max = 100000;

	rank[0] = 0;
	rank[1] = 5000;
	rank[2] = 10000;
	rank[3] = 30000;
	rank[4] = 50000;
	rank[5] = 100000;

	font_num = CreateFontToHandle("EmbossedBlackWide", 50, 6, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

Ranking_Screen::~Ranking_Screen()
{
	delete ranking_str;
	delete konkai;
	delete number[0];
	delete number[1];
	delete number[2];
	delete number[3];
	delete number[4];
//	delete back;
	DeleteFontToHandle(font_num);
}

void Ranking_Screen::Sort()
{
	rank[0] = temp_score_max;

	for (int i = 0; i < 6 - 1; i++) {
		for (int j = 6 - 1; j > i; j--) {
			if (rank[j] < rank[j - 1]) {
				int temp = rank[j];
				rank[j] = rank[j - 1];
				rank[j - 1] = temp;
			}
		}
	}

}

void Ranking_Screen::Draw()
{
	ranking_str->Draw();
	konkai->Draw();
	for (int i = 0; i < 5; i++)
		number[i]->Draw();

	DrawFormatStringToHandle(14 * 32, 32 * 6 , GetColor(255, 255, 0), font_num, "%d", rank[5]);
	DrawFormatStringToHandle(14 * 32, 32 * 8 , GetColor(221, 200, 21), font_num, "%d", rank[4]);
	DrawFormatStringToHandle(14 * 32, 32 * 10, GetColor(231, 238, 255), font_num, "%d", rank[3]);
	DrawFormatStringToHandle(14 * 32, 32 * 12, GetColor(224, 107, 45), font_num, "%d", rank[2]);
	DrawFormatStringToHandle(14 * 32, 32 * 14, GetColor(224, 107, 45), font_num, "%d", rank[1]);

	DrawFormatStringToHandle(21 * 32, 32 * 16, GetColor(255, 255, 0), font_num, "%d", temp_score_max);
}

bool Ranking_Screen::SetScreen()
{
	if (CheckHitKeyAll()) return true;
	else return false;
}

void Ranking_Screen::GetScore(int temp)
{
	temp_score_max = temp;
}