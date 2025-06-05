#include<stdio.h>
#define F(i) for(i=1;i<=9;i++)
__global__ void kernel(int *a, int *b){
int i,j;
F(i)F(j)a[i*9+j]=i*j;
}
int main(){
int *a, *b;
int i,j;
a=(int *)malloc(9*9*sizeof(int));
b=(int *)malloc(9*9*sizeof(int));
kernel<<<1,1>>>(a,b);
F(i)F(j)printf("%dx%d=%d\n",i,j,a[i*9+j]);
free(a);
free(b);
return 0;
}