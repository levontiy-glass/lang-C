#include<stdio.h>

int main()
{
    int a = 1234567890;
    int *pa = &a;
    unsigned char *ppa = (unsigned char*)&a;
    for(int i = (sizeof(int)/sizeof(unsigned char)) - 1; i >= 0; i--)
    {
        printf("%d ", *(ppa+i));
    }
    printf("\n");
}