#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

float freq_resp(float w, float* p_real, float* p_imag, float* p_mag);

int main()
{
    float w, real, imag, mag;

    printf("Frequency response function for feed back system\n");
    printf("*************************************************\n");
    printf("Freq.     Real part     Imaginary part   Magnitude\n");

    for (float i = 1; i < 11; i++)
    {
        w = 2 * M_PI * i;
        freq_resp(w, &real, &imag, &mag);
        printf("%1.1f\t%1.10f\t%1.10f\t%1.10f\n", i, real, imag, mag);
    }
    
}

float freq_resp(float w, float* p_real, float* p_imag, float* p_mag){
    float complex a, b, c, d, e, f, g;

    a = 200.0*I;
    b = 2.0+w*I;
    c = w*w*w;
    d = 1.0+0.1*w*I;
    e = 1.0+0.3*w*I;
    f = 1.0+0.6*w*I;
    g = 1.0+0.8*w*I;

    float complex num = a*b;
    float complex denom = c*d*e*f*g;

    float complex res = num/denom;

    *p_real = creal(res);
    *p_imag = cimag(res);
    *p_mag = cabs(res);

}