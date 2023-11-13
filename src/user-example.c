#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
	Stack* stack;
	init_stack(&stack, 5);

	int* arr = (int*)malloc(5 * sizeof(int));
	
	for (int i = 0; i < 5; ++i) {
		printf("Ingrese un numero: ");
		scanf("%d", (arr + i));
		push(stack, (int*)(arr + i));
	}

	stack_print(stack, "%d\n", printf);

	return 0;
}
