#ifndef BASELIB_BASE_H
#define BASELIB_BASE_H

#include <stdio.h>

void swap(int* x, int* y);

#define PRINT_ARRAY(FORMAT, ARRAY, SIZE) ({\
    for(int i = 0; i < SIZE; i++){\
        printf(FORMAT, ARRAY[i]);\
    }\
})

#endif //BASELIB_BASE_H
