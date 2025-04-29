#include <stdio.h>
typedef unsigned long long ull;
typedef ull (*ReduceFunc)(ull, ull);

ull reduce(ull arr[], ull size, ReduceFunc func, ull initial) {
    ull result = initial;
    for (ull i = 0; i < size; ++i) {
        result = func(result, arr[i]);
    }
    return result;
}

ull add(ull a, ull b) {
    return a + b;
}

int main() {
    ull arr[] = {1, 2, 3};
    ull size = sizeof(arr) / sizeof(arr[0]);
    ull initial = 0;
    ull result = reduce(arr, size, add, initial);
    printf("Result: %llu\n", result); 
    return 0;
}



#include <stdio.h>
#include <stdbool.h>

#define MAX_UCHASTNICI 100

typedef struct {
    char ime[30];
    char prezime[30];
    char familno[30];
    char email[50];
    char telefon[20];
} Uchastnik;

typedef struct {
    Uchastnik uchastnik;
    bool shte_uchastva;
} Otgovor;

typedef struct {
    char zaglavie[100];
    char opisanie[300];
    struct {
        int den;
        int mesec;
        int godina;
        struct {
            int chas;
            int minuti;
        } chasOtDenq;
    } data;
    Otgovor otgovori[MAX_UCHASTNICI];
    int broiOtgovori;
} Kauza;

// Функция за принтиране на участник
void printUchastnik(Uchastnik u) {
    printf("Име: %s %s %s\n", u.ime, u.prezime, u.familno);
    printf("Имейл: %s\n", u.email);
    printf("Телефон: %s\n", u.telefon);
}

// Функция за принтиране на отговор
void printOtgovor(Otgovor o) {
    printUchastnik(o.uchastnik);
    printf("Ще участва: %s\n", o.shte_uchastva ? "Да" : "Не");
}

// Функция за принтиране на дата
void printData(struct {
    int den;
    int mesec;
    int godina;
    struct {
        int chas;
        int minuti;
    } chasOtDenq;
} data) {
    printf("Дата: %02d.%02d.%04d в %02d:%02d\n",
           data.den, data.mesec, data.godina,
           data.chasOtDenq.chas, data.chasOtDenq.minuti);
}

// Функция за принтиране на кауза
void printKauza(Kauza k) {
    printf("Кауза: %s\n", k.zaglavie);
    printf("Описание: %s\n", k.opisanie);
    printData(k.data);
    printf("Участници:\n");
    for (int i = 0; i < k.broiOtgovori; ++i) {
        printf("Участник #%d:\n", i + 1);
        printOtgovor(k.otgovori[i]);
        printf("\n");
    }
}

int main() {
    // Създаване на две каузи

    Kauza kauzi[2] = {
        {
            .zaglavie = "Залесяване на парк",
            .opisanie = "Доброволческа инициатива за залесяване на градски парк.",
            .data = {25, 4, 2025, {10, 30}},
            .otgovori = {
                {{ "Иван", "Петров", "Иванов", "ivan@example.com", "0888123456" }, true},
                {{ "Мария", "Георгиева", "Стоянова", "maria@example.com", "0899123456" }, false}
            },
            .broiOtgovori = 2
        },
        {
            "Помощ в приют за животни",
            "Събиране на доброволци за помощ в приюта.",
            {12, 5, 2025, {14, 0}},
            {
                {{ "Георги", "Димитров", "Николов", "georgi@example.com", "0877123456" }, true},
                {{ "Елена", "Иванова", "Костова", "elena@example.com", "0887123456" }, true}
            },
            2
        }
    };

    // Принтиране на каузите
    for (int i = 0; i < 2; ++i) {
        printf("==== Кауза #%d ====\n", i + 1);
        printKauza(kauzi[i]);
        printf("\n");
    }

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура за представяне на член на семейството
typedef struct Node {
    char firstname[50];
    struct Node* father;
    struct Node* mother;
    struct Node* marriedto;
} Node;

// Функция за създаване на нов член на семейството
Node* createMember(const char* name, Node* father, Node* mother) {
    Node* newMember = (Node*)malloc(sizeof(Node));
    if (!newMember) {
        printf("Грешка при заделяне на памет.\n");
        exit(1);
    }

    strncpy(newMember->firstname, name, sizeof(newMember->firstname));
    newMember->father = father;
    newMember->mother = mother;
    newMember->marriedto = NULL;

    return newMember;
}

// Функция за отпечатване на информация за член
void printMember(Node* member) {
    if (!member) return;

    printf("Име: %s\n", member->firstname);
    printf("Баща: %s\n", member->father ? member->father->firstname : "неизвестен");
    printf("Майка: %s\n", member->mother ? member->mother->firstname : "неизвестна");
    printf("Женен/Омъжена за: %s\n", member->marriedto ? member->marriedto->firstname : "неженен/неомъжена");
    printf("---------------------------\n");
}

int main() {
    // Създаваме баби и дядовци (неизвестни родители => NULL)
    Node* grandfather1 = createMember("Иван", NULL, NULL);
    Node* grandmother1 = createMember("Мария", NULL, NULL);
    Node* grandfather2 = createMember("Георги", NULL, NULL);
    Node* grandmother2 = createMember("Елена", NULL, NULL);

    // Създаваме родители
    Node* father = createMember("Николай", grandfather1, grandmother1);
    Node* mother = createMember("Анна", grandfather2, grandmother2);

    // Женим родителите
    father->marriedto = mother;
    mother->marriedto = father;

    // Създаваме себе си
    Node* me = createMember("Александър", father, mother);

    // Печатаме информация
    printMember(grandfather1);
    printMember(grandmother1);
    printMember(grandfather2);
    printMember(grandmother2);
    printMember(father);
    printMember(mother);
    printMember(me);

    // Освобождаваме заделената памет
    free(grandfather1);
    free(grandmother1);
    free(grandfather2);
    free(grandmother2);
    free(father);
    free(mother);
    free(me);

    return 0;
}
