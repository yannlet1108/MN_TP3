#include "mnblas.h"
#include <stdio.h>
#include "complexe.h"

void mncblas_sgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                   MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                   const int K, const float alpha, const float *A,
                   const int lda, const float *B, const int ldb,
                   const float beta, float *C, const int ldc)
{
    float sum = 0.0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k1 = 0; k1 < K; k1++)
            {
                sum += A[i * K + k1] * B[k1 * N + j];
            }
            sum *= alpha;
            C[i * N + j] = sum + beta * C[i * N + j];
            sum = 0.0;
        }
    }
}


void mncblas_dgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double *A,
                 const int lda, const double *B, const int ldb,
                 const double beta, double *C, const int ldc){
    double sum = 0.0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k1 = 0; k1 < K; k1++)
            {
                sum += A[i * K + k1] * B[k1 * N + j];
            }
            sum *= alpha;
            C[i * N + j] = sum + beta * C[i * N + j];
            sum = 0.0;
        }
    }                   
}
void mncblas_cgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc){
    complexe_float_t sum = {0.0,0.0};
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k1 = 0; k1 < K; k1++)
            {
                sum = add_complexe_float(sum,mult_complexe_float(((complexe_float_t*)A)[i * K + k1],((complexe_float_t*)B)[k1 * N + j]));
            }
            sum.real=(int) alpha * sum.real;
            sum.imaginary=(int) alpha *sum.imaginary;
            ((complexe_float_t*)C)[i * N + j].real=(int) beta * ((complexe_float_t*)C)[i * N + j].real;
            ((complexe_float_t*)C)[i * N + j].imaginary=(int) beta * ((complexe_float_t*)C)[i * N + j].imaginary;
            ((complexe_float_t*)C)[i * N + j] = add_complexe_float(sum,((complexe_float_t*)C)[i * N + j]);
            sum.real=0.0;
            sum.imaginary=0.0;
        }
    }                   
}

void mncblas_zgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc){
complexe_double_t sum = {0.0,0.0};
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k1 = 0; k1 < K; k1++)
            {
                sum = add_complexe_double(sum,mult_complexe_double(((complexe_double_t*)A)[i * K + k1],((complexe_double_t*)B)[k1 * N + j]));
            }
            sum.real=(int) alpha * sum.real;
            sum.imaginary=(int) alpha *sum.imaginary;
            ((complexe_double_t*)C)[i * N + j].real=(int) beta * ((complexe_double_t*)C)[i * N + j].real;
            ((complexe_double_t*)C)[i * N + j].imaginary=(int) beta * ((complexe_double_t*)C)[i * N + j].imaginary;
            ((complexe_double_t*)C)[i * N + j] = add_complexe_double(sum,((complexe_double_t*)C)[i * N + j]);
            sum.real=0.0;
            sum.imaginary=0.0;
        }
    }                   
}