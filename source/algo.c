#include "algo.h"

int binary_search(int array[], int low, int high, int target){
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

int binary_search_recursive(int array[], int low, int high, int target){
    if(low > high){
        return -1;
    }

    int mid = (low + high) / 2;
    if(array[mid] == target){
        return mid;
    } else if(array[mid] > target){
        return binary_search_recursive(array, low, mid - 1, target);
    } else {
        return binary_search_recursive(array, mid + 1, high, target);
    }
}


