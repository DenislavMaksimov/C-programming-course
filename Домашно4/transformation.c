#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "transformation.h"

transformation string_to_long(const char *str) {
    transformation result;
    char *endptr;
    result.result = 0;
    result.error[0] = '\0';
    
    if (str == NULL || strlen(str) == 0) {
        strcpy(result.error, "Input string is empty");
        return result;
    }

    result.result = strtol(str, &endptr, 10);

    if (*endptr != '\0') {
        result.result = 0;
        strcpy(result.error, "Invalid input string");
    }
    return result;
}
