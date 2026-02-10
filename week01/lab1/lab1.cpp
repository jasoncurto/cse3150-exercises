#include <iostream>
#include <vector>
#include "../include/doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  
using namespace std;

bool non_neg_prefix_sum(vector<int> x){
    int sum = 0;
    for(int i = 1; i<= x.size()-1; i++){
        sum += x.at(i);
        if(sum < 0){return false;}
    }
    return true;
}

int main() {
    int input;
    vector<int> lst;
    lst.push_back(0);
    cout << "Enter a value 1 or -1, or ^D for exit: " << endl;
    while (cin >> input) {
        if((input != -1) && (input != 1)){
            cout << "Cannot input this value. Terminating." << endl;
            return 0;
        }
        lst.push_back(input);
        cout << "Enter another value 1 or -1, or ^D for exit: " << endl;
    }
}

TEST_CASE("tes"){
    CHECK(non_neg_prefix_sum(vector<int> {1, -1, 1, 1, -1}));
    CHECK(non_neg_prefix_sum(vector<int> {1, 1, 1, 1, 1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {1, -1, -1, 1, -1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {-1, 1, 1, 1, 1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {-1, -1, -1, -1, -1, -1, -1}));
    CHECK_FALSE(non_neg_prefix_sum(vector<int> {1, 23, -15, 1, -1}));
}

