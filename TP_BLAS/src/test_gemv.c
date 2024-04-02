#include <stdio.h>
#include <stdlib.h>

#include "mnblas.h"
#include "complexe.h"

#define SIZE 10

int main(int argc, char **argv)
{
    // programme de test de la fonction gemv

    printf("Tests de gemv\n\n");

    float *a = malloc(sizeof(float) * SIZE * SIZE);
    float *x = malloc(sizeof(float) * SIZE);
    float *y = malloc(sizeof(float) * SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        x[i] = i;
        y[i] = i;
        for (int j = 0; j < SIZE; j++)
        {
            a[i * SIZE + j] = i * SIZE + j;
        }
    }

    mncblas_sgemv(MNCblasRowMajor, MNCblasNoTrans, SIZE, SIZE, 1, a, SIZE, x, 1, 1, y, 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%f ", y[i]);
    }
    printf("\n");

    free(a);
    free(x);
    free(y);

    return 0;
}