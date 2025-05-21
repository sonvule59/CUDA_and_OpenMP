#include <stdio.h>
int dummyMethod1();
int dummyMethod2();
int dummyMethod3();
int dummyMethod4();
/* { dg-do run } */
/* { dg-additional-options "-msse2" { target sse2_runtime } } */
/* { dg-additional-options "-mavx" { target avx_runtime } } */

int main ()
{
//   int k = 0, i, s = 0;
    int i, s = 0;
dummyMethod1();
// #pragma omp parallel for reduction(+:k,s)
#pragma omp parallel for reduction(+:s)
#pragma rose_outline
  for (i = 0; i < 128; i++)
    {
    //   k = k + 3;
      int k = (i+1) *3;
      s = s + k;
    }
    printf("Sum s = %d\n", s);  
  if (s != 128 * 129 / 2 * 3) __builtin_abort ();
dummyMethod2();
  return 0;
}
int dummyMethod1(){
    return 0;
}
int dummyMethod2(){
    return 0;
}
int dummyMethod3(){
    return 0;
}
int dummyMethod4(){
    return 0;
}