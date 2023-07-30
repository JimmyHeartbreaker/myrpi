#pragma once

#ifdef SF_X86
#include "./x86_64/vector4.h"
#else
#include "./aarch64/vector4.h"
#endif

class Star
{
 private:
 Vector4 _point;

 public:
 Star();
 Star(Vector4 point);
 Vector4 GetPoint();
 void Translate(float x, float y, float z);
}; 
