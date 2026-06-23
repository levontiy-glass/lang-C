# Отчет по лабораторной работе №4

## Тема: Введение в функции. Базовая работа со строками (однобайтовыми)

---

## Комплект 1: Введение в функции

### Задача 1.1: Факториал: цикл и рекурсия (task_1_1.c)

#### Постановка задачи
Реализовать и сравнить два способа вычисления факториала: итеративный и рекурсивный. Обе функции должны давать одинаковый результат для одного и того же n. Корректно обработать случай n = 0.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| factorial_iter | long long(*) | итеративная функция |
| factorial_rec | long long(*) | рекурсивная функция |
| n | int | число для вычисления факториала |
| result | long long | результат вычислений |
| numbers[] | int[] | массив тестовых значений |

#### Код программы
```c
#include<stdio.h>

long long factorial_iter(int n)
{
    long long result = 1;
    for(int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

long long factorial_rec(int n)
{
    if(n <= 1)
        return 1;
    return n * factorial_rec(n - 1);
}

int main()
{
    int numbers[] = {0, 1, 5, 7, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Сравнение итеративного и рекурсивного факториала:\n");
    printf("n\tИтеративно\tРекурсивно\tСовпадают?\n");
    printf("------------------------------------------------\n");
    
    for(int i = 0; i < size; i++)
    {
        int n = numbers[i];
        long long iter = factorial_iter(n);
        long long rec = factorial_rec(n);
        printf("%d\t%lld\t\t%lld\t\t%s\n", n, iter, rec, (iter == rec) ? "Да" : "Нет");
    }
    
    return 0;
}
```

#### Результаты работы программы
```
Сравнение итеративного и рекурсивного факториала:
n       Итеративно     Рекурсивно      Совпадают?
------------------------------------------------
0       1              1               Да
1       1              1               Да
5       120            120             Да
7       5040           5040            Да
10      3628800        3628800         Да
```

---

### Задача 1.2: Обмен чётных/нечётных ячеек массива (task_1_2.c)

#### Постановка задачи
Отработать передачу динамического массива в функцию и изменение данных "по месту". Функция делает попарный обмен соседних элементов: индексы 0↔1, 2↔3, 4↔5, ..., 10↔11.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| arr | int* | указатель на динамический массив |
| size | int | размер массива |
| swap_pairs | void(*) | функция обмена пар |
| print_array | void(*) | функция печати массива |
| temp | int | временная переменная для обмена |

#### Код программы
```c
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
```

#### Результаты работы программы
```
Введите 12 целых чисел через пробел: 1 2 3 4 5 6 7 8 9 10 11 12
Исходный массив: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
После обмена пар: [2, 1, 4, 3, 6, 5, 8, 7, 10, 9, 12, 11]
```

---

### Задача 1.3: Набор функций для матрицы double (task_1_3.c)

#### Постановка задачи
Реализовать функции выделения, заполнения, печати и освобождения двумерного динамического массива. Обеспечить отсутствие утечек памяти.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| rows, cols | size_t | размеры матрицы |
| matrix | double** | указатель на матрицу |
| allocate_matrix | double**(*) | функция выделения памяти |
| free_matrix | void(*) | функция освобождения памяти |
| fill_matrix | void(*) | функция заполнения матрицы |
| print_matrix | void(*) | функция печати матрицы |

#### Код программы
```c
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
```

#### Результаты работы программы
```
Введите количество строк и столбцов: 2 3
Введите элементы матрицы (2 x 3):
1.5 2.5 3.5
4.5 5.5 6.5

Матрица:
1.50 2.50 3.50 
4.50 5.50 6.50 
```

---

### Задача 1.4: Смешанное произведение трёх векторов в 3D (task_1_4.c)

#### Постановка задачи
Вычислить смешанное произведение трёх векторов через разбиение задачи на функции: векторное произведение, скалярное произведение и смешанное произведение.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| a, b, c | double[3] | векторы |
| out | double[3] | результат векторного произведения |
| tmp | double[3] | промежуточный вектор |
| cross3 | void(*) | функция векторного произведения |
| dot3 | double(*) | функция скалярного произведения |
| triple3 | double(*) | функция смешанного произведения |

#### Код программы
```c
#include<stdio.h>

void cross3(const double a[3], const double b[3], double out[3])
{
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
}

double dot3(const double a[3], const double b[3])
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

double triple3(const double a[3], const double b[3], const double c[3])
{
    double tmp[3];
    cross3(b, c, tmp);
    return dot3(a, tmp);
}

void print_vector(const char* name, const double v[3])
{
    printf("%s = (%.2f, %.2f, %.2f)\n", name, v[0], v[1], v[2]);
}

int main()
{
    double a[3], b[3], c[3];
    
    printf("Введите вектор a (x y z): ");
    scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);
    printf("Введите вектор b (x y z): ");
    scanf("%lf %lf %lf", &b[0], &b[1], &b[2]);
    printf("Введите вектор c (x y z): ");
    scanf("%lf %lf %lf", &c[0], &c[1], &c[2]);
    
    printf("\nВекторы:\n");
    print_vector("a", a);
    print_vector("b", b);
    print_vector("c", c);
    
    double result = triple3(a, b, c);
    printf("\nСмешанное произведение [a, b, c] = %.2f\n", result);
    
    if(result == 0)
        printf("Векторы компланарны (лежат в одной плоскости)\n");
    else
        printf("Объём параллелепипеда = %.2f\n", result > 0 ? result : -result);
    
    return 0;
}
```

