#pragma once
#include "UI.h"

class Select : public UI{
private:
	int image[4];
	int fps;
	int i;
	enum {
		START,
		RANKING,
	};
public:
	Select();
	~Select();
	void Move(int);
	void Draw();
};

