#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARR_LEN 10

float num_sum(float num_arr[], int n);

int main()
{
    char num_buf[10];
    float res, num_arr[ARR_LEN];

    printf("Sum of the numbers of an array of %i elements.\n", ARR_LEN);

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

    res = num_sum(num_arr, ARR_LEN);

    printf("The result of the sum is %1.2f", res);
}

float num_sum(float num_arr[], int n)
{
    float res = 0;

    for (int i = 0; i < n; i++)
    {
        res += num_arr[i];
    }
    return res;
}