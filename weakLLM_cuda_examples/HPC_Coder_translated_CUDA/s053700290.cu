#include <cstdlib>
#include <iostream>

__global__ void print_multiplication_table() {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    if (i <= 9 && j <= 9) {
        printf("%d x %d = %d\n", i, j, i * j);
    }
}

int main() {
    int blockSize = 16;
    int numBlocks = 9;
    print_multiplication_table<<<numBlocks, blockSize>>>();
    cudaDeviceSynchronize();
    return EXIT_SUCCESS;
}