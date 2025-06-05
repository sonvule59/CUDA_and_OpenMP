#include<stdio.h>
__global__ void multiply(int *a, int *b, int *c)
{
	int x = threadIdx.x;
	int y = threadIdx.y;
	int z = threadIdx.z;
	int a_val = a[x];
	int b_val = b[y];
	int c_val = a_val * b_val;
	c[z] = c_val;
}

int main(void)
{
	int a[9][9] = {0};
	int b[9][9] = {0};
	int c[9][9] = {0};
	int *d_a, *d_b, *d_c;
	int size = sizeof(a)/sizeof(a[0]);
	cudaMalloc((void **)&d_a, size);
	cudaMalloc((void **)&d_b, size);
	cudaMalloc((void **)&d_c, size);
	cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);
	multiply<<<1, size>>>(d_a, d_b, d_c);
	cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%dx%d=%d\n",a[i],b[j],c[i][j]);
		}
	}
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
	return 0;
}