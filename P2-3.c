#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pow_ser(float x, float prec);
float fact(int n);

int main()
{
    char x_buf[10], prec_buf[10];
    float x, prec, res;

    printf("Power series evaluation.\n");
    printf("Enter the number to evaluate: ");
    gets(x_buf);
    x = atof(x_buf);
    printf("Enter the precision of the last value of the series: ");
    gets(prec_buf);
    prec = atof(prec_buf);

    res = pow_ser(x, prec);
    printf("The result of the power series for %1.2f with a precision of %1.2f is %1.2f", x, prec, res);

}

float pow_ser(float x, float prec){
    float num, res, tot_res = 1;
    int f, n = 1;
    do
    {
        f = fact(n);
        num = pow(x, n);
        res = num/f;
        tot_res += res;
        n++;
    } while (fabs(res) > prec);
    return tot_res;
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