#include "rpn.h"
#include "expr_assert.h"
#include <string.h>

void test_evaluate_should_return_2_for_1_plus_1 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "1 1 + ");
	assertEqual((int*)evaluate(expression), 2);
	free(expression);
}

void test_evaluate_should_return_3_for_2_plus_1 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 + ");
	assertEqual((int*)evaluate(expression), 3);
	free(expression);
}

void test_evaluate_should_return_5_for_2_plus_1_plus_2 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 2 + + ");
	assertEqual((int*)evaluate(expression), 5);
	free(expression);
}

void test_evaluate_should_return_3_for_2_minus_1_plus_2 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 2 - +");
	assertEqual((int*)evaluate(expression), 3);
	free(expression);
}

// void test_evaluate_should_return_2014_for_2_minus_1 () {
// 	String expression = calloc(sizeof(char), 256);
// 	strcpy(expression, "2013 1 2 - +");
// 	assertEqual(evaluate(expression), 2014);
// 	free(expression);
// }

void test_evaluate_should_return_2_for_2_multiply_by_1 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 * ");
	assertEqual((int*)evaluate(expression), 2);
	free(expression);
}

void test_evaluate_should_return_9_for_2_minus_1_plus_2_mul_3 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "3 2 1 2 - + *");
	assertEqual((int*)evaluate(expression), 9);
	free(expression);
}

void test_evaluate_should_return_2_for_4_divided_by_2 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "4 2 / ");
	assertEqual((int*)evaluate(expression), 2);
	free(expression);
}

void test_evaluate_should_return_1_for_2_minus_1_plus_2_div_3 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "3 2 1 2 - + /");
	assertEqual((int*)evaluate(expression), 1);
	free(expression);
}

void test_evaluate_should_return_1_for_2_minus_1_plus_2_div_3_with_lots_of_spaces () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "3 2 1   2 - + /");
	assertEqual((int*)evaluate(expression), 1);
	free(expression);
}
