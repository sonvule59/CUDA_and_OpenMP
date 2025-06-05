c++
__global__ void add(int* a, int* b, int* c, int N) {
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (index < N) {
        c[index] += a[index] + b[index];
    }
}

int main() {

    int N = 9;
    int* a = new int[N];
    int* b = new int[N];
    int* c = new int[N];

    // Copy input values into arrays
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1;
        b[i] = i + 2;
        c[i] = i + 3;
    }

    __shared__ int sharedSum = 0;

    add<<<16, 8>>>(a, b, c, N); // blockDim.x = 16, gridDim.x = 8

    // Access shared sum variable
    sharedSum = __syncthreads();

    for (int i = 0; i < N; ++i) {
        c[i] += sharedSum;
    }

    // Print final result
    std::cout << "Final Result: " << c[0] << " x " << c[1] << " x " << c[2] << "=" << sharedSum << std::endl;

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
 c++
#include <cuda.h>
#include <stdio.h>

__global__ void add(int* a, int* b, int* c, int N) {
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (index < N) {
        c[index] += a[index] + b[index];
    }
}

int main() {

    int N = 9;
    int* a = new int[N];
    int* b = new int[N];
    int* c = new int[N];

    // Copy input values into arrays
    for (int i = 0; i < N; ++i) {
        a[i] = i + 1;
        b[i] = i + 2;
        c[i] = i + 3;
    }

    __shared__ int sharedSum = 0;

    add<<<16, 8>>>(a, b, c, N); // blockDim.x =