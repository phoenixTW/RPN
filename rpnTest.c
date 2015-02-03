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

// void test_evaluate_should_return_23_for_12_plus_11 () {
// 	String expression = calloc(sizeof(char), 256);
// 	strcpy(expression, "12 11 + ");
// 	assertEqual((int*)evaluate(expression), 23);
// 	free(expression);
// }

void test_evaluate_should_return_5_for_2_plus_1_plus_2 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 2 + +");
	assertEqual((int*)evaluate(expression), 5);
	free(expression);
}

void test_evaluate_should_return_3_for_2_minus_1 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "4 1 -");
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
	strcpy(expression, "3 2 2 1 - + *");
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
	strcpy(expression, "3 2 2 1 - + /");
	assertEqual((int*)evaluate(expression), 1);
	free(expression);
}

void test_evaluate_should_return_1_for_2_minus_1_plus_2_div_3_with_lots_of_spaces () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "3 2 2  1 - + /");
	assertEqual((int*)evaluate(expression), 1);
	free(expression);
}

void test_evaluate_should_return_14_for_5_1_2_plus_4_mul_plus_3 () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "5 1 2 + 4 * + 3 -");
	assertEqual((int*)evaluate(expression), 14);
	free(expression);
}

void test_evaluate_should_return_7_for_2_2_2_mul_2_sub_3_plus_plus () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 2 2 * 2 - 3 + +");
	assertEqual((int*)evaluate(expression), 7);
	free(expression);
}

void test_evaluate_should_return_7_for_2_2_2_2_2_mul_mul_2_plus_plus_2_sub_mul () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 2 2 2 2 * * 2 + + 2 - *");
	assertEqual((int*)evaluate(expression), 20);
	free(expression);
}

void test_evaluate_should_return_0_for_2_2_sub_2_2_2_mul_2_sub_sub_sub () {
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 2 - 2 2 2 * 2 - - -");
	assertEqual((int*)evaluate(expression), 0);
	free(expression);
}
