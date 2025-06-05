__global__ void print_table(int *table) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int j = blockIdx.y * blockDim.y + threadIdx.y;
	if (i < 10 && j < 10) {
		printf("%d x %d = %d\n", i, j, i*j);
	}
}

int main() {
	int *table;
	cudaMalloc((void **)&table, 100 * sizeof(int));
	print_table<<<dim3(10, 10), dim3(16, 16)>>>(table);
	cudaDeviceSynchronize();
	cudaFree(table);
	return 0;
}