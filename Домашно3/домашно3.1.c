#include <stdio.h>
#define DEBUG  
void sort_and_sum(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

#ifdef DEBUG
    printf("Сортиран масив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
#endif

    int sum = 0;
    printf("Елементи на индекси кратни на 3: ");
    for (int i = 0; i < size; i++) {
        if (i % 3 == 0) {
            sum += arr[i];
#ifdef DEBUG
            printf("%d ", arr[i]);
#endif
        }
    }
    printf("\nСума на елементите на индекси кратни на 3: %d\n", sum);
}

int main() {
    int arr[] = {9, 3, 7, 1, 6, 2, 8, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort_and_sum(arr, size);
    return 0;
}   
