#include "linkedList.h"

#ifndef queueLib_h_
#define queueLib_h_

typedef struct queue Queue;
typedef Queue* Queue_ptr;

struct queue {
	LinkedList *list;
	Node_ptr* front;
	Node_ptr* rear;
};

Queue createQueue(void);
int enqueue(Queue_ptr, void*);
void* dequeue(Queue_ptr);

#endif