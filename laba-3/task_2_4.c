#include<stdio.h>
#include<stdlib.h>

enum DataType
{
    INT_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE
};

union Value
{
    int int_val;
    float float_val;
    char char_val;
};

struct TaggedUnion
{
    enum DataType type;
    union Value value;
};

void print_tagged(struct TaggedUnion* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Элемент %d: ", i + 1);
        switch(arr[i].type)
        {
            case INT_TYPE:
                printf("int = %d\n", arr[i].value.int_val);
                break;
            case FLOAT_TYPE:
                printf("float = %.2f\n", arr[i].value.float_val);
                break;
            case CHAR_TYPE:
                printf("char = %c\n", arr[i].value.char_val);
                break;
            default:
                printf("Неизвестный тип\n");
        }
    }
}

int main()
{
    int n;
    printf("Введите количество элементов массива: ");
    scanf("%d", &n);
    
    struct TaggedUnion* arr = (struct TaggedUnion*)malloc(n * sizeof(struct TaggedUnion));
    
    for(int i = 0; i < n; i++)
    {
        int type_choice;
        printf("\nЭлемент %d:\n", i + 1);
        printf("Выберите тип (0 - int, 1 - float, 2 - char): ");
        scanf("%d", &type_choice);
        
        arr[i].type = (enum DataType)type_choice;
        
        switch(arr[i].type)
        {
            case INT_TYPE:
                printf("Введите целое число: ");
                scanf("%d", &arr[i].value.int_val);
                break;
            case FLOAT_TYPE:
                printf("Введите вещественное число: ");
                scanf("%f", &arr[i].value.float_val);
                break;
            case CHAR_TYPE:
                printf("Введите символ: ");
                scanf(" %c", &arr[i].value.char_val);
                break;
        }
    }
    
    printf("\nРезультаты:\n");
    print_tagged(arr, n);
    
    free(arr);
    return 0;
}