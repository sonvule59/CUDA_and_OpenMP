#include <stdio.h>

__global__ void multiply(uint8_t *a, uint8_t *b, uint8_t *c, int n)
{
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n)
    {
        for (int i = 0; i < n; i++)
        {
            c[idx * n + i] = a[idx * n + i] * b[i * n + idx];
        }
    }
}

int main()
{
    uint8_t *a, *b, *c;
    int n = 10;
    a = (uint8_t *)malloc(n * n * sizeof(uint8_t));
    b = (uint8_t *)malloc(n * n * sizeof(uint8_t));
    c = (uint8_t *)malloc(n * n * sizeof(uint8_t));

    // Initialize a and b

    multiply<<<1, n>>>(a, b, c, n);

    // Print the result

    free(a);
    free(b);
    free(c);
    return 0;
}