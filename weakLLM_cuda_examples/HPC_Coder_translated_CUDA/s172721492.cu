#include <stdio.h>
#include <stdlib.h>

__global__ void print_table(int *table) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < 100) {
        printf("%d x %d = %d\n", idx / 10, idx % 10, table[idx]);
    }
}

int main() {
    int *table;
    cudaMallocManaged(&table, 100 * sizeof(int));
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            table[i * 10 + j] = i * j;
        }
    }
    int blockSize = 10;
    int numBlocks = (100 + blockSize - 1) / blockSize;
    print_table<<<numBlocks, blockSize>>>(table);
    cudaDeviceSynchronize();
    cudaFree(table);
    return 0;
}