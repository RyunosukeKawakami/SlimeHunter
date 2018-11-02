#pragma once
#include "UI.h"

class Hitpoint : public UI{
private:
    int hp_now;
    int hp_max;
  float hp_per;
    int length;
    int height;

public:
         Hitpoint();
   float Calculate(float);
    void Draw();
    
};