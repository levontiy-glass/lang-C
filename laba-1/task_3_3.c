#include<stdio.h>

int main()
{
    int A[3][3];
    int n = 1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            A[i][j] = n;
            n++;
        }
    }

    int AT[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            AT[i][j] = A[j][i];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", AT[i][j]);
        }
        printf("\n");
    }
}