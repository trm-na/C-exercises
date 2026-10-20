#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float cramer(float a[3][3], float b[3], float res[3]);
float det(float x[3][3]);

int main()
{
    float a[3][3], b[3], res[3];
    printf("Resolution of a 3x3 system of equations by Cramer's rule\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Enter the coefficient number %i of equation number %i: ", j, i + 1);
            if (j == 3)
            {
                scanf("%f", &b[i]);
            }
            else
            {
                scanf("%f", &a[i][j]);
            }
        }
    }
    cramer(a, b, res);
    printf("The solution of the system of equations is: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("x%i = %4.2f\n", i, res[i]);
    }
}

float cramer(float a[3][3], float b[3], float res[3])
{
    float det_a, x[3][3];
    det_a = det(a);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (k == i)
                {
                    x[j][k] = b[j];
                } else
                {
                    x[j][k] = a[j][k];
                }
                
            } 
        }
        res[i] = det(x)/det_a;
    }
    
}

float det(float x[3][3])
{
    return (x[0][0] * (x[1][1] * x[2][2] - x[2][1] * x[1][2]) - x[0][1] * (x[1][0] * x[2][2] - x[1][2] * x[2][0]) + x[0][2] * (x[1][0] * x[2][1] - x[2][0] * x[1][1]));
}