#include "../include/starfield.h"
#include "../include/starfield_config.h"
#include <stdlib.h> 

double starfield_random()
{
  return (double)rand() / (double)RAND_MAX ;
}
Starfield::Starfield() : _starsCount(200)
{
  _stars = new Star[_starsCount];
  for(int i=0;i<_starsCount;i++)
  {
    _stars[i] = Star(Vector4(starfield_random()* 40 - 20,starfield_random()* 40 - 20,starfield_random() * 100+1,1));
  }
}

Star& Starfield::GetStar(int starNumber)
{
  return _stars[starNumber];
}
int Starfield::GetStarsCount()
{
  return _starsCount;
}


