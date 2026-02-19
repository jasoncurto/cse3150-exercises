#include <iostream>
#include <cmath>
#include "func.h"
using namespace std;

void initialize_array(int* array, int size);
bool non_neg_prefix_sum(int* x, int size);
int32_t pseudoRandom(int limit);
void fisherYates(int *array, int totalElements, int (*randomFcn)(int limit));

int main() {

    srand(0);

    int size;
    cout << "Enter an integer: " ;
    if(!(cin >> size)){ return 1;}
    size *= 2;
    
    int trials;
    cout << "How many trials would you like to run?: ";
    if(!(cin >> trials)){ return 1;}

    int *array = new int[size];
    initialize_array(array, size);

    int count = 0;
    for(int i = 0; i < trials; i++){
        fisherYates(array, size, pseudoRandom);
        if(non_neg_prefix_sum(array, size)){
            count++;
        }
    }
    cout << "The number of lists that have a positive prefix sum is: " << count << endl;
    cout << "Computed proportion of randomly permutated arrays of 1s and -1s of size " << size << " is: " << (double)count/trials << endl;

    delete[] array;
    return 0;
}