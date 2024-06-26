#ifndef BASELIB_ALGO_H
#define BASELIB_ALGO_H

#include <stdlib.h>
#include <time.h>

void rand_fill_array(int array[], int size, int limit);
void swap_nums(int*, int*);
int array_min(int[], int);
int array_max(int[], int);
int factorial(int);
int fibonacci(int);
int binary_search(int[], int, int, int);
void selection_sort(int[], int);

#endif //BASELIB_ALGO_H
