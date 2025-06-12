c++
#include<bits/stdc++.h>

using namespace std;

__global__ void sort_array(int *arr, int n)
{
    int tid = threadIdx.x;
    int i = tid;
    int temp;
    while(i < n)
    {
        int j = i - 1;
        while(j >= 0 && arr[j] < arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j--;
        }
        i++;
    }
}

int main()
{
    int hi,a=10;
    vector<int> mou;
    while(a--)
    {
        cin>>hi;
        mou.push_back(hi);
    }
    int *d_arr;
    cudaMalloc((void **)&d_arr, mou.size() * sizeof(int));
    cudaMemcpy(d_arr, mou.data(), mou.size() * sizeof(int), cudaMemcpyHostToDevice);
    sort_array<<<1, mou.size()>>>(d_arr, mou.size());
    cudaMemcpy(mou.data(), d_arr, mou.size() * sizeof(int), cudaMemcpyDeviceToHost);
    sort(mou.rbegin(),mou.rend());
    for(int i=0;i<3;i++)
        cout<<mou[i]<<endl;
    cudaFree(d_arr);
    return 0;
}