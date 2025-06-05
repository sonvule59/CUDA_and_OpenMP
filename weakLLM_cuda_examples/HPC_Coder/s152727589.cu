#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

__global__ void f_input(int *i, int *j)
{
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < 10)
    {
        for (int j = 1; j <= 9; ++j)
        {
            printf("%d x %d = %d\n", idx, j, idx * j);
        }
    }
}

int main()
{
    int *i, *j;
    cudaMalloc((void **)&i, sizeof(int));
    cudaMalloc((void **)&j, sizeof(int));

    f_input<<<1, 10>>>(i, j);

    cudaDeviceSynchronize();

    cudaFree(i);
    cudaFree(j);

    return 0;
}