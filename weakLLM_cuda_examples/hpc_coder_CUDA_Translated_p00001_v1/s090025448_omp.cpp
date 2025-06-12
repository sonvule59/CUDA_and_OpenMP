#include<iostream>
#include<algorithm>
using namespace std;
 
const int MAX_N = 9;
int a[MAX_N];
   
__global__ void sort_array(int *a) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < MAX_N) {
        for (int i = idx; i < MAX_N; i += blockDim.x * gridDim.x) {
            for (int j = i + 1; j < MAX_N; j++) {
                if (a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}
 
int main(){
 
    for(int i=0; i<=MAX_N; i++){
        cin >> a[i];
    }
      
    int *d_a;
    cudaMalloc((void **)&d_a, MAX_N * sizeof(int));
    cudaMemcpy(d_a, a, MAX_N * sizeof(int), cudaMemcpyHostToDevice);
 
    int threadsPerBlock = 256;
    int blocksPerGrid = (MAX_N + threadsPerBlock - 1) / threadsPerBlock;
    sort_array<<<blocksPerGrid, threadsPerBlock>>>(d_a);
 
    cudaMemcpy(a, d_a, MAX_N * sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(d_a);
 
    sort(a, a+10);
    cout << a[9] << endl << a[8] << endl << a[7] << endl;
 
    return 0;
}