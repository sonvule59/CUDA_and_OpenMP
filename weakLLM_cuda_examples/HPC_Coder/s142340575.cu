#include<stdio.h>
__global__ void kernel(int *a, int *b){
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    if(i<9 && j<9){
        printf("%dx%d=%d\n",i+1,j+1,(i+1)*(j+1));
    }
}

int main(){
    int *a, *b;
    cudaMalloc((void **)&a, sizeof(int));
    cudaMalloc((void **)&b, sizeof(int));
    kernel<<<dim3(9,9), dim3(1,1)>>>(a, b);
    cudaDeviceSynchronize();
    cudaFree(a);
    cudaFree(b);
    return 0;
}