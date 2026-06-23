#include<stdio.h>

union ByteView
{
    unsigned long value;
    unsigned char bytes[sizeof(unsigned long)];
};

int main()
{
    union ByteView uv;
    
    printf("Введите беззнаковое длинное целое: ");
    scanf("%lu", &uv.value);
    
    printf("Побайтовое представление (от старшего к младшему):\n");
    for(int i = sizeof(unsigned long) - 1; i >= 0; i--)
    {
        printf("%02X ", uv.bytes[i]);
    }
    printf("\n");
    
    return 0;
}