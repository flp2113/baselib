#include "algo.h"

int array_min(int array[], int size){
    int min = array[0], min_index = 0;
    for(int i = 1; i < size; i++){
        if(array[i] < min){
            min = array[i];
            min_index = i;
        }
    }
    return min_index;
}

int array_max(int array[], int size){
    int max = array[0], max_index = 0;
    for(int i = 1; i < size; i++){
        if(array[i] > max){
            max = array[i];
            max_index = i;
        }
    }
    return max_index;
}

int factorial(int x){
    if(x == 1){ return 1; }
    return x * factorial(x - 1);
}

int fibonacci(int index){
    int a = 0, b = 1, c = 1;
    for(int i = 2; i <= index; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int binary_search(int array[], int low, int high, int target){
    int mid = (low + high) / 2;
    if(low > high){ return -1; }
    else if(array[mid] == target){ return mid; }
    else if(array[mid] > target){ return binary_search(array, low, mid - 1, target); }
    else{ return binary_search(array, mid + 1, high, target); }
}

void selection_sort(int array[], int size){
    for(int i = 0; i < size; i++){
        int min = array[i], min_index = i;
        for(int j = i + 1; j < size; j++){
            if(array[j] < min){
               min = array[j];
               min_index = j;
            }
        }
        if(min_index != i){
            swap(&array[min_index], &array[i]);
        }
    }
}