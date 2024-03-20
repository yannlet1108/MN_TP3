include "mkl.h"

const float* transpose(const float* a){
    float* b = (float*)malloc(sizeof(float)*m*n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            b[j*m+i] = a[i*n+j];
        }
    }
    return b;
}
void cblas_sgemv (const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE trans, const MKL_INT m, const MKL_INT n, const float alpha, const float *a,
    const MKL_INT lda, const float *x, const MKL_INT incx, const float beta, float *y, const MKL_INT incy){

    if (trans == CblasNoTrans){
    
        for (int i = 0; i < m; i++){
            y[i] = 0;
            for (int j = 0; j < n; j++){
                y[i] += a[i*n+j]*x[j]*alpha;
            }
        }
        for (int i = 0; i < m; i++){
            y[i] = y[i] + beta*y[i];
        }
    }
    else if(trans == CblasTrans){
        a=transpose(a);
        for (int i = 0; i < n; i++){
            y[i] = 0;
            for (int j = 0; j < m; j++){
                y[i] += a[j*n+i]*x[j]*alpha;//Faut faire transposer a
            }
        }
        for (int i = 0; i < n; i++){
            y[i] = y[i] + beta*y[i];
        }
    }
    else{
        
    }

}

