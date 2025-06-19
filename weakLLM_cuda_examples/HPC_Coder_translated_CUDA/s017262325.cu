#include <stdio.h>

__global__ void multiply(int *a, int *b, int *c)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < 10)
    {
        for (int j = 1; j <= 9; ++j)
        {
            c[i * 9 + j] = a[i] * b[j];
        }
    }
}

int main()
{
    int a[10], b[9], c[10];
    for (int i = 0; i < 10; ++i)
    {
        a[i] = i + 1;
        b[i] = i + 1;
    }

    int *d_a, *d_b, *d_c;
    cudaMalloc((void **)&d_a, 10 * sizeof(int));
    cudaMalloc((void **)&d_b, 9 * sizeof(int));
    cudaMalloc((void **)&d_c, 10 * sizeof(int));

    cudaMemcpy(d_a, a, 10 * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, 9 * sizeof(int), cudaMemcpyHostToDevice);

    multiply<<<1, 10>>>(d_a, d_b, d_c);

    cudaMemcpy(c, d_c, 10 * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            printf("%dx%d=%d\n", i + 1, j, c[i * 9 + j]);
        }
    }

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}