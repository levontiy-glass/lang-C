#include<stdio.h>

int main()
{
    int a, b;
    int *pa = &a;
    int *pb = &b;
    scanf("%d %d", pa, pb);
    int sum =  *pa + *pb;
    printf("%d\n", sum);
}