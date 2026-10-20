#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x[11], y[11], n;
    int i;

    printf("Standard Gaussian density function\n");
    printf("**********************************\n");
    printf("value of x              value of y\n");
    for (i = 0; i <= 10; i++)
    {
        x[i] = n;
        y[i] = 1.0/(2.0*M_PI)*exp(x[i]*(x[i]/2.0));
        printf("   %1.1f                    %1.3f\n", x[i], y[i]);
        n += 0.1;
    }
    
}