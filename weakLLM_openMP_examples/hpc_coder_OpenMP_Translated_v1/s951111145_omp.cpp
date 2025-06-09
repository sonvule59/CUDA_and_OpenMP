#include <stdio.h>
#include <omp.h>
int main(void)
{
    int a, b;
#pragma omp parallel for private(a, b)
    for(a=1; a<=9; a++){
        for(b=1; b<=9; b++){
            printf("%dx%d=%d\n" ,a, b, a*b);
        }
    }
       return 0;
}