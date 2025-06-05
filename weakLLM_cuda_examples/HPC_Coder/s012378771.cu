#include <stdio.h>

__global__ void print_table(int start, int end) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx >= start && idx <= end) {
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", idx, i, idx * i);
        }
    }
}

int main() {
    int start = 1;
    int end = 9;
    int threads_per_block = 256;
    int blocks_per_grid = (end - start + 1 + threads_per_block - 1) / threads_per_block;
    print_table<<<blocks_per_grid, threads_per_block>>>(start, end);
    cudaDeviceSynchronize();
    return 0;
}