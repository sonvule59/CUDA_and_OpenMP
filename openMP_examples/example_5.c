/*
 * Sorbonne Universit�
 *
 * Programme de multiplication de matrices carr�es.
 */
#include <stdlib.h>
#include <stdio.h>
#include <omp.h> 
int dummyMethod1();
int dummyMethod2();
int dummyMethod3();
int dummyMethod4();
#include <sys/time.h>

double my_gettimeofday()
{
  struct timeval tmp_time;
  gettimeofday(&tmp_time,(void *)0);
  return (tmp_time . tv_sec + tmp_time . tv_usec * 1.0e-6L);
}
#define REAL_T float
#define NB_TIMES 10
/*** Matmul: ***/
/* C += A x B
 * square matrices of order 'n'
 */

void matmul(int n,float *A,float *B,float *C)
{
  dummyMethod3();
  for (int i = 0; i <= n - 1; i += 1) {
    for (int j = 0; j <= n - 1; j += 1) {
      for (int k = 0; k <= n - 1; k += 1) {
        C[i * n + j] += A[i * n + k] * B[k * n + j];
/* for k */
      }
    }
/* for j */
  }
/* for i */
  dummyMethod4();
}

void matmul_openmp(int n,float *A,float *B,float *C)
{
  dummyMethod1();
  for (int i = 0; i <= n - 1; i += 1) {
    for (int j = 0; j <= n - 1; j += 1) {
      for (int k = 0; k <= n - 1; k += 1) {
        C[i * n + j] += A[i * n + k] * B[k * n + j];
/* for k */
      }
    }
/* for j */
  }
/* for i */
  dummyMethod2();
}

int main(int argc,char **argv)
{
  float *A;
  float *B;
  float *C;
  int n = 2;
/* default value */
  int nb = 0;
/* Read 'n' on command line: */
  if (argc == 2) {
    n = atoi(argv[1]);
  }
/* Allocate the matrices: */
  if ((A = ((float *)(malloc((n * n) * sizeof(float ))))) == ((void *)0)) 
    fprintf(stderr,"Error while allocating A.\n");
  if ((B = ((float *)(malloc((n * n) * sizeof(float ))))) == ((void *)0)) 
    fprintf(stderr,"Error while allocating B.\n");
  if ((C = ((float *)(malloc((n * n) * sizeof(float ))))) == ((void *)0)) 
    fprintf(stderr,"Error while allocating C.\n");
/* Initialize the matrices */
  dummyMethod3();
int j;  
#pragma omp parallel for private (j)
#pragma rose_outline
  for (int i = 0; i <= n - 1; i += 1) {
    for (int j = 0; j <= n - 1; j += 1) {
       *(A + i * n + j) = 1 / ((float )(i + j + 1));
       *(B + i * n + j) = 1.0;
       *(C + i * n + j) = 1.0;
    }
  }
  dummyMethod4();
/* Start timing */
  double debut = my_gettimeofday();
  dummyMethod3();
  for (nb = 0; nb <= 9; nb += 1) {
/* Do matrix-product C=A*B+C */
    matmul(n,A,B,C);
/* End timing */
  }
  dummyMethod4();
  double fin = my_gettimeofday();
  fprintf(stdout,"For n=%d: total computation time (with gettimeofday()) : %g s\n",n,(fin - debut) / 10);
  fprintf(stdout,"For n=%d: performance = %g Gflop/s \n",n,((double )2) * n * n * n / ((fin - debut) / 10) / ((double )1e9));
/* 2n^3 flops */
/* Start timing */
  debut = my_gettimeofday();
  dummyMethod3();
  for (nb = 0; nb <= 9; nb += 1) {
/* Do matrix-product C=A*B+C */
    matmul_openmp(n,A,B,C);
/* End timing */
  }
  dummyMethod4();
  fin = my_gettimeofday();
  fprintf(stdout,"For n=%d: total computation time (with gettimeofday()) : %g s\n",n,(fin - debut) / 10);
  fprintf(stdout,"For n=%d: performance = %g Gflop/s \n",n,((double )2) * n * n * n / ((fin - debut) / 10) / ((double )1e9));
/* 2n^3 flops */
/* Print 2x2 top-left square of C : */
  dummyMethod3();
  for (int i = 0; i <= 1; i += 1) {
    for (int j = 0; j <= 1; j += 1) {
      printf("%+e  ",C[i * n + j]);
    }
    printf("\n");
  }
  dummyMethod4();
  printf("\n");
/* Print 2x2 bottom-right square of C : */
  dummyMethod3();
  for (int i = n - 2; i <= n - 1; i += 1) {
    for (int j = n - 2; j <= n - 1; j += 1) {
      printf("%+e  ",C[i * n + j]);
    }
    printf("\n");
  }
  dummyMethod4();
  return 0;
}

int dummyMethod1()
{
  return 0;
}

int dummyMethod2()
{
  return 0;
}

int dummyMethod3()
{
  return 0;
}

int dummyMethod4()
{
  return 0;
}
