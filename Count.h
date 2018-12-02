#pragma once
#include "UI.h";
#include "Mystring.h"

class Count : public UI{
private:
	Mystring* one;
	Mystring* two;
	Mystring* three;
	Mystring* go;
	int start_time;
public:
	Count();
	~Count();
	void Draw();
	int  count();
	bool Start_f();
};

