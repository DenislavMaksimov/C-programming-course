#include <stdio.h>

typedef enum {
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
    SUNDAY = 7
} dayofweek;

int main() {
    int dayNumber;
    printf("Въведи номер на ден от седмицата (1-7): ");
    scanf("%d", &dayNumber);
    if (dayNumber < 1 || dayNumber > 7) {
        printf("Невалиден номер на ден. Моля, въведи число от 1 до 7.\n");
        return 1;
    }
    dayofweek day = (dayofweek)dayNumber;
    switch (day) {
        case MONDAY:    printf("Понеделник\n"); break;
        case TUESDAY:   printf("Вторник\n"); break;
        case WEDNESDAY: printf("Сряда\n"); break;
        case THURSDAY:  printf("Четвъртък\n"); break;
        case FRIDAY:    printf("Петък\n"); break;
        case SATURDAY:  printf("Събота\n"); break;
        case SUNDAY:    printf("Неделя\n"); break;
    }
    return 0;
}
