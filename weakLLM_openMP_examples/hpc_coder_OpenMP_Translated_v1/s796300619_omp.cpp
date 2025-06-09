#include<cstdio>
#include<omp.h>
int main(){
int i,n;
#pragma omp parallel for private(i,n)
for(i=1;i<10;++i)for(n=1;n<10;++n)printf("%dx%d=%d\n",i,n,i*n);
}