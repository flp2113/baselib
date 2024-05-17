#include "base.h"

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void rand_fill_array(int array[], int size, int limit){
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        array[i] = rand() % limit;
    }
}