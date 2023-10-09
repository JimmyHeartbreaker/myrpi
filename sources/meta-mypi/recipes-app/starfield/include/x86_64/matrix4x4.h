#pragma once

class Matrix4x4
{
 private:
 float _m0n0;
 float _m1n0;
 float _m2n0;
 float _m3n0;

 float _m0n1;
 float _m1n1;
 float _m2n1;
 float _m3n1;

 float _m0n2;
 float _m1n2;
 float _m2n2;
 float _m3n2;

 float _m0n3;
 float _m1n3;
 float _m2n3;
 float _m3n3;
 public:
 Matrix4x4();
 Matrix4x4(float m0n0,float m1n0,float m2n0,float m3n0,
           float m0n1,float m1n1,float m2n1,float m3n1,
           float m0n2,float m1n2,float m2n2,float m3n2,
           float m0n3,float m1n3,float m2n3,float m3n3);
  ~Matrix4x4(); 
  friend class Vector4;
           
 static Matrix4x4 CreatePerspectiveProjectioMatrix( float near, float far, float widthN, float heightN);
 static Matrix4x4 CreatePerspectiveProjectioMatrixFov( float fov,float aspectRatio, float near, float far);
}; 
