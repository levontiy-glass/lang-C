#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n = 0, sum = 0;
    while (n <= 1 || n >= 1000)
    {
        printf("Элементов в массиве: ");
        scanf("%d", &n);
        if(n <= 1 || n >= 1000)
        {
            printf("Число должно быть больше 1 и меньше 1000!\n");
        }
    }
    int *arr = malloc(sizeof(int) * n);
    printf("Ввод элементов\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    for(int i = n-1; i >= 0; i--)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}