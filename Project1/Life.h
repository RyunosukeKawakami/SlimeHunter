#ifndef _LIFE_DEFINE_
#define _LIFE_DEFINE_
#include "UI.h"

class Life : public UI{
private:
    int life;
   char value_str[10];
   char x_str[10];
   char* result_str;
public:
    Life();
    void Draw();
};

#endif