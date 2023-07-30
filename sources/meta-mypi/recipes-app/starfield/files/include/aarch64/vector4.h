#pragma once

#include "../aarch64/matrix4x4.h"
#include "arm_neon.h"

class Vector4
{
 private:
 float32x4_t _v;
 Vector4(float32x4_t v);

 public:
 Vector4(float x,float y,float z,float w);
 Vector4 Multiply(Matrix4x4& mat4x4);      
 Vector4 Add(Vector4 v);
 bool operator==(const Vector4& cmp) const 
 { 
    uint32x4_t compared = vceqq_f32(_v,cmp._v);
    return compared[0] != 0 && compared[1] != 0 && compared[2] != 0 && compared[3] != 0;
}
 bool operator!=(const Vector4& cmp) const 
 { 
    uint32x4_t compared = vceqq_f32(_v,cmp._v);
    return compared[0] == 0 || compared[1] == 0 || compared[2] == 0 || compared[3] == 0;
}

 float GetX();    
 float GetY();
 float GetZ();
 float GetW();
 
}; 
