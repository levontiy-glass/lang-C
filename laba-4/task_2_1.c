#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MY_SIZE 32
#define BUF_SIZE 64

int main()
{
    char my_string[MY_SIZE];
    char copy[BUF_SIZE];
    char concat[BUF_SIZE];
    char lower_str[BUF_SIZE];
    char upper_str[BUF_SIZE];
    
    printf("Введите строку (до 10 латинских символов): ");
    fgets(my_string, MY_SIZE, stdin);
    
    // Удаляем символ новой строки
    size_t len = strlen(my_string);
    if(len > 0 && my_string[len-1] == '\n')
        my_string[len-1] = '\0';
    
    // Шаг 1: Ручной подсчёт длины по индексам
    int len1 = 0;
    for(int i = 0; my_string[i] != '\0'; i++)
        len1++;
    printf("1. Длина по индексам: %d\n", len1);
    
    // Шаг 2: Ручной подсчёт длины по указателю
    int len2 = 0;
    char* p = my_string;
    while(*p != '\0')
    {
        len2++;
        p++;
    }
    printf("2. Длина по указателю: %d\n", len2);
    
    // Шаг 3: Подсчёт длины библиотечной функцией
    size_t len3 = strlen(my_string);
    printf("3. Длина через strlen: %zu\n", len3);
    
    // Шаг 4: Копирование строки
    strcpy(copy, my_string);
    printf("4. Исходная: \"%s\", Копия: \"%s\"\n", my_string, copy);
    
    // Шаг 5: Конкатенация двух строк
    char str1[] = "Hello";
    char str2[] = "World";
    strcpy(concat, str1);
    strcat(concat, " ");
    strcat(concat, str2);
    printf("5. Конкатенация: \"%s\" + \"%s\" = \"%s\"\n", str1, str2, concat);
    
    // Шаг 6: Сравнение строк
    char cmp1[] = "apple";
    char cmp2[] = "banana";
    char cmp3[] = "apple";
    int res1 = strcmp(cmp1, cmp2);
    int res2 = strcmp(cmp1, cmp3);
    printf("6. Сравнение \"%s\" и \"%s\": %d (первая меньше)\n", cmp1, cmp2, res1);
    printf("   Сравнение \"%s\" и \"%s\": %d (равны)\n", cmp1, cmp3, res2);
    
    // Шаг 7: Перевод регистра
    strcpy(lower_str, my_string);
    strcpy(upper_str, my_string);
    for(int i = 0; lower_str[i] != '\0'; i++)
    {
        lower_str[i] = tolower((unsigned char)lower_str[i]);
        upper_str[i] = toupper((unsigned char)upper_str[i]);
    }
    printf("7. Исходная: \"%s\"\n", my_string);
    printf("   Нижний регистр: \"%s\"\n", lower_str);
    printf("   Верхний регистр: \"%s\"\n", upper_str);
    
    return 0;
}