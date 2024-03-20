#include <stdio.h>
#include <stdlib.h>

#include "complexe.h"

#include "mnblas.h"

#define SIZE 10

int main(int argc, char **argv)
{
    // programme de test de la fonction copy pour les 4 types de variables

    /*pour chaque type de variable, la variable 1 est composée des nombres 0 à SIZE-1 et la variable 2 est remplie de 0
    On copie ensuite la variable 1 dans la variable 2 puis on écrit la variable 2 à l'écran
    Elle doit être composée des nombres 0 à SIZE-1*/

    printf("Tests de copy\n");

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
        s2[i] = 0;
        d1[i] = i;
        d2[i] = 0;
        c1[i].real = i;
        c1[i].imaginary = i;
        c2[i].real = 0;
        c2[i].imaginary = 0;
        z1[i].real = i;
        z1[i].imaginary = i;
        z2[i].real = 0;
        z2[i].imaginary = 0;
    }

    printf("float\n");
    mncblas_scopy(SIZE, s1, 1, s2, 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %f,  ", s2[i]);
    }
    printf("\n\n");

    printf("double\n");
    mncblas_dcopy(SIZE, d1, 1, d2, 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %f,  ", d2[i]);
    }
    printf("\n\n");

    printf("complexe_float_t\n");
    mncblas_ccopy(2 * SIZE, c1, 1, c2, 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %f + %fi, ", c2[i].real, c2[i].imaginary);
    }
    printf("\n\n");

    printf("complexe_double_t\n");
    mncblas_zcopy(2 * SIZE, z1, 1, z2, 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %f + %fi, ", z2[i].real, z2[i].imaginary);
    }
    printf("\n\n");

    free(s1);
    free(s2);
    free(d1);
    free(d2);
    free(c1);
    free(c2);
    free(z1);
    free(z2);

    return 0;
}