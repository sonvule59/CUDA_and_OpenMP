#include<cstdio>
#include<omp.h>
int main(){int m,n;#pragma omp parallel for private(m,n)
for(m=1;m<=9;++m)for(n=1;n<=9;++n)printf("%dx%d=%d\n",m,n,m*n);}