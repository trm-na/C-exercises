#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gauss_seidel(float a[][3], float b[], float res[], int max_it);

int main()
{
    float a[3][3], res[3], b[3];
    int max_it;

    printf("Computation of linear equation Ax = b by Gauss-Seidel's method\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter the coefficient A%i%i: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the coefficient b%i: ", i);
        scanf("%f", &b[i]);
    }
    printf("Enter the number of iterations: ");
    scanf("%i", &max_it);
    gauss_seidel(a,b,res,max_it);
    printf("The solution to the linear equation Ax = b is: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("x%i = %4.2f\n", i, res[i]);
    }
}

void gauss_seidel(float a[][3], float b[], float res[], int max_it)
{
    int i, it, j;
    float sol;
    for (i = 0; i < 3; i++)
    {
        res[i] = b[i]/a[i][i];
    }
    for (it = 0; it < max_it; it++)
    {
        for (i = 0; i < 3; i++)
        {
            sol = b[i];
            for (j = 0; j < i; j++)
            {
                sol -= a[i][j]*res[j];
            }
            for (j = i+1; j < 3; j++)
            {
                sol -= a[i][j]*res[j];
            }
            res[i] = sol/a[i][i];
        }
    }
}