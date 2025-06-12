c++
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(n) n.begin(),n.end()
using namespace std;

__global__ void sort_kernel(int *h, int N)
{
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if(idx < N)
    {
        for(int i = idx; i < N; i += blockDim.x * gridDim.x)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(h[i] > h[j])
                {
                    swap(h[i], h[j]);
                }
            }
        }
    }
}

int main()
{
    const int N = 10;
    vector<int> h;
    int hnum = 0;
    rep(i,N) 
    {
        cin >> hnum;
        h.push_back(hnum);
    }

    int *d_h;
    cudaMalloc((void **)&d_h, N * sizeof(int));
    cudaMemcpy(d_h, h.data(), N * sizeof(int), cudaMemcpyHostToDevice);

    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
    sort_kernel<<<blocksPerGrid, threadsPerBlock>>>(d_h, N);

    cudaMemcpy(h.data(), d_h, N * sizeof(int), cudaMemcpyDeviceToHost);

    sort(all(h));

    cout << h[9] << endl;
    cout << h[8] << endl;
    cout << h[7] << endl;

    cudaFree(d_h);

    return 0;
}