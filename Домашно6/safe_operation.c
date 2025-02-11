#include "safeint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_result(SafeResult result) {
    if (result.errorflag) {
        printf("Error: Overflow, underflow, or invalid operation.\n");
    } else {
        printf("Result: %d\n", result.value);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./safe_operations <operation> <num1> <num2>\n");
        printf("Operations: add, subtract, multiply, divide\n");
        return 1;
    }

    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    SafeResult result;

    if (strcmp(argv[1], "add") == 0) {
        result = safeadd(a, b);
    } else if (strcmp(argv[1], "subtract") == 0) {
        result = safesubtract(a, b);
    } else if (strcmp(argv[1], "multiply") == 0) {
        result = safemultiply(a, b);
    } else if (strcmp(argv[1], "divide") == 0) {
        result = safedivide(a, b);
    } else {
        printf("Unknown operation: %s\n", argv[1]);
        return 1;
    }

    print_result(result);
    return 0;
}
