#include <stdlib.h>

#include "baselib.h"
#include "test.h"

int main(){
    ll_int linked_list = {NULL, NULL, 0};
    ll_int linked_list2 = {NULL, NULL, 0};

    lib_test(&linked_list);
    lib_test(&linked_list2);

    CONCAT_LL(&linked_list, &linked_list2);

    DELETE_HEAD_LL(&linked_list);
    DELETE_TAIL_LL(&linked_list);
    node_int* head = HEAD_LL(&linked_list);

    printf("%d", head->data);

    PRINT_LL("%d -> ", int, &linked_list);


    return SUCCESS;
}