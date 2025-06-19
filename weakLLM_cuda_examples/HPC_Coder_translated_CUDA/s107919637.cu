#include<stdio.h>

__global__ void multiply(int *a, int *b, int *c) {
    int i = threadIdx.x;
    int j = threadIdx.y;
    c[i*blockDim.y + j] = a[i] * b[j];
}

int main() {
    int a[10][10];
    int b[10][10];
    int c[10][10];

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            a[i][j] = i+1;
            b[i][j] = j+1;
        }
    }

    int *d_a, *d_b, *d_c;
    cudaMalloc((void **)&d_a, 10*10*sizeof(int));
    cudaMalloc((void **)&d_b, 10*10*sizeof(int));
    cudaMalloc((void **)&d_c, 10*10*sizeof(int));

    cudaMemcpy(d_a, a, 10*10*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, 10*10*sizeof(int), cudaMemcpyHostToDevice);

    multiply<<<10,10>>>(d_a, d_b, d_c);

    cudaMemcpy(c, d_c, 10*10*sizeof(int), cudaMemcpyDeviceToHost);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d x %d = %d\n", i+1, j+1, c[i][j]);
        }
    }

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d