#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int A[7];
    int temp = 0;
    bool unused[10];
    for(int i = 0; i < 10; i++)
    {
        unused[i] = true;
    }
    printf("Массив:\n");
    for(int i = 0; i < 6;)
    {
        temp = rand() % 10;
        if(unused[temp])
        {
            A[i] = temp;
            printf("%d ", A[i]);
            unused[temp] = false;
            i++;
            
        }
    }
    printf("\nОтсортированный массив:\n");

    for (int i = 0; i < 6; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(A[i] < A[i-j])
            {
                temp = A[i];
                A[i] = A[i-j];
                A[i-j] = temp;
                i = 0;
            }
        }
    }
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", A[i]);
    }
}
