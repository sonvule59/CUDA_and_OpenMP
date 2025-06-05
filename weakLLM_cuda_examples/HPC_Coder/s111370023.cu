#include <stdio.h>

__global__ void print_table(int start, int end) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i >= start && i <= end) {
        for (int k = 1; k <= 9; k++) {
            printf("%dx%d=%d\n", i, k, i * k);
        }
    }
}

int main() {
    int start = 1;
    int end = 9;
    int blockSize = 256;
    int numBlocks = (end - start + 1) / blockSize;

    print_table<<<numBlocks, blockSize>>>(start, end);

    cudaDeviceSynchronize();

    return 0;
}