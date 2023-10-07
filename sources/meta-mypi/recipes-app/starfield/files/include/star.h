#pragma once


#include "macros.h"

#include INCLUDE_FILE(vector4.h)


class Star
{
 private:
 Vector4 _point;

 public:
 Star();
 Star(Vector4 point);
 Vector4& GetPoint();
 void Translate(float x, float y, float z);
}; 
