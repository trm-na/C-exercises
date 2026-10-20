#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float height(float t);

int main()
{
    float h, t = 0;
    int impact = 0;

    printf("Prediction of the performance of a retrorocket\n");
    printf("Time (in seconds)\t\tHeight (in metres)\n");
    printf("*************************************************\n");

    do
    {
        h = height(t);
        printf("%5.4f\t\t\t%8.4f\n", t, h);
        if (h <= 0)
        {
            impact = 1;
        } else if (h < 50)
        {
            t  += 0.05;
        } else
        {
            t += 2;
        }
        
    } while (impact!=1 && t <= 100);
    
}

float height(float t){
    return 60 + 2.13 * t * t - 0.0013 * t * t * t * t + 0.000034 * pow(t, 4.751);
}