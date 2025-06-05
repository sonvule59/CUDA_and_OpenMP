#include<stdio.h>
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
using namespace std;

__global__ void kernel(int *a, int n){
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if(idx < n){
        REP(j,9)printf("%d x %d = %d\n", idx+1, j+1, (idx+1)*(j+1));
    }
}

int main(){
    int n = 9;
    int *a;
    cudaMalloc((void **)&a, n*n*sizeof(int));
    kernel<<<1,n>>>(a, n);
    cudaDeviceSynchronize();
    cudaFree(a);
    return 0;
}