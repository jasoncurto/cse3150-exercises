#ifndef FUNC_H
#define FUNC_H

#include <cmath>

inline void initialize_array(int* array, int size){
    for (int i=0 ; i < size ; i++) {
        if (i < size/2) {
            array[i] = 1;
        } else {
            array[i] = -1;
        }
    }
}

inline bool non_neg_prefix_sum(int* x, int size){ // changed from last assignment, we can assume only 1, -1 are input now
    int sum = 0;
    for(int i = 0; i< size; i++){
        sum += x[i];
        if(sum < 0){return false;}
    }
    return true;
}

inline int32_t pseudoRandom(int limit) {
    
    int value = rand() % (limit+1);
    return value;
}


inline void fisherYates(int *array, int totalElements, int (*randomFcn)(int limit)) {
    for(int i=totalElements -1; i > 0 ; i--) {
        int randomIndex = randomFcn(i);
        int temp = array[i];
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
}

#endif