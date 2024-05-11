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
#define DEFINE_NODE(TYPE)\
    typedef struct node_##TYPE{\
        TYPE data;\
        struct node_##TYPE* next;\
        struct node_##TYPE* prev;\
    } node_##TYPE;

/**
 * @brief Generic linked list struct.
 * @param TYPE Data type. (int, float, double, char, ...)
 **/
#define DEFINE_LINKED_LIST(TYPE)\
    typedef struct ll_##TYPE{\
        struct node_##TYPE* head;\
        struct node_##TYPE* tail;\
        unsigned int length;\
    } ll_##TYPE;

/**
 * @brief Print linked list.
 * @param FORMAT String formatter. ("%d", "%f", "%lf", "c", ...)
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @return Void.
 **/
#define PRINT_LL(FORMAT, TYPE, LL) ({\
    node_##TYPE* current_node = (LL)->head;\
    while(current_node != NULL){\
        printf(FORMAT, current_node->data);\
        current_node = current_node->next;\
    }\
    printf("NULL\n");\
})

/**
 * @brief Create node.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Node pointer.
 **/
#define CREATE_NODE(TYPE, DATA) ({\
    node_##TYPE* new_node = (node_##TYPE*)malloc(sizeof(node_##TYPE));\
    new_node->data = DATA;\
    new_node->next = NULL;\
    new_node->prev = NULL;\
    new_node;\
})

/**
 * @brief Append node to a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Void.
 **/
#define APPEND_LL(TYPE, LL, DATA) ({\
    node_##TYPE* new_node = CREATE_NODE(TYPE, DATA);\
    if((LL)->head == NULL){\
        (LL)->head = new_node;\
        (LL)->tail = new_node;\
    } else {\
        (LL)->tail->next = new_node;\
        new_node->prev = (LL)->tail;\
        (LL)->tail = new_node;\
    }\
    (LL)->length++;\
})

/**
 * @brief Prepend node to a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Void.
 **/
#define PREPEND_LL(TYPE, LL, DATA) ({\
    node_##TYPE* new_node = CREATE_NODE(TYPE, DATA);\
    if((LL)->head == NULL){\
        (LL)->head = new_node;\
        (LL)->tail = new_node;\
    } else {\
        new_node->next = (LL)->head;\
        (LL)->head->prev = new_node;\
        (LL)->head = new_node;\
    }\
    (LL)->length++;\
})

/**
 * @brief Insert a node in a specified position in a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param INDEX Index to be inserted in linked list. (0, 1, 2, ...)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Void.
 **/
#define INSERT_LL(TYPE, LL, INDEX, DATA) ({\
    if(INDEX < 0 || INDEX > (LL)->length){\
        puts("OUT OF BOUNDS LINKED LIST INSERTION.\n");\
        exit(FAILURE);\
    } else {\
        node_##TYPE* new_node = CREATE_NODE(TYPE, DATA);\
        if(INDEX == 0){\
            if((LL)->length == 0){\
                (LL)->head = new_node;\
                (LL)->tail = new_node;\
            } else {\
                new_node->next = (LL)->head;\
                (LL)->head->prev = new_node;\
                (LL)->head = new_node;\
            }\
        } else if(INDEX == (LL)->length){\
                if((LL)->length == 0){\
                    (LL)->head = new_node;\
                    (LL)->tail = new_node;\
                } else {\
                    new_node->prev = (LL)->tail;\
                    (LL)->tail->next = new_node;\
                    (LL)->tail = new_node;\
                }\
        } else {\
                node_##TYPE* current_node = (LL)->head;\
                for(int i = 0; i < INDEX; i++){\
                    current_node = current_node->next;\
                }\
                new_node->next = current_node;\
                new_node->prev = current_node->prev;\
                current_node->prev->next = new_node;\
        }\
    }\
    (LL)->length++;\
})

/**
 * @brief Remove the last node of the linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Void.
 **/
#define DELETE_TAIL_LL(LL) ({\
    if((LL)->head == NULL){\
        puts("DELETING TAIL NODE, BUT LINKED LIST IS EMPTY.\n");\
        exit(FAILURE);\
    } else if((LL)->length == 1){\
        free((LL)->head);\
        (LL)->head = NULL;\
        (LL)->tail = NULL;\
    } else {\
        (LL)->tail = (LL)->tail->prev;\
        free((LL)->tail->next);\
        (LL)->tail->next = NULL;\
    }\
    (LL)->length--;\
})

/**
 * @brief Remove the first node of the linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Void.
 **/
