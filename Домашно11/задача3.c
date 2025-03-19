#include <stdio.h>


void strhalf(const char *str, char **ptr) {
    if (str == NULL || ptr == NULL) return;
    int length = 0;
    const char *temp = str;
    while (*temp != '\0') {
        length++;
        temp++;
    }
    *ptr = (char *)(str + length / 2);
}

int main() {
    const char *myString = "Hello, world!";
    char *halfPtr = NULL;  
    strhalf(myString, &halfPtr);
    printf("%s\n", halfPtr);
    return 0;
}
