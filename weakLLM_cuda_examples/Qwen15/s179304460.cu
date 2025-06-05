#include<cuda.h>
#include<stdio.h>

__global__ void kernel(int x, int y) {
    int sum = 0;
    for (int i = blockIdx.x * blockDim.x + threadIdx.x; i < blockDim.x * gridDim.x; i += blockDim.x * blockDim.y) {
        sum += x * y;
    }
    printf("Sum of %dx%d is %d\n", x, y, sum);
}

int main() {
    int gridDimX = 9, blockDimY = 9;
    int numBlocksX = gridDimX / blockDimX, numBlocksY = gridDimY / blockDimY;
    
    // Allocate memory on GPU
    cudaMalloc(&sumGridX, numBlocksX * blockDimX * sizeof(int));
    cudaMalloc(&sumGridY, numBlocksY * blockDimY * sizeof(int));

    // Copy input data to GPU
    cudaMemcpy(sumGridX, &gridData[0], numBlocksX * blockDimX * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(sumGridY, &gridData[1], numBlocksY * blockDimY * sizeof(int), cudaMemcpyHostToDevice);

    // Launch kernel on GPU
    kernel<<<gridDimX, blockDimY>>>(sumGridX, sumGridY);

    // Read result from GPU
    cudaMemcpy(&result, sumGridX, numBlocksX * blockDimX * sizeof(int), cudaMemcpyDeviceToHost);

    // Free memory on GPU
    cudaFree(sumGridX);
    cudaFree(sumGridY);
    
    return 0;
}