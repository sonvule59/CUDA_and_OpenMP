#include<cstdio>
#include<omp.h>
int main(){
#pragma omp parallel for
for(int i=0;i<81;i++)printf("%dx%d=%d\n",i/9+1,i%9+1,(i/9+1)*(i%9+1));
}