#define DELETE_HEAD_LL(LL) ({\
    if((LL)->head == NULL) {\
        puts("DELETING HEAD NODE, BUT LINKED LIST IS EMPTY.\n");\
        exit(FAILURE);\
    } else if((LL)->length == 1) {\
        free((LL)->head);\
        (LL)->head = NULL;\
        (LL)->tail = NULL;\
    } else {\
        (LL)->head = (LL)->head->next;\
        free((LL)->head->prev);\
        (LL)->head->prev = NULL;\
    }\
    (LL)->length--;\
})

/**
 * @brief Delete a node in a specified position in a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param INDEX Index to be deleted in linked list. (0, 1, 2, ...)
 * @return Void.
 **/
#define DELETE_POS_LL(TYPE, LL, INDEX) ({\
    if((LL)->head == NULL){\
        puts("LINKED LIST IS EMPTY.\n");\
        exit(FAILURE);\
    } else if(INDEX < 0 || INDEX > (LL)->length - 1) {\
        puts("OUT OF BOUNDS DELETION LINKED LIST.\n");\
        exit(FAILURE);\
    } else {\
        node_##TYPE* current_node = (LL)->head;\
        for(int i = 0; i < INDEX; i++){\
            current_node = current_node->next;\
        }\
        if(current_node == (LL)->head){\
            if((LL)->length == 1){\
                free((LL)->head);\
                (LL)->head = NULL;\
                (LL)->tail = NULL;\
            } else {\
                (LL)->head = (LL)->head->next;\
                free((LL)->head->prev);\
                (LL)->head->prev = NULL;\
            }\
        } else if(current_node == (LL)->tail){\
            (LL)->tail = (LL)->tail->prev;\
            free((LL)->tail->next);\
            (LL)->tail->next = NULL;\
        } else {\
            current_node->prev->next = current_node->next;\
            current_node->next->prev = current_node->prev;\
            free(current_node);\
        }\
        (LL)->length--;\
    }\
})

/**
 * @brief Delete a node with a specified value in a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param VALUE Value that contains in a node. (0, 1, 2, ...)
 * @return Void.
 **/
#define DELETE_VALUE_LL(TYPE, LL, VALUE) ({\
        if((LL)->head == NULL){\
            puts("LINKED LIST IS EMPTY.\n");\
            exit(FAILURE);\
        } else {\
            if((LL)->head->data == VALUE){\
                if((LL)->length == 1){\
                    free((LL)->head);\
                    (LL)->head = NULL;\
                    (LL)->tail = NULL;\
                } else {\
                    (LL)->head = (LL)->head->next;\
                    free((LL)->head->prev);\
                    (LL)->head->prev = NULL;\
                }\
            } else {\
                node_##TYPE* current_node = (LL)->head->next;\
                while(current_node != NULL){\
                    if(current_node->data == VALUE){\
                        if(current_node == (LL)->tail){\
                            (LL)->tail = (LL)->tail->prev;\
                            free((LL)->tail->next);\
                            (LL)->tail->next = NULL;\
                        } else {\
                            current_node->prev->next = current_node->next;\
                            current_node->next->prev = current_node->prev;\
                            free(current_node);\
                        }\
                        break;\
                    }\
                    current_node = current_node->next;\
                }\
                if(current_node == NULL){\
                    puts("VALUE NOT FOUND IN LINKED LIST.\n");\
                    exit(FAILURE);\
                }\
            }\
            (LL)->length--;\
        }\
})

/**
 * @brief Search for a node in a specified position.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param INDEX Index to be deleted in linked list. (0, 1, 2, ...)
 * @return Node pointer.
 **/
#define SEARCH_POS_LL(TYPE, LL, INDEX) ({\
    node_##TYPE* result = NULL;\
    if((LL)->head == NULL){\
        puts("LINKED LIST IS EMPTY.\n");\
        exit(FAILURE);\
    } else if(INDEX < 0 || INDEX > ((LL)->length - 1)){\
        puts("OUT OF BOUNDS SEARCH LINKED LIST.\n");\
        exit(FAILURE);\
    } else {\
        node_##TYPE* current_node = (LL)->head;\
        for(int i = 0; i < INDEX; i++){\
            current_node = current_node->next;\
        }\
        result = current_node;\
    }\
    result;\
})

/**
 * @brief Delete a node with a specified value in a linked list.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param LL Linked list pointer. (&linked_list)
 * @param VALUE Value that contains in a node. (0, 1, 2, ...)
 * @return Node pointer.
 **/
#define SEARCH_VALUE_LL(TYPE, LL, VALUE) ({\
    node_##TYPE* result = NULL;\
    if((LL)->head == NULL){\
        puts("LINKED LIST IS EMPTY.\n");\
        exit(FAILURE);\
    } else {\
        node_##TYPE* current_node = (LL)->head;\
        while(current_node != NULL){\
            if(current_node->data == VALUE){\
                result = current_node;\
                break;\
            }\
            current_node = current_node->next;\
        }\
        if(current_node == NULL){\
            puts("VALUE NOT FOUND IN THE LINKED LIST.\n");\
            exit(FAILURE);\
        }\
    }\
    result;\
})

