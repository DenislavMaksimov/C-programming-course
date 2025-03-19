#include <stdio.h>

int stringLength(const char *str) {
    const char *ptr = str; 
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

int main() {
    const char *myString = "Hello, world!";
    int length = stringLength(myString);
    printf("Lengt of myString is: %d", length);
    return 0;
}

