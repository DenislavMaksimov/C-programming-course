#include <stdio.h>

union Number {
    long odd;
    short even;
};

int main() {
    union Number arr[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            arr[i].even = i;  
        } else {
            arr[i].odd = i;  
        }
    }
    printf("Нечетни индекси (odd):\n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            printf("Индекс %d: %ld\n", i, arr[i].odd);
        }
    }
    printf("\nЧетни индекси (even):\n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            printf("Индекс %d: %hd\n", i, arr[i].even);
        }
    }
    return 0;
}
