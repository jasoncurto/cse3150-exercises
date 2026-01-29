#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

#include "../include/doctest.h" 

#include "isPrimeFunction.h"



TEST_CASE("testing the isPrime.cpp function") { 
  CHECK_FALSE(isPrimeInteger(-2));
  CHECK_FALSE(isPrimeInteger(0));
  CHECK_FALSE(isPrimeInteger(1));
  CHECK_FALSE(isPrimeInteger(-101));
  CHECK_FALSE(isPrimeInteger(105));
  CHECK_FALSE(isPrimeInteger(49));
  CHECK_FALSE(isPrimeInteger(9999));
  CHECK(isPrimeInteger(2));
  CHECK(isPrimeInteger(3));
  CHECK(isPrimeInteger(101));
    

};