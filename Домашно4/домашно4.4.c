#include <stdio.h>
#include <math.h>
#define SIZE 5  

void topower4(long arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (long)pow(arr[i], 4);
    }
}

int main() {
    long array[SIZE] = {1, 2, 3, 4, 5};
    printf("Масив преди повдигане на четвърта степен:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%ld ", array[i]);
    }
    printf("\n");
    topower4(array, SIZE);
    printf("Масив след повдигане на четвърта степен:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%ld ", array[i]);
    }
    printf("\n");
    return 0;
}

