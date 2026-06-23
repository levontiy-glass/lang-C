#include<stdio.h>
#include<stdlib.h>

void swap_pairs(int* arr, int size)
{
    for(int i = 0; i + 1 < size; i += 2)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void print_array(int* arr, int size)
{
    printf("[");
    for(int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if(i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main()
{
    int size = 12;
    int* arr = malloc(size * sizeof(int));
    
    if(!arr)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    printf("Введите 12 целых чисел через пробел: ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Исходный массив: ");
    print_array(arr, size);
    
    swap_pairs(arr, size);
    
    printf("После обмена пар: ");
    print_array(arr, size);
    
    free(arr);
    return 0;
}