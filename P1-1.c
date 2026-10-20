#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char x_buf[10], y_buf[10], a_buf[10], b_buf[10], c_buf[10];
    int x, y , a, b, c;
    float dist;

    printf("Distance between a point (x, y) in the plane and the line whose equation is ax + by = c\n");
    printf("Enter x value (int): ");
    gets(x_buf);
    x = atoi(x_buf);
    printf("Enter y value (int): ");
    gets(y_buf);
    y = atoi(y_buf);
    printf("Enter a value (int): ");
    gets(a_buf);
    a = atoi(a_buf);
    printf("Enter b value (int): ");
    gets(b_buf);
    b = atoi(b_buf);
    printf("Enter c value (int): ");
    gets(c_buf);
    c = atoi(c_buf);

    dist = abs(a*x + b*y - c)/sqrt(pow(a,2)+pow(b,2));

    printf("The distance between the point (%i, %i) and the line %ix + %iy = %i is %f", x, y, a, b, c, dist);

}