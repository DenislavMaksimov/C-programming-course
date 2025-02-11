#include <stdio.h>
#include "processes.h"
#include <stdlib.h>

void displaymenu() {
    printf("\nTask Manager Options:\n");
    printf("1. Създаване на процес\n");
    printf("2. Извеждане на списък със всички процеси\n");
    printf("3. Спиране на процес\n");
    printf("4. Изход на програмата\n");
}

int main() {
    int choice;
    char process_name[MAX_PROCESSES_NAME_LENGTH + 1];
    int process_id;

    while (1) {
        displaymenu();
        printf("Избери: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Напиши името на процеса: ");
                scanf("%s", process_name);
                int new_id = createnewprocess(process_name);
                if (new_id > 0) {
                    printf("Процесът е създаден с ID: %d\n", new_id);
                }
                break;

            case 2:
                listprocesses();
                break;

            case 3:
                printf("Напиши id-то на процеса за да спре: ");
                scanf("%d", &process_id);
                stopprocess(process_id);
                break;

            case 4:
                printf("Излизане от програмата.\n");
                exit(0);

            default:
                printf("Невалидно число. Опитай с чилата от 1 до 4\n");
        }
    }

    return 0;
}
