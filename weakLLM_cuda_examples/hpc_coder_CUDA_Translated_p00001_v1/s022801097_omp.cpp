c++
#include <iostream>
#include <algorithm>
using namespace std;

__global__ void sort_array(int *list, int size) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < size) {
        for (int i = idx + 1; i < size; i++) {
            if (list[idx] > list[i]) {
                swap(list[idx], list[i]);
            }
        }
    }
}

int main() {
    int i;
    int list[10];
    for(i=0;i<10;i++){
        cin >> list[i];
    }
    int *d_list;
    cudaMalloc((void **)&d_list, 10 * sizeof(int));
    cudaMemcpy(d_list, list, 10 * sizeof(int), cudaMemcpyHostToDevice);
    int threadsPerBlock = 256;
    int blocksPerGrid = (10 + threadsPerBlock - 1) / threadsPerBlock;
    sort_array<<<blocksPerGrid, threadsPerBlock>>>(d_list, 10);
    cudaMemcpy(list, d_list, 10 * sizeof(int), cudaMemcpyDeviceToHost);
    for(i=0;i<3;i++){
        cout << list[9-i] << endl;
    }
    cudaFree(d_list);
    return 0;
}