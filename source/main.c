#include <stdlib.h>

#include "baselib.h"

DEFINE_NODE(int);
DEFINE_LINKED_LIST(int);

int main(){
    ll_int linked_list;

    APPEND_LL(int, &linked_list, 10);
    APPEND_LL(int, &linked_list, 20);
    APPEND_LL(int, &linked_list, 30);

    PREPEND_LL(int, &linked_list, 69);
    PREPEND_LL(int, &linked_list, 70);

    INSERT_LL(int, &linked_list, 5, 555);
    INSERT_LL(int, &linked_list, 6, 333);

    //DELETE_TAIL_LL(&linked_list);

    //DELETE_HEAD_LL(&linked_list);

    DELETE_POS_LL(int, &linked_list, 6);

    PRINT_LL("%d -> ", int, &linked_list);

    return SUCCESS;
}