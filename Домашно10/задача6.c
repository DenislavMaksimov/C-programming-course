#include <stdio.h>
#include <string.h>
#include "задача4.c"
#include "задача3.c"

void printarray(int *array, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {5, 2, 9, 1, 5, 6};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    printarray(array, n);

    bubblesort(array, n, sizeof(int), compareasc, swap);
    printf("Sorted in ascending order:\n");
    printarray(array, n);

    bubblesort(array, n, sizeof(int), comparedesc, swap);
    printf("Sorted in descending order:\n");
    printarray(array, n);

    return 0;
}
