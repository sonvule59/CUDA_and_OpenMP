c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

__global__ void sort_height(int* vec_height, int size) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < size) {
        for (int i = idx + 1; i < size; i++) {
            if (vec_height[idx] < vec_height[i]) {
                swap(vec_height[idx], vec_height[i]);
            }
        }
    }
}

int main() {
    vector<int> vec_height(10);

    for (auto& h : vec_height)
        cin >> h;

    int* d_vec_height;
    cudaMalloc((void**)&d_vec_height, vec_height.size() * sizeof(int));
    cudaMemcpy(d_vec_height, vec_height.data(), vec_height.size() * sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (vec_height.size() + threadsPerBlock - 1) / threadsPerBlock;
    sort_height<<<blocksPerGrid, threadsPerBlock>>>(d_vec_height, vec_height.size());

    cudaMemcpy(vec_height.data(), d_vec_height, vec_height.size() * sizeof(int), cudaMemcpyDeviceToHost);

    sort(vec_height.begin(), vec_height.end(), greater<int>());

    cout
        << vec_height[0] << endl
        << vec_height[1] << endl
        << vec_height[2] << endl;

    cudaFree(d_vec_height);
    return 0;
}