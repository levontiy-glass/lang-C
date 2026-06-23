#include<stdio.h>

long long factorial_iter(int n)
{
    long long result = 1;
    for(int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

long long factorial_rec(int n)
{
    if(n <= 1)
        return 1;
    return n * factorial_rec(n - 1);
}

int main()
{
    int numbers[] = {0, 1, 5, 7, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Сравнение итеративного и рекурсивного факториала:\n");
    printf("n\tИтеративно\tРекурсивно\tСовпадают?\n");
    printf("------------------------------------------------\n");
    
    for(int i = 0; i < size; i++)
    {
        int n = numbers[i];
        long long iter = factorial_iter(n);
        long long rec = factorial_rec(n);
        printf("%d\t%lld\t\t%lld\t\t%s\n", n, iter, rec, (iter == rec) ? "Да" : "Нет");
    }
    
    return 0;
}