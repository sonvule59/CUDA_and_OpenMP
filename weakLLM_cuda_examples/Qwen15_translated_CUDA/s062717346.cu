#pragma kernel "kernels/cuda_code.cpp"
#include <cuda_runtime.h>

__global__ void add(int *a, int *b, int *c)
{
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if(tid < a.size() && tid < b.size())
    {
        c[tid] = a[tid] + b[tid];
    }
}

__global__ void sub(int *a, int *b, int *c)
{
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if(tid < a.size() && tid < b.size())
    {
        c[tid] = a[tid] - b[tid];
    }
}

__global__ void mul(int *a, int *b, int *c)
{
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if(tid < a.size() && tid < b.size())
    {
        c[tid] = a[tid] * b[tid];
    }
}

__global__ void div(int *a, int *b, int *c)
{
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if(tid < a.size() && tid < b.size())
    {
        c[tid] /= b[tid];
    }
}

void addKernel(int *a, int *b, int *c)
{
    __shared__ int sharedData[N];
    int threadIdx = threadIdx.x + blockIdx.x * blockDim.x;
    int blockDimX = blockDim.x / numBlocks;
    int blockDimY = blockDim.y / numBlocks;

    // Add data
    sharedData[threadIdx] = a[blockDimX * blockDimY];
    sharedData[threadIdx + 1] = b[blockDimX * blockDimY];

    // Subtract data
    sharedData[threadIdx] -= a[blockDimX * blockDimY];
    sharedData[threadIdx + 2] -= b[blockDimX * blockDimY];

    // Multiply data
    sharedData[threadIdx] *= a[blockDimX * blockDimY];
    sharedData[threadIdx + 3] *= b[blockDimX * blockDimY];

    // Divide data
    sharedData[threadIdx] /= b[blockDimX * blockDimY];
    sharedData[threadIdx + 4] /= a[blockDimX * blockDimY];

    // Store result
    c[blockDimX * blockDimY] = sharedData[threadIdx];
}

void subKernel(int *a, int *b, int *c)
{
    __