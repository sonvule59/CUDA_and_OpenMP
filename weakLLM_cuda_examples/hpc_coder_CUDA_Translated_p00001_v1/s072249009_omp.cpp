#include<iostream>

using namespace std;

__global__ void sort(int *arr, int n) {
    int tid = threadIdx.x;
    int i = tid;
    int tmp;
    while (i < n) {
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j + 1]) {
            tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
            j--;
        }
        i++;
    }
}

int main() {
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 10;
    int *d_arr;
    cudaMalloc((void **)&d_arr, n * sizeof(int));
    cudaMemcpy(d_arr, arr, n * sizeof(int), cudaMemcpyHostToDevice);
    sort<<<1, n>>>(d_arr, n);
    cudaMemcpy(arr, d_arr, n * sizeof(int), cudaMemcpyDeviceToHost);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cudaFree(d_arr);
    return 0;
}