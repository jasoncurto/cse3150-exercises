#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include <vector>
#include "prefix_sum.h"
using namespace std;

TEST_CASE("tes"){
    CHECK(non_neg_prefix_sum(vector<int> {1, -1, 1, 1, -1}));
    CHECK(non_neg_prefix_sum(vector<int> {1, 1, 1, 1, 1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {0}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {1, 0}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {1, -1, -1, 1, -1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {-1, 1, 1, 1, 1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {-1, -1, -1, -1, -1, -1, -1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {1, 23, -15, 1, -1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {-23, 23, -15, 1, -1}));

    CHECK(non_pos_prefix_sum(vector<int> {-1, -1, -1, -1, -1, -1, -1}));
    CHECK_FALSE(non_pos_prefix_sum(vector<int> {1, -22, 1, 1, -1}));
    CHECK_FALSE(non_pos_prefix_sum(vector<int> {1, -1, 1, 1, -1}));
    CHECK_FALSE(non_pos_prefix_sum(vector<int> {1, 1, 1, 1, 1}));
    CHECK_FALSE(non_pos_prefix_sum(vector<int> {0}));
    CHECK_FALSE(non_pos_prefix_sum(vector<int> {1, 0}));
    CHECK_FALSE(non_pos_prefix_sum(vector<int> {-1, 1, 1, 1, 1}));
    CHECK_FALSE(non_pos_prefix_sum(vector<int> {1, 23, -15, 1, -1}));
    CHECK_FALSE(non_pos_prefix_sum(vector<int> {-23, 23, -15, 1, -1}));
};