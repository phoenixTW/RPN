#include "stackLib.h"

typedef char* String;
typedef struct result Result;

struct result {
	int error;
	int result;
};

Result evaluate(String);