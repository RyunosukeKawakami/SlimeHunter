#pragma once
#include <string>
#include"UI.h"
using namespace std;

class ControlTime : public UI{
private:
	string time_value;
	int time_now;
	int time_limit;
public:
	ControlTime();
	void Draw();
};
