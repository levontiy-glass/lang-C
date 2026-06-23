#include<stdio.h>

int main()
{
    int a, b;
    int *pa = &a;
    int *pb = &b;
    scanf("%d %d", pa, pb);
    printf("%d, %d\n", *pa, *pb);
    int *temp = pa;
    pa = pb;
    pb = temp;
    printf("%d, %d\n", *pa, *pb);
}