#### Результаты работы программы
```
Введите вектор a (x y z): 1 0 0
Введите вектор b (x y z): 0 1 0
Введите вектор c (x y z): 0 0 1

Векторы:
a = (1.00, 0.00, 0.00)
b = (0.00, 1.00, 0.00)
c = (0.00, 0.00, 1.00)

Смешанное произведение [a, b, c] = 1.00
Объём параллелепипеда = 1.00
```

---

## Комплект 2: Базовые операции со строками

### Задача 2.1: Базовые строковые операции (task_2_1.c)

#### Постановка задачи
Освоить базовые операции с С-строкой: ручной подсчёт длины (по индексам и по указателю), подсчёт длины через strlen, копирование, конкатенация, сравнение, перевод регистра.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| MY_SIZE | #define | размер буфера |
| my_string | char[MY_SIZE] | исходная строка |
| copy | char[BUF_SIZE] | копия строки |
| concat | char[BUF_SIZE] | результат конкатенации |
| lower_str | char[BUF_SIZE] | строка в нижнем регистре |
| upper_str | char[BUF_SIZE] | строка в верхнем регистре |
| len1, len2 | int | ручной подсчёт длины |
| len3 | size_t | подсчёт через strlen |
| p | char* | указатель для обхода строки |

#### Код программы
```c
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MY_SIZE 32
#define BUF_SIZE 64

int main()
{
    char my_string[MY_SIZE];
    char copy[BUF_SIZE];
    char concat[BUF_SIZE];
    char lower_str[BUF_SIZE];
    char upper_str[BUF_SIZE];
    
    printf("Введите строку (до 10 латинских символов): ");
    fgets(my_string, MY_SIZE, stdin);
    
    size_t len = strlen(my_string);
    if(len > 0 && my_string[len-1] == '\n')
        my_string[len-1] = '\0';
    
    int len1 = 0;
    for(int i = 0; my_string[i] != '\0'; i++)
        len1++;
    printf("1. Длина по индексам: %d\n", len1);
    
    int len2 = 0;
    char* p = my_string;
    while(*p != '\0')
    {
        len2++;
        p++;
    }
    printf("2. Длина по указателю: %d\n", len2);
    
    size_t len3 = strlen(my_string);
    printf("3. Длина через strlen: %zu\n", len3);
    
    strcpy(copy, my_string);
    printf("4. Исходная: \"%s\", Копия: \"%s\"\n", my_string, copy);
    
    char str1[] = "Hello";
    char str2[] = "World";
    strcpy(concat, str1);
    strcat(concat, " ");
    strcat(concat, str2);
    printf("5. Конкатенация: \"%s\" + \"%s\" = \"%s\"\n", str1, str2, concat);
    
    char cmp1[] = "apple";
    char cmp2[] = "banana";
    char cmp3[] = "apple";
    int res1 = strcmp(cmp1, cmp2);
    int res2 = strcmp(cmp1, cmp3);
    printf("6. Сравнение \"%s\" и \"%s\": %d (первая меньше)\n", cmp1, cmp2, res1);
    printf("   Сравнение \"%s\" и \"%s\": %d (равны)\n", cmp1, cmp3, res2);
    
    strcpy(lower_str, my_string);
    strcpy(upper_str, my_string);
    for(int i = 0; lower_str[i] != '\0'; i++)
    {
        lower_str[i] = tolower((unsigned char)lower_str[i]);
        upper_str[i] = toupper((unsigned char)upper_str[i]);
    }
    printf("7. Исходная: \"%s\"\n", my_string);
    printf("   Нижний регистр: \"%s\"\n", lower_str);
    printf("   Верхний регистр: \"%s\"\n", upper_str);
    
    return 0;
}
```

#### Результаты работы программы
```
Введите строку (до 10 латинских символов): Hello123
1. Длина по индексам: 8
2. Длина по указателю: 8
3. Длина через strlen: 8
4. Исходная: "Hello123", Копия: "Hello123"
5. Конкатенация: "Hello" + "World" = "Hello World"
6. Сравнение "apple" и "banana": -1 (первая меньше)
   Сравнение "apple" и "apple": 0 (равны)
7. Исходная: "Hello123"
   Нижний регистр: "hello123"
   Верхний регистр: "HELLO123"
```

---

### Задача 2.2: Конвертация строк в числа (task_2_2.c)

