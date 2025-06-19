#include <stdio.h>

__global__ void print_multiplication_table() {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;

    if (i < 9 && j < 9) {
        int m = i + 1;
        int n = j + 1;
        printf("%d x %d = %d\n", m, n, m * n);
    }
}

int main() {
    dim3 threadsPerBlock(3, 3);
    dim3 numBlocks(3, 3);  // 3x3 blocks * 3x3 threads = 9x9 grid

    print_multiplication_table<<<numBlocks, threadsPerBlock>>>();
    cudaDeviceSynchronize();

    return 0;
}
