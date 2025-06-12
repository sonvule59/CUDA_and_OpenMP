#include<iostream>
using namespace std;
__global__ void findMax(int *x, int *No1, int *No2, int *No3) {
int idx = threadIdx.x + blockIdx.x * blockDim.x;
if (idx < 10) {
if (x[idx] > *No1) {
*No3 = *No2;
*No2 = *No1;
*No1 = x[idx];
} else if (x[idx] > *No2) {
*No3 = *No2;
*No2 = x[idx];
} else if (x[idx] > *No3) {
*No3 = x[idx];
}
}
}
int main() {
int x[10];
int No1, No2, No3;
No1 = 0;
No2 = 0;
No3 = 0;
for (int i = 0; i < 10; i++) {
cin >> x[i];
}
int *d_x, *d_No1, *d_No2, *d_No3;
cudaMalloc((void **)&d_x, 10 * sizeof(int));
cudaMalloc((void **)&d_No1, sizeof(int));
cudaMalloc((void **)&d_No2, sizeof(int));
cudaMalloc((void **)&d_No3, sizeof(int));
cudaMemcpy(d_x, x, 10 * sizeof(int), cudaMemcpyHostToDevice);
cudaMemcpy(d_No1, &No1, sizeof(int), cudaMemcpyHostToDevice);
cudaMemcpy(d_No2, &No2, sizeof(int), cudaMemcpyHostToDevice);
cudaMemcpy(d_No3, &No3, sizeof(int), cudaMemcpyHostToDevice);
findMax<<<1, 10>>>(d_x, d_No1, d_No2, d_No3);
cudaMemcpy(&No1, d_No1, sizeof(int), cudaMemcpyDeviceToHost);
cudaMemcpy(&No2, d_No2, sizeof(int), cudaMemcpyDeviceToHost);
cudaMemcpy(&No3, d_No3, sizeof(int), cudaMemcpyDeviceToHost);
cout << No1 << endl << No2 << endl << No3 << endl;
return 0;
}