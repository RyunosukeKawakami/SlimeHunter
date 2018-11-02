#pragma once
#include <list>
#include "Box.h"
#include "Soil.h"
using namespace std;

class World{
private:
	const int YOKO = 37;
	const int TATE = 20;
	int map[20][37];
	list<Box*> box;
	list<Box*>::iterator it;
public:
	World();
	void Draw();
};

