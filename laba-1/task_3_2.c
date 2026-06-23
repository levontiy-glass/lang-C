#include<stdio.h>

int main()
{
    int X[5];
    printf("Введите X1, X2, X3, X4, X5\n");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &X[i]);
    }
    for(int i = 4; i >= 0; i--)
    {
        printf("%d ", X[i]);
    }
    printf("\n");
}