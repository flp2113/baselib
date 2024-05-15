#include "algo.h"

int binary_search(const int* array, int low, int high, int target){
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(array[mid] == target){
            return mid;
        } else if(array[mid] > target){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

