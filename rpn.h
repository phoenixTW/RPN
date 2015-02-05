#include "stackLib.h"

typedef char* String;
typedef struct result Result;
typedef struct token Token;

struct token {
	int type;
	int start;
	int end;
};

struct result {
	int error;
	int result;
};

Result evaluate(String);
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
