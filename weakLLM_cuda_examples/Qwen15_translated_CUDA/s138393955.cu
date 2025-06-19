#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

__global__ void multiply(int* a, int* b, int* c) {
    int tid = threadIdx.x;
    int blockIdx.x = blockIdx.y * blockDim.x + tid;
    
    if (tid < 8) {
        c[tid] = a[tid] * b[tid];
    }
}

int main() {

    // Allocate memory on GPU
    cudaMalloc(&a, sizeof(int) * 9);
    cudaMalloc(&b, sizeof(int) * 9);
    cudaMalloc(&c, sizeof(int) * 9);

    // Copy input data to GPU
    cudaMemcpy(a, &input_data[0], sizeof(int) * 9, cudaMemcpyHostToDevice);
    cudaMemcpy(b, &input_data[1], sizeof(int) * 9, cudaMemcpyHostToDevice);
    cudaMemcpy(c, &input_data[2], sizeof(int) * 9, cudaMemcpyHostToDevice);

    // Launch kernel
    multiply<<<gridDim=3, blockDim=x>>>(a, b, c);

    // Copy result data back to host
    cudaMemcpy(output_data, c, sizeof(int) * 9, cudaMemcpyDeviceToHost);

    // Free memory on GPU
    cudaFree(a);
    cudaFree(b);
    cudaFree(c);

    return 0;
}
 c++
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

__global__ void multiply(int* a, int* b, int* c) {
    int tid = threadIdx.x;
    int blockIdx.x = blockIdx.y * blockDim.x + tid;
    
    if (tid < 8) {
        c[tid] = a[tid] * b[tid];
    }
}

int main() {

    // Allocate memory on GPU
    cudaMalloc(&a, sizeof(int) * 9);
    cudaMalloc(&b, sizeof(int) * 9);
    cudaMalloc(&c, sizeof(int) * 9);

    // Copy input data to GPU
    cudaMemcpy(a, &input_data[0], sizeof(int) * 9, cudaMemcpyHostToDevice);
    cudaMemcpy(b, &input_data[1], sizeof(int) * 9, cudaMemcpyHostToDevice);
    cudaMemcpy(c, &input_data[2], sizeof(int) * 9, cudaMemcpyHostToDevice);

    // Launch kernel
    multiply<<<gridDim=3, blockDim=x>>>(a, b, c);

    // Copy result data back to host
    cudaMemcpy(output