typedef struct linkedList LinkedList;
typedef struct node Node;
typedef struct students Students;
typedef Students* Student_ptr;
typedef Node* Node_ptr;
typedef int (predicate)(void *data);

struct students {
	int roll;
	int marks;
};

struct node {
	// Student_ptr student;
	void* data;
 	Node_ptr next;
};

struct linkedList {
	Node_ptr head;
	Node_ptr tail;
	int count;
};

LinkedList createList(void);
Node_ptr create_node(void*);
int add_to_list(LinkedList*, Node_ptr);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void traverse(LinkedList, void (*)(void*));
void *getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void * deleteElementAt(LinkedList*, int);
int asArray(LinkedList, void **);
LinkedList * filter(LinkedList, int (*)(void *));
