#include<cstdio>
#include<omp.h>
int main(){
    #pragma omp parallel for
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            printf("%dx%d=%d\n",i+1,j+1,(i+1)*(j+1));
}