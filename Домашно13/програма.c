#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 15
#define CHECK_ALLOC(ptr) if (!(ptr)) { printf("Memory allocation failed!\n"); exit(1); }

void readString(char *str, int maxLen) {
    fgets(str, maxLen, stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Add a new student\n");
    printf("2. Print the class diary\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int subjectCount = 0, studentCount = 0;
    char **subjects = NULL;
    char **students = NULL;
    int **grades = NULL;

    do {
        printf("Enter the number of subjects: ");
        scanf("%d", &subjectCount);
        while (getchar() != '\n'); 
        if (subjectCount <= 0) printf("The number of subjects must be positive!\n");
    } while (subjectCount <= 0);

    subjects = (char **)malloc(subjectCount * sizeof(char *));
    CHECK_ALLOC(subjects);
    printf("Enter the subjects' names (max %d characters each):\n", MAX_NAME_LEN);
    for (int i = 0; i < subjectCount; i++) {
        subjects[i] = (char *)malloc((MAX_NAME_LEN + 1) * sizeof(char));
        CHECK_ALLOC(subjects[i]);
        printf("Subject %d: ", i + 1);
        readString(subjects[i], MAX_NAME_LEN + 1);
    }

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        while (getchar() != '\n'); 

        switch (choice) {
            case 1: { 
                students = (char **)realloc(students, (studentCount + 1) * sizeof(char *));
                CHECK_ALLOC(students);
                students[studentCount] = (char *)malloc((MAX_NAME_LEN + 1) * sizeof(char));
                CHECK_ALLOC(students[studentCount]);
                printf("Enter student name (max %d characters): ", MAX_NAME_LEN);
                readString(students[studentCount], MAX_NAME_LEN + 1);
                grades = (int **)realloc(grades, (studentCount + 1) * sizeof(int *));
                CHECK_ALLOC(grades);
                grades[studentCount] = (int *)malloc(subjectCount * sizeof(int));
                CHECK_ALLOC(grades[studentCount]);
                for (int i = 0; i < subjectCount; i++) {
                    printf("Enter grade for %s: ", subjects[i]);
                    scanf("%d", &grades[studentCount][i]);
                    while (getchar() != '\n');
                }
                studentCount++;
                break;
            }

            case 2: { 
                if (studentCount == 0) {
                    printf("There is no students yet.\n");
                    break;
                }
                printf("%-15s", " ");
                for (int i = 0; i < subjectCount; i++) {
                    printf("%-15s", subjects[i]);
                }
                printf("\n");
                for (int i = 0; i < studentCount; i++) {
                    printf("%-15s", students[i]);
                    for (int j = 0; j < subjectCount; j++) {
                        printf("%-15d", grades[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 3:
                printf("Exiting the program!\n");
                break;

            default:
                printf("Invalid option! Try again.\n");
        }

    } while (choice != 3);

    
    for (int i = 0; i < subjectCount; i++) free(subjects[i]);
    free(subjects);
    for (int i = 0; i < studentCount; i++) {
        free(students[i]);
        free(grades[i]);
    }
    free(students);
    free(grades);
    return 0;
}
