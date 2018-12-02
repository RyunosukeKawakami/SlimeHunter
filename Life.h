#ifndef _LIFE_DEFINE_
#define _LIFE_DEFINE_
#include "UI.h"

class Life : public UI{
private:
    int life;
	int font[2];
   char value_str[20];
   char x_str[20];
   char* result_str;
public:
    Life();
	~Life();
    void Draw();
	void Calculate(int);
};

#endif