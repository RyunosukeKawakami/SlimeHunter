#include "Count.h"

Count::Count()
{
	one = new Mystring(Point(10 * 32, 32 * 8, 32), "1"
		, GetColor(255, 0, 0), "EmbossedBlackWide", 60);

	two = new Mystring(Point(10 * 32, 32 * 8, 32), "2"
		, GetColor(255, 0, 0), "EmbossedBlackWide", 60);

	three = new Mystring(Point(10 * 32, 32 * 8, 32), "3"
		, GetColor(255, 0, 0), "EmbossedBlackWide", 60);

	go = new Mystring(Point(10 * 32 - 10,32 * 8, 32), "G O!"
		, GetColor(255, 0, 0), "EmbossedBlackWide", 60);

	start_time = GetNowCount();
}

Count::~Count()
{
	delete one;
	delete two;
	delete three;
	delete go;
}

int Count::count()
{
	if (GetNowCount() - start_time > 4000)
		return 4;
	else if (GetNowCount() - start_time > 3000)
		return 3;
	else if (GetNowCount() - start_time > 2000)
		return 2;
	else if (GetNowCount() - start_time > 1000)
		return 1;
}

bool Count::Start_f()
{
	if (count() == 4) return true;
	else return false;
}

void Count::Draw()
{
	if (count() == 4) go->Draw();
	if (count() == 3) three->Draw();
	if (count() == 2) two->Draw();
	if (count() == 1) one->Draw();
}
