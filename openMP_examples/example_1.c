#include <stdio.h>
#include <stdlib.h>
int dummyMethod1();
int dummyMethod2();
int dummyMethod3();
int dummyMethod4();
#define M 1000
#define INT_MAX 999

int main(void)
{
    int A[M];
    int i;
    int result= INT_MAX;

dummyMethod3();
    #pragma omp parallel for private(i)
    #pragma rose_outline
    for (i = 0; i < M; i++)
    {
        A[i] = i;
    }
dummyMethod4();

        /* M ́ınimo de valores en un array */
dummyMethod1();
    for (i = 0; i < 1000; i++)
    {
        if (A[i] < result)
            result = A[i];
    }
dummyMethod2();
    printf("Suma %d\n", result);
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