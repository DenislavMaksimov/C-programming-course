#include "mystrings.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./strconcat.out <string1> <string2>\n");
        return 1;
    }

    if (strlen(argv[1]) > 50 || strlen(argv[2]) > 50) {
        printf("Error: Всеки сринг трябва да е най-много 50.\n");
        return 1;
    }

    char result[101]; 
    strcpy(result, argv[1]);
    strconcat(result, argv[2]);
    printf("%s\n", result);
    return 0;
}
