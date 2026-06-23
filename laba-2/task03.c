#include<stdio.h>

int main()
{
    int a, b;
    int *pa = &a;
    int *pb = &b;
    scanf("%d %d", pa, pb);
    int max;
    if(*pa > *pb)
    {
        max = *pa;
    }
    else
    {
        max = *pb;
    }
    printf("%d\n", max);
}