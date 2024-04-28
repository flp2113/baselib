#ifndef BASELIB_DS_H
#define BASELIB_DS_H

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "defs.h"
//TODO: ERROR.h

#define DEFINE_NODE(TYPE)                       \
    typedef struct node_##TYPE{                 \
        TYPE data;                              \
        struct node_##TYPE* next;               \
        struct node_##TYPE* prev;               \
    } node_##TYPE;

#define DEFINE_LINKED_LIST(TYPE)                \
    typedef struct ll_##TYPE{                   \
        struct node_##TYPE* head;               \
        struct node_##TYPE* tail;               \
        unsigned int length;                    \
    } ll_##TYPE;

#define PRINTLL(FORMAT, TYPE, LL) ({            \
    node_##TYPE* current_node = (LL)->head;     \
    while(current_node != NULL){                \
        printf(FORMAT, current_node->data);     \
        current_node = current_node->next;      \
    }                                           \
    printf("NULL");                             \
})

#define CREATE_NODE(TYPE, DATA) ({                                          \
    node_##TYPE* new_node = (node_##TYPE*)malloc(sizeof(node_##TYPE));      \
    new_node->data = (DATA);                                                \
    new_node->next = NULL;                                                  \
    new_node->prev = NULL;                                                  \
    new_node;                                                               \
})

#define APPEND_LL(TYPE, LL, DATA) ({                        \
    node_##TYPE* new_node = CREATE_NODE(TYPE, DATA);        \
    if((LL)->head == NULL){                                 \
        (LL)->head = new_node;                              \
        (LL)->tail = new_node;                              \
    } else {                                                \
        new_node->prev = (LL)->tail;                        \
        (LL)->tail->next = new_node;                        \
        (LL)->tail = new_node;                              \
    }                                                       \
    (LL)->length++;                                         \
})

//TODO: prepend()
#define PREPEND_LL(TYPE, LL, DATA) ({                       \
    node_##TYPE* new_node = CREATE_NODE(TYPE, DATA);        \
    if((LL)->head == NULL){                                 \
        (LL)->head = new_node;                              \
        (LL)->tail = new_node;                              \
    } else {                                                \
        new_node->next = (LL)->head;                        \
        (LL)->head->prev = new_node;                        \
        (LL)->head = new_node;                              \
    }                                                       \
    (LL)->length++;                                         \
})

//TODO: insert()
#define INSERT_LL(TYPE, LL, INDEX, DATA) ({                 \
    if(INDEX < 0 || INDEX > (LL)->length){                  \
        puts("OUT OF BOUNDS LINKED LIST INSERTION.");       \
        exit(FAILURE);                                      \
    } else {                                                \
        node_##TYPE* new_node = CREATE_NODE(TYPE, DATA);    \
        if(INDEX == 0){                                     \
            if((LL)->length == 0){                          \
                (LL)->head = new_node;                      \
                (LL)->tail = new_node;                      \
            } else {                                        \
                new_node->next = (LL)->head;                \
                (LL)->head->prev = new_node;                \
                (LL)->head = new_node;                      \
            }                                               \
        } else if(INDEX == (LL)->length){                   \
                if((LL)->length == 0){                      \
                    (LL)->head = new_node;                  \
                    (LL)->tail = new_node;                  \
                } else {                                    \
                    new_node->prev = (LL)->tail;            \
                    (LL)->tail->next = new_node;            \
                    (LL)->tail = new_node;                  \
                }                                           \
        } else {                                            \
                node_##TYPE* current_node = (LL)->head;     \
                for(int i = 0; i < INDEX; i++){             \
                    current_node = current_node->next;      \
                }                                           \
                new_node->next = current_node;              \
                new_node->prev = current_node->prev;        \
                current_node->prev->next = new_node;        \
        }                                                   \
    }                                                       \
    (LL)->length++;                                         \
})

//TODO: pop()
//TODO: delete_start()
//TODO: delete_pos()
//TODO: delete_value()
//TODO: search_pos()
//TODO: search_value()
//TODO: length()
//TODO: concat()
//TODO: sort()
//TODO: merg()
//TODO: split()

#endif //BASELIB_DS_H
