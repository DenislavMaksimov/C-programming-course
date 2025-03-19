#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    printf("Брой колони:");
    scanf("%d", &cols);
    printf("Брой редове:");
    scanf("%d", &rows);

    int **matrix=(int **)malloc(rows * sizeof(int *));
    if (matrix==NULL)
    {
        printf(" Не е заделена памет");
        return 1;
    }

    for(int i=0; i<rows; i++)
    {
        matrix[i]=(int *)malloc(cols * sizeof(int));
        if (matrix[i]==NULL)
        {
            printf("Неуспешно заделена памет за ред:", i);
            return 1;
        }
    }
    
    int counter=1;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            *(*(matrix+i)+j)=counter++;
        }
    }

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("Масива е ", *(*(matrix+i)+j));
        }
        printf("\n");
    }

    for(int j=0; j<cols; j++)
    {
        for(int i=0; i<rows; i++)
        {
            printf("Масива е ", *(*(matrix+i)+j));
        }
    }
    printf("\n");
    
    for(int i=0; i<rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

