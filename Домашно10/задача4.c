#include <stdio.h>


int compareasc(const void *a, const void *b) {
    int value1 = *(int*)a;
    int value2 = *(int*)b;
    return (value1 > value2) - (value1 < value2);
}

int comparedesc(const void *a, const void *b) {
    int value1 = *(int*)a;
    int value2 = *(int*)b;
    return (value1 < value2) - (value1 > value2);
}

int main() {
    int a = 8, b = 12;
    printf("compareasc: %d\n", compareasc(&a, &b));
    printf("comparedesc: %d\n", comparedesc(&a, &b));
    
    return 0;
}