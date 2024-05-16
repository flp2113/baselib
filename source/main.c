#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "baselib.h"

DEFINE_QUEUE(int);

int main()
{
    int x[5] = {10, 20, 30, 40, 50};

    char* z[5] = {"Felipe", "Marcos", "Thales", "Joao", "Rapha"};

    int y = binary_search(x, 0, 4, 30);

    printf("%d\n", y);

    PRINT_ARRAY("%s ", z, 5);

    return 0;
}