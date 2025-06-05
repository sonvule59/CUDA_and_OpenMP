#include<iostream>
using namespace std;

__global__ void print_table(int *table) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < 100) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                printf("%d x %d = %d\n", i, j, i * j);
            }
        }
    }
}

int main() {
    int *table;
    cudaMalloc((void **)&table, sizeof(int) * 100);
    print_table<<<1, 100>>>(table);
    cudaDeviceSynchronize();
    cudaFree(table);
    return 0;
}