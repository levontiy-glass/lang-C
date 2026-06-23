#include<stdio.h>

union Data
{
    int int_val;
    float float_val;
    char char_val;
};

int main()
{
    union Data data;
    union Data* pdata = &data;
    
    pdata->int_val = 42;
    printf("Целое значение: %d\n", pdata->int_val);
    
    pdata->float_val = 3.14;
    printf("Вещественное значение: %.2f\n", pdata->float_val);
    
    pdata->char_val = 'A';
    printf("Символьное значение: %c\n", pdata->char_val);
    
    return 0;
}