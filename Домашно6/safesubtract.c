#include <stdio.h>
#include <stdlib.h>
#include "safeint.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    SafeResult res = safesubtract(atoi(argv[1]), atoi(argv[2]));

    if (res.errorflag) {
        printf("Error!!!\n");
    } else {
        printf("Result: %d\n", res.value);
    }

    return 0;
}
