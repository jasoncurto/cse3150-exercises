#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <chrono>
#include <iostream>
#include "bigint_fractions.cpp"
using namespace std::chrono;

TEST_CASE("Testing BigInt Fractions and Performance") {
    const int iterations = 10000;

    SUBCASE("checking for overflow in memory") {
        BigFraction f1 = {bigint("1"), bigint("50000")};
        BigFraction f2 = {bigint("1"), bigint("50000")};
        BigFraction res = sumFracs(f1, f2);
        CHECK(fracToString(res) == "100000/2500000000");
    }

    SUBCASE("int*int") {
        int a = 32000;
        int b = 32000;
        auto start = high_resolution_clock::now();
        for(int i = 0; i < iterations; ++i) {
            volatile int res = a * b;
        }
        auto end = high_resolution_clock::now();
        cout << "int*int (" << iterations << " iters): " 
             << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;
    }

    SUBCASE("long*long") { //interestingly longlong is faster than intint :O
        long a = 123456789L;
        long b = 987654321L;
        auto start = high_resolution_clock::now();
        for(int i = 0; i < iterations; ++i) {
            volatile long res = a * b;
        }
        auto end = high_resolution_clock::now();
        cout << "long*long (" << iterations << " iters): " 
             << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;
    }

    SUBCASE("Performance Benchmark") {
        BigFraction f1 = {bigint("123456789"), bigint("987654321")};
        BigFraction f2 = {bigint("987654321"), bigint("123456789")};

        auto start = high_resolution_clock::now();
        for(int i = 0; i < iterations; ++i) {
            multFracs(f1, f2);
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "bigint * biging (" << iterations << " iterations): " 
             << duration.count() << " microseconds" << endl;    
             
        CHECK(duration.count() > 0); 
    }
}