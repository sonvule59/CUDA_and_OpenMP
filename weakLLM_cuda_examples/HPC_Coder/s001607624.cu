#include<iostream>
using namespace std;
__global__ void print_table(int *table){
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if(idx < 100)
        printf("%d x %d = %d\n", idx/10, idx%10, table[idx]);
}
int main(){
    int table[100];
    for(int i=0;i<100;i++)
        table[i] = i+1;
    int *d_table;
    cudaMalloc((void **)&d_table, 100*sizeof(int));
    cudaMemcpy(d_table, table, 100*sizeof(int), cudaMemcpyHostToDevice);
    print_table<<<1,100>>>(d_table);
    cudaDeviceSynchronize();
    cudaFree(d_table);
    return 0;
}