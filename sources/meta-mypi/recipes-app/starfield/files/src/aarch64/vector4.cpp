#include "../../include/aarch64/vector4.h"
#include "arm_neon.h"

Vector4::Vector4(float x,float y,float z,float w) : _v{x,y,z,w}
{       
}

Vector4::Vector4(float32x4_t v) : _v(v)
{       
}

Vector4 Vector4::Multiply(Matrix4x4& mat4x4)
{      
    float32x4_t result = vmulxq_laneq_f32(mat4x4._mat.val[0],_v,0);
                result = vmlaq_laneq_f32(result,mat4x4._mat.val[1],_v,1);
                result = vmlaq_laneq_f32(result,mat4x4._mat.val[2],_v,2);  
    return vmlaq_laneq_f32(result,mat4x4._mat.val[3],_v,3);
}

Vector4 Vector4::Add(Vector4 a)
{
    return Vector4(vaddq_f32(_v,a._v));
}

float Vector4::GetX()
{
    return _v[0];
}
float Vector4::GetY()
{
    return _v[1];
}
float Vector4::GetZ()
{
    return _v[2];
}
float Vector4::GetW()
{
    return _v[3];
}