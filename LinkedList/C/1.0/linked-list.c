#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_list(List* list, void (*destroy)(void* data)) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->destroy = destroy;
	return;
}

int list_ins_next(List* list, Node* node, const void* data) {
	Node* new_elem = (Node*)malloc(sizeof(Node));

	if (new_elem  == NULL) {
		return -1;
	}

	new_elem = (void*)data;

	if (node == NULL) {
		if (list_size(list) == 0)
			list->tail = new_elem;

		new_elem->next = list->head;
		list->head = new_elem;

	} else {
		if (node->next == NULL)
			list->tail = new_elem;

		new_elem->next = node->next;
		node->next = new_elem;
	}

	list->size += 1;

	return 0;
}

int list_rem_next(List* list, Node* node, void** data) {
	Node* old_elem;

	if (list_size(list) == 0) return -1;

	if (node == NULL) {
		old_elem = list->head;
		list->head = list->head->next;

		if (list_size(list) == 1)
			list->tail = NULL;
	} else {
		if (node->next == NULL) return -1;
		
		old_elem = node->next;
		node->next = node->next->next;

		if (node->next == NULL) 
			list->tail = node;
	}

	free(old_elem);
	old_elem = NULL;
 
	list->size -= 1;

	return 0;
}

void destroy_list(List* list) {
	void* data;
	while (list_size(list) > 0) {
		list_rem_next(list, NULL, (void**)&data);
	}
	
	// memset(list, 0, list_size(list));
	return;
}