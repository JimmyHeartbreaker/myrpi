#include "gtest/gtest.h"
#include "../include/star.h"
namespace {


TEST(Star, Translate)
{
    Star s(Vector4(0,0,0,0));
    s.Translate(100,100,100);
    EXPECT_EQ( s.GetPoint() , Vector4(100,100,100,0) );
}
}