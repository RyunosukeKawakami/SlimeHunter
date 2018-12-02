#pragma once
#include <string> 
#include "DxLib.h"
#include "Point.h"
using namespace std;

class Mystring {
private:
	const char* str;
	int font;
	int color;

public:
	Point p;
	Mystring(Point temp, const char* temp_str, int temp_color, const char* temp_font,int thick);
	~Mystring();
	void Draw();
	Point SetPoint();
};