//  (C) Copyright Gennadiy Rozental 2005.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at 
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.

// Boost.Test

// each test module could contain no more then one 'main' file with init function defined
// alternatively you could define init function yourself

#include <boost/test/unit_test.hpp>
#include "../../include/x86_64/vector4.h"
#include "../../include/x86_64/matrix4x4.h"
namespace bt = boost::unit_test;

//____________________________________________________________________________//

// most frequently you implement test cases as a free functions with automatic registration
BOOST_AUTO_TEST_CASE( vector4_mul_matrix4x4 )
{
    Vector4 vector(1,2,3,4);
   
    Matrix4x4 matrix=    Matrix4x4(11.0,12.0,13.0,14.0,
                                   21.0,22.0,23.0,24.0,
                                   31.0,32.0,33.0,34.0,
                                   41.0,42.0,43.0,44.0);

    Vector4 result = vector.Multiply(matrix);
    Vector4 expected(310, 320 ,330,340);
    bool match =  result == expected;
    // reports 'error in "test1": test 2 == 1 failed'
    BOOST_TEST(match);
}
// most frequently you implement test cases as a free functions with automatic registration
BOOST_AUTO_TEST_CASE( vector4_mul_matrix4x4_perspective )
{
    Vector4 position(10,10,10,1);
    double n = 1;
    double f = 100;
    double w = 1;
    double h = 1;
    Matrix4x4 projectionMatrix=    Matrix4x4::CreatePerspectiveProjectioMatrix(n,f,w,h);

    Vector4 perspectiveCorrect = position.Multiply(projectionMatrix);
    float Sx = perspectiveCorrect.GetX() / perspectiveCorrect.GetW();
    float Sy =  perspectiveCorrect.GetY() / perspectiveCorrect.GetW();
    // reports 'error in "test1": test 2 == 1 failed'
    BOOST_TEST( 1 == 1 );
}

//____________________________________________________________________________//

