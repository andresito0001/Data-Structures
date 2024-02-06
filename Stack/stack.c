#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(Stack** stack, size_t size) {
	*stack = (Stack*)malloc(sizeof(Stack));
	(*stack)->top = NULL;
	(*stack)->size = size;
}

bool stack_empty(Stack* stack) {
	if (!stack->top) return true;
	return false;
}

void* top(Stack* stack) {
	if (stack_empty(stack)) return NULL;
	return stack->top->data;
}

void _push(Stack* stack, void* data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = stack->top;
	stack->top = newnode;
	stack->size += 1;
}

void* _pop(Stack* stack) {
	if (stack_empty(stack)) return NULL;
	void* data = stack->top->data;
	Node* tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
	stack->size += 1;
	return data;
}

void stack_print(Stack* stack, const char* format, printf_fptr f_print) {
    Node* current = stack->top;
    while (current != NULL) {
    	f_print(format, current->data);
        current = current->next;
    }
}

void destroy_stack(Stack** stack_pp) {
	if(!(*stack_pp)) return;

	Node* current = (*stack_pp)->top;

	while (current != NULL) {
		Node* tmp = current;
		current = current->next;
		free(tmp);
	}

	free((*stack_pp));
	(*stack_pp) = NULL;
	return;
}
