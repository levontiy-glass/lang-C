#include<stdio.h>

struct strc
{
    int (*pfunk)(int);
    int num;
};

int funk(int a)
{
    return a*a;
}

int main()
{
    struct strc square = {&funk, 3};
    printf("%d\n", square.pfunk(square.num));
}