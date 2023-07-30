#pragma once

#include "star.h"

class Starfield
{
 private:
 int _starsCount;
 Star* _stars;
 public:
 Starfield();
 int GetStarsCount();
 Star& GetStar(int starNumber);
}; 
