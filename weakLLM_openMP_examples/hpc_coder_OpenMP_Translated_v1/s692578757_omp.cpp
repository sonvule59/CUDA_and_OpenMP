#include<stdio.h>
#include<omp.h>

int main ()
{
    #pragma omp parallel for
    for(int i=1;i<10;i++){
            for(int z=1;z<10;z++){
                    printf("%dx%d=%d\n", i, z, i*z);
                    }}
                    
            getchar();return 0;
            }

Note: The OpenMP code uses the `#pragma omp parallel for` directive to parallelize the outer loop. The inner loop is not parallelized, as it is not necessary for the problem.