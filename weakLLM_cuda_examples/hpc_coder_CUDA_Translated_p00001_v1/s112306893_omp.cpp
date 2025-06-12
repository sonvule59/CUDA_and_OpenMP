c++
#include<iostream>
using namespace std;

__global__ void sort(int *a, int n) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n) {
        int input = a[idx];
        if (input > a[0]) {
            a[2] = a[1];
            a[1] = a[0];
            a[0] = input;
        } else if (input > a[1]) {
            a[2] = a[1];
            a[1] = input;
        } else if (input > a[2]) {
            a[2] = input;
        }
    }
}

int main() {
    int a[3];
    for (int i = 0;i < 10; i++) {
        int input;
        cin >> input;
        a[i] = input;
    }

    int *d_a;
    cudaMalloc((void **)&d_a, 3 * sizeof(int));
    cudaMemcpy(d_a, a, 3 * sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (3 + 255) / threadsPerBlock;
    sort<<<blocksPerGrid, threadsPerBlock>>>(d_a, 3);

    cudaMemcpy(a, d_a, 3 * sizeof(int), cudaMemcpyDeviceToHost);

    for (int j = 0; j < 3; j++) {
        cout << a[j] << endl;
    }

    cudaFree(d_a);
    return 0;
}