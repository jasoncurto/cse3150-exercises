#ifndef PREFIX_SUM_H
#define PREFIX_SUM_H
#include <vector> 

bool non_neg_prefix_sum(std::vector<int> x){
   // if(x.empty()){return false;}
    int sum = 0;
    x.insert(x.begin(), 0);
    for(int i = 0; i< x.size(); i++){
        if (x.at(i) != 1 && x.at(i) != -1){
            if (!(i == 0 && x.at(i) == 0)){return false;}
        } //redundant without doctest
        sum += x.at(i);
        if(sum < 0){return false;}
    }
    return true;
}

bool non_pos_prefix_sum(std::vector<int> y){
    int sum = 0;
    y.insert(y.begin(), 0);
    for(int i = 0; i< y.size(); i++){
        if (y.at(i) != 1 && y.at(i) != -1){
            if (!(i == 0 && y.at(i) == 0)){return false;}
        } //redundant without doctest
        sum += y.at(i);
        if(sum > 0){return false;}
    }
    return true;
}
#endif