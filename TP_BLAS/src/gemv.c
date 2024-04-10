#include "mnblas.h"
#include "complexe.h"

void mncblas_sgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, const float alpha, const float *a,
                   const int lda, const float *x, const int incx, const float beta, float *y, const int incy)
{
    float sum=0.0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum=a[i * n + j] * x[j] * alpha;
            y[i]*=beta;
            y[i]+=sum;
        }

    }
}

void mncblas_dgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int m, const int n,
                 const double alpha, const double *a, const int lda,
                 const double *x, const int incX, const double beta,
                 double *y, const int incY){
    double sum=0.0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum=a[i * n + j] * x[j] * alpha;
            y[i]*=beta;
            y[i]+=sum;
        }

    }
}
void mncblas_cgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int m, const int n,
                 const void *alpha, const void *a, const int lda,
                 const void *x, const int incX, const void *beta,
                 void *y, const int incY){
    complexe_float_t sum;
    for (int i = 0; i < m; i++)
    {
        sum.real=0.0;
        sum.imaginary=0.0;
        for (int j = 0; j < n; j++)
        {
            ((complexe_float_t*)x)[j]= mult_complexe_float(*((complexe_float_t*) alpha) , ((complexe_float_t*)x)[j]);
            sum=mult_complexe_float(((complexe_float_t*)a)[i * n + j],((complexe_float_t*)x)[j]);
            //printf("i=%d, j=%d, %f\n",i,j,((complexe_float_t*)a)[i * n + j].real);
            ((complexe_float_t*)y)[i]= mult_complexe_float(*((complexe_float_t*) beta) , ((complexe_float_t*)y)[i]);
            ((complexe_float_t*)y)[i]=add_complexe_float(sum,((complexe_float_t*)y)[i]);
        }
    }
}

void mncblas_zgemv(MNCBLAS_LAYOUT layout,
                 MNCBLAS_TRANSPOSE TransA, const int m, const int n,
                 const void *alpha, const void *a, const int lda,
                 const void *x, const int incX, const void *beta,
                 void *y, const int incY){
    complexe_double_t sum;
    for (int i = 0; i < m; i++)
    {
        sum.real=0.0;
        sum.imaginary=0.0;
        for (int j = 0; j < n; j++)
        {
            ((complexe_double_t*)x)[j]= mult_complexe_double(*((complexe_double_t*) alpha) , ((complexe_double_t*)x)[j]);
            sum=mult_complexe_double(((complexe_double_t*)a)[i * n + j],((complexe_double_t*)x)[j]);
            ((complexe_double_t*)y)[i]= mult_complexe_double(*((complexe_double_t*) beta) , ((complexe_double_t*)y)[i]);
            ((complexe_double_t*)y)[i]=add_complexe_double(sum,((complexe_double_t*)y)[i]);
        }
    }
}


