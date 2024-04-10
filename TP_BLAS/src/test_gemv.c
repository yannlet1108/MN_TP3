#include <stdio.h>
#include <stdlib.h>

#include "mnblas.h"
#include "complexe.h"

#define SIZE 3

void testS(){
    printf("Float :\n");
    const float a[9]={0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};

    float x[3] = {0.0,1.0,2.0};

    float y[3] = {0.0,1.0,2.0};

    const float alpha=1;
    const float beta=1;

    mncblas_sgemv(MNCblasRowMajor, MNCblasNoTrans, SIZE, SIZE, alpha, a, 1, x, 1, beta, y, 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%f ", y[i]);
    }
    printf("\n");

}

void testD(){
    printf("Double :\n");
    const double a[9]={0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};

    double x[3] = {0.0,1.0,2.0};

    double y[3] = {0.0,1.0,2.0};

    const int alpha=1;
    const int beta=1;

    mncblas_dgemv(MNCblasRowMajor, MNCblasNoTrans, SIZE, SIZE, alpha, a, 1, x, 1, beta, y, 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%f ", y[i]);
    }
    printf("\n");
    
}
void testC(){
    printf("Complexe simple :\n");
    // Allocation de mémoire pour les vecteurs x et y
    complexe_float_t *x = malloc(sizeof(complexe_float_t) * SIZE);
    complexe_float_t *y = malloc(sizeof(complexe_float_t) * SIZE);
    if (x == NULL || y == NULL) {
        printf("Erreur d'allocation de mémoire pour les vecteurs x et y.\n");
        return ;
    }

    complexe_float_t *a = malloc(sizeof(complexe_float_t) * SIZE*SIZE);
    if (a == NULL) {
        printf("Erreur d'allocation de mémoire pour la matrice a.\n");
        return ;
    }
    // Initialisation des valeurs pour x, y et a
    for (int i = 0; i < SIZE; i++) {
        x[i].real = i;
        x[i].imaginary = i;
        y[i].real = i;
        y[i].imaginary = i;
        for (int j = 0; j < SIZE; j++) {
            a[i * 3 + j].real = i * 3 + j;
            a[i * 3 + j].imaginary = i * 3 + j;
        }
    }
    complexe_float_t *alpha = malloc(sizeof(complexe_float_t));
    complexe_float_t *beta = malloc(sizeof(complexe_float_t));
    alpha->real=1.0;
    alpha->imaginary=0.0;
    beta->real=1.0;
    beta->imaginary=0.0;

    mncblas_cgemv(MNCblasRowMajor, MNCblasNoTrans, SIZE, SIZE, (void *)alpha, a, 1, x, 1, beta, y, 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%f ", y[i].real);
        printf("%f \n", y[i].imaginary);
        /* Res attendu : 0+10i 
                        0+28i 
                        0+46i */
    }

    // Libération de la mémoire allouée dynamiquement
    free(a);
    free(x);
    free(y);
    free(alpha);
    free(beta);
}

void testZ(){
    printf("Complexe double :\n");
    // Allocation de mémoire pour les vecteurs x et y
    complexe_double_t *x = malloc(sizeof(complexe_double_t) * SIZE);
    complexe_double_t *y = malloc(sizeof(complexe_double_t) * SIZE);
    if (x == NULL || y == NULL) {
        printf("Erreur d'allocation de mémoire pour les vecteurs x et y.\n");
        return ;
    }

    complexe_double_t *a = malloc(sizeof(complexe_double_t) * SIZE * SIZE);
    if (a == NULL) {
        printf("Erreur d'allocation de mémoire pour la matrice a.\n");
        return ;
    }

    // Initialisation des valeurs pour x, y et a
    for (int i = 0; i < SIZE; i++) {
        x[i].real = i;
        x[i].imaginary = i;
        y[i].real = i;
        y[i].imaginary = i;
        for (int j = 0; j < SIZE; j++) {
            a[i * SIZE + j].real = i * 3 + j;
            a[i * SIZE + j].imaginary = i * 3 + j;
        }
    }
    complexe_double_t *alpha = malloc(sizeof(complexe_double_t));
    complexe_double_t *beta = malloc(sizeof(complexe_double_t));
    alpha->real=1.0;
    alpha->imaginary=0.0;
    beta->real=1.0;
    beta->imaginary=0.0;

    mncblas_zgemv(MNCblasRowMajor, MNCblasNoTrans, SIZE, SIZE, alpha, a, 1, x, 1, beta, y, 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%f ", y[i].real);
        printf("%f \n", y[i].imaginary);
        /* Res attendu : 0+10i 
                        0+28i 
                        0+46i */
    }

    // Libération de la mémoire allouée dynamiquement
    free(a);
    free(x);
    free(y);
    free(alpha);
    free(beta);
}

int main(int argc, char **argv)
{
    // programme de test de la fonction gemv

    printf("Tests de gemv\n\n");
    testS();
    testD();
    testC();
    testZ();

    return 0;
}