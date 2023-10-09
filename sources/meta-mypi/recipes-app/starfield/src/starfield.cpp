#include "../include/starfield.h"
#include "../include/starfield_config.h"
#include <stdlib.h> 
#include <iterator>
#include <vector>
double starfield_random()
{
  return (double)rand() / (double)RAND_MAX ;
}
Starfield::Starfield() : _starsCount(200)
{
  for(int i=0;i<_starsCount;i++)
  {
    _stars.push_back(Star(Vector4(starfield_random()* 40 - 20,starfield_random()* 40 - 20,starfield_random() * 100+1,1)));
    
  }
}

 std::vector<Star>& Starfield::GetStars()
 {
  return _stars;
 }

Star& Starfield::GetStar(int starNumber)
{
  auto x = std::begin(_stars);
  return _stars[starNumber];
}



