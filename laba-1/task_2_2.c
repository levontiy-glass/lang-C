#include<stdio.h>
#include<math.h>

double F(double x) {
    float result = (x - 2) * (x + 2);
    return result;
}

double parabols(double a, double b, int n) {
    if (n % 2 != 0) {
        n++;
    }
    
    double result = 0.0;
    double h = (b - a) / n;
    
    result = F(a) + F(b);
    
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        result += 4 * F(x);
    }
    
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h;
        result += 2 * F(x);
    }
    
    return result * h / 3.0;
}

int main()
{
    float a = 0.0, b = 5.0, n = 5;
    printf("Ответ: %f\n", parabols(a, b, n));
}