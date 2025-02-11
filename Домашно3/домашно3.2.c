#include <stdio.h>
#define ARRAY_SIZE 5
int main() {
#if defined(ARRAY_SIZE) && ARRAY_SIZE > 0 && ARRAY_SIZE <= 10
    int array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = 2^i ;  
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", array[i]);
    }
#else
    printf("Размерът на масива не е поддържан от приложението.\n");
#endif

    return 0;
}
