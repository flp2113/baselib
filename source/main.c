#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "baselib.h"

DEFINE_QUEUE(int);

int main()
{
    int x[5] = {10, 20, 30, 40, 50};

    int y = binary_search_recursive(x, 0, 4, 60);

    printf("%d", y);

    return 0;
}