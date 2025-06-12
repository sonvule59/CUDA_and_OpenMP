c++
#include<iostream>
using namespace std;
__global__ void sort(int *a, int n) {
    int i = threadIdx.x;
    int temp;
    for(int j = i; j < n; j += blockDim.x) {
        if(a[i] < a[j]) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}
int main() {
    int a[100], i, j, temp;
    for(i=1;i<=10;i++){
        cin>>a[i];
    }
    int *d_a;
    cudaMalloc((void **)&d_a, 100 * sizeof(int));
    cudaMemcpy(d_a, a, 100 * sizeof(int), cudaMemcpyHostToDevice);
    int n = 10;
    int blockSize = 10;
    int numBlocks = (n + blockSize - 1) / blockSize;
    sort<<<numBlocks, blockSize>>>(d_a, n);
    cudaMemcpy(a, d_a, 100 * sizeof(int), cudaMemcpyDeviceToHost);
    for(i=1;i<=3;i++){
        cout<<a[i]<<endl;
    }
    cudaFree(d_a);
    return 0;
}