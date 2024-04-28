#include <stdlib.h>

#include "baselib.h"

DEFINE_NODE(int);
DEFINE_LINKED_LIST(int);


int main(){
    ll_int linked_list  = {NULL, NULL, 0};

    APPEND_LL(int, &linked_list, 10);
    APPEND_LL(int, &linked_list, 10);
    APPEND_LL(int, &linked_list, 10);

    PRINTLL("%d -> ", int, &linked_list);

    return 0;
}