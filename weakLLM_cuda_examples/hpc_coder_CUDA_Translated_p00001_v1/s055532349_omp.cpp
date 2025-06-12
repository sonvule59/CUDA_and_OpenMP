c++
#include<stdio.h>
#include<iostream>

using namespace std;

__global__ void sort(int *a, int n) {
    int i = threadIdx.x;
    int temp;
    for (int j = 0; j < n - i - 1; j++) {
        if (a[j] > a[j + 1]) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    int *d_a;
    cudaMalloc((void **)&d_a, 10 * sizeof(int));
    cudaMemcpy(d_a, a, 10 * sizeof(int), cudaMemcpyHostToDevice);
    sort<<<1, 10>>>(d_a, 10);
    cudaMemcpy(a, d_a, 10 * sizeof(int), cudaMemcpyDeviceToHost);
    for (int i = 10 - 1; i > 6; i--) {
        cout << a[i] << "\n";
    }
    cudaFree(d_a);
    return 0;
}