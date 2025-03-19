#include <stdio.h>
#define COLUMNS 4  

void printTable(int arr[][COLUMNS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%5d ", arr[i][j]);  
        }
        printf("\n");
    }
}

int main() {
    int array[][COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int rows = sizeof(array) / sizeof(array[0]); 
    printf("Таблица:\n");
    printTable(array, rows);
    return 0;
}
