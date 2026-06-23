#include<stdio.h>
#include<math.h>

float w(float T)
{
    return 2 * M_PI / T;
}

int main()
{
    int r_mars = 227900000;
    int r_earth = 149600000;
    float T_mars = 1.881;
    float T_earth = 1.000;
    for(int t = 0; t < 365; t++)
    {
        int x = r_mars*cos(w(T_mars)*t) - r_earth*(cos(w(T_earth) * t));
        int y = r_mars*sin(w(T_mars)*t) - r_earth*(sin(w(T_earth) * t));
        printf("t = %d, x = %d, y = %d\n", t, x, y);
    }
}