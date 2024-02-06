#include "llinked-list.h"
#include <stdlib.h>
#include <stdio.h>

List* init_list() {
    List* list = (List*)malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void list_insert(List* list, Node* node, const void* data) {
    if (!list) return;

    Node* new_node = (Node*)malloc(sizeof(Node));

    if (!new_node) return;

    new_node = (void*)data;

    if (!node) {
        list->tail = (!list_size(list)) ? new_node : list->tail;

        new_node->next = list->head;
        list->head = new_node;
    } else { 
        list->tail = (!node->next) ? new_node : list->tail;

        new_node->next = node->next;
        node->next = new_node;
    }

    list->size += 1;
    return;
}