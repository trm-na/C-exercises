#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char x_buf[10];
    float x;
    float res_app, res_fun, abs_err, rel_err, per_err;

    printf("Comparison between an approximation and the C exp funtion\n");
    printf("Enter x value: ");
    gets(x_buf);
    x = atoi(x_buf);

    res_app = 1.0 + x * (1.0 + x * (1.0/2.0 + x * (1.0/6.0 + x * (1.0/24.0 + x * 1.0/120.0))));
    res_fun = exp(x);
    abs_err = res_app - res_fun;
    if (abs_err < 0)
    {
        abs_err = - abs_err;
    }
    rel_err = abs_err/res_fun;
    per_err = 100 * rel_err;

    printf("Function's output is %f\n", res_fun);
    printf("Approximation's output is %f\n", res_app);
    printf("The approximation's absolute error is %f\n", abs_err);
    printf("The approximation's relative error is %f (%3.2f%)\n", rel_err, per_err);

}