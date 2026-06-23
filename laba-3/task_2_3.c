#include<stdio.h>

enum Days
{
    Ponedelnik = 1,
    Vtornik,
    Sreda,
    Chetverg,
    Pyatnica,
    Subbota,
    Voskresenye
};

int main()
{
    printf("Дни недели:\n");
    printf("%d - Понедельник\n", Ponedelnik);
    printf("%d - Вторник\n", Vtornik);
    printf("%d - Среда\n", Sreda);
    printf("%d - Четверг\n", Chetverg);
    printf("%d - Пятница\n", Pyatnica);
    printf("%d - Суббота\n", Subbota);
    printf("%d - Воскресенье\n", Voskresenye);
    
    return 0;
}