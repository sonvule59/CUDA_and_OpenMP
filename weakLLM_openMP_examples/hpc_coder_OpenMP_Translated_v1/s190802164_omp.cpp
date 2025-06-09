#include<cstdio>
#include<omp.h>
main(){
#pragma omp parallel for
for(int i=1,j;i<=9;i++)for(j=1;j<=9;)printf("%dx%d=%d\n",i,j++,i*j);
}