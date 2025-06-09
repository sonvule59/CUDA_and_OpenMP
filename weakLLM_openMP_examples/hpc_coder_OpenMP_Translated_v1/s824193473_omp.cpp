#include<stdio.h>
#include<omp.h>
main(){int i=0,j;#pragma omp parallel for private(j) shared(i)
while(j=0|i++<9)while(10-j)printf("%dx%d=%d\n",i,j++,i*j);}

Note:

*

*The OpenMP code uses the #pragma omp parallel for directive to parallelize the loop.

*The private(j) clause specifies that the variable j is private to each thread.

*The shared(i) clause specifies that the variable i is shared among all threads.

*The while(j=0|i++<9)while(10-j)printf("%dx%d=%d\n",i,j++,i*j); loop is the same as the original C++ code.