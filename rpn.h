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