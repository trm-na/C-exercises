#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARR_LEN 10

float num_proc(float num_arr[], int n, float* p_max, float* p_min, float *p_avg);

int main()
{
    char num_buf[10];
    float res, num_arr[ARR_LEN], max, min, avg;

    printf("Maximum, minimum and average value of the numbers of an array of %i elements.\n", ARR_LEN);

    for (int i = 0; i < ARR_LEN; i++)
    {
        switch (i+1)
        {
        case 1:
            printf("Enter the %ist number: ", i+1);
            gets(num_buf);
            num_arr[i] = atof(num_buf);
            break;

        case 2:
            printf("Enter the %ind number: ", i+1);
            gets(num_buf);
            num_arr[i] = atof(num_buf);
            break;

        case 3:
            printf("Enter the %ird number: ", i+1);
            gets(num_buf);
            num_arr[i] = atof(num_buf);
            break;

        default:
            printf("Enter the %ith number: ", i+1);
            gets(num_buf);
            num_arr[i] = atof(num_buf);
            break;
        }
    }

    num_proc(num_arr, ARR_LEN, &max, &min, &avg);

    printf("The maximum value of the array is %1.2f\n", max);
    printf("The minimum value of the array is %1.2f\n", min);
    printf("The average value of the array is %1.2f\n", avg);
}

float num_proc(float num_arr[], int n, float* p_max, float* p_min, float *p_avg)
{
    float max = num_arr[0], min = num_arr[0], avg = 0;
    for (int i = 0; i < n; i++)
    {
        if (num_arr[i] > max)
        {
            max = num_arr[i];
        }

        if (num_arr[i] < min)
        {
            min = num_arr[i];
        }
        
        avg += num_arr[i];
    }

    *p_max = max;
    *p_min = min;
    *p_avg = avg/n;
}