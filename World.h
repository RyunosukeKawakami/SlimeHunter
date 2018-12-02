#ifndef _WORLD_
#define _WORLD_
#include <vector>
#include "Box.h"
#include "Soil.h"
using namespace std;

struct Map {
	int map[20][38];
};

class World{
private:
	int YOKO;
    int TATE;
	int map[20][38];
	const int DOWN_MAX;
	vector<Box*> box;
	vector<Box*>::iterator it;
public:
	World();
	void Draw();
	int  Set(Point);
};

#endif