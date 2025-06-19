#include<stdio.h>

__global__ void multiply(int *a, int *b, int *c){
	int i = threadIdx.x;
	c[i] = a[i] * b[i];
}

int main(){
	int a[10], b[10], c[10];
	for(int i=0;i<10;i++){
		a[i] = i+1;
		b[i] = i+1;
	}
	
	multiply<<<1,10>>>(a,b,c);
	
	for(int i=0;i<10;i++){
		printf("%d x %d = %d\n",a[i],b[i],c[i]);
	}
	
	return 0;
}