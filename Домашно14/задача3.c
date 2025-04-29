#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 16 

typedef struct {
    char name[NAME_LEN];
    int classNumber;
    double averageGrade;
} Student;

int main() {
    Student* students = NULL; 
    int studentCount = 0;     
    int choice;
    while (1) {
        printf("\nМеню\n");
        printf("1. Добавяне на ученик\n");
        printf("2. Извеждане на всички ученици\n");
        printf("3. Изход\n");
        printf("Изберете опция: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                students = realloc(students, (studentCount + 1) * sizeof(Student));
                if (students == NULL) {
                    printf("Грешка при заделяне на памет.\n");
                    return 1;
                }
                Student* newStudent = &students[studentCount];
                printf("Въведете име на ученика (до 15 символа): ");
                scanf("%15s", newStudent->name); 
                printf("Въведете номер в класа: ");
                scanf("%d", &newStudent->classNumber);
                printf("Въведете среден успех: ");
                scanf("%lf", &newStudent->averageGrade);
                studentCount++;
                printf("Ученикът е добавен успешно.\n");
                break;
            }
            case 2: {
                if (studentCount == 0) {
                    printf("Няма добавени ученици.\n");
                } else {
                    printf("\n=== Списък с ученици ===\n");
                    for (int i = 0; i < studentCount; ++i) {
                        printf("Име: %s | Номер в клас: %d | Среден успех: %.2f\n",
                               students[i].name,
                               students[i].classNumber,
                               students[i].averageGrade);
                    }
                }
                break;
            }
            case 3: {
                free(students); 
                printf("Изход от програмата.\n");
                return 0;
            }
            default:
                printf("Невалидна опция. Опитайте отново.\n");
        }
    }
    return 0;
}
