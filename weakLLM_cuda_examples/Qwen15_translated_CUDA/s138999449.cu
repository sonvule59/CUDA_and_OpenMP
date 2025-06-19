#include <cuda_runtime.h>

__global__ void my_kernel(int *a, int *b, int *c) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if (tid < 9) {
        c[tid] = a[tid] * b[tid];
    }
}

int main() {
    int a[9], b[9], c[9];
    // Copy input values into GPU memory
    cudaMemcpy(a, &a[0], sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(b, &b[0], sizeof(int), cudaMemcpyHostToDevice);

    // Set kernel block size and grid size
    dim3 block_size(16, 16, 16); // 16 threads per block, 16 blocks per grid
    dim3 grid_size(16, 16, 16); // 16 threads per grid

    // Create thread block for each grid element
    my_kernel<<<grid_size, block_size>>>(a, b, c);

    // Wait for all threads to finish
    cudaDeviceWaitAll();

    // Read output values from GPU memory
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += c[i];
    }

    printf("Sum of elements on the GPU: %d\n", sum);

    return 0;
}