#include<stdio.h>
#include<omp.h>

int main()
{

    int i,j,n;
    n = 9;
    #pragma omp parallel for
    for(i = 1; i <= 9; i++){
        for(j = 1; j <= 9;j++ ){
            printf("%dx%d=%d\n" ,i,j,(i*j));
        }

    //printf("\n");

    }
return 0;

}