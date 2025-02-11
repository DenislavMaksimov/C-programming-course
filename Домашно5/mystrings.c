#include "mystrings.h"
#include <string.h>
#include <stdio.h>

int strlength(const char *str) 
    {
        return strlen(str);
    }
void strconcat(char *str1, const char *str2) 
    {
        strcat(str1, str2);
    }
int strcompare(const char *str1, const char *str2) 
    {
        return strcmp(str1, str2);
    }
