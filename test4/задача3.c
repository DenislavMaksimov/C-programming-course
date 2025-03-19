#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int compareasc(int a, int b)
{
    if(a<b) return -1;
    if(a>b) return 1;
    return 0;
}

int comparedesc(int a, int b)
{
    if(a<b) return 1;
    if(a>b) return -1;
    return 0;
}

int main()
{
    int n;
    printf("Брой на елемети от масива");
    scanf("%d", &n);

    int *arr=(int *)malloc(n * sizeof(int));
    if(arr==NULL)
    {
        printf("Не е заделена памет");
        return 1;
    }

    printf("Въведете елемтнтите на масива:");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    sort(arr, n, compareasc);
    printf("Масива във възходящ ред:");
    for(int i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    sort(arr, n, comparedesc);
    printf("Масива във низходящ ред:");
    for(int i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
