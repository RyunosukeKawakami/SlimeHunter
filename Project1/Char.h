#ifndef _CHAR_DEFINE_
#define _CHAR_DEFINE_
#include "UI.h"

class Char : public UI{
protected:
	int hitpoint;
	int vectorr;
    const int GRAVITY;
	const int RIGHT_MAX;
	const int LEFT_MAX;
	const int DOWN_MAX;
	const int UP_MAX;
	enum {
		RIGHT,
		LEFT,
		UP,
		DOWN,
		STOP
	};
public:
                 Char() : GRAVITY(5), RIGHT_MAX(35 * 32), LEFT_MAX(2 * 32), DOWN_MAX(32 * 16), UP_MAX(2 * 32) {};
	virtual void Main() = 0;
    virtual void Move() = 0;
	Point SetPoint() { return p; };
};

#endif