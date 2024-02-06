#include <stdbool.h>
#include <stddef.h>

#define push(stack, data) _push(stack, (void*)data)
typedef int(*printf_fptr)(const char*, ...);

typedef struct _node {
	void* data;
	struct _node* next;
}Node;

typedef struct _stack {
	Node* top;
	size_t size;
}Stack;

void init_stack(Stack** stack, size_t size);
bool stack_empty(Stack* stack);
void _push(Stack* stack, void* data);
void* _pop(Stack* stack);
void stack_print(Stack* s, const char* format, printf_fptr f_print);
void destroy_stack(Stack** stack_pp);
void* top(Stack* stack);
