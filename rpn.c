#include "rpn.h"

int add(int, int);
int toDigit(char);

int evaluate(String expression) {
	int count = 0, value, *data, value1, value2;
	Stack stack = createStack();

	while(expression[count] != '\0') {
		if(expression[count] != 32 && expression[count] >= 48){
			data = (void*)malloc(sizeof(int), 1);
			*data = toDigit(expression[count]);
			push(&stack, data);
		}

		if(expression[count] == 43){
			value1 = *(int*)pop(&stack);
			value2 = *(int*)pop(&stack);
			data = (void*)malloc(sizeof(int), 1);
			*data = add(value1, value2);
			push(&stack, data);
		}

		count++;
	}

	return *(int*)pop(&stack);
}

int toDigit(char character) {
	return character - '0';
}

int add (int operand1, int operand2) {
	int sum = operand1 + operand2;
	return sum;
}
