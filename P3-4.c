#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float mat_prod(float x[][10], float y[][10], float res[][10], int n);

int main()
{
    char n_val, x_buf[10], y_buf[10], n_buf[10];
    float res[10][10], x[10][10], y[10][10];
    int n;

    printf("Product of matrices x and y of order nxn (n <= 10)\n");
    printf("Enter the number of rows and columns of the matrices (<= 10): ");
    gets(n_buf);
    n_val = sscanf(n_buf, "%i", &n);
    while (n_val != 1 || n > 10)
    {
        printf("Please enter a valid character.");
        printf("\nEnter the number of rows and columns of the matrices (<= 10): ");
        gets(n_buf);
        n_val = sscanf(n_buf, "%i", &n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the value of x[%i][%i]: ", i, j);
            gets(x_buf);
            x[i][j] = atof(x_buf);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the value of y[%i][%i]: ", i, j);
            gets(y_buf);
            y[i][j] = atof(y_buf);
        }
    }
    mat_prod(x, y, res, n);
    printf("The result of the product of matrices x and y is:");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%4.2f  ", res[i][j]);
        }   
    }
}

float mat_prod(float x[][10], float y[][10], float res[][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                res[i][j] += x[i][k] * y[k][j];
            }
        }   
    }
}