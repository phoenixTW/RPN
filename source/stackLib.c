#include "stackLib.h"
#include <stdio.h>
#include <stdlib.h>

Stack createStack(void) {
	LinkedList* list = calloc(sizeof(LinkedList), 1);
	return (Stack){list, &list->tail};
}

int push(Stack *stack, void* data) {
	int isAdded = add_to_list(stack->list, create_node(data));
	return (isAdded < 1) ? -1 : stack->list->count;
}

void* pop(Stack *stack) {
	if(stack->list->count == 0) return (void*)(-1);
	return deleteElementAt(stack->list, stack->list->count - 1);
}