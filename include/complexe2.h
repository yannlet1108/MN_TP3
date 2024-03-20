
typedef struct {
  float real ;
  float imaginary ;
} complexe_float_t ;

typedef struct {
  double real ;
  double imaginary ;
} complexe_double_t ;

inline complexe_float_t add_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}

inline complexe_double_t add_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r ;

  r.real = c1.real + c2.real ;
  r.imaginary = c1.imaginary + c2.imaginary ;
  
  return r ;
}



inline complexe_float_t mult_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r ;
  r.real = c1.real*c2.real - c1.imaginary*c2.imaginary ;
  r.imaginary = c1.real*c2.imaginary + c2.real*c1.imaginary ;
  return r ;
}

inline complexe_double_t mult_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r ;
  r.real = c1.real*c2.real - c1.imaginary*c2.imaginary ;
  r.imaginary = c1.real*c2.imaginary + c2.real*c1.imaginary ;
  return r ;
}

inline complexe_float_t conjugue_float (const complexe_float_t c1){
  complexe_float_t c;
  c.real=c1.real;
  c.imaginary=-c1.imaginary;
  return c;
}

inline complexe_double_t conjugue_double (const complexe_double_t c1){
  complexe_double_t c;
  c.real=c1.real;
  c.imaginary=-c1.imaginary;
  return c;
}

inline complexe_float_t div_complexe_float (const complexe_float_t c1, const complexe_float_t c2)
{
  complexe_float_t r = mult_complexe_float(c1,conjugue_float(c2));
  float den = c2.real * c2.real + c2.imaginary * c2.imaginary;
  r.real = r.real / den ;
  r.imaginary = r.imaginary / den ;
  return r ;
}

inline complexe_double_t div_complexe_double (const complexe_double_t c1, const complexe_double_t c2)
{
  complexe_double_t r = mult_complexe_double(c1,conjugue_double(c2));
  double den = c2.real * c2.real + c2.imaginary * c2.imaginary;
  r.real = r.real / den ;
  r.imaginary = r.imaginary / den ;
  return r ;
}



