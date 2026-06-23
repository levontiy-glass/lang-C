#include<stdio.h>
#include<math.h>

float h(float a, float b, float c, float x)
{
    float hx = -(x/a)/(pow(x*x + a*a, 1/3)) - (4 * pow((x*x + b*b), 3/4))/(2 + a + b + pow((x - c), 2/3));
}

int main()
{
    float a = 0.12, b = 0.35, c = 2.4, x = 1.4;
    float H = h(a, b, c, x);
    printf("| a = %f, b = %f, c = %f, x = %f | h = %f |\n", a, b, c, x, H);
    x = 1.6;
    H = h(a, b, c, x);
    printf("| a = %f, b = %f, c = %f, x = %f | h = %f |\n", a, b, c, x, H);
    a = 0.27, b = 3.9, c = 2.8, x = 1.8;
    H = h(a, b, c, x);
    printf("| a = %f, b = %f, c = %f, x = %f | h = %f |\n", a, b, c, x, H);
}