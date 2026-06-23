#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    printf("Введите до какого числа вычислять последовательность?\n");
    int m = 0;
    scanf("%d", &m);
    int size = sizeof(int)*5;
    int* P = malloc(size);
    P[0] = 1;
    P[1] = 1;
    P[2] = 1;
    P[3] = 2;
    P[4] = 2;
    printf("%d, %d, %d, %d", P[0], P[1], P[2], P[3]);
    int count = 3;
    for(;;;)
    {
        size = size + sizeof(int);
        int* temp = realloc(P, size);
        P = temp;
        count++;
        P[count] = P[count-2] + P[count-3];
        if(P[count] >= m)
        {
            break;
        }
        printf(", %d", P[count]);
        
    }
    printf("\n");
}