#include<stdio.h>
#include<omp.h>
int main(){
    #pragma omp parallel for
    for(int i=9;i<90;i++)printf("%dx%d=%d\n",i/9,i%9+1,i/9*(i%9+1));
}