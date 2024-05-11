#include <stdlib.h>
#include <stdio.h>

#include "baselib.h"

DEFINE_QUEUE(int);

int main(){
    /*
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
    */

    /*
    stack_int stack = {NULL, 0};

    STACK_PUSH(int, &stack, 10);
    STACK_PUSH(int, &stack, 20);
    STACK_PUSH(int, &stack, 30);

    int x = STACK_POP(int, &stack);

    printf("%d", stack.top->data);
    printf("%d", x);
    */

    queue_int queue = {NULL, NULL, 0};

    QUEUE_ENQUEUE(int, &queue, 10);
    QUEUE_ENQUEUE(int, &queue, 20);
    QUEUE_ENQUEUE(int, &queue, 30);

    printf("%d ", queue.head->data);
    printf("%d ", queue.head->next->data);
    printf("%d ", queue.head->next->next->data);

    int x = QUEUE_DEQUEUE(int, &queue);
    QUEUE_DEQUEUE(int, &queue);
    QUEUE_DEQUEUE(int, &queue);

    printf("FIRST: %d ", x);

    return SUCCESS;
}