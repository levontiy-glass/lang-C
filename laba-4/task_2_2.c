#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<ctype.h>

int main()
{
    char int_str[64];
    char float_str[64];
    char* endptr;
    long int_val;
    double float_val;
    
    printf("Введите строку с целым числом: ");
    fgets(int_str, sizeof(int_str), stdin);
    // Удаляем новую строку
    int_str[strcspn(int_str, "\n")] = '\0';
    
    printf("Введите строку с вещественным числом: ");
    fgets(float_str, sizeof(float_str), stdin);
    float_str[strcspn(float_str, "\n")] = '\0';
    
    // Преобразование целого числа
    errno = 0;
    endptr = NULL;
    int_val = strtol(int_str, &endptr, 10);
    
    printf("\n--- Преобразование целого числа ---\n");
    printf("Исходная строка: \"%s\"\n", int_str);
    if(endptr == int_str)
    {
        printf("Ошибка: не найдено ни одного числового символа\n");
    }
    else if(errno == ERANGE)
    {
        printf("Ошибка: число вне допустимого диапазона\n");
    }
    else
    {
        printf("Результат: %ld\n", int_val);
        if(*endptr != '\0')
        {
            printf("Предупреждение: после числа остались символы: \"%s\"\n", endptr);
        }
        else
        {
            printf("Успешно: вся строка преобразована в число\n");
        }
    }
    
    // Преобразование вещественного числа
    errno = 0;
    endptr = NULL;
    float_val = strtod(float_str, &endptr);
    
    printf("\n--- Преобразование вещественного числа ---\n");
    printf("Исходная строка: \"%s\"\n", float_str);
    if(endptr == float_str)
    {
        printf("Ошибка: не найдено ни одного числового символа\n");
    }
    else if(errno == ERANGE)
    {
        printf("Ошибка: число вне допустимого диапазона\n");
    }
    else
    {
        printf("Результат: %f\n", float_val);
        if(*endptr != '\0')
        {
            printf("Предупреждение: после числа остались символы: \"%s\"\n", endptr);
        }
        else
        {
            printf("Успешно: вся строка преобразована в число\n");
        }
    }
    
    return 0;
}