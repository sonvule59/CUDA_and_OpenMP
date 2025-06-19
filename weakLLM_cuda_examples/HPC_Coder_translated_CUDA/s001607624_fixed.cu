#include <iostream>
#include <cuda_runtime.h>

__global__ void print_table() {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < 10 && col < 10) {
        int val = (row + 1) * (col + 1);
        printf("%d x %d = %d\n", row + 1, col + 1, val);
    }
}
int main() {
    dim3 threadsPerBlock(10, 10);
    dim3 numBlocks(1, 1);

    print_table<<<numBlocks, threadsPerBlock>>>();
    cudaDeviceSynchronize();
    return 0;
}
