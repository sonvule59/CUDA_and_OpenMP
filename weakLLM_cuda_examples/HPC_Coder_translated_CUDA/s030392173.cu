#include <stdio.h>

__global__ void print_multiplication_table(int start, int end)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i >= start && i <= end)
    {
        for (int j = 1; j < 10; j++)
        {
            printf("%dx%d=%d\n", i, j, i * j);
        }
    }
}

int main()
{
    int start = 1;
    int end = 10;
    int blockSize = 256;
    int numBlocks = (end - start + 1 + blockSize - 1) / blockSize;

    print_multiplication_table<<<numBlocks, blockSize>>>(start, end);

    cudaDeviceSynchronize();

    return 0;
}