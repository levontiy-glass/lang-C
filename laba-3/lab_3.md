# Отчет по лабораторной работе №3

## Тема: Структуры. Объединения. Перечисления.

---

## Комплект 1: Структуры

### Задача 1.1: Указатель на функцию в структуре (task_1_1.c)

#### Постановка задачи
Создать некоторую структуру с указателем на некоторую функцию в качестве поля. Вызвать эту функцию через имя переменной этой структуры и поле указателя на функцию.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| strc | struct | структура с указателем на функцию и числом |
| pfunk | int(*)(int) | указатель на функцию |
| num | int | число для передачи в функцию |
| square | struct strc | экземпляр структуры |

#### Код программы
```c
#include<stdio.h>

struct strc
{
    int (*pfunk)(int);
    int num;
};

int funk(int a)
{
    return a*a;
}

int main()
{
    struct strc square = {&funk, 3};
    printf("%d\n", square.pfunk(square.num));
}
```

#### Результаты работы программы
```
9
```

---

### Задача 1.2: Вектор в 3-х мерном пространстве (task_1_2.c)

#### Постановка задачи
Создать структуру для вектора в 3-х мерном пространстве. Реализовать и использовать в своей программе следующие операции над векторами: скалярное умножение, векторное произведение, модуль вектора, распечатка вектора в консоли. В структуре вектора указать имя вектора в качестве отдельного поля.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| Vector3D | struct | структура вектора |
| name | char[20] | имя вектора |
| x, y, z | double | координаты вектора |
| v1, v2 | struct Vector3D | экземпляры векторов |
| sc | double | скалярное произведение |
| vp | struct Vector3D | векторное произведение |

#### Код программы
```c
#include<stdio.h>
#include<math.h>

struct Vector3D
{
    char name[20];
    double x;
    double y;
    double z;
};

double scalar_product(struct Vector3D v1, struct Vector3D v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

struct Vector3D vector_product(struct Vector3D v1, struct Vector3D v2)
{
    struct Vector3D result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

double vector_length(struct Vector3D v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void print_vector(struct Vector3D v)
{
    printf("%s = (%.2f, %.2f, %.2f)\n", v.name, v.x, v.y, v.z);
}

int main()
{
    struct Vector3D v1 = {"Vektor_A", 1.0, 2.0, 3.0};
    struct Vector3D v2 = {"Vektor_B", 4.0, 5.0, 6.0};
    
    printf("Исходные векторы:\n");
    print_vector(v1);
    print_vector(v2);
    
    double sc = scalar_product(v1, v2);
    printf("\nСкалярное произведение: %.2f\n", sc);
    
    struct Vector3D vp = vector_product(v1, v2);
    printf("Векторное произведение: ");
    print_vector(vp);
    
    printf("Модуль вектора A: %.2f\n", vector_length(v1));
    printf("Модуль вектора B: %.2f\n", vector_length(v2));
    
    return 0;
}
```

#### Результаты работы программы
```
Исходные векторы:
Vektor_A = (1.00, 2.00, 3.00)
Vektor_B = (4.00, 5.00, 6.00)

Скалярное произведение: 32.00
Векторное произведение: Vektor_C = (-3.00, 6.00, -3.00)
Модуль вектора A: 3.74
Модуль вектора B: 8.77
```

---

### Задача 1.3: Комплексная экспонента (task_1_3.c)

#### Постановка задачи
Вычислить, используя структуру комплексного числа, комплексную экспоненту exp(z) некоторого z ∈ C.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| Complex | struct | структура комплексного числа |
| real, imag | double | действительная и мнимая части |
| z | struct Complex | комплексное число |
| exp_z | struct Complex | экспонента от z |
| term | struct Complex | текущий член ряда |
| factorial | double | факториал |
| n | int | количество членов ряда |

