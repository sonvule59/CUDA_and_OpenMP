#include<iostream>

using namespace std;

__global__ void multiply(int *a, int *b, int *c, int n) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < n) {
        c[i] = a[i] * b[i];
    }
}

int main() {
    int n = 10;
    int *a, *b, *c;
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    c = (int *)malloc(n * sizeof(int));

    // Initialize a and b arrays

    multiply<<<1, n>>>(a, b, c, n);

    // Print the result

    free(a);
    free(b);
    free(c);
    return 0;
}