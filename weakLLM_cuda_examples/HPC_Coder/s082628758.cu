#include<stdio.h>
__global__ void multiply(int *a, int *b, int *c, int n, int m)
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int j = blockIdx.y * blockDim.y + threadIdx.y;
	if(i<n && j<m)
	{
		c[i*m+j] = a[i]*b[j];
	}
}

int main()
{
	int *a, *b, *c;
	int n, m;
	scanf("%d %d", &n, &m);
	a = (int *)malloc(n*sizeof(int));
	b = (int *)malloc(m*sizeof(int));
	c = (int *)malloc((n*m)*sizeof(int));

	// Initialize a and b

	dim3 threadsPerBlock(16, 16);
	dim3 numBlocks((n+threadsPerBlock.x-1)/threadsPerBlock.x, (m+threadsPerBlock.y-1)/threadsPerBlock.y);
	multiply<<<numBlocks, threadsPerBlock>>>(a, b, c, n, m);

	// Print the result

	free(a);
	free(b);
	free(c);
	return 0;
}