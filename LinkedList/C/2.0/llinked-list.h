#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define node_next(node) ((node)->next)
#define node_data(node) ((node)->data)

/*
#define PRINT_LIST(T, begin, end, fn, str_format) \
        for(T __val__ = begin; __val__ != end; __val__ = __val__->next) { \
            fn(str_format, node_data(__val__)); \
        }
*/

#define __print_list__(first, last, u_fn, format) \
    for (; first != last; first = first->next) { \
        u_fn(format, first->data); \
    }

#define widget(Type, val, data) \
    data = (Type*)malloc(sizeof(Type)); \
    *data = val; \


typedef struct _node {
    void* data;
    struct _node* next;
} Node;

typedef struct _list {
    Node* head;
    Node* tail;

    size_t size;
} List;

List* init_list();
void list_insert(List* list, Node* node, const void* data);
void list_remove(List* list, Node* node);
void list_destroy(List** list);

#define __list_insert__(list, node, data)


#endif