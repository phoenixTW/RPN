#include "rpn.h"
#include "expr_assert.h"
#include <string.h>

void test_evaluate_should_return_2_for_1_plus_1 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "1 1 + ");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	free(expression);
}

void test_evaluate_should_return_3_for_2_plus_1 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 + ");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	free(expression);
}

void test_evaluate_should_return_23_for_12_plus_11 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "12 11 + ");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 23);
	free(expression);
}

void test_evaluate_should_return_5_for_2_plus_1_plus_2 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 2 + +");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 5);
	free(expression);
}

void test_evaluate_should_return_3_for_2_minus_1 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "4 1 -");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 3);
	free(expression);
}

void test_evaluate_should_return_2014_for_2_minus_1 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2013 2 1 - +");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 2014);
	free(expression);
}

void test_evaluate_should_return_2_for_2_multiply_by_1 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 1 * ");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 2);
	free(expression);
}

void test_evaluate_should_return_9_for_2_minus_1_plus_2_mul_3 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "3 2 2 1 - + *");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 9);
	free(expression);
}

void test_evaluate_should_return_2_for_4_divided_by_2 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "4 2 / ");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 2);
	free(expression);
}

void test_evaluate_should_return_1_for_2_minus_1_plus_2_div_3 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "3 2 2 1 - + /");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 1);
	free(expression);
}

void test_evaluate_should_return_1_for_2_minus_1_plus_2_div_3_with_lots_of_spaces () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "3 2 2  1 - + /");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 1);
	free(expression);
}

void test_evaluate_should_return_14_for_5_1_2_plus_4_mul_plus_3 () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "5 1 2 + 4 * + 3 -");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 14);
	free(expression);
}

void test_evaluate_should_return_7_for_2_2_2_mul_2_sub_3_plus_plus () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 2 2 * 2 - 3 + +");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 7);
	free(expression);
}

void test_evaluate_should_return_20_for_2_2_2_2_2_mul_mul_2_plus_plus_2_sub_mul () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 2 2 2 2 * * 2 + + 2 - *");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 20);
	free(expression);
}

void test_evaluate_should_return_0_for_2_2_sub_2_2_2_mul_2_sub_sub_sub () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 2 - 2 2 2 * 2 - - -");
	res = evaluate(expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 0);
	free(expression);
}

void test_evaluate_should_return_negative_1_for_too_many_opearators () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 2 - + *");
	res = evaluate(expression);
	assertEqual(res.error, 0);
	assertEqual(res.result, 0x0);
	free(expression);
}

void test_evaluate_should_return_negative_1_for_too_many_opearands () {
	Result res;
	String expression = calloc(sizeof(char), 256);
	strcpy(expression, "2 2 3 4 - + ");
	res = evaluate(expression);
	assertEqual(res.error, 0);
	assertEqual(res.result, 0x0);
	free(expression);
}

void test_isOperands_should_return_1_for_2 () {
	assertEqual(isOperand('2'), 1);
}

void test_isOperands_should_return_0_for_a () {
	assertEqual(isOperand('a'), 0);
}

void test_isOperator_should_return_1_for_plus () {
	assertEqual(isOperator('+'), 1);
}

void test_isOperator_should_return_1_for_minus () {
	assertEqual(isOperator('-'), 1);
}

void test_isOperator_should_return_1_for_multiply () {
	assertEqual(isOperator('*'), 1);
}

void test_isOperator_should_return_1_for_division () {
	assertEqual(isOperator('/'), 1);
}

void test_isOperator_should_return_0_for_greaterThan () {
	assertEqual(isOperator('>'), 0);
}

void test_isOperator_should_return_0_for_comma () {
	assertEqual(isOperator(','), 0);
}

void test_perform_should_return_2_for_1_1_plus () {
	Result res;
	Stack stack = createStack();
	String expression = "1 1 + ";
	res = perform(stack, expression);
	assertEqual(res.error, 1);
	assertEqual(res.result, 2);
}

void test_perform_should_return_error_for_1_1_plus_plus () {
	Result res;
	Stack stack = createStack();
	String expression = "1 1 + +";
	res = perform(stack, expression);
	assertEqual(res.error, 0);
	assertEqual(res.result, 0x0);
}

void test_should_create_a_list_of_tokens () {
	LinkedList list = createList();
	String expr = "1 1 +";
	generateToken(&list, expr);
	assertEqual(((Token*)list.head->data)->type, 1);
	assertEqual(((Token*)list.head->next->data)->type, 0);
	assertEqual(((Token*)list.head->next->next->next->next->data)->type, 2);
}