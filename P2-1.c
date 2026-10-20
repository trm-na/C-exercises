#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fact(int n);

int main()
{
    char n_buf[10];
    int n;
    float f;

    printf("Computation of the factorial of an integer number.\n");
    printf("Enter the number: ");
    gets(n_buf);
    n = atoi(n_buf);
    f = fact(n);
    printf("The factorial of %i is %1.0f\n", n, f);
    if (n > 5)
    {
        float stir = sqrt(2 * M_PI * n) * exp(-n) * pow(n, n);
        printf("The Stirling approximation is %1.2f\n", stir);
        float abs_err = stir - f;
        if (abs_err < 0)
        {
            abs_err = -abs_err;
        }
        float rel_err = abs_err / f;
        float per_err = 100 * rel_err;
        printf("The approximation's absolute error is %1.2f\n", abs_err);
        printf("The approximation's relative error is %1.2f (%3.2f%)\n", rel_err, per_err);
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