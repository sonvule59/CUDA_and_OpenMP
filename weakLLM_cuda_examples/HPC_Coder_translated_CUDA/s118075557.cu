#include <stdio.h>

#define rep(i,n) for(i=0;i<n;i++)

__global__ void kernel(int *a, int *b, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) {
        printf("%dx%d=%d\n",i+1,i+1,(i+1)*(i+1));
    }
}

int main() {
    int i, k;
    int *a, *b;
    int n = 9;
    cudaMalloc((void **)&a, n * sizeof(int));
    cudaMalloc((void **)&b, n * sizeof(int));
    rep(i, n) {
        a[i] = i + 1;
        b[i] = i + 1;
    }
    kernel<<<1, n>>>(a, b, n);
    cudaDeviceSynchronize();
    cudaFree(a);
    cudaFree(b);
    return 0;
}