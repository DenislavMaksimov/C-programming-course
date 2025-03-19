#include <stdio.h>

void swap(void *a, void *b)
{
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;

}

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int *ptr = arr; ptr < arr + size - 1 - i; ptr++) {
            if (*ptr > *(ptr + 1)) {
                swap(ptr, ptr + 1);
            }
        }
    }
}

void printArray(int *arr, int size) {
    for (int *ptr = arr; ptr < arr + size; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

int main() {
    int array[] = {64, 93, 13, 8, 11};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Масив преди сортиране:\n");
    printArray(array, size);
    selectionSort(array, size);
    printf("Масив след сортиране:\n");
    printArray(array, size);
    return 0;
}
