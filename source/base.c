#include "base.h"

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_array(int* array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(array + i));
    }
}
