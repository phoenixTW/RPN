#include "rpn.h"
#include <stdlib.h>

int add(int, int);
int multiply(int, int);
int divide(int, int);
int toDigit(char);
int operation(int, int, char);
int substract(int, int);
int isOpearands(char);
int isOperator(char);
int isWhiteSpace (char);
Result perform(Stack, String);
void generateToken(LinkedList*, String);
Token* create_token(int, int, int);
Result calculate(LinkedList*, String, Stack);

Result evaluate(String expression) {
	// int count = 0, value, *data, value1, value2;
	// Stack stack = createStack();

	// while(expression[count] != '\0') {
	// 	if(isOpearands(expression[count])){
	// 		data = (void*)malloc(sizeof(int) * 1);
	// 		*data = toDigit(expression[count]);
	// 		push(&stack, data);
	// 	}

	// 	if(isOperator(expression[count])){
	// 		value1 = pop(&stack);
	// 		value2 = pop(&stack);

	// 		if((value1 == -1) || (value2 == -1)) return (Result){0, NULL};
			
	// 		data = (void*)malloc(sizeof(int) * 1);
	// 		*data = operation(*(int*)value2, *(int*)value1, expression[count]);//add(value2, value1);
	// 		push(&stack, data);
	// 	}

	// 	count++;
	// }

	// if(stack.list->count > 1) return (Result){0, NULL};

	// return (Result){1, *(int*)pop(&stack)};
	Stack stack = createStack();
	Result res = perform(stack, expression);
	return res;
}

/* 
	whiteSpace = 0;
	Operands = 1;
	Operator = 2;
*/

Result perform(Stack stack, String expression) {
	int count, *data;
	LinkedList list = createList();
	generateToken(&list, expression);

	// printf("%d\n", ((Token*)(list.head->data))->type);
	return calculate(&list, expression, stack);
	// return (Result){1, 0};
}
	// 		value1 = pop(&stack);
	// 		value2 = pop(&stack);

	// 		if((value1 == -1) || (value2 == -1)) return (Result){0, NULL};
			
	// 		data = (void*)malloc(sizeof(int) * 1);
	// 		*data = operation(*(int*)value2, *(int*)value1, expression[count]);//add(value2, value1);
	// 		push(&stack, data);

Result calculate (LinkedList *list, String expression, Stack stack) {
	Node_ptr walker = list->head;
	int *value, data1, data2;
	char op;
	while(walker != NULL) {
		if(((Token*)walker->data)->type == 1){
			value = (void*)malloc(sizeof(int));
			*value = getValue(expression, ((Token*)walker->data)->start, ((Token*)walker->data)->end);
			push(&stack, value);
		}

		if(((Token*)walker->data)->type == 2) {
			data1 = pop(&stack);
			data2 = pop(&stack);
			
			if((data1 == -1) || (data2 == -1)) return (Result){0, NULL};
			
			op = getValue(expression, ((Token*)walker->data)->start, ((Token*)walker->data)->end);
			value = malloc(sizeof(int));
			*value = operation(*(int*)data2, *(int*)data1, op);

			push(&stack, value);
		}

		walker = walker->next;
	}

	if(stack.list->count > 1) return (Result){0, NULL};

	return (Result){1, *(int*)pop(&stack)};
}

int getValue(String expression, int start, int end) {
	int count, result = 0;

	if(isOperator(expression[start])) return expression[start];
	for(count = start; count <= end; count++) {
		result = result * 10 + (expression[count] - '0');
	}

	return result;
}

void generateToken (LinkedList *list, String expression) {
	int count = 0, type, start = -1, end = -1;
	while(expression[count] != '\0') {
		if(isOpearands(expression[count])) type = 1;
		if(isOperator(expression[count])) type = 2;
		if(isWhiteSpace(expression[count])) type = 0;

		if(start == -1) start = count;
		if(isWhiteSpace(expression[count + 1]) || expression[count + 1] == '\0') end = count;
		if(expression[count + 1] == ' ' || expression[count] == ' ') end = count; 

		if(start != -1 && end != -1) {
			add_to_list(list, create_node(create_token(type, start, end)));
			start = -1;
			end = -1;
		}

		count++;
	}
}

Token* create_token(int type, int start, int end) {
	Token* token;
	token = malloc(sizeof(token));
	token->type = type;
	token->start = start;
	token->end = end;
	return token;
}

int isWhiteSpace(char character) {
	return character == ' ';
}

int isOpearands (char character) {
	return (character != 32 && character >= '0' && character <= '9') ? 1 : 0;
}

int isOperator (char character) {
	return ((character >= '*') && (character <= '/') && (character != ',')) ? 1 : 0;
}

int toDigit(char character) {
	return character - '0';
}

int operation(int value1, int value2, char operator){
	int result = 0;
	operator == '+' && (result = add(value1, value2));
	operator == '-' && (result = substract(value1, value2));
	operator == '*' && (result = multiply(value1, value2));
	operator == '/' && (result = divide(value1, value2));
	return result;
}

int add (int operand1, int operand2) {
	int sum = operand1 + operand2;
	return sum;
}

int substract (int oparand1, int oparand2){
	return oparand1 - oparand2;
}

int multiply (int oparand1, int oparand2){
	return oparand2 * oparand1;
}

int divide (int oparand1, int oparand2){
	return oparand1 / oparand2;
}