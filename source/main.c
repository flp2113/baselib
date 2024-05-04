#include <stdlib.h>

#include "baselib.h"
#include "test.h"

int main(){
    ll_int linked_list = {NULL, NULL, 0};

    lib_test(&linked_list);

    node_int* my_node = SEARCH_VALUE_LL(int, &linked_list, 7);

    printf("%d", my_node->data);

    return SUCCESS;
}