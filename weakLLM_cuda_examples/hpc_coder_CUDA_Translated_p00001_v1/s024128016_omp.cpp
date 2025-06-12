c++
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

__global__ void sort_kernel(int *a, int n){
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if(idx < n){
    for(int i=idx+1;i<n;i++){
      if(a[idx] > a[i]){
        swap(a[idx], a[i]);
      }
    }
  }
}

int main(){
  vector<int> a;
  a.resize(10);
  for(int i=0;i<10;i++){
    cin>>a[i];
  }
  int *d_a;
  cudaMalloc((void **)&d_a, a.size() * sizeof(int));
  cudaMemcpy(d_a, a.data(), a.size() * sizeof(int), cudaMemcpyHostToDevice);
  int threadsPerBlock = 256;
  int blocksPerGrid = (a.size() + threadsPerBlock - 1) / threadsPerBlock;
  sort_kernel<<<blocksPerGrid, threadsPerBlock>>>(d_a, a.size());
  cudaMemcpy(a.data(), d_a, a.size() * sizeof(int), cudaMemcpyDeviceToHost);
  sort(a.begin(),a.end());
  cout<<a[9]<<endl<<a[8]<<endl<<a[7]<<endl;
  cudaFree(d_a);
}