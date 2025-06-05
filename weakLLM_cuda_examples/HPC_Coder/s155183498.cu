#include <stdio.h>

__global__ void print_table(int start, int end) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i >= start && i <= end) {
        for (int n = 1; n <= 9; n++) {
            printf("%d x %d = %d\n", i, n, i * n);
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