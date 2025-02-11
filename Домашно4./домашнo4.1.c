#include <stdio.h>
#define SQUARE_SUM(A, B) ((A) + (B)) * ((A) + (B))

int main() {
    int x = 3;
    int y = 4;
    int result = SQUARE_SUM(x, y);
    printf("Резултатът от (x + y)^2 е: %d\n", result);
    return 0;
}
