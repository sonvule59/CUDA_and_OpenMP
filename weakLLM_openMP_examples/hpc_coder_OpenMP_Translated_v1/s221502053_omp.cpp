#include<stdio.h>
#include<omp.h>
char a, b;int main(){#pragma omp parallel for
for(a=1;a<=9;a++)#pragma omp parallel for
for(b=1;b<=9;b++)printf("%dx%d=%d\n",a,b,a*b);return 0;}