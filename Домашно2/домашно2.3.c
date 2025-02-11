#include <stdio.h>
#define DEBUG_PRINT(h) \
    printf("Debug: %s = %d, File: %s, Line: %d\n", #h, (h), __FILE__, __LINE__)
int main() 
{
    int x = 11;
    DEBUG_PRINT(x);
    int y = x + 2;
    DEBUG_PRINT(y);
    return 0;
}
