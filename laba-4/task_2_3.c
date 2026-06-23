#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_LEN 64

int main()
{
    char str[MAX_LEN];
    
    printf("Введите строку (цифры, буквы, пробелы, знаки пунктуации): ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    
    printf("\nКлассификация символов строки \"%s\":\n", str);
    printf("------------------------------------------------\n");
    printf("Символ\tТип\n");
    printf("------------------------------------------------\n");
    
    for(int i = 0; str[i] != '\0'; i++)
    {
        unsigned char ch = (unsigned char)str[i];
        
        printf("'%c'\t", ch);
        
        if(ch == ' ')
        {
            printf("Пробел");
        }
        else if(isdigit(ch))
        {
            printf("Цифра");
        }
        else if(isalpha(ch))
        {
            if(isupper(ch))
                printf("Буква (заглавная)");
            else
                printf("Буква (строчная)");
        }
        else if(ispunct(ch))
        {
            printf("Знак пунктуации");
        }
        else
        {
            printf("Другой символ (код %d)", ch);
        }
        printf("\n");
    }
    
    return 0;
}