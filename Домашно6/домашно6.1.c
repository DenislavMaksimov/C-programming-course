#include <stdio.h>
#include <limits.h>
#define PRINT_TYPE_INFO(type, format, uformat, max_unsigned) \
    printf("%-10s %-10s %5lu %14d %14d %-10s %14u\n", \
           #type, format, sizeof(type), INT_MIN, INT_MAX, uformat, max_unsigned)

int main() {
    printf("%-10s %-10s %5s %14s %14s %-10s %14s\n",
           "Type", "Format", "Size", "Signed Min", "Signed Max", "UFormat", "Unsigned Max");
    printf("-----------------------------------------------\n");

    PRINT_TYPE_INFO(int, "%d", "%u", UINT_MAX);
    PRINT_TYPE_INFO(short, "%hd", "%hu", USHRT_MAX);
    PRINT_TYPE_INFO(long, "%ld", "%lu", ULONG_MAX);
    PRINT_TYPE_INFO(char, "%c", "%hhu", UCHAR_MAX);
    return 0;
}
