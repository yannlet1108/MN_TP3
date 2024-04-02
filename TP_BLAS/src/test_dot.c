#include <stdio.h>
#include <stdlib.h>

#include "mnblas.h"
#include "complexe.h"

#define SIZE 10

int main(int argc, char **argv)
{
    // programme de test de la fonction dot pour les 4 types de variables

    printf("Tests de dot\n\n");

    float *s1 = malloc(sizeof(float) * SIZE);
    float *s2 = malloc(sizeof(float) * SIZE);
    double *d1 = malloc(sizeof(double) * SIZE);
    double *d2 = malloc(sizeof(double) * SIZE);
    complexe_float_t *c1 = malloc(sizeof(complexe_float_t) * SIZE);
    complexe_float_t *c2 = malloc(sizeof(complexe_float_t) * SIZE);
    complexe_double_t *z1 = malloc(sizeof(complexe_double_t) * SIZE);
    complexe_double_t *z2 = malloc(sizeof(complexe_double_t) * SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        s1[i] = i;
        s2[i] = i;
        d1[i] = i;
        d2[i] = i;
        c1[i].real = i;
        c1[i].imaginary = i;
        c2[i].real = i;
        c2[i].imaginary = i;
        z1[i].real = i;
        z1[i].imaginary = i;
        z2[i].real = i;
        z2[i].imaginary = i;
    }

    printf("float\n");
    printf("mncblas_sdot : %f\n", mncblas_sdot(SIZE, s1, 1, s2, 1));
    printf("résultat attendu : 285\n");
    printf("\n");

    printf("double\n");
    printf("mncblas_ddot : %f\n", mncblas_ddot(SIZE, d1, 1, d2, 1));
    printf("résultat attendu : 285\n");
    printf("\n");

    printf("complexe_float_t\n");
    complexe_float_t dotu;
    mncblas_cdotu_sub(SIZE, c1, 1, c2, 1, &dotu);
    printf("mncblas_cdotu_sub : %f + %fi\n", dotu.real, dotu.imaginary);
    printf("résultat attendu : 0 + 570i\n");
    printf("\n");

    complexe_float_t dotu2;
    mncblas_cdotc_sub(SIZE, c1, 1, c2, 1, &dotu2);
    printf("mncblas_cdotc_sub : %f + %fi\n", dotu2.real, dotu2.imaginary);
    printf("résultat attendu : 570 + 0i\n");
    printf("\n");    

    printf("complexe_double_t\n");
    complexe_double_t dotu3;
    mncblas_zdotu_sub(SIZE, z1, 1, z2, 1, &dotu3);
    printf("mncblas_zdotu_sub : %f + %fi\n", dotu3.real, dotu3.imaginary);
    printf("résultat attendu : 0 + 570i\n");
    printf("\n");

    complexe_double_t dotu4;
    mncblas_zdotc_sub(SIZE, z1, 1, z2, 1, &dotu4);
    printf("mncblas_zdotc_sub : %f + %fi\n", dotu4.real, dotu4.imaginary);
    printf("résultat attendu : 570 + 0i\n");
    printf("\n");

    return 0;
}