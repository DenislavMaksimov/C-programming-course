#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char firstname[50];
    struct Node *father;
    struct Node *mother;
    struct Node *MarriedTo;
} Node;

Node* createMember(const char *name, Node *father, Node *mother) {
    Node *newMember = (Node *)malloc(sizeof(Node));
    if (newMember == NULL) {
        printf("Грешка при заделяне на памет!\n");
        exit(1);
    }
    strncpy(newMember->firstname, name, sizeof(newMember->firstname));
    newMember->father = father;
    newMember->mother = mother;
    newMember->MarriedTo = NULL;
    return newMember;
}

void marry(Node *person1, Node *person2) {
    if (person1 != NULL && person2 != NULL) {
        person1->MarriedTo = person2;
        person2->MarriedTo = person1;
    }
}

void printMember(const Node *member) {
    if (member == NULL) return;
    
    printf("Name: %s\n", member->firstname);
    if (member->father != NULL)
        printf("  Father: %s\n", member->father->firstname);
    else
        printf("  Father: неизвестен\n");

    if (member->mother != NULL)
        printf("  Mother: %s\n", member->mother->firstname);
    else
        printf("  Mother: неизвестна\n");

    if (member->MarriedTo != NULL)
        printf("  Married to: %s\n", member->MarriedTo->firstname);
    else
        printf("  do not married\n");

    printf("\n");
}

int main() {
    Node *grandfather1 = createMember("Дядо Едно", NULL, NULL);
    Node *grandmother1 = createMember("Баба Едно", NULL, NULL);
    Node *grandfather2 = createMember("Дядо Две", NULL, NULL);
    Node *grandmother2 = createMember("Баба Две", NULL, NULL);
    marry(grandfather1, grandmother1);
    marry(grandfather2, grandmother2);
    Node *father = createMember("Син Едно", grandfather1, grandmother1);
    Node *mother = createMember("Дъщеря Две", grandfather2, grandmother2);
    marry(father, mother);
    Node *me = createMember("Дете ЕдноДве", father, mother);
    printf("== Родословно дърво ==\n\n");
    printMember(grandfather1);
    printMember(grandmother1);
    printMember(grandfather2);
    printMember(grandmother2);
    printMember(father);
    printMember(mother);
    printMember(me);

    free(grandfather1);
    free(grandmother1);
    free(grandfather2);
    free(grandmother2);
    free(father);
    free(mother);
    free(me);

    return 0;
}
