#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char a_buf[10], b_buf[10], c_buf[10], d_buf[10], x_buf[10], cont_buf[10];
    int x, a, b, c, d;
    float res;
    char cont, cont_val;

    printf("Evaluation of the polynomial ax^3 + bx^2 + cx + d\n");
    printf("Enter a value (int): ");
    gets(a_buf);
    a = atoi(a_buf);
    printf("Enter b value (int): ");
    gets(b_buf);
    b = atoi(b_buf);
    printf("Enter c value (int): ");
    gets(c_buf);
    c = atoi(c_buf);
    printf("Enter d value (int): ");
    gets(d_buf);
    d = atoi(d_buf);

    printf("The evaluated polynomial will be %ix^3 + %ix^2 + %ix + %i\n", a, b, c, d);

    do
    {
        printf("Enter x value (int): ");
        gets(x_buf);
        x = atoi(x_buf);
        res = d + x * (c + x * (b + a * x));
        printf("The value of the polynomial is %f", res);
        printf("\nWould you like to continue? (y/n): ");
        gets(cont_buf);
        cont_val = sscanf(cont_buf, "%c", &cont);
        while (cont_val != 1 || ((cont != 'y') && (cont != 'n')))
        {
            printf("Please enter a valid character.");
            printf("\nWould you like to continue? (y/n): ");
            gets(cont_buf);
            cont_val = sscanf(cont_buf, "%c", &cont);
        }

    } while (cont == 'y');
}