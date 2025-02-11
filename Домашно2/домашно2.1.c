#include <stdio.h>
#define PRINT_ARRAY                     \
    for (int i = 0; i < ARRAY_SIZE; i++) {   \
        printf("%d ", arr[i]);               \
    }                                        \
    printf("\n");

#define ARRAY_SIZE 5
#define PRINT printf("%d", arr[i]);
int main(void) {
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    PRINT_ARRAY
    return 0;
}
