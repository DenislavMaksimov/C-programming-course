#include <stdio.h>
#include <stdbool.h>

#define MAX_PEOPLE 100

typedef struct {
    char name[25];
    char surname[25];
    char lastname[25];
    char email[50];
    char phone_number[13];
} Person;

typedef struct {
    Person person;
    bool will_participate;
} Answer;

typedef struct {
    char title[100];
    char description[300];
    struct {
        int day;
        int month;
        int year;
        struct {
            int hour;
            int minutes;
        } HourOfDay;
    } data;
    Answer answers [MAX_PEOPLE];
    int NumberOfAnswers;
} Cause;

void printPerson(Person p) {
    printf("Име: %s %s %s\n", p.name, p.surname, p.lastname);
    printf("Имейл: %s\n", p.email);
    printf("Телефон: %s\n", p.phone_number);
}

void printAnswer(Answer a) {
    printPerson(a.person);
    printf("Ще участва: %s\n", a.will_participate ? "Да" : "Не");
}

void printData(const void *data_ptr) {
    const struct {
        int day;
        int month;
        int year;
        struct {
            int hour;
            int minutes;
        } HourOfDay;
    } *data=data_ptr; 
        printf("Дата: %02d.%02d.%04d в %02d:%02d\n",
            data->day, data->month, data->year,
            data->HourOfDay.hour, data->HourOfDay.minutes);
}

void printCause(Cause c) {
    printf("Кауза: %s\n", c.title);
    printf("Описание: %s\n", c.description);
    printData(&c.data);
    printf("Участници:\n");
    for (int i = 0; i < c.NumberOfAnswers; ++i) {
        printf("Участник #%d:\n", i + 1);
        printAnswer(c.answers[i]);
        printf("\n");
    }
}

int main() {
    Cause causes[2] = {
        {
            .title = "Залесяване на парк",
            .description = "Доброволческа инициатива за залесяване на градски парк.",
            .data = {28, 4, 2025, {10, 30}},
            .answers = {
                {{ "Иван", "Петров", "Иванов", "ivan@gmail.com", "0899999999" }, true},
                {{ "Мария", "Георгиева", "Стоянова", "maria@gmail.com", "0889999999" }, false}
            },
            .NumberOfAnswers = 2
        },
        {
            "Пренасяе на нещата от ТУЕС",
            "Събиране на доброволци за помощ в пренасянето.",
            {01, 7, 2025, {10, 0}},
            {
                {{ "Георги", "Димитров", "Николов", "georgi@gmail.com", "0888888888" }, true},
                {{ "Елена", "Иванова", "Костова", "elena@gmail.com", "0898888888" }, true}
            },
            2
        }
    };
    for (int i = 0; i < 2; ++i) {
        printf("==== Кауза #%d ====\n", i + 1);
        printCause(causes[i]);
        printf("\n");
    }

    return 0;
}


