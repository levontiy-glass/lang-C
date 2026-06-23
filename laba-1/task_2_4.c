#include<stdio.h>
#include<math.h>


int main()
{
    bool flag = true;
    do
    {
        printf("Введите трёхзначное число: ");
        int num = 0;
        scanf("%d", &num);
        int n100 = num / 100;
        int n10 = (num % 100) / 10;
        int n1 = num % 10;  
        if (num < 99 || num > 1000)
        {
                printf("Введённое число не трёхзначное!");
        }    
        else if (n100 + n10 + n1 > 10)
        {
            
            printf("%d + %d + %d больше 10", n100, n10, n1);
        }
        else
        {
            printf("%d + %d + %d меньше 10", n100, n10, n1);
            flag = false;
        }
        printf("\n");
    } while (flag);
}