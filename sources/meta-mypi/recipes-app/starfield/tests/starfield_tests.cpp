#include "gtest/gtest.h"
#include "../include/star.h"
namespace {


TEST(Star, Translate)
{
    //arrange
    Star s(Vector4(0,0,0,0));

    //act
    s.Translate(100,100,100);

    //assert
    EXPECT_EQ( s.GetPoint() , Vector4(100,100,100,0) );
}
}