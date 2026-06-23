#include<stdio.h>

void cross3(const double a[3], const double b[3], double out[3])
{
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
}

double dot3(const double a[3], const double b[3])
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

double triple3(const double a[3], const double b[3], const double c[3])
{
    double tmp[3];
    cross3(b, c, tmp);
    return dot3(a, tmp);
}

void print_vector(const char* name, const double v[3])
{
    printf("%s = (%.2f, %.2f, %.2f)\n", name, v[0], v[1], v[2]);
}

int main()
{
    double a[3], b[3], c[3];
    
    printf("Введите вектор a (x y z): ");
    scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);
    printf("Введите вектор b (x y z): ");
    scanf("%lf %lf %lf", &b[0], &b[1], &b[2]);
    printf("Введите вектор c (x y z): ");
    scanf("%lf %lf %lf", &c[0], &c[1], &c[2]);
    
    printf("\nВекторы:\n");
    print_vector("a", a);
    print_vector("b", b);
    print_vector("c", c);
    
    double result = triple3(a, b, c);
    printf("\nСмешанное произведение [a, b, c] = %.2f\n", result);
    
    if(result == 0)
        printf("Векторы компланарны (лежат в одной плоскости)\n");
    else
        printf("Объём параллелепипеда = %.2f\n", result > 0 ? result : -result);
    
    return 0;
}