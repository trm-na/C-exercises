#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float norm1(float x[], int n);
float norm2(float x[], int n);
float norminf(float x[], int n);

int main()
{
    char cont, n_val, x_buf[10], n_buf[10], cont_buf[10], opt_buf[10];
    float res, x[10];
    int opt, n;

    printf("Computation of the norms of vector x of size n (<= 10)\n");
    printf("Enter the number of elements of the vector (<= 10): ");
    gets(n_buf);
    n_val = sscanf(n_buf, "%i", &n);
    while (n_val != 1 || n > 10)
    {
        printf("Please enter a valid character.");
        printf("\nEnter the number of elements of the vector (<= 10): ");
        gets(n_buf);
        n_val = sscanf(n_buf, "%i", &n);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of x[%i]: ", i);
        gets(x_buf);
        x[i] = atof(x_buf);
    }
    do
    {
        printf("Choose the norm to compute\n");
        printf("1.- l1 norm\n");
        printf("2.- l2 norm (Euclidean norm)\n");
        printf("3.- linf norm (uniform norm)\n");
        printf("Choose your option: ");
        gets(opt_buf);
        opt = atoi(opt_buf);

        switch (opt)
        {
        case 1:
            res = norm1(x, n);
            printf("The l1 norm of vector x is %4.2f", res);
            break;

        case 2:
            res = norm2(x, n);
            printf("The l2 norm of vector x is %4.2f", res);
            break;

        case 3:
            res = norminf(x, n);
            printf("The linf norm of vector x is %4.2f", res);
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

float norm1(float x[], int n)
{
    float res = 0;
    for (int i = 0; i < n; i++)
    {
        res += fabs(x[i]);
    }
    return res;
}

float norm2(float x[], int n)
{
    float res = 0;
    for (int i = 0; i < n; i++)
    {
        res += fabs(x[i]) * fabs(x[i]);
    }
    return sqrtf(res);
}

float norminf(float x[], int n)
{
    float res = fabs(x[0]);
    for (int i = 1; i < n; i++)
    {
        if (fabs(x[i]) > res)
        {
            res = fabs(x[i]);
        }
    }
    return res;
}
