/** @file ds.h
 *  @brief Data structure functions.
 *  @author flp2113
 */

#ifndef BASELIB_DS_H
#define BASELIB_DS_H

#include <stdlib.h>
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
        puts("OUT OF BOUNDS LINKED LIST INSERTION.\n");     \
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

/**
 * @brief Remove the last node of the linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Void.
 **/
#define DELETE_TAIL_LL(LL) ({                                       \
    if((LL)->head == NULL){                                         \
        puts("DELETING TAIL NODE, BUT LINKED LIST IS EMPTY.\n");    \
        exit(FAILURE);                                              \
    } else if((LL)->length == 1){                                   \
        free((LL)->head);                                           \
        (LL)->head = NULL;                                          \
        (LL)->tail = NULL;                                          \
    } else {                                                        \
        (LL)->tail = (LL)->tail->prev;                              \
        free((LL)->tail->next);                                     \
        (LL)->tail->next = NULL;                                    \
    }                                                               \
    (LL)->length--;                                                 \
})

/**
 * @brief Remove the first node of the linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Void.
 **/
#define DELETE_HEAD_LL(LL) ({ \
    if((LL)->head == NULL) { \
        puts("DELETING HEAD NODE, BUT LINKED LIST IS EMPTY. ");     \
        exit(FAILURE);                                              \
    } else if((LL)->length == 1) {                                  \
        free((LL)->head);                                           \
        (LL)->head = NULL;                                          \
        (LL)->tail = NULL;                                          \
    } else {                                                        \
        (LL)->head = (LL)->head->next;                              \
        free((LL)->head->prev);                                     \
        (LL)->head->prev = NULL;                                    \
    }                                                               \
    (LL)->length--;                                                 \
})

//TODO: delete_pos() WORKING ON
/**
 * @brief Delete a node in a specified position in a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param INDEX Index to be deleted in linked list. (0, 1, 2, ...)
 * @return Void.
 **/
#define DELETE_POS_LL(TYPE, LL, INDEX) ({                               \
    if(INDEX < 0 || INDEX > ((LL)->length - 1)){                        \
        puts("OUT OF BOUNDS LINKED LIST DELETION.\n");                  \
        exit(FAILURE);                                                  \
    } else {                                                            \
        if(INDEX == 0){                                                 \
            if((LL)->length == 1){                                      \
                free((LL)->head);                                       \
                (LL)->head = NULL;                                      \
                (LL)->tail = NULL;                                      \
            } else {                                                    \
                (LL)->head = (LL)->head->next;                          \
                free((LL)->head->prev);                                 \
                (LL)->head->prev = NULL;                                \
            }                                                           \
        } else if(INDEX == ((LL)->length - 1)){                         \
            if(((LL)->length - 1) == 1){                                \
                free((LL)->head);                                       \
                (LL)->head = NULL;                                      \
                (LL)->tail = NULL;                                      \
            } else {                                                    \
                (LL)->tail = (LL)->tail->prev;                          \
                free((LL)->tail->next);                                 \
                (LL)->tail->next = NULL;                                \
            }                                                           \
        } else {                                                        \
            node_##TYPE* current_node = (LL)->head;                     \
            for(int i = 0; i <= INDEX; i++){                            \
                current_node = current_node->next;                      \
            }                                                           \
            current_node->next->prev = current_node->prev;              \
            current_node->prev->next = current_node->next;              \
            free(current_node);                                         \
        }                                                               \
        (LL)->length--;                                                 \
    }                                                                   \
})

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
