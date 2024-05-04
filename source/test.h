#ifndef BASELIB_TEST_H
#define BASELIB_TEST_H

#include <assert.h>
#include "baselib.h"

#define DEBUG_DELETE_NODES
#undef DEBUG_DELETE_NODES

DEFINE_NODE(int);
DEFINE_LINKED_LIST(int);

void lib_test(ll_int* linked_list){
    APPEND_LL(int, linked_list, 10);
    assert(linked_list->head->data == 10);
    assert(linked_list->tail->data == 10);
    assert(linked_list->length == 1);

    APPEND_LL(int, linked_list, 20);
    assert(linked_list->head->data == 10);
    assert(linked_list->tail->data == 20);
    assert(linked_list->length == 2);

    APPEND_LL(int, linked_list, 30);
    assert(linked_list->head->data == 10);
    assert(linked_list->tail->data == 30);
    assert(linked_list->length == 3);

    PREPEND_LL(int, linked_list, 1);
    assert(linked_list->head->data == 1);
    assert(linked_list->tail->data == 30);
    assert(linked_list->length == 4);

    PREPEND_LL(int, linked_list, 2);
    assert(linked_list->head->data == 2);
    assert(linked_list->tail->data == 30);
    assert(linked_list->length == 5);

    PREPEND_LL(int, linked_list, 3);
    assert(linked_list->head->data == 3);
    assert(linked_list->tail->data == 30);
    assert(linked_list->length == 6);

    INSERT_LL(int, linked_list, 0, 0);
    assert(linked_list->head->data == 0);
    assert(linked_list->tail->data == 30);
    assert(linked_list->length == 7);

    INSERT_LL(int, linked_list, 7, 7);
    assert(linked_list->head->data == 0);
    assert(linked_list->tail->data == 7);
    assert(linked_list->length == 8);

    INSERT_LL(int, linked_list, 4, 15);
    assert(linked_list->head->data == 0);
    assert(linked_list->head->next->next->next->next->data == 15);
    assert(linked_list->tail->data == 7);
    assert(linked_list->length == 9);

#ifdef DEBUG_DELETE_NODES
    DELETE_TAIL_LL(linked_list);
    assert(linked_list->head->data == 0);
    assert(linked_list->tail->data == 30);
    assert(linked_list->length == 8);

    DELETE_TAIL_LL(linked_list);
    assert(linked_list->head->data == 0);
    assert(linked_list->tail->data == 20);
    assert(linked_list->length == 7);

    DELETE_TAIL_LL(linked_list);
    assert(linked_list->head->data == 0);
    assert(linked_list->tail->data == 10);
    assert(linked_list->length == 6);

    DELETE_HEAD_LL(linked_list);
    assert(linked_list->head->data == 3);
    assert(linked_list->tail->data == 10);
    assert(linked_list->length == 5);

    DELETE_HEAD_LL(linked_list);
    assert(linked_list->head->data == 2);
    assert(linked_list->tail->data == 10);
    assert(linked_list->length == 4);

    DELETE_HEAD_LL(linked_list);
    assert(linked_list->head->data == 1);
    assert(linked_list->tail->data == 10);
    assert(linked_list->length == 3);

    DELETE_POS_LL(int, linked_list, 1);
    assert(linked_list->head->data == 1);
    assert(linked_list->tail->data == 10);
    assert(linked_list->length == 2);

    DELETE_POS_LL(int, linked_list, 0);
    assert(linked_list->head->data == 10);
    assert(linked_list->tail->data == 10);
    assert(linked_list->length == 1);
#endif
    //DELETE_VALUE_LL(int, linked_list, 7);

    PRINT_LL("%d -> ", int, linked_list);
}

#endif //BASELIB_TEST_H
