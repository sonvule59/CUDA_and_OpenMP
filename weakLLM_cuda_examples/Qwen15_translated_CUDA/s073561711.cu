#include <cuda_runtime.h>

__global__ void kernel(int x, int y) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;

    if (i <= 8 && j <= 8) {
        // Calculate product of two numbers
        int product = x * y;

        // Store result in GPU memory
        cudaMemcpy(&product, &product, sizeof(int), cudaMemcpyHostToDevice);

        // Update global variables
        i += blockDim.x * gridDim.x;
        j += blockDim.y * gridDim.y;
    }
}

int main() {
    int i = 1, ii = 1;
    
    dim3 threads(2, 2, 2); // 2 threads per block, 2 blocks per grid
    dim3 grid(5, 5, 5); // 5x5 grid
    
    kernel<<<grid, threads>>>(i, ii);
    
    // Read results from GPU memory
    int product[10];
    cudaMemcpy(product, kernel.getOutput(), sizeof(int), cudaMemcpyDeviceToHost);

    // Print results
    for (int j = 0; j < 10; j++) {
        printf("%d ", product[j]);
    }

    return 0;
}