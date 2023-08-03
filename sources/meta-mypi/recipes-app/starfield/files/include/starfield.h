#pragma once

#include "star.h"
#include <vector>

class Starfield
{
 private:
 int _starsCount;
 std::vector<Star> _stars;
 public:
 Starfield();
 Star& GetStar(int starNumber);
 std::vector<Star>& GetStars();
}; 
