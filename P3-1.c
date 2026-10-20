#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dot_product(float x[], float y[], int n);

int main()
{
    char n_val, x_buf[10], y_buf[10], n_buf[10];
    float res, x[10], y[10];
    int n;

    printf("Dot product of vectors x and y of size n (<= 10)\n");
    printf("Enter the number of elements of the vector (<= 10): ");
    gets(n_buf);
    n_val = sscanf(n_buf, "%i", &n);
    while (n_val != 1 || n > 10)
    {
        printf("Please enter a valid character.");
        printf("\nEnter the number of elements of the vector (<= 10): ");
        gets(n_buf);
        n_val = sscanf(n_buf, "%i", &n);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of x[%i]: ", i);
        gets(x_buf);
        x[i] = atof(x_buf);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of y[%i]: ", i);
        gets(y_buf);
        y[i] = atof(y_buf);
    }
    res = dot_product(x, y, n);
    printf("The dot product between vectors x and y is %4.2f", res);
}

float dot_product(float x[], float y[], int n)
{
    float res = 0;
    for (int i = 0; i < n; i++)
    {
        res += x[i] * y[i];
    }
    return res;
}