#include "../include/star.h"



Star::Star() : _point(Vector4(0.0,0.0,0.0,0.0))
{

}
Star::Star(Vector4 point) : _point(point) 
{

}
Vector4& Star::GetPoint()
{
    return _point;
}

void Star::Translate(float x, float y, float z)
{
    _point = _point.Add(Vector4(x,y,z,0));
}

