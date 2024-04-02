#include "mnblas.h"

void mncblas_sgemv(const MNCBLAS_LAYOUT Layout, const MNCBLAS_TRANSPOSE trans, const int m, const int n, const float alpha, const float *a,
                 const int lda, const float *x, const int incx, const float beta, float *y, const int incy)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            y[i*n + j] = a[i * n + j] * x[j] * alpha + y[i * n + j] * beta;
        }
    }
}
