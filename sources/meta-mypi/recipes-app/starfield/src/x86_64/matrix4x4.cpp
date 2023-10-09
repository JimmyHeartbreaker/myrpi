#include "../../include/x86_64/matrix4x4.h"
Matrix4x4::Matrix4x4(){}

Matrix4x4::Matrix4x4( float m0n0,float m0n1,float m0n2,float m0n3,
                      float m1n0,float m1n1,float m1n2,float m1n3,
                      float m2n0,float m2n1,float m2n2,float m2n3,
                      float m3n0,float m3n1,float m3n2,float m3n3) 
                      : _m0n0(m0n0),_m1n0(m1n0),_m2n0(m2n0) ,_m3n0(m3n0),
                        _m0n1(m0n1),_m1n1(m1n1),_m2n1(m2n1) ,_m3n1(m3n1),
                        _m0n2(m0n2),_m1n2(m1n2),_m2n2(m2n2) ,_m3n2(m3n2),
                        _m0n3(m0n3),_m1n3(m1n3),_m2n3(m2n3) ,_m3n3(m3n3)

{

}
Matrix4x4::~Matrix4x4() {
   
}
  

Matrix4x4 Matrix4x4::CreatePerspectiveProjectioMatrix( float n, float f, float w, float h)
{
    float twoN = 2 * n;
    float fMinusN = f-n;
    return Matrix4x4(twoN/w,0     ,0             ,0,
                      0    ,twoN/h,0             ,0,
                      0    ,0     ,f/fMinusN     ,1,
                      0    ,0     ,-((f*n)/fMinusN),0);    
}