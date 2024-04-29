#ifndef BASELIB_DS_H
#define BASELIB_DS_H

#include <malloc.h>
#include <stdio.h>

#include "defs.h"
//TODO: ERROR.h

/**
 * @brief Generic node struct.
 * @param TYPE Data type. (int, float, double, char, ...)
 **/
#define DEFINE_NODE(TYPE)                       \
    typedef struct node_##TYPE{                 \
        TYPE data;                              \
        struct node_##TYPE* next;               \
        struct node_##TYPE* prev;               \
    } node_##TYPE;

/**
 * @brief Generic linked list struct.
 * @param TYPE Data type. (int, float, double, char, ...)
 **/
#define DEFINE_LINKED_LIST(TYPE)                \
    typedef struct ll_##TYPE{                   \
        struct node_##TYPE* head;               \
        struct node_##TYPE* tail;               \
        unsigned int length;                    \
    } ll_##TYPE;

/**
 * @brief Print linked list.
 * @param FORMAT String formatter. ("%d", "%f", "%lf", "c", ...)
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @return Void.
 **/
#define PRINT_LL(FORMAT, TYPE, LL) ({           \
    node_##TYPE* current_node = (LL)->head;     \
    while(current_node != NULL){                \
        printf(FORMAT, current_node->data);     \
        current_node = current_node->next;      \
    }                                           \
    printf("NULL");                             \
})

/**
 * @brief Create node.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Node pointer.
 **/
#define CREATE_NODE(TYPE, DATA) ({                                          \
    node_##TYPE* new_node = (node_##TYPE*)malloc(sizeof(node_##TYPE));      \
    new_node->data = (DATA);                                                \
    new_node->next = NULL;                                                  \
    new_node->prev = NULL;                                                  \
    new_node;                                                               \
})

/**
 * @brief Append node to a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Void.
 **/
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

/**
 * @brief Prepend node to a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Void.
 **/
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

/**
 * @brief Insert a node in a specified position in a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param INDEX Index to be inserted in linked list. (0, 1, 2, ...)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Void.
 **/
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

//TODO: delete_end()
//TODO: delete_start()
//TODO: delete_pos()
//TODO: delete_value()
//TODO: search_pos()
//TODO: search_value()
//TODO: concat()
//TODO: sort()
//TODO: merge()
//TODO: split()

/**
 * @brief Get the length of a linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Size of the linked list.
 **/
#define LENGTH_LL(LL) ({ \
    (LL)->length;        \
})

/**
 * @brief Pointer to the head of the linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Pointer to the head of the linked list.
 **/
#define HEAD_LL(LL) ({  \
    (LL)->head;         \
})

/**
 * @brief Pointer to the tail of the linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Pointer to the tail of the linked list.
 **/
#define TAIL_LL(LL) ({  \
    (LL)->tail;         \
})

#endif //BASELIB_DS_H
