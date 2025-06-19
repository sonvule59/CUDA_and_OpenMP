#include<iostream>
using namespace std;

__global__ void print_table(int *table) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < 100) {
        int i = idx / 10;
        int j = idx % 10;
        printf("%d x %d = %d\n", i, j, i*j);
    }
}

int main() {
    int *table;
    cudaMalloc((void **)&table, 100 * sizeof(int));
    print_table<<<1, 100>>>(table);
    cudaDeviceSynchronize();
    cudaFree(table);
    return 0;
}