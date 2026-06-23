#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *row1 = malloc(sizeof(int) * 3);
    int *row2 = malloc(sizeof(int) * 3);
    int **colls = malloc(sizeof(int*) * 6);
    colls[0] = row1;
    colls[1] = row2;
    for(int i = 0; i < 6; i++)
    {
        scanf("%d", (colls+i));
    }
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", *(colls+i));
        if(i == 2)
        {
            printf("\n");
        }
    }
    printf("\n");
    free(colls);
    free(row2);
    free(row1);
}