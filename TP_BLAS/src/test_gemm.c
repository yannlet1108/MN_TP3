#include <stdio.h>
#include <stdlib.h>

#include "mnblas.h"
#include "complexe.h"


int main(int argc, char **argv)
{
    // programme de test de la fonction gemm
    printf("Tests de gemm\n\n");
    testS();
    testD();
    testC();
}

void testS(){
    printf("Float :\n");
    const int m=4;
    const int k=3;
    const int n=2;

    float a[4][3]={{0.0,1.0,2.0},
                    {0.0,1.0,2.0},
                    {0.0,1.0,2.0},
                    {0.0,1.0,2.0}};
    float b[3][2]={{1.0,1.0},
                    {1.0,1.0},
                    {1.0,1.0}};
    float c[4][2]={{1.0,1.0},
                    {1.0,1.0},
                    {1.0,1.0},
                    {1.0,1.0}};

    mncblas_sgemm(0,0,0,m,n,k,2,a,0,b,0,2,c,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf(" %f,  ", c[i][j]);
    }}
    printf("\n");
}

void testD(){
    printf("Double :\n");
    const int m=4;
    const int k=3;
    const int n=2;

    double a[4][3]={{0.0,1.0,2.0},
                    {0.0,1.0,2.0},
                    {0.0,1.0,2.0},
                    {0.0,1.0,2.0}};
    double b[3][2]={{1.0,1.0},
                    {1.0,1.0},
                    {1.0,1.0}};
    double c[4][2]={{1.0,1.0},
                    {1.0,1.0},
                    {1.0,1.0},
                    {1.0,1.0}};

    mncblas_dgemm(0,0,0,m,n,k,2,a,0,b,0,2,c,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf(" %f,  ", c[i][j]);
    }}
    printf("\n");
}

void testC(){
    printf("Complexe simple :\n");
    const int m=4;
    const int k=3;
    const int n=2;

    // Allocation des matrices a, b et c.
    complexe_float_t **a = malloc(sizeof(complexe_float_t *) * m);
    complexe_float_t **b = malloc(sizeof(complexe_float_t *) * k);
    complexe_float_t **c = malloc(sizeof(complexe_float_t *) * m);

    if (a == NULL || b == NULL || c == NULL) {
        printf("Erreur d'allocation de mémoire pour les matrices a, b ou c.\n");
        return;
    }

    for (int i = 0; i < m; i++) {
        a[i] = malloc(sizeof(complexe_float_t) * k);
        c[i] = malloc(sizeof(complexe_float_t) * n);

        if (a[i] == NULL || c[i] == NULL) {
            printf("Erreur d'allocation de mémoire pour la ligne %d de la matrice a ou c.\n", i);
            return;
        }
    }

    for (int i = 0; i < k; i++) {
        b[i] = malloc(sizeof(complexe_float_t) * n);

        if (b[i] == NULL) {
            printf("Erreur d'allocation de mémoire pour la ligne %d de la matrice b.\n", i);
            return;
        }
    }
    // Initialisation des matrices a, b et c.
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            a[i][j].real=j;
            a[i][j].imaginary=j;
        }
        for(int j=0;j<n;j++){
            c[i][j].real=1.0;
            c[i][j].imaginary=1.0;
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            b[i][j].real=1.0;
            b[i][j].imaginary=1.0;
        }
    }
    complexe_float_t *alpha = malloc(sizeof(complexe_float_t));
    complexe_float_t *beta = malloc(sizeof(complexe_float_t));
    alpha->real=1.0;
    alpha->imaginary=0.0;
    beta->real=1.0;
    beta->imaginary=0.0;


    mncblas_cgemm(0,0,0,m,n,k,alpha,a,0,b,0,beta,c,0);
    for(int i=0;i<m;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            printf(" %f + ", c[i][j].real);
            printf(" %fi,  ", c[i][j].imaginary);
        /*Res attendu : 1+7i , 1+7i
                        1+7i , 1+7i
                        1+7i , 1+7i
                        1+7i , 1+7i */
        }
    }
    printf("\n");
    
    // Libération de la mémoire allouée dynamiquement
    for (int i = 0; i < m; i++) {
        free(a[i]);
        free(c[i]);
    }
    for (int i = 0; i < k; i++) {
        free(b[i]);
    }
    free(a);
    free(b);
    free(c);
}