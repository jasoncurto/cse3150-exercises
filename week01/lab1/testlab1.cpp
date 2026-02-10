#include "../include/doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>


TEST_CASE("tes"){
    CHECK(non_neg_prefix_sum(vector<int> {1, -1, 1, 1, -1}));
    CHECK(non_neg_prefix_sum(vector<int> {1, 1, 1, 1, 1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {1, -1, -1, 1, -1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {-1, 1, 1, 1, 1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {-1, -1, -1, -1, -1, -1, -1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {1, 23, -15, 1, -1}));
}

