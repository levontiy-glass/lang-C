#include<stdio.h>
#include<math.h>

struct Complex
{
    double real;
    double imag;
};

struct Complex complex_add(struct Complex z1, struct Complex z2)
{
    struct Complex result;
    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return result;
}

struct Complex complex_mul(struct Complex z1, struct Complex z2)
{
    struct Complex result;
    result.real = z1.real * z2.real - z1.imag * z2.imag;
    result.imag = z1.real * z2.imag + z1.imag * z2.real;
    return result;
}

struct Complex complex_div_scalar(struct Complex z, double scalar)
{
    struct Complex result;
    result.real = z.real / scalar;
    result.imag = z.imag / scalar;
    return result;
}

void print_complex(struct Complex z)
{
    if(z.imag >= 0)
        printf("%.4f + %.4fi", z.real, z.imag);
    else
        printf("%.4f - %.4fi", z.real, -z.imag);
}

struct Complex complex_exp(struct Complex z, int n)
{
    struct Complex result = {1.0, 0.0};
    struct Complex term = {1.0, 0.0};
    double factorial = 1.0;
    
    for(int i = 1; i <= n; i++)
    {
        factorial *= i;
        term = complex_mul(term, z);
        struct Complex add_term = complex_div_scalar(term, factorial);
        result = complex_add(result, add_term);
    }
    
    return result;
}

int main()
{
    struct Complex z;
    int n;
    
    printf("Введите действительную часть z: ");
    scanf("%lf", &z.real);
    printf("Введите мнимую часть z: ");
    scanf("%lf", &z.imag);
    printf("Введите количество членов ряда n: ");
    scanf("%d", &n);
    
    printf("z = ");
    print_complex(z);
    printf("\n");
    
    struct Complex exp_z = complex_exp(z, n);
    printf("exp(z) = ");
    print_complex(exp_z);
    printf("\n");
    
    return 0;
}