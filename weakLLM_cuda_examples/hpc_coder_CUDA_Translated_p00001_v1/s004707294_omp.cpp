c++
#include<iostream>
#include<algorithm>
using namespace std;

__global__ void sort(int *a, int n) {
    int i = threadIdx.x;
    int temp;
    for (int j = i; j < n; j += blockDim.x) {
        for (int k = j; k < n; k += blockDim.x) {
            if (a[j] > a[k]) {
                temp = a[j];
                a[j] = a[k];
                a[k] = temp;
            }
        }
    }
}

int main() {
    int a[10], i, judge;
    for (i = 0; i < 10; i++) cin >> a[i];
    judge = 0;
    do {
        judge = 1;
        for (i = 0; i < 9; i++) {
            if (a[i] < a[i + 1]) {
                swap(a[i], a[i + 1]);
                judge = 0;
            }
        }
    } while (!judge);

    int *d_a;
    cudaMalloc((void **)&d_a, 10 * sizeof(int));
    cudaMemcpy(d_a, a, 10 * sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (10 + threadsPerBlock - 1) / threadsPerBlock;
    sort<<<blocksPerGrid, threadsPerBlock>>>(d_a, 10);

    cudaMemcpy(a, d_a, 10 * sizeof(int), cudaMemcpyDeviceToHost);

    for (i = 0; i < 3; i++)
        cout << a[i] << endl;

    cudaFree(d_a);
    return 0;
}