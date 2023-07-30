#pragma once

#include "matrix4x4.h"
class Vector4
{
 private:
 float _x;
 float _y;
 float _z;
 float _w;

 public:
 Vector4(float x,float y,float z,float w);
 Vector4 Multiply(Matrix4x4& mat4x4);      
 Vector4 Add(Vector4 v);    
  bool operator==(const Vector4& cmp) const 
 { 
    
    return _x == cmp._x && _y == cmp._y && _z == cmp._z && _w == cmp._w;
}
 bool operator!=(const Vector4& cmp) const 
 { 
    return _x != cmp._x || _y != cmp._y || _z != cmp._z || _w != cmp._w;
}

 float GetX();    
 float GetY();
 float GetZ();
 float GetW();
}; 
