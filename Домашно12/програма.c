#include <stdio.h>
#include <stdlib.h>
#define CHECK_ALLOC(ptr) if (!(ptr)) { printf("Memory allocation failed!\n"); exit(1); }

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Calculate average grade\n");
    printf("2. Add a new grade\n");
    printf("3. Delete the last grade\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

float calculateAverage(int *grades, int count) {
    if (count == 0) return 0;
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return (float)sum / count;
}

int main() {
    int *grades = NULL;
    int count = 0;
    do {
        printf("Enter number of grades: ");
        scanf("%d", &count);
        if (count < 0) printf("The number of grades cannot be negative!\n");
    } while (count < 0);
    if (count > 0) {
        grades = (int *)malloc(count * sizeof(int));
        CHECK_ALLOC(grades);
        printf("Enter the grades: \n");
        for (int i = 0; i < count; i++) {
            scanf("%d", &grades[i]);
        }
    }

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count == 0) printf("No grades. Sorry it is not have average grade.\n");
                else printf("Average grade is: %.2f\n", calculateAverage(grades, count));
                break;

            case 2: {
                int newGrade;
                printf("Enter the new grade: ");
                scanf("%d", &newGrade);
                count++;
                grades = (int *)realloc(grades, count * sizeof(int));
                CHECK_ALLOC(grades);
                grades[count - 1] = newGrade;
                printf("Grade was added!\n");
                break;
            }

            case 3:
                if (count == 0) printf("No grades to remove!\n");
                else {
                    count--;
                    grades = (int *)realloc(grades, count * sizeof(int));
                    CHECK_ALLOC(grades);
                    printf("Last grade was removed!\n");
                }
                break;

            case 4:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid option! Try again.\n");
        }

    } while (choice != 4);
    free(grades);
    return 0;
}
