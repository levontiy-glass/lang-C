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
    for(int i = 0; i < 3; i++)
    {
        n = 0;
        for(int j = 0; j < 3; j++)
        {
            n+=A[i][j];
        }
        n = n / 3;
        A[i][0] = n;
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}