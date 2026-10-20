#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define printfc(c) printf("%2.2f%c%2.2fi",creal(c),(cimag(c)>=0.0f)? '+':'\0',cimag(c))

float quad(float a, float b, float c, float complex* x1, float complex* x2);

int main()
{
    char a_buf[10], b_buf[10], c_buf[10];
    float a, b, c;
    float complex x1, x2;

    printf("Solution of the quadratic equation ax^2 + bx + c = 0\n");
    printf("Enter a's value: ");
    gets(a_buf);
    a = atof(a_buf);
    printf("Enter b's value: ");
    gets(b_buf);
    b = atof(b_buf);
    printf("Enter c's value: ");
    gets(c_buf);
    c = atof(c_buf);

    quad(a,b,c, &x1, &x2);

    printf("The solutions to the quadratic equation %2.2fx^2 + %2.2fx + %2.2f = 0 are ", a, b, c);
    printfc(x1);
    printf(" and ");
    printfc(x2);
}

float quad(float a, float b, float c, float complex* x1, float complex* x2){
    *x1 = (-b + csqrt(b*b - 4*a*c))/(2*a);
    *x2 = (-b - csqrt(b*b - 4*a*c))/(2*a);  
}