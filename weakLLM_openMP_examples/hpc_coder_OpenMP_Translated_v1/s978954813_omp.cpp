#include<stdio.h>
#include<omp.h>
int main(void){
 int x,i;
 #pragma omp parallel for private(x,i)
 for(x=1;x<10;++x){
	 for(i=1;i<10;++i){
        printf("%dx%d=%d\n",x,i,x*i);
	 }
 }
 return 0;
}