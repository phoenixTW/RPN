#include "linkedList.h"
typedef struct stack Stack;
typedef Stack* Stack_ptr;

struct stack {
	LinkedList* list;
	Node_ptr* top;
};

Stack createStack(void);
int push(Stack*, void*);
void* pop(Stack*);
