#include "../../include/x86_64/vector4.h"

Vector4::Vector4(float x,float y,float z,float w) 
                 : _x(x),_y(y),_z(z) ,_w(w)

{   

}

Vector4 Vector4::Multiply(Matrix4x4& mat4x4)
{    
    return Vector4(_x * mat4x4._m0n0 + _y * mat4x4._m1n0 + _z * mat4x4._m2n0 + _w * mat4x4._m3n0,
                   _x * mat4x4._m0n1 + _y * mat4x4._m1n1 + _z * mat4x4._m2n1 + _w * mat4x4._m3n1,
                   _x * mat4x4._m0n2 + _y * mat4x4._m1n2 + _z * mat4x4._m2n2 + _w * mat4x4._m3n2,
                   _x * mat4x4._m0n3 + _y * mat4x4._m1n3 + _z * mat4x4._m2n3 + _w * mat4x4._m3n3);
}
Vector4 Vector4::Add(Vector4 a)
{
    return Vector4(_x + a._x,_y + a._y,_z + a._z,_w + a._w);
}
float Vector4::GetX()
{
    return _x;
}
float Vector4::GetY()
{
    return _y;
}
float Vector4::GetZ()
{
    return _z;
}
float Vector4::GetW()
{
    return _w;
}