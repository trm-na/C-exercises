#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void random(float x[], int n, float seed);

int main()
{
    char seed_buf[10], n_buf[10];
    float seed, x[100];
    int n;
    printf("Random number generator.\n");
    printf("Enter the seed: ");
    gets(seed_buf);
    seed = atof(seed_buf);
    printf("Enter how many numbers to generate (<= 100): ");
    gets(n_buf);
    char n_val = sscanf(n_buf, "%i", &n);
    while (n_val != 1 || n > 100)
    {
        printf("Please enter a valid character.");
        printf("\nEnter how many numbers to generate (<= 100): ");
        gets(n_buf);
        n_val = sscanf(n_buf, "%i", &n);
    }
    random(x, n, seed);
    for (int i = 0; i < n; i++)
    {
        printf("%f\n", x[i]);
    }
}

void random(float x[], int n, float seed)
{
    int r = 16807;
    int p = 2147483647;
    x[0] = seed;
    float max = seed;
    for (int i = 1; i < n; i++)
    {
        x[i] = fmod((r * x[i - 1]), p);
        if (x[i] > max)
        {
            max = x[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        x[i] = x[i] / max;
    }
}