#include <stdio.h>

__global__ void print_multiplication_table(int start, int end){
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if(i >= start && i <= end){
        for(int j=1;j<10;j++){
            printf("%dx%d=%d\n",i,j,i*j);
        }
    }
}

int main(void){
    int start = 1;
    int end = 10;
    int threads_per_block = 256;
    int blocks_per_grid = (end - start + 1 + threads_per_block - 1) / threads_per_block;
    print_multiplication_table<<<blocks_per_grid, threads_per_block>>>(start, end);
    cudaDeviceSynchronize();
}