#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float smooth(float x[], float res[], int n);

int main()
{
    char n_val, x_buf[10], n_buf[10];
    float res[10], x[10];
    int n;

    printf("Smoothing of data from vector x of size n (<= 10)\n");
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
    smooth(x, res, n);
    printf("The smoothed data is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%4.2f\n", res[i]);
    }
}

float smooth(float x[], float res[], int n)
{
    float f[12];
    f[0] = 0;
    f[n+1] = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        res[i-1] = (f[i-1]+f[i]+f[i+1])/3;
    }
}