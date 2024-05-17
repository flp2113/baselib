#ifndef BASELIB_BASE_H
#define BASELIB_BASE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int* x, int* y);

void rand_fill_array(int[], int, int);

#define PRINT_ARRAY(FORMAT, ARRAY, SIZE) ({\
    for(int i = 0; i < SIZE; i++){\
        printf(FORMAT, ARRAY[i]);\
    }                                      \
    puts("\n");\
})

#endif //BASELIB_BASE_H
