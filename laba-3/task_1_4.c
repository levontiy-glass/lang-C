#include<stdio.h>

struct Date
{
    unsigned int day : 5;    // 0-31
    unsigned int month : 4;  // 0-15
    unsigned int year : 12;  // 0-4095
};

int main()
{
    struct Date birthday;
    
    printf("Введите день рождения (1-31): ");
    int day;
    scanf("%d", &day);
    birthday.day = day;
    
    printf("Введите месяц рождения (1-12): ");
    int month;
    scanf("%d", &month);
    birthday.month = month;
    
    printf("Введите год рождения: ");
    int year;
    scanf("%d", &year);
    birthday.year = year;
    
    printf("\nДата рождения: %d.%d.%d\n", birthday.day, birthday.month, birthday.year);
    printf("Размер структуры Date: %lu байт\n", sizeof(struct Date));
    
    return 0;
}