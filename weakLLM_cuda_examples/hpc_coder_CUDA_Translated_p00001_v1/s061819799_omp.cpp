c++
#include <iostream>

__global__ void find_max(int *a, int *max1, int *max2, int *max3) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < n) {
        if (a[idx] > *max1) {
            *max3 = *max2;
            *max2 = *max1;
            *max1 = a[idx];
        } else if (a[idx] > *max2) {
            *max3 = *max2;
            *max2 = a[idx];
        } else if (a[idx] > *max3) {
            *max3 = a[idx];
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    int *a = new int[n];
    int *max1 = new int;
    int *max2 = new int;
    int *max3 = new int;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    *max1 = *max2 = *max3 = a[0];

    int threadsPerBlock = 256;
    int blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;
    find_max<<<blocksPerGrid, threadsPerBlock>>>(a, max1, max2, max3);

    std::cout << *max1 << std::endl;
    std::cout << *max2 << std::endl;
    std::cout << *max3 << std::endl;

    delete[] a;
    delete max1;
    delete max2;
    delete max3;

    return 0;
}