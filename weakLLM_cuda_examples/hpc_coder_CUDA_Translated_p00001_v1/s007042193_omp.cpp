#include <stdio.h>

__global__ void max_kernel(int *a, int *max, int *temp, int *temp1, int bat)
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < bat)
	{
		if (a[i] > *max)
		{
			*max = a[i];
			*temp1 = i;
		}
	}
	__syncthreads();
	
	if (i < bat)
	{
		int temp = a[bat];
		a[bat] = a[*temp1];
		a[*temp1] = temp;
		bat--;
	}
}

int main()
{
	int a[100];
	int max, bat, temp, temp1;
	bat = 10;
	for (int i = 1; i <= 10; i++)
		scanf("%d", &a[i]);
	
	int *d_a, *d_max, *d_temp, *d_temp1;
	cudaMalloc((void **)&d_a, 100 * sizeof(int));
	cudaMalloc((void **)&d_max, sizeof(int));
	cudaMalloc((void **)&d_temp, sizeof(int));
	cudaMalloc((void **)&d_temp1, sizeof(int));
	
	cudaMemcpy(d_a, a, 100 * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_max, &max, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_temp, &temp, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_temp1, &temp1, sizeof(int), cudaMemcpyHostToDevice);
	
	max_kernel<<<1, 10>>>(d_a, d_max, d_temp, d_temp1, bat);
	
	cudaMemcpy(&max, d_max, sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(&temp, d_temp, sizeof(int), cudaMemcpyDeviceToHost);
	cudaMemcpy(&temp1, d_temp1, sizeof(int), cudaMemcpyDeviceToHost);
	
	for (int i = 10; i > 7; i--)
		printf("%d\n", a[i]);
	
	cudaFree(d_a);
	cudaFree(d_max);
	cudaFree(d_temp);
	cudaFree(d_temp1);
	
	return 0;
}