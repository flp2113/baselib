#ifndef BASELIB_TEST_H
#define BASELIB_TEST_H

#include <assert.h>
#include "baselib.h"

DEFINE_NODE(int);
DEFINE_LINKED_LIST(int);

void lib_test(ll_int* ll){
    APPEND_LL(int, ll, 10);
    assert(ll->head->data == 10);
    assert(ll->tail->data == 10);
    assert(ll->length == 1);

    APPEND_LL(int, ll, 20);
    assert(ll->head->data == 10);
    assert(ll->tail->data == 20);
    assert(ll->length == 2);

    APPEND_LL(int, ll, 30);
    assert(ll->head->data == 10);
    assert(ll->tail->data == 30);
    assert(ll->length == 3);

    PREPEND_LL(int, ll, 1);
    assert(ll->head->data == 1);
    assert(ll->tail->data == 30);
    assert(ll->length == 4);

    PREPEND_LL(int, ll, 2);
    assert(ll->head->data == 2);
    assert(ll->tail->data == 30);
    assert(ll->length == 5);

    PREPEND_LL(int, ll, 3);
    assert(ll->head->data == 3);
    assert(ll->tail->data == 30);
    assert(ll->length == 6);

    INSERT_LL(int, ll, 0, 0);
    assert(ll->head->data == 0);
    assert(ll->tail->data == 30);
    assert(ll->length == 7);

    INSERT_LL(int, ll, 7, 7);
    assert(ll->head->data == 0);
    assert(ll->tail->data == 7);
    assert(ll->length == 8);

    INSERT_LL(int, ll, 4, 15);
    assert(ll->head->data == 0);
    assert(ll->head->next->next->next->next->data == 15);
    assert(ll->tail->data == 7);
    assert(ll->length == 9);

    DELETE_TAIL_LL(ll);
    assert(ll->head->data == 0);
    assert(ll->tail->data == 30);
    assert(ll->length == 8);

    DELETE_TAIL_LL(ll);
    assert(ll->head->data == 0);
    assert(ll->tail->data == 20);
    assert(ll->length == 7);

    DELETE_TAIL_LL(ll);
    assert(ll->head->data == 0);
    assert(ll->tail->data == 10);
    assert(ll->length == 6);

    DELETE_HEAD_LL(ll);
    assert(ll->head->data == 3);
    assert(ll->tail->data == 10);
    assert(ll->length == 5);

    DELETE_HEAD_LL(ll);
    assert(ll->head->data == 2);
    assert(ll->tail->data == 10);
    assert(ll->length == 4);

    DELETE_HEAD_LL(ll);
    assert(ll->head->data == 1);
    assert(ll->tail->data == 10);
    assert(ll->length == 3);

    DELETE_POS_LL(int, ll, 1);
    assert(ll->head->data == 1);
    assert(ll->tail->data == 10);
    assert(ll->length == 2);

    DELETE_POS_LL(int, ll, 0);
    assert(ll->head->data == 10);
    assert(ll->tail->data == 10);
    assert(ll->length == 1);

    PRINT_LL("%d -> ", int, ll);
}

#endif //BASELIB_TEST_H
