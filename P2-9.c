#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define cmplxf(x, y) ((float complex)((float)(x) + I * (float)(y)))
#define printfc(c) printf("%f%c%fi",creal(c),(cimag(c)>=0.0f)? '+':'\0',cimag(c))

void dft(float complex x[], float complex *y, int N, int n);
void idft(float complex y[], float complex *x, int N, int k);

int main()
{
    char n_val, cont, opt_buf[10], cont_buf[10], real_buf[10], imag_buf[10], n_buf[10];
    float complex x[100];
    float complex y[100];
    float complex z[100];
    int opt, n;
    float real, imag;

    do
    {
        printf("Choose the transform to compute\n");
        printf("1.- DFT\n");
        printf("2.- IDFT\n");
        printf("3.- Check DFT-IDFT on the same sequence\n");
        printf("Choose your option: ");
        gets(opt_buf);
        opt = atoi(opt_buf);

        switch (opt)
        {
        case 1:
            printf("Enter how many complex numbers will the sequence include (<= 100): ");
            gets(n_buf);
            n_val = sscanf(n_buf, "%i", &n);
            while (n_val != 1 || n > 100)
            {
                printf("Please enter a valid character.");
                printf("\nEnter how many numbers to generate (<= 100): ");
                gets(n_buf);
                n_val = sscanf(n_buf, "%i", &n);
            }
            for (int i = 0; i < n; i++)
            {
                printf("Enter the real part of x%i: ", i);
                gets(real_buf);
                real = atof(real_buf);
                printf("Enter the imaginary part of x%i: ", i);
                gets(imag_buf);
                imag = atof(imag_buf);
                x[i] = cmplxf(real, imag);
            }

            printf(" i\t\txi\t\t\tyi");

            for (int i = 0; i < n; i++)
            {
                dft(x, &y[i], n, i);
            }

            for (int i = 0; i < n; i++)
            {
                printf("\n%i\t", i);
                printfc(x[i]);
                printf("\t");
                printfc(y[i]);
                printf("\t");
                printfc(z[i]);
            }
            break;

        case 2:
            printf("Enter how many complex numbers will the sequence include (<= 100): ");
            gets(n_buf);
            n_val = sscanf(n_buf, "%i", &n);
            while (n_val != 1 || n > 100)
            {
                printf("Please enter a valid character.");
                printf("\nEnter how many numbers to generate (<= 100): ");
                gets(n_buf);
                n_val = sscanf(n_buf, "%i", &n);
            }
            for (int i = 0; i < n; i++)
            {
                printf("Enter the real part of y%i: ", i);
                gets(real_buf);
                real = atof(real_buf);
                printf("Enter the imaginary part of y%i: ", i);
                gets(imag_buf);
                imag = atof(imag_buf);
                y[i] = cmplxf(real, imag);
            }

            printf(" i\t\tyi\t\t\txi");

            for (int i = 0; i < n; i++)
            {
                idft(y, &x[i], n, i);
            }

            for (int i = 0; i < n; i++)
            {
                printf("\n%i\t", i);
                printfc(y[i]);
                printf("\t");
                printfc(x[i]);
            }
            break;

        case 3:
            printf("Enter how many complex numbers will the sequence include (<= 100): ");
            gets(n_buf);
            n_val = sscanf(n_buf, "%i", &n);
            while (n_val != 1 || n > 100)
            {
                printf("Please enter a valid character.");
                printf("\nEnter how many numbers to generate (<= 100): ");
                gets(n_buf);
                n_val = sscanf(n_buf, "%i", &n);
            }
            for (int i = 0; i < n; i++)
            {
                printf("Enter the real part of x%i: ", i);
                gets(real_buf);
                real = atof(real_buf);
                printf("Enter the imaginary part of x%i: ", i);
                gets(imag_buf);
                imag = atof(imag_buf);
                x[i] = cmplxf(real, imag);
            }

            for (int i = 0; i < n; i++)
            {
                dft(x, &y[i], n, i);
            }

            printf("z will be the recovered x sequence after applying the dft and the idft.\n");
            printf(" i\t\txi\t\t\tyi\t\t\tzi");

            for (int i = 0; i < n; i++)
            {
                idft(y, &z[i], n, i);
            }

            for (int i = 0; i < n; i++)
            {
                printf("\n%i\t", i);
                printfc(x[i]);
                printf("\t");
                printfc(y[i]);
                printf("\t");
                printfc(z[i]);
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

void dft(float complex x[], float complex *y, int N, int n)
{
    float complex e;
    float complex res = 0;
    for (int k = 0; k < N; k++)
    {
        e = cmplxf(cos(2 * M_PI * k * n / N), -sin(2 * M_PI * k * n / N));
        res += x[k] * e;
    }
    *y = res / N;
}

void idft(float complex y[], float complex *x, int N, int k)
{
    float complex e;
    float complex res = 0;
    for (int n = 0; n < N; n++)
    {
        e = cmplxf(cos(2 * M_PI * k * n / N), sin(2 * M_PI * k * n / N));
        res += y[n] * e;
    }
    *x = res;
}