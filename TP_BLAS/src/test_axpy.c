#include <stdio.h>
#include <stdlib.h>

#include "mnblas.h"
#include "complexe.h"

#define SIZE 3
int main(int argc, char **argv)
{
    // programme de test de la fonction axpy
    printf("Tests de axpy\n\n");
    testS();
    testD();
    testC();
    testZ();
}

void testS(){
    printf("Float :\n");
    float x[3] = {0.0,1.0,2.0};

    float y[3] = {0.0,1.0,2.0};

    const int alpha=1;

    mnblas_saxpy(SIZE,alpha,x,1,y,1);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%f ", y[i]);
    }
    printf("\n\n");
}

void testD(){
    printf("Double :\n");
    double x[3] = {0.0,1.0,2.0};

    double y[3] = {0.0,1.0,2.0};

    const int alpha=1;

    mnblas_daxpy(SIZE,alpha,x,1,y,1);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%lf ", y[i]);
    }
    printf("\n\n");
}

void testC(){
    printf("Complexe simple :\n");
    complexe_float_t *x = malloc(sizeof(complexe_float_t) * SIZE);
    complexe_float_t *y = malloc(sizeof(complexe_float_t) * SIZE);
    for(int i=0;i<SIZE;i++){
        x[i].real = i;
        x[i].imaginary = i;
        y[i].real = i;
        y[i].imaginary = i;
    }

    const int alpha= 1;

    mnblas_caxpy(SIZE,(void*)alpha,x,1,y,1);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%f ", y[i].real);
        printf("%f ", y[i].imaginary);
    }
    printf("\n\n");
    free(x);
    free(y);
}

void testZ(){
    printf("Complexe double :\n");
    complexe_double_t *x = malloc(sizeof(complexe_double_t) * SIZE);
    complexe_double_t *y = malloc(sizeof(complexe_double_t) * SIZE);
    for(int i=0;i<SIZE;i++){
        x[i].real = i;
        x[i].imaginary = i;
        y[i].real = i;
        y[i].imaginary = i;
    }

    const int alpha= 1;

    mnblas_zaxpy(SIZE,(void*)alpha,x,1,y,1);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%f ", y[i].real);
        printf("%f ", y[i].imaginary);
    }
    printf("\n\n");
    free(x);
    free(y);
}