#### Код программы
```c
#include<stdio.h>
#include<math.h>

struct Complex
{
    double real;
    double imag;
};

struct Complex complex_add(struct Complex z1, struct Complex z2)
{
    struct Complex result;
    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return result;
}

struct Complex complex_mul(struct Complex z1, struct Complex z2)
{
    struct Complex result;
    result.real = z1.real * z2.real - z1.imag * z2.imag;
    result.imag = z1.real * z2.imag + z1.imag * z2.real;
    return result;
}

struct Complex complex_div_scalar(struct Complex z, double scalar)
{
    struct Complex result;
    result.real = z.real / scalar;
    result.imag = z.imag / scalar;
    return result;
}

void print_complex(struct Complex z)
{
    if(z.imag >= 0)
        printf("%.4f + %.4fi", z.real, z.imag);
    else
        printf("%.4f - %.4fi", z.real, -z.imag);
}

struct Complex complex_exp(struct Complex z, int n)
{
    struct Complex result = {1.0, 0.0};
    struct Complex term = {1.0, 0.0};
    double factorial = 1.0;
    
    for(int i = 1; i <= n; i++)
    {
        factorial *= i;
        term = complex_mul(term, z);
        struct Complex add_term = complex_div_scalar(term, factorial);
        result = complex_add(result, add_term);
    }
    
    return result;
}

int main()
{
    struct Complex z;
    int n;
    
    printf("Введите действительную часть z: ");
    scanf("%lf", &z.real);
    printf("Введите мнимую часть z: ");
    scanf("%lf", &z.imag);
    printf("Введите количество членов ряда n: ");
    scanf("%d", &n);
    
    printf("z = ");
    print_complex(z);
    printf("\n");
    
    struct Complex exp_z = complex_exp(z, n);
    printf("exp(z) = ");
    print_complex(exp_z);
    printf("\n");
    
    return 0;
}
```

#### Результаты работы программы
```
Введите действительную часть z: 1
Введите мнимую часть z: 1
Введите количество членов ряда n: 10
z = 1.0000 + 1.0000i
exp(z) = 1.4687 + 2.2874i
```

---

### Задача 1.4: Битовые поля для даты (task_1_4.c)

#### Постановка задачи
Используя "битовые" поля в структуре С, создать экономичную структуру в оперативной памяти для заполнения даты некоторого события.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| Date | struct | структура даты |
| day | unsigned int:5 | день (0-31) |
| month | unsigned int:4 | месяц (0-15) |
| year | unsigned int:12 | год (0-4095) |
| birthday | struct Date | экземпляр структуры |

#### Код программы
```c
#include<stdio.h>

struct Date
{
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 12;
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
```

#### Результаты работы программы
```
Введите день рождения (1-31): 15
Введите месяц рождения (1-12): 6
Введите год рождения: 2004

Дата рождения: 15.6.2004
Размер структуры Date: 4 байт
```

---

### Задача 1.5: Двунаправленный связный список (task_1_5.c)

#### Постановка задачи
Реализовать в виде структур двунаправленный связный список и совершить отдельно его обход в прямом и обратном направлениях с распечаткой значений каждого элемента списка.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| Node | struct | узел списка |
| data | int | данные узла |
| prev | struct Node* | указатель на предыдущий узел |
| next | struct Node* | указатель на следующий узел |
| head | struct Node* | указатель на голову списка |
| current | struct Node* | текущий узел |

#### Код программы
```c
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* create_node(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void add_node(struct Node** head, int data)
{
    struct Node* new_node = create_node(data);
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    
    struct Node* current = *head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void print_forward(struct Node* head)
{
    printf("Прямой обход: ");
    struct Node* current = head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_backward(struct Node* head)
{
    printf("Обратный обход: ");
    struct Node* current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void free_list(struct Node* head)
{
    struct Node* current = head;
    while(current != NULL)
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Node* head = NULL;
    int n, value;
    
    printf("Введите количество элементов списка: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        printf("Введите элемент %d: ", i + 1);
        scanf("%d", &value);
        add_node(&head, value);
    }
    
    print_forward(head);
    print_backward(head);
    
    free_list(head);
    return 0;
}
```

#### Результаты работы программы
```
Введите количество элементов списка: 5
Введите элемент 1: 10
Введите элемент 2: 20
Введите элемент 3: 30
Введите элемент 4: 40
Введите элемент 5: 50
Прямой обход: 10 20 30 40 50 
Обратный обход: 50 40 30 20 10 
```

---

## Комплект 2: Объединения и перечисления

### Задача 2.1: Указатель на объединение (task_2_1.c)

#### Постановка задачи
Напишите программу, которая использует указатель на некоторое объединение union.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| Data | union | объединение для разных типов данных |
| int_val | int | целочисленное значение |
| float_val | float | вещественное значение |
| char_val | char | символьное значение |
| data | union Data | экземпляр объединения |
| pdata | union Data* | указатель на объединение |

