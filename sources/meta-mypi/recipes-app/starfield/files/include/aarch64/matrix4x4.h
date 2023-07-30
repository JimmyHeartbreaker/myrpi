#pragma once

#include "arm_neon.h"

class Matrix4x4
{
 private:
 float32x4x4_t _mat;
 public:
 Matrix4x4();
 Matrix4x4(float m0n0,float m1n0,float m2n0,float m3n0,
           float m0n1,float m1n1,float m2n1,float m3n1,
           float m0n2,float m1n2,float m2n2,float m3n2,
           float m0n3,float m1n3,float m2n3,float m3n3);
  ~Matrix4x4(); 
  friend class Vector4;
           
 static Matrix4x4 CreatePerspectiveProjectioMatrix( float n, float f, float w, float h);
 static Matrix4x4 CreatePerspectiveProjectioMatrixFov( float fov,float aspectRatio, float near, float far);
}; 
