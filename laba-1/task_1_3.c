#include<stdio.h>
#include<math.h>

float sinxy(int x, int y)
{
    return sin(x+y);
}

int main()
{
    int x, y;
    printf("Введите аргументы (x, y) для функции.\n");
    scanf("%d %d", &x, &y);
    float u = (1 + sinxy(x, y) * sinxy(x, y))/(2 + fabs(x - (2*x*x)/(1+fabs(sinxy(x, y)))));
    printf("Результат: %f\n", u);
}