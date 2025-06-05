#include <cuda_runtime.h>

__global__ void my_kernel(int a, int b, int c) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    
    if (tid < 10) {
        // Access element of matrix A at row and column tid
        int x = a[tid];
        
        // Multiply matrix A by B
        int product = a[tid] * b;
        
        // Store product in matrix C
        c[tid] = product;
    }
}

int main() {
    int a = 1, b = 1, c = 0;
    
    // Allocate memory for matrix A on GPU
    cudaMalloc((void**)&a, sizeof(int) * 10);
    
    // Allocate memory for matrix B on GPU
    cudaMalloc((void**)&b, sizeof(int) * 10);
    
    // Allocate memory for matrix C on GPU
    cudaMalloc((void**)&c, sizeof(int) * 10);
    
    // Copy data from CPU to GPU
    cudaMemcpy(a, &a[0], sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(b, &b[0], sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(c, &c[0], sizeof(int), cudaMemcpyHostToDevice);

    // Launch kernel on GPU
    my_kernel<<<10, 1>>>(a, b, c);

    // Copy result from GPU to CPU
    cudaMemcpy(c, &c[0], sizeof(int), cudaMemcpyDeviceToHost);

    // Free memory allocated on GPU
    cudaFree(a);
    cudaFree(b);
    cudaFree(c);

    return 0;
}