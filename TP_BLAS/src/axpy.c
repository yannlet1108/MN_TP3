#include "mnblas.h"
#include "complexe.h"

void mnblas_saxpy(const int N, const float alpha, const float *X,
                 const int incX, float *Y, const int incY){
register unsigned int i = 0;
register unsigned int j = 0;

  for (; ((i < N) && (j < N)); i += incX, j += incY){
    Y[j]+=alpha*X[i];
}
}

void mnblas_daxpy(const int N, const double alpha, const double *X,const int incX, double *Y, const int incY){
register unsigned int i = 0;
register unsigned int j = 0;

  for (; ((i < N) && (j < N)); i += incX, j += incY){
    Y[j]+=alpha*X[i];
}
}

void mnblas_caxpy(const int N, const void *alpha, const void *X,const int incX, void *Y, const int incY){
register unsigned int i = 0;
register unsigned int j = 0;

  for (; ((i < N) && (j < N)); i += incX, j += incY){
    ((complexe_float_t*)X)[i].real=(int)alpha*((complexe_float_t*)X)[i].real;
    ((complexe_float_t*)X)[i].imaginary=(int)alpha*((complexe_float_t*)X)[i].imaginary;
    ((complexe_float_t*)Y)[j]=add_complexe_float(((complexe_float_t*)X)[i],((complexe_float_t*)Y)[j]);
}
}

void mnblas_zaxpy(const int N, const void *alpha, const void *X,const int incX, void *Y, const int incY){
register unsigned int i = 0;
register unsigned int j = 0;

  for (; ((i < N) && (j < N)); i += incX, j += incY){
    ((complexe_double_t*)X)[i].real=(int)alpha*((complexe_double_t*)X)[i].real;
    ((complexe_double_t*)X)[i].imaginary=(int)alpha*((complexe_double_t*)X)[i].imaginary;
    ((complexe_double_t*)Y)[j]=add_complexe_double(((complexe_double_t*)X)[i],((complexe_double_t*)Y)[j]);
}
}
