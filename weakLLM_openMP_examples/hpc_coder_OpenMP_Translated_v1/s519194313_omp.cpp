#include<stdio.h>
#include<omp.h>
int main (void){
int i,j,a,b;
#pragma omp parallel for private(i,j) shared(a,b)
for(i=1;i<=9;i++){
for(j=1;j<=9;j++){
    printf("%dx%d=%d\n",i,j,i*j);
}
}
return 0;
}