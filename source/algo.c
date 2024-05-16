#include "algo.h"

int binary_search(int array[], int low, int high, int target){
    int mid = (low + high) / 2;
    if(low > high){ return -1; }
    else if(array[mid] == target){ return mid; }
    else if(array[mid] > target){ return binary_search(array, low, mid - 1, target); }
    else{ return binary_search(array, mid + 1, high, target); }
}


