#include<stdio.h>
#include<stdlib.h>

double** allocate_matrix(size_t rows, size_t cols)
{
    double** matrix = malloc(rows * sizeof(double*));
    if(!matrix)
        return NULL;
    
    for(size_t i = 0; i < rows; i++)
    {
        matrix[i] = malloc(cols * sizeof(double));
        if(!matrix[i])
        {
            for(size_t j = 0; j < i; j++)
                free(matrix[j]);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void free_matrix(double** matrix, size_t rows)
{
    if(!matrix)
        return;
    for(size_t i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

void fill_matrix(double** matrix, size_t rows, size_t cols)
{
    printf("Введите элементы матрицы (%zu x %zu):\n", rows, cols);
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < cols; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void print_matrix(double** matrix, size_t rows, size_t cols)
{
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < cols; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    size_t rows, cols;
    
    printf("Введите количество строк и столбцов: ");
    scanf("%zu %zu", &rows, &cols);
    
    double** matrix = allocate_matrix(rows, cols);
    if(!matrix)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    fill_matrix(matrix, rows, cols);
    
    printf("\nМатрица:\n");
    print_matrix(matrix, rows, cols);
    
    free_matrix(matrix, rows);
    return 0;
}