/**
 * @brief Concatenate a linked list to another one.
 * @param f_LL Main linked list. (&linked_list)
 * @param s_LL Linked list to be concatenated. (&linked_list2)
 * @return Void.
 **/
#define CONCAT_LL(f_LL, s_LL) ({\
    (f_LL)->tail->next = (s_LL)->head;\
    (f_LL)->tail = (s_LL)->tail;\
    (f_LL)->length += (s_LL)->length;\
})

//TODO: sort()
//TODO: merge()
//TODO: split()

/**
 * @brief Get the length of a linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Size of the linked list.
 **/
#define LENGTH_LL(LL) ({\
    (LL)->length;\
})

/**
 * @brief Pointer to the head of the linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Pointer to the head of the linked list.
 **/
#define HEAD_LL(LL) ({\
    (LL)->head;\
})

/**
 * @brief Pointer to the tail of the linked list.
 * @param LL Linked list pointer. (&linked_list)
 * @return Pointer to the tail of the linked list.
 **/
#define TAIL_LL(LL) ({\
    (LL)->tail;\
})

/**
 * @brief Generic stack struct.
 * @param TYPE Data type. (int, float, double, char, ...)
 **/
#define DEFINE_STACK(TYPE)\
    typedef struct stack_##TYPE{\
        struct node_##TYPE* top;\
        unsigned int size;\
    } stack_##TYPE;\

/**
 * @brief Push a node in a stack.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param STACK Stack pointer. (&stack)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Void.
 **/
#define STACK_PUSH(TYPE, STACK, DATA) ({\
    node_##TYPE* new_node = CREATE_NODE(TYPE, DATA);\
    if((STACK)->top == NULL){\
        (STACK)->top = new_node;\
    } else {\
        (STACK)->top->next = new_node;\
        new_node->prev = (STACK)->top;\
        (STACK)->top = new_node;\
    }\
    (STACK)->size++;\
})

/**
 * @brief Pop off a node in a stack.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param STACK Stack pointer. (&stack)
 * @return Data with the specified type.
 **/
#define STACK_POP(TYPE, STACK) ({\
    TYPE data;\
    if((STACK)->top == NULL){\
        puts("STACK IS EMPTY.\n");\
        exit(FAILURE);\
    } else {\
        data = (STACK)->top->data;\
        if((STACK)->size == 1){\
            free((STACK)->top);\
            (STACK)->top = NULL;\
        } else {\
            (STACK)->top = (STACK)->top->prev;\
            free((STACK)->top->next);\
            (STACK)->top->next = NULL;\
        }\
        (STACK)->size--;\
    }\
    data;\
})

/**
 * @brief Generic queue struct.
 * @param TYPE Data type. (int, float, double, char, ...)
 **/
#define DEFINE_QUEUE(TYPE)\
    typedef struct queue_##TYPE{\
        struct node_##TYPE* head; \
        struct node_##TYPE* tail; \
        unsigned int length;\
    } queue_##TYPE;\

/**
 * @brief Enqueue a node in a queue.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param QUEUE Queue pointer. (&queue)
 * @param DATA User data. (10, "c", "15", ...)
 * @return Void.
 **/
#define QUEUE_ENQUEUE(TYPE, QUEUE, DATA) ({\
    node_##TYPE* new_node = CREATE_NODE(TYPE, DATA);\
    if((QUEUE)->head == NULL){\
        (QUEUE)->head = new_node;\
        (QUEUE)->tail = new_node;\
    } else {\
        (QUEUE)->tail->next = new_node;\
        (QUEUE)->tail = new_node;\
    }\
    (QUEUE)->length++;\
})

/**
 * @brief Dequeue a node in a queue.
 * @param TYPE Data type. (int, float, double, char, ...)
 * @param QUEUE Queue pointer. (&queue)
 * @return Data with the specified type.
 **/
#define QUEUE_DEQUEUE(TYPE, QUEUE) ({\
    TYPE data;\
    if((QUEUE)->head == NULL){\
        puts("QUEUE IS EMPTY.\n");\
        exit(FAILURE);\
    } else {\
        data = (QUEUE)->head->data;\
        if((QUEUE)->length == 1){\
            free((QUEUE)->head);\
            (QUEUE)->head = NULL;\
            (QUEUE)->tail = NULL;\
        } else {\
            (QUEUE)->head = (QUEUE)->head->next;\
            free((QUEUE)->head->prev);\
            (QUEUE)->head->prev = NULL;\
        }\
        (QUEUE)->length--;\
    }\
    data;\
})

#endif //BASELIB_DS_H
