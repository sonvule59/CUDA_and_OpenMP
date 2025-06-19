#include<stdio.h>

__global__ void multiply(int *a, int *b, int *c, int n){
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if(i < n){
		c[i] = a[i] * b[i];
	}
}

int main(){
	int a[9] = {1,2,3,4,5,6,7,8,9};
	int b[9] = {1,2,3,4,5,6,7,8,9};
	int c[9];
	int n = 9;

	multiply<<<1,n>>>(a,b,c,n);

	for(int i=0;i<n;i++){
		printf("%d x %d = %d\n",a[i],b[i],c[i]);
	}

	return 0;
}