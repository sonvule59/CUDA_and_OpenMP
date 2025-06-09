#include<stdio.h>
#include<omp.h>
#define f(i,m) for(int i=1;i<=m;i++)
int main(){
    f(i,9)f(j,9)printf("%dx%d=%d\n",i,j,i*j);
    #pragma omp parallel for collapse(2)
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            printf("%dx%d=%d\n",i,j,i*j);
        }
    }
    return 0;
}