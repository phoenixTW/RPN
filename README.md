# RPN
Reverse Polish Notation in C.

##Version 1.0

Write a RPN calculator that can evaluate simple expressions such as:

2 3 +
2 3 -
2 3 *
2 3 /
2 3 4 + - 
1 2 3 4 5 * * * * 

For the first version, assume:

	1. Every operand is provided as an integer
	2. The input is perfectly formatted(only digits, spaces and operators are allowed)
	3. Evaluate only for operators +, - , * and /
	4. Expressions provided are valid and complete(no dangling operators or operands)
	5. No negative numbers are used

The only API you have to provide is as follows:

int evaluate(char *expression);

##Version 2.0

Complex expressions

Expressions that are surrounded by parentheses in infix 
	notation are represented slightly differently in postfix. 

	For example:

		5 + ((1 + 2) * 4) − 3  in infix notation is written as
		5 1 2 + 4 * + 3 − in postfix notation

The above expression evaluates to 14.

Your evaluate function should now handle complex expressions such as the one above. 
Here are a few more:

	2 2 2 * 2 - 3 + +  == 7  
	2 2 2 2 2 * * 2 + + 2 - * == 20
	2 2 - 2 2 2 * 2 - - - ==  0

##Version 3.0

Result evaluate(char * expression);

Given expressions which either have too many operands or 
too many operators, the evaluate should fail and the error 
field of the Result should indicate this by returning an appropriate value upon failure.

For this version limit yourself only to complain about failures 
caused on too many operators or too many operands. Do not worry 
about divide by zero errors or any syntactic issues.

