#include <stdio.h>

void swap(void *a, void *b)
{
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;

}

int main()
{
    int x = 8, y = 12;
    printf("The nuber before the swap: x=%d and y=%d", x, y);
    swap(&x, &y);
    printf("The numbers after after the swap: x=%d and y=%d", x, y);

    return 0;
}


