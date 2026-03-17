#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "../include/doctest.h" 
#include "ComplexArray.h"
#include "Complex.h"
using namespace std;

// not doing doctests for Complex.h as we 
// already covered that in testComplex.cpp

TEST_CASE("testssssssssss") {

    SUBCASE("empty array move") {
        ComplexArray x(0);

        CHECK(x.getSize() == 0);

        ComplexArray movedArr = move(x);
        
        CHECK(movedArr.getSize() == 0);
    }

    SUBCASE("moving self") {
        ComplexArray x(2);
        x.modElementAtI(0, Complex(1.1, 2.2));
        x = move(x); 

        CHECK(x.getSize() == 2);
        CHECK(x.getSize() != 0);
    }

    SUBCASE("moving an already moved array") {
        ComplexArray x(5);
        ComplexArray y = move(x);
        ComplexArray z = move(x); 
        
        CHECK(x.getSize() == 0);
        CHECK(z.getSize() == 0);
        CHECK(y.getSize() == 5);
    }

    SUBCASE("checking overwriting a moved array x") {
        ComplexArray x(10);
        ComplexArray y(2);
        y = move(x); 

        CHECK(y.getSize() == 10);
        CHECK(x.getSize() == 0);
    }
}