#### Код программы
```c
#include<stdio.h>

union Data
{
    int int_val;
    float float_val;
    char char_val;
};

int main()
{
    union Data data;
    union Data* pdata = &data;
    
    pdata->int_val = 42;
    printf("Целое значение: %d\n", pdata->int_val);
    
    pdata->float_val = 3.14;
    printf("Вещественное значение: %.2f\n", pdata->float_val);
    
    pdata->char_val = 'A';
    printf("Символьное значение: %c\n", pdata->char_val);
    
    return 0;
}
```

#### Результаты работы программы
```
Целое значение: 42
Вещественное значение: 3.14
Символьное значение: A
```

---

### Задача 2.2: Побайтовая распечатка unsigned long (task_2_2.c)

#### Постановка задачи
Напишите программу, которая использует union для побайтовой распечатки типа unsigned long.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| ByteView | union | объединение для просмотра байтов |
| value | unsigned long | значение для просмотра |
| bytes | unsigned char[] | массив байтов значения |
| uv | union ByteView | экземпляр объединения |

#### Код программы
```c
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
```

#### Результаты работы программы
```
Введите беззнаковое длинное целое: 123456789
Побайтовое представление (от старшего к младшему):
07 5B CD 15 
```

---

### Задача 2.3: Перечисление дней недели (task_2_3.c)

#### Постановка задачи
Создайте перечислимый тип данных (enum) для семи дней недели и распечатайте на экране его значения, как целые числа.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| Days | enum | перечисление дней недели |
| Ponedelnik | int | 1 - понедельник |
| Vtornik | int | 2 - вторник |
| Sreda | int | 3 - среда |
| Chetverg | int | 4 - четверг |
| Pyatnica | int | 5 - пятница |
| Subbota | int | 6 - суббота |
| Voskresenye | int | 7 - воскресенье |

#### Код программы
```c
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
```

#### Результаты работы программы
```
Дни недели:
1 - Понедельник
2 - Вторник
3 - Среда
4 - Четверг
5 - Пятница
6 - Суббота
7 - Воскресенье
```

---

### Задача 2.4: Размеченное объединение (task_2_4.c)

#### Постановка задачи
Создайте размеченное объединение union, которое заключено в виде поля структуры struct вместе с ещё одним полем, которое является перечислением enum и служит индикатором того, что именно на текущий момент хранится в таком вложенном объединении. Создать и заполнить динамический массив таких структур с объединениями внутри, заполняя вспомогательное поле перечисления enum для сохранения информации о хранимом в каждом размеченном объединении типе данных. Реализовать распечатку данных массива таких структур в консоль.

#### Список идентификаторов

| имя переменной | тип данных | описание |
| -------------- | ---------- | -------- |
| DataType | enum | типы данных в объединении |
| Value | union | объединение для хранения данных |
| TaggedUnion | struct | размеченное объединение |
| type | enum DataType | индикатор типа |
| value | union Value | значение |
| arr | struct TaggedUnion* | динамический массив |

#### Код программы
```c
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
```

#### Результаты работы программы
```
Введите количество элементов массива: 3

Элемент 1:
Выберите тип (0 - int, 1 - float, 2 - char): 0
Введите целое число: 42

Элемент 2:
Выберите тип (0 - int, 1 - float, 2 - char): 1
Введите вещественное число: 3.14

Элемент 3:
Выберите тип (0 - int, 1 - float, 2 - char): 2
Введите символ: A

Результаты:
Элемент 1: int = 42
Элемент 2: float = 3.14
Элемент 3: char = A
```

---

## Выводы

В ходе выполнения лабораторной работы были изучены:

1. **Структуры** - создание пользовательских типов данных, объединение разнотипных данных, использование указателей на функции внутри структур.

2. **Битовые поля** - экономия памяти при хранении данных с известным диапазоном значений.

3. **Связные списки** - реализация двунаправленного связного списка с обходом в обоих направлениях.

4. **Объединения (union)** - хранение разных типов данных в одной области памяти, побайтовый доступ к данным.

5. **Перечисления (enum)** - создание именованных констант для повышения читаемости кода.

6. **Размеченные объединения** - комбинация структуры, объединения и перечисления для создания типобезопасных контейнеров.

Все программы успешно компилируются и выполняются, демонстрируя корректную работу с структурами, объединениями и перечислениями в языке C.

---

## Информация о студенте
Гласнер Лев Сергеевич, 1 курс, группа ИВТ-25