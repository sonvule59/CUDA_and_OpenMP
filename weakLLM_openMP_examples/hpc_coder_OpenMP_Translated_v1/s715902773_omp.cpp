#include<cstdio>
#include<omp.h>
int i,j;
main(){
    #pragma omp parallel for
    for(;i++<9;)for(j=1;j<10;)printf("%dx%d=%d\n",i,j++,i*j);
}