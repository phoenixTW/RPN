#include "rpn.h"
#include "expr_assert.h"
#include <string.h>

void test_evaluate_should_return_2_for_1_plus_1 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "1 1 + ");
	assertEqual(evaluate(expression), 2);
	free(expression);
}

void test_evaluate_should_return_3_for_2_plus_1 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 + ");
	assertEqual(evaluate(expression), 3);
	free(expression);
}

void test_evaluate_should_return_5_for_2_plus_1_plus_2 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 2 + + ");
	assertEqual(evaluate(expression), 5);
	free(expression);
}

void test_evaluate_should_return_1_for_2_minus_1 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "1 2 -");
	assertEqual(evaluate(expression), 1);
	free(expression);
}
