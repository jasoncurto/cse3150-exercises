#include <iostream>
#include <vector>
#include <string>
#include "prefix_sum.h"

using namespace std;

int main() {
    int input;
    vector<int> lst;
    int method;

    cout << "Did you want to calculate non-neg or non-pos prefix sum? 0 for non-neg, 1 for non-pos: " << endl;
    cin >> method;
    cin.ignore(9999, '\n');
    if(method != 1 && method != 0){cout << "Cannot input this value. Terminating." << endl; return 1;}

    cout << "To begin, enter a value 1 or -1, or ^D for exit: " << endl;

    while (cin >> input) {
        if((input != -1) && (input != 1)){
            cout << "Cannot input this value. Terminating." << endl;
            return 1;
        }
        lst.push_back(input);
        if(method == 0){
            if(!non_neg_prefix_sum(lst)){
                cout << "Prefix sum dropped below threshold. Terminating." << endl;
                return 1;
            }
        }
        else{
            if(!non_pos_prefix_sum(lst)){
                cout << "Prefix sum rose above threshold. Terminating." << endl;
                return 1;
            }
        }
        cout << "Enter another value 1 or -1, or ^D for exit: " << endl;
    }
}


