#include "../include/starfield.h"
#include "../include/starfield_config.h"


Starfield::Starfield(int nStars) : _starsCount(nStars) 
{

}

int Starfield::GetStarsCount()
{
  return _starsCount;
}


