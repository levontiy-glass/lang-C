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