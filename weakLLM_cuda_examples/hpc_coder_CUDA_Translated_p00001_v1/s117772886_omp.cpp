c++
#include<iostream>

using namespace std;

__global__ void sort(int *a, int n) {
    int tid = threadIdx.x;
    int i = tid;
    int temp;
    while (i < n) {
        int j = i - 1;
        while (j >= 0 && a[j] > a[j + 1]) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
            j--;
        }
        i++;
    }
}

int main() {
    int a[10] = {-1, -1, -1, 1, 2, 3, 4, 5, 6, 7};
    int n = 10;
    int *d_a;
    cudaMalloc((void **)&d_a, n * sizeof(int));
    cudaMemcpy(d_a, a, n * sizeof(int), cudaMemcpyHostToDevice);
    sort<<<1, n>>>(d_a, n);
    cudaMemcpy(a, d_a, n * sizeof(int), cudaMemcpyDeviceToHost);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    cudaFree(d_a);
    return 0;
}