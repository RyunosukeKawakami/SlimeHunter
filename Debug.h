#ifndef _DEBUG_
#define _DEBUG_
#include "DxLib.h"

class Debug{
private:
	int color;
	bool flag = false;
public:
	void Main();
	void Stop();
	void DrawFrame();
	void Exit();
};
#endif