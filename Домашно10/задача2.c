#include <stdio.h>
#include <stdio.h>

void remove_newline(char *str) {
    char *p = strchr(str, '\n');
    if (p) {
        *p = '\0';
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    remove_newline(input);
    printf("Processed string: %s\n", input);
    return 0;
}
