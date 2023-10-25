#include "gtest/gtest.h"
#include "../../include/x86_64/vector4.h"
#include "../../include/x86_64/matrix4x4.h"

namespace {

TEST( vector4, mul_matrix4x4 )
{
    //arrange

    Vector4 vector(1,2,3,4);
   
    Matrix4x4 matrix=    Matrix4x4(11.0,12.0,13.0,14.0,
                                   21.0,22.0,23.0,24.0,
                                   31.0,32.0,33.0,34.0,
                                   41.0,42.0,43.0,44.0);

    //act
    Vector4 result = vector.Multiply(matrix);

    //assert
    Vector4 expected(310, 320 ,330,340);    
    EXPECT_EQ(result,expected);
}
TEST( vector4, mul_matrix4x4_perspective )
{
    //arrange
    Vector4 position(10,10,10,1);
    double n = 1;
    double f = 100;
    double w = 1;
    double h = 1;
    Matrix4x4 projectionMatrix=    Matrix4x4::CreatePerspectiveProjectioMatrix(n,f,w,h);

    //act
    Vector4 perspectiveCorrect = position.Multiply(projectionMatrix);
    float Sx = perspectiveCorrect.GetX() / perspectiveCorrect.GetW();
    float Sy =  perspectiveCorrect.GetY() / perspectiveCorrect.GetW();
    
    //assert
    EXPECT_EQ( 2 ,Sx );
    EXPECT_EQ( 2 ,Sy );
}

//____________________________________________________________________________//
}

