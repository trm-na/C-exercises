#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float integral(float (*p_f)(float x), float x0, float xn, int n);
float f(float x);
float g(float x);

int main()
{
    char cont, opt_buf[10], cont_buf[10], n_buf[10], x1_buf[10];
    float x1;
    int opt, n;

    do
    {
        printf("Choose the integral to compute\n");
        printf("1.- x*x\n");
        printf("2.- exp(-(x*x)/2)\n");
        printf("Choose your option: ");
        gets(opt_buf);
        opt = atoi(opt_buf);

        switch (opt)
        {
        case 1:
            printf("Enter the number of strips: ");
            gets(n_buf);
            n = atoi(n_buf);
            printf("The integral of x*x between 0 and 1 with %i strips is ", n);
            integral(f, 0, 1, n);
            break;

        case 2:
            printf("Enter the number of strips: ");
            gets(n_buf);
            n = atoi(n_buf);
            printf("Enter the upper limit: ");
            gets(x1_buf);
            x1 = atof(x1_buf);
            printf("The integral of exp(-(x*x)/2) between 0 and %1.2f with %i strips is ", x1, n);
            integral(g, 0, x1, n);
            break;

        default:
            break;
        }

        printf("\nWould you like to continue? (y/n): ");
        gets(cont_buf);
        char cont_val = sscanf(cont_buf, "%c", &cont);
        while (cont_val != 1 || ((cont != 'y') && (cont != 'n')))
        {
            printf("Please enter a valid character.");
            printf("\nWould you like to continue? (y/n): ");
            gets(cont_buf);
            cont_val = sscanf(cont_buf, "%c", &cont);
        }

    } while (cont == 'y');
}

float f(float x)
{
    return x * x;
}

float g(float x)
{
    return (exp(-x*x/ 2));
}

float integral(float (*p_f)(float x), float x0, float xn, int n)
{
    float res;
    float h = (xn - x0)/n;
    res = ((*p_f)(x0))/2 + ((*p_f)(xn))/2;
    for (int i = 1; i < n; i++)
    {
        res += (*p_f)(x0+i*h);
    }
    
    printf("%1.2f\n", res*h);
}