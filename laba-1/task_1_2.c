#include<stdio.h>

int main()
{
    int a, b;
    printf("Введите числа которые будут суммироваться.\n");
    scanf("%d %d", &a, &b);
    int c = a + b;
    printf("Результат: %d\n", c);
}