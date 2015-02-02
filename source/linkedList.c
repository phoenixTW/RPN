#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList createList (void) {
	LinkedList list = {NULL, NULL, 0};
	return list;
}

Node_ptr create_node(void *data) {
	Node_ptr node;
	node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}

int add_to_list(LinkedList *list, Node_ptr node) {
	if(list->head == NULL){
		list->head = node;
		list->tail = node;
		list->count++;
		return 1;
	}

	list->tail->next = node;
	list->tail = node;
	list->count++;


	return 1;
}

void *get_first_element(LinkedList list) {
	return list.head->data;
}

void *get_last_element(LinkedList list) {
	return list.tail->data;
}

void traverse(LinkedList list, void (*callback)(void *data)) {
	void* walker = list.head;

	while(walker != NULL) {
		callback(list.head->data);
		walker = list.head->next;
	}
}

void *getElementAt(LinkedList list, int index) {
	int count = -1;
	Node_ptr walker = list.head;

	if(list.count < index + 1)
		return NULL;
	
	while(count < index) {
		count++;

		if(count == index) {
			return walker->data;
		}

		walker = walker->next;
	}
}

int indexOf(LinkedList list, void *data) {
	int count = -1;
	Node_ptr walker = list.head;

	while(walker != NULL) {
		count++;

		if(walker->data == data)
			return count;

		walker = walker->next;
	}

	return -1;
}

void* deleteElementAt(LinkedList *list, int index) {
	int count = -1;
	Node_ptr walker = list->head;
	Node_ptr prev = NULL;

	if(index + 1 > list->count)
		return NULL;

	while(walker != NULL) {
		count++;

		if(index == 0){
			list->head = walker->next;
		
			if((list->count == 1) && (index == 0)) {
				list->tail = NULL;
			}
		
			list->count--;
			return walker->data;
		}

		if((index == (list->count - 1)) && (index == count)){
			list->tail = prev;
			list->count--; 	
			return walker->data;
		}
		
		if(count == index) {
			prev->next = walker->next;
			list->count--;
			return walker->data;
		}
		
		prev = walker;
		walker = walker->next;
	}
}

int asArray(LinkedList list, void **array) {
	int counter = 0;

	while(counter < list.count) {
		array[counter] = getElementAt(list, counter);
		counter++;
	}

	return counter;
}

LinkedList* filter(LinkedList list, int (*callback)(void *data)) {
	LinkedList *newList = (LinkedList*)calloc(sizeof(LinkedList), 1);
	Node_ptr walker = list.head;

	while(walker != NULL) {
		if(callback(walker->data))
			add_to_list(newList, walker);

		walker = walker->next;
	}

	return newList;
}