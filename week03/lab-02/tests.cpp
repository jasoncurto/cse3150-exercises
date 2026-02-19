#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "func.h"

bool non_neg_prefix_sum(int* x, int size);
int32_t pseudoRandom(int limit);

TEST_CASE("Testing non_neg_prefix_sum") {
    int arr1[] = {1, -1, 1, -1};
    CHECK(non_neg_prefix_sum(arr1, 4) == true);

    int arr2[] = {1, -1, -1, 1};
    CHECK(non_neg_prefix_sum(arr2, 4) == false);

    int arr3[] = {-1, 1, 1, -1};
    CHECK(non_neg_prefix_sum(arr3, 4) == false);

    int arr4[] = {1, 1, -1, -1};
    CHECK(non_neg_prefix_sum(arr4, 4) == true);
}

TEST_CASE("Testing pseudoRandom") { // with our compiler, those are the first 4 output values for srand(0) and limit 10
    srand(0);

    CHECK(pseudoRandom(10) == 6);
    CHECK(pseudoRandom(10) == 10);
    CHECK(pseudoRandom(10) == 6);
    CHECK(pseudoRandom(10) == 2);
}

TEST_CASE("Testing fisherYates") {
    srand(0);
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 2, 1, 3, 4}; // with our compiler and srand(0), this is th output of fisher-yates for the input array

    fisherYates(arr, 5, pseudoRandom);

    for (int i = 0; i < 5; i++) {
        CHECK(arr[i] == expected[i]);
    }
}

TEST_CASE("Testing initialize_array") {
    int arr[6];
    initialize_array(arr, 6);
    CHECK(arr[0] == 1);
    CHECK(arr[1] == 1);
    CHECK(arr[2] == 1);
    CHECK(arr[3] == -1);
    CHECK(arr[4] == -1);
    CHECK(arr[5] == -1);
}