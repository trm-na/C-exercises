#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float euler(float (*p_f)(float y, float t), float y, float t, float h);
float f(float y, float t);
float g(float y, float t);

int main()
{
    char cont, opt_buf[10], cont_buf[10], h_buf[10], y0_buf[10];
    float t_step, y, h;
    int opt;

    do
    {
        printf("Choose the differential equation to compute\n");
        printf("1.- dy/dt = cos(y) from t = 0 to t = PI\n");
        printf("2.- 1/sqrt(2*PI)*exp(-(t*t)/2) from t = 0 to t = 1\n");
        printf("Choose your option: ");
        gets(opt_buf);
        opt = atoi(opt_buf);

        switch (opt)
        {
        case 1:
            printf("Enter the number of steps: ");
            gets(h_buf);
            h = atof(h_buf);
            printf("Enter the initial value of y: ");
            gets(y0_buf);
            y = atof(y0_buf);
            t_step = M_PI / h;
            printf("\n\t\tt\t\ty");
            printf("\n\t===================================\n");
            for (float t = 0; t <= M_PI; t += t_step)
            {
                printf("\t%12.6lf\t%12.6lf\n", t, y);
                y = euler(f, y, t, t_step);
            }
            break;

        case 2:
            printf("Enter the number of steps: ");
            gets(h_buf);
            h = atof(h_buf);
            printf("Enter the initial value of y: ");
            gets(y0_buf);
            y = atof(y0_buf);
            t_step = 1.0 / h;
            printf("\n\t\tt\t\ty");
            printf("\n\t===================================\n");
            for (float t = 0; t <= 1; t += t_step)
            {
                printf("\t%12.6lf\t%12.6lf\n", t, y);
                y = euler(g, y, t, t_step);
            }
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

float f(float y, float t)
{
    return (cos(y));
}

float g(float y, float t)
{
    return (exp(-t * t / 2) / sqrt(2 * M_PI));
}

float euler(float (*p_f)(float y, float t), float y, float t, float h)
{
    return (y + h * (*p_f)(y, t));
}