#### Постановка задачи
Безопасно преобразовывать текст в int и double с проверкой ошибок через strtol и strtod.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| int_str | char[64] | строка с целым числом |
| float_str | char[64] | строка с вещественным числом |
| endptr | char* | указатель на остаток строки |
| int_val | long | преобразованное целое |
| float_val | double | преобразованное вещественное |
| errno | int | код ошибки |

#### Код программы
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<ctype.h>

int main()
{
    char int_str[64];
    char float_str[64];
    char* endptr;
    long int_val;
    double float_val;
    
    printf("Введите строку с целым числом: ");
    fgets(int_str, sizeof(int_str), stdin);
    int_str[strcspn(int_str, "\n")] = '\0';
    
    printf("Введите строку с вещественным числом: ");
    fgets(float_str, sizeof(float_str), stdin);
    float_str[strcspn(float_str, "\n")] = '\0';
    
    errno = 0;
    endptr = NULL;
    int_val = strtol(int_str, &endptr, 10);
    
    printf("\n--- Преобразование целого числа ---\n");
    printf("Исходная строка: \"%s\"\n", int_str);
    if(endptr == int_str)
    {
        printf("Ошибка: не найдено ни одного числового символа\n");
    }
    else if(errno == ERANGE)
    {
        printf("Ошибка: число вне допустимого диапазона\n");
    }
    else
    {
        printf("Результат: %ld\n", int_val);
        if(*endptr != '\0')
        {
            printf("Предупреждение: после числа остались символы: \"%s\"\n", endptr);
        }
        else
        {
            printf("Успешно: вся строка преобразована в число\n");
        }
    }
    
    errno = 0;
    endptr = NULL;
    float_val = strtod(float_str, &endptr);
    
    printf("\n--- Преобразование вещественного числа ---\n");
    printf("Исходная строка: \"%s\"\n", float_str);
    if(endptr == float_str)
    {
        printf("Ошибка: не найдено ни одного числового символа\n");
    }
    else if(errno == ERANGE)
    {
        printf("Ошибка: число вне допустимого диапазона\n");
    }
    else
    {
        printf("Результат: %f\n", float_val);
        if(*endptr != '\0')
        {
            printf("Предупреждение: после числа остались символы: \"%s\"\n", endptr);
        }
        else
        {
            printf("Успешно: вся строка преобразована в число\n");
        }
    }
    
    return 0;
}
```

#### Результаты работы программы
```
Введите строку с целым числом: -42
Введите строку с вещественным числом: 3.14

--- Преобразование целого числа ---
Исходная строка: "-42"
Результат: -42
Успешно: вся строка преобразована в число

--- Преобразование вещественного числа ---
Исходная строка: "3.14"
Результат: 3.140000
Успешно: вся строка преобразована в число
```

---

### Задача 2.3: Классификация символов (task_2_3.c)

#### Постановка задачи
Научиться классифицировать каждый символ строки с помощью функций из ctype.h (isdigit, isalpha, isspace, ispunct).

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| str | char[MAX_LEN] | входная строка |
| ch | unsigned char | текущий символ |
| isdigit | int(*) | проверка на цифру |
| isalpha | int(*) | проверка на букву |
| isupper | int(*) | проверка на заглавную букву |
| ispunct | int(*) | проверка на знак пунктуации |

#### Код программы
```c
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
```

#### Результаты работы программы
```
Введите строку (цифры, буквы, пробелы, знаки пунктуации): A7, B!

Классификация символов строки "A7, B!":
------------------------------------------------
Символ  Тип
------------------------------------------------
'A'     Буква (заглавная)
'7'     Цифра
','     Знак пунктуации
' '     Пробел
'B'     Буква (заглавная)
'!'     Знак пунктуации
```

---

## Выводы

В ходе выполнения лабораторной работы были изучены:

1. **Функции в языке C**:
   - Объявление и определение функций
   - Передача параметров по значению и через указатели
   - Рекурсивные функции и итеративные решения
   - Возврат значений из функций

2. **Динамическая память**:
   - Выделение памяти под одномерные и двумерные массивы
   - Освобождение памяти и предотвращение утечек
   - Обработка ошибок при выделении памяти

3. **Работа со строками**:
   - Подсчёт длины строки (ручной и через strlen)
   - Копирование, конкатенация и сравнение строк
   - Изменение регистра символов
   - Классификация символов через ctype.h

4. **Преобразование строк в числа**:
   - Использование strtol и strtod
   - Проверка ошибок через errno и endptr
   - Обработка некорректного ввода

5. **Математические вычисления**:
   - Векторные операции в 3D
   - Смешанное произведение векторов
   - Разбиение сложных задач на функции

Все программы успешно компилируются и выполняются, демонстрируя корректную работу с функциями, динамической памятью и строками в языке C.

---

## Информация о студенте
Гласнер Лев Сергеевич, 1 курс, группа ИВТ-25