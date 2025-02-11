#include <stdio.h>
#define SWAP(A, B, TYPE) \
    do { \
        TYPE t = A; \
        A = B; \
        B = t; \
    } while (0)

void main() {
    int x = 3, y = 20;
    printf("Before SWAP: x = %d, y = %d\n", x, y);
    SWAP(x, y, int);
    printf("After SWAP: x = %d, y = %d\n", x, y);
    float a = 1.2, b = 4.6;
    printf("Before SWAP: a = %.2f, b = %.2f\n", a, b);
    SWAP(a, b, float);
    printf("After SWAP: a = %.2f, b = %.2f\n", a, b);
}
