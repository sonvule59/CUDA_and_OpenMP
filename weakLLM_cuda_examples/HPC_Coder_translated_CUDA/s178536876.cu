#include <stdio.h>

__global__ void print_table(int a, int b)
{
    printf("%d x %d = %d\n", a, b, a*b);
}

int main()
{
    int a, b;
    for(a = 1; a < 10; a++)
        for(b = 1; b < 10; b++)
            print_table<<<1,1>>>(a, b);
    cudaDeviceSynchronize();
    return 0;
}