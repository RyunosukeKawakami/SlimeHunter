#ifndef _DEFINE_BOX_
#define _DEFINE_BOX_
#include "UI.h"

class Box : public UI{
private:
public:
	virtual void Draw() = 0;
};
    
#endif