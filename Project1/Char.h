#ifndef _CHAR_DEFINE_
#define _CHAR_DEFINE_
#include "UI.h"

class Char : public UI{
protected:
    const int GRAVITY;
	Point p;
public:
                 Char() : GRAVITY(5){};
	virtual void Main() = 0;
    virtual void Move() = 0;
};

#endif