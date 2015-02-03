#include "rpn.h"

int add(int, int);
int multiply(int, int);
int divide(int, int);
int toDigit(char);
int operation(int, int, char);
int substract(int, int);

int evaluate(String expression) {
	int count = 0, value, *data, value1, value2;
	Stack stack = createStack();

	while(expression[count] != '\0') {
		if(isOpearands(expression[count])){
			data = (void*)malloc(sizeof(int), 1);
			*data = toDigit(expression[count]);
			push(&stack, data);
		}

		if(isOperator(expression[count])){
			value1 = *(int*)pop(&stack);
			value2 = *(int*)pop(&stack);
			data = (void*)malloc(sizeof(int), 1);
			*data = operation(value2, value1, expression[count]);//add(value2, value1);
			push(&stack, data);
		}

		count++;
	}

	return *(int*)pop(&stack);
}

int isOpearands (char character) {
	return (character != 32 && character >= 48) ? 1 : 0;
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
	return oparand2 - oparand1;
}

int multiply (int oparand1, int oparand2){
	return oparand2 * oparand1;
}

int divide (int oparand1, int oparand2){
	return oparand1 / oparand2;
}