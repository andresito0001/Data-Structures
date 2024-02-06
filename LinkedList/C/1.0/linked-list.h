#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct _node {
	void* data;
	struct _node* next;
}Node;

typedef struct linked_list  {
	Node* head;
	Node* tail;
	size_t size;

	int (*match)(const void* key1, const void* key2);
	void (*destroy)(void* data);
}List;

void init_list(List* list, void (*destroy)(void* data));
void destroy_list(List* list);
int list_ins_next(List* list, Node* element, const void* data);
int list_rem_next(List* list, Node* element, void** data);

/*
void list_size (List* list);
Node* list_head(List* list);
Node* list_tail(List* list);
int list_is_head(const Node* element);
int list_is_tail(const Node* element);
void* list_data(const Node* element);
Node* list_next(const Node* element);
*/

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list_head(list)) ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif