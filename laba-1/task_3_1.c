#include<stdio.h>

int main()
{
    int X[2];
    printf("Введите X1 и X2\n");
    scanf("%d %d", &X[0], &X[1]);
    printf("Y1 = %d Y2 = %d\n", X[0] * X[0], X[1] * X[1]);
    return 0;
}