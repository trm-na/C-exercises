#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float binomial_coeff(int n, int r);
float fact(int n);

int main()
{
    char n_buf[10], r_buf[10];
    int n, r;
    float bc;

    printf("Computation of the binomial coefficients (n!/(r!*(n-r)!)) of two integer numbers n and r.\n");
    printf("Enter n value (int): ");
    gets(n_buf);
    n = atoi(n_buf);
    printf("Enter r value (int): ");
    gets(r_buf);
    r = atoi(r_buf);
    bc = binomial_coeff(n, r);
    printf("The binomial coefficients (%i!/(%i!*(%i-%i)!)) are %1.0f\n", n, r, n, r, bc);
}

float binomial_coeff(int n, int r)
{
    float num, denom;
    num = fact(n);
    denom = fact(r) * fact(n - r);
    if (denom != 0)
    {
        return num / denom;
    }
    else
    {
        return 0;
    }
}

float fact(int n)
{
    float res = 1;
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }
    else
    {
        for (n; n > 0; n--)
        {
            res *= n;
        }
        return res;
    }
}