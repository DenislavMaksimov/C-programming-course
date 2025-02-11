#include <stdio.h>
#include "maths.h"

int main() {
    int number;
    printf("Въведете число за изчисляване на факториел: ");
    scanf("%d", &number);
    long result = factorial(number);
    if (result == 0) {
        printf("Факторел не е дефиниран за отрицателни числа.\n");
    } else {
        printf("Факторел на %d е %ld\n", number, result);
    }
    return 0;
}
